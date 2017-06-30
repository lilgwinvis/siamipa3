<?php
 
 require_once 'shared.php';
 

class dt_staff 
{
   var $vstaff;
   var $numrows;
   
   function __construct(){
     $this->vstaff = new tb_gen('staff');
	 
   }
   
   function getData($user)
    {	  
	  if(!empty($user)){
     	  $where = "user_id='$user'"; 
	  }
	  $data = $this->vstaff->getData($where); 
	 
	  $this->numrows=$this->vstaff->numrows;
      	 
	  return $data;		 
	  	  
	}

   
  	
}
?>