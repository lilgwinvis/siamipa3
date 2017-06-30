<?php
require_once 'shared.php';

$idx = $_POST['idx'];

$idajuan = isset( $_POST['idajuan']) ? $_POST['idajuan'] : "";
$tglajuan = isset($_POST['tglajuan']) ? $_POST['tglajuan'] : "";
$noajuan = isset($_POST['noajuan']) ? $_POST['noajuan']: "";
$perihalajuan = isset($_POST['perihalajuan']) ? $_POST['perihalajuan']: "";
$tglcair = isset($_POST['tglcair']) ? $_POST['tglcair']: "";
$jmlajuan = isset($_POST['jmlajuan']) ? $_POST['jmlajuan']: 0;
$jmlcair = isset($_POST['jmlcair']) ? $_POST['jmlcair']: 0;
$tgllpj =  isset($_POST['tgllpj']) ? $_POST['tgllpj']: "";
$dilpjkan =  isset($_POST['dilpjkan']) ? $_POST['dilpjkan']: 0;
$dibagikan =  isset($_POST['dibagikan']) ? $_POST['dibagikan']: 0;
$accoutlvl1 =  isset($_POST['accoutlvl1']) ? $_POST['accoutlvl1']: 0;

$plh = isset($_POST['plh']) ? $_POST['plh']: "";


switch($idx)
{

  case 1 : 
          $dtajuankeu = new dt_ajuankeu;
		  $hsl = $dtajuankeu->tambah($tglajuan,$noajuan,$perihalajuan,$jmlajuan,$tglcair,$jmlcair,$tgllpj,$dilpjkan,$dibagikan,$accoutlvl1);
		  switch($hsl) 
		  { 
		   case 0 : echo "Ajuan Keuangan dengan kode=$idajuan sudah ada !!!";break;
		   case 1 : echo "Ajuan Keuangan Berhasil Disimpan !!!";break;
          }
		  break;
  case 2 : 
          $dtajuankeu = new dt_ajuankeu;
		  $hsl =$dtajuankeu->edit($idajuan,$tglajuan,$noajuan,$perihalajuan,$jmlajuan,$tglcair,$jmlcair,$tgllpj,$dilpjkan,$dibagikan,$accoutlvl1);
		  switch($hsl) 
		  { 
		   case 0 : echo "Ajuan Keuangan gagal diedit !!!";break;
		   case 1 : echo "Ajuan Keuangan Berhasil Diedit !!!";break;
          }
		  
          break;
  case 3 : 
          $dtajuankeu = new dt_ajuankeu;
		  $hsl = $dtajuankeu->hapus($plh);
		  echo "Ajuan Keuangan Berhasil Dihapus !!!";
          break;
		  

}  


?>