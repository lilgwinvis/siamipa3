<?php
require_once 'shared.php';
 
 class dt_publish_nilai
{
   var $vtbpublishnilai;
   function __construct(){
     $this->vtbpublishnilai = new tb_gen('publish_nilai');
   }
   function getData($where)
   {
     $this->vtbpublishnilai->sql_groupby="";
	 $data = $this->vtbpublishnilai->getData($where);
     return $data;  
   }
   
   function getgroupData($where)
   {
     $this->vtbpublishnilai->sql_groupby="b.thsmstrnlm,b.kdkmktrnlm,nakmktbkmk,b.kelastrnlm";
	 $this->vtbpublishnilai->sql_select = 'b.thsmstrnlm,b.kdkmktrnlm,nakmktbkmk,b.kelastrnlm';
	 $data = $this->vtbpublishnilai->getData($where);
     return $data;  
   }
   
 }  