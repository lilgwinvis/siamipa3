<?php
require_once 'shared.php';

class dt_krs 
{
	var $vkrs_mhs;
	var $vkrs_mtk;
	var $vkrs_mtk1;
	var $vjml_sks;

	var $vkrs;
	var $vkrs_h;
	var $vmtk;
	var $vsyarat;
	var $vtrans;
	var $vmsmhs;
	var $dt_poll;
	var $jml_sks;
	var $msg_txt;

	function __construct()
	{
		
		$this->vkrs_mhs = new tb_gen('vw_krs_jn_mhs');
		$this->vkrs_mhs->sql_select  = 'distinct thsmskrs,nimhsmsmhs,nmmhsmsmhs,shiftmsmhs,tahunmsmhs,semkrs,kelaskrs';
		$this->vkrs_mhs->sql_groupby = 'thsmskrs,nimhsmsmhs,nmmhsmsmhs,shiftmsmhs,tahunmsmhs';
		$this->vkrs_mhs->sql_orderby = 'tahunmsmhs,nimhskrs';
		
		$this->vkrs_mtk = new tb_gen('vw_krs_jn_mtk');
		$this->vkrs_mtk->sql_select  = 'thsmskrs,nimhskrs,kdkmkkrs,nakmktbkmk,sksmktbkmk,sksprtbkmk,shiftkrs,semkrs,kelaskrs,semestbkmk,wp,tgl_input';
		$this->vkrs_mtk->sql_orderby = 'semestbkmk,kdkmkkrs'; 
		
		
		$this->vkrs_mtk1 = new tb_gen('vw_krs_jn_mtk');
		$this->vkrs_mtk1->sql_select= 'kdkmkkrs,nakmktbkmk,sksmktbkmk,sksprtbkmk,shiftkrs,semestbkmk,semkrs,kelaskrs,wp,count(nimhskrs) as jml';
		$this->vkrs_mtk1->sql_groupby= 'semestbkmk,kdkmkkrs,wp,nakmktbkmk,sksmktbkmk,sksprtbkmk,shiftkrs,semkrs,kelaskrs';
		$this->vkrs_mtk1->sql_orderby= 'semestbkmk,kdkmkkrs';
		
		$this->vjml_sks = new tb_gen('vw_krs_jn_mtk');
		$this->vjml_sks->sql_select= 'sum(sksmktbkmk) as jml_sks';
		$this->vjml_sks->sql_where= 'kdkmkkrs not like "%MATP%"';
		
		$this->vkrs = new tb_gen('krs');
		$this->vkrs_h = new tb_krs_h;
		$this->vmtk=new tb_gen('tbkmk');
		$this->vsyarat=new tb_gen('syarat');
		$this->vmsmhs=new tb_gen('msmhs');
		$this->vtrans=new dt_trans;
		$this->dt_poll = new dt_poll;
		
		
		
	}

	function getAllMhs(){     
		$where = "";
		$data = $this->vkrs_mhs->getData($where);
		return $data; 
	}




	function getAngkatan($kd,$shift,$kelaskrs,$semkrs){
		$where = "kdkmkkrs='$kd' and shiftkrs='$shift' and kelaskrs='$kelaskrs' and semkrs='$semkrs'";
		$data = $this->vkrs_mhs->getData($where);
		
		return $data; 
	}

	function getAllMtk(){
		
		$where = "";
		$data = $this->vkrs_mtk1->getData($where);
		return $data; 
	}

	function getMhs($thsmskrs,$nim){
		$where = "thsmskrs='$thsmskrs' and nimhsmsmhs='$nim'";
		
		$data = $this->vkrs_mhs->getData($where);
		return $data; 
	}  

	function getMhs1($kdkmkkrs,$shiftkrs,$kelaskrs,$semkrs){
		if(!empty($kelaskrs)){
			$where = "kdkmkkrs='$kdkmkkrs' and shiftkrs='$shiftkrs' and semkrs='$semkrs' and kelaskrs='$kelaskrs'";
		}else{
			$where = "kdkmkkrs='$kdkmkkrs' and shiftkrs='$shiftkrs' and semkrs='$semkrs'";
		}
		$data = $this->vkrs_mhs->getData($where);
		return $data; 
	}  

	function getMtk($thsmskrs,$nim,$noprtk=1){
		
		if($noprtk==0){	
			$where = "thsmskrs='$thsmskrs' and nimhskrs='$nim' and kdkmkkrs NOT LIKE 'MATP%'";
		}else{
			$where = "thsmskrs='$thsmskrs' and nimhskrs='$nim'";
		}	 
		$data = $this->vkrs_mtk->getData($where);
		return $data; 
	}

	
	function getjmlsks($thsmskrs,$nim)
	{
		$data=$this->getMtk($thsmskrs,$nim,0);
		
		$jmlsks=array();
		if(!empty($data))
		{
			foreach($data as $row)
			{
								
				if(!isset($jmlsks['mtk']))
				{
				  if(!in_array($row['kdkmkkrs'],array('MAT352','MAT353','UBB106'))){
					$jmlsks['mtk']=$row['sksmktbkmk'];
					$jmlsks['prtk']=$row['sksprtbkmk'];
				  }else{
					$jmlsks['mtk']=0;
					$jmlsks['prtk']=0;
					
					 $jmlsks['skripsi']=(($row['kdkmkkrs']=='MAT352') or ($row['kdkmkkrs']=='MAT353')) ? 1:0; 
					 $jmlsks['kkn']= ($row['kdkmkkrs']=='UBB106')  ? 1:0;
					
				  }
					
				}else{
				  if(!in_array($row['kdkmkkrs'],array('MAT352','MAT353','UBB106'))){	
					$jmlsks['mtk']+=$row['sksmktbkmk'];
					$jmlsks['prtk']+=$row['sksprtbkmk'];
				  }
				}
			}
		}
		
		return $jmlsks;
	}
	
	
	function getMtk1($kdkmkkrs,$shiftkrs,$kelaskrs,$semkrs){
		
		$where = "kdkmkkrs='$kdkmkkrs' and shiftkrs='$shiftkrs' and semkrs='$semkrs' and kelaskrs='$kelaskrs'";
		
		$data = $this->vkrs_mtk->getData($where);
		return $data; 
	}

	function getData($where)
	{
		$data = $this->vkrs->getData($where);
		return $data;  
	}

	function gantikls($nim,$kdmtk)
	{
		
		if(!empty($nim)){
			$thnsms = $this->TA();
			foreach($nim as $vnim){         	  
				$where="kdkmkkrs='$kdmtk' and nimhskrs='$vnim'";
				$data=$this->getData($where);
				if(!empty($data)){
					foreach($data as $row){
						
						if($row['shiftkrs']=='R'){					 
							$tmp='N';
						}else{
							$tmp='R';
						}

						$today = date("Y-m-d H:i:s");
						
						$data=array('nimhskrs'=>$vnim,'kdkmkkrs'=>$kdmtk,'shiftkrs'=>$tmp,'tgl_input'=>$today);
						$this->vkrs->updateRecord ($data);
						
						if(!in_array($kdmtk,array('UBB106','MAT352','MAT353')))
						{ 
							$this->dt_poll->gantikelasMpoll($thnsms,$kdmtk,$vnim,$tmp);
						}
						
						$this->msg_txt='Berhasil ubah kelas !!!';
						
					}
				}
			}
		}else{
			
			$this->msg_txt='Gagal ubah kelas, data nim tidak dikirim !!!';
		}
	}

	function gantiklsmhs($klsmhs,$kdmtk)
	{ 
		if(!empty($klsmhs)){
			$thnsms = $this->TA();
			foreach($klsmhs as $field=>$value){
				
				$today = date("Y-m-d H:i:s");			 
				$data=array('nimhskrs'=>$field,'kdkmkkrs'=>$kdmtk,'kelaskrs'=>$value,'tgl_input'=>$today);
				$this->vkrs->updateRecord($data);	

				if(!in_array($kdmtk,array('UBB106','MAT352','MAT353')))
				{ 			 
					$this->dt_poll->gantikelasmhsMpoll($thnsms,$kdmtk,$field,$value);
				}	
			}
			$this->msg_txt='Berhasil ubah kelas mhs !!!';
		}
		else{
			
			$this->msg_txt='Gagal ubah kelas mhs, data nim tidak dikirim !!!';
		}
	}

	function gantisemmhs($semmhs,$kdmtk)
	{ 
		if(!empty($semmhs)){
			$thnsms = $this->TA();
			foreach($semmhs as $field=>$value){ 
				
				$today = date("Y-m-d H:i:s");			 
				$data=array('nimhskrs'=>$field,'kdkmkkrs'=>$kdmtk,'semkrs'=>$value,'tgl_input'=>$today);
				$this->vkrs->updateRecord($data);
				
				if(!in_array($kdmtk,array('UBB106','MAT352','MAT353')))
				{ 
					$this->dt_poll->gantisemmhsMpoll($thnsms,$kdmtk,$field,$value);
				}
				//$klskrs="";
				//$kelas="";
				//$thnsms = $this->TA();
				//$search= "thsmskrs='$thnsms' and nimhskrs='$field' and kdkmkkrs='$kdmtk'";
				//$search_data = $this->vkrs->getData($search);
				
				//if(!empty($search_data))
				//{
				//foreach($search_data as $row)
				//{
				//$klskrs=$row['kelaskrs'];
				//$kelas=$row['shiftkrs'];
				//}
				
				//}		 
				
				
				
				//$data_h=array('thsmskrs_h'=> $thnsms,'nimhskrs_h'=>$field,'kdkmkkrs_h'=>$kdmtk,'shiftkrs_h'=>$kelas,'kelaskrs_h'=>$klskrs,'tgl_input'=>$today,'semkrs_h'=>$value,'rec_stat'=>2);
				//$this->vkrs_h->insertRecord ($data_h);
				
				
			}
			$this->msg_txt='Berhasil ubah semester mhs !!!';
		}
		else{
			
			$this->msg_txt='Gagal ubah semester mhs, data nim tidak dikirim !!!';
		}
	}

	function TA()
	{
		$tmp=new mythnsem;
		$semester = $tmp->getthnsem();
		return $semester;
	}

	function hitsks($user)
	{
		$where = "nimhskrs = '$user'";
		
		$data = $this->vjml_sks->getData($where);
		if(!empty($data)){
			foreach($data as $row){
				return $row['jml_sks'];
			}
		} else {
			return 0;
		}
		
	}

	function buildkrs($user,$baru=1)
	{
		$this->jml_sks=0;
		$thnsms = $this->TA();
		$sem = str_split($thnsms, 4);
		
		//if($sem[1]=="1"){
		//  $where = "kdkmktbkmk NOT LIKE 'MATP%' and semestbkmk in ('01','03','05','07','08')"; 
		// }else{
		//   if($sem[1]=="2"){  
		//	  $where = "kdkmktbkmk NOT LIKE 'MATP%' and semestbkmk in ('02','04','06','08')";
		//	}
		// }
		if($baru==1){  
			$where = "kdkmktbkmk NOT LIKE 'MATP%' and (kdkmktbkmk not in (select kdkmkkrs from krs where nimhskrs='$user') ) and (kdkmktbkmk not in (select distinct kdkmktrnlm from trnlm_trnlp where nimhstrnlm='$user') )";
			
		}else
		{
			$where = "kdkmktbkmk NOT LIKE 'MATP%' and (kdkmktbkmk not in (select kdkmkkrs from krs where nimhskrs='$user') ) and (kdkmktbkmk in (select distinct kdkmktrnlm from trnlm_trnlp where nimhstrnlm='$user') ) ";
			
		}

		$data3 = array();
		$data = $this->vmtk->getData($where);
		$dt = $this->vtrans->hitipk($user);
		$sks = $this->vtrans->sks_mbl;
		
		if(!empty($data)){ 
			foreach ($data as $row) {
				$ctk=0;
				$tmp = $row['kdkmktbkmk'];
				
				$where = "kdkmksyarat='$tmp'"; 
				$data1 = $this->vsyarat->getData($where);
				$num_rows=$this->vsyarat->numrows;
				
				if($tmp=="UBB106" or $tmp=="MAT352" or $tmp=="MAT353" or $tmp=="MAT370"){
					
					if($sks>=110){				 
						
						$ctk=1;
						
					}else{
						$ctk=0;
					}
					
				}		 
				else{
					
					if($num_rows==0){
						$ctk=1;
					}else{	
						
						$where = "kdkmksyarat='$tmp' and (syaratkmk in (select distinct kdkmktrnlm from trnlm_trnlp where nimhstrnlm='$user' ))"; 
						$data2 = $this->vsyarat->getData($where);
						$num_rows1=$this->vsyarat->numrows;
						if($num_rows1==0){
							$ctk=0;
						}
						else{					     
							$ctk=1;						 
						}
						if($baru==0)
						{
							$ctk=1;
						}				   
						
					}
					
				}
				
				if($ctk==1){
					
					$where="nimhskrs='$user' and thsmskrs='$thnsms' and kdkmkkrs='$tmp'";
					
					$data4=$this->getData($where);
					$num_rows2=$this->vkrs->numrows;			
					
					if($num_rows2>0){
						$tmp2= "1";
						$this->jml_sks+=$row['sksmktbkmk'];
					}else
					{
						$tmp2= "0";
					}
					
					$data3[]= array('kdkmktbkmk' => $row['kdkmktbkmk'],
					'nakmktbkmk' => $row['nakmktbkmk'],
					'sksmktbkmk' => $row['sksmktbkmk'],
					'semestbkmk' => $row['semestbkmk'],
					'wp' => $row['wp'],
					'cek' => $tmp2);	
				}
				
			}
		}
		
		
		return $data3;
	}

	function simpankrs($user,$mk,$jml_sks,$kls)
	{
		
		
		
		$dt = $this->vtrans->hitipk_krs($user);
		$ipk=0;
		if($this->vtrans->sks_mbl_krs>0){ 
			$ipk = round($this->vtrans->sks_nm_krs/$this->vtrans->sks_mbl_krs,2);
		}	 
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
		
		
		$thnsms = $this->TA();
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
		
		$where = "nimhskrs='$user' and thsmskrs='$thnsms' and kdkmkkrs NOT LIKE 'MATP%'";
		
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
					$data1=array('thsmskrs'=> $thnsms,'nimhskrs'=>$user,'kdkmkkrs'=>$vmk,'shiftkrs'=>$kelas,'tgl_input'=>$today,'semkrs'=>$kls_mhs_txt);
					$this->vkrs->insertRecord ($data1);
					
					if(!in_array($vmk,array('UBB106','MAT352','MAT353')))
					{
						$this->dt_poll->insertDataMpoll($thnsms,$user,$kls_mhs_txt,$kelas,'01',$vmk);
					}
					
					//$data_h=array('thsmskrs_h'=> $thnsms,'nimhskrs_h'=>$user,'kdkmkkrs_h'=>$vmk,'shiftkrs_h'=>$kelas,'tgl_input'=>$today,'semkrs_h'=>$kls_mhs_txt,'rec_stat'=>1);
					//$this->vkrs_h->insertRecord ($data_h);
					
					
					$where = "kdkmktbkmk='$vmk' and sksprtbkmk=1";
					$data2 = $this->vmtk->getData($where);
					$num_rows = $this->vmtk->numrows;
					
					if($num_rows>0){
						foreach($data2 as $row1){
							$tmp=$row1['kdprtk'];			   
						}           
						
						if(!empty($tmp)){	
							
							$isinput=(($thnmsmhs<2016) or (($thnmsmhs>=2016) and ($kelas=='R')));							
							
							if($isinput){	
							  $data=array('thsmskrs'=> $thnsms,'nimhskrs'=>$user,'kdkmkkrs'=>$tmp,'shiftkrs'=>$kelas,'tgl_input'=>$today,'semkrs'=>$kls_mhs_txt);
							  $this->vkrs->insertRecord ($data);
							
							  $this->dt_poll->insertDataMpoll($thnsms,$user,$kls_mhs_txt,$kelas,'01',$tmp);
							}
							//$data_h=array('thsmskrs_h'=> $thnsms,'nimhskrs_h'=>$user,'kdkmkkrs_h'=>$tmp,'shiftkrs_h'=>$kelas,'tgl_input'=>$today,'semkrs_h'=>$kls_mhs_txt,'rec_stat'=>1);
							//$this->vkrs_h->insertRecord ($data_h);
							
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

	function hapuskrs($user,$mk)
	{
		if(!empty($mk)){
			
			foreach($mk as $vmk){
				$thnsms = $this->TA();
				$today = date("Y-m-d H:i:s");
				
				
				$kls_mhs_txt="";
				$kelas="";
				$search= "thsmskrs='$thnsms' and nimhskrs='$user' and kdkmkkrs='$vmk'";
				$search_data = $this->vkrs->getData($search);
				
				if(!empty($search_data))
				{
					foreach($search_data as $row)
					{
						$kls_mhs_txt=$row['semkrs'];
						$kelas=$row['shiftkrs'];
					}
					
				}
				
				
				
				//$data_h=array('thsmskrs_h'=> $thnsms,'nimhskrs_h'=>$user,'kdkmkkrs_h'=>$vmk,'shiftkrs_h'=>$kelas,'tgl_input'=>$today,'semkrs_h'=>$kls_mhs_txt,'rec_stat'=>3);
				//$this->vkrs_h->insertRecord ($data_h);
				
				$data1=array('thsmskrs'=> $thnsms,'nimhskrs'=>$user,'kdkmkkrs'=>$vmk);
				$this->vkrs->deleteRecord ($data1);		   
				
				$this->dt_poll->deleteDataMpoll($thnsms,$vmk,$user);
				
				$where = "kdkmktbkmk='$vmk' and sksprtbkmk=1";
				$data2 = $this->vmtk->getData($where);
				$num_rows = $this->vmtk->numrows;
				
				if($num_rows>0){
					foreach($data2 as $row1){
						$tmp=$row1['kdprtk'];			   
					}           
					
					if(!empty($tmp)){	
						
						//$data_h=array('thsmskrs_h'=> $thnsms,'nimhskrs_h'=>$user,'kdkmkkrs_h'=>$tmp,'shiftkrs_h'=>$kelas,'tgl_input'=>$today,'semkrs_h'=>$kls_mhs_txt,'rec_stat'=>3);
						//$this->vkrs_h->insertRecord ($data_h);
						
						$data=array('thsmskrs'=> $thnsms,'nimhskrs'=>$user,'kdkmkkrs'=>$tmp);
						$this->vkrs->deleteRecord ($data);
						$this->dt_poll->deleteDataMpoll($thnsms,$tmp,$user);
						
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

	function gantiklskrs($user,$mk,$kls)
	{
		if(!empty($kls)){
			$thnsms = $this->TA();
			foreach($kls as $vmk=>$vkls)
			{
				$kelas=$vkls;
				
				
				$today = date("Y-m-d H:i:s");
				$data1=array('thsmskrs'=> $thnsms,'nimhskrs'=>$user,'kdkmkkrs'=>$vmk,'shiftkrs'=>$kelas,'tgl_input'=>$today);
				$this->vkrs->updateRecord ($data1);
				
				if(!in_array($vmk,array('UBB106','MAT352','MAT353')))
				{
					$this->dt_poll->gantikelasMpoll($thnsms,$vmk,$user,$kelas);
				}
				
				$kls_mhs_txt="";		     
				$search= "thsmskrs='$thnsms' and nimhskrs='$user' and kdkmkkrs='$vmk' and shiftkrs='$kelas'";
				$search_data = $this->vkrs->getData($search);
				
				if(!empty($search_data))
				{
					foreach($search_data as $row)
					{
						$kls_mhs_txt=$row['semkrs'];			 
					}
					
				}
				
				
				//$data_h=array('thsmskrs_h'=> $thnsms,'nimhskrs_h'=>$user,'kdkmkkrs_h'=>$vmk,'shiftkrs_h'=>$kelas,'tgl_input'=>$today,'semkrs_h'=>$kls_mhs_txt,'rec_stat'=>2);
				//$this->vkrs_h->insertRecord ($data_h);	 
				
				$where = "kdkmktbkmk='$vmk' and sksprtbkmk=1";
				$data2 = $this->vmtk->getData($where);
				
				$tmp="";	
				if(!empty($data2)){
					foreach($data2 as $row1){
						$tmp=$row1['kdprtk'];			   
					}           
					
					if(!empty($tmp)){	
						$data=array('thsmskrs'=> $thnsms,'nimhskrs'=>$user,'kdkmkkrs'=>$tmp,'shiftkrs'=>$kelas,'tgl_input'=>$today);
						$this->vkrs->updateRecord ($data);
						
						$this->dt_poll->gantikelasMpoll($thnsms,$tmp,$user,$kelas);
						
						//$data_h=array('thsmskrs_h'=> $thnsms,'nimhskrs_h'=>$user,'kdkmkkrs_h'=>$tmp,'shiftkrs_h'=>$kelas,'tgl_input'=>$today,'semkrs_h'=>$kls_mhs_txt,'rec_stat'=>2);
						//$this->vkrs_h->insertRecord ($data_h);
						
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
	function delAllRecord($where)
	{
		$this->vkrs->deleteAllRecord($where);
		return 0;
	}

	function export_record($tb,$field,$field1,$where)
	{
		$this->vkrs->export_record($tb,$field,$field1,$where);
		return 0;
	}

	function getDataMhs($where)
	{
		$this->vkrs->sql_from  = "krs INNER JOIN msmhs ON nimhskrs=nimhsmsmhs";
		
		$this->vkrs->sql_select ='tahunmsmhs,nimhsmsmhs,nmmhsmsmhs';
		
		$this->vkrs->sql_groupby='tahunmsmhs,nimhsmsmhs'; 
		//$this->vkrs->sql_orderby='';
		$data = $this->vkrs->getData($where);
		return $data;  
	}

	function getDataMtk($where)
	{
		$this->vkrs->sql_from  = "krs INNER JOIN tbkmk ON kdkmkkrs=kdkmktbkmk";
		
		$this->vkrs->sql_select ='semestbkmk,kdkmkkrs,nakmktbkmk,COUNT(nimhskrs) AS jml';
		
		$this->vkrs->sql_groupby='kdkmkkrs';
		$this->vkrs->sql_orderby='semestbkmk,kdkmkkrs';	 
		$this->vkrs->sql_having='jml>1';
		$data = $this->vkrs->getData($where);
		return $data;  
	}
}


?>