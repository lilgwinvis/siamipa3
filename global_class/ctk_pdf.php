<?php

 require_once 'shared.php';
  
 
 $nim = isset($_POST['nim']) ? $_POST['nim'] : ''; 
 $idx = isset($_POST['idx']) ? $_POST['idx'] : '';
 $thnsms = isset($_POST['thnsms']) ? $_POST['thnsms'] : '';

  
 switch($idx){
  case 1 : $vwkrs=new vw_krs;
           echo $vwkrs->ctk_krs_topdf($nim); 
		   break; 
  case 2 : $vwjdwlklh=new vwjdwlklh; ;
           echo $vwjdwlklh->ctk_jdwl_topdf(); 
		   break; 
  case 3 : $vvwtrans=new vwtrans;
           echo $vvwtrans->ctk_pdf($nim); 
		   break;
  case 4 : $vwriwayatkrs=new vw_riwayat_krs;
           echo $vwriwayatkrs->ctk_krs_topdf($nim,$thnsms); 
		   break;  
 }
?>