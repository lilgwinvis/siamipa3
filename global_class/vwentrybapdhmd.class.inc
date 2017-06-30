<?php
require_once 'shared.php';

class vwentrybapdhmd
{
	function __construct()
	{
	  	  
	}
	
	function sem_filter($thnsms=0)
	{
	  $mythnsem = new mythnsem;	  
	  $dtsem = $mythnsem->getlstthnsem();	  
	  krsort($dtsem);
	  $vtemp = $dtsem[key($dtsem)];
	  $thnsms = $thnsms==0 ? key($dtsem) : $thnsms; 
	  
	  $frm = new HTML_Form();
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmfilter"));
	  $tbl->addRow();
      $tbl->addCell('Semester'.$frm->addSelectList("semester",$dtsem,true,null,null,array('id'=>'semester')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')), null, 'data');
	  
	  $txt="<fieldset>";
	  $txt.="<legend>Filter</legend>";
	  $txt.=$tbl->display();
	  $txt.="</fieldset>";
	  
	  $txt.="<fieldset>";
      $txt.="<legend id='hsl_filter'>Daftar Matakuliah : $vtemp </legend>";
      $txt.="<div id='data'>";	
	  $txt.=$this->listmtkdsn($thnsms);
	  $txt.="</div>";  
	  $txt.="</fieldset>";  
	  
	   
	  return $txt;   
	}
	
	private function ismrhitl($iswp,$data)
	{
	   if($iswp=='p'){
	      return "<font color='red'><i>".$data."</i></font>";
	   }else{
	      return "$data";
	   }
	}
	function listmtkdsn($thn)
	{
	 	$arr_rn = array('R'=>'Reguler','N'=>'Non Reguler');
		$tbstat = array("id" => "lstmtkdsn");	
		$header = array(array('Semester','Kode','Matakuliah','SKS','Reg/Non Reg','Angkatan','Sem. Mhs.','Kelas','Jumlah Pertemuan','Rata-rata Kehadiran Siswa','Aksi'));
		
		     $mythnsem = new mythnsem; 
		     $vdt_sebaran = new dt_sebaran;
			 $dt_bap = new dt_bap;
		     $dt_dhmd = new dt_dhmd;
			 
			 if($thn!=$mythnsem->getthnsem()){
			   $dt_sem = $vdt_sebaran->getriwayatsemmtk($thn);
			 }else{  
			   $dt_sem = $vdt_sebaran->getsemmtk(); 
			 }
			 
			 $isi_data = array();
			 
			if(!empty($dt_sem)){
				foreach($dt_sem as $sem)
				{
				
				    if($thn!=$mythnsem->getthnsem()){
					  $dt_mtk = $vdt_sebaran->getriwayatmtk($sem['semestbkmk'],$thn);
                    }else{
					  $dt_mtk = $vdt_sebaran->getmtk($sem['semestbkmk']);	
					}
					
					if(!empty($dt_mtk)){
						foreach($dt_mtk as $row){
								
								$tmp=array();		  
								
								$tmp[]=array($row['semestbkmk'],array());
								
								$kdkmk = ($thn!=$mythnsem->getthnsem()) ? $row['kdkmktrnlm'] : $row['kdkmkkrs'];
								$tmp[]=array($kdkmk,array());								
								
								$tmp[]=array($this->ismrhitl($row['wp'],$row['nakmktbkmk']),array());								
								$tmp[]=array($this->ismrhitl($row['wp'],$row['sksmktbkmk']),array());
								
								$rn = ($thn!=$mythnsem->getthnsem()) ? $row['shifttrnlm'] : $row['shiftkrs'];
								$tmp[]=array($arr_rn[$rn],array());
																
								$tmp_Ang = ($thn!=$mythnsem->getthnsem()) ? $vdt_sebaran->getriwayatAngkatan($row['kdkmktrnlm'],$row['shifttrnlm'],$row['kelastrnlm'],$row['semestrnlm'],$thn) : $vdt_sebaran->getAngkatan($row['kdkmkkrs'],$row['shiftkrs'],$row['kelaskrs'],$row['semkrs']);
                               	$tmp[]=array($tmp_Ang,array());
								
									$sem=($thn!=$mythnsem->getthnsem()) ? $row['semestrnlm'] : $row['semkrs'];
									$kelas=($thn!=$mythnsem->getthnsem()) ? $row['kelastrnlm'] : $row['kelaskrs'];
																
								$tmp[]=array('<center>'.$sem.'</center>',array());
								$tmp[]=array('<center>'.$kelas.'</center>',array());
								
								$idbapdhmd= $thn.$kdkmk.$sem.$kelas.$rn;								
								
								$tmp[]=array('<center>'.$dt_bap->getjmlpertemu('BAP'.$idbapdhmd).'</center>',array());
								$tmp[]=array('<center>'.floor($dt_dhmd->jmlratapertemu('DHMD'.$idbapdhmd)).'</center>',array());
								
								$link='frm_entry_bap_dhmd.php?thn='.$thn.'&kdkmk='.$kdkmk.'&rn='.$rn.'&kelas='.$kelas.'&sem='.$sem;
								$tmp[]=array("<a href='$link'>Entry</a>",array());
                                $isi_data[]=$tmp; 								
							
							}
					}
				
				}
			} 
			
			
					$txt = "<tr>";
						$txt = $txt."<th></th>";
						$txt = $txt."<th><input type='hidden' name='search_sem' value='Search sem' class='search_init' /><input type='text' name='search_kode' value='Kode' class='search_init' style='width:150px'/></th>";
						$txt = $txt."<th><input type='text' name='search_mtk' value='Matakuliah' class='search_init' style='width:250px' /></th>";
						$txt = $txt."<th><input type='hidden' name='search_sks' value='sks' class='search_init' /></th>";
						$txt = $txt."<th><input type='text' name='search_RgNrg' value='Reg/NReg' class='search_init' style='width:50px'/></th>";
						$txt = $txt."<th><input type='text' name='search_Ang' value='Angkatan' class='search_init' style='width:50px'/></th>";
						$txt = $txt."<th><input type='text' name='search_SemMhs' value='Sem. Mhs.' class='search_init' style='width:50px'/></th>";
						$txt = $txt."<th><input type='text' name='search_KlsMhs' value='Kls. Mhs.' class='search_init' style='width:50px'/></th>";
						//$txt = $txt."<th><input type='text' name='search_Jmlh' value='Jumlah.' class='search_init' style='width:50px'/></th>";
						
						$txt = $txt."<th></th>";
						$txt = $txt."<th></th>";
						$txt = $txt."<th></th>";
						 
					$txt = $txt."</tr>";
			  	
			
		
		
		
		$tbl = new mytable($tbstat,$header,$isi_data,$txt);
		
		return $tbl->display();
		
	}
	
	function entrybapdhmd($thn,$kdkmk,$sem,$kelas,$rn)
	{
		
		$dt_bap = new dt_bap;
		$dt_dhmd = new dt_dhmd;
		$html_element = new html_element;
		$mythnsem = new mythnsem;
		$dt_ksd_ngajar = new dt_ksd_ngajar;
		$dtdosen=new dt_dosen;
		$arr_rn = array('R'=>'Reguler','N'=>'Non Reguler');
			
		if($thn==$mythnsem->getthnsem()){		
		  $data =$dt_ksd_ngajar->getpengajar(array('Kdkmk'=>$kdkmk,'shift'=>$rn,'thnsms'=>$thn,'sem'=>$sem,'klsklh'=>$kelas));
		  $txtdsn=$data[0]['kdds'].' - '.$dtdosen->getnmdsn1($data[0]['kdds']);
		  $txtkmk=$data[0]['Kdkmk'].' - '.$data[0]['nakmktbkmk'];
		}else{
		  $data =$dt_ksd_ngajar->getriwayatpengajar(array('kdkmkpengajar'=>$kdkmk,'shiftpengajar'=>$rn,'thnsmspengajar'=>$thn,'semespengajar'=>$sem,'kelaspengajar'=>$kelas));
		  $txtdsn=$data[0]['kddspengajar'].' - '.$dtdosen->getnmdsn1($data[0]['kddspengajar']);
		  $txtkmk=$data[0]['kdkmkpengajar'].' - '.$data[0]['nakmktbkmk'];
		}
		    			
		    $tbstat = array("id" => "idmtk");
		    $isi_data = array();
			$tmp=array();								
			$tmp[]=array('Mata Kuliah',array());
			$tmp[]=array(':',array());
			$tmp[]=array($txtkmk,array());
			$isi_data[]=$tmp; 
			
			$tmp=array();								
			$tmp[]=array('Dosen',array());
			$tmp[]=array(':',array());
			$tmp[]=array($txtdsn,array());
			$isi_data[]=$tmp; 
			
			$tmp=array();								
			$tmp[]=array('Semester/TA',array());
			$tmp[]=array(':',array());
			$tmp[]=array($sem.'/'.$mythnsem->getthn().' - '.($mythnsem->getthn()+1),array());
			$isi_data[]=$tmp;
			
		    $tmp=array();								
			$tmp[]=array('Kelas',array());
			$tmp[]=array(':',array());
			$tmp[]=array($arr_rn[$rn],array());
			$isi_data[]=$tmp;
		
		
		$tbl = new mytable($tbstat,array(),$isi_data,'');
		$txt=$html_element->addfieldset('Identitas Matakuliah',$tbl->display());
		
		$tbstat = array("id" => "lstbapdhmd");
		$header = array(array('Pertemuan Ke','Tanggal','Materi','Jumlah Mhs','Aksi'));		
		
		$idbapdhmd= $thn.$kdkmk.$sem.$kelas.$rn;
		
		$isi_data = array();
		for($i=1;$i<=16;$i++)
		{
			$tmp=array();								
			$tmp[]=array("<center>$i</center>",array());
			
			$dt = $dt_bap->getData('id="BAP'.$idbapdhmd.$i.'"');
			
						
			$tmp[]=array((empty($dt) ? '' : $dt[0]['tgl']),array());			
			$tmp[]=array((empty($dt) ? 'Materi1:<br>Materi2:' : 'Materi1:<br>'.$this->ismrhitl('p',strip_tags($dt[0]['materi1'])).'<br>Materi2:<br>'.$this->ismrhitl('p',strip_tags($dt[0]['materi2']))),array());
			
			$jml=$dt_dhmd->jmlmhspertemu('DHMD'.$idbapdhmd.$i);
			$tmp[]=array("<center>$jml</center>",array());
			
			if(empty($dt)){	
				$link1='frm_add_bap_dhmd.php?thn='.$thn.'&kdkmk='.$kdkmk.'&rn='.$rn.'&kelas='.$kelas.'&sem='.$sem.'&ke='.$i.'&idx=1';
				$tmp[]=array("<a href='$link1'>Add</a>",array());
			}else{	
				$link2='frm_add_bap_dhmd.php?thn='.$thn.'&kdkmk='.$kdkmk.'&rn='.$rn.'&kelas='.$kelas.'&sem='.$sem.'&ke='.$i.'&idx=2';
				$tmp[]=array("<a href='$link2'>Edit</a>",array());			
			}
			$isi_data[]=$tmp; 
		}
		
		
		$tbl = new mytable($tbstat,$header,$isi_data,'');
		$txt.=$html_element->addfieldset('BAP & DHMD per Pertemuan',$tbl->display());
		
		return $txt;
	}
	
	function addbapdhmd($thn,$kdkmk,$sem,$kelas,$rn,$ke,$idx)
	{
	    $html_element = new html_element;
		$mythnsem = new mythnsem;
		$dt_ksd_ngajar = new dt_ksd_ngajar;
		$vbaca_krs = new dt_krs;
		$vbaca_trnlm = new dt_trnlm;
		$dt_bap = new dt_bap;
		$dt_dhmd = new dt_dhmd;
		$dtdosen=new dt_dosen;
		$arr_rn = array('R'=>'Reguler','N'=>'Non Reguler');
		$idbapdhmd= $thn.$kdkmk.$sem.$kelas.$rn.$ke;
			
		if($thn==$mythnsem->getthnsem()){		
		  $data =$dt_ksd_ngajar->getpengajar(array('Kdkmk'=>$kdkmk,'shift'=>$rn,'thnsms'=>$thn,'sem'=>$sem,'klsklh'=>$kelas));
		  $txtdsn=$data[0]['kdds'].' - '.$dtdosen->getnmdsn1($data[0]['kdds']);
		  $txtkmk=$data[0]['Kdkmk'].' - '.$data[0]['nakmktbkmk'];
		  $dt_mhs = $vbaca_krs->getMhs1($kdkmk,$rn,$kelas,$sem);
		}else{
		  $data =$dt_ksd_ngajar->getriwayatpengajar(array('kdkmkpengajar'=>$kdkmk,'shiftpengajar'=>$rn,'thnsmspengajar'=>$thn,'semespengajar'=>$sem,'kelaspengajar'=>$kelas));
		  $txtdsn=$data[0]['kddspengajar'].' - '.$dtdosen->getnmdsn1($data[0]['kddspengajar']);
		  $txtkmk=$data[0]['kdkmkpengajar'].' - '.$data[0]['nakmktbkmk'];
		  $dt_mhs = $vbaca_trnlm->getmhs($kdkmk,$rn,$kelas,$sem,$thn);
		}
		    			
		    $tbstat = array("id" => "idmtk");
		    $isi_data = array();
			$tmp=array();								
			$tmp[]=array('Mata Kuliah',array());
			$tmp[]=array(':',array());
			$tmp[]=array($txtkmk,array());
			$isi_data[]=$tmp; 
			
			$tmp=array();								
			$tmp[]=array('Dosen',array());
			$tmp[]=array(':',array());
			$tmp[]=array($txtdsn,array());
			$isi_data[]=$tmp; 
			
			$tmp=array();								
			$tmp[]=array('Semester/TA',array());
			$tmp[]=array(':',array());
			$tmp[]=array($sem.'/'.$mythnsem->getthn().' - '.($mythnsem->getthn()+1),array());
			$isi_data[]=$tmp;
			
		    $tmp=array();								
			$tmp[]=array('Kelas',array());
			$tmp[]=array(':',array());
			$tmp[]=array($arr_rn[$rn],array());
			$isi_data[]=$tmp;
		
		
		$tbl = new mytable($tbstat,array(),$isi_data,'');
		$txt=$html_element->addfieldset('Identitas Matakuliah',$tbl->display());
	  
	       if($idx=2){ 
			$data = $dt_bap->getData("id='BAP$idbapdhmd'");
		   }	
			$frm = new HTML_Form();
		    $tbstat = array("id" => "bap");
		    $isi_data = array();
			$tmp=array();								
			$tmp[]=array('Tanggal',array());
			$tmp[]=array(':',array());
			$tmp[]=array($frm->addInput('text',"tgl",($idx==2 ? $data[0]['tgl'] : null),array('id'=>'tgl')),array());
			$isi_data[]=$tmp; 
			
			$tmp=array();								
			$tmp[]=array('Materi(Direncanakan)',array());
			$tmp[]=array(':',array());
			$tmp[]=array($frm->addTextarea("m1",4,50,($idx==2 ? $data[0]['materi1']:'')),array());
			$isi_data[]=$tmp; 
			
			$tmp=array();								
			$tmp[]=array('Materi(Disampaikan)',array());
			$tmp[]=array(':',array());
			$tmp[]=array($frm->addTextarea("m2",4,50,($idx==2 ? $data[0]['materi1']:'')),array());
			$isi_data[]=$tmp;
			
		    $tmp=array();								
			$tmp[]=array('Metode Penyampaian',array());
			$tmp[]=array(':',array());
			
			$arr_mtd = array('Tutorial','Diskusi','Presentasi','Evaluasi dengan quiz','Evaluasi dengan tanya jawab lisan','Evaluasi dengan penyelesaian masalah nyata');
			
			$mtd_txt='';
			$i=0;
			foreach($arr_mtd as $row)
			{
			  $attr=array('id'=>'mtd$i');
			   if($idx=2){
			    if($data[0]['mtd'][$i]==1){
					$attr['checked']='true';
				}
			   }
			  $mtd_txt.=$frm->addInput('checkbox',"mtd[$i]",$i,$attr)."$row<br>";	
			  $i++;
			}
			
			$tmp[]=array($mtd_txt,array());
						
			$isi_data[]=$tmp;
		
		$tbl = new mytable($tbstat,array(),$isi_data,'');		
		$txt.=$html_element->addfieldset('Berita Acara Perkuliahan',$tbl->display());
	    
		$tbstat = array("id" => "lstdhmd",'width'=>'100%');
		$header = array(array(array('NIM',array('rowspan'=>2)),array('Nama',array('rowspan'=>2)),array('Presensi',array('colspan'=>4))),
		                 array('Hadir','Sakit','Izin','Alfa'));
		$isi_data = array();
		
		
		
		$arr_presensi=array();
		if($idx=2){
		  $arr_presensi	= $dt_dhmd->getpresensimhs('DHMD'.$idbapdhmd);
		}
		
		if(!empty($dt_mhs)){
			foreach($dt_mhs as $row){				
				$tmp=array();
				$tmp[]=array($row['nimhsmsmhs'],array());
				$tmp[]=array($row['nmmhsmsmhs'],array());
			
				for($i=1;$i<=4;$i++){
				  
				  $attr=array('id'=>"presensi$i");
                  if(!empty($arr_presensi)){  					
					  if(($idx==2) and ($i==$arr_presensi[$row['nimhsmsmhs']]))
					  {
						$attr['checked']='true';  
					  }
                  } 					  
				  $tmp[]=array($frm->addInput('radio','presensi['.$row['nimhsmsmhs'].']',$i,$attr),array());
				}
							
				$isi_data[]=$tmp;
			}
		} 
		
		
		$tbl = new mytable($tbstat,$header,$isi_data,'');
		$txt.=$html_element->addfieldset('Daftar Hadir Mahasiswa',$tbl->display());
	  
	  return $frm->startForm('#','post','frmbapdhmd').$txt.$frm->endForm();
	}
	
}	
?>