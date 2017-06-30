<?php

require_once 'shared.php';



$nim = isset($_POST['nim']) ? $_POST['nim'] : null;
$kdmtk = $_POST['kdmtk'];

$klsmhs = $_POST['klsmhs'];
$semmhs = $_POST['semmhs'];
$thsmstrnlm = isset($_POST['thsmstrnlm']) ? $_POST['thsmstrnlm'] : "";

$idx = $_POST['idx'];

$hsl='';
switch($idx)
{ 
 case 1 : $ventri_krs = new dt_krs;
          $rslt = $ventri_krs->gantikls($nim,$kdmtk);      
          $hsl= $ventri_krs->msg_txt;
          $rslt = $ventri_krs->gantiklsmhs($klsmhs,$kdmtk);      
          $hsl= $hsl."\n".$ventri_krs->msg_txt;
          $rslt = $ventri_krs->gantisemmhs($semmhs,$kdmtk);      
          $hsl= $hsl."\n".$ventri_krs->msg_txt;
		  break;
 case 2 : $ventri_trnlm = new dt_trnlm;
          $rslt = $ventri_trnlm->gantiriwayatkls($nim,$kdmtk,$thsmstrnlm);      
          $hsl= $ventri_trnlm->msg_txt;
          $rslt = $ventri_trnlm->gantiriwayatklsmhs($klsmhs,$kdmtk,$thsmstrnlm);      
          $hsl= $hsl."\n".$ventri_trnlm->msg_txt;
          $rslt = $ventri_trnlm->gantiriwayatsemmhs($semmhs,$kdmtk,$thsmstrnlm);      
          $hsl= $hsl."\n".$ventri_trnlm->msg_txt;
		  break;		   
}		
echo $hsl;        
		
		
		

?>