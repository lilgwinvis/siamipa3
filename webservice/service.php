<?php
require_once 'shared.php';
ini_set("soap.wsdl_cache_enabled", "0"); // disabling WSDL cache
$server = new SoapServer("inventory.wsdl");

// create the function
function getNMtk(){
  set_time_limit(90);
  $vwnilai = new vwnilai;  
  return $vwnilai->viewdata();
}


$server->addFunction("getNMtk");
$server->handle();


?>