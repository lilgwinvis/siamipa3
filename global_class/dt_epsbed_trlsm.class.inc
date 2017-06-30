<?php

require_once 'shared.php';


class dt_epsbed_trlsm
{
   var $tb;
   var $idx_array;
   
   function __construct(){
     $this->tb = new tb_epsbed_trlsm;
	 
	 $this->idx_array= array();
	 $data=$this->getData();
	 
	 if(!empty($data))
	 {
	   foreach($data as $row)
	   {
	      foreach($this->tb->fieldname as $fieldnm)
		  {
		    if(!in_array($fieldnm,$this->tb->keyfield)){
			 $this->idx_array[$row['THSMSTRLSM']][$row['NIMHSTRLSM']][$fieldnm]=$row[$fieldnm];
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
   
   function getviewdata($thnsms)
   {      
	  $fieldarray = array();
	  
	  if(!empty($this->idx_array))
      {
	    if(isset($this->idx_array[$thnsms]))
	   {
	     foreach($this->idx_array[$thnsms] as $f=>$v)
		 {
		    
			   $fieldarray[]=array('NIMHSTRLSM'=>$f,'STMHSTRLSM'=>$v['STMHSTRLSM']);
						
		 }
	   }
	  }
	  
	  return $fieldarray;   
   }
   
   
   function delData($thn)
   {
     $this->tb->deleteRecord(array('THSMSTRLSM'=>$thn));
   }
   
   function siatoepsbed($thn)
   {
        $dtta = new dt_ta;		
		$lls=$dtta->getdatalls();	 
	    
	  
	 $fieldarray = array(); 	 
	 //$data = $this->getData();
	 //if(!empty($data))
	// {
	 //  foreach($data as $row)
	 //  {
	 //     if($row['THSMSTRLSM'] != $thn){
	  //        $fieldarray[] = $row;	    
	 //     }
	 //  }	 
	// }
	 
	 $tmp = str_split($thn,4);
	 
	 if($tmp[1]==1){
	    $thn_1=$tmp[0].'2';
	 }else{
	    $thn_1=($tmp[0]+1).'1';
	 }
	 
	 
	 $dt_stat_mhs = new dt_stat_mhs;	
	 $data = $dt_stat_mhs->getData("thnsmsstat_mhs='$thn'");
	 $stat = array(2 => 'C',3 =>'D',4 => 'K',5 => 'L',6 => 'N');

     $dt_epsbed_trnlm = new dt_epsbed_trnlm;	 
	
	 if(!empty($data))
	 {
	   $dataunik=array();
	   foreach($data as $row)
	   {	     
	     if(!isset($dataunik[$thn.$row['nimstat_mhs']]))
         {		 
		        $dt_epsbed_trnlm->hit_sksbobotsem($thn,$row['nimstat_mhs']);  
				$sks_trnlm =$dt_epsbed_trnlm->jml_skssem;
				$dt_epsbed_trnlm->hit_sksbobotsem($thn_1,$row['nimstat_mhs']);
			    $sks_krs =$dt_epsbed_trnlm->jml_skssem;
               
               if(($sks_trnlm==0) and ($sks_krs!=0)){ 
			   
				 if($row['statstat_mhs']==5){
				    $fieldarray[] = array('THSMSTRLSM'=>$thn,'KDPTITRLSM'=>'041048','KDJENTRLSM'=>'C','KDPSTTRLSM'=>'44201','NIMHSTRLSM'=>$row['nimstat_mhs'],'STMHSTRLSM'=>$stat[$row['statstat_mhs']],'TGLLSTRLSM'=>$lls[$row['nimstat_mhs']][0],'SKSTTTRLSM'=>145,'NLIPKTRLSM'=>$lls[$row['nimstat_mhs']][1],'STLLSTRLSM'=>'S','JNLLSTRLSM'=>'I','BLAWLTRLSM'=>$lls[$row['nimstat_mhs']][2],'BLAKHTRLSM'=>$lls[$row['nimstat_mhs']][3],'NODS1TRLSM'=>$lls[$row['nimstat_mhs']][4],'NODS2TRLSM'=>$lls[$row['nimstat_mhs']][5]);
				 }else {  
				  if($row['statstat_mhs']!=1){	
					$fieldarray[] = array('THSMSTRLSM'=>$thn,'KDPTITRLSM'=>'041048','KDJENTRLSM'=>'C','KDPSTTRLSM'=>'44201','NIMHSTRLSM'=>$row['nimstat_mhs'],'STMHSTRLSM'=>$stat[$row['statstat_mhs']],'NLIPKTRLSM'=>0);	    
                  }
				 }
			     $dataunik[$thn.$row['nimstat_mhs']]=0; 
			   
			   }else{

                     if(($sks_trnlm!=0) and ($sks_krs==0)){			        
						
						$tmp_stat = $dt_stat_mhs->getstatmhs($thn_1,$row['nimstat_mhs'],-1);
						if($tmp_stat!=1){
						  if($tmp_stat==5){
								$fieldarray[] = array('THSMSTRLSM'=>$thn_1,'KDPTITRLSM'=>'041048','KDJENTRLSM'=>'C','KDPSTTRLSM'=>'44201','NIMHSTRLSM'=>$row['nimstat_mhs'],'STMHSTRLSM'=>$stat[$tmp_stat],'TGLLSTRLSM'=>$lls[$row['nimstat_mhs']][0],'SKSTTTRLSM'=>145,'NLIPKTRLSM'=>$lls[$row['nimstat_mhs']][1],'STLLSTRLSM'=>'S','JNLLSTRLSM'=>'I','BLAWLTRLSM'=>$lls[$row['nimstat_mhs']][2],'BLAKHTRLSM'=>$lls[$row['nimstat_mhs']][3],'NODS1TRLSM'=>$lls[$row['nimstat_mhs']][4],'NODS2TRLSM'=>$lls[$row['nimstat_mhs']][5]);
							 }else {  
								//echo $thn_1."->".$row['nimstat_mhs']." -> $tmp_stat".'<br>';
								$fieldarray[] = array('THSMSTRLSM'=>$thn_1,'KDPTITRLSM'=>'041048','KDJENTRLSM'=>'C','KDPSTTRLSM'=>'44201','NIMHSTRLSM'=>$row['nimstat_mhs'],'STMHSTRLSM'=>$stat[$tmp_stat],'NLIPKTRLSM'=>0);	    
							 }	    
                          $dataunik[$thn.$row['nimstat_mhs']]=0; 
			            }
					 }
			   
               }			   
		 } 
	   }	 
	 }
	 
	 
	 $this->tb->insertRecord($fieldarray);
   
   }
   
    function stat($thn)
   {
    
	 $dt_epsbed_msmhs = new dt_epsbed_msmhs;
	 $fieldarray = array(); 	 
	 
	 
	 
	if(!empty($this->idx_array))
    {	
	  if(($thn!=0)) 
	  {
	      if(isset($this->idx_array[$thn]))
	      {
					foreach($this->idx_array[$thn] as $f=>$v)
				  {										  
					 $ang=$dt_epsbed_msmhs->get_tahunmsmhs($f);
					 $fieldarray[$ang][$v['STMHSTRLSM']] =  isset($fieldarray[$ang][$v['STMHSTRLSM']]) ? $fieldarray[$ang][$v['STMHSTRLSM']]+1 : 1;        		
					 $fieldarray[$ang]['Total'] =isset($fieldarray[$ang]['Total']) ? $fieldarray[$ang]['Total']+1 : 1;
					 $fieldarray['Jumlah'][$v['STMHSTRLSM']] =  isset($fieldarray['Jumlah'][$v['STMHSTRLSM']]) ? $fieldarray['Jumlah'][$v['STMHSTRLSM']]+1 : 1;
				     $fieldarray['Jumlah']['Total'] =  isset($fieldarray['Jumlah']['Total']) ? $fieldarray['Jumlah']['Total']+1 : 1;
				  }
		  }
	   }else
	   {
	      foreach($this->idx_array as $f=>$v)
		  {
		  	
			foreach($v as $f1=>$v1)
		    {   
			 $fieldarray[$f][$v1['STMHSTRLSM']] =  isset($fieldarray[$f][$v1['STMHSTRLSM']]) ? $fieldarray[$f][$v1['STMHSTRLSM']]+1 : 1;        		
	         $fieldarray[$f]['Total'] =isset($fieldarray[$f]['Total']) ? $fieldarray[$f]['Total']+1 : 1;;
			}
			 
		  }
	 
	   }
	 }
	 
	 
	 
	 
	 return  $fieldarray;
   
   }
   
   
   function getTRLSM()
   {
   
     return $this->tb->getTablePath();
   }
   
   
}

?>