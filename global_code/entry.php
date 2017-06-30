<?php

require_once 'shared.php';


$kdkmk  = $_POST['kdkmk'];
$thnsms = $_POST['thnsms'];
$kelas  = $_POST['kelas'];


$kls = isset($_POST['kls']) ? $_POST['kls'] : "";
$nilai  = $_POST['nilai'];
$idx  = $_POST['idx'];
 
 $ventri_trnlm = new dt_trnlm;
 $hsl="";
 if($idx==1){ 
   $rslt = $ventri_trnlm->gantikls($kls,$thnsms,$kdkmk,$kelas);      
   $hsl= $ventri_trnlm->msg_txt;
 }
 $rslt = $ventri_trnlm->updatenilai($nilai,$thnsms,$kdkmk);      
 $hsl= $hsl." ".$ventri_trnlm->msg_txt;	      
		
echo $hsl;        
		
		
		

?>