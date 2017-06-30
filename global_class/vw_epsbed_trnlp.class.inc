<?php 

    
	require_once 'shared.php';
	

class vw_epsbed_trnlp
 {
	 function __construct()
	 {
	    
	 } 
	
	 function mhs_filter()
	{
	  $dtmhs = new dt_mhs;
	  $data = $dtmhs->getAllData('bpmsmhs=1');
	  
	  $dtnim = array();
	  $vtemp = "";	  
	  $nim ="";	  
	  if(!empty($data))
	  {
	    foreach($data as $row)
	    {
	      if($vtemp=="")
          {
		    $vtemp = $row['nimhsmsmhs'].' - '.$row['nmmhsmsmhs'];
			$nim =$row['nimhsmsmhs'];
		  }
		  
		  $dtnim[$row['nimhsmsmhs']]=$row['nimhsmsmhs'].' - '.$row['nmmhsmsmhs'];
	    } 
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
      $tbl->addCell('Mahasiswa'.$frm->addSelectList("nim",$dtnim,true,null,null,array('id'=>'nim')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')), null, 'data');
	  
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
	  $tbl1->addCell($frm->addInput('submit',"Add","SIA->EPSBED",array('id'=>'Add')).$frm->addInput('submit',"Delete","Delete",array('id'=>'Del')).$frm->addInput('submit',"Down","Download TRLNP.DBF",array('id'=>'Down')), null, 'data');
	  
	  
	  
	  $html_txt.=$tbl1->display()."</fieldset>";
	  
	  
	  $html_txt.="<div id='data'>";
	  $html_txt.=$this->epsbed_trnlp($nim);
	  $html_txt.="</div>";
	  
	  $html_txt.="</fieldset>";
        	  
	  
	  return $html_txt;
	
	}
	 
	 function epsbed_trnlp($nim)
	 {	 
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_epsbedtrakd"));
	    $tbl->addRow();
        $tbl->addCell('NIM', null, 'header');
	    $tbl->addCell('Nama Mahasiswa', null, 'header');
	    $tbl->addCell('Kode', null, 'header');
        $tbl->addCell('Matakuliah', null, 'header');
	    $tbl->addCell('Nilai', null, 'header');
	    $tbl->addCell('Bobot', null, 'header');
	    
	    
		$dt = new dt_epsbed_trnlp;
	    $data = $dt->getviewdata($nim);
		
		if(!empty($data)){
		    $dt_mtk = new dt_mtk;
		    $dt_mhs = new dt_mhs;
		   foreach($data as $row)
		   {
		     
			  $tbl->addRow();
              $tbl->addCell($row['NIMHSTRNLP'], null, 'data');
	          $tbl->addCell($dt_mhs->getnmmhs($row['NIMHSTRNLP']), null, 'data');
	          $tbl->addCell($row['KDKMKTRNLP'], null, 'data');
              $tbl->addCell($dt_mtk->getnmmtk($row['KDKMKTRNLP']), null, 'data');
	          $tbl->addCell($row['NLAKHTRNLP'], null, 'data');
	          $tbl->addCell($row['BOBOTTRNLP'], null, 'data');
	          
		    
		   }
		   
		} 
		
	 $html_txt="<fieldset>".$tbl->display()."</fieldset>";
	 return $html_txt;
	 }
	
	function stat($tbid,$thn=0)
	 {
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => $tbid));
	            
		    $tbl->addRow();
		    $tbl->addCell('NIM', null, 'header',array("rowspan"=>2));
		    $tbl->addCell('Nama', null, 'header',array("rowspan"=>2));
		    $tbl->addCell('Jumlah', null, 'header',array("colspan"=>2));
		    $tbl->addRow();
		    $tbl->addCell('Matakuliah', null, 'header');
			$tbl->addCell('SKS', null, 'header');
		 
        
		$dt = new dt_epsbed_trnlp;
	    $data = $dt->stat($thn);
	    $txt='';
		if(!empty($data)){   
		   $dt_mhs = new dt_mhs;
		      		 foreach($data as $f=>$v)
		            {  
					   $tbl->addRow();
					   
					   $tbl->addCell($f , null, 'data');
					   $tbl->addCell($dt_mhs->getnmmhs($f), null, 'data');
					   $tbl->addCell(isset($v['jml_mtk']) ? $v['jml_mtk'] : 0, null, 'data',array('align'=>'center'));
					   $tbl->addCell(isset($v['jml_sks']) ? $v['jml_sks'] : 0, null, 'data',array('align'=>'center'));
					   
					  
			        } 
			  
		
		}
         
		
	  return $tbl->display($txt);
	 }
	
}
?>