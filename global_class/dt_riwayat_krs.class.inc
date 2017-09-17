<?php
require_once 'shared.php';

class dt_riwayat_krs 
{
	var $vtrans;
	var $vmsmhs;
	var $vkrs_mtk;
	var $vmtk;
	var $vkrs;
	var $vtrnlm_trnlp;

	function __construct()
	{
		
		$this->vkrs_mtk = new tb_gen('trnlm_jn_mtk');
		$this->vkrs_mtk->sql_select  = 'thsmstrnlm,nimhstrnlm,kdkmktrnlm,nakmktbkmk,sksmktbkmk,sksprtbkmk,shifttrnlm,semestrnlm,kelastrnlm,semestbkmk,wp,tgl_input';
		$this->vkrs_mtk->sql_orderby = 'semestbkmk,kdkmktrnlm'; 
		
		
		$this->vtrans=new dt_trans;
		$this->vmsmhs=new tb_gen('msmhs');
		$this->vmtk=new tb_gen('tbkmk');
		$this->vkrs = new tb_gen('trnlm');
		$this->vtrnlm_trnlp = new tb_gen('trnlm_trnlp');
	}

	function getAllMhs(){     
		$where = "";
		$data = $this->vkrs_mhs->getData($where);
		return $data; 
	}
	

	function simpankrs($user,$mk,$jml_sks,$kls,$thnsms)
	{
		

		$tmp = str_split($thnsms, 4);
		
		if($tmp[1]==1)
		{
			$bts=$tmp[0]-1;
			
		}else
		{
			$bts=$tmp[0];
			
		}
		
		$txt_filter="00000,";
		for($i=2007;$i<=$bts;$i++)
		{
			for($j=1;$j<=2;$j++)
			{
				$txt_filter.="'".$i.$j."',";		 
			} 
		}
		
		if($tmp[1]==1)
		{
			$txt_filter.="'".$thnsms."'";
			
		}else{
			$txt_filter = rtrim($txt_filter, ',');
		}
		
		$txt_filter1 = rtrim($txt_filter, "'".$thnsms."'"); 
		$txt_filter1 = rtrim($txt_filter1, ',');
		
		$dt = $this->vtrans->hitipk_krs($user,$txt_filter1);
		$ipk= ($dt['jml_sks']>0) ? round($dt['jml_sksnm']/$dt[jml_sks],2) : 0;
			 
		if($ipk>2.99){
			$sks_blh=24;
		} else{
			if(($ipk>=2.50) and($ipk<=2.99)){
				$sks_blh=21;
			} else{
				if(($ipk>=2.00) and ($ipk<=2.49)){
					$sks_blh=18;
				} else{
					if(($ipk>=1.50) and ($ipk<=1.99)){
						$sks_blh=16;
					} else{
						if(($ipk>0.00) and ($ipk<=1.49)){
							$sks_blh=14;
						} else{  
							$sks_blh=20;
						}

					}

				}

			}

		}		  
		
		//$sks_blh=24;
		
		$where = "nimhsmsmhs='$user'";
		$sqlrslt = $this->vmsmhs->getData($where);
		
		foreach($sqlrslt as $row){		  
			$thnmsmhs=$row['tahunmsmhs'];
		}     
		
		
		
		$sem = str_split($thnsms, 4);
		
		$j=0;
		for($i=$thnmsmhs;$i<=$sem[0];$i++){
			$j++;
		}
		
		
		
		$kls_mhs=1;
		if($sem[1]==1 and $j>0){
			$kls_mhs=($j*2)-1;
		}else{	     
			if($sem[1]==2 and $j>0){ 
				$kls_mhs=($j*2);
			}
		}
		
		
		if($kls_mhs<10){	 
			$kls_mhs_txt='0'.(string) $kls_mhs;
		}else{
			$kls_mhs_txt=(string) $kls_mhs;
		} 
		
		
		$where = "nimhstrnlm='$user' and thsmstrnlm='$thnsms' and kdkmktrnlm NOT LIKE 'MATP%'";
		
		$sqlrslt1 = $this->vkrs_mtk->getData($where);
		//$num_rows = $this->vkrs->numrows;
		
		
		if(!empty($sqlrslt1)){
			foreach($sqlrslt1 as $row){
				$jml_sks+=$row['sksmktbkmk'];
			}  			   
		}
		
		
		if($jml_sks<=$sks_blh){	 
			
			
			if(!empty($mk)){	
				
				foreach($mk as $vmk){
					
					$kelas=$kls[$vmk];
					
					$today = date("Y-m-d H:i:s");
					$data1=array('thsmstrnlm'=> $thnsms,'nimhstrnlm'=>$user,'kdkmktrnlm'=>$vmk,'shifttrnlm'=>$kelas,'tgl_input'=>$today,'semestrnlm'=>$kls_mhs_txt,'nlakhtrnlm'=>'T','bobottrnlm'=>0);
					$this->vkrs->insertRecord ($data1);
					
					$data1=array('thsmstrnlm'=> $thnsms,'nimhstrnlm'=>$user,'kdkmktrnlm'=>$vmk,'nlakhtrnlm'=>'T','bobottrnlm'=>0);
					$this->vtrnlm_trnlp->insertRecord($data1);
					
					
					$where = "kdkmktbkmk='$vmk' and sksprtbkmk=1";
					$data2 = $this->vmtk->getData($where);
					$num_rows = $this->vmtk->numrows;
					
					if($num_rows>0){
						foreach($data2 as $row1){
							$tmp=$row1['kdprtk'];			   
						}           
						
						if(!empty($tmp)){	
							
							$data=array('thsmstrnlm'=> $thnsms,'nimhstrnlm'=>$user,'kdkmktrnlm'=>$tmp,'shifttrnlm'=>$kelas,'tgl_input'=>$today,'semestrnlm'=>$kls_mhs_txt,'nlakhtrnlm'=>'T','bobottrnlm'=>0);
							$this->vkrs->insertRecord ($data);
							
							
							
						}
					}
					
				}
			}
			
			$this->msg_txt ="Kartu Rencana Studi (KRS) Disimpan !!!";
			
			return 1;
		}else{
			
			$this->msg_txt ="IPK = ".number_format($ipk, 2, '.', '')." Hanya diperkenankan mengambil ".$sks_blh." sks !!!";
			//$this->msg_txt ="Hanya diperkenankan mengambil maksimal 24 sks !!!";
			return 0;
		}
		
		
	}

	function hapuskrs($user,$mk,$thnsms)
	{
		if(!empty($mk)){
			
			foreach($mk as $vmk){	   		   
				
				
				$data1=array('thsmstrnlm'=> $thnsms,'nimhstrnlm'=>$user,'kdkmktrnlm'=>$vmk);
				$this->vkrs->deleteRecord ($data1);		   
				$this->vtrnlm_trnlp->deleteRecord ($data1);
				
				
				$where = "kdkmktbkmk='$vmk' and sksprtbkmk=1";
				$data2 = $this->vmtk->getData($where);
				$num_rows = $this->vmtk->numrows;
				
				if($num_rows>0){
					foreach($data2 as $row1){
						$tmp=$row1['kdprtk'];			   
					}           
					
					if(!empty($tmp)){		
						$data=array('thsmstrnlm'=> $thnsms,'nimhstrnlm'=>$user,'kdkmktrnlm'=>$tmp);
						$this->vkrs->deleteRecord ($data);
					}
				}
			}		 
			
			$this->msg_txt ="Kartu Rencana Studi (KRS) Berhasil Dihapus !!!";
			return 1;  
			
		}else{
			$this->msg_txt ="Anda tidak memilih matakuliah apapun !!!";
			return 0;       
		}

	}

	function gantiklskrs($user,$mk,$kls,$thnsms)
	{
		if(!empty($kls)){
			
			foreach($kls as $vmk=>$vkls)
			{
				$kelas=$vkls;
				
				
				$today = date("Y-m-d H:i:s");
				$data1=array('thsmstrnlm'=> $thnsms,'nimhstrnlm'=>$user,'kdkmktrnlm'=>$vmk,'shifttrnlm'=>$kelas,'tgl_input'=>$today);
				$this->vkrs->updateRecord ($data1);
				
				
				
				$where = "kdkmktbkmk='$vmk' and sksprtbkmk=1";
				$data2 = $this->vmtk->getData($where);
				
				$tmp="";	
				if(!empty($data2)){
					foreach($data2 as $row1){
						$tmp=$row1['kdprtk'];			   
					}           
					
					if(!empty($tmp)){	
						$data=array('thsmstrnlm'=> $thnsms,'nimhstrnlm'=>$user,'kdkmktrnlm'=>$tmp,'shifttrnlm'=>$kelas,'tgl_input'=>$today);
						$this->vkrs->updateRecord ($data);
						
						
						
					}
				}
			}
			
			
			
			$this->msg_txt ="Kelas Berhasil Dirubah !!!";
			return 1;  
			
		}else{
			$this->msg_txt ="Anda tidak memilih matakuliah apapun !!!";
			return 0;       
		}
	}

}


?>