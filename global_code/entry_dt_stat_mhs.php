<?php
require_once 'shared.php';

$idx = $_POST['idx'];

$thn = isset( $_POST['thn']) ? $_POST['thn'] : "";
$stat = isset($_POST['stat']) ? $_POST['stat']: array();
$plh = isset($_POST['plh']) ? $_POST['plh']: array();



switch($idx)
{

  case 1 : 
          $dt_stat_mhs = new dt_stat_mhs;
		  $hsl = $dt_stat_mhs->tambah($thn,$stat);
		  echo "Status Mahasiswa Disimpan !!!";break;
		  break;
  case 2 : 
          $dt_stat_mhs = new dt_stat_mhs;
		  $hsl = $dt_stat_mhs->edit($thn,$stat);
		  echo "Status Mahasiswa Berhasil Diedit !!!";
		  break;
  case 3 : 
          $dt_stat_mhs = new dt_stat_mhs;
		  $hsl = $dt_stat_mhs->hapus($thn,$plh);
		  echo "Status Mahasiswa Berhasil Dihapus !!!";
          break;
		  

}  


?>