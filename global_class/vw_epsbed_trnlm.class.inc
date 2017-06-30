<?php 

    
	require_once 'shared.php';
	

class vw_epsbed_trnlm
 {
	 function __construct()
	 {
	    
	 } 
	
	 function sem_filter()
	{
	  $mythnsem = new mythnsem;	  
	  $dtsem=$mythnsem->getlstthnsem('','');
	  $vtemp = $dtsem[key($dtsem)];
	  
	  $html_element = new html_element;	  
	
	 $isi_fieldset="<div id='stat'>";
	 $isi_fieldset.=$this->stat('stat1_epsbedtrnlm');
	 $isi_fieldset.="</div>";	 
	 
     $html_txt=$html_element->addfieldset('Statistik',$isi_fieldset); 
	 
	  $frm = new HTML_Form();
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmfilter"));
	  $tbl->addRow();
      $tbl->addCell('Semester'.$frm->addSelectList("semester",$dtsem,true,null,null,array('id'=>'semester')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')), null, 'data');
	  
	  $html_txt.=$html_element->addfieldset('Filter',$tbl->display());
	        	  
	  $frm = new HTML_Form();
	  $tbl1 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmAksi"));
	  $tbl1->addRow();
	  $tbl1->addCell($frm->addInput('submit',"Add","SIA->EPSBED",array('id'=>'Add')).$frm->addInput('submit',"Add1","SIA(TRNLM->KRS)->EPSBED",array('id'=>'Add1')).$frm->addInput('submit',"Delete","Delete",array('id'=>'Del')).$frm->addInput('submit',"Down","Download TRLNM.DBF",array('id'=>'Down')), null, 'data');
	  	  
	  $isi_fieldset=$html_element->addfieldset('Aksi',$tbl1->display());
	  
	  $isi_fieldset.="<div id='data'>";
	  $isi_fieldset.=$this->epsbed_trnlm(key($dtsem));
	  $isi_fieldset.="</div>";
	  
	  
      $html_txt.=$html_element->addfieldset('Hasil Filter : '.$vtemp,$isi_fieldset,array('id'=>'hsl_filter'));  	  
	  
	  return $html_txt;
	
	}
	 
	 function epsbed_trnlm($thnsms)
	 {	 
	    $tbstat = array("id" => "lst_epsbedtrakd");
	    $header = array(array('NIM','Nama Mahasiswa','Kode','Matakuliah','Nilai','Bobot'));
	    $data_table	= array();
			    
		$dt = new dt_epsbed_trnlm;
	    $data = $dt->getviewData($thnsms);
		
		if(!empty($data)){
		    $dt_mtk = new dt_epsbed_kmk;
		    $dt_mhs = new dt_mhs;
		   foreach($data as $row)
		   {
		     
			  $temp_data=array();
              $temp_data[]=array($row['NIMHSTRNLM'],array());
	          $temp_data[]=array($dt_mhs->getnmmhs($row['NIMHSTRNLM']),array());
	          $temp_data[]=array($row['KDKMKTRNLM'],array());
              $temp_data[]=array($dt_mtk->getnmmtk($thnsms,$row['KDKMKTRNLM']),array());
	          $temp_data[]=array($row['NLAKHTRNLM'],array());
	          $temp_data[]=array($row['BOBOTTRNLM'],array());
	          $data_table[]=$temp_data;
		    
		   }
		   
		} 
		 $txt = '';
					$txt = $txt."<tr>";
						$txt = $txt."<th><input type='text' name='search_nim' value='nim' class='search_init' style='width:51px' /></th>";
						$txt = $txt."<th><input type='text' name='search_mhs' value='nm mhs' class='search_init' /></th>";	
						$txt = $txt."<th><input type='text' name='search_kd' value='kd' class='search_init' style='width:30px'/></th>";
						$txt = $txt."<th><input type='text' name='search_nm' value='nm Mtk' class='search_init' /></th>";											
						$txt = $txt."<th><input type='text' name='search_NM' value='nm' class='search_init' style='width:10px'/></th>";
						$txt = $txt."<th></th>";
											
					$txt = $txt."</tr>";
	 	 
     $html_element = new html_element;
	 $html_txt=$html_element->addfieldset('Statistik',$this->stat('stat2_epsbedtrnlm',$thnsms));
	 
	 $tbl = new mytable($tbstat,$header,$data_table,$txt);	 
	 $html_txt.=$html_element->addfieldset('List Nilai Mahasiswa',$tbl->display());
	 
	 return $html_txt;
	 }
	
	 function stat($tbid,$thn=0)
	 {
	    $tbstat = array("id" => $tbid);	    
	    $data_table	= array();		
			    
        if($thn==0){
		   
		   $header = array(array(array('Semester',array("rowspan"=>2)),array('Jumlah',array("colspan"=>4)),array('SKS',array("colspan"=>2))),
		                   array('Angkatan','Mahasiswa','Matakuliah','Nilai T','Min','Max'));		   
		   
		}else{
		  
		  $header = array(array(array('Angkatan',array("rowspan"=>2)),array('NIM',array("rowspan"=>2)),array('Nama',array("rowspan"=>2)),array('Jumlah',array("colspan"=>3))),
		                   array('Matakuliah','SKS','Nilai T'));	
		}
		
	            
		$dt = new dt_epsbed_trnlm;
		$mythnsem = new mythnsem;
	    $data = $dt->stat($thn);
	    
		if(!empty($data)){
		
		   foreach($data as $f=>$v)
		   {
		      
              if($thn==0){
					   
					   $temp_data=array();				   
					   $temp_data[]=array($mythnsem->gettxtthnsem($f),array());						   
					   $temp_data[]=array($v['jml_ang'].$v['nm_ang'],array());	
					   $temp_data[]=array($v['jml_mhs'],array('align'=>'center'));
					   $temp_data[]=array($v['jml_mtk'],array('align'=>'center'));
					   $temp_data[]=array(isset($v['jml_mtk_t']) ? $v['jml_mtk_t'] : 0, array('align'=>'center'));
					   $temp_data[]=array($v['min_sks'], array('align'=>'center'));
					   $temp_data[]=array($v['max_sks'], array('align'=>'center'));
					   $data_table[]=$temp_data;
			  
			  }else{
                foreach($v as $f1=>$v1)
		       {
			         if( !empty($v1) && is_array($v1)){
						 $dt_mhs = new dt_mhs;
						 foreach($v1 as $f2=>$v2)
						{
						  $temp_data=array();
						  $temp_data[]=array($f1,array());	
						  $temp_data[]=array($f2,array());	
						  $temp_data[]=array($dt_mhs->getnmmhs($f2),array());	
						  $temp_data[]=array($v2['jml_mtk'],array('align'=>'center'));
						  $temp_data[]=array($v2['jml_sks'], array('align'=>'center'));
						  $temp_data[]=array($v2['jml_mtk_t'], array('align'=>'center'));
						  $data_table[]=$temp_data;
						}
                     } 			   
			   } 
			  }			  
			  	
		   }
		
		}
         
	  $tbl = new mytable($tbstat,$header,$data_table,'');
	  return $tbl->display();
	 }
}
?>