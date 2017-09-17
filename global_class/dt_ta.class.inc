<?php
 require_once 'shared.php';

class dt_ta 
{  
   var $numrows;
      
   function __construct()
   {
      	  	  
   }
    
   function getdatalls()
   {
        $lls = array();
        
		
		$vtrans= new dt_trans;
		$dtnidnbim= new tb_gen('vw_nidnbim');
		$data = $dtnidnbim->getData('');
		
		if(!empty($data)){
		
		   foreach($data as $row)
		   {
		    $tmp_awl=(strlen($row['awlbim'])<6 ? '0'.$row['awlbim']:$row['awlbim']);
			$tmp_akh=(strlen($row['akhbim'])<6 ? '0'.$row['akhbim']: $row['akhbim']);
			    
				$hsl = $vtrans->hitipk($row["nimhssidang"]);
				$ipk = $hsl['jml_sks']!=0 ? $hsl['jml_sksnm']/$hsl['jml_sks'] :0.00; 
				
			$lls[$row['nimhssidang']]=array(mktime(0,0,0,$row['tgl'],$row['bln'],$row['thn']),number_format($ipk, 2, '.', ''),$tmp_awl,$tmp_akh,$row['nidn_pemb1'],$row['nidn_pemb2']);		   
		   }
		
		//$lls['F1A080004']=array(mktime(0,0,0,7,22,2013),3.32,'022011','072013','0402108204','0404037103');
        //$lls['F1A080005']=array(mktime(0,0,0,7,22,2013),3.11,'022011','072013','0402108204','0404037103'); 
		//$lls['F1A090002']=array(mktime(0,0,0,2,22,2014),3.25,'022012','022014','0402108204','0404037103');
        //$lls['F1A090004']=array(mktime(0,0,0,2,22,2014),3.10,'022012','022014','0402108204','0404037103'); 
        //$lls['F1A090005']=array(mktime(0,0,0,2,22,2014),3.60,'022012','022014','0402108204','0404037103');	
        //$lls['F1A090012']=array(mktime(0,0,0,2,22,2014),3.27,'022012','022014','0403037403','0404037103');
        //$lls['F1A090014']=array(mktime(0,0,0,2,22,2014),3.12,'022012','022014','0403037403','0402108204');
        //$lls['F1A090015']=array(mktime(0,0,0,2,22,2014),3.21,'022012','022014','0404037103','0403067801');    		
	   	//$lls['F1A090019']=array(mktime(0,0,0,2,22,2014),3.01,'022011','022014','0404037103','0402108204');
        //$lls['F1A090022']=array(mktime(0,0,0,2,22,2014),3.63,'022012','022014','0404037103','0403067801'); 
		//$lls['F1A100002']=array(mktime(0,0,0,2,22,2014),3.18,'092013','022014','0404037103','0403067801'); 
		//$lls['F1A100006']=array(mktime(0,0,0,2,22,2014),3.41,'092013','022014','0404037103','0403067801');
   
        }
    return $lls; 
   }   
	
   function gettema($id)
   {
      $dtbimbingan = new tb_gen('tbbimbingan');
      $data =  $dtbimbingan->getData('idbimbingan="'.$id.'"');  
      $tema='';
	  if(!empty($data))
	 {
	  
	   foreach($data as $row)
	   {
	     $tema = $row['temabimbingan'];
	   }
	 }
	 return $tema;
   }
   
   
	 
   function getDataViewBimbingan()
   {
     
	            $user = $_SESSION['user'];
	            		         
		        $dtuser = new dt_user;
                $hak = $dtuser->gethak($user); 
	 
	 
	 $dtvbimbingan = new tb_gen('vw_bimbingan');
     $data =  $dtvbimbingan->getData('');     
	 
	 $dtvpembimbing = new tb_gen('vw_pembimbing');
	 
	 $temp_data=array();
		 
	 if(!empty($data))
	 {
	  
	   foreach($data as $row)
	   {
           $pembimbing='';
		   $dokumen='';
		   if($row['idbimbingan']==''){	
		      if($hak==0){
				$link ="Add";  
			  }		      
			  else{
  			    $link ="<a href='frm_dt_bimbingan_entry.php?idx=1&thn=".$row['thsmskrs']."&nim=".$row['nimhskrs']."'>Add</a>";
		      }
		   }else{
		      if($hak==0){
				$link ="Edit<br>Delete";  
			  }		      
			  else{
			   $link ="<a href='frm_dt_bimbingan_entry.php?idx=2&id=".$row['idbimbingan']."'>Edit</a><br><a href='javascript:hapus(".'"'.$row['idbimbingan'].'"'.")'>Delete</a>";
			  }
			  
			 $data1 = $dtvpembimbing->getData('id = "'.$row['idbimbingan'].'"');
			 if(!empty($data1))
			 {
			    $pembimbing='<ol>';
			   foreach($data1 as $row1)
			   {
			     $pembimbing.='<li>'.$row1['Nama'].'</li>';
			   }
			   $pembimbing.='</ol>';
			 }
			   $dokumen='<table>';
				if($row['nosrttgs']!=''){
				 $dokumen.='<tr><td>Tgs</td><td>'.$row['nosrttgs'].'<br>'.$row['tglsrttgs'].'</td></tr>';
				}
                if($row['nosk']!=''){				
				 $dokumen.='<tr><td>SK</td><td>'.$row['nosk'].'<br>'.$row['tglsk'].'</td></tr>';
			    }
				
		 	   $dokumen.='</table>'; 	
		   }
		   
		   
		   
		   
		   $temp_data[] = array(array($row['thsmskrs'],array()),
								array($row['nimhskrs'],array()),
								array($row['nmmhsmsmhs'],array()),
								array($row['temabimbingan'],array()),
								array($pembimbing,array()),
                                array($dokumen,array()),								
								array($link,array('align'=>'center')));
		
	   }          
	   
	 }
	
     return $temp_data;
   }

   function getDataViewBimbingan1()
   {      
	 
	 $dtvbimbingan = new tb_gen('vw_bimbingan');
     $data =  $dtvbimbingan->getData('');     
	 
	 $dtvpembimbing = new tb_gen('vw_pembimbing');
	 
	 $temp_data=array();
		 
	 if(!empty($data))
	 {
	  
	   foreach($data as $row)
	   {
           $pembimbing='';
		   
		   
		     			  
			 $data1 = $dtvpembimbing->getData('id = "'.$row['idbimbingan'].'"');
			 if(!empty($data1))
			 {
			    $pembimbing='<ol>';
			   foreach($data1 as $row1)
			   {
			     $pembimbing.='<li>'.$row1['Nama'].'</li>';
			   }
			   $pembimbing.='</ol>';
			 }
			   	
		   	   
		   
		   $temp_data[] = array(array($row['nimhskrs'],array()),
								array($row['nmmhsmsmhs'],array()),
								array($row['temabimbingan'],array()),
								array($pembimbing,array()));		
	   }          
	   
	 }
	
     return $temp_data;
   }


   function getDataViewHBimbingan()
   {
     	  
	            $user = $_SESSION['user'];
	            		         
		        $dtuser = new dt_user;
                $hak = $dtuser->gethak($user); 
	 
	 $dtvhbimbingan = new tb_gen('vw_hbimbingan');
     $data =  $dtvhbimbingan->getData('');
	 
	 $dtvpembimbing = new tb_gen('vw_pembimbing');
	 
	 $temp_data=array();
	
	 
	 if(!empty($data))
	 {
	  
	   foreach($data as $row)
	   {
        $pembimbing='';
		$dokumen='';
		if($row['idbimbingan']==''){		   
		     if($hak==0){
				$link ="Add";  
			  }		      
			  else{
			    $link ="<a href='frm_dt_bimbingan_entry.php?idx=1&thn=".$row['thsmstrnlm']."&nim=".$row['nimhstrnlm']."'>Add</a>";
		      }
		   }else{
		        if($hak==0){
				   $link ="Edit<br>Delete";  
			    }		      
			    else{
			        $link ="<a href='frm_dt_bimbingan_entry.php?idx=2&id=".$row['idbimbingan']."'>Edit</a><br><a href='javascript:hapus(".'"'.$row['idbimbingan'].'"'.")'>Delete</a>";		   
			    }
			 $data1 = $dtvpembimbing->getData('id = "'.$row['idbimbingan'].'"');
			 if(!empty($data1))
			 {
			   $pembimbing='<ol>';
			   foreach($data1 as $row1)
			   {
			     $pembimbing.='<li>'.$row1['Nama'].'</li>';
			   }
			   $pembimbing.='</ol>';
			 }
			 
			    $dokumen='<table>';
				if($row['nosrttgs']!=''){
				 $dokumen.='<tr><td>Tgs</td><td>'.$row['nosrttgs'].'<br>'.$row['tglsrttgs'].'</td></tr>';
				}
                if($row['nosk']!=''){				
				 $dokumen.='<tr><td>SK</td><td>'.$row['nosk'].'<br>'.$row['tglsk'].'</td></tr>';
			    }
				
		 	   $dokumen.='</table>'; 			    
		   }
		
		$temp_data[] = array(array($row['thsmstrnlm'],array()),
								array($row['nimhstrnlm'],array()),
								array($row['nmmhsmsmhs'],array()),
								array($row['temabimbingan'],array()),
								array($pembimbing,array()),		
                                array($dokumen,array()),								
								array($link,array('align'=>'center')));
	   }
         
	   
	 }
     return $temp_data;
   }
   
   function getDataViewSidang()
   {
     
	            $user = $_SESSION['user'];
	            		         
		        $dtuser = new dt_user;
                $hak = $dtuser->gethak($user); 
	 
	 $dtvsidang = new tb_gen('vw_sidang');
     $data =  $dtvsidang->getData('');     
	 
	 $dtvpenguji = new tb_gen('vw_penguji');
	 
	 $temp_data=array();
		 
	 if(!empty($data))
	 {
	  
	   foreach($data as $row)
	   {
           $penguji='';
		   $dokumen='';
		   if($row['idsidang']==''){	
		      if($hak==0){
				$link ="Add";  
			  }		      
			  else{  
		        $link ="<a href='frm_dt_sidang_entry.php?idx=1&thn=".$row['thsmsbimbingan']."&nim=".$row['nimhsbimbingan']."&idbimbingan=".$row['idbimbingan']."'>Add</a>";
		      }
		  }else{
		      if($hak==0){
				   $link ="Edit<br>Delete";  
			    }		      
			    else{
			       $link ="<a href='frm_dt_sidang_entry.php?idx=2&id=".$row['idsidang']."&idbimbingan=".$row['idbimbingan']."'>Edit</a><br><a href='javascript:hapus(".'"'.$row['idsidang'].'"'.")'>Delete</a>";
                }
			 $data1 = $dtvpenguji->getData('id = "'.$row['idsidang'].'"');
			 if(!empty($data1))
			 {
			   $penguji='<ol>';
			   foreach($data1 as $row1)
			   {
			     $penguji.='<li>'.$row1['Nama'].'</li>';
			   }
			   $penguji.='</ol>';
			 }
			  
			    $dokumen='<table>';
			  if($row['tglskpenguji']!=''){
				 $dokumen.='<tr><td>sk</td><td>'.$row['noskpenguji'].'<br>'.$row['tglskpenguji'].'</td></tr>';
				}
              if($row['tgllls']!=''){
				 $dokumen.='<tr><td>lls</td><td>'.$row['tgllls'].'</td></tr>';
				} 
			   if($row['abs_indo']!=''){
				 $dokumen.='<tr><td>abs_indo</td><td>Ya</td></tr>';
				} 
			   if($row['abs_ing']!=''){
				 $dokumen.='<tr><td>abs_ing</td><td>Ya</td></tr>';
				} 
               if($row['nidn_pemb1']!=''){
				 $dokumen.='<tr><td>NIDN 1</td><td>'.$row['nidn_pemb1'].'</td></tr>';
				}
                if($row['nidn_pemb2']!=''){				
				 $dokumen.='<tr><td>NIDN 2</td><td>'.$row['nidn_pemb2'].'</td></tr>';
			    } 				
				
			  $dokumen.='</table>';
		 	 
				
		   }
		   
		   
		   
		   
				  $temp = array(array($row['thsmsbimbingan'],array()),
										array($row['nimhsbimbingan'],array()),
										array($row['nmmhsmsmhs'],array()),
										array($row['jdlskripsi'],array()),
										array($penguji,array()),	
										array($row['tglsidang'],array()),	
										array($row['sesi'],array()),	  								
										array($dokumen,array()),								
										array($link,array('align'=>'center')));
		         if($row['idsidang']==''){ 
		            $temp[3]=array($row['temabimbingan'],array());
				 }
				 $temp_data[] =$temp;
	   }          
	   
	 }
	
     return $temp_data;
   }
   function getDataViewHSidang()
   {
	   
	            $user = $_SESSION['user'];
	            	         
		        $dtuser = new dt_user;
                $hak = $dtuser->gethak($user); 
	   
    $dtvhsidang = new tb_gen('vw_hsidang');
    $data =  $dtvhsidang->getData('');
	 
	 $dtvpenguji = new tb_gen('vw_penguji');
	 
	 $temp_data=array();
	
	 
	 if(!empty($data))
	 {
	  
	   foreach($data as $row)
	   {
        $penguji='';
		$dokumen='';
		if($row['idsidang']==''){		   
		     if($hak==0){
				$link ="Add";  
			  }		      
			  else{ 
			   $link ="<a href='frm_dt_sidang_entry.php?idx=1&thn=".$row['thsmsbimbingan']."&nim=".$row['nimhsbimbingan']."&idbimbingan=".$row['idbimbingan']."'>Add</a>";
		      }
		   }else{
		      if($hak==0){
				   $link ="Edit<br>Delete";  
			    }		      
			    else{
			 
			      $link ="<a href='frm_dt_sidang_entry.php?idx=2&id=".$row['idsidang']."&idbimbingan=".$row['idbimbingan']."'>Edit</a><br><a href='javascript:hapus(".'"'.$row['idsidang'].'"'.")'>Delete</a>";		   
				}
			 
			 $data1 = $dtvpenguji->getData('id = "'.$row['idsidang'].'"');
			 if(!empty($data1))
			 {
			   $penguji='<ol>';
			   foreach($data1 as $row1)
			   {
			     $penguji.='<li>'.$row1['Nama'].'</li>';
			   }
			   $penguji.='</ol>';
			 }
			   $dokumen='<table>';
			  if($row['tglskpenguji']!=''){
				 $dokumen.='<tr><td>sk</td><td>'.$row['noskpenguji'].'<br>'.$row['tglskpenguji'].'</td></tr>';
				}
              if($row['tgllls']!=''){
				 $dokumen.='<tr><td>lls</td><td>'.$row['tgllls'].'</td></tr>';
				} 
			  
			  if($row['abs_indo']!=''){
				 $dokumen.='<tr><td>abs_indo</td><td>Ya</td></tr>';
				} 
			   if($row['abs_ing']!=''){
				 $dokumen.='<tr><td>abs_ing</td><td>Ya</td></tr>';
				} 	
			  if($row['nidn_pemb1']!=''){
				 $dokumen.='<tr><td>NIDN 1</td><td>'.$row['nidn_pemb1'].'</td></tr>';
				}
                if($row['nidn_pemb2']!=''){				
				 $dokumen.='<tr><td>NIDN 2</td><td>'.$row['nidn_pemb2'].'</td></tr>';
			    }
			  $dokumen.='</table>';
		   }
		
		  $temp = array(array($row['thsmsbimbingan'],array()),
								array($row['nimhsbimbingan'],array()),
								array($row['nmmhsmsmhs'],array()),
								array($row['jdlskripsi'],array()),
								array($penguji,array()),	
                                array($row['tglsidang'],array()),	
                                array($row['sesi'],array()),	  								
                                array($dokumen,array()),								
								array($link,array('align'=>'center')));
		 
		 if($row['idsidang']==''){ 
		            $temp[3]=array($row['temabimbingan'],array());
				 }
				 $temp_data[] =$temp;						
								
	   }
         
	   
	 }
     return $temp_data;
   }

   
   function getDataViewHSidang1()
   {
	   
		   
     $dtvhsidang = new tb_gen('vw_hsidang');
     $dtvhsidang->sql_orderby = 'tglsidang,sesi';
	 $data =  $dtvhsidang->getData('tglsidang>=now()');
	 
	 $dtvpenguji = new tb_gen('vw_penguji');
	 
	 $temp_data=array();
	
	 
	 if(!empty($data))
	 {
	  
	   foreach($data as $row)
	   {
        $penguji=array();
		
		if($row['idsidang']==''){		   
		    
			 
			 $data1 = $dtvpenguji->getData('id = "'.$row['idsidang'].'"');
			 if(!empty($data1))
			 {
			   
			   foreach($data1 as $row1)
			   {
			     $penguji[$row['penugasan']]=$row1['Nama'];
			   }
			   
			 }
			  
		   }
		
		  $temp = array(array(date_format(date_create($row['tglsidang']),'d F Y'),array()),	
                                array($row['sesi'],array()),
								array($row['nmmhsmsmhs'],array()),
								array($row['jdlskripsi'],array()),
								array(isset($penguji[1]) ? $penguji[1] : '',array()),
								array(isset($penguji[2]) ? $penguji[1] : '',array()),
								array(isset($penguji[3]) ? $penguji[1] : '',array()));
		 
		 
				 $temp_data[] =$temp;						
								
	   }
         
	   
	 }
     return $temp_data;
   }
   
   
   function getJudulSkripsi()
   {
	   
		   
     $dtvhsidang = new tb_gen('vw_hsidang');
     $dtvhsidang->sql_orderby = 'tgllls desc';
	 $data =  $dtvhsidang->getData('not isnull(tgllls)');
	 
	 $dtvpembimbing = new tb_gen('vw_pembimbing');
	 
	 $temp_data=array();	 
	 if(!empty($data))
	 {
	   $i=1;
	   foreach($data as $row)
	   {
          $data1 = $dtvpembimbing->getData('id = "'.$row['idbimbingan'].'"');
			 $pembimbing=array();
			 if(!empty($data1))
			 {
			   
			   foreach($data1 as $row1)
			   {
			     $pembimbing[$row1['penugasan']]=$row1['Nama'];
			   }
			   
			 }
		  
		  
		  $temp = array(array($i++,array()),array(date_format(date_create($row['tgllls']),'d F Y'),array()),                                
								array($row['nmmhsmsmhs'],array()),
								array($row['jdlskripsi'],array()),
								array($pembimbing[1],array()),
								array($pembimbing[2],array()));
		 
				 $temp_data[] =$temp;						
								
	   }
         
	   
	 }
     return $temp_data;
   }
   
   
    function editDataBimbingan($thn,$nim,$tema,$tglsrttgs,$tglsk,$nosrttgs,$nosk,$pemb1,$pemb2)
	{
	  $tb_bimbingan = new tb_gen('tbbimbingan');
	  $today = date("Y-m-d H:i:s");
	  $idbimbingan='B'.$thn.$nim; 
	  $data=array('idbimbingan'=>$idbimbingan,'thsmsbimbingan'=>$thn,'nimhsbimbingan'=>$nim,'nosrttgs'=>$nosrttgs,'nosk'=>$nosk,'tglinput'=>$today);
	  
	  if($tema!='undefined'){
	     $data['temabimbingan']=mysql_escape_string($tema);
	  }
	  if($tglsrttgs!=''){
	     $data['tglsrttgs']=$tglsrttgs;
	  } 
	  if($tglsk!=''){
	      $data['tglsk']=$tglsk;
	  }
	  
	  $tb_bimbingan->updateRecord($data);    
	  
	  $tb_penugasan = new tb_gen('tbpenugasan');
	  
	  $data=array('id'=>$idbimbingan);
	  $tb_penugasan->deleteRecord($data); 
	 
	  
	  if($pemb1!=''){  
		$data=array('id'=>$idbimbingan,'kddsn'=>$pemb1,'penugasan'=>1);
	    $tb_penugasan->insertRecord($data); 
	  }
      if($pemb2!=''){ 	  
	    $data=array('id'=>$idbimbingan,'kddsn'=>$pemb2,'penugasan'=>2);
	    $tb_penugasan->insertRecord($data);  
	  }
	
	  return 0;
	}
		
	
	
	function insertDataBimbingan($thn,$nim,$tema,$tglsrttgs,$tglsk,$nosrttgs,$nosk,$pemb1,$pemb2)
	{
	  $tb_bimbingan = new tb_gen('tbbimbingan');
	  $today = date("Y-m-d H:i:s");
	  $idbimbingan='B'.$thn.$nim; 
	  $data=array('idbimbingan'=>$idbimbingan,'thsmsbimbingan'=>$thn,'nimhsbimbingan'=>$nim,'nosrttgs'=>$nosrttgs,'nosk'=>$nosk,'tglinput'=>$today);
	  if($tema!='undefined'){
	     $data['temabimbingan']=mysql_escape_string($tema);
	  }
	  if($tglsrttgs!=''){
	     $data['tglsrttgs']=$tglsrttgs;
	  } 
	  if($tglsk!=''){
	      $data['tglsk']=$tglsk;
	  }
	  
	  if(($tema!='undefined') or ($tglsrttgs!='') or ($tglsk!='') or ($nosrttgs!='') or ($nosk!='') or ($pemb1!='') or ($pemb2!='') )
	  {
	   $tb_bimbingan->insertRecord($data);    
	  }
	  
	  $tb_penugasan = new tb_gen('tbpenugasan');
	  if($pemb1!=''){  
		$data=array('id'=>$idbimbingan,'kddsn'=>$pemb1,'penugasan'=>1);
	    $tb_penugasan->insertRecord($data); 
	  }
      if($pemb2!=''){ 	  
	    $data=array('id'=>$idbimbingan,'kddsn'=>$pemb2,'penugasan'=>2);
	    $tb_penugasan->insertRecord($data);  
	  }
	  return 0; 
	}
	
    function editDataSidang($idbimbingan,$thn,$nim,$judul,$absindo,$absing,$tglsid,$sesi,$tgllls,$tglsk,$nosk,$pengu1,$pengu2,$pengu3,$pengu4,$NIDNPemb1,$NIDNPemb2)
	{
	  $tb_sidang = new tb_gen('tbsidang');
	  $today = date("Y-m-d H:i:s");
	  $idsidang='S'.$thn.$nim; 
	  $data=array('idsidang'=>$idsidang,'thsmssidang'=>$thn,'nimhssidang'=>$nim,'noskpenguji'=>$nosk,'sesi'=>$sesi,'idbimbingan'=>$idbimbingan,'nidn_pemb1'=>$NIDNPemb1,'nidn_pemb2'=>$NIDNPemb2,'tglinput'=>$today);
	  if($judul!='undefined'){
	     $data['jdlskripsi']=addslashes($judul);
	  }
	  if($absindo!='undefined'){
	     $data['abs_indo']=addslashes($absindo);
	  }
	  if($absing!='undefined'){
	     $data['abs_ing']=addslashes($absing);
	  }	  
	  if($tglsk!=''){
	     $data['tglskpenguji']=$tglsk;
	  } 
	  if($tglsid!=''){
	      $data['tglsidang']=$tglsid;
	  }
	  if($tgllls!=''){
	      $data['tgllls']=$tgllls;
	  }
	  
	  $tb_sidang->updateRecord($data);    
	  
	  $tb_penugasan = new tb_gen('tbpenugasan');
	  
	  $data=array('id'=>$idsidang);
	  $tb_penugasan->deleteRecord($data); 
	 
	  
	  if($pengu1!=''){  
		$data=array('id'=>$idsidang,'kddsn'=>$pengu1,'penugasan'=>1);
	    $tb_penugasan->insertRecord($data); 
	  }
      if($pengu2!=''){ 	  
	    $data=array('id'=>$idsidang,'kddsn'=>$pengu2,'penugasan'=>2);
	    $tb_penugasan->insertRecord($data);  
	  }
	  if($pengu3!=''){ 	  
	    $data=array('id'=>$idsidang,'kddsn'=>$pengu3,'penugasan'=>3);
	    $tb_penugasan->insertRecord($data);  
	  }
	  if($pengu4!=''){ 	  
	    $data=array('id'=>$idsidang,'kddsn'=>$pengu4,'penugasan'=>4);
	    $tb_penugasan->insertRecord($data);  
	  }
	
	  return 0;
	}
		
	
	
	function insertDataSidang($idbimbingan,$thn,$nim,$judul,$absindo,$absing,$tglsid,$sesi,$tgllls,$tglsk,$nosk,$pengu1,$pengu2,$pengu3,$pengu4,$NIDNPemb1,$NIDNPemb2)
	{
	  $tb_sidang = new tb_gen('tbsidang');
	  $today = date("Y-m-d H:i:s");
	  $idsidang='S'.$thn.$nim; 
	  $data=array('idsidang'=>$idsidang,'thsmssidang'=>$thn,'nimhssidang'=>$nim,'noskpenguji'=>$nosk,'sesi'=>$sesi,'idbimbingan'=>$idbimbingan,'nidn_pemb1'=>$NIDNPemb1,'nidn_pemb2'=>$NIDNPemb2,'tglinput'=>$today);
	  if($judul!='undefined'){	     
	     $data['jdlskripsi']=addslashes($judul);
	  }else{
	     $tema= $this->gettema($idbimbingan);
		 $data['jdlskripsi']=addslashes($tema);
	  }
	  if($absindo!='undefined'){
	     $data['abs_indo']=addslashes($absindo);
	  }
	  if($absing!='undefined'){
	     $data['abs_ing']=addslashes($absing);
	  }	  
	  if($tglsk!=''){
	     $data['tglskpenguji']=$tglsk;
	  } 
	  if($tglsid!=''){
	      $data['tglsidang']=$tglsid;
	  }
	  if($tgllls!=''){
	      $data['tgllls']=$tgllls;
	  }
	  
	  if(($judul!='undefined')or($absindo!='undefined')or($absing!='undefined')or($tglsk!='')or($tglsid!='') or ($tgllls!='') or ($nosk!='') or ($sesi!=''))
	  {
	   $tb_sidang->insertRecord($data);    
	  }
	  
	  $tb_penugasan = new tb_gen('tbpenugasan');
	  if($pengu1!=''){  
		$data=array('id'=>$idsidang,'kddsn'=>$pengu1,'penugasan'=>1);
	    $tb_penugasan->insertRecord($data); 
	  }
      if($pengu2!=''){ 	  
	    $data=array('id'=>$idsidang,'kddsn'=>$pengu2,'penugasan'=>2);
	    $tb_penugasan->insertRecord($data);  
	  }
	  if($pengu3!=''){ 	  
	    $data=array('id'=>$idsidang,'kddsn'=>$pengu3,'penugasan'=>3);
	    $tb_penugasan->insertRecord($data);  
	  }
	  if($pengu4!=''){ 	  
	    $data=array('id'=>$idsidang,'kddsn'=>$pengu4,'penugasan'=>4);
	    $tb_penugasan->insertRecord($data);  
	  }

	  return 0; 
	}
	
	
	
}


?>