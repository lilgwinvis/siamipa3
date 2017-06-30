<?php
require_once 'shared.php';
 
class dt_sebaran
{   var $vkrs_mhs;
    var $vkrs_mtk;
   
	function __construct()
	{
	  
	}
	
	function getsemmtk() 
	{	
	   $this->vkrs_mtk = new tb_gen('vw_krs_jn_mtk');
	   $this->vkrs_mtk->sql_select= 'semestbkmk';
	   $this->vkrs_mtk->sql_groupby= 'semestbkmk';
       $this->vkrs_mtk->sql_orderby= 'semestbkmk';
	   $data = $this->vkrs_mtk->getData("");
       return $data;
	}
	
	function getriwayatsemmtk($thn)
	{	
	   $this->vkrs_mtk = new tb_gen('trnlm_jn_mtk');
	   $this->vkrs_mtk->sql_select= 'semestbkmk';
	   $this->vkrs_mtk->sql_groupby= 'semestbkmk';
       $this->vkrs_mtk->sql_orderby= 'semestbkmk';
	   $data = $this->vkrs_mtk->getData("thsmstrnlm=$thn");
       return $data;
	}
	
	function getangkatan($kdkmkkrs,$shiftkrs,$kelaskrs,$semkrs)
	{
	  $this->vkrs_mhs = new tb_gen('vw_krs_jn_mhs');
      $this->vkrs_mhs->sql_select  = 'tahunmsmhs';
	  $this->vkrs_mhs->sql_groupby = 'tahunmsmhs';
      $this->vkrs_mhs->sql_orderby = 'tahunmsmhs';
	  
	  $data = $this->vkrs_mhs->getData("kdkmkkrs='$kdkmkkrs' and shiftkrs='$shiftkrs' and kelaskrs='$kelaskrs' and semkrs='$semkrs'");
     
	  $tmp_Ang="";
	  if(!empty($data))
	  {
	    foreach($data as $row)
		{
		  $tmp_Ang=$tmp_Ang.",".$row['tahunmsmhs'];		
		}	
        $tmp_Ang = ltrim($tmp_Ang, ',');		
	  }
	  
	  return $tmp_Ang;
	  
	  
	}
	
	function getriwayatangkatan($kdkmktrnlm,$shifttrnlm,$kelastrnlm,$semestrnlm,$thn)
	{
	  $this->vkrs_mhs = new tb_gen('trnlm_jn_msmhs');
      $this->vkrs_mhs->sql_select  = 'tahunmsmhs';
	  $this->vkrs_mhs->sql_groupby = 'tahunmsmhs';
      $this->vkrs_mhs->sql_orderby = 'tahunmsmhs';
	  
	  $data = $this->vkrs_mhs->getData("kdkmktrnlm='$kdkmktrnlm' and shifttrnlm='$shifttrnlm' and kelastrnlm='$kelastrnlm' and semestrnlm='$semestrnlm' and thsmstrnlm='$thn'");
     
	  $tmp_Ang="";
	  if(!empty($data))
	  {
	    foreach($data as $row)
		{
		  $tmp_Ang=$tmp_Ang.",".$row['tahunmsmhs'];		
		}	
        $tmp_Ang = ltrim($tmp_Ang, ',');		
	  }
	  
	  return $tmp_Ang;
	  
	  
	}
	
	function getmtk($semmtk)
	{	
	  $this->vkrs_mtk = new tb_gen('vw_krs_jn_mtk');
	  $this->vkrs_mtk->sql_select= 'kdkmkkrs,nakmktbkmk,sksmktbkmk,sksprtbkmk,shiftkrs,semestbkmk,semkrs,kelaskrs,wp,count(nimhskrs) as jml';
	  $this->vkrs_mtk->sql_groupby= 'semestbkmk,kdkmkkrs,wp,nakmktbkmk,sksmktbkmk,sksprtbkmk,shiftkrs,semkrs,kelaskrs';
      $this->vkrs_mtk->sql_orderby= 'semestbkmk,kdkmkkrs'; 
	  $data = $this->vkrs_mtk->getData("semestbkmk='$semmtk'");
      return $data;
	}
	
	
	
	function getriwayatmtk($semmtk,$thn)
	{	
	  $this->vkrs_mtk = new tb_gen('trnlm_jn_mtk');
	  $this->vkrs_mtk->sql_select= 'kdkmktrnlm,nakmktbkmk,sksmktbkmk,sksprtbkmk,shifttrnlm,semestbkmk,semestrnlm,kelastrnlm,wp,count(nimhstrnlm) as jml';
	  $this->vkrs_mtk->sql_groupby= 'semestbkmk,kdkmktrnlm,wp,nakmktbkmk,sksmktbkmk,sksprtbkmk,shifttrnlm,semestrnlm,kelastrnlm';
      $this->vkrs_mtk->sql_orderby= 'semestbkmk,kdkmktrnlm,shifttrnlm'; 
	  $data = $this->vkrs_mtk->getData("semestbkmk='$semmtk' and thsmstrnlm='$thn'");
      return $data;
	}
	
	function getjmlmhs($kdkmkkrs,$shiftkrs,$semkrs)
	{	
	  $this->vkrs_mtk = new tb_gen('vw_krs_jn_mtk');
	  $this->vkrs_mtk->sql_select= 'kdkmkkrs,nakmktbkmk,sksmktbkmk,sksprtbkmk,shiftkrs,semestbkmk,semkrs,kelaskrs,wp,count(nimhskrs) as jml';
	  $this->vkrs_mtk->sql_groupby= 'semestbkmk,kdkmkkrs,wp,nakmktbkmk,sksmktbkmk,sksprtbkmk,shiftkrs,semkrs,kelaskrs';
      $this->vkrs_mtk->sql_orderby= 'semestbkmk,kdkmkkrs'; 
	  $data = $this->vkrs_mtk->getData("kdkmkkrs='$kdkmkkrs' and shiftkrs='$shiftkrs' and semkrs='$semkrs'");
      return $data;
	}


}

?>