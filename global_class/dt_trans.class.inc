<?php

require_once 'shared.php';

class dt_trans 
{
   var $vnilai;
   var $vmtk;
   var $sks_mbl;
   var $sks_nm;
   
   var $sks_mbl_krs;
   var $sks_nm_krs;
   
   function __construct(){
     $this->vnilai = new tb_gen('trnlm_trnlp');
	 $this->vmtk = new tb_gen('vw_tbtrnlptrnlmjnmtk');	 
   }
   
   function getData($user)
   {
    
	$this->vmtk->sql_select = "distinct kdkmktrnlm,nakmktbkmk,sksmktbkmk,nlakhtrnlm,bobottrnlm,wp,semestbkmk";
    $where = "nimhstrnlm='$user' and nlakhtrnlm !='K'"; 
    $this->vmtk->sql_orderby = 'semestbkmk,kdkmktrnlm,bobottrnlm desc';
	$data = $this->vmtk->getData($where);
	
	$this->sks_mbl=0.00;
	 if(!empty($data)){
	   $hsl = array_filter($data,function($row){
			static $kode=array();			
			$ada = false;
			if(!in_array($row['kdkmktrnlm'],$kode)){
			  $kode[]=$row['kdkmktrnlm'];
              $ada = true;			  
			}
			return $ada;
		});
      }
      return $hsl;
   }
   
   function hitipk($user,$thn="")
   {
    $this->vmtk->sql_select = "distinct kdkmktrnlm,nakmktbkmk,sksmktbkmk,nlakhtrnlm,bobottrnlm,wp,semestbkmk";
    if($thn==""){
	 $where = "nimhstrnlm='$user' and nlakhtrnlm not in ('K')"; 
	}else{
	 $where = "nimhstrnlm='$user' and nlakhtrnlm not in ('K') and thsmstrnlm in ($thn)";
	}
	$this->vmtk->sql_orderby = 'semestbkmk,kdkmktrnlm,bobottrnlm desc';
    $data = $this->vmtk->getData($where);
		
	$this->sks_mbl=0.00;
	$this->sks_nm=0.00;
	$hsl=array();
	 if(!empty($data)){
 	  
        $hsl = array_filter($data,function($row){
			static $kode=array();			
			$ada = false;
			if(!in_array($row['kdkmktrnlm'],$kode)){
			  $kode[]=$row['kdkmktrnlm'];
              $ada = true;			  
			}
			return $ada;
		});
        
        $this->sks_mbl = array_reduce(array_column($hsl,'sksmktbkmk'),function($a,$b){ return $a+$b;});
        
		$this->sks_nm = array_reduce(array_map(function($row){ return $row['bobottrnlm']*$row['sksmktbkmk']; },$hsl),function($a,$b){ return $a+$b;});
			
	 }
        return $hsl;
     
   }
   
   function hitipk_krs($user,$thn="")
   {
    $this->vmtk->sql_select = "distinct kdkmktrnlm,nakmktbkmk,sksmktbkmk,nlakhtrnlm,bobottrnlm,wp,semestbkmk";
    if($thn==""){
	 $where = "nimhstrnlm='$user' and nlakhtrnlm not in ('T','K')"; 
	}else{
	 $where = "nimhstrnlm='$user' and nlakhtrnlm not in ('T','K') and thsmstrnlm in ($thn)";
	}
	$this->vmtk->sql_orderby = 'semestbkmk,kdkmktrnlm,bobottrnlm desc';
    $data = $this->vmtk->getData($where);
		
	$this->sks_mbl_krs=0.00;
	$this->sks_nm_krs=0.00;
	$hsl=array();
	 if(!empty($data)){
 	 $hsl = array_filter($data,function($row){
			static $kode=array();			
			$ada = false;
			if(!in_array($row['kdkmktrnlm'],$kode)){
			  $kode[]=$row['kdkmktrnlm'];
              $ada = true;			  
			}
			return $ada;
		});
        
        $this->sks_mbl_krs = array_reduce(array_column($hsl,'sksmktbkmk'),function($a,$b){ return $a+$b;});
        
		$this->sks_nm_krs = array_reduce(array_map(function($row){ return $row['bobottrnlm']*$row['sksmktbkmk']; },$hsl),function($a,$b){ return $a+$b;});
			
     
	    
	 
	 }
      return $hsl;
     
   }
	
}
?>