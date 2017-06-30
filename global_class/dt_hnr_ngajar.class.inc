<?php

require_once 'shared.php';


class dt_hnr_ngajar
{
   var $tb_hnr;
   
   function __construct(){
     
	 $this->tb_hnr = new tb_gen('hnr_ngajar');
   }
   
   function getHonor($shift,$hstat)
   {
      $where = "shift='$shift' and Hstat='$hstat'";     
	  $data = $this->tb_hnr->getData($where);
      $tmp=0;
	  if(!empty($data))
	  {
	    foreach($data as $row)
		{
		  if($hstat=='DTY'){
		    $tmp = $row['lebih'];
		  }else{
		    $tmp = $row['honor'];
		  } 
		}
	  
	  }
	  
	  return $tmp;
   
   }
   
	function getTrans($shift,$hstat)
   {
      $where = "shift='$shift' and Hstat='$hstat'";     
	  $data = $this->tb_hnr->getData($where);
      $tmp=0;
	  if(!empty($data))
	  {
	    foreach($data as $row)
		{
    	    $tmp = $row['trans'];		   
		}
	  
	  }
	  
	  return $tmp;
   
   }
	
   
   
}
?>