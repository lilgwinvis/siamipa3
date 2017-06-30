<?php
require_once 'shared.php';

$idx = $_POST['idx'];

$nim = isset( $_POST['NIM']) ? $_POST['NIM'] : "";
$nama = isset($_POST['nama']) ? $_POST['nama'] : "";
$thnmsk = isset($_POST['thnmsk']) ? $_POST['thnmsk']: "";
$tempat = isset($_POST['tempat']) ? $_POST['tempat']: "";
$sem = isset($_POST['sem']) ? $_POST['sem']: "";
$kelas = isset($_POST['kelas']) ? $_POST['kelas']: "";
$kelamin = isset($_POST['kelamin']) ? $_POST['kelamin']: "";
$datepicker = isset($_POST['datepicker']) ? $_POST['datepicker']: "";
$plh = isset($_POST['plh']) ? $_POST['plh']: "";

$agama = isset( $_POST['agama']) ? $_POST['agama'] : "";
$alamat = isset($_POST['alamat']) ? $_POST['alamat'] : "";
$email = isset($_POST['email']) ? $_POST['email']: "";
$penddk = isset($_POST['penddk']) ? $_POST['penddk']: "";
$status = isset($_POST['status']) ? $_POST['status']: "";
$tlp = isset($_POST['tlp']) ? $_POST['tlp']: "";
$bp = isset($_POST['bp']) ? $_POST['bp']: "";
$link = isset($_POST['link_forlap']) ? $_POST['link_forlap']: "";

switch($idx)
{

  case 1 : 
          $dt_mhs = new dt_mhs;
		  $hsl = $dt_mhs->tambah($nim,$nama,$thnmsk,$tempat,$sem,$kelas,$kelamin,$datepicker,$agama,$alamat,$email,$penddk,$status,$tlp,$bp,$link);
		  switch($hsl) 
		  { 
		   case 0 : echo "Mahasiswa dengan NIM=$nim sudah ada !!!";break;
		   case 1 : echo "Data Mahasiswa Berhasil Disimpan !!!";break;
          }
		  break;
  case 2 : 
          $dt_mhs = new dt_mhs;
		  $hsl = $dt_mhs->edit($nim,$nama,$thnmsk,$tempat,$sem,$kelas,$kelamin,$datepicker,$agama,$alamat,$email,$penddk,$status,$tlp,$bp,$link);
		  switch($hsl) 
		  { 
		   case 0 : echo "Data Mahasiswa gagal diedit !!!";break;
		   case 1 : echo "Data Mahasiswa Berhasil Diedit !!!";break;
          }
		  
          break;
  case 3 : 
          $dt_mhs = new dt_mhs;
		  $hsl = $dt_mhs->hapus($plh);
		  echo "Data Mahasiswa Berhasil Dihapus !!!";
          break;
		  

}  


?>