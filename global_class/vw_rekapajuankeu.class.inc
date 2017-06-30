<?php
  require_once 'shared.php';

class vw_rekapajuankeu {
	
	
	function __construct() {
		// Type your code here
	}
	
	function tbl_rekap()
	{
		$dt = new dt_rekapkeu;
		
        $header = array(array("Tahun","Dana Masuk","Dana Keluar","Surflus","Defisit"));  
		
		$datatotal=$dt->getrekapkeutotal();
				
		$tbstat = array("id" => "rekaptotal",'width'=>'100%');
		$tbl = new mytable($tbstat,$header,$datatotal['isitable'],$datatotal['footer']);
		$content1=$tbl->display();
				
		$dataoperasional=$dt->getrekapkeuoperasional();		
				
		$tbstat = array("id" => "rekapoperasional",'width'=>'100%');
		$tbl = new mytable($tbstat,$header,$dataoperasional['isitable'],$dataoperasional['footer']);
		
		$content2=$tbl->display();
		
		 
		 $header = array('Total Keuangan Per Tahun','Total Operasional Per tahun');
         $arrcontent=array($content1,$content2);
		 $mytabs = new mytabs('tabs1',$header,$arrcontent);
		 return $mytabs->display();
	}
	
}
?>