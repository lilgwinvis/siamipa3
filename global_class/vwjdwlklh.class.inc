<?php

require_once 'shared.php';

class vwjdwlklh
{   var $dtjdwlklh;

	function __construct()
	{
		$this->dtjdwlklh = new dt_jdwl_klh;  
		
	}
	
	private function ismrhitl($iswp,$data)
	{
		if($iswp=='p'){
			return "<font color='red'><i>".$data."</i></font>";
		}else{
			return "$data";
		}
	}
	
	
	function build()
	{
		
		$tbstat = array('id' => 'box-table-a','width'=>'100%');	
		$header = array(array('Hari', 'Awal','Akhir','Sem','Kelas','Kode Matakuliah', 'Nama Matakuliah', 'Kode Dosen','Nama Dosen','Kode Asisten','Nama Asisten','Ruang Kelas'));
		$isi_data = array();
		
		$dt_dosen= new dt_dosen;
		
		$data=$this->dtjdwlklh->buildjdwlklh();
		$bentrok=$this->dtjdwlklh->cekbentrok();				
		
		
		
		if(!empty($data)){
			foreach($data as $row)
			{		  
				$tmp=array();
				$tmp[]=array($row['hariklh'], array());
				
				$iswp = isset($bentrok[$row['kdds']][$row['hariklh']]) ? 'p':'w';		  
				$iswp = ($iswp!='p') ? (isset($bentrok[$row['sem']][$row['hariklh']]) ? 'p':'w') : $iswp; 
				
				$tmp[]=array($this->ismrhitl($iswp,$row['jawalklh']), array());  
				$tmp[]=array($this->ismrhitl($iswp,$row['jakhirklh']), array());
				$tmp[]=array($row['sem'], array());
				$tmp[]=array($row['shift']=='R' ? 'Reguler':'Non Reguler', array());
				$tmp[]=array($row['kdkmk'], array());  
				$tmp[]=array($row['nakmktbkmk'], array());		  
				$tmp[]=array($row['kdds'], array());
				$tmp[]=array($row['nama'], array()); 
				$tmp[]=array($row['kdass']!="?????" ? $row['kdass'] : "", array());
				$tmp[]=array($row['kdass']!="?????" ? $dt_dosen->getnmdsn1($row['kdass']) : "", array());
				$tmp[]=array($row['rklh'], array());
				$isi_data[]=$tmp;
			}
		}		            $txt = '';
		$txt = $txt."<tr>";
		$txt = $txt."<th><input type='hidden' name='search_RgNrg' value='Reg/NReg' class='search_init' style='width:50px'/></th>";
		$txt = $txt."<th><input type='hidden' name='search_RgNrg' value='Reg/NReg' class='search_init' style='width:50px'/></th>";
		$txt = $txt."<th><input type='hidden' name='search_RgNrg' value='Reg/NReg' class='search_init' style='width:50px'/></th>";
		$txt = $txt."<th><input type='text' name='search_sem' value='Sem' class='search_init' style='width:20px'/></th>";
		$txt = $txt."<th><input type='text' name='search_RgNrg' value='Reg/NReg' class='search_init' style='width:50px'/></th>";
		$txt = $txt."<th><input type='text' name='search_KdMtk' value='Kd Mtk' class='search_init' style='width:45px'/></th>";
		$txt = $txt."<th><input type='text' name='search_NmMtk' value='Nama Mtk' class='search_init' style='width:100px'/></th>";
		$txt = $txt."<th><input type='text' name='search_KdDsn' value='Kd Dosen' class='search_init' style='width:45px'/></th>";
		$txt = $txt."<th><input type='text' name='search_NmDsn' value='Nama Dosen' class='search_init' style='width:100px'/></th>";
		$txt = $txt."<th><input type='hidden' name='search_RgNrg' value='Reg/NReg' class='search_init' style='width:50px'/></th>";
		$txt = $txt."<th><input type='hidden' name='search_RgNrg' value='Reg/NReg' class='search_init' style='width:50px'/></th>";
		$txt = $txt."<th><input type='hidden' name='search_RgNrg' value='Reg/NReg' class='search_init' style='width:50px'/></th>";						
		$txt = $txt."</tr>";
		
		$tbl = new mytable($tbstat,$header,$isi_data,$txt);		
		
		$dt_jdwl_klh = new dt_jdwl_klh;
		$dt_tgl_lama = $dt_jdwl_klh->getTglterlama();
		$dt_tgl_baru = $dt_jdwl_klh->getTglterbaru();
		$tgllama=isset($dt_tgl_lama[0]['tgllama']) ? $dt_tgl_lama[0]['tgllama'] : "0000-00-00 00:00:00";
		$tglbaru=isset($dt_tgl_baru[0]['tglbaru']) ? $dt_tgl_baru[0]['tglbaru'] : "0000-00-00 00:00:00";
			
		$html=new html_element;
		
		$txt=$html->addfieldset('Jadwal Kuliah',$tbl->display());
		
		$tbl1 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmstat","width" => "100%"));
		$tbl1->addRow();
		$tbl1->addCell('Tanggal Input Terlama', null, 'data'); 
		$tbl1->addCell(':', null, 'data');
		$tbl1->addCell($tgllama, null, 'data');
		
		$tbl1->addCell('Tanggal Input Terbaru', null, 'data'); 
		$tbl1->addCell(':', null, 'data');
		$tbl1->addCell($tglbaru, null, 'data');		
		
		$txt.=$html->addfieldset('Tanggal Input',$tbl1->display());
		
		return $txt;
	}
	
	function build_riwayat($thnsms)
	{
		$tbstat = array('id' => 'box-table-a','width'=>'100%');	
		$header = array(array('Hari', 'Awal','Akhir','Sem','Kelas','Kode Matakuliah', 'Nama Matakuliah', 'Kode Dosen','Nama Dosen','Kode Asisten','Nama Asisten','Ruang Kelas'));
		$isi_data = array();
		
		$data=$this->dtjdwlklh->buildriwayatjdwlklh($thnsms);
		$dt_dosen= new dt_dosen;
		if(!empty($data)){	
			foreach($data as $row)
			{
				$tmp=array();
				$tmp[]=array($row['haripengajar'], array());
				$tmp[]=array($row['jawalpengajar'], array()); 
				$tmp[]=array($row['jakhirpengajar'], array());
				$tmp[]=array($row['semestrnlm'], array());
				$tmp[]=array($row['shifttrnlm']=='R' ? 'Reguler':'Non Reguler', array());
				$tmp[]=array($row['kdkmktrnlm'], array());
				$tmp[]=array($row['nakmktbkmk'], array());	  
				$tmp[]=array($row['kddspengajar'], array());
				$tmp[]=array($row['nama'], array()); 
				$tmp[]=array($row['kdass']!="?????" ? $row['kdass'] : "", array());
				$tmp[]=array($row['kdass']!="?????" ? $dt_dosen->getnmdsn1($row['kdass']) : "", array());
				$tmp[]=array($row['ruangpengajar'], array());
                $isi_data[]=$tmp;				
			}
		}
		$txt = '';
		$txt = $txt."<tr>";
		$txt = $txt."<th><input type='hidden' name='search_RgNrg' value='Reg/NReg' class='search_init' style='width:50px'/></th>";
		$txt = $txt."<th><input type='hidden' name='search_RgNrg' value='Reg/NReg' class='search_init' style='width:50px'/></th>";
		$txt = $txt."<th><input type='hidden' name='search_RgNrg' value='Reg/NReg' class='search_init' style='width:50px'/></th>";
		$txt = $txt."<th><input type='text' name='search_sem' value='Sem' class='search_init' style='width:20px'/></th>";
		$txt = $txt."<th><input type='text' name='search_RgNrg' value='Reg/NReg' class='search_init' style='width:50px'/></th>";
		$txt = $txt."<th><input type='text' name='search_KdMtk' value='Kd Mtk' class='search_init' style='width:45px'/></th>";
		$txt = $txt."<th><input type='text' name='search_NmMtk' value='Nama Mtk' class='search_init' style='width:100px'/></th>";
		$txt = $txt."<th><input type='text' name='search_KdDsn' value='Kd Dosen' class='search_init' style='width:45px'/></th>";
		$txt = $txt."<th><input type='text' name='search_NmDsn' value='Nama Dosen' class='search_init' style='width:100px'/></th>";
		$txt = $txt."<th><input type='hidden' name='search_RgNrg' value='Reg/NReg' class='search_init' style='width:50px'/></th>";	
		$txt = $txt."<th><input type='hidden' name='search_RgNrg' value='Reg/NReg' class='search_init' style='width:50px'/></th>";	
		$txt = $txt."<th><input type='hidden' name='search_RgNrg' value='Reg/NReg' class='search_init' style='width:50px'/></th>";							
		$txt = $txt."</tr>";
		
		$tbl = new mytable($tbstat,$header,$isi_data,$txt);
		return $tbl->display();
	}
	
	function sem_filter()
	{
		
		$mythnsem = new mythnsem;	
		
		$dtsem=$mythnsem->getlstthnsem();
		$vtemp = $dtsem[key($dtsem)];
		$thnsms =key($dtsem);
		
		$frm = new HTML_Form();
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmfilter","width" => "100%"));
		$tbl->addRow();
		$tbl->addCell('Semester'.$frm->addSelectList("semester",$dtsem,true,null,null,array('id'=>'semester')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')), null, 'data');
				
		$html=new html_element;
		$txt=$html->addfieldset('Filter',$tbl->display());
				
		$tmp="<div id='data'>";	
		$tmp.=$this->build_riwayat($thnsms);
		$tmp.="</div>";  
		$txt.=$html->addfieldset("Jadwal Kuliah : $vtemp",$tmp,array('id'=>'hsl_filter'));  
		
		$dt_jdwl_klh = new dt_jdwl_klh;
		
		$dt_tgl_lama = $dt_jdwl_klh->getRiwayatTglterlama();		
		$tgllama=isset($dt_tgl_lama[0]['tgllama']) ? $dt_tgl_lama[0]['tgllama'] : "0000-00-00 00:00:00";
			
		
		$dt_tgl_baru = $dt_jdwl_klh->getRiwayatTglterbaru();		
		$tglbaru=isset($dt_tgl_baru[0]['tglbaru']) ? $dt_tgl_baru[0]['tglbaru'] : "0000-00-00 00:00:00";
			
		
		$tbl1 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmstat","width" => "100%"));
		$tbl1->addRow();
		$tbl1->addCell('Tanggal Input Terlama', null, 'data'); 
		$tbl1->addCell(':', null, 'data');
		$tbl1->addCell($tgllama, null, 'data');
		
		$tbl1->addCell('Tanggal Input Terbaru', null, 'data'); 
		$tbl1->addCell(':', null, 'data');
		$tbl1->addCell($tglbaru, null, 'data');		
		
		$txt.=$html->addfieldset('Tanggal Input',$tbl1->display());
		
		return $txt; 
	}
	
	function ctk_honor()
	{
		
		$vbaca_krs = new dt_krs;
		$thnsms = $vbaca_krs->TA();
		$tmp = str_split($thnsms, 4);	  
		$thn=$tmp[0];
		
		$dt_hnr = new dt_hnr_ngajar;
		$dataLB=$this->dtjdwlklh->buildhonor('"LB"');
		$dataDTY=$this->dtjdwlklh->buildhonor("'DTY','DTYLP'");        	
		
		
		if($tmp[1]==1){
			$tmp="../Admin/cetak/bap/Honor Dosen Ganjil ".$thn.($thn+1)." 4 Per.xls";
		}else{
			$tmp="../Admin/cetak/bap/Honor Dosen Genap ".$thn.($thn+1)." 4 Per.xls";
		}
		
		$vwctkhnr = new vw_ctkhnr;
		$vwctkhnr->buathnr($dataLB,$dt_hnr,$dataDTY,$dt_hnr);
		$vwctkhnr->save($tmp);
		
		return $tmp;
		
	}
	
	
	function ctk_honor2()
	{
		
		
		
		$vbaca_krs = new dt_krs;
		$thnsms = $vbaca_krs->TA();
		$tmp = str_split($thnsms, 4);	  
		$thn=$tmp[0];
		
		$dt_hnr = new dt_hnr_ngajar;
		$dataLB=$this->dtjdwlklh->buildhonor('"LB"',2);		
		$dataDTY=$this->dtjdwlklh->buildhonor("'DTY','DTYLP'",2);	   	  
		
		if($tmp[1]==1){
			$tmp="../Admin/cetak/bap/Honor Dosen Ganjil ".$thn.($thn+1)." 2 per.xls";
		}else{
			$tmp="../Admin/cetak/bap/Honor Dosen Genap ".$thn.($thn+1)." 2 per.xls";
		}
		
		$vwctkhnr = new vw_ctkhnr;
		$vwctkhnr->buathnr2($dataLB,$dt_hnr,$dataDTY,$dt_hnr);
		$vwctkhnr->save($tmp);
		
		return $tmp;
		
	}
	
	function ctk_pakasi()
	{
		
		$vbaca_krs = new dt_krs;
		$thnsms = $vbaca_krs->TA();
		$tmp = str_split($thnsms, 4);	  
		$thn=$tmp[0];
		
		$dtPR=$this->dtjdwlklh->buildpakasi('R');     
		$dt_jmlmhs=new dt_sebaran;
		$dtPN=$this->dtjdwlklh->buildpakasi('N');
		
		if($tmp[1]==1){
			$tmp="../Admin/cetak/bap/Pakasi Dosen Ganjil ".$thn.($thn+1).".xls";
		}else{
			$tmp="../Admin/cetak/bap/Pakasi Dosen Genap ".$thn.($thn+1).".xls";
		}
		
		$vwctkpakasi = new vw_ctkpakasi;
		$vwctkpakasi->buatpakasi($dtPR,$dtPN,$dt_jmlmhs);
		$vwctkpakasi->save($tmp);
		
		return $tmp;
	}
	
	function ctk_jdwl_toexcel()
	{
		
		$vbaca_krs = new dt_krs;
		$thnsms = $vbaca_krs->TA();
		$tmp = str_split($thnsms, 4);	  
		$thn=$tmp[0];
		$sem=$tmp[1]; 	   
		
		$dt_dosen= new dt_dosen;
		$data=$this->dtjdwlklh->buildjdwlklh();
		
		if($sem==1){
			$tmp="../Admin/cetak/bap/Jadwal Kuliah Ganjil ".$thn.($thn+1).".xls";
		}else{
			$tmp="../Admin/cetak/bap/Jadwal Kuliah Genap ".$thn.($thn+1).".xls";
		}
		
		$vwctkjdwlklh = new vw_ctkjdwlklh;
		$vwctkjdwlklh->buatjdwlklh($data,$dt_dosen,$thn,$sem);
		$vwctkjdwlklh->save($tmp);
		
		return $tmp;
		
	}
	
	function ctk_jdwl_topdf()
	{
		
		$jdl = '<font face="Times New Roman" size="10pt"><b>PROGRAM STUDI MATEMATIKA<br>FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM<br>UNIVERSITAS BALE BANDUNG</b></font><br><br>';
		$jdl .= '<center><font face="Times New Roman" size="10pt"><b>JADWAL KULIAH</b></font></center>';
		$vbaca_krs = new dt_krs;
		$thnsms = $vbaca_krs->TA();
		$tmp = str_split($thnsms, 4);	  
		$thn=$tmp[0];
		
		$server = $_SERVER['DOCUMENT_ROOT'];
		
		if($server=="/home/fmipaun/public_html") {
			$server=$server."/";
		} 
		else{
			$server="../Admin/cetak/bap/";
		}  
		
		
		if($tmp[1]==1){
			$tmp1="Jadwal Kuliah Ganjil ".$thn.($thn+1)." ".date("dmY His").".pdf";
			$jdl .= '<center><font face="Times New Roman" size="10pt"><b>SEMESTER GANJIL '.$thn.'/'.($thn+1).'</b></font></center><br><br>';
		}else{
			$tmp1="Jadwal Kuliah Genap ".$thn.($thn+1)." ".date("dmY His").".pdf";
			$jdl .= '<center><font face="Times New Roman" size="10pt"><b>SEMESTER GENAP '.$thn.'/'.($thn+1).'</b></font></center><br><br>';
		}
		
		
		
		
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "box-table-a","width"=>"100%",'border'=>'1','cellpadding'=>'2'));
		$tbl->addRow();
		$tbl->addCell('Hari', null, 'header');
		$tbl->addCell('Awal', null, 'header');
		$tbl->addCell('Akhir', null, 'header');
		$tbl->addCell('Sem', null, 'header');
		$tbl->addCell('Kelas', null, 'header');
		$tbl->addCell('Kode Matakuliah', null, 'header');
		$tbl->addCell('Nama Matakuliah', null, 'header');
		//$tbl->addCell('Kode Dosen', null, 'header');
		$tbl->addCell('Nama Dosen', null, 'header');
		$tbl->addCell('Ruang Kelas', null, 'header');
		
		$dt_dosen= new dt_dosen;
		$kdds = "";
		$nmds = ""; 
		
		$data=$this->dtjdwlklh->buildjdwlklh();
		$hari = array('','Senin','Selasa','Rabu','Kamis',"Jum"."'"."at",'Sabtu','Minggu');
		if(!empty($data)){
			foreach($data as $row)
			{
				$tbl->addRow();        
				foreach($row as $f=>$v)
				{
					if($f=="hariklh"){
						$tbl->addCell($hari[$v], null, 'data'); 
					}else{
						if($f=="shift"){
							$tbl->addCell($v=='R' ? 'Reguler':'Non Reguler', null, 'data'); 
						}else{
							if($f=="kdds" || $f=="kdass" || $f=="nama"){						   
								
								if($f=="kdds"){
									$kdds=$v; 
								}
								if($f=="nama"){
									$nmds=$v;
								}					   
								if($f=="kdass"){						     					     
									$nm= $v!="?????" ? $nmds.'('.$kdds.')'.'/'.$dt_dosen->getnmdsn1($v).'('.$v.')' : $nmds.'('.$kdds.')';							 
									$tbl->addCell($nm, null, 'data');
									
								}
								
							}else{
								
								
								if($f!="hnr" & $f!="Hstat" & $f!="sksmktbkmk" & $f!="kdds" & $f!="kdass" & $f!="nama"){
									$tbl->addCell($v, null, 'data');
								} 
							}
							
						}
					}				 
				}		
			}
		}		
		
		$html= '<html>'.
		'<style type="text/css">'.
		'table{font-family: Calibri; font-size: 9pt;}'.
		'</style>'.
		'<body>'.
		$jdl.
		$tbl->display().
		'<br><br>'.'<font face="Calibri" size="9pt">Dicetak dari Sistem Informasi Akademik FMIPA UNIBBA pada tanggal : '.date("d-m-Y H:i:s").'</font>'.
		'</body>'.
		'</html>';    
		
		
		
		$dompdf = new DOMPDF();
		$dompdf->load_html($html);
		$dompdf->set_paper('a4', 'landscape');
		$dompdf->render();
		$output = $dompdf->output();
		file_put_contents($server.$tmp1, $output);   
		
		if($server=="/home/fmipaun/public_html/") {
			$server="http://fmipa-unibba.org/";
		} 
		
		
		return $server.$tmp1;
		
	}
	
}	



?>