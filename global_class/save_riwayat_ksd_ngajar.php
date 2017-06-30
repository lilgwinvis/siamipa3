<?php
require_once 'shared.php';

$kdds = $_POST['kdds'];
$thn = $_POST['thn'];
$plh = isset($_POST['plh']) ? $_POST['plh']: "";
$hari = isset($_POST['hari']) ? $_POST['hari'] : array();
$mulai = isset($_POST['mulai']) ? $_POST['mulai'] : array();
$ass = isset($_POST['ass']) ? $_POST['ass'] : array();
$hnr = isset($_POST['hnr']) ?  $_POST['hnr']: array();
$idx_switch = isset($_POST['idx']) ? $_POST['idx']: "";

$vmtk = new dt_mtk;

switch($idx_switch){
case 1 :  

	$vb = new tb_gen('pengajar';           
	$TA = $thn;
	$errors=array();
	$param =array();
	$entry = array();
	foreach($hari as $f=>$v)
	{
		
		$tmp = $f;
		
		$f=str_replace("'", "", $f);
		
		$param=explode("_",$f);
		
		$today = date("Y-m-d H:i:s");
		
		$sksmktbkmk=$vmtk->getsksmtk($param[0]);
		$time = new DateTime($mulai[$tmp]);
		$add_minute=($sksmktbkmk*50);
		$time->modify('+'.$add_minute.'minutes'); 
		
		if (isset($hnr[$tmp])){		
			$entry =array('kdkmkpengajar'=>$param[0],'kddspengajar'=>$kdds,'shiftpengajar'=>$param[1],'thnsmspengajar'=>$TA,'semespengajar'=>$param[2],'jawalpengajar'=>$mulai[$tmp],'jakhirpengajar'=>$time->format('H:i:s'),'kdass'=>$ass[$tmp],'haripengajar'=>$v,'kelaspengajar'=>$param[3],'tgl_input'=>$today,'hnrpengajar'=>$hnr[$tmp]);
		}else
		{
			$entry =array('kdkmkpengajar'=>$param[0],'kddspengajar'=>$kdds,'shiftpengajar'=>$param[1],'thnsmspengajar'=>$TA,'semespengajar'=>$param[2],'jawalpengajar'=>$mulai[$tmp],'jakhirpengajar'=>$time->format('H:i:s'),'kdass'=>$ass[$tmp],'haripengajar'=>$v,'kelaspengajar'=>$param[3],'tgl_input'=>$today);
		}			
		$vb->updateRecord($entry);
		
	}
	echo "Data Berhasil Disimpan !!!"; 
	break;
case 2 :  if(!empty($plh))
	{
		$vb = new tb_gen('pengajar');   
		$TA = $thn;
		$errors=array();

		foreach($plh as $idx){

			$tmp = "'".$idx."'";
			$param=explode("_",$idx);
			
			$entry =array('kdkmkpengajar'=>$param[0],'kddspengajar'=>$kdds,'shiftpengajar'=>$param[1],'thnsmspengajar'=>$TA,'semespengajar'=>$param[2],'kelaspengajar'=>$param[3]);
			
			$vb->deleterecord($entry);

		}    

		echo "Data Berhasil Dihapus !!!";   

	}else{
		echo "Cheklist Kesediaan yang akan dihapus !!!"; 
	}
	break;
default:		  
	if(!empty($plh))
	{
		$vb = new tb_gen('pengajar');   
		$TA = $thn;
		$errors=array();

		foreach($plh as $idx){
			
			$tmp = "'".$idx."'";
			$param=explode("_",$idx);
			$today = date("Y-m-d H:i:s");
			$tmp1= 0;
			
			$sksmktbkmk=$vmtk->getsksmtk($param[0]);
			$time = new DateTime($mulai[$tmp]);
			$add_minute=($sksmktbkmk*50);
			$time->modify('+'.$add_minute.'minutes'); 
			
			$entry =array('kdkmkpengajar'=>$param[0],'kddspengajar'=>$kdds,'shiftpengajar'=>$param[1],'thnsmspengajar'=>$thn,'semespengajar'=>$param[2],'jawalpengajar'=>$mulai[$tmp],'jakhirpengajar'=>$time->format('H:i:s'),'kdass'=>$ass[$tmp],'haripengajar'=>$hari[$tmp],'kelaspengajar'=>$param[3],'tgl_input'=>$today,'hnrpengajar'=>$param[1]);
			
			$vb->insertrecord($entry);

		}    

		echo "Data Kesediaan Berhasil Disimpan !!!";   

	}else{
		echo "Kesediaan Tidak di cheklist !!!"; 
	}
}
?>