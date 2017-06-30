<?php
require_once 'shared.php';
include_once 'simple_html_dom.php';

class forlap_crawler {	
    
	var $tbdatamhs;
    var $tbdatakuliah;
    var $tbdatamtk;
	var $mhsfield;
	var $kd_sem;
	var $tbpenddsn;
	var $tbngajar;
	var $tbteliti;
	
	function __construct() {
		$this->tbdatamhs=array(0=>'judul',2=>'data');
	    $this->tbdatakuliah=array(1=>'thnsms',2=>'statmhs',3=>'sks');
	    $this->tbdatamtk=array(1=>'thnsms',2=>'kdmtk',3=>'nmmtk',4=>'sks');
		$this->mhsfield = array('Nama'=>'nmmhs','Jenis Kelamin'=>'pwmhs','Semester Awal'=>'semawal','Status Awal Mahasiswa'=>'bpmhs','Perguruan Tinggi Sebelumnya'=>'ptasal','Program Studi Sebelumnya'=>'pstasal','Status Mahasiswa Saat ini'=>'statmhs','Tanggal Lulus'=>'txttgllsmhs','Nomor Ijazah'=>'noijazah');
	    $this->kd_sem = array('Ganjil'=>1,'Genap'=>2);
		$this->tbpenddsn=array(1=>'pt',2=>'gelar',3=>'ijazah',4=>'jenjang');
		$this->tbngajar=array(1=>'sem',2=>'kd_mtk',3=>'nm',4=>'kd_kls',5=>'pt');
		$this->tbteliti=array(1=>'jdl',2=>'bid',3=>'lemb',4=>'thn');
	}
	
	function readpage($url)
    {
      $page = file_get_html($url);
      return $page; 
    }
	
	function readtable($page,$tbclass,$dbfieldname)
    {
	  $tmp_table=array();
	  $regexp = "<a\s[^>]*href=(\"??)([^\" >]*?)\\1[^>]*>(.*)<\/a>";
	  foreach($page->find('table[class="'.$tbclass.'"]') as $table)
		{ 	 
			
			foreach($table->find('tr') as $tr)
			{ 	
				$i=1; 		
				$row=array();
				$j=0;
				foreach($tr->find('td') as $td)
				{				  
				  if(isset($dbfieldname[$j])){
				   if(preg_match_all("/$regexp/siU", $td->innertext, $matches)) {
				     $row[$dbfieldname[$j]]=$matches[3][0];
					 $row['link']=$matches[2][0];					 
				    }else{
                     $row[$dbfieldname[$j]]=trim($td->innertext);				
					} 
				  }
				  $j++;
				}
				 if(!empty($row)){				
				  //$row['uptime']=$this->uptime;
				  $tmp_table[]=$row;
				 } 
				  $i++;
			}        		
		}
      return $tmp_table; 		
    }
	
	function readtableincontainer($page,$conclass,$tbclass,$dbfieldname)
	{
		$tmp_table=array();
		foreach($page->find('div[id="'.$conclass.'"]') as $tab)
		{
			$tmp_table=$this->readtable($tab,$tbclass,$dbfieldname);
		}	
		 return $tmp_table;
	}
	
	function readbiodatamhs($link)
	{
		$page = $this->readpage($link);
		$data=array();
		
		if($page){
		  $data['errkode']=0;
		  
		                        
								$isi_table=$this->readtable($page,"table1",$this->tbdatamhs);						
								$tmp_data=array();
								$jml=count($isi_table);
								for($i=0;$i<$jml;$i++)
								{
								  if(isset($isi_table[$i]['data'])){ 
									//if(isset($this->mhsfield[$isi_table[$i]['judul']])){
									 if($isi_table[$i]['judul']=='Semester Awal'){   
									   $tmp_data[$isi_table[$i]['judul']]=$isi_table[$i]['data'];						   
									   
									 }else{
										if($isi_table[$i]['judul']=='Nama')
										{
										  $nmmhs = preg_replace( '/[^[:print:]]/', '',$isi_table[$i]['data']);
										  $tmp_data[$isi_table[$i]['judul']]=addslashes($nmmhs);	 
										}
									   else{
										$tmp_data[$isi_table[$i]['judul']]=$isi_table[$i]['data'];	
									   }	
									 }
									 //$tmp_data['uptime']=$isi_table[$i]['uptime'];
									 //$tmp_data['kdpst']=$kd_prodi;
									 //$tmp_data['nimmhs']=$nim;
									 //$tmp_data['link']=$link;
									 //}
									 
								  } 
								}
		  
		  $data['biodatamhs']=$tmp_data;
		  
		}else{
               $data['errkode']=1; 
			   $data['errtxt']= "Gagal baca data dari situs forlap !!!";
             }
	
	   return $data;
	}
	function readrekapsksmhs($link)
	{
		$page = $this->readpage($link);
		$data=array();
		
		if($page){
		  $data['errkode']=0;
		  
		                        $isi_table=$this->readtableincontainer($page,"kuliahmhs","table table-bordered",$this->tbdatakuliah);
								
								$jml=count($isi_table);
								for($i=0;$i<$jml;$i++)
								{
								  //$isi_table[$i]['kdpst']=$kd_prodi;
								  //$isi_table[$i]['nimmhs']=$nim;
								  $isi_table[$i]['thnsms']=$isi_table[$i]['thnsms'];
								  $isi_table[$i]['sks'] = ($isi_table[$i]['sks']=='' ? 0 : $isi_table[$i]['sks']);
								}
		  
		  $data['rekapsksmhs']=$isi_table;
	     }else{
               $data['errkode']=1; 
			   $data['errtxt']= "Gagal baca data dari situs forlap !!!";
             }
	
	   return $data;
	}
	function readlstmtkmhs($link)
	{
		$page = $this->readpage($link);
		$data=array();
		
		if($page){
		  $data['errkode']=0;	      
		                        $isi_table=$this->readtableincontainer($page,"khsmhs","table table-bordered",$this->tbdatamtk);
							  
							    $jml=count($isi_table);
								for($i=0;$i<$jml;$i++)
								{
								  //$isi_table[$i]['kdpst']=$kd_prodi;
								  //$isi_table[$i]['nimmhs']=$nim;
								  $isi_table[$i]['thnsms']=$isi_table[$i]['thnsms'];
								  //$isi_table[$i]['sks'] = ($isi_table[$i]['sks']=='' ? 0 : $isi_table[$i]['sks']);
								}
		  
		  
		  
		  $data['lstmtkmhs']=$isi_table;
	     }else{
               $data['errkode']=1; 
			   $data['errtxt']= "Gagal baca data dari situs forlap !!!";
             }
	
	   return $data;
	}
	
	function readbiodatadsn($link)
	{
		$page = $this->readpage($link);
		$data=array();
		
		if($page){
		  $data['errkode']=0;
		  
		                        
								$isi_table=$this->readtable($page,"table1",$this->tbdatamhs);						
								$tmp_data=array();
								$jml=count($isi_table);
								for($i=0;$i<$jml;$i++)
								{
								  if(isset($isi_table[$i]['data'])){ 
									//if(isset($this->mhsfield[$isi_table[$i]['judul']])){
									 if($isi_table[$i]['judul']=='Semester Awal'){   
									   $tmp_data[$isi_table[$i]['judul']]=$isi_table[$i]['data'];						   
									   
									 }else{
										if($isi_table[$i]['judul']=='Nama')
										{
										  $nmmhs = preg_replace( '/[^[:print:]]/', '',$isi_table[$i]['data']);
										  $tmp_data[$isi_table[$i]['judul']]=addslashes($nmmhs);	 
										}
									   else{
										$tmp_data[$isi_table[$i]['judul']]=$isi_table[$i]['data'];	
									   }	
									 }
									 //$tmp_data['uptime']=$isi_table[$i]['uptime'];
									 //$tmp_data['kdpst']=$kd_prodi;
									 //$tmp_data['nimmhs']=$nim;
									 //$tmp_data['link']=$link;
									 //}
									 
								  } 
								}
		  
		  $data['biodatadsn']=$tmp_data;
		  
		}else{
               $data['errkode']=1; 
			   $data['errtxt']= "Gagal baca data dari situs forlap !!!";
             }
	
	   return $data;
	}
	
	function readrpendidikandsn($link)
	{
		$page = $this->readpage($link);
		$data=array();
		
		if($page){
		  $data['errkode']=0;	      
		                        $isi_table=$this->readtableincontainer($page,"riwayatpendidikan","table table-bordered",$this->tbpenddsn);
							  
							    $jml=count($isi_table);
								for($i=0;$i<$jml;$i++)
								{
								  //$isi_table[$i]['kdpst']=$kd_prodi;
								  //$isi_table[$i]['nimmhs']=$nim;
								  //$isi_table[$i]['thnsms']=$isi_table[$i]['thnsms'];
								  //$isi_table[$i]['sks'] = ($isi_table[$i]['sks']=='' ? 0 : $isi_table[$i]['sks']);
								}
		  
		  
		  
		  $data['penddsn']=$isi_table;
	     }else{
               $data['errkode']=1; 
			   $data['errtxt']= "Gagal baca data dari situs forlap !!!";
             }
	
	   return $data;
	}
	
	function readrmengajardsn($link)
	{
		$page = $this->readpage($link);
		$data=array();
		
		if($page){
		  $data['errkode']=0;	      
		                        $isi_table=$this->readtableincontainer($page,"riwayatmengajar","table table-bordered",$this->tbngajar);
							  
							    $jml=count($isi_table);
								for($i=0;$i<$jml;$i++)
								{
								  //$isi_table[$i]['kdpst']=$kd_prodi;
								  //$isi_table[$i]['nimmhs']=$nim;
								  //$isi_table[$i]['thnsms']=$isi_table[$i]['thnsms'];
								  //$isi_table[$i]['sks'] = ($isi_table[$i]['sks']=='' ? 0 : $isi_table[$i]['sks']);
								}
		  
		  
		  
		  $data['mengajardsn']=$isi_table;
	     }else{
               $data['errkode']=1; 
			   $data['errtxt']= "Gagal baca data dari situs forlap !!!";
             }
	
	   return $data;
	}
	function readrpenelitiandsn($link)
	{
		$page = $this->readpage($link);
		$data=array();
		
		if($page){
		  $data['errkode']=0;	      
		                        $isi_table=$this->readtableincontainer($page,"penelitian","table table-bordered",$this->tbteliti);
							  
							    $jml=count($isi_table);
								for($i=0;$i<$jml;$i++)
								{
								  //$isi_table[$i]['kdpst']=$kd_prodi;
								  //$isi_table[$i]['nimmhs']=$nim;
								  //$isi_table[$i]['thnsms']=$isi_table[$i]['thnsms'];
								  //$isi_table[$i]['sks'] = ($isi_table[$i]['sks']=='' ? 0 : $isi_table[$i]['sks']);
								}
		  
		  
		  
		  $data['menelitidsn']=$isi_table;
	     }else{
               $data['errkode']=1; 
			   $data['errtxt']= "Gagal baca data dari situs forlap !!!";
             }
	
	   return $data;
	}
}

?>