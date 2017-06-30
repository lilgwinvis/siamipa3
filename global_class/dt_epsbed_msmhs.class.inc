<?php

require_once 'shared.php';

class dt_epsbed_msmhs
{
   var $tb;
   var $idx_array;
   
   function __construct(){
     $this->tb = new tb_epsbed_msmhs;
	 $this->idx_array= array();
	 $data=$this->getData();
	 
	 if(!empty($data))
	 {
	   foreach($data as $row)
	   {
	      foreach($this->tb->fieldname as $fieldnm)
		  {
		    if(!in_array($fieldnm,$this->tb->keyfield)){
			 $this->idx_array[$row['NIMHSMSMHS']][$fieldnm]=$row[$fieldnm];
		    }
		  } 
	   }
	 }  
	 
   }
   
   function getData()
   {      
	  $data = $this->tb->getData();
	  return $data;   
   }
     
   	

	
   function siatoepsbed($thn)
   {
     $fieldarray = array(); 	 
	 $data = $this->getData();
	 if(!empty($data))
	 {
	   foreach($data as $row)
	   {
	      if($row['TAHUNMSMHS'] != $thn){
	          $fieldarray[] = $row;	    
	      }
	   }	 
	 }
	 
	 $dt_mhs = new dt_mhs;
	 
	 $data = $dt_mhs->getAllData("tahunmsmhs=".$thn);
	
	 if(!empty($data))
	 {
	  
	   foreach($data as $row)
	   {	       	  
		  $thn=str_split($row['smawlmsmhs'],4);
		  if($thn[1]==1)
		  {
		    $tglmsk=mktime(0,0,0,1,9,$thn[0]);		  
		  }else
		  {
		    $tglmsk=mktime(0,0,0,1,3,$thn[0]+1);
		  }
		  
		  $fieldarray[] = array('KDPTIMSMHS'=>'041048','KDJENMSMHS'=>'C','KDPSTMSMHS'=>'44201','NIMHSMSMHS'=>strtoupper($row['nimhsmsmhs']),'NMMHSMSMHS'=>strtoupper($row['nmmhsmsmhs']),'SHIFTMSMHS'=>'R','TPLHRMSMHS'=>strtoupper($row['tplhrmsmhs']),'TGLHRMSMHS'=>strtotime($row['tglhrmsmhs']),'KDJEKMSMHS'=>$row['kdjekmsmhs'],'TAHUNMSMHS'=>$row['tahunmsmhs'],'SMAWLMSMHS'=>$row['smawlmsmhs'],'BTSTUMSMHS'=>($row['smawlmsmhs']+30),'ASSMAMSMHS'=>'02','TGMSKMSMHS'=>$tglmsk,'TGLLSMSMHS'=>'','STMHSMSMHS'=>'A','STPIDMSMHS'=>($row['bpmsmhs']==0 ? 'B' : 'P' ),'SKSDIMSMHS'=>'0','ASNIMMSMHS'=>'','ASPTIMSMHS'=>'','ASJENMSMHS'=>'','ASPSTMSMHS'=>'','BISTUMSMHS'=>'','PEKSBMSMHS'=>'','NMPEKMSMHS'=>'','PTPEKMSMHS'=>'','PSPEKMSMHS'=>'','NOPRMMSMHS'=>'','NOKP1MSMHS'=>'','NOKP2MSMHS'=>'','NOKP3MSMHS'=>'','NOKP4MSMHS'=>'');	    
       }	 
	 }
	 
	 
	 $this->tb->writedata($fieldarray);
     //$this->tb->insertRecord($fieldarray);
	 return;
   }
	

    function UpdateData($thn)
   {
     $dt_mhs = new dt_mhs;	 
	 $dt_stat_mhs = new dt_stat_mhs;
	 $data = $dt_stat_mhs->getData('thnsmsstat_mhs='.$thn);
	
	 if(!empty($data))
	 {  
	    
		$dt_ta = new dt_ta;
		$lls = $dt_ta->getdatalls();		
		
		
	    foreach($data as $row)
	   {  	 
		 	 $statmhs="O";
		     switch($row['statstat_mhs'])
			  {
			  case 0 : $statmhs="O";break;
			  case 1 : $statmhs="A";break;
			  case 2 : $statmhs="C";break;
			  case 3 : $statmhs="D";break;
			  case 4 : $statmhs="K";break;
			  case 5 : $statmhs="L";break;
			  case 6 : $statmhs="N";break;
			  }	 
		 
		 $data1 = $dt_mhs->getAllData('nimhsmsmhs="'.$row['nimstat_mhs'].'"');
		   $tplhrmsmhs='';
		   $tglhrmsmhs='';
		   if(!empty($data1)){ 	 
			 foreach($data1 as $row1)
			 { 
			   $tplhrmsmhs=$row1['tplhrmsmhs'];
		       $tglhrmsmhs=$row1['tglhrmsmhs'];
			 }
		   }	 
		 if($statmhs!="O"){		   
		      if($statmhs=="L"){ 		              
		              $this->tb->updateRecord(array('NIMHSMSMHS'=>$row['nimstat_mhs']),array('STMHSMSMHS'=>$statmhs,'TGLLSMSMHS'=>$lls[$row['nimstat_mhs']][0],'TPLHRMSMHS'=>strtoupper($tplhrmsmhs),'TGLHRMSMHS'=>strtotime($tglhrmsmhs)));		              
		      }
		       else{
			         $this->tb->updateRecord(array('NIMHSMSMHS'=>$row['nimstat_mhs']),array('STMHSMSMHS'=>$statmhs,'TGLLSMSMHS'=>'','TPLHRMSMHS'=>strtoupper($tplhrmsmhs),'TGLHRMSMHS'=>strtotime($tglhrmsmhs)));
		           }
		  } 
		    
		 
		 
       }	 
	 }
	 
        
     return;
   }	
	 
	function delData($thn)
   {
     $this->tb->deleteRecord(array('TAHUNMSMHS'=>$thn));  
	 return;
   } 
	 
	 
   function getMSMHS()
   {
   
     return $this->tb->getTablePath();
   }
   
   function stat()
   {
     $fieldarray = array(); 	
	 if(!empty($this->idx_array))
	 {
	   foreach($this->idx_array as $f=>$v)
	   {
	      if(!isset($fieldarray[$v['TAHUNMSMHS']])){   
			$fieldarray[$v['TAHUNMSMHS']]['A'] =	0;    
	        $fieldarray[$v['TAHUNMSMHS']]['C'] =	0;
            $fieldarray[$v['TAHUNMSMHS']]['D'] =	0;  
            $fieldarray[$v['TAHUNMSMHS']]['K'] =	0;  
            $fieldarray[$v['TAHUNMSMHS']]['L'] =	0;  
            $fieldarray[$v['TAHUNMSMHS']]['N'] =	0; 
            $fieldarray[$v['TAHUNMSMHS']]['P'] =	0;
			$fieldarray[$v['TAHUNMSMHS']]['B'] =	0;
			$fieldarray[$v['TAHUNMSMHS']][$v['STMHSMSMHS']] =	1;	
            $fieldarray[$v['TAHUNMSMHS']][$v['STPIDMSMHS']] =	1;			
	      }else{
		     $fieldarray[$v['TAHUNMSMHS']][$v['STMHSMSMHS']] =	$fieldarray[$v['TAHUNMSMHS']][$v['STMHSMSMHS']]+1;
			 $fieldarray[$v['TAHUNMSMHS']][$v['STPIDMSMHS']] =	$fieldarray[$v['TAHUNMSMHS']][$v['STPIDMSMHS']]+1;
		  }
	   }	 
	 }
   
     return  $fieldarray;
   
   }
   
   function get_tahunmsmhs($nim){
     $tmp_txt=isset($this->idx_array[$nim]) ? $this->idx_array[$nim]['TAHUNMSMHS']   : $nim;   
     return $tmp_txt;
   }
   
}

?>