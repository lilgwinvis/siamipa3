<?php

  require_once 'shared.php';

  $idx = $_POST['idx'];
  
  $tgl_input = date("Y-m-d H:i:s");;
  $user=$_SESSION['user'];
  
  $mtd='';
  if(isset($_POST['mtd']))
  {
	$tmp=$_POST['mtd'];
	for($i=0;$i<6;$i++){	  
	  $mtd.= isset($tmp[$i]) ? '1':'0'; 	  		  
	}  
  }
  
  $idbapdhmd = isset($_POST['idbapdhmd']) ? $_POST['idbapdhmd']:'';
  $sql_str = array();
  
  if(isset($_POST['presensi']))
  {
	$tmp= $_POST['presensi'];	
    foreach($tmp as $nim=>$abs)
    {
		$tmp_arr=array();
		$tmp_arr['id']='DHMD'.$idbapdhmd;
		$tmp_arr['nim']=$nim;
		$tmp_arr['presensi']=$abs;
		$tmp_arr['tgl_input']=$tgl_input;
		$tmp_arr['user']=$user;
		$sql_str[]=$tmp_arr;
	} 	  
  }
 

  $sql_str1 = array(); 
  $sql_str1['id'] ='BAP'.$idbapdhmd; 
  
  if(isset($_POST['tgl'])){
    $sql_str1['tgl']=$_POST['tgl'];
  }
  
  if(isset($_POST['m1'])){ 
   $sql_str1['materi1'] =$_POST['m1'];
  }
 
  if(isset($_POST['m2'])){   
    $sql_str1['materi2'] =$_POST['m2'];
  }
 
  if(isset($_POST['mtd']))
  {
	$sql_str1['mtd'] =$mtd;  
  }	  
  
  $sql_str1['tgl_input'] =$tgl_input;
  $sql_str1['user']=$user;
  
  $dt_bap = new dt_bap;
  $dt_dhmd = new dt_dhmd;
			  
  switch($idx){
	 case 1 : 
	          $dt_bap->save($sql_str1);
			  if(!empty($sql_str)){
			    foreach($sql_str as $row){ 
				 $dt_dhmd->save($row);
				} 
			  }
			  echo 'Data Berhasil Disimpan !!!'; 
	          break; 
	 case 2 : 
	          $dt_bap->update($sql_str1);
			  if(!empty($sql_str)){
				 foreach($sql_str as $row){  
			      $dt_dhmd->update($row);
	             }
			  }
			  echo 'Data Berhasil Diupdate !!!';
	          break; 
	  
  }	  


?>