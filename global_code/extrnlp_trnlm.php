<?php

require_once 'shared.php';

$nim = isset($_POST['nim']) ? $_POST['nim'] : '';
$idx = isset($_POST['idx']) ? $_POST['idx']:'';

 $ventri_trnlp_trnlm = new dt_trnlp_trnlm;
    
 
 if($idx==1){
 
    $rslt = $ventri_trnlp_trnlm->trnlptotrnlp_trnlm($nim); 
 }else
   if ($idx==2){
        $rslt = $ventri_trnlp_trnlm->trnlmtotrnlp_trnlm($nim);
    }
 
        
  $hsl= $ventri_trnlp_trnlm->msg_txt;
	   
		
echo $hsl;        
		
		
		

?>