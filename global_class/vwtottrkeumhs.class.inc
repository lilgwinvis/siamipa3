<?php
   require_once 'shared.php';
class vwtottrkeumhs
{
  function __construct()
	{
	  
	}
	
	function filter_mhs()
	{
	  
	  $html_txt="<fieldset>";
	  $html_txt.="<legend>Filter</legend>";
	  
	  $vmhs = new dt_mhs;
	  $data = $vmhs->getAngkatan();
	  $thn = "";
	  foreach($data as $row)
	  {
	     foreach($row as $field => $value)
		 {
		    if(empty($thn))
			{
			  $thn=$value;
			}						
			  $ang[$value]=$value;						
		 }
	  } 			
	  
	   $data = $vmhs->getkls($thn);
	   $kls="";
	   foreach($data as $row)
	   {
		  foreach($row as $field => $value)
		  {
			if(empty($kls))
			{
			   $kls=$value;
			}
				if($value=='R')
				{
				  $tmp="Reguler";
				}else
				{
                  $tmp="Non Reguler";								
				}
						
			    $kelas[$value]=$value." - ".$tmp; 
						
			}
		} 	
	  
	  $data = $vmhs->getmhs($thn,$kls);
	  $vnim = "";
	  $vtemp= "";
	  foreach($data as $row)
	  {	
        if(empty($vnim))
		{
		  $vnim=$row['nimhsmsmhs'];
		  $vtemp = $row['nimhsmsmhs']."-".$row['nmmhsmsmhs'];
		}						   
						
		 $Mhs[$row['nimhsmsmhs']]=$row['nimhsmsmhs']."-".$row['nmmhsmsmhs']; 
						
	  }						
	  
	 



      $frm = new HTML_Form();
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmfilter"));
	  $tbl->addRow();
	  $tbl->addCell('Angkatan '.$frm->addSelectList("Angkatan",$ang,true,null,null,array('id'=>'Angkatan')).' Kelas '.$frm->addSelectList("kls",$kelas,true,null,null,array('id'=>'kls')).' Mahasiswa '.$frm->addSelectList("Mhs",$Mhs,true,null,null,array('id'=>'Mhs')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')), null, 'data');
	   
	  $html_txt.=$tbl->display()."</fieldset>";

      $html_txt.="<fieldset>";
	  $html_txt.="<legend  id='hsl_filter'>Total Transaksi Keuangan : ".$vtemp."</legend>";
      
	  $html_txt.="<div id='data'>";
	  $html_txt.=$this->tottrankeumhs($vnim);
	  $html_txt.="</div>";
	  
	  $html_txt.="</fieldset>";
        	  
	  
	  return $html_txt;
	  
	}
	
	function tottrankeumhs($nim)
	{
	  
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_trans"));
	    $tbl->addRow();
        $tbl->addCell('Kode', null, 'header');
	    $tbl->addCell('Nama Akun', null, 'header');
        $tbl->addCell('Kewajiban', null, 'header');
		$tbl->addCell('Pembayaran', null, 'header');
        $tbl->addCell('Kekurangan', null, 'header');
		$tbl->addCell('Kelebihan', null, 'header');
		
        $dt = new dt_tot_trkeumhs;   		
	    $data = $dt->gettottrkeumhs($nim);
	  
	    
		  $ttl=0;
		  $tmp_kurang = 0;
		  $tmp_lebih = 0;
		  $ttl_kurang = 0;
		  $ttl_lebih = 0;
		  $ttl_wajib = 0;
		if(!empty($data))		
		{		  
		  foreach($data as $row)
		  {
		     $tbl->addRow();		 
			 $tbl->addCell($row['acclvl1keumhs'], null, 'data'); 
			 $tbl->addCell($row['nmacclvl1'], null, 'data');
	         $tbl->addCell(number_format($row['wajibByr'], 2, ',', '.'), null, 'data',array('align'=>'right'));
             $tbl->addCell(number_format($row['jmlbyr'], 2, ',', '.'), null, 'data',array('align'=>'right'));
		     $tbl->addCell($row['wajibByr']>$row['jmlbyr'] ? number_format($tmp_kurang=($row['wajibByr']-$row['jmlbyr']), 2, ',', '.') : number_format($tmp_kurang=0.00, 2, ',', '.'), null, 'data',array('align'=>'right'));
			 $tbl->addCell($row['wajibByr']<$row['jmlbyr'] ? number_format($tmp_lebih=($row['jmlbyr']-$row['wajibByr']), 2, ',', '.') : number_format($tmp_lebih=0.00, 2, ',', '.'), null, 'data',array('align'=>'right'));
			 $ttl+=$row['jmlbyr'];
			 $ttl_wajib += $row['wajibByr'];
			 $ttl_kurang += $tmp_kurang;
		     $ttl_lebih += $tmp_lebih;
		  }
		}
	  
                 $txt = '';
					$txt = $txt."<tr>";
						$txt = $txt."<th></th>";
						$txt = $txt."<th>Total</th>";	
						$txt = $txt."<th align='right'>".number_format($ttl_wajib, 2, ',', '.')."</th>";
						$txt = $txt."<th align='right'>".number_format($ttl, 2, ',', '.')."</th>";											
						$txt = $txt."<th align='right'>".number_format($ttl_kurang, 2, ',', '.')."</th>";
						$txt = $txt."<th align='right'>".number_format($ttl_lebih, 2, ',', '.')."</th>";										
					$txt = $txt."</tr>";	   

	   
	  $html_txt="<fieldset>".$tbl->display($txt)."</fieldset>";
	  
	  $tbl1 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "summary"));
	   $tbl1->addRow();
	
       $tbl1->addCell("Kewajian Yang Belum Dibayar = Total Kewajiban - Total Pembayaran = ".number_format($ttl_wajib, 2, ',', '.')." - ".number_format($ttl, 2, ',', '.')." = ".number_format($ttl_wajib-$ttl, 2, ',', '.'), null, 'data');
	   	   
	   $tbl1->addRow();
	   $tbl1->addCell("Kekurangan Yang Belum Dibayar = Total Kekurangan - Total Kelebihanan = ".number_format($ttl_kurang, 2, ',', '.')." - ".number_format($ttl_lebih, 2, ',', '.')." = ".number_format($ttl_kurang-$ttl_lebih, 2, ',', '.'), null, 'data');
	   
	   
	   $html_txt.="<fieldset>".$tbl1->display()."</fieldset>";
	   
	  return $html_txt;
	}
	

}

?>