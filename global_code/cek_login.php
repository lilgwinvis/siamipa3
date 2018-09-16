<?php

require_once 'shared.php';

$tmp = isset($_POST['user']) ? $_POST['user'] : '';
$clean_code = preg_replace('/[^\w]/', '', $tmp);  
$user = $clean_code;
$tmp = isset($_POST['pass']) ? $_POST['pass'] : '';
$clean_code = preg_replace('/[^\w]/', '', $tmp);

$pass = $clean_code;
$idx = $_POST['idx'];
       
$longi = $_POST['longi'];
$lati = $_POST['lati'];
   
   $vlgn = new login;
   $hsl=$vlgn->user_login($user,$pass,$idx,$longi,$lati);     
   echo $hsl;    

?>
