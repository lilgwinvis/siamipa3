<?php
	require_once 'shared.php';
	
	class vw_riwayat_krs
    {

	  function __construct()
	 {
	    
	 } 
	 private function ismrhitl($iswp,$data)
	{
	   if($iswp=='p'){
	      return "<font color='red'><i>".$data."</i></font>";
	    }
		else{
	       return "$data";
		  
	   }
	}
	 
	 function sem_filter()
	{
	  $dtkrs = new dt_krs;
	  $TA = $dtkrs->TA();
      	  	
		
	  $thn = str_split($TA, 4);
	  
	  $dtsem = array();
	  $txt_sem = array(1=>'Ganjil',2=>'Genap');
	  $vtemp = "";	  
	  if($thn[1]==1)
	  {
	    $bts=$thn[0]-1;
	  }else
	  {
        $bts=$thn[0];         		
	  }
	  
	  for($i=2008;$i<=$bts;$i++)
	  {
	    for($j=1;$j<=2;$j++)
	    {
	      if($vtemp=="")
          {
		    $vtemp = 'Semester '.$txt_sem[$j].' '.$i;
			$thnsms =$i.$j;
		  }
		  
		  $dtsem[$i.$j]='Semester '.$txt_sem[$j].' '.$i;
	    } 
	  }	  
	  
	  if($thn[1]==1)
	  {
	    $dtsem[$thn[0].'1']='Semester Ganjil '.$thn[0];
	  }
	  
	 
	  
	  $frm = new HTML_Form();
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmfilter"));
	  $tbl->addRow();
      $tbl->addCell('Semester'.$frm->addSelectList("semester",$dtsem,true,null,null,array('id'=>'semester')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')), null, 'data');
	  
	  $html_txt="<fieldset>";
	  $html_txt.="<legend>Filter</legend>";
	  $html_txt.=$tbl->display()."</fieldset>";

      $html_txt.="<fieldset>";
	  $html_txt.="<legend  id='hsl_filter'>Riwayat Kartu Rencana Studi (KRS) : ".$vtemp."</legend>";
      
	 // $html_txt.="<fieldset>";
	 // $html_txt.="<legend>Aksi</legend>";
	 // $frm = new HTML_Form();
	 // $tbl1 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmAksi"));
	 // $tbl1->addRow();
	 // $tbl1->addCell($frm->addInput('submit',"Add","Add",array('id'=>'Add')).$frm->addInput('submit',"Edit","Edit",array('id'=>'Edit')).$frm->addInput('submit',"Delete","Delete",array('id'=>'Del')), null, 'data');
	//  $html_txt.=$tbl1->display()."</fieldset>";
	  
	  
	  $html_txt.="<div id='data'>";
	  $html_txt.=$this->riwayat_krs($thnsms);
	  $html_txt.="</div>";
	  
	  $html_txt.="</fieldset>";
        	  
	  
	  return $html_txt;
	
	}
	 
	 function riwayat_krs($thnsms)
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
       
		
	  $dt_mhs = new dt_mhs; 
	  $dt_trnlm = new dt_trnlm;
      $vbaca_trans = new dt_trans;	  
	  $dt_stat_mhs = new dt_stat_mhs; 
	  
	  $kls = array('R'=>'Reguler','N'=>'Non Reguler');
	  
	  $data = $dt_mhs->getAllData("smawlmsmhs in ($txt_filter)");
	  
	  if(!empty($data))
	  {
        $dataisi=array();
		$datanoisi=array();
		$dataisi1=array();
		$datanoisi1=array();
		
		foreach($data as $row)
		{
		 $tmpdt=array();
		 $tmpdt[]=array($row["tahunmsmhs"],array());
		 $tmpdt[]=array($row["nimhsmsmhs"],array());
	     $tmpdt[]=array($row["nmmhsmsmhs"],array());
		 $tmp=$row['shiftmsmhs'];
		 $tmpdt[]=array($kls[$tmp],array());
		
		 $tmp_stat = $dt_stat_mhs->getstatmhs($thnsms,$row['nimhsmsmhs']);
         $tmpdt[]=array($tmp_stat, array());	     
		 
         		 
		 $data1 = $vbaca_trans->hitipk($row['nimhsmsmhs'],$txt_filter1);
						
		 $ipk=0;
		 if($vbaca_trans->sks_mbl>0){ 
	  		$ipk = $vbaca_trans->sks_nm/$vbaca_trans->sks_mbl;
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
                                                   if($ipk>0){ 
												     $sks_blh=14;
                                                   } else {
												     $sks_blh=20;
												   }
					                              }

				                         }

			                       }
                             }  				
		 
		 $tmpdt[]=array(number_format($ipk, 2, '.', ''),array('align'=>'right'));
		 $tmpdt[]=array($sks_blh,array('align'=>'right'));
	     
		  $jml_sks=$dt_trnlm->getriwayatsks($thnsms,$row['nimhsmsmhs']);
		 
		  $tmpdt[]=array($jml_sks, array('align'=>'right'));
		  $link="frm_edit_riwayat_krs.php?nim=".$row['nimhsmsmhs']."&thnsms=".$thnsms;
		  $tmpdt[]=array("<a href='$link'>Edit KRS</a>",array('align'=>'center'));
		  
		  switch($tmp_stat)
		  {
		    case "Aktif" : $jml_sks>0 ? $dataisi[]=$tmpdt : $datanoisi[]=$tmpdt ;break;
		    default: $jml_sks>0 ? $dataisi1[]=$tmpdt :  $datanoisi1[]=$tmpdt;break;
		  }
		  
		  
		}	  
	  }
	  
	 
	 $header = array(array("Angkatan","NIM","Nama","Kelas","Status","IPK","Batas SKS","Ambil SKS","Aksi")); 
	 
     $accheader=array("Mahasiswa Aktif","Mahasiswa Dengan Status Lain");  
	 $acccontent = array();

	 
	 
		  $html_txt="<fieldset>";	
		  $html_txt.="<legend>Mengisi KRS</legend>";
		     $tbstat = array("id" => "lst_riwayatkrs",'width'=>'100%');
			 $tbl = new mytable($tbstat,$header,$dataisi,"");
		     $html_txt.=$tbl->display();
		  $html_txt.="</fieldset>";
	      $html_txt.="<fieldset>";	
		  $html_txt.="<legend>Tidak Mengisi KRS</legend>";
		     $tbstat = array("id" => "lst_riwayatkrs1",'width'=>'100%');
			 $tbl = new mytable($tbstat,$header,$datanoisi,"");
		     $html_txt.=$tbl->display();
		  $html_txt.="</fieldset>";
	 
	 $acccontent[] = $html_txt;
	 
	 
	       $html_txt="<fieldset>";	
		  $html_txt.="<legend>Mengisi KRS</legend>";
		     $tbstat = array("id" => "lst_riwayatkrs2",'width'=>'100%');
			 $tbl = new mytable($tbstat,$header,$dataisi1,"");
		     $html_txt.=$tbl->display();
		  $html_txt.="</fieldset>";
	      $html_txt.="<fieldset>";	
		  $html_txt.="<legend>Tidak Mengisi KRS</legend>";
		     $tbstat = array("id" => "lst_riwayatkrs3",'width'=>'100%');
			 $tbl = new mytable($tbstat,$header,$datanoisi1,"");
		     $html_txt.=$tbl->display();
		  $html_txt.="</fieldset>";  
	 $acccontent[] = $html_txt;		 
	 
	 $myaccordion = new myaccordion('accordion',$accheader,$acccontent);
	      return $myaccordion->display();
	 }
	 
	 function lht_krs($nim,$thnsms){
	   
	     $user = $_SESSION['user'];
	     
		            
		 $dtuser = new dt_user;
         $hak = $dtuser->gethak($user); 	   
	   
	   
	   $html_txt  = "<fieldset>";
	   $html_txt .= "<legend>Aksi</legend>";
	  
       $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "aksi"));
	   
	    $tbl->addRow();
		
			
		$btn="";
		
		 $btn="<button type='submit' id='ambil' ".($hak==0 ? 'disabled':'').">Ambil Mtk. Baru</button>";
		 $btn.="<button type='submit'  id='ulang' ".($hak==0 ? 'disabled':'').">Ulang Mtk.</button>";
		 $btn.="<button type='submit' id='edit' ".($hak==0 ? 'disabled':'').">Edit Kelas</button>";
		 $btn.="<button type='submit' id='hapus' ".($hak==0 ? 'disabled':'').">Hapus Mtk.</button>";
		 $btn.="<button type='submit' id='ctkexcel'>Cetak ke Excel</button>";		
		 $btn.="<button type='submit' id='ctkpdf'>Cetak Ke PDF</button>";
		
		$tbl->addCell($btn, null, 'data');
	    
       
	   $html_txt .= $tbl->display();
       $html_txt .= "</fieldset>";
       $html_txt .= "<fieldset>";	   
	   $html_txt .= "<legend>Kartu Rencana Studi (KRS)</legend>";
	   $html_txt .= "<div>";
	   $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_krs","width"=>"100%"));
	   
	    $tbl->addRow();
		$tbl->addCell("Sem", null, 'header');
		$tbl->addCell("Kode Mata Kuliah", null, 'header');
		$tbl->addCell("Nama Mata Kuliah", null, 'header');
		$tbl->addCell("SKS", null, 'header');
		$tbl->addCell("Kelas", null, 'header');
		$tbl->addCell("Tanggal Input", null, 'header');
		  
		  $vbaca_trnlm = new dt_trnlm;
		  		 
		  $data = $vbaca_trnlm->getMtk1($thnsms,$nim);
		    $jmlsks=0;
			if(!empty($data)){ 
			  foreach($data as $row){
			  
			    if($row['sksprtbkmk']>0){
                   $sks=number_format($row['sksmktbkmk']-1, 2, '.', '');
                   $jmlsks+=$row['sksmktbkmk']-1;
				}else{
				   $sks=$row['sksmktbkmk'];
                   $jmlsks+=$row['sksmktbkmk'];				   
				}
							
                 if($row['shifttrnlm']=='R'){
					  $tmp1="Reguler";
				 }else
				 {
				      $tmp1="Non Reguler";
				 }
				 
				 $tbl->addRow();
				 $tbl->addCell($row['semestbkmk'], null, 'data');
				 $tbl->addCell($row['kdkmktrnlm'], null, 'data');
				 $tbl->addCell($this->ismrhitl($row['wp'],$row['nakmktbkmk']), null, 'data');
				 $tbl->addCell($this->ismrhitl($row['wp'],$sks), null, 'data'); 
			     $tbl->addCell($tmp1, null, 'data'); 						
				 $tbl->addCell($row['tgl_input'], null, 'data'); 
				 
              }			  
            }
       $html_txt .= $tbl->display();
       $html_txt .= "</div>";	   
	   $html_txt .= "</fieldset>";	   
	   $html_txt .= "<fieldset>";	   
	   $html_txt .= "<legend>Statistik</legend>";
	   $html_txt .= "<p>Jumlah SKS yg diambil = ".$jmlsks."</p>";
	   $html_txt .= "</fieldset>";
	   return $html_txt;
	 
	 }
	 
	 function build_krs($nim,$thnsms,$baru=1){
	    
		$html_txt  = "<fieldset>";
		$html_txt .= "<legend>Daftar Matakuliah</legend>";
	    $html_txt .= "<div>";
		$html_txt .= "<form name='inputkrs' id='inputkrs' method='post' action='isikrs.php'>";
	    $html_txt .= "<input type='hidden' name='nim' value='$nim'>";
	    
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_mtk","width"=>"100%"));
	     
	    $tbl->addRow();
		$tbl->addCell("Sem", null, 'header');
		$tbl->addCell("Kode Mata Kuliah", null, 'header');
		$tbl->addCell("Nama Mata Kuliah", null, 'header');
		$tbl->addCell("SKS", null, 'header');
		$tbl->addCell("Ambil", null, 'header');
		$tbl->addCell("Kelas", null, 'header');
		
		$vdt_mhs = new dt_mhs;
		$data = $vdt_mhs->getData($nim);
		
		if(!empty($data))
		{
		  foreach($data as $row){
		    $kls = $row['shiftmsmhs'];
		     }		  
		}
		
		$vbuild_trnlm = new dt_trnlm;
		$data = $vbuild_trnlm->buildkrs($nim,$thnsms,$baru);
		
		if(!empty($data)){
		$i=0;
		  foreach($data as $row){
		         $tbl->addRow();
				 $tbl->addCell($row['semestbkmk'], null, 'data');
				 $tbl->addCell($row['kdkmktbkmk'], null, 'data');
				 $tbl->addCell($this->ismrhitl($row['wp'],$row['nakmktbkmk']), null, 'data');
				 $tbl->addCell($this->ismrhitl($row['wp'], $row['sksmktbkmk']), null, 'data'); 
			     $tmp_kd=$row['kdkmktbkmk'];
				 $tmp_input = "<input type='checkbox' name='mk[]' value='$tmp_kd' id='mk' >";
				 $tbl->addCell($tmp_input, null, 'data',array('align'=>'center')); 						
				 
				 
				 $tmp_input ="<select name='kls[".$tmp_kd."]' id='kls'>";				 
  				 if($kls=='R'){
				    $tmp_input .="<option selected='selected' value='R'>Reguler</option>";
					$tmp_input .="<option value='N'>Non Reguler</option>";
				 }else{
				    $tmp_input .="<option value='R'>Reguler</option>";
                    $tmp_input .="<option selected='selected' value='N'>Non Reguler</option>";
				 }
				 $tmp_input .="</select>";			 
				 
				 $tbl->addCell($tmp_input, null, 'data'); 
				 $i++;
		  }
		}
	   
	   $tbl1 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "jml_sks","width"=>"100%"));
	   $tbl1->addRow();
	   $tbl1->addCell("<b>JUMLAH SKS YANG DIAMBIL</b>", null, 'data',array('colspan'=>3,'align'=>'center'));		
       $tmp_input =	"<input type='text' name='totalsks' size='3' maxlength='3' id='jsks' readonly='readonly' style='text-align:center; color:red;'>";	
	   $tbl1->addCell($tmp_input, null, 'data',array('align'=>'center'));
		
	   
       $html_txt .= $tbl->display().$tbl1->display()."</form>"; 	   
	   $html_txt .= "</div>";
	   $html_txt .= "</fieldset>";
	   
	   return $html_txt;
	 }
	 
	 function olah_krs($nim,$thnsms,$hapus=0){
	   
	   
	  
       $html_txt = "<fieldset>";	   
	   $html_txt .= "<legend>Kartu Rencana Studi (KRS)</legend>";
	   $html_txt .= "<div>";
	   $html_txt .= "<form name='inputkrs' id='inputkrs' method='post' action='isikrs.php'>";
	    $html_txt .= "<input type='hidden' name='nim' value='$nim'>";
	   $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_krs","width"=>"100%"));
	   
	    $tbl->addRow();
		$tbl->addCell("Sem", null, 'header');
		$tbl->addCell("Kode Mata Kuliah", null, 'header');
		$tbl->addCell("Nama Mata Kuliah", null, 'header');
		$tbl->addCell("SKS", null, 'header');
		if($hapus==0){
		  $tbl->addCell("Kelas", null, 'header');
		}else{
		  $tbl->addCell("Hapus", null, 'header');
		}
		  
		  $vbaca_krs = new dt_trnlm;
		  		 
		  $data = $vbaca_krs->getMtk2($thnsms,$nim,0);
		    $jmlsks=0;
			if(!empty($data)){ 
			  foreach($data as $row){
			  
			    if($row['sksprtbkmk']>0 and $hapus==0){
                   $sks=number_format($row['sksmktbkmk']-1, 2, '.', '');
                   $jmlsks+=$row['sksmktbkmk']-1;
				}else{
				   $sks=$row['sksmktbkmk'];
                   $jmlsks+=$row['sksmktbkmk'];				   
				}
							
                 
				 
				 $tbl->addRow();
				 $tbl->addCell($row['semestbkmk'], null, 'data');
				 $tbl->addCell($row['kdkmktrnlm'], null, 'data');
				 $tbl->addCell($this->ismrhitl($row['wp'],$row['nakmktbkmk']), null, 'data');
				 $tbl->addCell($this->ismrhitl($row['wp'],$sks), null, 'data'); 
			    if($hapus==0){ 						
				 $tmp_kd=$row['kdkmktrnlm'];
				 $tmp_input ="<select name='kls[".$tmp_kd."]' id='kls'>";
				 if($row['shifttrnlm']=='R'){
					 $tmp_input .="<option selected='selected' value='R'>Reguler</option>";
					 $tmp_input .="<option value='N'>Non Reguler</option>";
				 }else
				 {
				    $tmp_input .="<option value='R'>Reguler</option>";
                    $tmp_input .="<option selected='selected' value='N'>Non Reguler</option>";
				 }
				  $tmp_input .="</select>";
				 
				 }else{
				   $tmp_kd=$row['kdkmktrnlm'];
				   $tmp_input = "<input type='checkbox' name='mk[]' value='$tmp_kd' id='mk' >"; 
				 }
				  $tbl->addCell($tmp_input, null, 'data');
				 
              }			  
            }
       $html_txt .= $tbl->display()."</form>";
       $html_txt .= "</div>";	   
	   $html_txt .= "</fieldset>";	   
	   
	   return $html_txt;
	 
	 } 
	 
	 
	 function ctk_kartu($vnim,$idx=1){
	  $objPHPExcel = new PHPExcel();
	  $objPHPExcel->setActiveSheetIndex(0);
	  
	
      $objPHPExcel->getActiveSheet()->getColumnDimension('A')->setWidth(3.57);
	  $objPHPExcel->getActiveSheet()->getColumnDimension('B')->setWidth(11.14);
	  $objPHPExcel->getActiveSheet()->getColumnDimension('C')->setWidth(0.83);
	  $objPHPExcel->getActiveSheet()->getColumnDimension('D')->setWidth(32.00);	
	  $objPHPExcel->getActiveSheet()->getColumnDimension('E')->setWidth(6.00);
	  $objPHPExcel->getActiveSheet()->getColumnDimension('F')->setWidth(8.43);
	  $objPHPExcel->getActiveSheet()->getColumnDimension('G')->setWidth(2.86);
	  $objPHPExcel->getActiveSheet()->getColumnDimension('H')->setWidth(7.00); 
	  $objPHPExcel->getActiveSheet()->getColumnDimension('I')->setWidth(0.83); 
	  $objPHPExcel->getActiveSheet()->getColumnDimension('J')->setWidth(16.00); 
     	  
	  $objPHPExcel->getActiveSheet()->getRowDimension(1)->setRowHeight(26.25);  
	  $objPHPExcel->getActiveSheet()->getRowDimension(5)->setRowHeight(20.25);
      		
      
	  $objPHPExcel->getActiveSheet()->mergeCells('D1:J1');
	  $objPHPExcel->getActiveSheet()->getStyle('D1:J1')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('D1:J1')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->setCellValue('D1', 'UNIVERSITAS BALE BANDUNG');	  
	  $objPHPExcel->getActiveSheet()->getStyle('D1')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Arial',
							'size'      => 20
						)
					)
			);
			
	  $objPHPExcel->getActiveSheet()->mergeCells('D2:J2');
	  $objPHPExcel->getActiveSheet()->getStyle('D2:J2')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('D2:J2')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->setCellValue('D2', 'Kampus : Jl. RAA. Wiranatakusumah Baleendah Telp./Fax 5940443 Bandung 40258');	  
	  $objPHPExcel->getActiveSheet()->getStyle('D2')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => false,
							'name'      => 'Arial',
							'size'      => 10
						)
					)
			);		
	  $objPHPExcel->getActiveSheet()->mergeCells('D4:J4');
	  $objPHPExcel->getActiveSheet()->getStyle('D4:J4')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('D4:J4')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 
	  
	  $objDrawing = new PHPExcel_Worksheet_Drawing(); 
	  $objDrawing->setPath('../img/logo_unibba.png');
	  $objDrawing->setHeight(100);
	  $objDrawing->setWorksheet($objPHPExcel->getActiveSheet());
	  $objDrawing->setCoordinates('A1');
	  
	  if($idx==2){
	    $objPHPExcel->getActiveSheet()->setCellValue('D4', 'KARTU UJIAN AKHIR SEMESTER');	 
	  }else{
	    $objPHPExcel->getActiveSheet()->setCellValue('D4', 'KARTU UJIAN TENGAH SEMESTER');
	  }
	  $objPHPExcel->getActiveSheet()->getStyle('D4')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Arial',
							'size'      => 16
						)
					)
			);	
      
	  $objPHPExcel->getActiveSheet()->setCellValue('A6', 'NAMA MAHASISWA'); 
	  $objPHPExcel->getActiveSheet()->mergeCells('A6:B6'); 
	  $objPHPExcel->getActiveSheet()->setCellValue('A7', 'NIM');
	  $objPHPExcel->getActiveSheet()->mergeCells('A7:B7'); 
      $objPHPExcel->getActiveSheet()->setCellValue('A8', 'FAKULTAS');
      $objPHPExcel->getActiveSheet()->mergeCells('A8:B8'); 	  
      $objPHPExcel->getActiveSheet()->setCellValue('A9', 'PRODI'); 
       $objPHPExcel->getActiveSheet()->mergeCells('A9:B9'); 	  
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('C6', ':'); 
	  $objPHPExcel->getActiveSheet()->setCellValue('C7', ':');
      $objPHPExcel->getActiveSheet()->setCellValue('C8', ':');	
      $objPHPExcel->getActiveSheet()->setCellValue('C9', ':');  
	  
	    $vdt_mhs = new dt_mhs;
		$data = $vdt_mhs->getData($vnim);
		
		if(!empty($data))
		{
		  foreach($data as $row){
		     $nmmhs = $row['nmmhsmsmhs'];
			 $objPHPExcel->getActiveSheet()->setCellValue('D6', $row['nmmhsmsmhs']); 
	         $objPHPExcel->getActiveSheet()->setCellValue('D7', $row['nimhsmsmhs']);
		     }		  
		}
	  
	  
	  
      
	  $objPHPExcel->getActiveSheet()->setCellValue('D8', 'MATEMATIKA DAN ILMU PENGETAHUAN ALAM');	
      $objPHPExcel->getActiveSheet()->setCellValue('D9', 'MATEMATIKA'); 

	  $objPHPExcel->getActiveSheet()->setCellValue('G6', 'SEMESTER'); 
	  $objPHPExcel->getActiveSheet()->setCellValue('G7', 'JENJANG');
      $objPHPExcel->getActiveSheet()->setCellValue('G8', 'JUMLAH SKS');	
      $objPHPExcel->getActiveSheet()->setCellValue('G9', 'T.A.');  
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('I6', ':'); 
	  $objPHPExcel->getActiveSheet()->setCellValue('I7', ':');
      $objPHPExcel->getActiveSheet()->setCellValue('I8', ':');	
      $objPHPExcel->getActiveSheet()->setCellValue('I9', ':'); 
      
	      $vbaca_krs = new dt_krs;
		  $thnsms = $vbaca_krs->TA();
		 
		  $data = $vbaca_krs->getMtk($thnsms,$vnim,1);
	  
	  $sem=array(1=>'Ganjil',2=>'Genap');
	  
	  $tmp = str_split($thnsms, 4);
	  
	  $thn=$tmp[0];
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('J6', $sem[$tmp[1]]); 
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('J7', 'S1');
      
	  
	  
      $objPHPExcel->getActiveSheet()->setCellValue('J9',$thn.'/'.($thn+1) ); 
      
      $objPHPExcel->getActiveSheet()->getStyle('A6:J9')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Arial',
							'size'      => 9
						)
					)
			);
       
      $objPHPExcel->getActiveSheet()->setCellValue('A10', 'NO');
      $objPHPExcel->getActiveSheet()->setCellValue('B10', 'KODE MK'); 
	  $objPHPExcel->getActiveSheet()->mergeCells('B10:C10');
      $objPHPExcel->getActiveSheet()->setCellValue('D10', 'MATAKULIAH'); 
      $objPHPExcel->getActiveSheet()->setCellValue('E10', 'SKS'); 
      $objPHPExcel->getActiveSheet()->setCellValue('F10', 'Tgl.UJIAN'); 
	  $objPHPExcel->getActiveSheet()->mergeCells('F10:G10');
      $objPHPExcel->getActiveSheet()->setCellValue('H10', 'KLS'); 
      $objPHPExcel->getActiveSheet()->setCellValue('I10', 'Paraf'); 
      $objPHPExcel->getActiveSheet()->mergeCells('I10:J10');	  
      
	  $objPHPExcel->getActiveSheet()->getStyle('A10:J10')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('A10:J10')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 
      $objPHPExcel->getActiveSheet()->getStyle('A10:J10')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Arial',
							'size'      => 10
						),
						'borders' => array(
							'inside'     => array(
								'style' => PHPExcel_Style_Border::BORDER_THIN
							),
							'outline'     => array(
								'style' => PHPExcel_Style_Border::BORDER_MEDIUM
							)
						)
					)
			);	  
	  
	  if(!empty($data)){
	     $i=11;
		 $no=1;
		 $jmlsks=0;
		 foreach($data as $row){
	        
			    if($row['sksprtbkmk']>0){
                   $sks=number_format($row['sksmktbkmk']-1, 2, '.', '');
                   $jmlsks+=$row['sksmktbkmk']-1;
				}else{
				   $sks=$row['sksmktbkmk'];
                   $jmlsks+=$row['sksmktbkmk'];				   
				}
			
			$objPHPExcel->getActiveSheet()->setCellValue('A'.$i, $no);
			$objPHPExcel->getActiveSheet()->setCellValue('B'.$i, $row['kdkmkkrs']);
			$objPHPExcel->getActiveSheet()->mergeCells('B'.$i.':C'.$i);
			$objPHPExcel->getActiveSheet()->setCellValue('D'.$i, $row['nakmktbkmk']);
			$objPHPExcel->getActiveSheet()->setCellValue('E'.$i, $sks);
			$objPHPExcel->getActiveSheet()->mergeCells('F'.$i.':G'.$i);
			$objPHPExcel->getActiveSheet()->mergeCells('I'.$i.':J'.$i);
			$no++;
			$i++;
	     }
	  }
	  $objPHPExcel->getActiveSheet()->mergeCells('B'.$i.':C'.$i);
	  $objPHPExcel->getActiveSheet()->mergeCells('F'.$i.':G'.$i);
	  $objPHPExcel->getActiveSheet()->mergeCells('I'.$i.':J'.$i);
	  
	  $objPHPExcel->getActiveSheet()->getStyle('A11:J'.($i))->applyFromArray(
					array(						
						'borders' => array(
							'inside'     => array(
								'style' => PHPExcel_Style_Border::BORDER_THIN
							),
							'outline'     => array(
								'style' => PHPExcel_Style_Border::BORDER_MEDIUM
							)
						)
					)
			);
	  $i++;
	  $objPHPExcel->getActiveSheet()->getRowDimension($i)->setRowHeight(3.75);	  
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('J8', $jmlsks);	
	  $objPHPExcel->getActiveSheet()->getStyle('J8')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_LEFT);
	  
	  $i++;
	  $tmp='="Baleendah,  " & TEXT(NOW(),"dd mmm YYYY")';
	  $objPHPExcel->getActiveSheet()->setCellValue('G'.$i, $tmp);
	  
	  $i++;
	  $objPHPExcel->getActiveSheet()->setCellValue('B'.$i, 'Ketua Panitia Ujian,');
	  $objPHPExcel->getActiveSheet()->setCellValue('G'.$i, 'Peserta Ujian,');
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('G'.($i+4), $nmmhs);
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('B'.($i+4), '                              ');
	  
	  
	  $objPHPExcel->getActiveSheet()->getStyle('A11:J'.($i))->applyFromArray(
					array(						
						'font'    => array(
							'bold'      => false,
							'name'      => 'Arial',
							'size'      => 10
						)
					)
			);
			
		$objPHPExcel->getActiveSheet()->getStyle('A'.($i+4).':J'.($i+4))->applyFromArray(
					array(						
						'font'    => array(
							'bold'      => true,
							'name'      => 'Arial',
							'size'      => 10,
							'underline' => true
						)
					)
			);	
	  
	  switch($idx){
	    case 1 : $tmp="../Admin/cetak/kartu/Kartu UTS - ".$vnim.".xls";break;
		case 2 : $tmp="../Admin/cetak/kartu/Kartu UAS - ".$vnim.".xls";break;
	  }
	  $objWriter = PHPExcel_IOFactory::createWriter($objPHPExcel, 'Excel5');
      $objWriter->save($tmp);
	  return $tmp;
	 }
	 
	 
	 function ctk_krs_toexcel($vnim,$TA){
	  $objPHPExcel = new PHPExcel();
	  $objPHPExcel->setActiveSheetIndex(0);
	  
	  $dt_krs = new dt_trnlm();
      	
	  
	  
	  
	   $objDrawing = new PHPExcel_Worksheet_Drawing();
       $objDrawing->setWorksheet($objPHPExcel->getActiveSheet());
       $objDrawing->setName("logo");
       $objDrawing->setDescription("logo fakultas");
       $objDrawing->setPath('../img/logo_fak.jpg');
       $objDrawing->setCoordinates('B1');
	   //$objDrawing->setHeight(53);
       $objDrawing->setWidth(60);
	   $objDrawing->setOffsetX(-10);
       $objDrawing->setOffsetY(0); 
	  
	  $objPHPExcel->getActiveSheet()->getColumnDimension('A')->setWidth(3.34);	  
	  $objPHPExcel->getActiveSheet()->getColumnDimension('C')->setWidth(0.92);
	  $objPHPExcel->getActiveSheet()->getColumnDimension('F')->setWidth(0.92);
	  $objPHPExcel->getActiveSheet()->getColumnDimension('H')->setWidth(11.14);
	  $objPHPExcel->getActiveSheet()->getColumnDimension('I')->setWidth(0.92);
	 

        
	  $objPHPExcel->getActiveSheet()->setCellValue('C1', 'PROGRAM STUDI MATEMATIKA');
	  $objPHPExcel->getActiveSheet()->setCellValue('C2', 'FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM');
	  $objPHPExcel->getActiveSheet()->setCellValue('C3', 'UNIVERSITAS BALE BANDUNG');
	  $objPHPExcel->getActiveSheet()->getStyle('C1:C3')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Times New Roman',
							'size'      => 10
						)
					)
			); 	 

      $objPHPExcel->getActiveSheet()->setCellValue('A5', 'KARTU RENCANA STUDI (KRS)');
	  $objPHPExcel->getActiveSheet()->mergeCells('A5:K5');
	  $objPHPExcel->getActiveSheet()->getStyle('A5:K5')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('A5:K5')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 		
	  
	  
	  $objPHPExcel->getActiveSheet()->getStyle('A5:K5')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Times New Roman',
							'size'      => 10
						)
					)
			);

      $dt_mhs = new dt_mhs;
	  $data = $dt_mhs->getData($vnim);
	  
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('A7', 'NIM');
	  $objPHPExcel->getActiveSheet()->setCellValue('A8', 'NAMA');
	  $objPHPExcel->getActiveSheet()->setCellValue('A9', 'Dosen Wali');
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('C7', ':');
	  $objPHPExcel->getActiveSheet()->setCellValue('C8', ':');
	  $objPHPExcel->getActiveSheet()->setCellValue('C9', ':');
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('D7', $vnim);
	  
	  $txt_sem = array(1=>'Ganjil',2=>'Genap');
	  foreach($data as $row)
      {
	    $objPHPExcel->getActiveSheet()->setCellValue('D8', $row['nmmhsmsmhs']);	
		
		$thn = str_split($row['smawlmsmhs'], 4);
		$objPHPExcel->getActiveSheet()->setCellValue('J7',$txt_sem[$thn[1]]." ".$thn[0]);		
		
		$thn = str_split($TA, 4);
		$objPHPExcel->getActiveSheet()->setCellValue('J8', $thn[0].'/'.($thn[0]+1));		
		$objPHPExcel->getActiveSheet()->setCellValue('J9', $txt_sem[$thn[1]]." ".$thn[0]);
	  }	  
	  	  
	  $objPHPExcel->getActiveSheet()->setCellValue('H7', 'Sem. Awal');
	  $objPHPExcel->getActiveSheet()->setCellValue('H8', 'Tahun Ajaran');
	  $objPHPExcel->getActiveSheet()->setCellValue('H9', 'Semester');
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('I7', ':');
	  $objPHPExcel->getActiveSheet()->setCellValue('I8', ':');
	  $objPHPExcel->getActiveSheet()->setCellValue('I9', ':');
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('A11', 'Matakuliah :');
	  
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('A12', 'NO');
	  $objPHPExcel->getActiveSheet()->setCellValue('B12', 'KODE');
	  $objPHPExcel->getActiveSheet()->mergeCells('B12:D12');
	  $objPHPExcel->getActiveSheet()->getStyle('B12:D12')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('B12:D12')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->setCellValue('E12', 'NAMA');
	  $objPHPExcel->getActiveSheet()->mergeCells('E12:I12');
	  $objPHPExcel->getActiveSheet()->getStyle('E12:I12')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('E12:I12')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->setCellValue('J12', 'SKS');
	  $objPHPExcel->getActiveSheet()->mergeCells('J12:K12');
	  $objPHPExcel->getActiveSheet()->getStyle('J12:K12')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('J12:K12')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 	  
	  
	  $objPHPExcel->getActiveSheet()->getStyle('A7:K12')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Calibri',
							'size'      => 9
						)
					)
			); 	  
      
      $objPHPExcel->getActiveSheet()->getStyle('A12:K12')->applyFromArray(
					array(
         					'borders' => array(
							'inside'     => array(
								'style' => PHPExcel_Style_Border::BORDER_THIN
							),
							'outline'     => array(
								'style' => PHPExcel_Style_Border::BORDER_MEDIUM
							)
						)
					)
			); 	  
	  
	  $data = $dt_krs->getMtk2($TA,$vnim,0);
	  $nbrs = 13;
	  $jml_mtk = 1;
	  $jml_sks = 0;
	  if(!empty($data)){
	     
	     foreach($data as $row){
		  
		  $objPHPExcel->getActiveSheet()->setCellValue('A'.$nbrs, $jml_mtk);
		  
           $objPHPExcel->getActiveSheet()->setCellValue('B'.$nbrs, $row['kdkmktrnlm']);
		   $objPHPExcel->getActiveSheet()->mergeCells('B'.$nbrs.':D'.$nbrs);
		   $objPHPExcel->getActiveSheet()->getStyle('B'.$nbrs.':D'.$nbrs)->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	       $objPHPExcel->getActiveSheet()->getStyle('B'.$nbrs.':D'.$nbrs)->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
		   
		   $objPHPExcel->getActiveSheet()->setCellValue('E'.$nbrs, $row['nakmktbkmk']);
		   $objPHPExcel->getActiveSheet()->mergeCells('E'.$nbrs.':I'.$nbrs);
		   
		   $objPHPExcel->getActiveSheet()->setCellValue('J'.$nbrs, $row['sksmktbkmk']);
		   $objPHPExcel->getActiveSheet()->mergeCells('J'.$nbrs.':K'.$nbrs);
		   $objPHPExcel->getActiveSheet()->getStyle('J'.$nbrs.':K'.$nbrs)->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	       $objPHPExcel->getActiveSheet()->getStyle('J'.$nbrs.':K'.$nbrs)->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
		   
		   $jml_sks+=$row['sksmktbkmk'];
		   
		  $nbrs++;
		  $jml_mtk++;			
		 }
	  
	     
	  
	  }	  
	  
	  $objPHPExcel->getActiveSheet()->getStyle('A13:K'.$nbrs)->applyFromArray(
					array(
						'font'    => array(
							'bold'      => false,
							'name'      => 'Calibri',
							'size'      => 9
						)
					)
			); 
	  
	  $objPHPExcel->getActiveSheet()->mergeCells('B'.$nbrs.':D'.$nbrs);
      $objPHPExcel->getActiveSheet()->mergeCells('E'.$nbrs.':I'.$nbrs);	 
	  $objPHPExcel->getActiveSheet()->mergeCells('J'.$nbrs.':K'.$nbrs);
	  
	  $objPHPExcel->getActiveSheet()->getStyle('A13:K'.($nbrs+1))->applyFromArray(
					array(
         					'borders' => array(
							'inside'     => array(
								'style' => PHPExcel_Style_Border::BORDER_THIN
							),
							'outline'     => array(
								'style' => PHPExcel_Style_Border::BORDER_MEDIUM
							)
						)
					)
			); 
	  
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('A'.($nbrs+1), 'Jumlah');
	  $objPHPExcel->getActiveSheet()->mergeCells('A'.($nbrs+1).':I'.($nbrs+1));
	  $objPHPExcel->getActiveSheet()->getStyle('A'.($nbrs+1).':I'.($nbrs+1))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('A'.($nbrs+1).':I'.($nbrs+1))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
		   
	  $objPHPExcel->getActiveSheet()->setCellValue('J'.($nbrs+1), $jml_sks);
	  $objPHPExcel->getActiveSheet()->mergeCells('J'.($nbrs+1).':K'.($nbrs+1));
	  $objPHPExcel->getActiveSheet()->getStyle('J'.($nbrs+1).':K'.($nbrs+1))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('J'.($nbrs+1).':K'.($nbrs+1))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
		   
	  
	  $objPHPExcel->getActiveSheet()->getStyle('A'.($nbrs+1).':K'.($nbrs+1))->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Calibri',
							'size'      => 9
						),
						'borders' => array(
							'inside'     => array(
								'style' => PHPExcel_Style_Border::BORDER_THIN
							),
							'outline'     => array(
								'style' => PHPExcel_Style_Border::BORDER_MEDIUM
							)
						)
					)
			); 
			
	  
	  $nbrs+=3;
	  $objPHPExcel->getActiveSheet()->setCellValue('A'.$nbrs, 'Praktikum :');
	  $nbrs+=1;
	  $objPHPExcel->getActiveSheet()->setCellValue('A'.$nbrs, 'NO');
	  $objPHPExcel->getActiveSheet()->setCellValue('B'.$nbrs, 'KODE');
	  $objPHPExcel->getActiveSheet()->mergeCells('B'.$nbrs.':D'.$nbrs);
	  $objPHPExcel->getActiveSheet()->getStyle('B'.$nbrs.':D'.$nbrs)->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('B'.$nbrs.':D'.$nbrs)->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->setCellValue('E'.$nbrs, 'NAMA');
	  $objPHPExcel->getActiveSheet()->mergeCells('E'.$nbrs.':I'.$nbrs);
	  $objPHPExcel->getActiveSheet()->getStyle('E'.$nbrs.':I'.$nbrs)->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('E'.$nbrs.':I'.$nbrs)->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 
	   
	  $objPHPExcel->getActiveSheet()->getStyle('A'.($nbrs-1).':I'.$nbrs)->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Calibri',
							'size'      => 9
						)
					)
			); 	 
      
       $objPHPExcel->getActiveSheet()->getStyle('A'.$nbrs.':I'.$nbrs)->applyFromArray(
					array(
         					'borders' => array(
							'inside'     => array(
								'style' => PHPExcel_Style_Border::BORDER_THIN
							),
							'outline'     => array(
								'style' => PHPExcel_Style_Border::BORDER_MEDIUM
							)
						)
					)
			); 	

      $data = $dt_krs->getMtk2($TA,$vnim,1);
	  $nbrs+=1;
	  $jml_mtk = 1;
	  
	  if(!empty($data)){
	     
	     foreach($data as $row){
		 $kd = str_split($row['kdkmktrnlm'],4); 
		 if($kd[0]=='MATP'){ 
		   $objPHPExcel->getActiveSheet()->setCellValue('A'.$nbrs, $jml_mtk);
		  
           $objPHPExcel->getActiveSheet()->setCellValue('B'.$nbrs, $row['kdkmktrnlm']);
		   $objPHPExcel->getActiveSheet()->mergeCells('B'.$nbrs.':D'.$nbrs);
		   $objPHPExcel->getActiveSheet()->getStyle('B'.$nbrs.':D'.$nbrs)->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	       $objPHPExcel->getActiveSheet()->getStyle('B'.$nbrs.':D'.$nbrs)->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
		   
		   $objPHPExcel->getActiveSheet()->setCellValue('E'.$nbrs, $row['nakmktbkmk']);
		   $objPHPExcel->getActiveSheet()->mergeCells('E'.$nbrs.':I'.$nbrs);   
		   
		   
		    $nbrs++;
		    $jml_mtk++;
          } 		  
		 }
	  
	     
	  
	  }	  	  

      $objPHPExcel->getActiveSheet()->mergeCells('B'.$nbrs.':D'.$nbrs);
      $objPHPExcel->getActiveSheet()->mergeCells('E'.$nbrs.':I'.$nbrs);	 
	  
	  
	  $objPHPExcel->getActiveSheet()->getStyle('A'.($nbrs-($jml_mtk-1)).':I'.($nbrs))->applyFromArray(
					array(
         					'font'    => array(
							'bold'      => false,
							'name'      => 'Calibri',
							'size'      => 9
						),
							'borders' => array(
							'inside'     => array(
								'style' => PHPExcel_Style_Border::BORDER_THIN
							),
							'outline'     => array(
								'style' => PHPExcel_Style_Border::BORDER_MEDIUM
							)
						)
					)
			); 
	 	  
	  $nbrs+=2;
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('B'.$nbrs, 'MAHASISWA');
	  $objPHPExcel->getActiveSheet()->mergeCells('B'.$nbrs.':D'.$nbrs);
	  $objPHPExcel->getActiveSheet()->getStyle('B'.$nbrs.':D'.$nbrs)->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('B'.$nbrs.':D'.$nbrs)->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
		   
	  $objPHPExcel->getActiveSheet()->setCellValue('e'.$nbrs, 'DOSEN WALI');
      $objPHPExcel->getActiveSheet()->mergeCells('E'.$nbrs.':G'.$nbrs);
	  $objPHPExcel->getActiveSheet()->getStyle('E'.$nbrs.':G'.$nbrs)->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('E'.$nbrs.':G'.$nbrs)->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
		
       $objPHPExcel->getActiveSheet()->getStyle('B'.$nbrs.':G'.$nbrs)->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Calibri',
							'size'      => 9
						)
					)
			); 	 
      
	  $objPHPExcel->getActiveSheet()->mergeCells('B'.($nbrs+1).':D'.($nbrs+2));
	  $objPHPExcel->getActiveSheet()->mergeCells('E'.($nbrs+1).':G'.($nbrs+2));
	  
       $objPHPExcel->getActiveSheet()->getStyle('B'.$nbrs.':G'.($nbrs+2))->applyFromArray(
					array(
         					'borders' => array(
							'inside'     => array(
								'style' => PHPExcel_Style_Border::BORDER_THIN
							),
							'outline'     => array(
								'style' => PHPExcel_Style_Border::BORDER_MEDIUM
							)
						)
					)
			); 

     	 		
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('A'.($nbrs+4), 'Dicetak dari Sistem Informasi Akademik FMIPA UNIBBA pada tanggal : '.date("d-m-Y H:i:s"));
	  
	  $objPHPExcel->getActiveSheet()->getStyle('A'.($nbrs+4))->applyFromArray(
					array(
						'font'    => array(
							'bold'      => false,
							'name'      => 'Calibri',
							'size'      => 9
						)
					)
			); 
	
	  $tmp = "../Admin/cetak/kartu/KRS - ".$vnim." - ".$TA.".xls";
	  $objWriter = PHPExcel_IOFactory::createWriter($objPHPExcel, 'Excel5');
      $objWriter->save($tmp);
	  return $tmp;
	 
	 }
	 
	 
	 function ctk_krs_topdf($vnim,$TA){
	   
	   
	   $dt_krs = new dt_trnlm();
       
	   
	   
	   $tbl4 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_jdl",'cellpadding'=>'2'));
	   
	   $tbl4->addRow();		  
		  $tbl4->addCell('<img src="../img/logo_fak.jpg" alt="logo" width="55" height="55">','data');
          $tbl4->addCell('<font face="Times New Roman" size="10pt">'.
	                     '<b>PROGRAM STUDI MATEMATIKA<br>'.
				             'FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM<br>'.
					         'UNIVERSITAS BALE BANDUNG'.
				         '</b>'.
			             '</font>',null,'data');
	   
	   $jdl = $tbl4->display().			  
			  '<br><br>'.
	          '<center>'.
			            '<font face="Times New Roman" size="10pt">'.
						       '<b>KARTU RENCANA STUDI (KRS)</b>'.
					    '</font>'.
			  '</center><br><br>';
	
       $dt_mhs = new dt_mhs;
	   $data = $dt_mhs->getData($vnim);
	
	  $txt_sem = array(1=>'Ganjil',2=>'Genap');
	  foreach($data as $row)
      {  
	   $tbl2 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_mhs","width"=>"100%"));       
	   $tbl2->addRow();		  
		  $tbl2->addCell('NIM','data');
          $tbl2->addCell(':',null,'data');
		  $tbl2->addCell($vnim,null,'data');
		  $tbl2->addCell('Sem. Awal','data');
          $tbl2->addCell(':',null,'data');
		  $thn = str_split($row['smawlmsmhs'], 4);
		  $tbl2->addCell($txt_sem[$thn[1]]." ".$thn[0],null,'data');
	   $tbl2->addRow();		  
		  $tbl2->addCell('Nama','data');
          $tbl2->addCell(':',null,'data');
		  $tbl2->addCell($row['nmmhsmsmhs'],null,'data');
		  $tbl2->addCell('Tahun Ajaran','data');
          $tbl2->addCell(':',null,'data');
		  $thn = str_split($TA, 4);
		  $tbl2->addCell( $thn[0].'/'.($thn[0]+1),null,'data');	  
	   $tbl2->addRow();		  
		  $tbl2->addCell('Dosen Wali','data');
          $tbl2->addCell(':',null,'data');
		  $tbl2->addCell('',null,'data');
		  $tbl2->addCell('Semester','data');
          $tbl2->addCell(':',null,'data');
		  $tbl2->addCell( $txt_sem[$thn[1]]." ".$thn[0],null,'data');
	  }
	  
	 
	  
       $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_mtk","width"=>"100%",'border'=>'1','cellpadding'=>'2'));
	   
	   $tbl->addRow(); 
	   $tbl->addCell('NO',null,'header',array('width'=>'5%'));
	   $tbl->addCell('KODE',null,'header',array('width'=>'15%'));	  
	   $tbl->addCell('NAMA',null,'header',array('width'=>'70%'));	 
	   $tbl->addCell('SKS',null,'header',array('width'=>'10%'));
	   
	  $data = $dt_krs->getMtk2($TA,$vnim,0);
	  
	  $jml_mtk = 1;
	  $jml_sks = 0.00;
	  if(!empty($data)){
	     
	     foreach($data as $row){
		  $tbl->addRow();
		  
		  $tbl->addCell($jml_mtk,null,'data',array('align'=>'right'));
          $tbl->addCell($row['kdkmktrnlm'],null,'data',array('align'=>'center'));
		  $tbl->addCell($row['nakmktbkmk'],null,'data',array('align'=>'left'));
		  $tbl->addCell($row['sksmktbkmk'],null,'data',array('align'=>'center'));
		   
		  $jml_sks+=$row['sksmktbkmk'];  
		  $jml_mtk++;			
		 }  
	  }	
	      $tbl->addRow();		  
		  $tbl->addCell('',null,'data',array('align'=>'right','height'=>'18px'));
          $tbl->addCell('',null,'data',array('align'=>'center','height'=>'18px'));
		  $tbl->addCell('',null,'data',array('align'=>'left','height'=>'18px'));
		  $tbl->addCell('',null,'data',array('align'=>'center','height'=>'18px'));
		  
		  $tbl->addRow();
		  $tbl->addCell('Jumlah',null,'data',array('colspan'=>'3','align'=>'center'));
		  $tbl->addCell($jml_sks,null,'data',array('align'=>'center'));
		  
	   $tbl1 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_prak",'border'=>'1','width'=>'90%','cellpadding'=>'2'));
	   
	   $tbl1->addRow(); 
	   $tbl1->addCell('NO',null,'header',array('width'=>'5%'));
	   $tbl1->addCell('KODE',null,'header',array('width'=>'15%'));	  
	   $tbl1->addCell('NAMA',null,'header',array('width'=>'70%'));	 
	   

	  $data = $dt_krs->getMtk2($TA,$vnim,1);
      
	  $jml_mtk = 1;
	  
	  if(!empty($data)){
	     
	     foreach($data as $row){
		   $kd = str_split($row['kdkmktrnlm'],4); 
		    if($kd[0]=='MATP'){  
		       $tbl1->addRow();
		       $tbl1->addCell($jml_mtk,null,'data',array('align'=>'right'));
               $tbl1->addCell($row['kdkmktrnlm'],null,'data',array('align'=>'center'));
		       $tbl1->addCell($row['nakmktbkmk'],null,'data',array('align'=>'left'));
		      $jml_mtk++;
            }  		  
		 }  
	  }		   
	   
	    $tbl1->addRow();
		$tbl1->addCell('',null,'data',array('align'=>'right','height'=>'18px'));
        $tbl1->addCell('',null,'data',array('align'=>'center','height'=>'18px'));
		$tbl1->addCell('',null,'data',array('align'=>'left','height'=>'18px'));
	   
	   $tbl3 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_ttd",'border'=>'1','width'=>'60%','cellpadding'=>'2'));
	   
	   $tbl3->addRow(); 
	   $tbl3->addCell('MAHASISWA',null,'header',array('width'=>'50%'));
	   $tbl3->addCell('DOSEN WALI',null,'header',array('width'=>'50%'));	  
	   $tbl3->addRow(); 
	   $tbl3->addCell(' ',null,'data',array('height'=>'50px'));
	   $tbl3->addCell(' ',null,'data',array('height'=>'50px'));
	   
	   
	   $html =
            '<html>'.
			'<style type="text/css">'.
			'table{font-family: Calibri; font-size: 9pt;}'.
			'</style>'.
			'<body>'.
			 $jdl.$tbl2->display().             
			'<br>Matakuliah : <br>'.$tbl->display().
			'<br>Praktikum : <br>'.$tbl1->display().
			'<br><br>'.$tbl3->display().
			'<br><br>'.'<font face="Calibri" size="9pt">Dicetak dari Sistem Informasi Akademik FMIPA UNIBBA pada tanggal '.date("d-m-Y H:i:s").'</font>'.
            '</body>'.
			'</html>';          
		  
		  $tmp = "../Admin/cetak/kartu/KRS - ".$vnim." - ".$TA.".pdf";
          
		  $dompdf = new DOMPDF();
          $dompdf->load_html($html);
          $dompdf->set_paper('a4', 'portrait');
		  $dompdf->render();
          $output = $dompdf->output();
          file_put_contents($tmp, $output);   
	   
	   return $tmp;
	 }
	 
    }
?>