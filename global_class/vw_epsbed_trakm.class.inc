<?php 

    
	require_once 'shared.php';
	

class vw_epsbed_trakm
 {
	 function __construct()
	 {
	    
	 } 
	
	 function sem_filter()
	{
	  $dtkrs = new dt_krs;
	  $TA = $dtkrs->TA();
      	  	
		
	  $thn = str_split($TA, 4);
	  
	  $dtsem = array();
	  $txt_sem = array(1=>'Ganjil',2=>'Genap');
	  $vtemp = "";	  
	  if($thn[1]==1)
	  {
	    $bts=$thn[0]-1;
	  }else
	  {
        $bts=$thn[0];         		
	  }
	  
	  for($i=2008;$i<=$bts;$i++)
	  {
	    for($j=1;$j<=2;$j++)
	    {
	      if($vtemp=="")
          {
		    $vtemp = 'Semester '.$txt_sem[$j].' '.$i;
			$thnsms =$i.$j;
		  }
		  
		  $dtsem[$i.$j]='Semester '.$txt_sem[$j].' '.$i;
	    } 
	  }	  
	  
	  if($thn[1]==1)
	  {
	    $dtsem[$thn[0].'1']='Semester Ganjil '.$thn[0];
	  }
	  
	 $html_txt="<fieldset>";
	 $html_txt.="<legend>Statistik</legend>";
	 $html_txt.="<div id='stat'>";
	 $html_txt.=$this->stat('stat1_epsbedtrnlm');
	 $html_txt.="</div>";
	 $html_txt.="</fieldset>";
	  
	  $frm = new HTML_Form();
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmfilter"));
	  $tbl->addRow();
      $tbl->addCell('Semester'.$frm->addSelectList("semester",$dtsem,true,null,null,array('id'=>'semester')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')), null, 'data');
	  
	  $html_txt.="<fieldset>";
	  $html_txt.="<legend>Filter</legend>";
	  $html_txt.=$tbl->display()."</fieldset>";

      $html_txt.="<fieldset>";
	  $html_txt.="<legend  id='hsl_filter'>Hasil Filter : ".$vtemp."</legend>";
      
	  $html_txt.="<fieldset>";
	  $html_txt.="<legend>Aksi</legend>";
	  $frm = new HTML_Form();
	  $tbl1 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmAksi"));
	  $tbl1->addRow();
	  $tbl1->addCell($frm->addInput('submit',"Add","SIA->EPSBED",array('id'=>'Add')).$frm->addInput('submit',"Delete","Delete",array('id'=>'Del')).$frm->addInput('submit',"Down","Download TRAKM.DBF",array('id'=>'Down')), null, 'data');
	  
	  
	  
	  $html_txt.=$tbl1->display()."</fieldset>";
	  
	  
	  $html_txt.="<div id='data'>";
	  $html_txt.=$this->epsbed_trakm($thnsms);
	  $html_txt.="</div>";
	  
	  $html_txt.="</fieldset>";
        	  
	  
	  return $html_txt;
	
	}
	 
	 function epsbed_trakm($thnsms)
	 {	 
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_epsbedtrakd"));
	    $tbl->addRow();
        $tbl->addCell('NIM', null, 'header');
	    $tbl->addCell('Nama', null, 'header');
	    $tbl->addCell('IPS', null, 'header');
        $tbl->addCell('SKS-sem', null, 'header');
	    $tbl->addCell('IPK', null, 'header');
	    $tbl->addCell('SKS-Total', null, 'header');
	   	    
		$dt = new dt_epsbed_trakm;
	    $data = $dt->getviewdata($thnsms);
		
		if(!empty($data)){
		   $dt_mhs = new dt_mhs;
		   
		   foreach($data as $row)
		   {
		    
			  $tbl->addRow();
              $tbl->addCell($row['NIMHSTRAKM'], null, 'data');
	          $tbl->addCell($dt_mhs->getnmmhs($row['NIMHSTRAKM']), null, 'data');
	          $tbl->addCell($row['NLIPSTRAKM'], null, 'data');
              $tbl->addCell($row['SKSEMTRAKM'], null, 'data');
	          $tbl->addCell($row['NLIPKTRAKM'], null, 'data');
	          $tbl->addCell($row['SKSTTTRAKM'], null, 'data');
		    
		   }
		   
		}
		           $txt = '';
					$txt = $txt."<tr>";
						$txt = $txt."<th><input type='text' name='search_nim' value='NIM' class='search_init' style='width:51px' /></th>";
						$txt = $txt."<th><input type='text' name='search_nama' value='Nama' class='search_init' /></th>";	
						$txt = $txt."<th></th>";
						$txt = $txt."<th></th>";											
						$txt = $txt."<th></th>";
						$txt = $txt."<th></th>";
					$txt = $txt."</tr>";
	 $html_txt="<fieldset>".$tbl->display($txt)."</fieldset>";
	 return $html_txt;
	 }
	function stat($tbid,$thn=0)
	 {
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => $tbid));
	    
        
		   $tbl->addRow();
		   $tbl->addCell('Semester', null, 'header',array("rowspan"=>2));
	       $tbl->addCell('Jumlah Mahasiswa', null, 'header',array("rowspan"=>2));
		   $tbl->addCell('IPS', null, 'header',array("colspan"=>2));
		   $tbl->addCell('SKS-sem', null, 'header',array("colspan"=>2));
		   $tbl->addCell('IPK', null, 'header',array("colspan"=>2));
		   $tbl->addCell('SKS-Total', null, 'header',array("colspan"=>2));
		   $tbl->addRow();
		   $tbl->addCell('Min', null, 'header');
		   $tbl->addCell('Max', null, 'header');
		   $tbl->addCell('Min', null, 'header');
		   $tbl->addCell('Max', null, 'header');
		   $tbl->addCell('Min', null, 'header');
		   $tbl->addCell('Max', null, 'header');
		   $tbl->addCell('Min', null, 'header');
		   $tbl->addCell('Max', null, 'header');
		  
		
	    
        
		$dt = new dt_epsbed_trakm;
	    $data = $dt->stat($thn);
	    
		if(!empty($data)){
		
		   foreach($data as $f=>$v)
		   {
		         	   $tbl->addRow();
					   $tmp=str_split($f,4);
					   $tbl->addCell($tmp[1]==1 ? 'Ganjil '.$tmp[0] : 'Genap '.$tmp[0] , null, 'data');
					   
					   $tbl->addCell($v['jml_mhs'], null, 'data',array('align'=>'center'));
					   $tbl->addCell($v['min_ips'], null, 'data',array('align'=>'center'));
					   $tbl->addCell($v['max_ips'], null, 'data',array('align'=>'center'));
					   $tbl->addCell($v['min_sks_sem'], null, 'data',array('align'=>'center'));
					   $tbl->addCell($v['max_sks_sem'], null, 'data',array('align'=>'center'));
					   $tbl->addCell($v['min_ipk'], null, 'data',array('align'=>'center'));
					   $tbl->addCell($v['max_ipk'], null, 'data',array('align'=>'center'));
					   $tbl->addCell($v['min_sks_tot'], null, 'data',array('align'=>'center'));
					   $tbl->addCell($v['max_sks_tot'], null, 'data',array('align'=>'center'));
					   
		   }
		
		}
         
		
	  return $tbl->display();
	 }
}
?>