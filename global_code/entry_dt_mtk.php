<?php
require_once 'shared.php';

$idx = $_POST['idx'];

$kddsn = isset( $_POST['kddsn']) ? $_POST['kddsn'] : "";
$kdkmk = isset( $_POST['kdkmk']) ? $_POST['kdkmk'] : "";
$nama = isset($_POST['nama']) ? $_POST['nama'] : "";
$kdprtk = isset($_POST['kdprtk']) ? $_POST['kdprtk']: "";
$sem = isset($_POST['sem']) ? $_POST['sem']: "";
$wp = isset($_POST['wp']) ? $_POST['wp']: "";
$skslptbkmk = isset($_POST['skslptbkmk']) ? $_POST['skslptbkmk']: "";
$sksprtbkmk = isset($_POST['sksprtbkmk']) ? $_POST['sksprtbkmk']: "";
$skstmtbkmk = isset($_POST['skstmtbkmk']) ? $_POST['skstmtbkmk']: "";
$plh = isset($_POST['plh']) ? $_POST['plh']: "";

switch($idx)
{

  case 1 : 
          $dt_mtk = new dt_mtk;
		  $hsl = $dt_mtk->tambah($kdkmk,$nama,$kdprtk,$sem,$wp,$skslptbkmk,$sksprtbkmk,$skstmtbkmk,$kddsn);
		  switch($hsl) 
		  { 
		   case 0 : echo "Matakuliah dengan kode=$kdkmk sudah ada !!!";break;
		   case 1 : echo "Data Matakuliah Berhasil Disimpan !!!";break;
          }
		  break;
  case 2 : 
          $dt_mtk = new dt_mtk;
		  $hsl = $dt_mtk->edit($kdkmk,$nama,$kdprtk,$sem,$wp,$skslptbkmk,$sksprtbkmk,$skstmtbkmk,$kddsn);
		  switch($hsl) 
		  { 
		   case 0 : echo "Matakuliah gagal diedit !!!";break;
		   case 1 : echo "Data Matakuliah Berhasil Diedit !!!";break;
          }
		  
          break;
  case 3 : 
          $dt_mtk = new dt_mtk;
		  $hsl = $dt_mtk->hapus($plh);
		  echo "Data Matakuliah Berhasil Dihapus !!!";
          break;
  case 4 : 
          $dt_syarat = new dt_syarat;
		  $hsl = $dt_syarat->hapus($kdkmk);
		  $hsl = $dt_syarat->tambah($plh,$kdkmk);
		  echo "Data Prasyarat Matakuliah Berhasil Disimpan !!!";
          break;		  
		  

}  


?>