<?php
require_once 'shared.php';
$kdds = $_POST['kdds'];
$plh = isset($_POST['plh']) ? $_POST['plh'] : array();
$hari = isset($_POST['hari']) ? $_POST['hari'] : array();
$mulai =isset($_POST['mulai']) ? $_POST['mulai'] : array();
$ass = isset($_POST['ass']) ? $_POST['ass'] : array();
$acc = isset($_POST['acc']) ? $_POST['acc']: array();
$hnr = isset($_POST['hnr']) ? $_POST['hnr'] : array();
$idx_switch = isset($_POST['idx']) ? $_POST['idx'] : 0;

$vmtk = new dt_mtk;

switch($idx_switch){
case 1 :  

          $vb = new tb_gen('ksd_ngajar');   
          $vkrs = new dt_krs;
		 
          $TA = $vkrs->TA();
          $errors=array();
		  
          foreach($hari as $f=>$v)
		  {
		    
			$tmp = $f;
			$f=str_replace("'", "", $f);
			$f=str_replace("\\", "", $f);
            $param=explode("_",$f);			
			$today = date("Y-m-d H:i:s");
			$tmp1= isset($acc[$tmp]) ? $acc[$tmp] : 0 ;							
			
			$sksmktbkmk=$vmtk->getsksmtk($param[0]);
		    $time = new DateTime($mulai[$tmp]);
		    $add_minute=($sksmktbkmk*50);
		    $time->modify('+'.$add_minute.'minutes');
			
			$entry =array('Kdkmk'=>$param[0],'kdds'=>$kdds,'shift'=>$param[1],'thnsms'=>$TA,'sem'=>$param[2],'jawalklh'=>$mulai[$tmp],'jakhirklh'=>$time->format('H:i:s'),'kdass'=>$ass[$tmp],'hariklh'=>$v,'klsklh'=>$param[3],'tgl_input'=>$today,'disetujui'=>$tmp1,'hnr'=>$hnr[$tmp]);
     
            $vb->updateRecord($entry);
			
		  }
          echo "Data Berhasil Disimpan !!!"; 
          break;
case 2 :  if(!empty($plh))
{
   $vb = new tb_gen('ksd_ngajar');   
   $vkrs = new dt_krs;
   $TA = $vkrs->TA();
   $errors=array();
   
   foreach($plh as $idx){
   
   $tmp = "'".$idx."'";
   $param=explode("_",$idx);
        
   $entry =array('Kdkmk'=>$param[0],'kdds'=>$kdds,'shift'=>$param[1],'thnsms'=>$TA,'sem'=>$param[2],'klsklh'=>$param[3]);
     
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
   $vb = new tb_gen('ksd_ngajar');   
   $vkrs = new dt_krs;
   $TA = $vkrs->TA();
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

	
    $entry =array('Kdkmk'=>$param[0],'kdds'=>$kdds,'shift'=>$param[1],'thnsms'=>$TA,'sem'=>$param[2],'jawalklh'=>$mulai[$tmp],'jakhirklh'=>$time->format('H:i:s'),'kdass'=>$ass[$tmp],'hariklh'=>$hari[$tmp],'klsklh'=>$param[3],'tgl_input'=>$today,'disetujui'=>$tmp1,'hnr'=>$param[1]);
     
    $vb->insertrecord($entry);
  
  }    
  
	echo "Data Kesediaan Berhasil Disimpan !!!";   
  
}else{
   echo "Kesediaan Tidak di cheklist !!!"; 
}
}
?>