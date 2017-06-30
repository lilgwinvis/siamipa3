<?php

require_once 'shared.php';

class dt_dosen 
{
   var $vtbdos;
   var $vhutang;
   var $numrows;
   
   function __construct(){
     $this->vtbdos = new tb_gen('tbdos');
	 
	 $temp = new tb_gen('vw_pengajar_jn_trnlm');
	 $temp->sql_select = 'distinct kddspengajar';
	 $temp->sql_where  = "nlakhtrnlm='T'";
     $data = $temp->getData("");
     
	 $temp="(";
	 if(!empty($data)){
	    foreach($data as $row){
	      if($temp=="("){
		     $temp=$temp.'"'.$row['kddspengajar'].'"';
		  }else{
		     $temp=$temp.',"'.$row['kddspengajar'].'"';
		  }
		}
	 }
	 $temp=$temp.")";
	
	 $this->vhutang = new tb_gen('tbdos');
	 $this->vhutang->sql_where ="kode in ".$temp;
	 
   }
   
   function isuserexist($user,$pass)
	{
	 $where = "Kode='$user' AND pass='$pass'";   	
	 $this->getAllData($where);
     return  $this->numrows>0;	 
	}
   
   
   
   function getAllData($where)
    {	  
	    
	  $data = $this->vtbdos->getData($where); 
	 
	  $this->numrows=$this->vtbdos->numrows;
      	 
	  return $data;		 
	  	  
	}

	function getforlaplink($kode)
	{
	  $where = "kode = '$kode'";
	  $data = $this->getAllData($where);
	 
	 $link="";
	 if(!empty($data))
	 {
	   foreach($data as $row){
	      $link = $row['link_forlap'];
	   }
	   
	 }
	 
     return $link;	  	  
	
	
	}
	
	
     function getnmdsn($nidn_epsbed)
    {	  
	    
	  $where = "nidn = '$nidn_epsbed'";
	  $data = $this->getAllData($where);
	 
	 $nmdsn="";
	 if(!empty($data))
	 {
	   foreach($data as $row){
	      $nmdsn = $row['Nama'];
	   }
	   
	 }
	 
     return $nmdsn;	  	  
	}	
	
	function getnmdsn1($kdds)
    {	  
	    
	  $where = "kode = '$kdds'";
	  $data = $this->getAllData($where);
	 
	 $nmdsn="Tidak Ditemukan";
	 if(!empty($data))
	 {
	   foreach($data as $row){
	      $nmdsn = $row['Nama'];
	   }
	   
	 }
	 
     return $nmdsn;	  	  
	}
	
	
	 function getnidnepsbed($kd)
    {	  
	    
	  $where = "Kode = '$kd'";
	  $data = $this->getAllData($where);
	 
	 $nidn_epsbed="";
	 if(!empty($data))
	 {
	   foreach($data as $row){
	      $nidn_epsbed = $row['nidn_epsbed'];
	   }
	   
	 }
	 
     return $nidn_epsbed;	  	  
	}	
	
	
	function getDataPenghutang($where)
    {	  
	    
	  $data = $this->vhutang->getData($where); 
	 
	  $this->numrows=$this->vhutang->numrows;
      	 
	  return $data;		 
	  	  
	}
   
   function getData($user)
    {	  
	  $where = "Kode='$user'"; 
	  
	  $data = $this->vtbdos->getData($where); 
	 
	  $this->numrows=$this->vtbdos->numrows;
      	 
	  return $data;		 
	  	  
	}
	
	function getDataArray($kdds)
    {
	  $where = "Kode <> '$kdds'";
	  $data = $this->getAllData($where);
	 	 
	  $tmp_array=array();
	  if(!empty($data))
	  {
	    foreach($data as $row){
	      $tmp_array[$row['Kode']] = $row['Nama'];
	   }
	  }	
	  return $tmp_array;
	}
	

    function tambah($kode,$nama,$tstat,$hstat,$smawl,$nidn1,$nidn2,$link)
    {
	
	  $this->vtbdos = new tb_gen('tbdos');
	  $where = "Kode ='$kode'";
	  $data = $this->vtbdos->getData($where); 
	  
	  if(!empty($data))
	  {
	    return 0;
	  }else{
		$this->vtbdos->insertRecord(array('Kode'=>$kode,'Nama'=>$nama,'Hstat'=>$hstat,'Tstat'=>$tstat,'smawl'=>$smawl,'pass'=>$kode,'nidn'=>$nidn1,'nidn_epsbed'=>$nidn2,'link_forlap'=>$link));
	    return 1;
	  }
	
	}	
	function edit($kode,$nama,$tstat,$hstat,$smawl,$nidn1,$nidn2,$link)
    {
	
	  $this->vtbdos = new tb_gen('tbdos');
	  $this->vtbdos->updateRecord(array('Kode'=>$kode,'Nama'=>$nama,'Hstat'=>$hstat,'Tstat'=>$tstat,'smawl'=>$smawl,'nidn'=>$nidn1,'nidn_epsbed'=>$nidn2,'link_forlap'=>$link));
	    
	  return 1;
	 
	}
	
	function hapus($plh)
    {
	  $this->vtbdos = new tb_gen('tbdos');
      
      if(!empty($plh))
      {
	     foreach($plh as $kode)
		 {
		   $this->vtbdos->deleteRecord(array('Kode'=>$kode));
		 }
	  }	  
       	  
	  return 1;
	}
}
?>