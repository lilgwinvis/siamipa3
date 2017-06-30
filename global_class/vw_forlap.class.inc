<?php 
  require_once 'shared.php';
	

class vw_forlap
 {
	 function __construct()
	 {
	    
	 } 

	 function vw_dt_forlap()
	 {
		   $vdosen = new dt_dosen;
		   $data = $vdosen->getAllData("nidn IS NOT NULL AND kode !='?????' AND nidn !=''");
		   $vtemp= "";
		   $vkode="";
		   foreach($data as $row){	
                 if(empty($vtemp)){
					$vtemp = $row['Kode']." - ".$row['Nama'];
					$vkode = $row['Kode'];
				 }	
                              
            $dsn[$row['Kode']]=$row['Kode']." - ".$row['Nama'] ;
           }
		
		  $frm = new HTML_Form();
	      $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmfilter"));
	      $tbl->addRow();
	      $tbl->addCell('Nama Dosen '.$frm->addSelectList("Kode",$dsn,true,null,null,array('id'=>'Kode')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filterdsn')), null, 'data');
	      
		  $taghtml = new html_element;
		  $content1 = $taghtml->addfieldset('Filter',$tbl->display()); 
		  $content1.= $taghtml->addfieldset("Hasil Filter : $vtemp","<div id='datadosen'>".$this->dataforlapdsn($vkode)."</div>",array('id'=>'hsl_filterdsn'));
		  		  
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
		  $tbl->addCell('Angkatan '.$frm->addSelectList("Angkatan",$ang,true,null,null,array('id'=>'Angkatan')).' Kelas '.$frm->addSelectList("kls",$kelas,true,null,null,array('id'=>'kls')).' Mahasiswa '.$frm->addSelectList("Mhs",$Mhs,true,null,null,array('id'=>'Mhs')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filtermhs')), null, 'data');
		  
		  $taghtml = new html_element;
		  $content2 = $taghtml->addfieldset('Filter',$tbl->display()); 	
		  $content2 .= $taghtml->addfieldset("Hasil Filter : $vtemp","<div id='datamhs'>".$this->dataforlapmhs($vnim)."</div>",array('id'=>'hsl_filtermhs'));  
  		
		 
		
		 $header = array('Data Dosen','Data Mahasiswa');
         $arrcontent=array($content1,$content2);
		 $mytabs = new mytabs('tabs1',$header,$arrcontent);		
		 
	    return $mytabs->display();    	   
	 
	 }

	 function dataforlapmhs($nim)
	 {  
        $dtmhs = new dt_mhs;	 
		$link = $dtmhs->getforlaplink($nim);
		
		$biodata=array();
		$errortxt="";
		$forlap = new forlap_crawler;
		if(!empty($link)){
		   $tmp_data = $forlap->readbiodatamhs($link);
		   if($tmp_data['errkode']==0)
		   {
			  if(!empty($tmp_data['biodatamhs'])){
				 
				 foreach($tmp_data['biodatamhs'] as $key=>$val){
					$tmp_data1=array();
					$tmp_data1[]=array($key,array('align'=>'right'));
                    $tmp_data1[]=array(':',array('align'=>'center'));
                    $tmp_data1[]=array($val,array('align'=>'left'));
                    $biodata[]=$tmp_data1;  					
				 } 
			  } 
			   
		   }else{
			   $errortxt=$tmp_data['errtxt'];			   
		   }	   
		}
		
		$tbstat = array("id" => "biodata",'width'=>'100%');
		$tbl = new mytable($tbstat,null,$biodata,"");
		
		
		$taghtml = new html_element;
		$content = $taghtml->addfieldset('Biodata',$tbl->display());
		
        $rekapsks=array();
		$errortxt="";
		if(!empty($link)){
		   $tmp_data = $forlap->readrekapsksmhs($link);
           if($tmp_data['errkode']==0)
		   {
			   if(!empty($tmp_data['rekapsksmhs'])){
				   $i=1;
				   foreach($tmp_data['rekapsksmhs'] as $data){
					$tmp_data1=array();
					$tmp_data1[]=array($i,array('align'=>'right'));
					foreach($data as $row){
					 $tmp_data1[]=array($row,array());	
					}
                    $i=$i+1;
					$rekapsks[]=$tmp_data1; 					
				 } 
			   }
			   
			}else{
			   $errortxt=$tmp_data['errtxt'];			   
		   }	   
		}   
		
		$tbstat = array("id" => "rstatklh",'width'=>'100%');		
		$header = array(array('No','Semester','Status','SKS')); 
		$tbl1 = new mytable($tbstat,$header,$rekapsks,"");
		
		$lstmtk=array();
		$errortxt="";
		if(!empty($link)){
		   $tmp_data = $forlap->readlstmtkmhs($link);
           if($tmp_data['errkode']==0)
		   {
		      if(!empty($tmp_data['lstmtkmhs'])){
			       $i=1;
				   foreach($tmp_data['lstmtkmhs'] as $data){
					$tmp_data1=array();
					$tmp_data1[]=array($i,array('align'=>'right'));
					foreach($data as $row){
					 $tmp_data1[]=array($row,array());	
					}
                    $i=$i+1;
					$lstmtk[]=$tmp_data1; 					
				 }
			  }
		   }else{
			   $errortxt=$tmp_data['errtxt'];			   
		   }	   
		}   
		
		$tbstat = array("id" => "rklh",'width'=>'100%');	
		$header = array(array('No','Semester','Kode Mata Kuliah','Matakuliah','SKS'));
		$tbl2 = new mytable($tbstat,$header,$lstmtk,"");
		 
		 
		 $header = array('Riwayat Status Kuliah','Riwayat Studi');
         $arrcontent=array($tbl1->display(),$tbl2->display());
		 $mytabs = new mytabs('tabsmhs',$header,$arrcontent);
		
		 $sumber = '<br>Sumber Data : ';
		 if(!empty($link)){
		    $sumber .="<a target='_blank' href='$link'>$link</a>";
		 }	 
		
		$html_txt=$errortxt.$content.$mytabs->display().$sumber;
		return $html_txt; 
		 
	 }
	 function dataforlapdsn($kode)
	 {
		$dtdosen = new dt_dosen;
		$link = $dtdosen->getforlaplink($kode);
		
		$biodata=array();
		$errortxt="";
		$forlap = new forlap_crawler;
		if(!empty($link)){
		   $tmp_data = $forlap->readbiodatadsn($link);
		   if($tmp_data['errkode']==0)
		   {
			  if(!empty($tmp_data['biodatadsn'])){
				 
				 foreach($tmp_data['biodatadsn'] as $key=>$val){
					$tmp_data1=array();
					$tmp_data1[]=array($key,array('align'=>'right'));
                    $tmp_data1[]=array(':',array('align'=>'center'));
                    $tmp_data1[]=array($val,array('align'=>'left'));
                    $biodata[]=$tmp_data1;  					
				 } 
			  } 
			   
		   }else{
			   $errortxt=$tmp_data['errtxt'];			   
		   }	   
		}
		
		$tbstat = array("id" => "biodata",'width'=>'100%');
		$tbl = new mytable($tbstat,null,$biodata,"");		
		
		$taghtml = new html_element;
		$content = $taghtml->addfieldset('Biodata',$tbl->display());
		
		$rpend=array();
		$errortxt="";
		if(!empty($link)){
		   $tmp_data = $forlap->readrpendidikandsn($link);
           if($tmp_data['errkode']==0)
		   {
			   if(!empty($tmp_data['penddsn'])){
				   $i=1;
				   foreach($tmp_data['penddsn'] as $data){
					$tmp_data1=array();
					$tmp_data1[]=array($i,array('align'=>'right'));
					foreach($data as $row){
					 $tmp_data1[]=array($row,array());	
					}
                    $i=$i+1;
					$rpend[]=$tmp_data1; 					
				 } 
			   }
			   
			}else{
			   $errortxt=$tmp_data['errtxt'];			   
		   }	   
		}
		
		
		
		
		$tbstat = array("id" => "rpendidikan",'width'=>'100%');		
		$header = array(array('No','Perguruan Tinggi','Gelar Akademik','Tanggal Ijazah','Jenjang')); 
		$tbl1 = new mytable($tbstat,$header,$rpend,"");
		
		$rngajar=array();
		$errortxt="";
		if(!empty($link)){
		   $tmp_data = $forlap->readrmengajardsn($link);
           if($tmp_data['errkode']==0)
		   {
			   if(!empty($tmp_data['mengajardsn'])){
				   $i=1;
				   foreach($tmp_data['mengajardsn'] as $data){
					$tmp_data1=array();
					$tmp_data1[]=array($i,array('align'=>'right'));
					foreach($data as $row){
					 $tmp_data1[]=array($row,array());	
					}
                    $i=$i+1;
					$rngajar[]=$tmp_data1; 					
				 } 
			   }
			   
			}else{
			   $errortxt=$tmp_data['errtxt'];			   
		   }	   
		}
			
		$tbstat = array("id" => "rpengajaran",'width'=>'100%');	
		$header = array(array('No','Semester','Kode Mata Kuliah','Nama Matakuliah','Kode Kelas','Perguruan Tinggi'));
		$tbl2 = new mytable($tbstat,$header,$rngajar,"");
		
		$rteliti=array();
		$errortxt="";
		if(!empty($link)){
		   $tmp_data = $forlap->readrpenelitiandsn($link);
           if($tmp_data['errkode']==0)
		   {
			   if(!empty($tmp_data['menelitidsn'])){
				   $i=1;
				   foreach($tmp_data['menelitidsn'] as $data){
					$tmp_data1=array();
					$tmp_data1[]=array($i,array('align'=>'right'));
					foreach($data as $row){
					 $tmp_data1[]=array($row,array());	
					}
                    $i=$i+1;
					$rteliti[]=$tmp_data1; 					
				 } 
			   }
			   
			}else{
			   $errortxt=$tmp_data['errtxt'];			   
		   }	   
		}
		
		
		
		
		$tbstat = array("id" => "rpenelitian",'width'=>'100%');
		$header = array(array('No','Judul Penelitian','Bidang Ilmu','Lembaga','Tahun'));
        $tbl3 = new mytable($tbstat,$header,$rteliti,"");  		
		
		
		 $header = array('Riwayat Pendidikan','Riwayat Mengajar','Penelitian');
         $arrcontent=array($tbl1->display(),$tbl2->display(),$tbl3->display());
		 $mytabs = new mytabs('tabsdsn',$header,$arrcontent);
		
		$sumber = '<br>Sumber Data : ';
		 if(!empty($link)){
		    $sumber .="<a target='_blank' href='$link'>$link</a>";
		 }	 
		
		$html_txt=$errortxt.$content.$mytabs->display().$sumber;
		return $html_txt; 
		 
	 }
 }

?>