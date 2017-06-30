<?php
require_once 'shared.php';
 
 class dt_trnlp
{

 var $tbtrnlp;
 var $tbmtk;
 var $msg_txt;
 
 function __construct(){
     $this->tbtrnlp = new tb_gen('trnlp');
	 $this->tbmtk=new tb_gen('tbkmk');
   }
  function getData($where){
   $data=$this->tbtrnlp->getData($where);
   return $data;
  }  
   
  
  function data_trnlp($nim,$baru=1)
  {
     if($baru==1)
	 {
	  $where = "kdkmktbkmk NOT LIKE 'MATP%' and (kdkmktbkmk not in (select kdkmktrnlp from trnlp where nimhstrnlp='$nim') )";
      $data = $this->tbmtk->getData($where);
	  
	 return $data;
	 }else
     {
       $where = "nimhstrnlp='$nim'";
       $tb = new tb_gen('vw_trnlp_jn_tbkmk');
	   $data = $tb->getData($where); 
	   return $data;
	 }
  
  }  
  
  function simpantrnlp($nim,$mk,$nilai)
  {
     $bbt = array('A'=>4.00,'B'=>3.00,'C'=>2.00,'D'=>1.00,'E'=>0.00);
	 if(!empty($mk)){
	   $txt='';
	   foreach($mk as $row)
       {
	    $this->tbtrnlp->insertRecord(array('thsmstrnlp'=>'00000','nimhstrnlp'=>$nim,'kdkmktrnlp'=>$row,'nlakhtrnlp'=>$nilai[$row],'bobottrnlp'=>$bbt[$nilai[$row]],'kelastrnlp'=>'01'));	
	   } 	   
  	   
	   $this->msg_txt = $txt.'Nilai Konversi Disimpan !!!';
	   return 1;
	 }else{
	   $this->msg_txt = 'Anda belum memilih Matakuliah, Nilai Konversi Tidak Disimpan !!!';
	   return 0;
	 }
   
  }   
  function gantihmtrnlp($nim,$nilai)
  {
     $bbt = array('A'=>4.00,'B'=>3.00,'C'=>2.00,'D'=>1.00,'E'=>0.00);
	 if(!empty($nilai)){
	   $txt='';
	   foreach($nilai as $f=>$v)
       {
	    $this->tbtrnlp->updateRecord(array('thsmstrnlp'=>'00000','nimhstrnlp'=>$nim,'kdkmktrnlp'=>$f,'nlakhtrnlp'=>$v,'bobottrnlp'=>$bbt[$v],'kelastrnlp'=>'01'));	
	   } 	   
  	   
	   $this->msg_txt = $txt.'Nilai Konversi Disimpan !!!';
	   return 1;
	 }else{
	   $this->msg_txt = 'Nilai Konversi Kosong, Nilai Konversi Tidak Disimpan !!!';
	   return 0;
	 }
   
  }   
  
  function hapustrnlp($nim,$mk)
  {
     $bbt = array('A'=>4.00,'B'=>3.00,'C'=>2.00,'D'=>1.00,'E'=>0.00);
	 if(!empty($mk)){
	   $txt='';
	   foreach($mk as $row)
       {
	    $this->tbtrnlp->deleteRecord(array('thsmstrnlp'=>'00000','nimhstrnlp'=>$nim,'kdkmktrnlp'=>$row));	
	   } 	   
  	   
	   $this->msg_txt = $txt.'Nilai Konversi Dihapus !!!';
	   return 1;
	 }else{
	   $this->msg_txt = 'Anda belum memilih Matakuliah, Nilai Konversi Tidak Dihapus !!!';
	   return 0;
	 }
   
  } 
}

?>