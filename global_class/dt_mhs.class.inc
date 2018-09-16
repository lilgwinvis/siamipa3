<?php

require_once 'shared.php';


class dt_mhs 
{
	var $vmsmhs;
	var $numrows;

	function __construct(){
		$this->vmsmhs = new tb_gen('msmhs');
		
	}

	function isuserexist($user,$pass)
	{
		$where = "nimhsmsmhs='$user' AND pass=md5('$pass')";  	
		$this->getAllData($where);
		return  $this->numrows>0;	 
	}


	function getData($user)
	{	  
		
		if(!empty($user)){
			$where = "nimhsmsmhs='$user'"; 
		}else{ $where=""; }
		$data = $this->vmsmhs->getData($where); 
		
		$this->numrows=$this->vmsmhs->numrows;
		
		return $data;		 
		
	}

	function getAllData($where)
	{  
		$data = $this->vmsmhs->getData($where); 
		$this->numrows=$this->vmsmhs->numrows;      	 
		return $data;	  	  
	}
	
	
	function getAngkatan()
	{	  
		$this->vmsmhs->sql_select=" distinct tahunmsmhs ";
		$this->vmsmhs->sql_orderby=" tahunmsmhs ";
		$data = $this->vmsmhs->getData("");	 
		$this->numrows=$this->vmsmhs->numrows;      	 
		return $data;	  	  
	}

	function getkls($thn)
	{	  
		$this->vmsmhs->sql_select=" distinct shiftmsmhs ";
		$where = " tahunmsmhs='$thn' ";
		$this->vmsmhs->sql_orderby=" shiftmsmhs desc ";
		$data = $this->vmsmhs->getData($where);	 
		$this->numrows=$this->vmsmhs->numrows;      	 
		return $data;	  	  
	}	

	function getmhs($thn,$kls)
	{	  
		$this->vmsmhs->sql_select="*";
		$where = " tahunmsmhs='$thn' and shiftmsmhs='$kls'";	  
		$this->vmsmhs->sql_orderby=" nimhsmsmhs ";
		$data = $this->vmsmhs->getData($where); 
		
		$this->numrows=$this->vmsmhs->numrows;
		
		return $data;	  	  
	}
	
	
	function getnmmhs($nim)
	{	  
		
		$where = "nimhsmsmhs = '$nim'";
		$data = $this->getAllData($where);
		
		$nmmhs="";
		if(!empty($data))
		{
			foreach($data as $row){
				$nmmhs = $row['nmmhsmsmhs'];
			}
			
		}
		
		return $nmmhs;	  	  
	}	
	
	function getforlaplink($nim)
	{
		$where = "nimhsmsmhs = '$nim'";
		$data = $this->getAllData($where);
		
		$link="";
		if(!empty($data))
		{
			foreach($data as $row){
				$link = $row['link_forlap'];
			}
			
		}
		
		return $link;	  	  
		
		
	}
	
	function getshiftmhs($nim)
	{	
		$data = $this->getData($nim);		
		$kls='R';
		if(!empty($data))
		{
			foreach($data as $row){
				$kls = $row['shiftmsmhs'];
			}		  
		}
		return $kls;
	}
	
	function tambah($nim,$nama,$thnmsk,$tempat,$sem,$kelas,$kelamin,$datepicker,$agama,$alamat,$email,$penddk,$status,$tlp,$bp,$link)
	{
		
		$this->vmsmhs = new tb_gen('msmhs');
		$where = "nimhsmsmhs ='$nim'";
		$data = $this->vmsmhs->getData($where); 
		
		if(!empty($data))
		{
			return 0;
		}else{
			$nama = addslashes($nama);
			$tmp_data = array('kdpstmsmhs'=>'44201','nimhsmsmhs'=>strtoupper(trim($nim)),'nmmhsmsmhs'=>$nama,'tahunmsmhs'=>$thnmsk,'tplhrmsmhs'=>$tempat,'smawlmsmhs'=>$thnmsk.$sem,'shiftmsmhs'=>$kelas,'kdjekmsmhs'=>$kelamin,'pass'=>md5(strtoupper(trim($nim))),'agamamsmhs'=>$agama,'almmsmhs'=>$alamat,'emailmsmhs'=>$email,'smamsmhs'=>$penddk,'statmsmhs'=>$status,'tlpmsmhs'=>$tlp,'bpmsmhs'=>$bp,'link_forlap'=>$link);
			if(!empty($datepicker))
			{
				$tmp_data['tglhrmsmhs']=$datepicker;
			}			
			
			$this->vmsmhs->insertRecord($tmp_data);
			return 1;
		}
		
	}	
	function edit($nim,$nama,$thnmsk,$tempat,$sem,$kelas,$kelamin,$datepicker,$agama,$alamat,$email,$penddk,$status,$tlp,$bp,$link)
	{
		
		$this->vmsmhs = new tb_gen('msmhs');
		$nama = addslashes($nama); 
		
		$tmp_data =array('kdpstmsmhs'=>'44201','nimhsmsmhs'=>$nim,'nmmhsmsmhs'=>$nama,'tahunmsmhs'=>$thnmsk,'tplhrmsmhs'=>$tempat,'smawlmsmhs'=>$thnmsk.$sem,'shiftmsmhs'=>$kelas,'kdjekmsmhs'=>$kelamin,'agamamsmhs'=>$agama,'almmsmhs'=>$alamat,'emailmsmhs'=>$email,'smamsmhs'=>$penddk,'statmsmhs'=>$status,'tlpmsmhs'=>$tlp,'bpmsmhs'=>$bp,'link_forlap'=>$link);
		if(!empty($datepicker))
		{
			$tmp_data['tglhrmsmhs']=$datepicker;
		}	
		
		$this->vmsmhs->updateRecord($tmp_data);
		
		return 1;
		
	}
	
	function hapus($plh)
	{
		$this->vmsmhs = new tb_gen('msmhs');
		
		if(!empty($plh))
		{
			foreach($plh as $kode)
			{
				$this->vmsmhs->deleteRecord(array('nimhsmsmhs'=>$kode));
			}
		}	  
		
		return 1;
	}
	
}
?>