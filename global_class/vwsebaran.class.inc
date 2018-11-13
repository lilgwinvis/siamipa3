<?php

require_once 'shared.php';

class vwsebaran
{
	function __construct()
	{
	  	  
	}
    
	private function ismrhitl($iswp,$data)
	{
	   if($iswp=='p'){
	      return "<font color='red'><i>".$data."</i></font>";
	   }else{
	      return "$data";
	   }
	}
	
	function build($idx)
	{
	  	
	   $txt = "<table  id=\"box-table-a\" width=\"100%\">";
	   $txt = $txt."<thead>";
			
	   $txt = $txt."<tr>";
	   $txt = $txt."<th>Semester</th>";
	   $txt = $txt."<th>Kode</th>";
	   $txt = $txt."<th>Matakuliah</th>";
	   $txt = $txt."<th>SKS</th>";
	   $txt = $txt."<th>Reg/Non Reg</th>";
	   $txt = $txt."<th>Angkatan</th>";
	   $txt = $txt."<th>Sem. Mhs.</th>";
	   $txt = $txt."<th>Kls. Mhs.</th>";
	   $txt = $txt."<th>Jumlah Siswa</th>";
		 
		 if($idx==1){ 
		 // $tbl->addCell('Aksi', null, 'header',array('colspan'=>2,'align'=>'center'));
		 $txt = $txt."<th>Aksi 1</th>";
		 $txt = $txt."<th>Aksi 2</th>";
		 }else{
		    $txt = $txt."<th>Aksi 1</th>";
		 }
	 	$txt = $txt."</tr>";
		$txt = $txt."</thead>";
		$txt = $txt."<tbody>";	 
		
     		$vdt_sebaran = new dt_sebaran;
			 $dt_sem = $vdt_sebaran->getsemmtk();
		 
          if(!empty($dt_sem))
          {		  
			 foreach($dt_sem as $sem)
			 {
			   
			   $dt_mtk = $vdt_sebaran->getmtk($sem['semestbkmk']);
			  if(!empty($dt_mtk)){
			   foreach($dt_mtk as $row){
			           $txt = $txt."<tr>";
				   
					  $txt = $txt."<td>".$row['semestbkmk']."</td>";
					  $txt = $txt."<td>".$row['kdkmkkrs']."</td>";
					  $txt = $txt."<td>".$this->ismrhitl($row['wp'],$row['nakmktbkmk'])."</td>";
					  
				      $txt = $txt."<td>".$this->ismrhitl($row['wp'],$row['sksmktbkmk'])."</td>";
					   
					  $tmp1= ($row['shiftkrs']=='R') ? "Reguler" : "Non Reguler";
					  $txt = $txt."<td>".$tmp1."</td>";
					   
					  $tmp_Ang = $vdt_sebaran->getAngkatan($row['kdkmkkrs'],$row['shiftkrs'],$row['kelaskrs'],$row['semkrs']);
					  $txt = $txt."<td>".$tmp_Ang."</td>";
					  
 					   $txt = $txt."<td>".$row['semkrs']."</td>";
					   $txt = $txt."<td>".$row['kelaskrs']."</td>";
					   $txt = $txt."<td>".$row['jml']."</td>";
					   
					   $lnk="../global_code/frm_lht_mhs.php?shiftkrs=".$row['shiftkrs']."&kdkmkkrs=".$row['kdkmkkrs']."&kelaskrs=".$row['kelaskrs']."&semkrs=".$row['semkrs'];
					  $txt = $txt."<td><a href='".$lnk."'>Lihat MHS</a></td>";
					  // $tbl->addCell($txt,null,'data');
					   
					     if($idx==1){
					   	       
							   $user = $_SESSION['user'];
	                           
		            
		                       $dtuser = new dt_user;
                               $hak = $dtuser->gethak($user); 
							   
							   
							   $lnk="../global_code/frm_ubah_kls.php?shiftkrs=".$row['shiftkrs']."&kdkmkkrs=".$row['kdkmkkrs']."&kelaskrs=".$row['kelaskrs']."&semkrs=".$row['semkrs'];
							   
							   if($hak==0){
								   $txt = $txt."<td>Ubah</td>";
							   }else{
								   $txt = $txt."<td><a href='".$lnk."'>Ubah</a></td>";
							   }
							   
							   
							   
							   //$tbl->addCell($txt,null,'data');
					        }
			          
			    $txt = $txt."</tr>";
			   }
			  }
			   
			 }
		   }
			$txt = $txt."</tbody>";
			$txt = $txt."<tfoot>";
					$txt = $txt."<tr>";
						$txt = $txt."<th></th>";
						$txt = $txt."<th><input type='hidden' name='search_sem' value='Search sem' class='search_init' /><input type='text' name='search_kode' value='Kode' class='search_init' style='width:150px'/></th>";
						$txt = $txt."<th><input type='text' name='search_mtk' value='Matakuliah' class='search_init' style='width:250px' /></th>";
						$txt = $txt."<th><input type='hidden' name='search_sks' value='sks' class='search_init' /></th>";
						$txt = $txt."<th><input type='text' name='search_RgNrg' value='Reg/NReg' class='search_init' style='width:50px'/></th>";
						$txt = $txt."<th><input type='text' name='search_Ang' value='Angkatan' class='search_init' style='width:50px'/></th>";
						$txt = $txt."<th><input type='text' name='search_SemMhs' value='Sem. Mhs.' class='search_init' style='width:50px'/></th>";
						$txt = $txt."<th><input type='text' name='search_KlsMhs' value='Kls. Mhs.' class='search_init' style='width:50px'/></th>";
						$txt = $txt."<th><input type='text' name='search_Jmlh' value='Jumlah.' class='search_init' style='width:50px'/></th>";
						$txt = $txt."<th></th>";
						if($idx==1){
						 $txt = $txt."<th></th>";
						} 
					$txt = $txt."</tr>";
			  $txt = $txt."</tfoot>";	
			$txt = $txt."</table>";
			return $txt;	
	}
	
	function riwayatsebaran($thn)
	{
	  	
	   $txt = "<table  id=\"box-table-a\" width=\"100%\">";
	   $txt = $txt."<thead>";
			
	   $txt = $txt."<tr>";
	   $txt = $txt."<th>Semester</th>";
	   $txt = $txt."<th>Kode</th>";
	   $txt = $txt."<th>Matakuliah</th>";
	   $txt = $txt."<th>SKS</th>";
	   $txt = $txt."<th>Reg/Non Reg</th>";
	   $txt = $txt."<th>Angkatan</th>";
	   $txt = $txt."<th>Sem. Mhs.</th>";
	   $txt = $txt."<th>Kls. Mhs.</th>";
	   $txt = $txt."<th>Jumlah Siswa</th>";
		 
		 
		 $txt = $txt."<th>Aksi 1</th>";
		 $txt = $txt."<th>Aksi 2</th>";
		 
	 	$txt = $txt."</tr>";
		$txt = $txt."</thead>";
		$txt = $txt."<tbody>";	 
		
     		 $vdt_sebaran = new dt_sebaran;
			 $dt_sem = $vdt_sebaran->getriwayatsemmtk($thn);
			 
			if(!empty($dt_sem)){
			 foreach($dt_sem as $sem)
			 {
			   
			   $dt_mtk = $vdt_sebaran->getriwayatmtk($sem['semestbkmk'],$thn);
			  if(!empty($dt_mtk)){
			   foreach($dt_mtk as $row){
			           $txt = $txt."<tr>";
				   
					  $txt = $txt."<td>".$row['semestbkmk']."</td>";
					  $txt = $txt."<td>".$row['kdkmktrnlm']."</td>";
					  $txt = $txt."<td>".$this->ismrhitl($row['wp'],$row['nakmktbkmk'])."</td>";
					  
				      $txt = $txt."<td>".$this->ismrhitl($row['wp'],$row['sksmktbkmk'])."</td>";
					   
					  $tmp1= ($row['shifttrnlm']=='R') ? "Reguler" : "Non Reguler";
					  $txt = $txt."<td>".$tmp1."</td>";
					   
					  $tmp_Ang = $vdt_sebaran->getriwayatAngkatan($row['kdkmktrnlm'],$row['shifttrnlm'],$row['kelastrnlm'],$row['semestrnlm'],$thn);
					  $txt = $txt."<td>".$tmp_Ang."</td>";
					  
 					   $txt = $txt."<td>".$row['semestrnlm']."</td>";
					   $txt = $txt."<td>".$row['kelastrnlm']."</td>";
					   $txt = $txt."<td>".$row['jml']."</td>";
					   
					  $lnk="../global_code/frm_lht_riwayat_mhs.php?shifttrnlm=".$row['shifttrnlm']."&kdkmktrnlm=".$row['kdkmktrnlm']."&kelastrnlm=".$row['kelastrnlm']."&semestrnlm=".$row['semestrnlm']."&thsmstrnlm=".$thn;
					  $txt = $txt."<td><a href='".$lnk."'>Lihat MHS</a></td>";
					  // $tbl->addCell($txt,null,'data');
					           $user = $_SESSION['user'];
	                           
		            
		                       $dtuser = new dt_user;
                               $hak = $dtuser->gethak($user); 
					     
					   	       $lnk="../global_code/frm_ubah_riwayat_kls.php?shifttrnlm=".$row['shifttrnlm']."&kdkmktrnlm=".$row['kdkmktrnlm']."&kelastrnlm=".$row['kelastrnlm']."&semestrnlm=".$row['semestrnlm']."&thsmstrnlm=".$thn;
							   
							   if($hak==0)
                               {
								   $txt = $txt."<td>Ubah</td>";
							   }else{							   
							   $txt = $txt."<td><a href='".$lnk."'>Ubah</a></td>";
							   }
							   //$tbl->addCell($txt,null,'data');
					        
			          
			    $txt = $txt."</tr>";
			   }
			  }
			   
			 }
			 } 
			$txt = $txt."</tbody>";
			$txt = $txt."<tfoot>";
					$txt = $txt."<tr>";
						$txt = $txt."<th></th>";
						$txt = $txt."<th><input type='hidden' name='search_sem' value='Search sem' class='search_init' /><input type='text' name='search_kode' value='Kode' class='search_init' style='width:150px'/></th>";
						$txt = $txt."<th><input type='text' name='search_mtk' value='Matakuliah' class='search_init' style='width:250px' /></th>";
						$txt = $txt."<th><input type='hidden' name='search_sks' value='sks' class='search_init' /></th>";
						$txt = $txt."<th><input type='text' name='search_RgNrg' value='Reg/NReg' class='search_init' style='width:50px'/></th>";
						$txt = $txt."<th><input type='text' name='search_Ang' value='Angkatan' class='search_init' style='width:50px'/></th>";
						$txt = $txt."<th><input type='text' name='search_SemMhs' value='Sem. Mhs.' class='search_init' style='width:50px'/></th>";
						$txt = $txt."<th><input type='text' name='search_KlsMhs' value='Kls. Mhs.' class='search_init' style='width:50px'/></th>";
						$txt = $txt."<th><input type='text' name='search_Jmlh' value='Jumlah.' class='search_init' style='width:50px'/></th>";
						$txt = $txt."<th></th>";
						$txt = $txt."<th></th>";
						 
					$txt = $txt."</tr>";
			  $txt = $txt."</tfoot>";	
			$txt = $txt."</table>";			
			return $txt;	
	}
	
	function sem_filter()
	{
	  	  
	  $mythnsem = new mythnsem;	  
	  $dtsem = $mythnsem->getlstthnsem();	  
	  $vtemp = $dtsem[key($dtsem)];
	  $thnsms =key($dtsem); 
	  
	  $frm = new HTML_Form();
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmfilter"));
	  $tbl->addRow();
      $tbl->addCell('Semester'.$frm->addSelectList("semester",$dtsem,true,null,null,array('id'=>'semester')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')), null, 'data');
	  
	  $txt="<fieldset>";
	  $txt.="<legend>Filter</legend>";
	  $txt.=$tbl->display();
	  $txt.="</fieldset>";
	  
	  $txt.="<fieldset>";
      $txt.="<legend id='hsl_filter'>Sebaran Matakuliah : $vtemp </legend>";
      $txt.="<div id='data'>";	
	  $txt.=$this->riwayatsebaran($thnsms);
	  $txt.="</div>";  
	  $txt.="</fieldset>";  
	  
	   
	  return $txt; 
	}
	
	function ctk_BAP($data)
	{
	 	  	  
	    $mk=$data['kdkmk']." - ".$data['nakmk'];
	    $ds=$data['kdds']." - ".$data['nads'];	   
	   
	   $vbaca_krs = new dt_krs;
	   $thnsms = $vbaca_krs->TA();
	   $tmp = str_split($thnsms, 4);	  
	   $thn=$tmp[0];
	        
	  $tmp="../Admin/cetak/bap/BAP ".$mk." ".$ds.".xls";
	  
       $vwctkBAP = new vw_ctkbap;
	   $vwctkBAP->ctk_BAP($mk,$ds, $data['sem'].'/'.$thn.'-'.($thn+1),$data['kls']);
	   $vwctkBAP->save($tmp);	  
	  
	  return $tmp;
	
	}
	
	function ctk_CBAP($data)
	{
	  
	  
	  $mk=$data['kdkmk']." - ".$data['nakmk'];
	  $ds=$data['kdds']." - ".$data['nads'];
	  
	  
	  
	   $vbaca_krs = new dt_krs;
	   $thnsms = $vbaca_krs->TA();
	   $tmp = str_split($thnsms, 4);	  
	   $thn=$tmp[0];
	  
	  	  
	  $tmp="../Admin/cetak/bap/CBAP ".$mk." ".$ds.".xls";
	  
	  
	   $vwctkCBAP = new vw_ctkcbap;
	   $vwctkCBAP->ctk_CBAP($mk,$ds, $data['sem'].'/'.$thn.'-'.($thn+1),$data['kls']);
	   $vwctkCBAP->save($tmp);
	  
	  
	  return $tmp;
	}
	
	function ctk_DHMD($data)
	{
	  
	  
	  $mk=$data['kdkmk']." - ".$data['nakmk'];
	  $ds=$data['kdds']." - ".$data['nads'];
	  
	  	  
	   $vbaca_krs = new dt_krs;
	   $thnsms = $vbaca_krs->TA();
	   $tmp = str_split($thnsms, 4);	  
	   $thn=$tmp[0];
	  
	 	  
	  if($data['kls']=='Reguler'){
	    $tmp_shift='R';
	  }else{
	    $tmp_shift='N';
	  }
	  
	  $data1 = $vbaca_krs->getMhs1($data['kdkmk'],$tmp_shift,'',$data['sem']);
	  
	  $tmp="../Admin/cetak/absen/DHMD ".$mk." ".$ds.".xls";
	  	  
	  $vwctkdhmd = new vw_ctkdhmd;
	  $vwctkdhmd->ctk_DHMD($data1,$mk,$ds, $data['sem'].'/'.$thn.'-'.($thn+1),$data['kls']);
	  $vwctkdhmd->save($tmp);
	  
	  return $tmp;
	}
	
	function ctk_Abs_Ujian($data,$idx=1)
	{
	    
	  $mk=$data['kdkmk']." - ".$data['nakmk'];
	  $ds=$data['kdds']." - ".$data['nads'];
	    
	   $vbaca_krs = new dt_krs;
	   $thnsms = $vbaca_krs->TA();
	   $tmp = str_split($thnsms, 4);	  
	   $thn=$tmp[0];
	  	  
	  if($data['kls']=='Reguler'){
	    $tmp_shift='R';
	  }else{
	    $tmp_shift='N';
	  }
	  
	  $data1 = $vbaca_krs->getMhs1($data['kdkmk'],$tmp_shift,'',$data['sem']);
	 	  
	  switch($idx){
	    case 1 : $tmp="../Admin/cetak/absen/Absen UTS ".$mk." ".$ds.".xls";break;
		case 2 : $tmp="../Admin/cetak/absen/Absen UAS ".$mk." ".$ds.".xls";break;
	  }
	  	  
	  $vwctkabsujian = new vw_ctk_abs_ujian;
	  $vwctkabsujian->ctk_Abs_Ujian($data1,$mk,$ds, $data['sem'].'/'.$thn.'-'.($thn+1),$data['kls'],$idx);
	  $vwctkabsujian->save($tmp);
	  
	  
	  return $tmp;
	}
	
	function ctk_DPNA($data)
	{
	  	  
	  $mk=$data['kdkmk']." - ".$data['nakmk'];
	  $ds=$data['kdds']." - ".$data['nads'];
	  $nads = $data['nads'];
	    
	   $vbaca_krs = new dt_krs;
	   $thnsms = $vbaca_krs->TA();
	   $tmp = str_split($thnsms, 4);	  
	   $thn=$tmp[0];
	    
	  
	   if($data['kls']=='Reguler'){
	    $tmp_shift='R';
	  }else{
	    $tmp_shift='N';
	  }
	  
	  $data1 = $vbaca_krs->getMhs1($data['kdkmk'],$tmp_shift,'',$data['sem']);
	   
	  	  
	  $tmp="../Admin/cetak/absen/DPNA ".$mk." ".$ds.".xls";
	  
	  $vwctkDPNA = new vw_ctk_dpna;
	  $vwctkDPNA->ctk_DPNA($data1,$mk,$ds, $data['sem'].'/'.$thn.'-'.($thn+1),$data['kls'],$nads);
	  $vwctkDPNA->save($tmp);
	  
	  
	  return $tmp;
	}
	
	function ctk_BAU($data)
	{
	  	  
	  $mk=$data['kdkmk']." - ".$data['nakmk'];
	  $ds=$data['kdds']." - ".$data['nads'];
	   	  
	   $vbaca_krs = new dt_krs;
	   $thnsms = $vbaca_krs->TA();
	   $tmp = str_split($thnsms, 4);	  
	   $thn=$tmp[0];
	   
	  $vwctkBAU = new vw_ctk_bau;
	  $vwctkBAU->ctk_BAU($mk,$ds, $data['sem'],$thn.'-'.($thn+1),$data['kls'],$tmp[1]=='1' ? 1 : 0);
	  
	  $tmp="../Admin/cetak/absen/BAU ".$mk." ".$ds.".xls";
	  $vwctkBAU->save($tmp);
	  	  
	  return $tmp;
	  
	}
	
	function ctk_label($data)
	{  
	  
	  $mk=$data['kdkmk']." - ".$data['nakmk'];
	  $ds=$data['kdds']." - ".$data['nads'];
	  	  
	   $vbaca_krs = new dt_krs;
	   $thnsms = $vbaca_krs->TA();
	   $tmp = str_split($thnsms, 4);	  
	   $thn=$tmp[0];
	  
	  $vwctklabel = new vw_ctk_label;	  
	  $vwctklabel->ctk_label($mk,$ds, $data['sem'],$thn,$data['kls']);

	  $tmp="../Admin/cetak/absen/Label ".$mk." ".$ds.".xls";
	  $vwctklabel->save($tmp);
	  	  
	  return $tmp;
	}

}


?>