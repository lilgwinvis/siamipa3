<?php

require_once 'shared.php';

$thn    = $_POST['thn'];
$sem    = $_POST['sem'];
$shift  = $_POST['shift'];
$kelas  = $_POST['kelas'];
$kdkmk  = $_POST['kdkmk'];
$nim    = $_POST['nim'];
$poll   = empty($_POST['poll']) ? array() : $_POST['poll']; 

if(empty($poll)){
  $hsl=array('stat'=>0,'msg'=>'Mohon kuosionernya diisi !!!');	
}else{
  if(count($poll)<12){
     $hsl=array('stat'=>0,'msg'=>'Mohon kuosionernya diisi !!!');
  }else{
	 
	 $dtpoll = new dt_poll;
	 if(!$dtpoll->alreadypoll($thn,$kdkmk,$nim)){
		 $dtpoll->updateDataMpoll($thn,$kdkmk,$nim);
		 $dtpoll->insertDataDpoll($thn,$sem,$shift,$kelas,$kdkmk,$poll); 
	 }
	 $hsl=array('stat'=>1); 
  }	  
}	
echo json_encode($hsl);
?>