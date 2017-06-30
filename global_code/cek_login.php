<?php

require_once 'shared.php';
  
$user = $_POST['user'];
$pass = $_POST['pass'];
$idx = $_POST['idx'];
       
$longi = $_POST['longi'];
$lati = $_POST['lati'];
   
   $vlgn = new login;
   $hsl=$vlgn->user_login($user,$pass,$idx,$longi,$lati);     
   echo $hsl;    

?>
