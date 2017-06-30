<?php
  
	 require_once 'shared.php';
	 
	 class vwriwayat 
	{
      var $vriwayat;
	  function __construct(){
	   	  $this->vriwayat=new dt_riwayat;   	   
	    }
	  
	  function dsn_filter($idx=1)
	  {
	      $html_txt="<fieldset>";
	      $html_txt.="<legend>Filter</legend>";
		  
           $vdosen = new dt_dosen;
		   $data = $vdosen->getAllData("Kode != '?????'");
		   $vtemp= "";
		   $vkode="";
		   foreach($data as $row){	
                 if(empty($vtemp)){
					$vtemp = $row['Kode']." - ".$row['Nama'];
					$vkode = $row['Kode'];
				 }	
                              
            $dsn[$row['Kode']]=$row['Kode']." - ".$row['Nama'] ;
           }

		  
		  $frm = new HTML_Form();
	      $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmfilter"));
	      $tbl->addRow();
	      $tbl->addCell('Nama Dosen '.$frm->addSelectList("Kode",$dsn,true,null,null,array('id'=>'Kode')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')), null, 'data');
	   
	      $html_txt.=$tbl->display()."</fieldset>";

          $html_txt.="<fieldset>";
	      $html_txt.="<legend  id='hsl_filter'> Hasil Filter : ".$vtemp."</legend>";
      	  
	      $html_txt.="<div id='data'>";
	      $html_txt.=$this->buildriwayat($vkode,$idx);
	      $html_txt.="</div>";
	  
	      $html_txt.="</fieldset>";
        	  
	      return $html_txt;
	  
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
	  
	    function buildriwayat($vkode,$idx=1){
	          
			  $hak=1;
			  if($idx==1)
			  {
			    $user = $_SESSION['user'];
	            	         
		        $dtuser = new dt_user;
                $hak = $dtuser->gethak($user);
			  }
			  
			  
			  $this->vriwayat->buildsem($vkode);
	          
			  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_riwayat"));
	          $tbl->addRow();
			  $tbl->addCell("TA", null, 'header');
	          $tbl->addCell("Kode", null, 'header');
			  $tbl->addCell("Matakuliah", null, 'header'); 
			  $tbl->addCell("Angkatan", null, 'header');
	          $tbl->addCell("Kelas", null, 'header');
			  $tbl->addCell("Jml. Mhs.", null, 'header');
			  $tbl->addCell("Jml. N. T", null, 'header');
	          $tbl->addCell("Aksi", null, 'header');
			  //$tbl->addCell("Aksi2", null, 'header');
			 
		   for($i = 0; $i < count($this->vriwayat->vthsms_txt); $i++){
		       
			  $data = $this->vriwayat->buildriwayat($vkode,$this->vriwayat->vthsms[$i]);
				 foreach($data as $row){
				 
				    $tbl->addRow();
										
					  $hsl= $this->vriwayat->detailriwayat($this->vriwayat->vthsms[$i],$row['kdkmkpengajar'],$row['shiftpengajar'],$row['kelaspengajar'],$row['semespengajar']);
					  
					  $link="../global_code/frm_lht_nilai.php?thnsms=".$this->vriwayat->vthsms[$i]."&kdkmk=".$row['kdkmkpengajar']."&kelas=".$row['shiftpengajar']."&kelas1=".$row['kelaspengajar']."&sem=".$row['semespengajar'];
					  $link1="../global_code/frm_entry_nilai.php?thnsms=".$this->vriwayat->vthsms[$i]."&kdkmk=".$row['kdkmkpengajar']."&kelas=".$row['shiftpengajar']."&idx=".$idx."&kelas1=".$row['kelaspengajar']."&sem=".$row['semespengajar'];
                      $link2='javascript:ctk_excel(21,"'.$row['semespengajar'].'","'.$row['shiftpengajar'].'","'.$row['kdkmkpengajar'].'","'.$row['nakmktbkmk'].'","'.$vkode.'",'.$this->vriwayat->vthsms[$i].')';
					  $link3='javascript:ctk_excel(22,"'.$row['semespengajar'].'","'.$row['shiftpengajar'].'","'.$row['kdkmkpengajar'].'","'.$row['nakmktbkmk'].'","'.$vkode.'",'.$this->vriwayat->vthsms[$i].')';
					 					  
                      $tbl->addCell($this->vriwayat->vthsms[$i], null, 'data');					  
					  $tbl->addCell($this->ismrhitl($row['wp'],$row['kdkmkpengajar']), null, 'data');
					  $tbl->addCell($this->ismrhitl($row['wp'],$row['nakmktbkmk']), null, 'data');
					  $tbl->addCell($hsl['thnsms'], null, 'data');				
                      $tbl->addCell($row['shiftpengajar']=='R' ? 'Reguler' : 'Non Reguler', null, 'data');
	                  $tbl->addCell($hsl['jml_mhs'], null, 'data');
					  $tbl->addCell($hsl['jml_T'], null, 'data');  
					  
					  
					  $tbl->addCell( $hsl['jml_mhs']!=0 ? "<a href='$link'>Lihat Nilai</a><br><a href='".($hak==1?$link1:'')."'>Edit Nilai</a><br><a href='$link2'>DHMD</a><br><a href='$link3'>DPNA</a>" : 'Lihat Nilai<br>Edit Nilai<br>DHMD<br>DPNA', null, 'data');
					  
					  
					  //$tbl->addCell( $hsl['jml_mhs']!=0 ? "<a href='$link1'>Edit Nilai</a>" : 'Edit Nilai', null, 'data');	
						
				 }
              
			  	   
			   
		   }
		      
		   return $tbl->display();
	    }
		
		function ctk_DHMD($data,$thnsms)
		{
		  
		  
		  $objPHPExcel = new PHPExcel();
		  $objPHPExcel->setActiveSheetIndex(0);
		  
		  
		  $vdosen = new dt_dosen;
		  $nads = $vdosen->getnmdsn1($data['kdds']);
		  
		  $mk=$data['kdkmk']." - ".$data['nakmk'];
		  $ds=$data['kdds']." - ".$nads;
		  
		  
		  
		   $objPHPExcel->getActiveSheet()->getColumnDimension('A')->setWidth(4.29);
		   $objPHPExcel->getActiveSheet()->getColumnDimension('B')->setWidth(7.57);
		   $objPHPExcel->getActiveSheet()->getColumnDimension('C')->setWidth(7.57);
		   $objPHPExcel->getActiveSheet()->getColumnDimension('D')->setWidth(7.57);
		   $objPHPExcel->getActiveSheet()->getColumnDimension('E')->setWidth(0.92);

		   $objPHPExcel->getActiveSheet()->getColumnDimension('F')->setWidth(7.57);
		   $objPHPExcel->getActiveSheet()->getColumnDimension('G')->setWidth(7.57);
		   $objPHPExcel->getActiveSheet()->getColumnDimension('H')->setWidth(7.57);
		   $objPHPExcel->getActiveSheet()->getColumnDimension('I')->setWidth(7.57);

		   $objPHPExcel->getActiveSheet()->getColumnDimension('J')->setWidth(2.57);
		   $objPHPExcel->getActiveSheet()->getColumnDimension('K')->setWidth(16);
		   $objPHPExcel->getActiveSheet()->getColumnDimension('L')->setWidth(2.57);
		   $objPHPExcel->getActiveSheet()->getColumnDimension('M')->setWidth(16);
		  
		  $objPHPExcel->getActiveSheet()->setCellValue('A1', 'PROGRAM STUDI MATEMATIKA');
		  $objPHPExcel->getActiveSheet()->setCellValue('A2', 'FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM');
		  $objPHPExcel->getActiveSheet()->setCellValue('A3', 'UNIVERSITAS BALE BANDUNG');
		  $objPHPExcel->getActiveSheet()->getStyle('A1:A3')->applyFromArray(
						array(
							'font'    => array(
								'bold'      => true,
								'name'      => 'Times New Roman',
								'size'      => 10
							)
						)
				);
		  
		  $objPHPExcel->getActiveSheet()->setCellValue('A6', 'DAFTAR HADIR KULIAH');
		  $objPHPExcel->getActiveSheet()->mergeCells('A6:M6');
		  $objPHPExcel->getActiveSheet()->getStyle('A6:M6')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
		  $objPHPExcel->getActiveSheet()->getStyle('A6:M6')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 		
		  
		  $objPHPExcel->getActiveSheet()->getStyle('A6:M6')->applyFromArray(
						array(
							'font'    => array(
								'bold'      => true,
								'name'      => 'Times New Roman',
								'size'      => 12
							)
						)
				);		
		  
		  $objPHPExcel->getActiveSheet()->setCellValue('A8', 'MATA KULIAH');
		  $objPHPExcel->getActiveSheet()->setCellValue('A9', 'DOSEN');
		  $objPHPExcel->getActiveSheet()->setCellValue('A10', 'Semester / Tahun Akademik');
		  $objPHPExcel->getActiveSheet()->setCellValue('A11', 'Kelas');
		  
		   
		   $tmp = str_split($thnsms, 4);	  
		   $thn=$tmp[0];
		  
		  $objPHPExcel->getActiveSheet()->setCellValue('E8',  ': ');
		  $objPHPExcel->getActiveSheet()->setCellValue('E9', ': ');
		  $objPHPExcel->getActiveSheet()->setCellValue('E10', ': ');
		  $objPHPExcel->getActiveSheet()->setCellValue('E11', ': ');
		  
		  $objPHPExcel->getActiveSheet()->setCellValue('F8',  $mk);
		  $objPHPExcel->getActiveSheet()->setCellValue('F9', $ds);
		  $objPHPExcel->getActiveSheet()->setCellValue('F10', $data['sem'].'/'.$thn.'-'.($thn+1));
		  
		  if($data['kls']=='R'){
			$tmp_shift='Reguler';
		  }else{
			$tmp_shift='Non Reguler';
		  }
		  
		  
		  $objPHPExcel->getActiveSheet()->setCellValue('F11', $tmp_shift);
		  
		  
		  $objPHPExcel->getActiveSheet()->getStyle('A8:F11')->applyFromArray(
						array(
							'font'    => array(
								'bold'      => true,
								'name'      => 'Times New Roman',
								'size'      => 10
							)
						)
				);
		  
		  
		  $objPHPExcel->getActiveSheet()->setCellValue('A13',  'NO');
		  $objPHPExcel->getActiveSheet()->setCellValue('B13', 'NIM');
		  $objPHPExcel->getActiveSheet()->mergeCells('B13:E13');
		  $objPHPExcel->getActiveSheet()->getStyle('B13:E13')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
		  $objPHPExcel->getActiveSheet()->getStyle('B13:E13')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
		  $objPHPExcel->getActiveSheet()->setCellValue('F13', 'NAMA');
		  $objPHPExcel->getActiveSheet()->mergeCells('F13:I13');
		  $objPHPExcel->getActiveSheet()->getStyle('F13:I13')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
		  $objPHPExcel->getActiveSheet()->getStyle('F13:I13')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
		  $objPHPExcel->getActiveSheet()->setCellValue('J13', 'TANDA TANGAN');
		  $objPHPExcel->getActiveSheet()->mergeCells('J13:M13');
		  $objPHPExcel->getActiveSheet()->getStyle('J13:M13')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
		  $objPHPExcel->getActiveSheet()->getStyle('J13:M13')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
		  
		  $objPHPExcel->getActiveSheet()->getStyle('A13:M13')->applyFromArray(
						array(
							'font'    => array(
								'bold'      => true,
								'name'      => 'Times New Roman',
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
		  
		  
		 
		  
		  $data = $this->vriwayat->getMhs($thnsms,$data['kdkmk'],$data['kls'],$data['sem']);
		  
		  if(!empty($data)){
			$i=1; 
			foreach($data as $row){
			  $objPHPExcel->getActiveSheet()->setCellValue('A'.(13+$i), $i);
			  $objPHPExcel->getActiveSheet()->getStyle('A'.(13+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
			  $objPHPExcel->getActiveSheet()->getStyle('A'.(13+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
			  
			  $objPHPExcel->getActiveSheet()->setCellValue('B'.(13+$i), $row['nimhstrnlm']);
			  $objPHPExcel->getActiveSheet()->mergeCells('B'.(13+$i).':'.'E'.(13+$i));
			  $objPHPExcel->getActiveSheet()->setCellValue('F'.(13+$i), $row['nmmhsmsmhs']);
			  $objPHPExcel->getActiveSheet()->mergeCells('F'.(13+$i).':'.'I'.(13+$i));
			  
			  if(($i%2)!=0){
				 $objPHPExcel->getActiveSheet()->setCellValue('J'.(13+$i), $i);
				 $objPHPExcel->getActiveSheet()->mergeCells('J'.(13+$i).':'.'K'.(13+($i+1)));
				 $objPHPExcel->getActiveSheet()->getStyle('J'.(13+$i).':'.'K'.(13+($i+1)))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_LEFT); 
				 $objPHPExcel->getActiveSheet()->getStyle('J'.(13+$i).':'.'K'.(13+($i+1)))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_TOP);
				 $objPHPExcel->getActiveSheet()->setCellValue('L'.(13+$i), $i+1);
				 $objPHPExcel->getActiveSheet()->mergeCells('L'.(13+$i).':'.'M'.(13+($i+1)));	
				 $objPHPExcel->getActiveSheet()->getStyle('L'.(13+$i).':'.'M'.(13+($i+1)))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_LEFT); 
				 $objPHPExcel->getActiveSheet()->getStyle('L'.(13+$i).':'.'M'.(13+($i+1)))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_TOP);			 
			  }
			  
			  
			  $i++;
			}		
		  }
		  
		   if(($i%2)==0){
			 $objPHPExcel->getActiveSheet()->mergeCells('B'.(13+$i).':'.'E'.(13+$i));
			 $objPHPExcel->getActiveSheet()->mergeCells('F'.(13+$i).':'.'I'.(13+$i));
		   }else{
			 $i--;
		   }
		   
		   
		   
		  $objPHPExcel->getActiveSheet()->getStyle('A14:M'.(13+$i))->applyFromArray(
						array(
							'font'    => array(
								'bold'      => false,
								'name'      => 'Times New Roman',
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
				
			$i+=2;
			$j=$i;
			
			$objPHPExcel->getActiveSheet()->setCellValue('A'.(13+$i), 'Jadwal Kuliah'); 
			$objPHPExcel->getActiveSheet()->mergeCells('A'.(13+$i).':'.'D'.(13+$i));		
			$objPHPExcel->getActiveSheet()->setCellValue('F'.(13+$i), 'Jadwal Pengganti'); 
			$objPHPExcel->getActiveSheet()->mergeCells('F'.(13+$i).':'.'I'.(13+$i));
			$objPHPExcel->getActiveSheet()->setCellValue('K'.(13+$i), 'Pertemuan Ke'); 
			$objPHPExcel->getActiveSheet()->mergeCells('K'.(13+$i).':'.'L'.(13+$i));
			
			$i++;
			
			$objPHPExcel->getActiveSheet()->setCellValue('A'.(13+$i), 'Tanggal'); 
			$objPHPExcel->getActiveSheet()->mergeCells('A'.(13+$i).':'.'B'.(13+$i));
			$objPHPExcel->getActiveSheet()->setCellValue('C'.(13+$i), 'Mulai'); 
			$objPHPExcel->getActiveSheet()->setCellValue('D'.(13+$i), 'Selesai'); 
			
			$objPHPExcel->getActiveSheet()->setCellValue('F'.(13+$i), 'Tanggal'); 
			$objPHPExcel->getActiveSheet()->mergeCells('F'.(13+$i).':'.'G'.(13+$i));
			$objPHPExcel->getActiveSheet()->setCellValue('H'.(13+$i), 'Mulai'); 
			$objPHPExcel->getActiveSheet()->setCellValue('I'.(13+$i), 'Selesai'); 
			
			$objPHPExcel->getActiveSheet()->setCellValue('K'.(13+$i), '1');
			$objPHPExcel->getActiveSheet()->mergeCells('K'.(13+$i).':'.'L'.(13+($i+1)));
			
			$i++;
			
			$objPHPExcel->getActiveSheet()->setCellValue('A'.(13+$i), '... / ... / ...'); 
			$objPHPExcel->getActiveSheet()->mergeCells('A'.(13+$i).':'.'B'.(13+$i));
			$objPHPExcel->getActiveSheet()->setCellValue('C'.(13+$i), '.... : ....'); 
			$objPHPExcel->getActiveSheet()->setCellValue('D'.(13+$i), '.... : ....'); 
			
			$objPHPExcel->getActiveSheet()->setCellValue('F'.(13+$i), '... / ... / ...'); 
			$objPHPExcel->getActiveSheet()->mergeCells('F'.(13+$i).':'.'G'.(13+$i));
			$objPHPExcel->getActiveSheet()->setCellValue('H'.(13+$i), '.... : ....'); 
			$objPHPExcel->getActiveSheet()->setCellValue('I'.(13+$i), '.... : ....'); 
			
			
			
			$objPHPExcel->getActiveSheet()->getStyle('A'.(13+$j).':'.'D'.(13+($i)))->applyFromArray(
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
				
			$objPHPExcel->getActiveSheet()->getStyle('F'.(13+$j).':'.'I'.(13+($i)))->applyFromArray(
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
			
			$objPHPExcel->getActiveSheet()->getStyle('K'.(13+$j).':'.'L'.(13+($i)))->applyFromArray(
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

			$objPHPExcel->getActiveSheet()->getStyle('A'.(13+$j).':'.'M'.(13+($i)))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
			$objPHPExcel->getActiveSheet()->getStyle('A'.(13+$j).':'.'M'.(13+($i)))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 		
			
			
			
			$objPHPExcel->getActiveSheet()->getStyle('A'.(13+$j).':'.'M'.(13+($i)))->applyFromArray(
						array(
							'font'    => array(
								'bold'      => true,
								'name'      => 'Times New Roman',
								'size'      => 11
							)
						)
				);	  
		  
			 $objPHPExcel->getActiveSheet()->getStyle('K'.(13+($j+1)).':'.'L'.(13+($i-1)))->applyFromArray(
						array(
							'font'    => array(
								'bold'      => true,
								'name'      => 'Times New Roman',
								'size'      => 18
							)
						)
				);	  
		  
		  $i+=1;
		  $j=$i;
		  
		  $objPHPExcel->getActiveSheet()->setCellValue('G'.(13+$i), 'Tanda Tangan'); 
		  $objPHPExcel->getActiveSheet()->mergeCells('G'.(13+$i).':'.'M'.(13+$i));	
		  
		  $i++;
		  
		  $objPHPExcel->getActiveSheet()->setCellValue('G'.(13+$i), 'Tata Usaha'); 
		  $objPHPExcel->getActiveSheet()->mergeCells('G'.(13+$i).':'.'I'.(13+$i));
		  $objPHPExcel->getActiveSheet()->setCellValue('J'.(13+$i), 'Dosen'); 
		  $objPHPExcel->getActiveSheet()->mergeCells('J'.(13+$i).':'.'K'.(13+$i));
		  $objPHPExcel->getActiveSheet()->setCellValue('L'.(13+$i), 'Mahasiswa'); 
		  $objPHPExcel->getActiveSheet()->mergeCells('L'.(13+$i).':'.'M'.(13+$i));
		  
		   $objPHPExcel->getActiveSheet()->getStyle('A'.(13+$j).':'.'M'.(13+($i)))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
		   $objPHPExcel->getActiveSheet()->getStyle('A'.(13+$j).':'.'M'.(13+($i)))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 		
				
		  $i++;
			
		  $objPHPExcel->getActiveSheet()->setCellValue('G'.(13+$i), '( .............................. )'); 
		  $objPHPExcel->getActiveSheet()->mergeCells('G'.(13+$i).':'.'I'.(13+($i+4)));
		  $objPHPExcel->getActiveSheet()->setCellValue('J'.(13+$i), '( ........................... )'); 
		  $objPHPExcel->getActiveSheet()->mergeCells('J'.(13+$i).':'.'K'.(13+($i+4)));
		  $objPHPExcel->getActiveSheet()->setCellValue('L'.(13+$i), '( ........................... )'); 
		  $objPHPExcel->getActiveSheet()->mergeCells('L'.(13+$i).':'.'M'.(13+($i+4)));
		
		  $objPHPExcel->getActiveSheet()->getStyle('G'.(13+$j).':'.'M'.(13+($i+4)))->applyFromArray(
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
		
		
			$objPHPExcel->getActiveSheet()->getStyle('A'.(13+$j).':'.'M'.(13+($i)))->applyFromArray(
						array(
							'font'    => array(
								'bold'      => true,
								'name'      => 'Times New Roman',
								'size'      => 11
							)
						)
				);	  
		  
		  $i+=6;
		  $j=$i;
		  
		  $objPHPExcel->getActiveSheet()->setCellValue('A'.(13+$i),'Pemberitahuan :');
		  $i++;
		  $objPHPExcel->getActiveSheet()->setCellValue('A'.(13+$i),'1. Jika nama anda tidak tercantum mohon segera lapor ke TU FMIPA');
		  $i++;
		  $objPHPExcel->getActiveSheet()->setCellValue('A'.(13+$i),'2. Serahkan kembali daftar hadir ini ke TU FMIPA');
		  $i++;
		  $objPHPExcel->getActiveSheet()->setCellValue('A'.(13+$i),'3. Mahasiswa yang tidak tercantum tidak berhak mengikuti perkuliahan');
		  
		  $objPHPExcel->getActiveSheet()->getStyle('A'.(13+$j).':'.'M'.(13+($i)))->applyFromArray(
						array(
							'font'    => array(
								'bold'      => false,
								'name'      => 'Times New Roman',
								'size'      => 11
							)
						)
				);	  
		  
		  
		  $objPHPExcel->getActiveSheet()->getPageSetup()->setOrientation(PHPExcel_Worksheet_PageSetup::ORIENTATION_LANDSCAPE);
		  $objPHPExcel->getActiveSheet()->getPageSetup()->setPaperSize(PHPExcel_Worksheet_PageSetup::PAPERSIZE_A4);
		  $objPHPExcel->getActiveSheet()->getPageSetup()->setHorizontalCentered(true);
		  $objPHPExcel->getActiveSheet()->getPageSetup()->setVerticalCentered(true);
		  
		  
		  // margin is set in inches (0.5cm)
		  $margin = 0.5 / 2.54;
		  $objPHPExcel->getActiveSheet()->getPageMargins()->setTop($margin);
		  $objPHPExcel->getActiveSheet()->getPageMargins()->setBottom($margin);
		  $objPHPExcel->getActiveSheet()->getPageMargins()->setLeft($margin);
		  $objPHPExcel->getActiveSheet()->getPageMargins()->setRight($margin);
		  
		  
		  $tmp="../Admin/cetak/absen/DHMD ".$mk." ".$ds.".xls";
		  $objWriter = PHPExcel_IOFactory::createWriter($objPHPExcel, 'Excel5');
		  $objWriter->save($tmp);
		  return $tmp;
		}
		
	function ctk_DPNA($data,$thnsms)
	{
	  
	  $objPHPExcel = new PHPExcel();
	  $objPHPExcel->setActiveSheetIndex(0);
	  
	  
	  $vdosen = new dt_dosen;
      $nads = $vdosen->getnmdsn1($data['kdds']);
	  
	  $mk=$data['kdkmk']." - ".$data['nakmk'];
	  $ds=$data['kdds']." - ".$nads;
	  //$nads = $data['nads'];
	  
	   $objPHPExcel->getActiveSheet()->getColumnDimension('A')->setWidth(5.00);
       $objPHPExcel->getActiveSheet()->getColumnDimension('B')->setWidth(10.29);
       $objPHPExcel->getActiveSheet()->getColumnDimension('C')->setWidth(8.86);
       $objPHPExcel->getActiveSheet()->getColumnDimension('D')->setWidth(1.43);
       $objPHPExcel->getActiveSheet()->getColumnDimension('E')->setWidth(6.14);
       $objPHPExcel->getActiveSheet()->getColumnDimension('F')->setWidth(7.57);
       $objPHPExcel->getActiveSheet()->getColumnDimension('G')->setWidth(9.00);
       $objPHPExcel->getActiveSheet()->getColumnDimension('H')->setWidth(7.00);
	   $objPHPExcel->getActiveSheet()->getColumnDimension('I')->setWidth(7.00);
       $objPHPExcel->getActiveSheet()->getColumnDimension('J')->setWidth(7.00);
       $objPHPExcel->getActiveSheet()->getColumnDimension('K')->setWidth(7.00);
       $objPHPExcel->getActiveSheet()->getColumnDimension('L')->setWidth(7.00);
	   $objPHPExcel->getActiveSheet()->getColumnDimension('M')->setWidth(7.14);
       $objPHPExcel->getActiveSheet()->getColumnDimension('N')->setWidth(7.86);
       $objPHPExcel->getActiveSheet()->getColumnDimension('O')->setWidth(19.57);
       
	  $objPHPExcel->getActiveSheet()->setCellValue('A1', 'PROGRAM STUDI MATEMATIKA');
	  $objPHPExcel->getActiveSheet()->setCellValue('A2', 'FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM');
	  $objPHPExcel->getActiveSheet()->setCellValue('A3', 'UNIVERSITAS BALE BANDUNG');
	  $objPHPExcel->getActiveSheet()->getStyle('A1:A3')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Times New Roman',
							'size'      => 10
						)
					)
			);
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('A6', 'DAFTAR NILAI AKHIR');
	  
	    
	  $objPHPExcel->getActiveSheet()->mergeCells('A6:O6');
	  $objPHPExcel->getActiveSheet()->getStyle('A6:O6')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('A6:O6')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 		
	  
	  $objPHPExcel->getActiveSheet()->getStyle('A6:O6')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Times New Roman',
							'size'      => 12
						)
					)
			);		
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('A8', 'MATA KULIAH');
	  $objPHPExcel->getActiveSheet()->setCellValue('A9', 'DOSEN');
	  $objPHPExcel->getActiveSheet()->setCellValue('A10', 'Semester / Tahun Akademik');
	  $objPHPExcel->getActiveSheet()->setCellValue('A11', 'Kelas');
	  	  
	  
	   
	   $tmp = str_split($thnsms, 4);	  
	   $thn=$tmp[0];
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('D8',  ': ');
	  $objPHPExcel->getActiveSheet()->setCellValue('D9', ': ');
	  $objPHPExcel->getActiveSheet()->setCellValue('D10', ': ');
	  $objPHPExcel->getActiveSheet()->setCellValue('D11', ': ');
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('E8',  $mk);
	  $objPHPExcel->getActiveSheet()->setCellValue('E9', $ds);
	  $objPHPExcel->getActiveSheet()->setCellValue('E10', $data['sem'].'/'.$thn.'-'.($thn+1));
	  
	  
	   if($data['kls']=='R'){
	    $tmp_shift='Reguler';
	  }else{
	    $tmp_shift='Non Reguler';
	  }
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('E11', $tmp_shift);
	  
	  
	  $objPHPExcel->getActiveSheet()->getStyle('A8:E11')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Times New Roman',
							'size'      => 10
						)
					)
			);
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('A13',  'NO');
	  $objPHPExcel->getActiveSheet()->mergeCells('A13:A14');
	  $objPHPExcel->getActiveSheet()->getStyle('A13:A14')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('A13:A14')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
	 
      $objPHPExcel->getActiveSheet()->setCellValue('B13', 'NIM');
	  $objPHPExcel->getActiveSheet()->mergeCells('B13:B14');
	  $objPHPExcel->getActiveSheet()->getStyle('B13:B14')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('B13:B14')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('C13', 'NAMA');
	  $objPHPExcel->getActiveSheet()->mergeCells('C13:G14');
	  $objPHPExcel->getActiveSheet()->getStyle('C13:G14')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('C13:G14')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('H13', 'KOMPONEN NILAI');
	  $objPHPExcel->getActiveSheet()->mergeCells('H13:L13');
	  $objPHPExcel->getActiveSheet()->getStyle('H13:L13')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('H13:L13')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('H14', 'Absensi');
	  $objPHPExcel->getActiveSheet()->setCellValue('I14', 'Tugas');
	  $objPHPExcel->getActiveSheet()->setCellValue('J14', 'Quiz');
	  $objPHPExcel->getActiveSheet()->setCellValue('K14', 'UTS');
	  $objPHPExcel->getActiveSheet()->setCellValue('L14', 'UAS');
	  $objPHPExcel->getActiveSheet()->getStyle('H14:L14')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('H14:L14')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('M13', 'TOTAL NILAI');
	  $objPHPExcel->getActiveSheet()->mergeCells('M13:M14');
	  $objPHPExcel->getActiveSheet()->getStyle('M13:M14')->getAlignment()->setWrapText(true);
	  $objPHPExcel->getActiveSheet()->getStyle('M13:M14')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('M13:M14')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
      	  
	  $objPHPExcel->getActiveSheet()->setCellValue('N13', 'HURUF MUTU');
	  $objPHPExcel->getActiveSheet()->mergeCells('N13:N14');
	  $objPHPExcel->getActiveSheet()->getStyle('N13:N14')->getAlignment()->setWrapText(true);
	  $objPHPExcel->getActiveSheet()->getStyle('N13:N14')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('N13:N14')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('O13', 'KETERANGAN');
	  $objPHPExcel->getActiveSheet()->mergeCells('O13:O14');
	  $objPHPExcel->getActiveSheet()->getStyle('O13:O14')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('O13:O14')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
	  
	  $objPHPExcel->getActiveSheet()->getStyle('A13:O14')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Times New Roman',
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
	  
	  
	  
	  $data = $this->vriwayat->getMhs($thnsms,$data['kdkmk'],$data['kls'],$data['sem']);
	  
	  if(!empty($data)){
	    $i=1; 
        foreach($data as $row){
          $objPHPExcel->getActiveSheet()->setCellValue('A'.(14+$i), $i);
	      $objPHPExcel->getActiveSheet()->getStyle('A'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	      $objPHPExcel->getActiveSheet()->getStyle('A'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
          
		  $objPHPExcel->getActiveSheet()->setCellValue('B'.(14+$i), $row['nimhstrnlm']);
		  $objPHPExcel->getActiveSheet()->setCellValue('C'.(14+$i), $row['nmmhsmsmhs']);
		  $objPHPExcel->getActiveSheet()->mergeCells('C'.(14+$i).':'.'G'.(14+$i));
		  $i++;
		}		
	  }
	  
	   $objPHPExcel->getActiveSheet()->getStyle('A15:O'.(14+($i-1)))->applyFromArray(
					array(
						'font'    => array(
							'bold'      => false,
							'name'      => 'Times New Roman',
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
			
		$objPHPExcel->getActiveSheet()->getRowDimension(14+$i)->setRowHeight(6.00);	
		$i++;
        $j=$i;		
		$objPHPExcel->getActiveSheet()->setCellValue('B'.(14+$i), 'BOBOT KOMPONEN NILAI');
		$objPHPExcel->getActiveSheet()->mergeCells('B'.(14+$i).':'.'G'.(14+$i));
        $objPHPExcel->getActiveSheet()->getStyle('B'.(14+$i).':'.'G'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	    $objPHPExcel->getActiveSheet()->getStyle('B'.(14+$i).':'.'G'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 		
			
		$objPHPExcel->getActiveSheet()->setCellValue('H'.(14+$i), 'TOTAL');
		$objPHPExcel->getActiveSheet()->mergeCells('H'.(14+$i).':'.'H'.(14+($i+1)));
		$objPHPExcel->getActiveSheet()->getStyle('H'.(14+$i).':'.'H'.(14+($i+1)))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	    $objPHPExcel->getActiveSheet()->getStyle('H'.(14+$i).':'.'H'.(14+($i+1)))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);

        $objPHPExcel->getActiveSheet()->setCellValue('J'.(14+$i), 'RUMUS TOTAL NILAI');
		$objPHPExcel->getActiveSheet()->mergeCells('J'.(14+$i).':'.'N'.(14+$i));
		$objPHPExcel->getActiveSheet()->getStyle('J'.(14+$i).':'.'N'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	    $objPHPExcel->getActiveSheet()->getStyle('J'.(14+$i).':'.'N'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
        $i++;
		
		$objPHPExcel->getActiveSheet()->setCellValue('B'.(14+$i), 'Absensi (%)');
		$objPHPExcel->getActiveSheet()->getStyle('B'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	    $objPHPExcel->getActiveSheet()->getStyle('B'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);

		$objPHPExcel->getActiveSheet()->setCellValue('C'.(14+$i), 'Tugas (%)');
		$objPHPExcel->getActiveSheet()->getStyle('C'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	    $objPHPExcel->getActiveSheet()->getStyle('C'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
		
		$objPHPExcel->getActiveSheet()->setCellValue('D'.(14+$i), 'Quiz (%)');
		$objPHPExcel->getActiveSheet()->mergeCells('D'.(14+$i).':'.'E'.(14+$i));
		$objPHPExcel->getActiveSheet()->getStyle('D'.(14+$i).':'.'E'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	    $objPHPExcel->getActiveSheet()->getStyle('D'.(14+$i).':'.'E'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
		
		$objPHPExcel->getActiveSheet()->setCellValue('F'.(14+$i), 'UTS (%)');
		$objPHPExcel->getActiveSheet()->getStyle('F'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	    $objPHPExcel->getActiveSheet()->getStyle('F'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
		
		$objPHPExcel->getActiveSheet()->setCellValue('G'.(14+$i), 'UAS (%)');
		$objPHPExcel->getActiveSheet()->getStyle('G'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	    $objPHPExcel->getActiveSheet()->getStyle('G'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
        
		$objPHPExcel->getActiveSheet()->mergeCells('J'.(14+$i).':'.'N'.(14+($i+1)));
		
		$i++;
		
		$objPHPExcel->getActiveSheet()->mergeCells('D'.(14+$i).':'.'E'.(14+$i));
		$objPHPExcel->getActiveSheet()->setCellValue('H'.(14+$i), '100%');
		$objPHPExcel->getActiveSheet()->getStyle('H'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	    $objPHPExcel->getActiveSheet()->getStyle('H'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
           		
        $objPHPExcel->getActiveSheet()->getStyle('B'.(14+($j)).':H'.(14+($i)))->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Times New Roman',
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
          $objPHPExcel->getActiveSheet()->getStyle('J'.(14+($j)).':N'.(14+($i)))->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Times New Roman',
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
      
	  $i++;
      $objPHPExcel->getActiveSheet()->getRowDimension(14+$i)->setRowHeight(6.00);	
	  $i++;			
      $j=$i;
      $objPHPExcel->getActiveSheet()->setCellValue('B'.(14+$i), 'RANGE NILAI');
	  $objPHPExcel->getActiveSheet()->mergeCells('B'.(14+$i).':'.'C'.(14+$i));
      $objPHPExcel->getActiveSheet()->getStyle('B'.(14+$i).':'.'C'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('B'.(14+$i).':'.'C'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 		
	  
      $objPHPExcel->getActiveSheet()->setCellValue('D'.(14+$i), 'HURUF MUTU');
	  $objPHPExcel->getActiveSheet()->mergeCells('D'.(14+$i).':'.'F'.(14+$i));
      $objPHPExcel->getActiveSheet()->getStyle('D'.(14+$i).':'.'F'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('D'.(14+$i).':'.'F'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 	  

	  $objPHPExcel->getActiveSheet()->setCellValue('H'.(14+$i), 'MASUKAN UNTUK PROGRAM STUDI');
	  $objPHPExcel->getActiveSheet()->mergeCells('H'.(14+$i).':'.'L'.(14+$i));
      $objPHPExcel->getActiveSheet()->getStyle('H'.(14+$i).':'.'L'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('H'.(14+$i).':'.'L'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 	  

	  $objPHPExcel->getActiveSheet()->setCellValue('N'.(14+$i), 'TANDA TANGAN DOSEN');
	  $objPHPExcel->getActiveSheet()->mergeCells('N'.(14+$i).':'.'O'.(14+$i));
      $objPHPExcel->getActiveSheet()->getStyle('N'.(14+$i).':'.'O'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('N'.(14+$i).':'.'O'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);

      $i++;
      $objPHPExcel->getActiveSheet()->setCellValue('B'.(14+$i), '.... < total nilai < 100');
	  $objPHPExcel->getActiveSheet()->mergeCells('B'.(14+$i).':'.'C'.(14+$i));
      $objPHPExcel->getActiveSheet()->getStyle('B'.(14+$i).':'.'C'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('B'.(14+$i).':'.'C'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 		
	  
      $objPHPExcel->getActiveSheet()->setCellValue('D'.(14+$i), 'A');
	  $objPHPExcel->getActiveSheet()->mergeCells('D'.(14+$i).':'.'F'.(14+$i));
      $objPHPExcel->getActiveSheet()->getStyle('D'.(14+$i).':'.'F'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('D'.(14+$i).':'.'F'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 	  

	  $objPHPExcel->getActiveSheet()->mergeCells('H'.(14+$i).':'.'L'.(14+($i+5)));
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('N'.(14+$i), '('.$nads.')');
	  $objPHPExcel->getActiveSheet()->mergeCells('N'.(14+$i).':'.'O'.(14+($i+5)));
	  $objPHPExcel->getActiveSheet()->getStyle('N'.(14+$i).':'.'O'.(14+($i+5)))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
	  
      $i++;
      $objPHPExcel->getActiveSheet()->setCellValue('B'.(14+$i), '.... < total nilai < ...');
	  $objPHPExcel->getActiveSheet()->mergeCells('B'.(14+$i).':'.'C'.(14+$i));
      $objPHPExcel->getActiveSheet()->getStyle('B'.(14+$i).':'.'C'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('B'.(14+$i).':'.'C'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 		
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('D'.(14+$i), 'B');
	  $objPHPExcel->getActiveSheet()->mergeCells('D'.(14+$i).':'.'F'.(14+$i));
      $objPHPExcel->getActiveSheet()->getStyle('D'.(14+$i).':'.'F'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('D'.(14+$i).':'.'F'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 	  

	  
      $i++;
      $objPHPExcel->getActiveSheet()->setCellValue('B'.(14+$i), '.... < total nilai < ...');
	  $objPHPExcel->getActiveSheet()->mergeCells('B'.(14+$i).':'.'C'.(14+$i));
      $objPHPExcel->getActiveSheet()->getStyle('B'.(14+$i).':'.'C'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('B'.(14+$i).':'.'C'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 		
	  
	   $objPHPExcel->getActiveSheet()->setCellValue('D'.(14+$i), 'C');
	  $objPHPExcel->getActiveSheet()->mergeCells('D'.(14+$i).':'.'F'.(14+$i));
      $objPHPExcel->getActiveSheet()->getStyle('D'.(14+$i).':'.'F'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('D'.(14+$i).':'.'F'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 	  

	  
      $i++;
      $objPHPExcel->getActiveSheet()->setCellValue('B'.(14+$i), '.... < total nilai < ...');
	  $objPHPExcel->getActiveSheet()->mergeCells('B'.(14+$i).':'.'C'.(14+$i));
      $objPHPExcel->getActiveSheet()->getStyle('B'.(14+$i).':'.'C'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('B'.(14+$i).':'.'C'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 		
	  
       $objPHPExcel->getActiveSheet()->setCellValue('D'.(14+$i), 'D');
	  $objPHPExcel->getActiveSheet()->mergeCells('D'.(14+$i).':'.'F'.(14+$i));
      $objPHPExcel->getActiveSheet()->getStyle('D'.(14+$i).':'.'F'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('D'.(14+$i).':'.'F'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 	  

	  
      $i++;
      $objPHPExcel->getActiveSheet()->setCellValue('B'.(14+$i), '0 < total nilai < ...');
	  $objPHPExcel->getActiveSheet()->mergeCells('B'.(14+$i).':'.'C'.(14+$i));
      $objPHPExcel->getActiveSheet()->getStyle('B'.(14+$i).':'.'C'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('B'.(14+$i).':'.'C'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 		
	  
	   $objPHPExcel->getActiveSheet()->setCellValue('D'.(14+$i), 'E');
	  $objPHPExcel->getActiveSheet()->mergeCells('D'.(14+$i).':'.'F'.(14+$i));
      $objPHPExcel->getActiveSheet()->getStyle('D'.(14+$i).':'.'F'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('D'.(14+$i).':'.'F'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 	  

	  
      $i++;
      $objPHPExcel->getActiveSheet()->setCellValue('B'.(14+$i), 'Komponen Nilai Kurang');
	  $objPHPExcel->getActiveSheet()->mergeCells('B'.(14+$i).':'.'C'.(14+$i));
      $objPHPExcel->getActiveSheet()->getStyle('B'.(14+$i).':'.'C'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('B'.(14+$i).':'.'C'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 		
	  
      $objPHPExcel->getActiveSheet()->setCellValue('D'.(14+$i), 'T');
	  $objPHPExcel->getActiveSheet()->mergeCells('D'.(14+$i).':'.'F'.(14+$i));
      $objPHPExcel->getActiveSheet()->getStyle('D'.(14+$i).':'.'F'.(14+$i))->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('D'.(14+$i).':'.'F'.(14+$i))->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 	  
 	  
	  $objPHPExcel->getActiveSheet()->getStyle('B'.(14+($j)).':F'.(14+($i)))->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Times New Roman',
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
          $objPHPExcel->getActiveSheet()->getStyle('H'.(14+($j)).':L'.(14+($i)))->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Times New Roman',
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
			
			$objPHPExcel->getActiveSheet()->getStyle('N'.(14+($j)).':O'.(14+($i)))->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Times New Roman',
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

		
	  $objPHPExcel->getActiveSheet()->getPageSetup()->setOrientation(PHPExcel_Worksheet_PageSetup::ORIENTATION_LANDSCAPE);
      $objPHPExcel->getActiveSheet()->getPageSetup()->setPaperSize(PHPExcel_Worksheet_PageSetup::PAPERSIZE_A4);
	  $objPHPExcel->getActiveSheet()->getPageSetup()->setHorizontalCentered(true);
	  $objPHPExcel->getActiveSheet()->getPageSetup()->setVerticalCentered(true);
	  
	  
	  // margin is set in inches (0.5cm)
      $margin = 0.5 / 2.54;
	  $objPHPExcel->getActiveSheet()->getPageMargins()->setTop($margin);
	  $objPHPExcel->getActiveSheet()->getPageMargins()->setBottom($margin);
      $objPHPExcel->getActiveSheet()->getPageMargins()->setLeft($margin);
      $objPHPExcel->getActiveSheet()->getPageMargins()->setRight($margin);	
	  
	  $tmp="../Admin/cetak/absen/DPNA ".$mk." ".$ds.".xls";
	  
	  $objWriter = PHPExcel_IOFactory::createWriter($objPHPExcel, 'Excel5');
      $objWriter->save($tmp);
	  return $tmp;
	}
		
    }
?>