<?php
require_once 'shared.php';

$idx = $_POST['idx'];

$thn = isset( $_POST['thn']) ? $_POST['thn'] : "";
$nim = isset( $_POST['nim']) ? $_POST['nim'] : "";
$tema = isset($_POST['edt']) ? $_POST['edt']: "";
$tglsrttgs = isset($_POST['tglsrttgs']) ? $_POST['tglsrttgs']: "";
$tglsk = isset($_POST['tglsk']) ? $_POST['tglsk']: "";
$nosrttgs = isset($_POST['nosrttgs']) ? $_POST['nosrttgs']: "";
$nosk = isset($_POST['noskbimbingan']) ? $_POST['noskbimbingan']: "";
$pemb1 = isset($_POST['Pembimbing1']) ? $_POST['Pembimbing1']: "";
$pemb2 = isset($_POST['Pembimbing2']) ? $_POST['Pembimbing2']: "";
$id = isset($_POST['id']) ? $_POST['id']: "";

switch($idx)
{

  case 1 : 
          $dt_ta = new dt_ta;
		  $hsl = $dt_ta->insertDataBimbingan($thn,$nim,$tema,$tglsrttgs,$tglsk,$nosrttgs,$nosk,$pemb1,$pemb2);
		  echo "Data Bimbingan Berhasil Disimpan !!!";          
		  break;
  case 2 : 
          $dt_ta = new dt_ta;
		  $hsl = $dt_ta->editDataBimbingan($thn,$nim,$tema,$tglsrttgs,$tglsk,$nosrttgs,$nosk,$pemb1,$pemb2);
		  echo "Data Bimbingan Berhasil Diedit !!!";
		  
          break;
  case 3 : 
          $tb_bimbingan = new tb_gen('tbbimbingan');
		  $data=array('idbimbingan'=>$id);
	      $tb_bimbingan->deleteRecord($data);
		  
		  $tb_penugasan = new tb_gen('tbpenugasan');  
	      $data=array('id'=>$id);
	      $tb_penugasan->deleteRecord($data); 
		  
		  $vwta = new vw_ta;
		  echo $vwta->view_bimbingan();
          break;
    
		  

}  


?>