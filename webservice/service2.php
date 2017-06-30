<?php
require_once 'shared.php';
ini_set("soap.wsdl_cache_enabled", "0"); // disabling WSDL cache
$server = new SoapServer("inventory2.wsdl");

// create the function
function getJadwal(){
  set_time_limit(120);
  $vwjdwlklh = new vwjdwlklh;
  $tmp = $vwjdwlklh->build(); 
  
  return $tmp;
}

function printJadwal(){
  set_time_limit(120);
  $vwjdwlklh = new vwjdwlklh;
  $tmp = $vwjdwlklh->ctk_jdwl_topdf(); 
  $tmp = str_replace("../","http://fmipa-unibba.org/sia/",$tmp);
  return $tmp;
}


$server->addFunction("printJadwal");
$server->addFunction("getJadwal");
$server->handle();


?>