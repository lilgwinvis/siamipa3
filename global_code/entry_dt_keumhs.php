<?php
require_once 'shared.php';

$idx = $_POST['idx'];

$nim = isset( $_POST['nim']) ? $_POST['nim'] : "";
$acc = isset($_POST['acc']) ? $_POST['acc']: 0;
$pengali = isset($_POST['pengali']) ? $_POST['pengali']: 0;
$plh = isset($_POST['plh']) ? $_POST['plh']: array();



switch($idx)
{

  case 1 : 
          $dt_keumhs= new dt_keumhs;
		  $hsl = $dt_keumhs->tambah($nim,$acc,$pengali);
		  echo "Kewajiban Mahasiswa Berhasil Disimpan !!!";break;
		  break;
  case 2 : 
          $dt_keumhs = new dt_keumhs;
		  $hsl = $dt_keumhs->edit($nim,$acc,$pengali);
		  case 1 : echo "Kewajiban Mahasiswa Berhasil Diedit !!!";
		  break;
  case 3 : 
          $dt_keumhs = new dt_keumhs;
		  $hsl = $dt_keumhs->hapus($plh,$nim);
		  echo "Kewajiban Mahasiswa Berhasil Dihapus !!!";
          break;
  case 4 :
          $dt_keumhs = new dt_keumhs;
		  $hsl = $dt_keumhs->hitung($nim);		  
		  echo "Selesai Hitung Kewajiban !!!";   
          break;  
}  


?>