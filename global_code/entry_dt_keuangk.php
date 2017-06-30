<?php
require_once 'shared.php';

$idx = $_POST['idx'];

$thn = isset( $_POST['thn']) ? $_POST['thn'] : "";
$kls = isset($_POST['kls']) ? $_POST['kls']: "";
$acc = isset($_POST['acc']) ? $_POST['acc']: 0;
$kewajiban = isset($_POST['kewajiban']) ? $_POST['kewajiban']: 0;
$dibyr = isset($_POST['dibyr']) ? $_POST['dibyr']: 0;
$plh = isset($_POST['plh']) ? $_POST['plh']: array();



switch($idx)
{

  case 1 : 
          $dt_keuangk = new dt_keuangk;
		  $hsl = $dt_keuangk->tambah($thn,$kls,$acc,$kewajiban,$dibyr);
		  echo "Kewajiban Angkatan Berhasil Disimpan !!!";break;
		  break;
  case 2 : 
          $dt_keuangk = new dt_keuangk;
		  $hsl = $dt_keuangk->edit($thn,$kls,$acc,$kewajiban,$dibyr);
		  case 1 : echo "Kewajiban Angkatan Berhasil Diedit !!!";
		  break;
  case 3 : 
          $dt_keuangk = new dt_keuangk;
		  $hsl = $dt_keuangk->hapus($plh,$thn,$kls);
		  echo "Kewajiban Angkatan Berhasil Dihapus !!!";
          break;
  case 4 :
          $dt_keuangk = new dt_keuangk;
		  $hsl = $dt_keuangk->hitung($thn,$kls);		  
		  echo "Selesai Hitung Kewajiban !!!";   
          break; 		  
		  

}  


?>