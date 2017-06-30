<?php

require_once 'shared.php';
$nim = $_POST['nim'];
$mk = $_POST['mk'];
$jsks = $_POST['totalsks'];



 $ventri_krs = new dt_krs;
 $rslt = $ventri_krs->simpankrs($nim,$mk,$jsks);      
 $hsl= $ventri_krs->msg_txt;
	   
		
echo $hsl;        
		
		
		

?>