<?php
require_once 'shared.php';

class dt_hutang 
{
  var $vhutang_mtk;
  var $vriwayat_nilai;
  var $vthsms;
  var $vthsms_txt;
   
  function __construct(){
     $this->vhutang_mtk = new tb_gen('vw_tbhutangmtk');
	 $this->vriwayat_nilai = new tb_gen('trnlm_jn_msmhs');
   }
   
   function semke($thsms)
   {
     $sem = str_split($thsms, 4);			
					 
	if($sem[1]=="1"){
		$tmp = "Semester Ganjil ".$sem[0];
		
	}else{
			if($sem[1]=="2"){
			   $tmp = "Semester Genap ".$sem[0];
			   
			}
		 }
	return $tmp;	 
   }
   
   function buildsem($kode)
    {	  
	     $where = "kddspengajar='$kode'"; 
      	 $data = $this->vhutang_mtk->getData($where);  
	     
		 $thsms='';		 
		 if(!empty($data)){
		  
		 foreach ($data as $row) {
            if (empty($thsms)) {
	               $thsms = $row['thnsmspengajar'];
				   $this->vthsms[]=$thsms;
                   $this->vthsms_txt[]=$this->semke($thsms); 				   
                 } else {
                      if ($thsms != $row['thnsmspengajar']){
					     $thsms = $row['thnsmspengajar']; 
                         $this->vthsms[]=$thsms; 
                         $this->vthsms_txt[]=$this->semke($thsms); 						 
					  }
                 } // if
			
          } // foreach
		 }
		 
	  return ;		 
	  	  
	}	
    
	function buildhutang($kode,$thsms)
    {	
	  $where = "kddspengajar='$kode' and thnsmspengajar='$thsms'"; 
      $data = $this->vhutang_mtk->getData($where); 
	  return $data;
	}
	
	function detailhutang($thsms,$kdkmk,$kls,$kls1,$sem)
    {	
	  $where = "thsmstrnlm='$thsms' and kdkmktrnlm='$kdkmk' and shifttrnlm='$kls' and kelastrnlm='$kls1' and semestrnlm='$sem'"; 
      $data = $this->vriwayat_nilai->getData($where);
      
	  $jml_mhs=0;
	  $jml_T=0;
	  $thnsms="";
	  $str_thnsms="";
	  foreach($data as $row){    
		 
		 if(empty($thnsms)){
		    $thnsms=$row['tahunmsmhs'];
			$str_thnsms=$row['tahunmsmhs'];
		 }else{
		   if($thnsms!=$row['tahunmsmhs']){
		      $thnsms=$row['tahunmsmhs'];
			  $str_thnsms=$str_thnsms.",".$row['tahunmsmhs'];
			} 
		 }
		 
		 if($row['nlakhtrnlm']=='T'){
		    $jml_T+=1;		  
		  }
		  
	      $jml_mhs+=1;
	  }
	  
	  $hsl['jml_mhs']=$jml_mhs;
	  $hsl['jml_T']=$jml_T;
	  $hsl['thnsms']=$str_thnsms;
	  
	  return $hsl;
	}
	
}

?>