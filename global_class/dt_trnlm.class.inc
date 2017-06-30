<?php
require_once 'shared.php';

class dt_trnlm 
{
	var $vtrnlm; 
	var $vtrnlm_trnlp;   
	var $vmtk;
	var $vtrans;
	var $vsyarat;
	var $vkrs;

	function __construct(){
		$this->vtrnlm = new tb_gen('trnlm');
		$this->vtrnlm_trnlp = new tb_gen('trnlm_trnlp');
	}

	function getData($where)
	{
		$data = $this->vtrnlm->getData($where);
		return $data;  
	}

	function gantikls($kls,$thnsms,$kdkmk,$kelas)
	{
		
		if(!empty($kls)){
			foreach($kls as $vnim){
								 
				$tmp=($kelas=='R') ? 'N' : 'R';				
				$today = date("Y-m-d H:i:s");
				
				$data=array('nimhstrnlm'=>$vnim,'thsmstrnlm'=>$thnsms,'kdkmktrnlm'=>$kdkmk,'shifttrnlm'=>$tmp,'tgl_input'=>$today);
				$this->vtrnlm->updateRecord ($data);				
			}
			$this->msg_txt='Berhasil ubah kelas !!!';
		}else{
			
			$this->msg_txt='Gagal ubah kelas, data nim tidak dikirim !!!';
		}
	}

	function gantiriwayatkls($nim,$kdmtk,$thsmstrnlm)
	{
		
		if(!empty($nim)){
			foreach($nim as $vnim){         	  
				$where="kdkmktrnlm='$kdmtk' and nimhstrnlm='$vnim' and thsmstrnlm='$thsmstrnlm'";
				$data=$this->vtrnlm->getData($where);
				if(!empty($data)){
					foreach($data as $row){						
										 
						$tmp=($row['shifttrnlm']=='R') ? 'N' : 'R';						
						$today = date("Y-m-d H:i:s");
						
						$data=array('nimhstrnlm'=>$vnim,'kdkmktrnlm'=>$kdmtk,'shifttrnlm'=>$tmp,'tgl_input'=>$today);
						$this->vtrnlm->updateRecord ($data);
						
						$this->msg_txt='Berhasil ubah kelas !!!';
						
					}
				}
			}
		}else{
			
			$this->msg_txt='Gagal ubah kelas, data nim tidak dikirim !!!';
		}
	}

	function gantiriwayatklsmhs($klsmhs,$kdmtk,$thsmstrnlm)
	{ 
		if(!empty($klsmhs)){
			foreach($klsmhs as $field=>$value){
				
				$today = date("Y-m-d H:i:s");			 
				$data=array('nimhstrnlm'=>$field,'kdkmktrnlm'=>$kdmtk,'kelastrnlm'=>$value,'tgl_input'=>$today,'thsmstrnlm'=>$thsmstrnlm);
				$this->vtrnlm->updateRecord($data);
				
				$data=array('nimhstrnlm'=>$field,'kdkmktrnlm'=>$kdmtk,'kelastrnlm'=>$value,'thsmstrnlm'=>$thsmstrnlm);
				$this->vtrnlm_trnlp->updateRecord($data);
				
			}
			$this->msg_txt='Berhasil ubah kelas mhs !!!';
		}
		else{
			
			$this->msg_txt='Gagal ubah kelas mhs, data nim tidak dikirim !!!';
		}
	}

	function gantiriwayatsemmhs($semmhs,$kdmtk,$thsmstrnlm)
	{ 
		if(!empty($semmhs)){
			foreach($semmhs as $field=>$value){
				
				$today = date("Y-m-d H:i:s");			 
				$data=array('nimhstrnlm'=>$field,'kdkmktrnlm'=>$kdmtk,'semestrnlm'=>$value,'tgl_input'=>$today,'thsmstrnlm'=>$thsmstrnlm);
				$this->vtrnlm->updateRecord($data);
				
			}
			$this->msg_txt='Berhasil ubah semester mhs !!!';
		}
		else{
			
			$this->msg_txt='Gagal ubah semester mhs, data nim tidak dikirim !!!';
		}
	}

	function updatenilai($nilai,$thnsms,$kdkmk)
	{
		$bbt = array('A'=>4.00,'B'=>3.00,'C'=>2.00,'D'=>1.00,'E'=>0.00,'T'=>0.00,'K'=>0.00,'S'=>0.00);
		if(!empty($nilai)){	   
			foreach($nilai as $vnim=>$vhm){        	       		

				$today = date("Y-m-d H:i:s");
				
				$data=array('nimhstrnlm'=>$vnim,'thsmstrnlm'=>$thnsms,'kdkmktrnlm'=>$kdkmk,'nlakhtrnlm'=>$vhm,'bobottrnlm'=>$bbt[$vhm],'tgl_input'=>$today);
				$this->vtrnlm->updateRecord ($data);		        
			}
			$this->msg_txt='Berhasil update nilai !!!';
		}else{	   
			$this->msg_txt='Gagal update nilai, data nilai tidak dikirim !!!';
		}



	}

	
	function getjmlskspersem($nim)
	{
		$this->vkrs_mtk = new tb_gen('trnlm_jn_mtk');
		$this->vkrs_mtk->sql_select  = 'thsmstrnlm,nimhstrnlm,kdkmktrnlm,sksmktbkmk,sksprtbkmk';
		$this->vkrs_mtk->sql_orderby = 'thsmstrnlm';
		
		$where = "nimhstrnlm='$nim' and skstmtbkmk>0";
		$data = $this->vkrs_mtk->getData($where);
		
		
		$skspersem=array();
		if(!empty($data))
		{
			foreach($data as $row)
			{
				
				if(!isset($skspersem[$row['thsmstrnlm']])){
				  if(!in_array($row['kdkmktrnlm'],array('MAT352','MAT353','UBB106'))){	
				   $skspersem[$row['thsmstrnlm']]['sksmtk']=$row['sksmktbkmk'];
				   $skspersem[$row['thsmstrnlm']]['sksprtk']=$row['sksprtbkmk'];
				  }else{
					 $skspersem[$row['thsmstrnlm']]['sksmtk']=0;
				     $skspersem[$row['thsmstrnlm']]['sksprtk']=0;
					 
					 $skspersem['skripsi']=(($row['kdkmktrnlm']=='MAT352') or ($row['kdkmktrnlm']=='MAT353')) ? 1:0; 
					 $skspersem['kkn']= ($row['kdkmktrnlm']=='UBB106')  ? 1:0;						 
				  } 
				}else{
				  if(!in_array($row['kdkmktrnlm'],array('MAT352','MAT353','UBB106'))){ 
				   $skspersem[$row['thsmstrnlm']]['sksmtk']+=$row['sksmktbkmk'];
				   $skspersem[$row['thsmstrnlm']]['sksprtk']+= $row['sksprtbkmk'];
				  } 
				 }
			}
		}
		
		return $skspersem;
	}
	
	
	function getmtk($kdkmktrnlm,$shifttrnlm,$kelastrnlm,$semestrnlm,$thsmstrnlm)
	{	
		$this->vkrs_mtk = new tb_gen('trnlm_jn_mtk');
		$this->vkrs_mtk->sql_select  = 'thsmstrnlm,nimhstrnlm,kdkmktrnlm,nakmktbkmk,sksmktbkmk,sksprtbkmk,shifttrnlm,semestrnlm,kelastrnlm,semestbkmk,wp,tgl_input';
		$this->vkrs_mtk->sql_orderby = 'semestbkmk,kdkmktrnlm';
		
		$where = "kdkmktrnlm='$kdkmktrnlm' and shifttrnlm='$shifttrnlm' and semestrnlm='$semestrnlm' and kelastrnlm='$kelastrnlm' and thsmstrnlm='$thsmstrnlm'";
		$data = $this->vkrs_mtk->getData($where);
		return $data;     
	}
	
	function getmtk1($thnsms,$nim)
	{	
		$this->vkrs_mtk = new tb_gen('trnlm_jn_mtk');
		$this->vkrs_mtk->sql_select  = 'thsmstrnlm,nimhstrnlm,kdkmktrnlm,nakmktbkmk,sksmktbkmk,sksprtbkmk,shifttrnlm,semestrnlm,kelastrnlm,semestbkmk,wp,tgl_input';
		$this->vkrs_mtk->sql_orderby = 'semestbkmk,kdkmktrnlm';
		
		$where = "thsmstrnlm='$thnsms' and nimhstrnlm='$nim'";
		$data = $this->vkrs_mtk->getData($where);
		return $data;     
	}
	
	function getMtk2($thsmskrs,$nim,$noprtk=1){
		
		
		$this->vkrs_mtk = new tb_gen('trnlm_jn_mtk');
		$this->vkrs_mtk->sql_select  = 'thsmstrnlm,nimhstrnlm,kdkmktrnlm,nakmktbkmk,sksmktbkmk,sksprtbkmk,shifttrnlm,semestrnlm,kelastrnlm,semestbkmk,wp,tgl_input';
		$this->vkrs_mtk->sql_orderby = 'semestbkmk,kdkmktrnlm';
		
		if($noprtk==0){	
			$where = "thsmstrnlm='$thsmskrs' and nimhstrnlm='$nim' and kdkmktrnlm NOT LIKE 'MATP%'";
		}else{
			$where = "thsmstrnlm='$thsmskrs' and nimhstrnlm='$nim'";
		}	 
		$data = $this->vkrs_mtk->getData($where);
		return $data; 
	} 

	
	
	function buildkrs($user,$thnsms,$baru=1)
	{
		$this->jml_sks=0;
		
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
		
		
		
		if($baru==1){  
			$where = "kdkmktbkmk NOT LIKE 'MATP%' and (kdkmktbkmk not in (select kdkmktrnlm from trnlm where nimhstrnlm='$user' and thsmstrnlm=$thnsms ) ) and (kdkmktbkmk not in (select distinct kdkmktrnlm from trnlm_trnlp where nimhstrnlm='$user' and thsmstrnlm in ($txt_filter1)) )";
			
		}else
		{
			$where = "kdkmktbkmk NOT LIKE 'MATP%' and (kdkmktbkmk not in (select kdkmktrnlm from trnlm where nimhstrnlm='$user' and thsmstrnlm=$thnsms) ) and (kdkmktbkmk in (select distinct kdkmktrnlm from trnlm_trnlp where nimhstrnlm='$user' and thsmstrnlm in ($txt_filter1))) ";
			
		}
		$this->vsyarat=new tb_gen('syarat');
		$this->vkrs = new tb_gen('krs');
		$data3 = array();
		$this->vmtk=new tb_gen('tbkmk');
		$data = $this->vmtk->getData($where);
		$this->vtrans=new dt_trans;
		$dt = $this->vtrans->hitipk($user,$txt_filter1);
		$sks = $this->vtrans->sks_mbl;
		
		if(!empty($data)){ 
			foreach ($data as $row) {
				$ctk=0;
				$tmp = $row['kdkmktbkmk'];
				
				$where = "kdkmksyarat='$tmp'"; 
				$data1 = $this->vsyarat->getData($where);
				$num_rows=$this->vsyarat->numrows;
				
				if(in_array($tmp,array("UBB106","MAT352","MAT353","MAT370"))){					
						$ctk=($sks>=110) ? 1 : 0;					
				}		 
				else{
					
					if($num_rows==0){
						$ctk=1;
					}else{	
						
						$where = "kdkmksyarat='$tmp' and (syaratkmk in (select distinct kdkmktrnlm from trnlm_trnlp where nimhstrnlm='$user' and thsmstrnlm in ($txt_filter1)))"; 
						$data2 = $this->vsyarat->getData($where);
						$num_rows1=$this->vsyarat->numrows;
						
						$ctk=($num_rows1==0) ? 0:1;						
						$ctk=($baru==0)? 1:$ctk;
					}
					
				}
				
				if($ctk==1){
					
					$where="nimhstrnlm='$user' and thsmstrnlm='$thnsms' and kdkmktrnlm='$tmp'";
					
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
	
	function getmhs($kdkmktrnlm,$shifttrnlm,$kelastrnlm,$semestrnlm,$thsmstrnlm){
		
		$this->vkrs_mhs = new tb_gen('trnlm_jn_msmhs');
		$this->vkrs_mhs->sql_select  = 'distinct thsmstrnlm,nimhsmsmhs,nmmhsmsmhs,shiftmsmhs,tahunmsmhs,semestrnlm,kelastrnlm';
		$this->vkrs_mhs->sql_groupby = 'thsmstrnlm,nimhsmsmhs,nmmhsmsmhs,shiftmsmhs,tahunmsmhs';
		$this->vkrs_mhs->sql_orderby = 'tahunmsmhs,nimhstrnlm';
		
		if(!empty($kelastrnlm)){
			$where = "kdkmktrnlm='$kdkmktrnlm' and shifttrnlm='$shifttrnlm' and semestrnlm='$semestrnlm' and kelastrnlm='$kelastrnlm' and thsmstrnlm='$thsmstrnlm'";
		}else{
			$where = "kdkmktrnlm='$kdkmktrnlm' and shifttrnlm='$shifttrnlm' and semestrnlm='$semestrnlm'  and thsmstrnlm='$thsmstrnlm'";
		}
		$data = $this->vkrs_mhs->getData($where);
		return $data; 
	}

	function getriwayatsks($thn,$nim)
	{
		$tb = new tb_gen('trnlm_jn_mtk');
		$tb->sql_select = "sum(sksmktbkmk) as jml";
		$where = "thsmstrnlm='$thn' and nimhstrnlm='$nim' and kdkmktrnlm not like 'MATP%'";
		$data = $tb->getData($where);
		
		$jml_sks=0;
		if(!empty($data))
		{
			foreach($data as $row)
			{
				$jml_sks=$row['jml'];
			}
			
		}
		
		return $jml_sks;
	}

}

?>