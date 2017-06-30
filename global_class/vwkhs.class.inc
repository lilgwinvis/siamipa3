<?php
require_once 'shared.php';


class vwkhs 
	{
	var $vkhs;
	function __construct(){
		$this->vkhs=new dt_khs;   	   
	}
	
	
	function filter_mhs($user=0)
	{
	
	$html_txt="<fieldset>";
	$html_txt.="<legend>Filter</legend>";
	
	$vmhs = new dt_mhs;
	$data = $vmhs->getAngkatan();
	$thn = $data[0]['tahunmsmhs'];	  
		
	$ang = array_combine(array_column($data,'tahunmsmhs'), array_column($data,'tahunmsmhs'));	
	
	$data = $vmhs->getkls($thn);
	$kls=$data[0]['shiftmsmhs'];	   
	
	$stat_arr = array_column($data,'shiftmsmhs');
	$txtstat_arr = array_map(function ($stat){ $tmp=($stat=='R') ? "Reguler" : "Non Reguler"; return $stat." - ".$tmp;},$stat_arr);
	$kelas = array_combine($stat_arr, $txtstat_arr);	   
	
	
	$data = $vmhs->getmhs($thn,$kls);
	$vnim=$data[0]['nimhsmsmhs'];
	$vtemp=$data[0]['nimhsmsmhs']."-".$data[0]['nmmhsmsmhs'];
	
	$nim_arr = array_column($data,'nimhsmsmhs');
	$nm_arr = array_map(function ($arr){ return $arr['nimhsmsmhs']." - ".$arr['nmmhsmsmhs'];},$data);
	$Mhs = array_combine($nim_arr, $nm_arr);				
	
	$frm = new HTML_Form();
	$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmfilter"));
	$tbl->addRow();
	$tbl->addCell('Angkatan '.$frm->addSelectList("Angkatan",$ang,true,null,null,array('id'=>'Angkatan')).' Kelas '.$frm->addSelectList("kls",$kelas,true,null,null,array('id'=>'kls')).' Mahasiswa '.$frm->addSelectList("Mhs",$Mhs,true,null,null,array('id'=>'Mhs')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')), null, 'data');
	
	$html_txt.=$tbl->display()."</fieldset>";

	$html_txt.="<fieldset>";
	$html_txt.="<legend  id='hsl_filter'> Hasil Filter : ".$vtemp."</legend>";
			
	
	$html_txt.="<div id='data'>";
	$html_txt.=$this->buildkhs($vnim,$user);
	$html_txt.="</div>";
	
	$html_txt.="</fieldset>";
			
	
	return $html_txt;
	
	}
	
	private function ismrhitl($iswp,$data)
	{
		if($iswp=='p')
		{
				return "<font color='red'><i>".$data."</i></font>";
			}
			else{
				return "$data";			
			}
	}
	
	function buildkhs($vnim,$user=0){
							
			$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_filter",'width'=>'100%'));
			$tbl->addRow();
			$tbl->addCell("Jdl", null, 'header');
			$tbl->addCell("Kode", null, 'header');
			$tbl->addCell("Matakuliah", null, 'header'); 
			$tbl->addCell("SKS", null, 'header');
			if ($user==0){ 
				$tbl->addCell("HM", null, 'header');
				$tbl->addCell("NM", null, 'header');
			}else{
				$tbl->addCell("Nilai Diumumkan", null, 'header');
				$tbl->addCell("Nilai Dosen", null, 'header');
			} 			  
			$this->vkhs->buildsem($vnim);
			$vtrnlm=new dt_trnlm;
		for($i = 0; $i < count($this->vkhs->vthsms_txt); $i++){
				$data = $this->vkhs->buildkhs($vnim,$this->vkhs->vthsms[$i]);
				foreach($data as $row){
				
					$tbl->addRow();
					$tbl->addCell($this->vkhs->vthsms[$i], null, 'data');
					$tbl->addCell($row['kdkmktrnlm'], null, 'data');
					$tbl->addCell($this->ismrhitl($row['wp'],$row['nakmktbkmk']), null, 'data');
					$tbl->addCell($this->ismrhitl($row['wp'],$row['sksmktbkmk']), null, 'data');					
					if ($user==0){ 	
						$tbl->addCell($row['nlakhtrnlm'], null, 'data');
						$tbl->addCell($row['bobottrnlm'], null, 'data');					
					}else{
						$tbl->addCell($row['nlakhtrnlm'], null, 'data');
						
						$data_trnlm = $vtrnlm->getData('nimhstrnlm="'.$vnim.'" and thsmstrnlm='.$this->vkhs->vthsms[$i].' and kdkmktrnlm="'.$row['kdkmktrnlm'].'"');
						if(!empty($data_trnlm)){ 
						foreach($data_trnlm as $row_trnlm){  
							if($row['nlakhtrnlm']!=$row_trnlm['nlakhtrnlm']){ 
							$tbl->addCell($row_trnlm['nlakhtrnlm'], null, 'data');
							}else{
							$tbl->addCell('', null, 'data');
							}
						}
						}else{
						$tbl->addCell('', null, 'data');
						}
				
						
					}					 
						
				}			  
		}
			
						$tfoot = "<tr>";
						$tfoot .= "<th></th>";
						$tfoot .= "<th><input type='hidden' name='search_sem' value='Search sem' class='search_init' /><input type='text' name='search_kode' value='Kode' class='search_init' style='width:150px'/></th>";
						$tfoot .= "<th><input type='text' name='search_mtk' value='Matakuliah' class='search_init' style='width:250px' /></th>";
						$tfoot .= "<th><input type='hidden' name='search_sks' value='Search sks' class='search_init' /></th>";
						$tfoot .= "<th><input type='text' name='search_hm' value='HM' class='search_init' style='width:20px'/></th>";
						$tfoot .= "<th></th>";
						$tfoot .= "</tr>";
						
		return $tbl->display($tfoot);
	}
	
	
	
	}

?>