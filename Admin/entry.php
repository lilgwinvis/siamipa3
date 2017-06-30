<?php

 require_once 'shared.php'; 

 $am = array('A'=>4,'B'=>3,'C'=>2,'D'=>1,'E'=>0,'K'=>0,'T'=>0,'S'=>0);
 
 $dt_trnlp_trnlm = new dt_trnlp_trnlm;
 
 $vnim = $_POST['vnim'];       
 $nilai = $_POST['nilai'];		

 foreach($nilai as $idx=>$val)
 {
   $part = explode("_",$idx);
   $dt_trnlp_trnlm->updateData($part[0],$vnim,$part[1],$val,$am[$val]);
 }		

?>