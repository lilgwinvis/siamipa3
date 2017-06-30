<?php

require_once 'shared.php';

class dt_tot_trkeumhs 
{

   function __construct(){
   
   }
   
   function gettottrkeumhs($nim)
   {
     $tb=new tb_gen('vw_trkeumhs_mtjn');
	 $where = "nimkeumhs='$nim'";
	 $data = $tb->getData($where);
     return $data;
   }
}


?>