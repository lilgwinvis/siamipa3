<?php
require_once 'shared.php';

class dt_khs 
{
   var $vnilai;
   var $vthsms;
   var $vthsms_txt;
   var $cnt = 1; 
   
   function __construct(){
     $this->vnilai = new tb_gen('vw_tbtrnlptrnlmjnmtk');
	 
   }
   
   
   
   function semke($thsms)
   {
     $sem = str_split($thsms, 4);			
					 
	if($sem[1]=="1"){
		$tmp = "Semester Ganjil ".$sem[0]." (Semester ke-".$this->cnt.")";
		$this->cnt = $this->cnt + 1;
	}else{
			if($sem[1]=="2"){
			   $tmp = "Semester Genap ".$sem[0]." (Semester ke-".$this->cnt.")";
			   $this->cnt = $this->cnt + 1;
			}else{
				 if($sem[1]=="0"){
				 $tmp = "Nilai Konversi";						    
				}
			}
		 }
	return $tmp;	 
   }
   
   function buildsem($user)
    {	  
	     $where = "nimhstrnlm='$user'"; 
      	 $data = $this->vnilai->getData($where);  
	     
		 $thsms='';		 
		 if(!empty($data)){
		  foreach ($data as $row) {
            if (empty($thsms)) {
	               $thsms = $row['thsmstrnlm'];
				   $this->vthsms[]=$thsms;
                   $this->vthsms_txt[]=$this->semke($thsms); 				   
                 } else {
                      if ($thsms != $row['thsmstrnlm']){
					     $thsms = $row['thsmstrnlm']; 
                         $this->vthsms[]=$thsms; 
                         $this->vthsms_txt[]=$this->semke($thsms); 						 
					  }
                 } // if
			
          } // foreach
		 }
		 
	  return ;		 
	  	  
	}	
	
	
	
	
	function buildkhs($user,$thsms)
    {
	
	  $where = "nimhstrnlm='$user' and thsmstrnlm='$thsms'"; 
      $data = $this->vnilai->getData($where); 
	  return $data;
	}
	
	function buildkhs_nl($user,$thsms,$nl)
    {	  
	  $where = "nimhstrnlm='$user' and thsmstrnlm='$thsms' and nlakhtrnlm='$nl'"; 
      $data = $this->vnilai->getData($where); 
	  return $data;
	}
	
	function buildkhs_ulang($user,$nl)
    {	  
	  $where = "nimhstrnlm='$user' and kdkmktrnlm in (select kdkmktrnlm from trnlm_trnlp where nimhstrnlm='$user' and nlakhtrnlm='$nl') and bobottrnlm>1"; 
      $data = $this->vnilai->getData($where); 
	  return $data;
	}	
	
	function hitsks($user,$thsms)
    {
	  
	  $this->vnilai->sql_select = 'sum(sksmktbkmk) as jml'; 
	  $where = "nimhstrnlm='$user' and thsmstrnlm='$thsms' and nlakhtrnlm not in ('K')"; 
      $data = $this->vnilai->getData($where); 
	  $jml=0.00;
	  if($this->vnilai->numrows>0){
     	 foreach($data as $row){
	      if($row['jml']!=null){ 
		   $jml = $row['jml'];
	       }
		 }
      }		 
	  
	  return $jml;
	}
	
	function hitip($user,$thsms)
    {
	  $this->vnilai->sql_select = 'sum(sksmktbkmk*bobottrnlm) as jml_sksam,sum(sksmktbkmk) as jml_sks'; 
	  $where = "nimhstrnlm='$user' and thsmstrnlm='$thsms' and nlakhtrnlm not in ('K')"; 
      $data = $this->vnilai->getData($where); 
	  $ip=0.00;
	  if($this->vnilai->numrows>0){
		  foreach($data as $row){
			if($row['jml_sks']!=0){ 
			 $ip = $row['jml_sksam']/$row['jml_sks'];
			 }
		  }
	  }
	  return number_format($ip, 2, '.', '');;
	}
	
}
?>