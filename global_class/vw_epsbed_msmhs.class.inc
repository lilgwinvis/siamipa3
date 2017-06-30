<?php 

    
	
   require_once 'shared.php';
	

class vw_epsbed_msmhs
 {
	 function __construct()
	 {
	    
	 } 
	
	 function lst_mhs()
	{
	  
      $vmhs = new dt_mhs;
	  $data = $vmhs->getAngkatan();
	  $ang = array();	  
	  array_walk_recursive($data,function($value,$key) use (&$ang){
		  $ang[$value]=$value;
	  });
      
	  $mythnsem = new mythnsem;	  
	  $dtsem=$mythnsem->getlstthnsem('','');
	  
	  $html_element = new html_element;
	  
		  $frm = new HTML_Form();
		  $isi_fieldset='Angkatan '.$frm->addSelectList("Angkatan",$ang,true,null,null,array('id'=>'Angkatan')).$frm->addInput('submit',"Add","SIA->EPSBED",array('id'=>'Add')).$frm->addInput('submit',"Delete","Delete",array('id'=>'Del')).$frm->addInput('submit',"Down","Download MSMHS.DBF",array('id'=>'Down'));
		  $isi_fieldset1=$html_element->addfieldset('Update Data',$isi_fieldset);
		  		  
		  $isi_fieldset='Semester'.$frm->addSelectList("semester",$dtsem,true,null,null,array('id'=>'semester')).$frm->addInput('submit',"Update","Update Status",array('id'=>'Update'));
		  $isi_fieldset1.=$html_element->addfieldset('Update Status',$isi_fieldset);
		  
	  $html_txt=$html_element->addfieldset('Aksi',$isi_fieldset1);
	  	  
	  $html_txt.="<div id='data'>";
	  $html_txt.=$this->epsbed_msmhs();
	  $html_txt.="</div>";
	  
	  return $html_txt;
	
	}
	 
	 function epsbed_msmhs()
	 {	 
	    
		
		$tbstat = array("id" => "lst_epsbedmsmhs");
	    $header = array(array('Angkatan','NIM','Nama Mahasiswa','TTL','Status','B/P','Sem. Awal','Batas Studi','SKS Konversi','NIM Asal','PT Asal','Jen. Asal','Prodi. Asal'));
	    $data_table	= array();
		
		$mythnsem = new mythnsem;	    
		$dt = new dt_epsbed_msmhs;
	    $data = $dt->getData();
		
		if(!empty($data)){
		   
		   $kd_stat = array('A'=>'Aktif','C'=>'Cuti','K'=>'Keluar','L'=>'Lulus','N'=>'Non Aktif');
		   
		   foreach($data as $row)
		   {
		     
			  $temp_data=array();
			  $temp_data[]=array($row['TAHUNMSMHS'],array());
              $temp_data[]=array($row['NIMHSMSMHS'],array());
	          $temp_data[]=array($row['NMMHSMSMHS'],array());  
	          $temp_data[]=array($row['TPLHRMSMHS'].'/'.date("Y-m-d",$row['TGLHRMSMHS']),array());			  
			  $temp_data[]=array($kd_stat[$row['STMHSMSMHS']],array());			  
			  $temp_data[]=array($row['STPIDMSMHS']=='B' ? 'Baru' : 'Pindahan',array());			  
			  $temp_data[]=array($mythnsem->gettxtthnsem($row['SMAWLMSMHS'],'Sem. '),array());			  		  
		      $temp_data[]=array($mythnsem->gettxtthnsem($row['BTSTUMSMHS'],'Sem. '),array());              
              $temp_data[]=array($row['SKSDIMSMHS'],array());
              $temp_data[]=array($row['ASNIMMSMHS'],array());
              $temp_data[]=array($row['ASPTIMSMHS'],array());
              $temp_data[]=array($row['ASJENMSMHS'],array());
              $temp_data[]=array($row['ASPSTMSMHS'],array()); 
              $data_table[]=$temp_data;  			  
		   }
		   
		} 
	     
	    $tbl = new mytable($tbstat,$header,$data_table,"");
		
		
		$tbstat = array("id" => "stat_epsbedmsmhs");
	    $header = array(array(array('Angkatan',array("rowspan"=>2)),array('Status Mahasiswa',array("colspan"=>6)),array('Total',array("rowspan"=>2)),array('B/P',array("colspan"=>2))),
		                array('Aktif','Cuti','DO','Keluar','Lulus','Non Aktif','Pindahan','Baru'));
	    $data_table	= array();
		$footer ='';
		
		$data = $dt->stat();
		if(!empty($data)){		   
		   $tot=0;
		   $jml_stat = array('A'=>0,'C'=>0,'D'=>0,'K'=>0,'L'=>0,'N'=>0);
		   $jml_P=0;
		   $jml_B=0;
		   $tot_P=0;
		   $tot_B=0;
		   foreach($data as $f=>$v)
		   {
		     $temp_data=array();
			 $temp_data[]=array($f,array());
			 $jml=0;
			 foreach($v as $f1=>$v1)
		     {
			   
			   if(($f1!='B') && ($f1!='P')){
			     $temp_data[]=array($v1,array('align'=>'center'));
			     $jml=$jml+$v1;
			     $jml_stat[$f1]=$jml_stat[$f1]+$v1;
			   }else{
			     if($f1=='P'){ 
				   $jml_P=$v1;
				 }else{
				    $jml_B=$v1;
				 }
			   }
			   
			 } 
               $temp_data[]=array($jml,array('align'=>'center'));
			   $tot = $tot+$jml;
			   $temp_data[]=array($jml_P,array('align'=>'center'));
			   $temp_data[]=array($jml_B,array('align'=>'center'));
			   $tot_P = $tot_P+$jml_P;
			   $tot_B = $tot_B+$jml_B;
			   $data_table[]=$temp_data;
		   }
		   
		        $footer = '';
					$footer = $footer."<tr>";
						$footer = $footer."<th>Jumlah</th>";											
						
						foreach($jml_stat as $v){
						  $footer = $footer."<th  align='center' >$v</th>";
						}
                        $footer = $footer."<th  align='center' >$tot</th>";
						$footer = $footer."<th  align='center' >$tot_P</th>";
						$footer = $footer."<th  align='center' >$tot_B</th>";
											
					$footer = $footer."</tr>"; 
		   
		  
		
		
		} 
		
		$tbl2 = new mytable($tbstat,$header,$data_table,$footer);
		
	 $html_element = new html_element;
	 
	 $html_txt=$html_element->addfieldset('Statistik Mahasiswa',$tbl2->display(),array('id'=>'stat_mhs'));
	 $html_txt.=$html_element->addfieldset('List Mahasiswa',$tbl->display(),array('id'=>'lst_mhs'));
	 
	 return $html_txt;
	 }
	 
	 function stat_epsbed_msmhs()
	 {
	 
	 
	 }
	 
}
?>