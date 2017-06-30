<?php


require_once 'shared.php';

class dt_nilai 
{
   var $vtbnilai;
  
   
   function __construct(){
     $this->vtbnilai = new tb_gen('vw_tbnilai');	 
	 
   }   
   
   function getData($where)
   {
     $data = $this->vtbnilai->getData($where);
     return $data;  
   }
   
   function setpageno($pageno)
   {
	 $this->vtbnilai->pageno=$pageno;
   }
   
   function setrows_per_page($rows_per_page)
   {
	 $this->vtbnilai->rows_per_page=$rows_per_page;
   }
   
   function getnumrows()
   {
	  return  $this->vtbnilai->numrows;
   }
   
}
?>