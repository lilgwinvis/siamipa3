<?php
require_once 'shared.php';
class vw_mychart{
	function __construct() {
		// Type your code here
	}
	
	function vwchartmhs()
	{
		$dt = new dt_stat_mhs;		
		$chartdata=$dt->getdtchart();	
		return $chartdata;
	}
	
	function vwchartmhs1()
	{
		$dt = new dt_stat_mhs;		
		$chartdata=$dt->getdtchart1();	
		return $chartdata;
	}
	function vwchartmhs2()
	{
		$dt = new dt_stat_mhs;		
		$chartdata=$dt->getdtchart2();	
		return $chartdata;
	}
	
	function vwchartmhs3()
	{
		$dt = new dt_rekap_trkeumhs;		
		$chartdata=$dt->getdtchart();	
		return $chartdata;
	}
	
	function vwchartmhs4()
	{
		$dt = new dt_rekap_trkeumhs;		
		$chartdata=$dt->getdtchart1();	
		return $chartdata;
	}
	function vwchartmhs5()
	{
		$dt = new dt_rekap_trkeumhs;		
		$chartdata=$dt->getdtchart2();	
		return $chartdata;
	}
	
	
	
	
	
	
}
?>