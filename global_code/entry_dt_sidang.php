<?php
require_once 'shared.php';

$idx = $_POST['idx'];

$thn = isset( $_POST['thn']) ? $_POST['thn'] : "";
$nim = isset( $_POST['nim']) ? $_POST['nim'] : "";
$judul = isset($_POST['judul']) ? $_POST['judul']: "";
$absindo = isset($_POST['absindo']) ? $_POST['absindo']: "";
$absing = isset($_POST['absing']) ? $_POST['absing']: "";
$tglsid = isset($_POST['tglsid']) ? $_POST['tglsid']: "";
$sesi = isset($_POST['sesi']) ? $_POST['sesi']: "";
$tgllls = isset($_POST['tgllls']) ? $_POST['tgllls']: "";
$tglsk = isset($_POST['tglsk']) ? $_POST['tglsk']: "";
$nosk = isset($_POST['nosk']) ? $_POST['nosk']: "";
$pengu1 = isset($_POST['Penguji1']) ? $_POST['Penguji1']: "";
$pengu2 = isset($_POST['Penguji2']) ? $_POST['Penguji2']: "";
$pengu3 = isset($_POST['Penguji3']) ? $_POST['Penguji3']: "";
$id = isset($_POST['id']) ? $_POST['id']: "";
$pemb1 = isset($_POST['Pemb1']) ? $_POST['Pemb1']: "";
$pemb2 = isset($_POST['Pemb2']) ? $_POST['Pemb2']: "";
$idbimbingan = isset($_POST['idbimbingan']) ? $_POST['idbimbingan']: "";

switch($idx)
{

  case 1 : 
          $dt_ta = new dt_ta;
		  $hsl = $dt_ta->insertDataSidang($idbimbingan,$thn,$nim,$judul,$absindo,$absing,$tglsid,$sesi,$tgllls,$tglsk,$nosk,$pengu1,$pengu2,$pengu3,$pemb1,$pemb2);
		  echo "Data Sidang Berhasil Disimpan !!!";          
		  break;
  case 2 : 
          
		  echo $absing;
		  $dt_ta = new dt_ta;
		  $hsl = $dt_ta->editDataSidang($idbimbingan,$thn,$nim,$judul,$absindo,$absing,$tglsid,$sesi,$tgllls,$tglsk,$nosk,$pengu1,$pengu2,$pengu3,$pemb1,$pemb2);
		  echo "Data Sidang Berhasil Diedit !!!";
		  
          break;
  case 3 : 
          $tb_sidang = new tb_gen('tbsidang');
		  $data=array('idsidang'=>$id);
	      $tb_sidang->deleteRecord($data);
		  
		  $tb_penugasan = new tb_penugasan;	  
	      $data=array('id'=>$id);
	      $tb_penugasan->deleteRecord($data); 
		  
		  $vwta = new vw_ta;
		  echo $vwta->view_sidang();
          break;
    
		  

}  


?>