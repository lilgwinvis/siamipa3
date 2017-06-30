<?php

require_once 'shared.php';
 
 
 class dt_ksd_ngajar
{
   var $tb_ksd_ngajar;
   var $mulai;
   var $akhir;
   var $acc;
   var $hari;
   
   function __construct()
   {
      $this->tb_ksd_ngajar = new tb_gen('ksd_ngajar');
	  
   }
   
   function update_jam_akhir($kdkmk,$kdds,$shift,$sem,$jakhirklh)
   {  
      $entry =array('Kdkmk'=>$kdkmk,'kdds'=>$kdds,'shift'=>$shift,'sem'=>$sem,'jakhirklh'=>$jakhirklh);
      $this->tb_ksd_ngajar->updateRecord($entry);  
   }
   
   function getSebaranData($kdds,$baru=1)
   {
      $vkrs_mtk = new tb_gen('vw_krs_jn_mtk');
	  $vkrs_mtk->sql_select= 'kdkmkkrs,nakmktbkmk,sksmktbkmk,sksprtbkmk,shiftkrs,semestbkmk,semkrs,kelaskrs,wp';
	  $vkrs_mtk->sql_groupby= 'semestbkmk,kdkmkkrs,wp,nakmktbkmk,sksmktbkmk,sksprtbkmk,shiftkrs,semkrs,kelaskrs';
      $vkrs_mtk->sql_orderby= 'semestbkmk,kdkmkkrs'; 
	  if($baru==1){
	    $vkrs_mtk->sql_having = "(kdkmkkrs not in (select distinct kdkmkpengajar from pengajar where kddspengajar='$kdds')) AND  (CONCAT(kdkmkkrs,'_',shiftkrs,'_',semkrs,'_',kelaskrs) NOT IN (SELECT CONCAT(kdkmk,'_',shift,'_',sem,'_',klsklh) FROM ksd_ngajar WHERE kdds='$kdds'))";
      }else{
	    $vkrs_mtk->sql_having= "(kdkmkkrs in (select distinct kdkmkpengajar from pengajar where kddspengajar='$kdds')) AND  (CONCAT(kdkmkkrs,'_',shiftkrs,'_',semkrs,'_',kelaskrs) NOT IN (SELECT CONCAT(kdkmk,'_',shift,'_',sem,'_',klsklh) FROM ksd_ngajar WHERE kdds='$kdds'))";
	  }
	  $data = $vkrs_mtk->getData("");
	  return $data;
   }
   
   function getRiwayatSebaranData($kdds,$thn)
   {
      $vkrs_mtk = new tb_gen('trnlm_jn_mtk');
	  $vkrs_mtk->sql_select= 'thsmstrnlm,kdkmktrnlm,nakmktbkmk,sksmktbkmk,sksprtbkmk,shifttrnlm,semestbkmk,semestrnlm,kelastrnlm,wp';
	  $vkrs_mtk->sql_groupby= 'semestbkmk,kdkmktrnlm,wp,nakmktbkmk,sksmktbkmk,sksprtbkmk,shifttrnlm,semestrnlm,kelastrnlm,thsmstrnlm ';
      $vkrs_mtk->sql_orderby= 'semestbkmk,kdkmktrnlm'; 
	  
	  $vkrs_mtk->sql_having = "(CONCAT(kdkmktrnlm,shifttrnlm,semestrnlm,kelastrnlm,thsmstrnlm) NOT IN (SELECT DISTINCT CONCAT(kdkmkpengajar,shiftpengajar,semespengajar,kelaspengajar,thnsmspengajar) FROM pengajar WHERE kddspengajar='$kdds' AND thnsmspengajar='$thn')) AND thsmstrnlm='$thn'";
     
	  $data = $vkrs_mtk->getData("");
	  return $data;
   }
   
   function getData($where)
   {
     
	 $data = $this->tb_ksd_ngajar->getData($where);
     return $data;  
   }
   
   function getDataMtk($kdds)
   {
     $tb = new tb_gen('vw_ksd_ngajar_jn_tbkmk');	
	 $data = $tb->getData("kdds='$kdds'");
     return $data;  
   }
   
   function getDataRiwayatMtk($kdds,$thn)
   {
     $tb = new tb_gen('vw_pengajar_jn_tbkmk');	
	 $data = $tb->getData("kddspengajar ='$kdds' and thnsmspengajar='$thn'");
     return $data;  
   }
   
   function getpengajar($arr)
   {
	  $tb = new tb_gen('vw_ksd_ngajar_jn_tbkmk');
	  $where='';	  
      $jml=count($arr);
	  $i=0;
	  foreach($arr as $k=>$v)
      {
		$where .= $k.'="'.$v.'" ';
		if($i<($jml-1)){
		   $where .= 'and ';	
		   $i++;	
		}		
		
	  }   	  
	  
	  $data = $tb->getData($where);
	  return $data; 
   }
   
   
   function getriwayatpengajar($arr)
   {	   
	 $tb = new tb_gen('vw_pengajar_jn_tbkmk');
	 $where='';	  
      $jml=count($arr);
	  $i=0;
	  foreach($arr as $k=>$v)
      {
		$where .= $k.'="'.$v.'" ';
		if($i<($jml-1)){
		   $where .= 'and ';	
		   $i++;	
		}		
		
	  }  	  
	 $data = $tb->getData($where);
     return $data;  
   }
   
   function getBebanSKS($kdds,$setuju=0)
   {
       $vksd_ngajar = new tb_gen('vw_ksd_ngajar_jn_tbkmk');
	   $vksd_ngajar->sql_select= 'kdkmk,sksmktbkmk,sksprtbkmk,disetujui';
	   $where = "kdds='$kdds'";
	
	if($setuju==1)
	 {
	   $where .= " and disetujui=1";
	 }
	 
	  $data = $vksd_ngajar->getData($where);
	 
     $jml=0;
      if(!empty($data))
      {  
         foreach($data as $row)
		 {
		   $jml+=($row['sksprtbkmk'] > 0 ? $row['sksmktbkmk']-1 : $row['sksmktbkmk']);
		 }
	  }	  
	  
	 return $jml;
   }
   
   function getBebanRiwayatSKS($thn,$kdds,$setuju=0)
   {
       $vksd_ngajar = new tb_gen('vw_pengajar_jn_tbkmk');
	   $vksd_ngajar->sql_select= 'kdkmkpengajar,sksmktbkmk,sksprtbkmk';
	   $where = "thnsmspengajar='$thn' and kddspengajar='$kdds'";
	
	if($setuju==1)
	 {
	   //$where .= "";
	 }
	 
	  $data = $vksd_ngajar->getData($where);
	 
     $jml=0;
      if(!empty($data))
      {  
         foreach($data as $row)
		 {
		   $jml+=($row['sksprtbkmk'] > 0 ? $row['sksmktbkmk']-1 : $row['sksmktbkmk']);
		 }
	  }	  
	  
	 return $jml;
   }
   
   function isbersedia($kdds,$kdkmkkrs,$shiftkrs,$semkrs,$kelaskrs)
   {
     $where = "kdds='$kdds' and kdkmk='$kdkmkkrs' and shift='$shiftkrs' and sem='$semkrs' and klsklh='$kelaskrs'";
	 $data = $this->getData($where);
	 
	 $this->mulai = '00:00:00';
     $this->akhir = '00:00:00';
	 $this->acc = false;
	 $this->hari=0;
	 if(!empty($data)){
	    foreach($data as $row)
		{
		   $this->mulai = $row['jawalklh'];
		   $this->akhir = $row['jakhirklh'];
		   $this->acc = $row['disetujui']==1;
		   $this->hari = (int) $row['hariklh'];
		}	 
	 }
	 
	 return $this->tb_ksd_ngajar->numrows>0;
	 
   }
   
   function delAllRecord($where)
   {
     $this->tb_ksd_ngajar->deleteAllRecord($where);
	 return 0;
   }
   
   function export_record($tb,$field,$field1,$where)
   {
     $this->tb_ksd_ngajar->export_record($tb,$field,$field1,$where);
	 return 0;
   } 
} 

?>