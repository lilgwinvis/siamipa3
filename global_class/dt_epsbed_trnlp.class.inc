<?php

require_once 'shared.php';


class dt_epsbed_trnlp
{
   var $tb;
   var $idx_array;
   var $jml_sks;
   var $jml_bbt;
   
   function __construct(){
     $this->tb = new tb_epsbed_trnlp;
	 
	 $this->idx_array= array();
	 $data=$this->getData();
	 
	 if(!empty($data))
	 {
	   foreach($data as $row)
	   {
	      foreach($this->tb->fieldname as $fieldnm)
		  {
		    if(!in_array($fieldnm,$this->tb->keyfield)){
			   $this->idx_array[$row['NIMHSTRNLP']]['mtk'][$row['KDKMKTRNLP']][$fieldnm]=$row[$fieldnm];
		    }
		  } 
	   }
	 }  
	 
	 
   }
   
   
   function getviewdata($nim)
   {      
	  $fieldarray = array();
	  
	  if(!empty($this->idx_array))
      {
	    if(isset($this->idx_array[$nim]))
	   {
	     foreach($this->idx_array[$nim] as $f=>$v)
		 {
		    foreach($v as $f1=>$v1)
			{
			   $fieldarray[]=array('NIMHSTRNLP'=>$nim,'KDKMKTRNLP'=>$f1,'NLAKHTRNLP'=>$v1['NLAKHTRNLP'],'BOBOTTRNLP'=>$v1['BOBOTTRNLP']);
			}			
		 }
	   }
	  }
	  
	  return $fieldarray;   
   }
   
   
   function getData()
   {
      
	  $data = $this->tb->getData();
	  return $data;   
   }
   
   function delData($nim)
   {
     $this->tb->deleteRecord(array('NIMHSTRNLP'=>$nim));
   }
   
   function siatoepsbed($nim)
   {
     $fieldarray = array(); 	 
	 $data = $this->getData();
	 if(!empty($data))
	 {
	   foreach($data as $row)
	   {
	      if($row['NIMHSTRNLP'] != $nim){
	          $fieldarray[] = $row;	    
	      }
	   }	 
	 }
	 
	 $tb_trnlp = new tb_gen('trnlp');
	
	
	 $data = $tb_trnlp->getData("nimhstrnlp='$nim'");
	
	 if(!empty($data))
	 {
	  
	   foreach($data as $row)
	   {	     
	      $fieldarray[] = array('THSMSTRNLP'=>'00000','KDPTITRNLP'=>'041048','KDJENTRNLP'=>'C','KDPSTTRNLP'=>'44201','NIMHSTRNLP'=>$nim,'KDKMKTRNLP'=>$row['kdkmktrnlp'],'NLAKHTRNLP'=>( $row['nlakhtrnlp']=='K' ? 'E' : $row['nlakhtrnlp']),'BOBOTTRNLP'=>( $row['nlakhtrnlp']=='K' ? '0.00' : $row['bobottrnlp']),'KELASTRNLP'=>$row['kelastrnlp']);	    
       }	 
	 }
	 
	 
	 $this->tb->writedata($fieldarray);
   
   }
   
   function stat($thn)
   {
    $dt_kmk = new dt_epsbed_kmk;
	$dt_krs = new dt_krs;
	$thn=$dt_krs->TA();
	 	 
	$fieldarray = array(); 	 
		 
	if(!empty($this->idx_array))
    {	
	  foreach($this->idx_array as $f=>$v)
      {
        foreach($v['mtk'] as $f1=>$v1)
        { 
		 $fieldarray[$f]['jml_mtk'] = isset($fieldarray[$f]['jml_mtk']) ? $fieldarray[$f]['jml_mtk']+1 : 1; 
		 $fieldarray[$f]['jml_sks'] = isset($fieldarray[$f]['jml_sks']) ? $fieldarray[$f]['jml_sks']+$dt_kmk->getsks($thn,$f1) : $dt_kmk->getsks($thn,$f1);
        }
	  } 
	   
	 }
	 
	 
	 
	 
	 return  $fieldarray;
   
   }
   
   function hit_sksbobottot($nim,$thn,$dt_mtk)
   {
     $dt_kmk = new dt_epsbed_kmk;
	 $jml_sks=0;
	 $jml_bbt=0;
	 if(!empty($this->idx_array))
	     {	  
	        if(isset($this->idx_array[$nim])){
					  foreach($this->idx_array[$nim]['mtk'] as $f=>$v)
					  {
					   						  
						 if( $f == 'MAT307' )
						 { 
						   $idx = 'MAT364';
						 }
						 else{
						   $idx = $f;
						 }
						 
						  if(!isset($dt_mtk[$idx]))
						 {
							$dt_mtk[$idx]=$v['BOBOTTRNLP'];
							$jml_bbt+=($dt_kmk->getsks($thn,$idx)*$v['BOBOTTRNLP']);
							$jml_sks+=$dt_kmk->getsks($thn,$idx);
						 }else{
						   if($dt_mtk[$idx]<$v['BOBOTTRNLP'])
						   {
						     $jml_bbt-=($dt_kmk->getsks($thn,$idx)*$dt_mtk[$idx]);
						     $jml_bbt+=($dt_kmk->getsks($thn,$idx)*$v['BOBOTTRNLP']);
							 $dt_mtk[$idx]=$v['BOBOTTRNLP'];
						   }
						  }
					 }	  
			}
	     
		
	   } 	   
	 $this->jml_sks = $jml_sks;
	 $this->jml_bbt = $jml_bbt;
   
   }
   
   
   function getTRNLP()
   {
   
     return $this->tb->getTablePath();
   }
   
   
}

?>