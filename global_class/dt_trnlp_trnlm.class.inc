<?php

require_once 'shared.php';
 
 class dt_trnlp_trnlm
{   
    var $msg_txt;
    var $tb;
    var $numrows;
    function __construct() 
    {
       $this->tb = new tb_gen('vw_tbtrnlptrnlmjnmtk');
    }
	
	
	function getData($where)
	{
	  $data = $this->tb->getData($where); 
	  $this->numrows=$this->tb->numrows;
      	  return $data;	  
	}
	
	function updateData($thsms,$nim,$kdkmk,$hm,$am)
	{
	  $tb_tujuan = new tb_gen('trnlm_trnlp');
	  $tb_tujuan->updateRecord(array('thsmstrnlm'=>$thsms,'nimhstrnlm'=>$nim,'kdkmktrnlm'=>$kdkmk,'nlakhtrnlm'=>$hm,'bobottrnlm'=>$am));
	}
	
	function trnlptotrnlp_trnlm($nim)
	{
	  $dt_mhs = new dt_mhs;
	  
	  $nm='';
	  
	  $tb_tujuan = new tb_gen('trnlm_trnlp');
	  $tb_asal = new tb_gen('trnlp');
	  
	  $tb_tujuan->deleteRecord(array('thsmstrnlm'=>'00000','nimhstrnlm'=>$nim));
	  $data = $tb_asal->getData("thsmstrnlp='00000' and nimhstrnlp='$nim'"); 
	  
      if(!empty($data)){	   
	   foreach($data as $row)
	    {
         $tb_tujuan->insertRecord(array('thsmstrnlm'=>'00000','nimhstrnlm'=>$nim,'kdkmktrnlm'=>$row['kdkmktrnlp'],'nlakhtrnlm'=>$row['nlakhtrnlp'],'bobottrnlm'=>$row['bobottrnlp'],'kelastrnlm'=>$row['kelastrnlp']));     
	    }
	  }
	  
	  $data=$dt_mhs->getData($nim);
      if(!empty($data)){	   
	   foreach($data as $row)
	    {
          $nm=$row['nmmhsmsmhs']; 	     
	    }
	  }
	  $this->msg_txt = "Data Nilai Konversi Atas Nama :".$nm.'('.$nim.'), Berhasil di publikasikan !!!';
	}
	
	
	
	
	function trnlmtotrnlp_trnlm($thsms,$kdkmk,$kelas,$nim,$hm,$am)
	{
	   $dt_mhs = new dt_mhs;
	   $data=$dt_mhs->getData($nim);
	   
	   $nm='';
	  
      if(!empty($data)){	   
	   foreach($data as $row)
	    {
          $nm=$row['nmmhsmsmhs']; 	     
	    }
	  }
	  $this->msg_txt = "Data Nilai Atas Nama :".$nm.'('.$nim.'), Berhasil di publikasikan !!!';
	  
	  $tb_tujuan = new tb_gen('trnlm_trnlp');
	  $tb_tujuan->updateRecord(array('thsmstrnlm'=>$thsms,'nimhstrnlm'=>$nim,'kdkmktrnlm'=>$kdkmk,'nlakhtrnlm'=>$hm,'bobottrnlm'=>$am,'kelastrnlm'=>$kelas));
	  
	}
	
	
}

?>