<?php
require_once 'shared.php';

$idx = $_POST['idx'];

$kode = isset( $_POST['Kode']) ? $_POST['Kode'] : "";
$nama = isset($_POST['nama']) ? $_POST['nama'] : "";
$tstat = isset($_POST['tstat']) ? $_POST['tstat']: "";
$hstat = isset($_POST['hstat']) ? $_POST['hstat']: "";
$smawl = isset($_POST['smawl']) ? $_POST['smawl']: "";
$nidn1 = isset($_POST['nidn1']) ? $_POST['nidn1']: "";
$nidn2 = isset($_POST['nidn2']) ? $_POST['nidn2']: "";
$link =  isset($_POST['link_forlap']) ? $_POST['link_forlap']: "";

$plh = isset($_POST['plh']) ? $_POST['plh']: "";


switch($idx)
{

  case 1 : 
          $dt_dsn = new dt_dosen;
		  $hsl = $dt_dsn->tambah($kode,$nama,$tstat,$hstat,$smawl,$nidn1,$nidn2,$link);
		  switch($hsl) 
		  { 
		   case 0 : echo "Dosen dengan kode=$kode sudah ada !!!";break;
		   case 1 : echo "Data Dosen Berhasil Disimpan !!!";break;
          }
		  break;
  case 2 : 
          $dt_dsn = new dt_dosen;
		  $hsl = $dt_dsn->edit($kode,$nama,$tstat,$hstat,$smawl,$nidn1,$nidn2,$link);
		  switch($hsl) 
		  { 
		   case 0 : echo "Dosen gagal diedit !!!";break;
		   case 1 : echo "Data Dosen Berhasil Diedit !!!";break;
          }
		  
          break;
  case 3 : 
          $dt_dsn = new dt_dosen;
		  $hsl = $dt_dsn->hapus($plh);
		  echo "Data Dosen Berhasil Dihapus !!!";
          break;
		  

}  


?>