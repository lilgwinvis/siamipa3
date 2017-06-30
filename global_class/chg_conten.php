<?php
 
 require_once 'shared.php';
 
 $idx = $_POST['idx'];
 
 if(isset($_POST['nim'])){
  $nim = $_POST['nim'];
 }
 if(isset($_POST['kdds'])){
  $kdds = $_POST['kdds'];
 }
 if(isset($_POST['tg'])){
  $tg = $_POST['tg'];
 }
 if(isset($_POST['thn'])){
  $thn = $_POST['thn'];
 }
 if(isset($_POST['kls'])){
  $kls = $_POST['kls'];
 }
 
 if(isset($_POST['thn'])){
  $thnsms = $_POST['thn'];
 }
 
   
 switch($idx){
  case 1 :   $vsummary = new vw_summary;
             echo $vsummary->summarymhs($nim);
			 break;
  case 2 :   $vwkhs=new vwkhs;
             echo $vwkhs->buildkhs($nim,1);
			 break;
  case 3 :   $vwtrans=new vwtrans;
             echo $vwtrans->buildtrans($nim);
			 break;
  case 4 :   $vwriwayat=new vwriwayat;
             echo $vwriwayat->buildriwayat($nim,$tg);
			 break;
  case 11 :  $vwhutang=new vwhutang;
             echo $vwhutang->buildhutang($nim,$tg);
             break;
  case 12 :  $vw_ksd_ngajar=new vw_ksd_ngajar;
             echo $vw_ksd_ngajar->build($kdds);
             break;
  case 13 :  $vw_log = new vw_log;
             echo $vw_log->buildlst($tg);
             break;
  
  case 14 :  $vwsebaran=new vwsebaran;
             echo $vwsebaran->riwayatsebaran($thn);
			 break;
  case 15 :  $vwjdwlklh = new vwjdwlklh;
             echo $vwjdwlklh->build_riwayat($thn);
			 break;
  case 16 :  $vw_ksd_ngajar=new vw_ksd_ngajar;
             echo $vw_ksd_ngajar->lst_riwayat_dsn($thn);
             break;
  
  case 17 :  $vwtrkeumhs = new vwtrkeumhs;
             echo $vwtrkeumhs->trankeumhs($nim);
			 break;
  
  case 18 :  $vwkeumhs = new vwkeumhs;
             echo $vwkeumhs->keumhs($nim);
             break;
  
  case 19 :  
             $vwtottrkeumhs = new vwtottrkeumhs;
             echo $vwtottrkeumhs->tottrankeumhs($nim);
			 break;
			 
  case 20 :  $vwkeuangk = new vwkeuangk;
             echo $vwkeuangk->keuangk($thn,$kls);
			 break;
  case 21 :  $vwstatmhs = new vw_stat_mhs;
             echo $vwstatmhs->stat_mhs($thn);
			 break;
  case 22 :  $vwriwayatkrs = new vw_riwayat_krs;
             echo $vwriwayatkrs->riwayat_krs($thn);
			 break;
			 
  case 23 :  $vw_epsbed_trakd = new vw_epsbed_trakd;
             echo $vw_epsbed_trakd->epsbed_trakd($thn);break;
  case 24 :  
             $dt_epsbed_trakd = new dt_epsbed_trakd;
			 $dt_epsbed_trakd->siatoepsbed($thn);
             $vw_epsbed_trakd = new vw_epsbed_trakd;
			 echo $vw_epsbed_trakd->epsbed_trakd($thn);
             break;
  case 25 :  
             $dt_epsbed_trakd = new dt_epsbed_trakd;
			 $dt_epsbed_trakd->delData($thn);
             $vw_epsbed_trakd = new vw_epsbed_trakd;
			 echo $vw_epsbed_trakd->epsbed_trakd($thn);
             break;
  case 26 :  
             $dt_epsbed_trakd = new dt_epsbed_trakd;
			 echo $dt_epsbed_trakd->getTRAKD();
             break;	
  case 27 :  
             $vw_epsbed_trnlm = new vw_epsbed_trnlm;
			 echo $vw_epsbed_trnlm->epsbed_trnlm($thn);break;
  case 28 :  
             $dt_epsbed_trnlm = new dt_epsbed_trnlm; 
             $dt_epsbed_trnlm->siatoepsbed($thn);
             $vw_epsbed_trnlm = new vw_epsbed_trnlm;
			 echo $vw_epsbed_trnlm->epsbed_trnlm($thn);
             break;
  case 29 :  $dt_epsbed_trnlm = new dt_epsbed_trnlm; 
             $dt_epsbed_trnlm->delData($thn);
             $vw_epsbed_trnlm = new vw_epsbed_trnlm;
			 echo $vw_epsbed_trnlm->epsbed_trnlm($thn);
             break;
  case 30 :  
             $dt_epsbed_trnlm = new dt_epsbed_trnlm;
             echo $dt_epsbed_trnlm->getTRNLM();
             break;			 
  case 31 :  $vw_epsbed_trnlp = new vw_epsbed_trnlp;
             echo $vw_epsbed_trnlp->epsbed_trnlp($nim);break;
  case 32 :  $dt_epsbed_trnlp = new dt_epsbed_trnlp;
             $dt_epsbed_trnlp->siatoepsbed($nim);
             $vw_epsbed_trnlp = new vw_epsbed_trnlp;
			 echo $vw_epsbed_trnlp->epsbed_trnlp($nim);
             break;
  case 33 :  $dt_epsbed_trnlp = new dt_epsbed_trnlp;
             $dt_epsbed_trnlp->delData($nim);
             $vw_epsbed_trnlp = new vw_epsbed_trnlp;
			 echo $vw_epsbed_trnlp->epsbed_trnlp($nim);
             break;
  case 34 :  $dt_epsbed_trnlp = new dt_epsbed_trnlp;
             echo $dt_epsbed_trnlp->getTRNLP();
			 break;
  case 35 :  $vw_epsbed_kmk = new vw_epsbed_kmk;
             echo $vw_epsbed_kmk->epsbed_kmk($thn);break;
  case 36 :  $dt_epsbed_kmk = new dt_epsbed_kmk;
             $dt_epsbed_kmk->siatoepsbed($thn);
             $vw_epsbed_kmk = new vw_epsbed_kmk;
			 echo $vw_epsbed_kmk->epsbed_kmk($thn);
             break;
  case 37 :  $dt_epsbed_kmk = new dt_epsbed_kmk;
             $dt_epsbed_kmk->delData($thn);
             $vw_epsbed_kmk = new vw_epsbed_kmk;
			 echo $vw_epsbed_kmk->epsbed_kmk($thn);
             break;
  case 38 :  $dt_epsbed_kmk = new dt_epsbed_kmk;
             echo $dt_epsbed_kmk->getTBKMK();
             break;			 
  case 39 :  $vw_epsbed_trakm = new vw_epsbed_trakm;
             echo $vw_epsbed_trakm->epsbed_trakm($thn);break;
  case 40 :  $dt_epsbed_trakm = new dt_epsbed_trakm;
             $dt_epsbed_trakm->siatoepsbed($thn);
             $vw_epsbed_trakm = new vw_epsbed_trakm;
			 echo $vw_epsbed_trakm->epsbed_trakm($thn);
             break;
  case 41 :  $dt_epsbed_trakm = new dt_epsbed_trakm;
             $dt_epsbed_trakm->delData($thn);
             $vw_epsbed_trakm = new vw_epsbed_trakm;
			 echo $vw_epsbed_trakm->epsbed_trakm($thn);
             break;
  case 42 :  $dt_epsbed_trakm = new dt_epsbed_trakm;
             echo $dt_epsbed_trakm->getTRAKM();
             break;
  case 43 :  $vw_epsbed_trlsm = new vw_epsbed_trlsm; 
             echo $vw_epsbed_trlsm->epsbed_trlsm($thn);break;
  case 44 :  $dt_epsbed_trlsm = new dt_epsbed_trlsm;
             $dt_epsbed_trlsm->siatoepsbed($thn);
             $vw_epsbed_trlsm = new vw_epsbed_trlsm;
			 echo $vw_epsbed_trlsm->epsbed_trlsm($thn);
             break;
  case 45 :  $dt_epsbed_trlsm = new dt_epsbed_trlsm;
             $dt_epsbed_trlsm->delData($thn);
             $vw_epsbed_trlsm = new vw_epsbed_trlsm;
			 echo $vw_epsbed_trlsm->epsbed_trlsm($thn);
             break;
  case 46 :  $dt_epsbed_trlsm = new dt_epsbed_trlsm;
             echo $dt_epsbed_trlsm->getTRLSM();
             break;	
  case 47 :   
             $dt_epsbed_trnlm = new dt_epsbed_trnlm;
             $dt_epsbed_trnlm->siakrstoepsbed($thn);
              $vw_epsbed_trnlm = new vw_epsbed_trnlm;
			 echo $vw_epsbed_trnlm->epsbed_trnlm($thn);
             break; 			 
   case 48 :   $vw_trnlp_trnlm = new vw_trnlp_trnlm;
               echo $vw_trnlp_trnlm->edt_trnlp_trnlm($nim);
			   break;
   case 49 :   $dt_epsbed_kmk->salin($thn);
               $vw_epsbed_kmk = new vw_epsbed_kmk;
			   echo $vw_epsbed_kmk->epsbed_kmk($thn);
               break;
	case 50 :$dt_epsbed_msmhs = new dt_epsbed_msmhs;  
             $dt_epsbed_msmhs->siatoepsbed($thn);
             $vw_epsbed_msmhs = new vw_epsbed_msmhs;
			 echo $vw_epsbed_msmhs->epsbed_msmhs();
             break;	
    case 51 :$dt_epsbed_msmhs = new dt_epsbed_msmhs;  
             $dt_epsbed_msmhs->delData($thn);
             $vw_epsbed_msmhs = new vw_epsbed_msmhs;
			 echo $vw_epsbed_msmhs->epsbed_msmhs();
             break; 			 
	case 52 :$dt_epsbed_msmhs = new dt_epsbed_msmhs;
	         echo $dt_epsbed_msmhs->getMSMHS();
             break;
    case 53 :$dt_epsbed_msmhs = new dt_epsbed_msmhs;  
             $dt_epsbed_msmhs->UpdateData($thn);
             $vw_epsbed_msmhs = new vw_epsbed_msmhs;
			 echo $vw_epsbed_msmhs->epsbed_msmhs();
             break;	
    case 54 :$vw_epsbed_trnlm = new vw_epsbed_trnlm;
	         echo $vw_epsbed_trnlm->stat('stat1_epsbedtrnlm',0);
             break;
    case 55 :$vw_epsbed_trakd = new vw_epsbed_trakd;
	         echo $vw_epsbed_trakd->stat('stat1_epsbedtrnlm',0);
             break;	
    case 56 :$vw_epsbed_trakm = new vw_epsbed_trakm;
	         echo $vw_epsbed_trakm->stat('stat1_epsbedtrnlm',0);
             break; 
    case 57 :$vw_epsbed_trlsm = new vw_epsbed_trlsm;
	         echo $vw_epsbed_trlsm->stat('stat1_epsbedtrnlm',0);
             break;
	case 58 : $vw_epsbed_trnlp = new vw_epsbed_trnlp;
	         echo $vw_epsbed_trnlp->stat('stat1_epsbedtrnlm',0);
             break;		 
	case 59 : $dt_stat_mhs = new dt_stat_mhs;
	          $dt_stat_mhs->import($thnsms);
			  $vwstatmhs = new vw_stat_mhs;
	          echo $vwstatmhs->stat_mhs($thn);break;
              break;
    case 60 : $vwjdwlklh = new vwjdwlklh;
	          $dtjdwlklh=new dt_jdwl_klh;
              $dtjdwlklh->hitung_akhir();
			  echo $vwjdwlklh->build();
			  break;
    case 61 :$vw_epsbed_kmk = new vw_epsbed_kmk;
	         echo $vw_epsbed_kmk->stat('stat1_epsbedtbkmk',0);
             break;	
	case 62 :$vwforlap = new vw_forlap;
             echo $vwforlap->dataforlapmhs($nim);			 
             break;	
    case 63 :$vwforlap = new vw_forlap;
             echo $vwforlap->dataforlapdsn($nim);			 
             break;
    case 64 :  $vwentrybapdhmd=new vwentrybapdhmd;
             echo $vwentrybapdhmd->listmtkdsn($thn);
			 break;			 
 }
?>