<?php
  require_once 'shared.php';
   
class vwkeumhs
{
  function __construct()
	{
	  
	}
	
	
   function filter_mhs($vthn,$vkls,$vnim1)
	{
		 $user = $_SESSION['user'];
	     
		            
		 $dtuser = new dt_user;
         $hak = $dtuser->gethak($user);
	  
	  
	  $html_txt="<fieldset>";
	  $html_txt.="<legend>Filter</legend>";
	  
	  $vmhs = new dt_mhs;
	  $data = $vmhs->getAngkatan();
	  $thn = $vthn;
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
	   $kls=$vkls;
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
	  $vnim = $vnim1;
	  $vtemp= "";
	  foreach($data as $row)
	  {	
        if(empty($vnim))
		{
		  $vnim=$row['nimhsmsmhs'];
		  $vtemp = $row['nimhsmsmhs']."-".$row['nmmhsmsmhs'];
		}else{
		
		  if($vnim==$row['nimhsmsmhs'])
		  {
		    $vtemp = $row['nimhsmsmhs']."-".$row['nmmhsmsmhs'];
		  }
		
		}						   
						
		 $Mhs[$row['nimhsmsmhs']]=$row['nimhsmsmhs']."-".$row['nmmhsmsmhs']; 
						
	  }						
	  
	  $frm = new HTML_Form();
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmfilter"));
	  $tbl->addRow();
	  $tbl->addCell('Angkatan '.$frm->addSelectList("Angkatan",$ang,true,$vthn,null,array('id'=>'Angkatan')).' Kelas '.$frm->addSelectList("kls",$kelas,true,$vkls,null,array('id'=>'kls')).' Mahasiswa '.$frm->addSelectList("Mhs",$Mhs,true,$vnim1,null,array('id'=>'Mhs')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')), null, 'data');
	   
	  $html_txt.=$tbl->display()."</fieldset>";

      $html_txt.="<fieldset>";
	  $html_txt.="<legend  id='hsl_filter'>Daftar Kewajiban : ".$vtemp."</legend>";
      
	  $html_txt.="<fieldset>";
	  $html_txt.="<legend>Aksi</legend>";
	  $frm = new HTML_Form();
	  $tbl1 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmAksi"));
	  $tbl1->addRow();
	  
	  
	  $addattr = array();
	  $addattr['id']='Add';
	  $editattr = array();
	  $editattr['id']='Edit';
	  $delattr= array();
	  $delattr['id']='Del';
	  $hitattr= array();
	  $hitattr['id']='Hit';
	  
	  if($hak==0)
	  {
		 $addattr['disabled']='disabled'; 
         $editattr['disabled']='disabled'; 
         $delattr['disabled']='disabled'; 	
         $hitattr['disabled']='disabled'; 			 
	  }	  
	  
	  
	  
	  $tbl1->addCell($frm->addInput('submit',"Add","Add",$addattr).
	                 $frm->addInput('submit',"Edit","Edit",$editattr).
	                 $frm->addInput('submit',"Delete","Delete",$delattr).
					 $frm->addInput('submit',"Hitung","Hitung",$hitattr), null, 'data');
	  $html_txt.=$tbl1->display()."</fieldset>";
	  
	  $html_txt.="<div id='data'>";
	  $html_txt.=$this->keumhs($vnim);
	  $html_txt.="</div>";
	  
	  $html_txt.="</fieldset>";
        	  
	  
	  return $html_txt;
	  
	}
	
	function keumhs($nim)
	{
	  
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_trans"));
	    $tbl->addRow();
       	$tbl->addCell('Kode', null, 'header');
	    $tbl->addCell('Nama Akun', null, 'header');
        $tbl->addCell('Pengali', null, 'header');
		$tbl->addCell('Kewajiban', null, 'header');
		$tbl->addCell('Jumlah Bayar', null, 'header');
        $tbl->addCell('Total', null, 'header');
		
        $dt = new dt_keumhs;   		
	    $data = $dt->getkeumhs($nim);
	    $ttl=0;
	    if(!empty($data))		
		{
		  
		  foreach($data as $row)
		  {
		     $tbl->addRow();
             
			
			 $tbl->addCell($row['acclvl1keumhs'], null, 'data');			 
		     $tbl->addCell($row['nmacclvl1'], null, 'data');
	         $tbl->addCell($row['pengalikeumhs'], null, 'data',array('align'=>'right'));
			 $tbl->addCell(number_format($row['jmlbyrkeuangk'], 2, ',', '.'), null, 'data',array('align'=>'right'));
             $tbl->addCell(number_format($row['pengalikeumhs']*$row['jmlbyrkeuangk'], 2, ',', '.'), null, 'data',array('align'=>'right'));
			 $ttl+=$row['pengalikeumhs']*$row['jmlbyrkeuangk'];
			 $tbl->addCell(number_format($ttl, 2, ',', '.'), null, 'data',array('align'=>'right'));
		    
			 
		  }
		}
	   
	              $txt = '';
					$txt = $txt."<tr>";
						$txt = $txt."<th></th>";
						$txt = $txt."<th></th>";
						$txt = $txt."<th></th>";											
						$txt = $txt."<th></th>";
						$txt = $txt."<th>Total</th>";
                        $txt = $txt."<th align='right'>".number_format($ttl, 2, ',', '.')."</th>";						
					$txt = $txt."</tr>";
	  
	  
	  $html_txt="<fieldset>".$tbl->display($txt)."</fieldset>";
	  return $html_txt;
	}	
	
  	function frm_add($nim)
	{
	  $frm = new HTML_Form();
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmAdd"));
	  
	  $tbl->addRow();
	  $tbl->addCell("NIM", null, 'data');
      $tbl->addCell(":", null, 'data');	 
      $tbl->addCell($frm->addInput('text',"nim",$nim,array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');	  
	  	  
	  $dt = new dt_keumhs;   		
	  $data = $dt->getnoacclvl1($nim);
	  
	  $noacc =array();
	  if(!empty($data))
	  {
	    foreach($data as $row)
		{
		  $noacc[$row['noacclvl1keuangk']]=$row['noacclvl1keuangk']." - ".$row['nmacclvl1'];		  
		}
	  
	  }
	  
	  $tbl->addRow();
	  $tbl->addCell("Akun", null, 'data');
	  $tbl->addCell(":", null, 'data');
	  $tbl->addCell($frm->addSelectList("acc",$noacc,true,null,null,array('id'=>'acc')), null, 'data');  
	  
	  $tbl->addRow();
	  $tbl->addCell("Pengali", null, 'data');
      $tbl->addCell(":", null, 'data');	 
      $tbl->addCell($frm->addInput('text',"pengali",0.00), null, 'data');	  
	  
	  
	  return $frm->startForm(null,'post','entrykeumhs').$tbl->display().$frm->endForm();
	
	}
	
	function frm_edit($nim,$kd)
	{
	  
	  $frm = new HTML_Form();
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmAdd"));
	  
	  $tbl->addRow();
	  $tbl->addCell("NIM", null, 'data');
      $tbl->addCell(":", null, 'data');	 
      $tbl->addCell($frm->addInput('text',"nim",$nim,array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');	  
	  	  
	  $dt = new dt_keumhs;   		
	  $data = $dt->getnoacclvl1($nim,0);
	  
	  $noacc =array();
	  if(!empty($data))
	  {
	    foreach($data as $row)
		{
		  $noacc[$row['noacclvl1keuangk']]=$row['noacclvl1keuangk']." - ".$row['nmacclvl1'];		  
		}
	  
	  }
	  
	  $tbl->addRow();
	  $tbl->addCell("Akun", null, 'data');
	  $tbl->addCell(":", null, 'data');
	  $tbl->addCell($frm->addSelectList("acc",$noacc,true,intval($kd),null,array('id'=>'acc','readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');  
	  
	  $kali = $dt->getpengali($nim,$kd);
	  
	  $tbl->addRow();
	  $tbl->addCell("Pengali", null, 'data');
      $tbl->addCell(":", null, 'data');	 
      $tbl->addCell($frm->addInput('text',"pengali",$kali), null, 'data');	  
	  
	  
	  return $frm->startForm(null,'post','entrykeumhs').$tbl->display().$frm->endForm();
	
	}
	
	function frm_del($nim)
	{
	    $frm = new HTML_Form();
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_keumhs"));
	    $tbl->addRow();
       	$tbl->addCell('Kode', null, 'header');
	    $tbl->addCell('Nama Akun', null, 'header');
        $tbl->addCell('Pengali', null, 'header');
		$tbl->addCell('Kewajiban', null, 'header');
		$tbl->addCell('Jumlah Bayar', null, 'header');
        $tbl->addCell('Hapus', null, 'header');
		
        $dt = new dt_keumhs;   		
	    $data = $dt->getkeumhs($nim);
	  
	    if(!empty($data))		
		{
		  $ttl=0;
		  foreach($data as $row)
		  {
		     $tbl->addRow();
             
			
			 $tbl->addCell($row['acclvl1keumhs'], null, 'data');			 
		     $tbl->addCell($row['nmacclvl1'], null, 'data');
	         $tbl->addCell($row['pengalikeumhs'], null, 'data',array('align'=>'right'));
			 $tbl->addCell(number_format($row['jmlbyrkeuangk'], 2, ',', '.'), null, 'data',array('align'=>'right'));
             $tbl->addCell(number_format($row['pengalikeumhs']*$row['jmlbyrkeuangk'], 2, ',', '.'), null, 'data',array('align'=>'right'));
			
			 $tbl->addCell($frm->addInput('checkbox',"plh[]",$row['acclvl1keumhs']), null, 'data',array('align'=>'center'));
		    
			 
		  }
		}
	  
	  
	  
	  $html_txt="<fieldset>".$frm->startForm(null,'post','entrykeumhs').$tbl->display().$frm->endForm()."</fieldset>";
	  return $html_txt;
	
	}
	
	
}

?>	