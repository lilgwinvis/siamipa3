<?php

 require_once 'shared.php';
 set_time_limit(120);
 $idx = isset($_POST['idx']) ? $_POST['idx'] :0;
 
 switch($idx){
	case 1 : 
	         $vwdos=new vwdosen;
	         echo $vwdos->viewdata();
	         break;
	case 2 : $vwriwayat=new vwriwayat;
			 echo $vwriwayat->dsn_filter();
			 break;
	case 3 : $vwhutang=new vwhutang;
			 echo $vwhutang->dsn_filter();
			 break;
	case 4 : $ksd_dosen = new vw_ksd_ngajar;
             echo $ksd_dosen->lst_dsn();
			 break;
	case 5 :$vwnilai = new vwnilai;
			echo json_encode($vwnilai->ss_viewdata($_POST));
            break;  
    case 6 :$vwsummary = new vw_summary;
			echo json_encode($vwsummary->ss_viewdata($_POST));
            break;  			
 }	 
 
 
 ?>