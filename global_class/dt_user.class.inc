<?php

require_once 'shared.php';

class dt_user {
	
	var $numrows;
	function __construct() {
		// Type your code here
	}
	
	function getData($where)
	{
		$vtb_user = new tb_gen('staff');		
		$data = $vtb_user->getData($where); 
		$this->numrows=$vtb_user->numrows;		      
		return $data;
	}
	
	
	function isuserexist($user,$pass)
	{
	 $where = "user_id='$user' AND pass='$pass'"; 	
	 $this->getData($where);
     return  $this->numrows>0;	 
	}
	
	function gethak($user)
	{
	 $where = "user_id='$user'"; 	
	 $data=$this->getData($where);
     
	 $hak =0;
	 if($this->numrows>0)
	 {
	   foreach($data as $row)
	   {
	     $hak = $row['hak_akses'];
	   }
	 }
	 
	 return  $hak;	 
	}
}

?>