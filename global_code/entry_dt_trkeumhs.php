<?php
require_once 'shared.php';

$idx = $_POST['idx'];
$id = isset($_POST['id']) ? $_POST['id'] : "";

$nim = isset( $_POST['nim']) ? $_POST['nim'] : "";
$acc = isset($_POST['acc']) ? $_POST['acc']: 0;
$datepicker = isset($_POST['datepicker']) ? $_POST['datepicker']: date("Y-m-d");
$tgl = isset($_POST['tgl']) ? $_POST['tgl']: date("Y-m-d");
$bayar = isset($_POST['bayar']) ? $_POST['bayar']: "";
$ket = isset($_POST['ket']) ? $_POST['ket']: "";
$plh = isset($_POST['plh']) ? $_POST['plh']: array();



switch($idx)
{

  case 1 : 
          $dt_trkeumhs= new dt_trkeumhs;
		  
		  if(is_array($datepicker)){
			 
             foreach($datepicker as $kd=>$tgl)
             {
				if(!empty($tgl)){
				   $hsl = $dt_trkeumhs->tambah($nim,$tgl,$kd,$bayar[$kd],$ket[$kd]);
				} 
			 }			 
			  
		  }		  
		  echo "Transaksi Keuangan Mahasiswa Berhasil Disimpan !!!";break;
		  break;
  case 2 : 
          $dt_trkeumhs = new dt_trkeumhs;
		  $hsl = $dt_trkeumhs->edit($nim,$tgl,$acc,$bayar,$ket,$id);
		  case 1 : echo "Transaksi Keuangan Mahasiswa Berhasil Diedit !!!";
		  break;
  case 3 : 
          $dt_trkeumhs = new dt_trkeumhs;
		  $hsl = $dt_trkeumhs->hapus($plh,$nim);
		  echo "Transaksi Keuangan Mahasiswa Berhasil Dihapus !!!";
          break;
  case 4 : $dt_trkeumhs = new dt_trkeumhs;
		   $hsl = $dt_trkeumhs->hitung($nim);
           echo "Transaksi Keuangan Mahasiswa Berhasil Diperbaiki !!!";
           break;		  

}  


?>