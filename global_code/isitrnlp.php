<?php

require_once 'shared.php';

$nim = isset($_POST['nim']) ? $_POST['nim'] : '';
$mk = isset($_POST['mk']) ? $_POST['mk']:'';
$nilai = isset($_POST['nilai']) ? $_POST['nilai']:'';
$idx = isset($_POST['idx']) ? $_POST['idx']:'';

 $ventri_trnlp = new dt_trnlp;
    
 
 if($idx==1){
 
    $rslt = $ventri_trnlp->gantihmtrnlp($nim,$nilai); 
 }else
   if ($idx==2){
        $rslt = $ventri_trnlp->hapustrnlp($nim,$mk);
    }else{
       $rslt = $ventri_trnlp->simpantrnlp($nim,$mk,$nilai);
    }  
 
        
  $hsl= $ventri_trnlp->msg_txt;
	   
		
echo $hsl;        
		
		
		

?>