<?php

require_once 'shared.php';

class dt_syarat 
{
  var $vtbsyarat;
  
  function __construct(){
    $this->vtbsyarat = new tb_gen('syarat');
  }
  
  function getData($where)
    {	  
	    
	  $data = $this->vtbsyarat->getData($where); 
	  return $data;		 
	  	  
	}	
	
	function tambah($plh,$kdkmk)
    {
	
	  
	   if(!empty($plh))
      {
	     foreach($plh as $kode)
		 {
		  $this->vtbsyarat->insertRecord(array('kdkmksyarat'=>$kdkmk,'syaratkmk'=>$kode));
		 }
	  }	  
	  
	    return 1;
	  
	
	}	
	
  function hapus($kode)
    {	  
	  $this->vtbsyarat->deleteRecord(array('kdkmksyarat'=>$kode));	  
	  return 1;		 
	  	  
	}	
	
}