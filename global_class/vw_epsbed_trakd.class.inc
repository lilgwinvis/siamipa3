<?php 

    
	require_once 'shared.php';
	

class vw_epsbed_trakd
 {
	 function __construct()
	 {
	    
	 } 
	
	 function sem_filter()
	{
	  set_time_limit(120);
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
	  $tbl1->addCell($frm->addInput('submit',"Add","SIA->EPSBED",array('id'=>'Add')).$frm->addInput('submit',"Delete","Delete",array('id'=>'Del')).$frm->addInput('submit',"Down","Download TRAKD.DBF",array('id'=>'Down')), null, 'data');
	  
	  $isi_fieldset=$html_element->addfieldset('Aksi',$tbl1->display());	  
	  
	  $isi_fieldset.="<div id='data'>";
	  $isi_fieldset.=$this->epsbed_trakd(key($dtsem));
	  $isi_fieldset.="</div>";
	  
	  $html_txt.=$html_element->addfieldset('Hasil Filter : '.$vtemp,$isi_fieldset,array('id'=>'hsl_filter'));  
	  
	  return $html_txt;
	
	}
	 
	 function epsbed_trakd($thnsms)
	 {	 
	    set_time_limit(120);
		$tbstat = array("id" => "lst_epsbedtrakd");
	    $header = array(array('NIDN','Nama Dosen','Kode','Matakuliah','Kelas','Rencana','Realisasi'));
	    $data_table	= array();
			    
		$dt = new dt_epsbed_trakd;
	    $data = $dt->getviewdata($thnsms);
		
		if(!empty($data)){
		    $dt_mtk = new dt_epsbed_kmk;
		    $dt_dsn = new dt_dosen;
		   foreach($data as $row)
		   {
		      
			  $temp_data=array();
              $temp_data[]=array($row['NODOSTRAKD'],array());
	          $temp_data[]=array($dt_dsn->getnmdsn($row['NODOSTRAKD']),array());
	          $temp_data[]=array($row['KDKMKTRAKD'],array());
              $temp_data[]=array($dt_mtk->getnmmtk($thnsms,$row['KDKMKTRAKD']),array());
	          $temp_data[]=array($row['KELASTRAKD'],array());
	          $temp_data[]=array($row['TMRENTRAKD'],array());
	          $temp_data[]=array($row['TMRELTRAKD'],array());
			  $data_table[]=$temp_data;
		    
		   }
		   
		}
		           $txt = '';
					$txt = $txt."<tr>";
						$txt = $txt."<th><input type='text' name='search_nidn' value='NIDN' class='search_init' style='width:51px' /></th>";
						$txt = $txt."<th><input type='text' name='search_dsn' value='nm dsn' class='search_init' /></th>";	
						$txt = $txt."<th><input type='text' name='search_nim' value='NIM' class='search_init' style='width:30px'/></th>";
						$txt = $txt."<th><input type='text' name='search_nm' value='nm Mtk' class='search_init' /></th>";											
						$txt = $txt."<th><input type='text' name='search_kls' value='Kls' class='search_init' style='width:10px'/></th>";
						$txt = $txt."<th></th>";
						$txt = $txt."<th></th>";
											
					$txt = $txt."</tr>";
					
	
	 
	 $html_element = new html_element;
	 $html_txt=$html_element->addfieldset('Statistik',$this->stat('stat2_epsbedtrnlm',$thnsms));
	 
	 $tbl = new mytable($tbstat,$header,$data_table,$txt);	 
	 $html_txt.=$html_element->addfieldset('List Aktifitas Dosen',$tbl->display());
	 
	 return $html_txt;
	 }
	
	function stat($tbid,$thn=0)
	 {
	    $tbstat = array("id" => $tbid);	    
	    $data_table	= array();
			    
        if($thn==0){		   
		   $header = array(array(array('Semester',array("rowspan"=>2)),array('Jumlah',array("colspan"=>5))),
		                   array('Dosen','Matakuliah','Kelas','Min. SKS','Max. SKS'));		  
		}else{		  
		  $header = array(array(array('NIDN',array("rowspan"=>2)),array('Nama',array("rowspan"=>2)),array('Jumlah',array("colspan"=>3))),
		                   array('Matakuliah','SKS','Kelas'));		  
		}
		        
		$dt = new dt_epsbed_trakd;
		$mythnsem = new mythnsem;
	    $data = $dt->stat($thn);
	    $txt='';
		if(!empty($data)){
			      
              if($thn==0){
				foreach($data as $f=>$v)
		       {
			           $temp_data=array();					   
					   $temp_data[]=array($mythnsem->gettxtthnsem($f),array());					   
					   $temp_data[]=array($v['jml_dsn'],array('align'=>'center'));
					   $temp_data[]=array($v['jml_mtk'],array('align'=>'center'));
					   $temp_data[]=array($v['jml_kelas'],array('align'=>'center'));
					   $temp_data[]=array($v['jml_min_sks'],array('align'=>'center'));
					   $temp_data[]=array($v['jml_max_sks'],array('align'=>'center'));
					   $data_table[]=$temp_data;                   			   
			   } 
			   
			  
			  }else{
                $dt_dsn = new dt_dosen;
				foreach($data as $f=>$v)
		       {
			          if($f!='Jumlah'){   					 
						  $temp_data=array();
						  $temp_data[]=array($f, null, 'data');
						  $temp_data[]=array($dt_dsn->getnmdsn($f), array());						  
						  $temp_data[]=array($v['jml_mtk'], array('align'=>'center'));
						  $temp_data[]=array($v['jml_sks'], array('align'=>'center'));
						  $temp_data[]=array($v['jml_kelas'],array('align'=>'center'));
						  $data_table[]=$temp_data;
					    }else{
                          $txt = $txt."<tr>";
						  $txt = $txt."<th colspan='2'>Jumlah</th>";					  
						  $txt = $txt."<th  align='center' >".$v['jml_mtk']."</th>";
						  $txt = $txt."<th  align='center' >".$v['jml_sks']."</th>";
						  $txt = $txt."<th  align='center' >".$v['jml_kelas']."</th>";
						  $txt = $txt."</tr>";
                         }						
                    			   
			   } 
			  }			  
			  	
		   
		
		}
         
	  $tbl = new mytable($tbstat,$header,$data_table,$txt);
	  return $tbl->display();
	 }
	
}
?>