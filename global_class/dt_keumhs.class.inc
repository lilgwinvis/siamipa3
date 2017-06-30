<?php

require_once 'shared.php';

class dt_keumhs
{

	function __construct(){

	}

	function getkeumhs($nim)
	{
		$tb=new tb_gen('vw_kewajibankeumhs');
		$where = "nimkeumhs='$nim'";
		$data = $tb->getData($where);
		return $data;
	}

	function getnoacclvl1($nim,$idx=1)
	{
		$tb_mhs=new tb_gen('msmhs');
		$where ="nimhsmsmhs='$nim'";
		
		$data = $tb_mhs->getData($where);
		
		$thn = 0;
		$shift= "";
		if(!empty($data))
		{
			foreach($data as $row)
			{
				$thn =$row['tahunmsmhs'];
				$shift=$row['shiftmsmhs']; 
				
			}
		}
		
		$tb_keuangk=new tb_gen('vw_keuangk_jn_acclvl1');	 
		$where ="";
		if($idx==1){	  
			$where =" angkkeuangk=$thn and shiftkeuangk='$shift' and noacclvl1keuangk not in (select acclvl1keumhs from keumhs where nimkeumhs='$nim')";
		}
		$data = $tb_keuangk->getData($where);
		return $data;
	}

	function getpengali($nim,$kd)
	{
		$tb=new tb_gen('keumhs');
		$where ="nimkeumhs='$nim' and acclvl1keumhs=$kd";
		$data = $tb->getData($where);
		$byr=0.00;
		if(!empty($data))
		{
			foreach($data as $row)
			{
				$byr=$row['pengalikeumhs'];
			}
		}
		return $byr;
	}

	function getkalibyr($angk,$shift,$kd)
	{
		$tb=new tb_gen('vw_keuangk_jn_acclvl1');
		$where ="angkkeuangk=$angk and shiftkeuangk='$shift' and noacclvl1keuangk=$kd";
		$data = $tb->getData($where);
		$byr=0;
		if(!empty($data))
		{
			foreach($data as $row)
			{
				$byr=$row['kalibyrkeuangk'];
			}
		}
		return $byr;
	}

	private function isaccexist($nim,$acc)
	{
		$tb_keumhs = new tb_gen('keumhs');
		$data = $tb_keumhs->getData("nimkeumhs='$nim' and acclvl1keumhs=$acc");
		return !empty($data);	   
	}

	private function tambah_kewajiban($nim,$acc,$pengali,$isedit=false)
	{
		if($this->isaccexist($nim,$acc)){
		  if($isedit){	
			$this->edit($nim,$acc,$pengali);
		  }
		}else{
			$this->tambah($nim,$acc,$pengali); 
		} 	
	}
	
	function hitung($nim)
	{
		$tb_mhs=new tb_gen('msmhs');
		$where ="nimhsmsmhs='$nim'";
		
		$data = $tb_mhs->getData($where);
		
		$thn = 0;
		$shift= '';
		$smawl= '';
		if(!empty($data))
		{
			foreach($data as $row)
			{
				$thn =$row['tahunmsmhs'];
				$shift=$row['shiftmsmhs']; 
				$smawl=$row['smawlmsmhs'];
			}
		}
		
		$dtstat = new dt_stat_mhs;
		$jmlaktif=$dtstat->getjmlaktif($nim);
		$jmlaktif = ($jmlaktif>=8)? 7 :$jmlaktif;
		
		$dtrnlm = new dt_trnlm;
		$skspersem = $dtrnlm->getjmlskspersem($nim);
		
		$mythnsem = new mythnsem;
		
		$dtkrs = new dt_krs;
		$skskrs = $dtkrs->getjmlsks($mythnsem->getthnsem(),$nim); 
		
		//hitung pengali sks
		$txt='SKS : ';
		$prakpersks = 0;
		$prakpersem = 0;
		
			for($i=1;$i<=12;$i++)
			{
				$tmpsem=$mythnsem->addthnsem($smawl,$i-1);
				
				if(isset($skspersem[$tmpsem])){										
					$kalibyr = $this->getkalibyr($thn,$shift,'4'.$i);					
					switch($kalibyr)
					{
					case 1 :$this->tambah_kewajiban($nim,'4'.$i,1,true);break;
					case 2 : 					
						    $jmlsks = ($thn<2013) ? $skspersem[$tmpsem]['sksmtk']-$skspersem[$tmpsem]['sksprtk'] : $skspersem[$tmpsem]['sksmtk'] ;	
							$this->tambah_kewajiban($nim,'4'.$i,$jmlsks,true); 
						    break;		
					}
					$prakpersem += 1;
					$prakpersks += $skspersem[$tmpsem]['sksprtk'];
				}else{
					if($tmpsem==$mythnsem->getthnsem()){
						
						$kalibyr = $this->getkalibyr($thn,$shift,'4'.$i);
						
						switch($kalibyr)
						{
						case 1 :$this->tambah_kewajiban($nim,'4'.$i,1,true);break;
                        case 2 : 
								$jmlsks = ($thn<2013) ? $skskrs['mtk']-$skskrs['prtk'] : (isset($skskrs['mtk']) ? $skskrs['mtk'] :0 );
							    $this->tambah_kewajiban($nim,'4'.$i,$jmlsks,true);
							    break;		
						}
						if($dtstat->getstatmhs($tmpsem,$nim,1)=='A'){
							$prakpersem += 1;					
							$prakpersks += isset($skskrs['prtk']) ? $skskrs['prtk'] : 0;
						}  
					}
				}
			}		 
		 
		
		
		//hitung pengali spp
		$txt.='<br> Spp : ';
			
			for($i=1;$i<=12;$i++)
			{
				$tmpsem=$mythnsem->addthnsem($smawl,$i-1);		
				if(isset($skspersem[$tmpsem])){	
					$kalibyr = $this->getkalibyr($thn,$shift,'5'.$i);
					
					switch($kalibyr)
					{
					case 1 :$this->tambah_kewajiban($nim,'5'.$i,1,true);break;
					case 2 : 
						if(isset($skspersem[$tmpsem])){ 
							$this->tambah_kewajiban($nim,'5'.$i,$skspersem[$tmpsem]['sksmtk'],true);
						}break;		
					}
				}else{
					if($tmpsem==$mythnsem->getthnsem()){
						$kalibyr = $this->getkalibyr($thn,$shift,'5'.$i);
						
						switch($kalibyr)
						{
						case 1 :$this->tambah_kewajiban($nim,'5'.$i,1,true);break;
						case 2 : 
							if(isset($skspersem[$tmpsem])){ 
								$this->tambah_kewajiban($nim,'5'.$i,$skskrs['sksmtk'],true);
							}break;		
						}
					}
				}
				
			}		 
		 
		
		
		//hitung pengali praktikum
		
		$kalibyr = $this->getkalibyr($thn,$shift,50);
		$txt.='<br> Praktikum : ';
		switch($kalibyr)
		{
		case 1 : $prakpersem = $prakpersem>7 ? 7 : $prakpersem;			
				 $this->tambah_kewajiban($nim,50,$prakpersem,true); 
			     break;
		case 2 :$this->tambah_kewajiban($nim,50,$prakpersks,true);break;		
		}
		
		//hitung biaya kkn
		
		if(!empty($skspersem))
		{
			if((isset($skspersem['kkn'])) and ($skspersem['kkn']==1))
			{
				$this->tambah_kewajiban($nim,9,1);
			}
		}
		if(!empty($skskrs))
		{
			if((isset($skskrs['kkn'])) and ($skskrs['kkn']==1))
			{
				$this->tambah_kewajiban($nim,9,1);				
			}
		}
		
		//hitung biaya skripsi
		$arr_kode=array(121,122,123,141,142,143,11,15);
		if(!empty($skspersem))
		{
			if((isset($skspersem['skripsi'])) and ($skspersem['skripsi']==1))
			{								
				foreach($arr_kode as $kd){
				   $this->tambah_kewajiban($nim,$kd,1);
				}			
			}
		}
		if(!empty($skskrs))
		{
			if((isset($skskrs['skripsi'])) and ($skskrs['skripsi']==1))
			{
				foreach($arr_kode as $kd){
				   $this->tambah_kewajiban($nim,$kd,1);
				}	
			}
		}
		
		//kewajiban mahasiswa baru
		$arr_kode=array(1,3,21,22,23,24,25,26,27,28);
		foreach($arr_kode as $kd){
			$this->tambah_kewajiban($nim,$kd,1);
		}	
		
		return $txt;
	}


	function tambah($nim,$acc,$pengali)
	{
		
		$tb_keumhs = new tb_gen('keumhs');
		$tb_keumhs->insertRecord(array('nimkeumhs'=>$nim,'acclvl1keumhs'=>$acc,'pengalikeumhs'=>$pengali));
		return 1;
	}

	function edit($nim,$acc,$pengali)
	{
		$tb_keumhs = new tb_gen('keumhs'); 
		$tb_keumhs->updateRecord(array('nimkeumhs'=>$nim,'acclvl1keumhs'=>$acc,'pengalikeumhs'=>$pengali));
		return 1;
	}

	function hapus($plh,$nim)
	{
		$tb_keumhs = new tb_gen('keumhs');
		
		if(!empty($plh))
		{
			foreach($plh as $kode)
			{
				$tb_keumhs->deleteRecord(array('acclvl1keumhs'=>$kode,'nimkeumhs'=>$nim));
			}
		}	  
		
		return 1;
	}

}


?>