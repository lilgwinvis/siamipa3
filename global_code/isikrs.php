<?php

require_once 'shared.php';

$nim = $_POST['nim'];
$mk = isset($_POST['mk']) ? $_POST['mk'] : array();
$jsks = isset($_POST['Jumlah']) ? $_POST['Jumlah'] : 0 ;
$kls = isset($_POST['kls']) ? $_POST['kls'] : array();
$idx = isset($_POST['idx']) ? $_POST['idx'] : 0;

 $ventri_krs = new dt_krs;
    
 
 if($idx==1){ 
    $rslt = $ventri_krs->gantiklskrs($nim,$mk,$kls); 
 }else
   if ($idx==2){
        $rslt = $ventri_krs->hapuskrs($nim,$mk);
    }else{
       
	   $rslt = $ventri_krs->simpankrs($nim,$mk,$jsks,$kls);
    }  
 
        
  $hsl= $ventri_krs->msg_txt;
	   
		
echo $hsl;        
		
		
		

?>