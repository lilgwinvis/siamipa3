<?php

require_once 'shared.php';

$nim = $_POST['nim'];
$mk = isset($_POST['mk']) ? $_POST['mk'] : array();
$jsks = isset($_POST['totalsks']) ? $_POST['totalsks'] : 0 ;
$kls = isset($_POST['kls']) ? $_POST['kls'] : array();
$idx = isset($_POST['idx']) ? $_POST['idx'] : 0;
$thnsms = isset($_POST['thnsms']) ? $_POST['thnsms'] : 0;

$ventri_krs = new dt_riwayat_krs;
    
 
 if($idx==1){ 
    $rslt = $ventri_krs->gantiklskrs($nim,$mk,$kls,$thnsms); 
 }else
   if ($idx==2){
        $rslt = $ventri_krs->hapuskrs($nim,$mk,$thnsms);
    }else{
        $rslt = $ventri_krs->simpankrs($nim,$mk,$jsks,$kls,$thnsms);
    }  
 
        
  $hsl= $ventri_krs->msg_txt;
	   
		
echo $hsl;        
		
		
		

?>