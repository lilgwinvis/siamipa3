<?php 
     
	require_once 'shared.php';
	 
	 
     $thnsms = $_POST['thnsms'];
	 $kdkmk = isset($_POST['kdkmk']) ? $_POST['kdkmk'] : " ";
	 $kelas = $_POST['kelas'];
     $nim = $_POST['nim'];
	 $hm = $_POST['hm'];
	 $am = $_POST['am'];
     
     $trnlp_trnlm = new dt_trnlp_trnlm; 

	 $trnlp_trnlm->trnlmtotrnlp_trnlm($thnsms,$kdkmk,$kelas,$nim,$hm,$am);	 
	 
     $vw_publish_nilai = new vw_publish_nilai;
     echo $vw_publish_nilai->lht_mhs($kdkmk,$kelas,$thnsms);
?>