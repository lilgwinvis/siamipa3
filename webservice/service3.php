<?php
require_once 'shared.php';
ini_set("soap.wsdl_cache_enabled", "0"); // disabling WSDL cache
$server = new SoapServer("inventory3.wsdl");

// create the function
function getJadwalSidang(){
  set_time_limit(120);
  
  $vw_ta = new vw_ta;
  $tmp = $vw_ta->view_sidang1();  
  
  return $tmp;
}

function getJudulSkripsi(){
  set_time_limit(120);
  $vw_ta = new vw_ta;
  $tmp = $vw_ta->view_judulskripsi();
  return $tmp;
}

function getBimbingan(){
  set_time_limit(120);
 
  $tmp = 'Daftar Bimbingan';
  return $tmp;
}


$server->addFunction("getJadwalSidang");
$server->addFunction("getJudulSkripsi");
$server->addFunction("getBimbingan");
$server->handle();


?>