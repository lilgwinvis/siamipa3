<?php

require_once 'shared.php';

class dt_keuangk 
{

	function __construct(){

	}

	function getkeuangk($thn,$shift)
	{
		$tb=new tb_gen('vw_keuangk_jn_acclvl1');
		$where = "angkkeuangk='$thn' and shiftkeuangk='$shift'";
		$data = $tb->getData($where);
		return $data;
	}

	function getnoacclvl1($thn,$shift,$idx=1)
	{
		$tb=new tb_gen('acclvl1');
		$where ="";
		if($idx==1){	  
			$where = "noacclvl1 not in (select noacclvl1keuangk from keuangk where angkkeuangk=$thn and shiftkeuangk='$shift')";
		}

		$data = $tb->getData($where);
		return $data;
	}

	function getbyr($thn,$shift,$kd)
	{
		$tb=new tb_gen('keuangk');
		$where ="angkkeuangk=$thn and shiftkeuangk='$shift' and noacclvl1keuangk=$kd";
		$data = $tb->getData($where);
		$byr=0.00;
		if(!empty($data))
		{
			foreach($data as $row)
			{
				$byr=$row['jmlbyrkeuangk'];
			}
		}
		return $byr;
	}


	function getdibyr($thn,$shift,$kd)
	{
		$tb=new tb_gen('keuangk');
		$where ="angkkeuangk=$thn and shiftkeuangk='$shift' and noacclvl1keuangk=$kd";
		$data = $tb->getData($where);
		$dibyr=0;
		if(!empty($data))
		{
			foreach($data as $row)
			{
				$dibyr=$row['kalibyrkeuangk'];
			}
		}
		return $dibyr;
	}

	private function isaccexist($thn,$kls,$acc)
	{
		$tb_keuang = new tb_gen('keuangk');
		$data = $tb_keuang->getData("angkkeuangk='$thn' and shiftkeuangk='$kls' and noacclvl1keuangk=$acc");
		return !empty($data);	   
	}
	
	private function tambah_kewajiban($thn,$kls,$acc,$kewajiban,$dibyr){
		if(!$this->isaccexist($thn,$kls,$acc)){
				$this->tambah($thn,$kls,$acc,$kewajiban,$dibyr);
			}
	}

	function hitung($thn,$kls)
	{
		$mythnsem = new mythnsem;
		$thnakh=$mythnsem->getthn();

		//kewajiban mahasiswa baru
		$arr_kode=array(1,3,21,22,23,24,25,26,27,28);
		foreach($arr_kode as $kd){			
		   $this->tambah_kewajiban($thn,$kls,$kd,$this->getbyr($thn-1,$kls,$kd),$this->getdibyr($thn-1,$kls,$kd));			
		}
				
		//kewajiban praktikum
		
		$this->tambah_kewajiban($thn,$kls,50,$this->getbyr($thn-1,$kls,50),$this->getdibyr($thn-1,$kls,50));
		
		//kewajiban kkn
		if(($thnakh-$thn)>=3){
			$this->tambah_kewajiban($thn,$kls,9,$this->getbyr($thn-1,$kls,9),$this->getdibyr($thn-1,$kls,9));
		}
		
		//kewajiban skripsi
		$arr_kode=array(121,122,123,141,142,143,11,15);
		
		if(($thnakh-$thn)>=4){
			foreach($arr_kode as $kd){			
				$this->tambah_kewajiban($thn,$kls,$kd,$this->getbyr($thn-1,$kls,$kd),$this->getdibyr($thn-1,$kls,$kd));			
			}
		}
				
		//kewajiban sks
				
		$j=1;
		for($i=$thn;$i<=$thnakh;$i++)
		{
				if($j==1){  
					$this->tambah_kewajiban($thn,$kls,'4'.$j,$this->getbyr($thn-1,$kls,'4'.$j),$this->getdibyr($thn-1,$kls,'4'.$j));
				}else{
					$this->tambah_kewajiban($thn,$kls,'4'.$j,$this->getbyr($thn,$kls,'4'.$j-1),$this->getdibyr($thn,$kls,'4'.$j-1)); 
				}
			
			$j++;
				$this->tambah_kewajiban($thn,$kls,'4'.$j,$this->getbyr($thn,$kls,'4'.$j-1),$this->getdibyr($thn,$kls,'4'.$j-1));
			$j++;
		}
		
		//kewajiban spp
		$j=1;
		for($i=$thn;$i<=$thnakh;$i++)
		{
			
				if($j==1){  
					$this->tambah_kewajiban($thn,$kls,'5'.$j,$this->getbyr($thn-1,$kls,'5'.$j),$this->getdibyr($thn-1,$kls,'5'.$j));
				}else{
					$this->tambah_kewajiban($thn,$kls,'5'.$j,$this->getbyr($thn,$kls,'5'.$j-1),$this->getdibyr($thn,$kls,'5'.$j-1)); 
				}
			
			$j++;
			
				$this->tambah_kewajiban($thn,$kls,'5'.$j,$this->getbyr($thn,$kls,'5'.$j-1),$this->getdibyr($thn,$kls,'5'.$j-1));
			
			$j++;
		}
		
		
		
		
	}


	function tambah($thn,$kls,$acc,$kewajiban,$dibyr)
	{
		$tb_keuangk = new tb_gen('keuangk'); 
		$tb_keuangk->insertRecord(array('angkkeuangk'=>$thn,'shiftkeuangk'=>$kls,'noacclvl1keuangk'=>$acc,'jmlbyrkeuangk'=>$kewajiban,'kalibyrkeuangk'=>$dibyr));
		return 1;
		

	}

	function edit($thn,$kls,$acc,$kewajiban,$dibyr)
	{
		$tb_keuangk = new tb_gen('keuangk'); 
		$tb_keuangk->updateRecord(array('angkkeuangk'=>$thn,'shiftkeuangk'=>$kls,'noacclvl1keuangk'=>$acc,'jmlbyrkeuangk'=>$kewajiban,'kalibyrkeuangk'=>$dibyr));
		return 1;

	}

	function hapus($plh,$thn,$kls)
	{
		$tb_keuangk = new tb_gen('keuangk');
		
		if(!empty($plh))
		{
			foreach($plh as $kode)
			{
				$tb_keuangk->deleteRecord(array('noacclvl1keuangk'=>$kode,'angkkeuangk'=>$thn,'shiftkeuangk'=>$kls));
			}
		}	  
		
		return 1;
	}

}


?>