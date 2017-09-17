<?php

require_once 'shared.php';

class dt_trans 
{
   var $vnilai;
   var $vmtk;
   var $sks_mbl;
   var $sks_nm;
   
   //var $sks_mbl_krs;
   //var $sks_nm_krs;
   
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
	   $this->sks_mbl = array_reduce(array_column($hsl,'sksmktbkmk'),function($a,$b){ return $a+$b;});

      }
      return $hsl;
   }
   
   function hitipk($user,$thn="")
   {
    $this->vmtk->sql_select = "nimhstrnlm,SUM(sksmktbkmk) AS jml_sks, SUM(sksmktbkmk*bobottrnlm) AS jml_sksnm";    

    if($thn==""){
	 $where = "nimhstrnlm='$user' and nlakhtrnlm not in ('K')"; 
	}else{
	 $where = "nimhstrnlm='$user' and nlakhtrnlm not in ('K') and thsmstrnlm in ($thn)";
	}
	

     $this->vmtk->sql_from = "(SELECT nimhstrnlm,kdkmktrnlm,sksmktbkmk,MAX(bobottrnlm) AS bobottrnlm FROM vw_tbtrnlptrnlmjnmtk WHERE $where GROUP BY nimhstrnlm,kdkmktrnlm) a";
     $this->vmtk->sql_orderby = '';
     

    $data = $this->vmtk->getData('');
		
	//$this->sks_mbl=0.00;
	//$this->sks_nm=0.00;
	$hsl=array('jml_sks'=>0,'jml_sksnm'=>0,'ipk'=>0);
	 if(!empty($data)){
 	  
        //$hsl = array_filter($data,function($row){
		//	static $kode=array();			
		//	$ada = false;
		//	if(!in_array($row['kdkmktrnlm'],$kode)){
		//	  $kode[]=$row['kdkmktrnlm'];
        //      $ada = true;			  
		//	}
		//	return $ada;
		//});
        
        $hsl['jml_sks'] = $data[0]['jml_sks'];
        $hsl['jml_sksnm'] = $data[0]['jml_sksnm']; 
        $hsl['ipk'] = $hsl['jml_sks']!=0 ?   $hsl['jml_sksnm']/ $hsl['jml_sks'] :0;

        //$this->sks_mbl = $data[0]['jml_sks'];        
		//$this->sks_nm = $data[0]['jml_sksnm'];


        //$this->sks_mbl = array_reduce(array_column($hsl,'sksmktbkmk'),function($a,$b){ return $a+$b;});
        
		//$this->sks_nm = array_reduce(array_map(function($row){ return $row['bobottrnlm']*$row['sksmktbkmk']; },$hsl),function($a,$b){ return $a+$b;});
			
	 }
        return $hsl;
     
   }
   
   function hitipk_krs($user,$thn="")
   {
    $this->vmtk->sql_select = "nimhstrnlm,SUM(sksmktbkmk) AS jml_sks, SUM(sksmktbkmk*bobottrnlm) AS jml_sksnm"; 
    
    if($thn==""){
	 $where = "nimhstrnlm='$user' and nlakhtrnlm not in ('T','K')"; 
	}else{
	 $where = "nimhstrnlm='$user' and nlakhtrnlm not in ('T','K') and thsmstrnlm in ($thn)";
	}
	

     $this->vmtk->sql_from = "(SELECT nimhstrnlm,kdkmktrnlm,sksmktbkmk,MAX(bobottrnlm) AS bobottrnlm FROM vw_tbtrnlptrnlmjnmtk WHERE $where GROUP BY nimhstrnlm,kdkmktrnlm) a";
     $this->vmtk->sql_orderby = '';
    
    
    $data = $this->vmtk->getData('');
		
	//$this->sks_mbl_krs=0.00;
	//$this->sks_nm_krs=0.00;
	$hsl=array('jml_sks'=>0,'jml_sksnm'=>0,'ipk'=>0);
	 if(!empty($data)){
 	 //$hsl = array_filter($data,function($row){
		//	static $kode=array();			
		//	$ada = false;
		//	if(!in_array($row['kdkmktrnlm'],$kode)){
		//	  $kode[]=$row['kdkmktrnlm'];
          //    $ada = true;			  
			//}
			//return $ada;
		//});
        
        //$this->sks_mbl_krs = array_reduce(array_column($hsl,'sksmktbkmk'),function($a,$b){ return $a+$b;});
        
		//$this->sks_nm_krs = array_reduce(array_map(function($row){ return $row['bobottrnlm']*$row['sksmktbkmk']; },$hsl),function($a,$b){ return $a+$b;});
			
        $hsl['jml_sks'] = $data[0]['jml_sks'];
        $hsl['jml_sksnm'] = $data[0]['jml_sksnm']; 
        $hsl['ipk'] = $hsl['jml_sks']!=0 ?   $hsl['jml_sksnm']/ $hsl['jml_sks'] :0;      
	    
	 
	 }
      return $hsl;
     
   }
	
}
?>