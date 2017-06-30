<?php

require_once 'shared.php';

class dt_mtk 
{
  var $vmtk; 
  
  function __construct(){
     $this->vmtk=new tb_gen('tbkmk');	 
   }
  
  function getData($where)
   {
     $data = $this->vmtk->getData($where);
     return $data;  
   }
   
   
   function getnmmtk($kd)
   {
     $where = "kdkmktbkmk = '$kd'";
	 $data = $this->getData($where);
	 
	 $nmmtk="";
	 if(!empty($data))
	 {
	   foreach($data as $row){
	      $nmmtk = $row['nakmktbkmk'];
	   }
	   
	 }
	 
     return $nmmtk;
   }
   
   function getsksmtk($kd)
   {
     $where = "kdkmktbkmk = '$kd'";
	 $data = $this->getData($where);
	 
	 $sksmtk=0;
	 if(!empty($data))
	 {
	   foreach($data as $row){
	      $sksmtk = $row['sksmktbkmk'];
	   }
	   
	 }
	 
     return $sksmtk;
   }
   
   function hittotsks()
   {
     $this->vmtk->sql_select = 'sum(sksmktbkmk) as jml';
	 $where ="kdkmktbkmk not like 'MATP%'"; 
	 
     $data = $this->vmtk->getData($where);
	 
	 $jml=0.00;
	  if($this->vmtk->numrows>0){
     	 foreach($data as $row){
	       $jml = $row['jml'];
	     }
	   }
	 return $jml;
   }
   
   function sksnmbl($nim)
   {
     $this->vmtk->sql_select = 'sum(sksmktbkmk) as jml';
	 $where ="kdkmktbkmk not IN (SELECT DISTINCT kdkmktrnlm FROM trnlm_trnlp WHERE nimhstrnlm='$nim' and nlakhtrnlm!='K' ) and (kdkmktbkmk not like 'MATP%') "; 
	 
     $data = $this->vmtk->getData($where);
	 
	 $jml=0.00;
	  if($this->vmtk->numrows>0){
     	 foreach($data as $row){
	       $jml = $row['jml'];
	     }
	   }
	 return $jml;
   }
   
   function tambah($kdkmk,$nama,$kdprtk,$sem,$wp,$skslptbkmk,$sksprtbkmk,$skstmtbkmk,$kddsn)
    {
	
	  $this->vtbmtk = new tb_gen('tbkmk');
	  $where = "kdkmktbkmk ='$kdkmk'";
	  $data = $this->vtbmtk->getData($where); 
	  
	  if(!empty($data))
	  {
	    return 0;
	  }else{
		$this->vtbmtk->insertRecord(array('kdkmktbkmk'=>$kdkmk,'nakmktbkmk'=>$nama,'sksmktbkmk'=>$skstmtbkmk+$sksprtbkmk,'skstmtbkmk'=>$skstmtbkmk,'skslptbkmk'=>$skslptbkmk,'sksprtbkmk'=>$sksprtbkmk,'semestbkmk'=>$sem,'kdprtk'=>$kdprtk,'wp'=>$wp,'nodostbkmk'=>$kddsn));
	    return 1;
	  }
	
	}	
	function edit($kdkmk,$nama,$kdprtk,$sem,$wp,$skslptbkmk,$sksprtbkmk,$skstmtbkmk,$kddsn)
    {
	
	  $this->vtbmtk = new tb_gen('tbkmk');
	  $this->vtbmtk->updateRecord(array('kdkmktbkmk'=>$kdkmk,'nakmktbkmk'=>$nama,'sksmktbkmk'=>$skstmtbkmk+$sksprtbkmk,'skstmtbkmk'=>$skstmtbkmk,'skslptbkmk'=>$skslptbkmk,'sksprtbkmk'=>$sksprtbkmk,'semestbkmk'=>$sem,'kdprtk'=>$kdprtk,'wp'=>$wp,'nodostbkmk'=>$kddsn));
	    
	  return 1;
	 
	}
	
	function hapus($plh)
    {
	  $this->vtbmtk = new tb_gen('tbkmk');
      $vtbsyarat = new tb_gen('syarat');
	  
      if(!empty($plh))
      {
	     foreach($plh as $kode)
		 {
		   $this->vtbmtk->deleteRecord(array('kdkmktbkmk'=>$kode));
		   $vtbsyarat->deleteRecord(array('syaratkmk'=>$kode));
		 }
	  }	  
       	  
	  return 1;
	}
   
}

?>