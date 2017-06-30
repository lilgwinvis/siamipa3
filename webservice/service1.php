<?php
require_once 'shared.php';
ini_set("soap.wsdl_cache_enabled", "0"); // disabling WSDL cache
$server = new SoapServer("inventory1.wsdl");

// create the function
function getKRS(){
  set_time_limit(90);
  $dtkrs = new dt_krs;
  $vwkrs = new vw_krs;
  
  $TA = $dtkrs->TA();
  
  $sem = str_split($TA, 4);
    
  $accheader=array("Mahasiswa yang sudah mengisi KRS","Matakuliah yang ditawarkan Semester ".($sem[1]==1 ? "Ganjil" : "Genap")." ".$sem[0]);
  
  $acccontent=array();  
  $acccontent[]=$vwkrs->viewdatamhs(1);
  $acccontent[]=$vwkrs->viewdatamtk();
  
  $myaccordion = new myaccordion('accordion',$accheader,$acccontent);
  
  $tmp = $myaccordion->display(1);
  
  return $tmp;
}


$server->addFunction("getKRS");
$server->handle();


?>