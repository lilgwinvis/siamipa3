<?php
  require_once 'shared.php';
  
  class vwtrans
  {
     var $vtrans;
	 
	 function __construct()
	 {
        $this->vtrans= new dt_trans;   
	 }   
		
      function filter_mhs()
	{
	  
	  $html_txt="<fieldset>";
	  $html_txt.="<legend>Filter</legend>";
	  
	  $vmhs = new dt_mhs;
	  $data = $vmhs->getAngkatan();
	  $thn = "";
	  foreach($data as $row)
	  {
	     foreach($row as $field => $value)
		 {
		    if(empty($thn))
			{
			  $thn=$value;
			}						
			  $ang[$value]=$value;						
		 }
	  } 			
	  
	   $data = $vmhs->getkls($thn);
	   $kls="";
	   foreach($data as $row)
	   {
		  foreach($row as $field => $value)
		  {
			if(empty($kls))
			{
			   $kls=$value;
			}
				if($value=='R')
				{
				  $tmp="Reguler";
				}else
				{
                  $tmp="Non Reguler";								
				}
						
			    $kelas[$value]=$value." - ".$tmp; 
						
			}
		} 	
	  
	  $data = $vmhs->getmhs($thn,$kls);
	  $vnim = "";
	  $vtemp= "";
	  foreach($data as $row)
	  {	
        if(empty($vnim))
		{
		  $vnim=$row['nimhsmsmhs'];
		  $vtemp = $row['nimhsmsmhs']."-".$row['nmmhsmsmhs'];
		}else{
		
		  if($vnim==$row['nimhsmsmhs'])
		  {
		    $vtemp = $row['nimhsmsmhs']."-".$row['nmmhsmsmhs'];
		  }
		
		}							   
						
		 $Mhs[$row['nimhsmsmhs']]=$row['nimhsmsmhs']."-".$row['nmmhsmsmhs']; 
						
	  }						
	  
	  $frm = new HTML_Form();
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmfilter"));
	  $tbl->addRow();
	  $tbl->addCell('Angkatan '.$frm->addSelectList("Angkatan",$ang,true,null,null,array('id'=>'Angkatan')).' Kelas '.$frm->addSelectList("kls",$kelas,true,null,null,array('id'=>'kls')).' Mahasiswa '.$frm->addSelectList("Mhs",$Mhs,true,null,null,array('id'=>'Mhs')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')).$frm->addInput('submit',"ctkexcel","Cetak Ke Excel",array('id'=>'ctkexcel')).$frm->addInput('submit',"ctkpdf","Cetak Ke Pdf",array('id'=>'ctkpdf')), null, 'data');
	   
	  $html_txt.=$tbl->display()."</fieldset>";

      $html_txt.="<fieldset>";
	  $html_txt.="<legend  id='hsl_filter'> Hasil Filter : ".$vtemp."</legend>";
      	  
	  
	  $html_txt.="<div id='data'>";
	  $html_txt.=$this->buildtrans($vnim);
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
		
       function buildtrans($vnim)
	   {    
	   
	        $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_trans",'width'=>'100%'));
	        $tbl->addRow();
	        $tbl->addCell("Semester", null, 'header');
	        $tbl->addCell("Kode", null, 'header');
			$tbl->addCell("Matakuliah", null, 'header'); 
			$tbl->addCell("SKS", null, 'header');
	        $tbl->addCell("HM", null, 'header');
			$tbl->addCell("NM", null, 'header');
					   
						  
			  $data = $this->vtrans->getData($vnim);		  	  
		      $semestbkmk = "";
			if(!empty($data)){ 
			  foreach ($data as $row) 
			  {                    
			
			           $tbl->addRow();
	                   $tbl->addCell($row['semestbkmk'], null, 'data');
					   $tbl->addCell($row['kdkmktrnlm'], null, 'data');
					   $tbl->addCell($this->ismrhitl($row['wp'],$row['nakmktbkmk']), null, 'data');
		               $tbl->addCell($this->ismrhitl($row['wp'],$row['sksmktbkmk']), null, 'data');
					   $tbl->addCell($row['nlakhtrnlm'], null, 'data');
					   $tbl->addCell($row['bobottrnlm'], null, 'data');
					 
			    }
			}	
			
					$txt = "<tr>";
						$txt = $txt."<th></th>";
						$txt = $txt."<th><input type='hidden' name='search_sem' value='Search sem' class='search_init' /><input type='text' name='search_kode' value='Kode' class='search_init' style='width:150px'/></th>";
						$txt = $txt."<th><input type='text' name='search_mtk' value='Matakuliah' class='search_init' style='width:250px' /></th>";
						$txt = $txt."<th><input type='hidden' name='search_sks' value='Search sks' class='search_init' /></th>";
						$txt = $txt."<th><input type='text' name='search_hm' value='HM' class='search_init' style='width:20px'/></th>";
						$txt = $txt."<th></th>";
					$txt = $txt."</tr>";
			  
			return $tbl->display($txt);	   
		}	
        
		
		function ctk_excel($vnim)
	   {
		   
			
			$objPHPExcel = new PHPExcel();
			
			$objPHPExcel->setActiveSheetIndex(0);
			
			$objDrawing = new PHPExcel_Worksheet_Drawing(); 
	        $objDrawing->setPath('../img/kop.jpg');
	        $objDrawing->setWidth(800);
	        $objDrawing->setOffsetX(0);
            $objDrawing->setOffsetY(0);
	        $objDrawing->setWorksheet($objPHPExcel->getActiveSheet());
	        $objDrawing->setCoordinates('A1');
			
			
			//$objPHPExcel->getActiveSheet()->setCellValue('B2', 'YAYASAN PENDIDIKAN BALE BANDUNG');
			//$objPHPExcel->getActiveSheet()->setCellValue('B3', 'UNIVERSITAS BALE BANDUNG');
			
			$objPHPExcel->getActiveSheet()->setCellValue('A11', 'TRANSKRIP NILAI');
			$objPHPExcel->getActiveSheet()->mergeCells('A11:O11');
			$objPHPExcel->getActiveSheet()->getStyle('A11')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);					  
			
			$objPHPExcel->getActiveSheet()->setCellValue('A14', 'Nama');
			$objPHPExcel->getActiveSheet()->setCellValue('A15', 'Tempat/Tanggal Lahir');
			$objPHPExcel->getActiveSheet()->setCellValue('A16', 'NIM');
			$objPHPExcel->getActiveSheet()->setCellValue('C14', ':');
			$objPHPExcel->getActiveSheet()->setCellValue('C15', ':');
			$objPHPExcel->getActiveSheet()->setCellValue('C16', ':');
			
			$dt_mhs = new dt_mhs;
			$data=$dt_mhs->getData($vnim);
			foreach($data as $row){
		    	$objPHPExcel->getActiveSheet()->setCellValue('D14', $row['nmmhsmsmhs']);
		    	$objPHPExcel->getActiveSheet()->setCellValue('D15', trim($row['tplhrmsmhs'])." / ".date_format(date_create($row['tglhrmsmhs']),'d-m-Y'));
		    	$objPHPExcel->getActiveSheet()->setCellValue('D16', $row['nimhsmsmhs']);
			}
			$objPHPExcel->getActiveSheet()->setCellValue('J14', 'Fakultas');
			$objPHPExcel->getActiveSheet()->setCellValue('J15', 'Program Studi');
			$objPHPExcel->getActiveSheet()->setCellValue('J16', 'Program Pendidikan');
			$objPHPExcel->getActiveSheet()->setCellValue('K14', ':');
			$objPHPExcel->getActiveSheet()->setCellValue('K15', ':');
			$objPHPExcel->getActiveSheet()->setCellValue('K16', ':');
			$objPHPExcel->getActiveSheet()->setCellValue('L14', 'Matematika dan IPA');
			$objPHPExcel->getActiveSheet()->setCellValue('L15', 'Matematika');
			$objPHPExcel->getActiveSheet()->setCellValue('L16', 'S1');
			
			$objPHPExcel->getActiveSheet()->getStyle('A11:P16')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Times New Roman',
							'size'      => 10
						)
					)
			);
			
			$styleThickBrownBorderOutline = array(
				'borders' => array(
					'outline' => array(
						'style' => PHPExcel_Style_Border::BORDER_MEDIUM,					
					),
				),
			);
			
			
			$objPHPExcel->getActiveSheet()->getColumnDimension('A')->setWidth(9.00);
			$objPHPExcel->getActiveSheet()->getColumnDimension('B')->setWidth(28.00);
			$objPHPExcel->getActiveSheet()->getColumnDimension('C')->setWidth(1);
			$objPHPExcel->getActiveSheet()->getColumnDimension('D')->setWidth(7.14);
			$objPHPExcel->getActiveSheet()->getColumnDimension('E')->setWidth(3.8);	
			$objPHPExcel->getActiveSheet()->getColumnDimension('F')->setWidth(3.8);
			$objPHPExcel->getActiveSheet()->getColumnDimension('G')->setWidth(3.8);
			$objPHPExcel->getActiveSheet()->getColumnDimension('H')->setWidth(3.8);
			$objPHPExcel->getActiveSheet()->getColumnDimension('I')->setWidth(0.33);
			
			$objPHPExcel->getActiveSheet()->setCellValue('A17', 'Matakuliah');	
            $objPHPExcel->getActiveSheet()->mergeCells('A17:C18');
            $objPHPExcel->getActiveSheet()->getStyle('A17')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
			$objPHPExcel->getActiveSheet()->getStyle('A17')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 
			$objPHPExcel->getActiveSheet()->setCellValue('D17', 'Kode');
			$objPHPExcel->getActiveSheet()->mergeCells('D17:D18');
			$objPHPExcel->getActiveSheet()->getStyle('D17')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
			$objPHPExcel->getActiveSheet()->getStyle('D17')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 
           	$objPHPExcel->getActiveSheet()->setCellValue('E17', 'SKS');
			$objPHPExcel->getActiveSheet()->mergeCells('E17:E18');
			$objPHPExcel->getActiveSheet()->getStyle('E17')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
			$objPHPExcel->getActiveSheet()->getStyle('E17')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);  
			$objPHPExcel->getActiveSheet()->setCellValue('F17', 'NILAI');
			$objPHPExcel->getActiveSheet()->mergeCells('F17:H17');
			$objPHPExcel->getActiveSheet()->getStyle('F17')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);					  
			$objPHPExcel->getActiveSheet()->setCellValue('F18', 'HM');
			$objPHPExcel->getActiveSheet()->getStyle('F12')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
			$objPHPExcel->getActiveSheet()->setCellValue('G18', 'AM');
			$objPHPExcel->getActiveSheet()->getStyle('G18')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
			$objPHPExcel->getActiveSheet()->setCellValue('H18', 'NM');
			$objPHPExcel->getActiveSheet()->getStyle('H18')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
			
			$objPHPExcel->getActiveSheet()->getColumnDimension('J')->setWidth(31.00);
			$objPHPExcel->getActiveSheet()->getColumnDimension('K')->setWidth(1);
			$objPHPExcel->getActiveSheet()->getColumnDimension('L')->setWidth(7.14);
			$objPHPExcel->getActiveSheet()->getColumnDimension('M')->setWidth(3.8);	
			$objPHPExcel->getActiveSheet()->getColumnDimension('N')->setWidth(3.8);
			$objPHPExcel->getActiveSheet()->getColumnDimension('O')->setWidth(3.8);
			$objPHPExcel->getActiveSheet()->getColumnDimension('P')->setWidth(3.8);
			
			$objPHPExcel->getActiveSheet()->setCellValue('J17', 'Matakuliah');
			$objPHPExcel->getActiveSheet()->getStyle('J17')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
			$objPHPExcel->getActiveSheet()->getStyle('J17')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 
            $objPHPExcel->getActiveSheet()->mergeCells('J17:K18');			
			$objPHPExcel->getActiveSheet()->setCellValue('L17', 'Kode');
            $objPHPExcel->getActiveSheet()->mergeCells('L17:L18');
            $objPHPExcel->getActiveSheet()->getStyle('L17')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
			$objPHPExcel->getActiveSheet()->getStyle('L17')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 			
			$objPHPExcel->getActiveSheet()->setCellValue('M17', 'SKS');
			$objPHPExcel->getActiveSheet()->mergeCells('M17:M18');
			$objPHPExcel->getActiveSheet()->getStyle('M17')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
			$objPHPExcel->getActiveSheet()->getStyle('M17')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 
			$objPHPExcel->getActiveSheet()->setCellValue('N17', 'NILAI');
			$objPHPExcel->getActiveSheet()->mergeCells('N17:P17');
			$objPHPExcel->getActiveSheet()->getStyle('N17')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);					  
			$objPHPExcel->getActiveSheet()->setCellValue('N18', 'HM');
			$objPHPExcel->getActiveSheet()->getStyle('N18')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
			$objPHPExcel->getActiveSheet()->setCellValue('O18', 'AM');
			$objPHPExcel->getActiveSheet()->getStyle('O18')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
			$objPHPExcel->getActiveSheet()->setCellValue('P18', 'NM');
			$objPHPExcel->getActiveSheet()->getStyle('P18')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);			
						  
			  $data = $this->vtrans->getData($vnim);		  	  
		      
			  $i=19;
			  $j=19;
			  $cnt = 1;
			  $jml_data = count($data);
			if(!empty($data)){ 

			foreach ($data as $row) 
			  {
                 	$sks = $row['sksmktbkmk'];	
					$am = $row['bobottrnlm'];
					$nm = $sks*$am;
              
   			            if($cnt<=(($jml_data/2)+($jml_data%2==0 ? 0:1))){                      					   
					    $objPHPExcel->getActiveSheet()->setCellValue('A'.$i,$row['nakmktbkmk']);
						$objPHPExcel->getActiveSheet()->mergeCells('A'.$i.':'.'C'.$i);
						$objPHPExcel->getActiveSheet()->setCellValue('D'.$i,$row['kdkmktrnlm']);						
						$objPHPExcel->getActiveSheet()->setCellValue('E'.$i,$row['sksmktbkmk']);
                        $objPHPExcel->getActiveSheet()->getStyle('E'.$i)->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 						
						$objPHPExcel->getActiveSheet()->setCellValue('F'.$i,$row['nlakhtrnlm']);
						$objPHPExcel->getActiveSheet()->getStyle('F'.$i)->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 						
						$objPHPExcel->getActiveSheet()->setCellValue('G'.$i,$row['bobottrnlm']);
						$objPHPExcel->getActiveSheet()->getStyle('G'.$i)->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 						
						$objPHPExcel->getActiveSheet()->setCellValue('H'.$i,$nm);
						$objPHPExcel->getActiveSheet()->getStyle('H'.$i)->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 						
					   	$i++;
						}else{
						   if($cnt>(($jml_data/2)+($jml_data%2==0 ? 0:1)) and $cnt<=$jml_data){
								$objPHPExcel->getActiveSheet()->setCellValue('J'.$j,$row['nakmktbkmk']);
								$objPHPExcel->getActiveSheet()->mergeCells('J'.$j.':'.'K'.$j);
								$objPHPExcel->getActiveSheet()->setCellValue('L'.$j,$row['kdkmktrnlm']);						
								$objPHPExcel->getActiveSheet()->setCellValue('M'.$j,$row['sksmktbkmk']);
								$objPHPExcel->getActiveSheet()->getStyle('M'.$j)->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 						
								$objPHPExcel->getActiveSheet()->setCellValue('N'.$j,$row['nlakhtrnlm']);
								$objPHPExcel->getActiveSheet()->getStyle('N'.$j)->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 						
								$objPHPExcel->getActiveSheet()->setCellValue('O'.$j,$row['bobottrnlm']);
								$objPHPExcel->getActiveSheet()->getStyle('O'.$j)->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 						
								$objPHPExcel->getActiveSheet()->setCellValue('P'.$j,$nm);
								$objPHPExcel->getActiveSheet()->getStyle('P'.$j)->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 						
								$j++;
							}	
						}
						
					 $cnt++;
					 
			    }
			    
			}

            if($i>$j){
			$max=$i+1;
            }else{
             $max=$j+1;
			}			
			
			$objPHPExcel->getActiveSheet()->getStyle('A17:P'.($max-2))->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Calibri',
							'size'      => 9
						),
						'borders' => array(
							'inside'     => array(
								'style' => PHPExcel_Style_Border::BORDER_MEDIUM
							),
							'outline'     => array(
								'style' => PHPExcel_Style_Border::BORDER_MEDIUM
							)
						)
					)
			);
			
			$objPHPExcel->getActiveSheet()->setCellValue('A'.$max,'TOTAL SKS');
			$objPHPExcel->getActiveSheet()->setCellValue('A'.($max+1),'INDEX PRESTASI KUMULATIF (IPK)');
			
			
			$objPHPExcel->getActiveSheet()->getStyle('A'.$max.':'.'D'.($max+1))->applyFromArray($styleThickBrownBorderOutline);
						
			$objPHPExcel->getActiveSheet()->setCellValue('C'.$max,':');
			$objPHPExcel->getActiveSheet()->setCellValue('C'.($max+1),':');
			
			
			$objPHPExcel->getActiveSheet()->getStyle('A'.$max.':'.'D'.($max+8))->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Calibri',
							'size'      => 9
						)
					)
			);
			
			$this->vtrans->hitipk($vnim);
			$ipk =  $this->vtrans->sks_nm /$this->vtrans->sks_mbl;
			$sks = $this->vtrans->sks_mbl;
			$objPHPExcel->getActiveSheet()->setCellValue('D'.$max,strval($sks));
			$objPHPExcel->getActiveSheet()->setCellValue('D'.($max+1),number_format($ipk, 2, ',', ' '));
			
			$objPHPExcel->getActiveSheet()->setCellValue('A'.($max+8),'Dicetak dari Sistem Informasi Akademik FMIPA UNIBBA pada tanggal :'.date("d-m-Y H:i:s"));

			$objPHPExcel->getActiveSheet()->setCellValue('K'.($max+1),'Baleendah, ____________ 20___');
			
			$objPHPExcel->getActiveSheet()->setCellValue('M'.($max+3),'___________');
			$objPHPExcel->getActiveSheet()->setCellValue('M'.($max+6),'___________');
			
			$objPHPExcel->getActiveSheet()->getPageSetup()->setPaperSize(PHPExcel_Worksheet_PageSetup::PAPERSIZE_LEGAL);
			$objPHPExcel->getActiveSheet()->getPageSetup()->setOrientation(PHPExcel_Worksheet_PageSetup::ORIENTATION_PORTRAIT);
			$objPHPExcel->getActiveSheet()->getPageSetup()->setHorizontalCentered(true);
			$objPHPExcel->getActiveSheet()->getPageSetup()->setFitToPage(true);
			// margin is set in inches (0.5cm)
            $margin = 0.5 / 2.54;
	        $objPHPExcel->getActiveSheet()->getPageMargins()->setTop($margin);
	        $objPHPExcel->getActiveSheet()->getPageMargins()->setBottom($margin);
            $objPHPExcel->getActiveSheet()->getPageMargins()->setLeft($margin);
            $objPHPExcel->getActiveSheet()->getPageMargins()->setRight($margin);     
			
			
			$tmp="../Admin/cetak/transkrip/Transkrip Nilai - ".$vnim.".xls";
			$objWriter = PHPExcel_IOFactory::createWriter($objPHPExcel, 'Excel5');
            $objWriter->save($tmp);
			
			return $tmp;	   
		}

        function ctk_pdf($vnim)
	   {
		    
			
			$tbl4 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_jdl",'cellpadding'=>'2'));
	   
	        $tbl4->addRow();		  
		    $tbl4->addCell('<img src="../img/kop.jpg" alt="logo" width="100%" height="100%">','data');
            //$tbl4->addCell('<font face="Times New Roman" size="10pt">'.
	                     //'<b>YAYASAN PENDIDIKAN BALE BANDUNG<br>'.
					    //     'UNIVERSITAS BALE BANDUNG'.
				       //  '</b>'.
			          //   '</font>',null,'data');
	   
	        $jdl = $tbl4->display().			  
			  '<br><br>'.
	          '<center>'.
			            '<font face="Times New Roman" size="10pt">'.
						       '<b>TRANSKRIP NILAI</b>'.
					    '</font>'.
			  '</center><br><br>';
			 			
			$dt_mhs = new dt_mhs;
			$data=$dt_mhs->getData($vnim);
			foreach($data as $row){
		    	
				$tbl2 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_mhs","width"=>"100%"));       
				   $tbl2->addRow();		  
					  $tbl2->addCell('Nama','data');
					  $tbl2->addCell(':',null,'data');
					  $tbl2->addCell($row['nmmhsmsmhs'],null,'data');
					  $tbl2->addCell('Fakultas','data');
					  $tbl2->addCell(':',null,'data');
					  $tbl2->addCell('Matematika dan IPA',null,'data');				  
				   $tbl2->addRow();		  
					  $tbl2->addCell('Tempat/Tanggal Lahir','data');
					  $tbl2->addCell(':',null,'data');
					  $tbl2->addCell(trim($row['tplhrmsmhs'])." / ".date_format(date_create($row['tglhrmsmhs']),'d-m-Y'),null,'data');
					  $tbl2->addCell('Program Studi','data');
					  $tbl2->addCell(':',null,'data');
					  $tbl2->addCell('Matematika',null,'data');
				   $tbl2->addRow();		  
					  $tbl2->addCell('NIM',null,'data');
					  $tbl2->addCell(':',null,'data');
					  $tbl2->addCell($row['nimhsmsmhs'],null,'data');
					  $tbl2->addCell('Program Pendidikan','data');
					  $tbl2->addCell(':',null,'data');
					  $tbl2->addCell('S1',null,'data');
				
			}
					
			
			 $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_mtk","width"=>"100%",'border'=>'1','cellpadding'=>'2'));
	   
	         $tbl->addRow(); 
	         $tbl->addCell('Matakuliah',null,'header',array('rowspan'=>'2'));
	         $tbl->addCell('Kode',null,'header',array('rowspan'=>'2'));	  
	         $tbl->addCell('SKS',null,'header',array('rowspan'=>'2'));	 
	         $tbl->addCell('NILAI',null,'header',array('colspan'=>'3'));
			
			 $tbl->addCell('Matakuliah',null,'header',array('rowspan'=>'2'));
	         $tbl->addCell('Kode',null,'header',array('rowspan'=>'2'));	  
	         $tbl->addCell('SKS',null,'header',array('rowspan'=>'2'));	 
	         $tbl->addCell('NILAI',null,'header',array('colspan'=>'3'));
			
			
			 $tbl->addRow(); 
	         $tbl->addCell('HM',null,'header');
	         $tbl->addCell('AM',null,'header');	  
	         $tbl->addCell('NM',null,'header');	 
	         			
			 $tbl->addCell('HM',null,'header');
	         $tbl->addCell('AM',null,'header');	  
	         $tbl->addCell('NM',null,'header');	 
	         
						
						  
			  $data = $this->vtrans->getData($vnim);		  	  
		      
			  $i=1;
			  $j=1;
			  $cnt = 1;
			  $jml_data = count($data);
			if(!empty($data)){ 

			foreach ($data as $row) 
			  {
                 	$sks = $row['sksmktbkmk'];	
					$am = $row['bobottrnlm'];
					$nm = $sks*$am;
              
   			            if($cnt<=(($jml_data/2)+($jml_data%2==0 ? 0:1))){                      					   
					     $data_tmp['nama'] = $row['nakmktbkmk'];
						 $data_tmp['kd']   = $row['kdkmktrnlm'];						
						 $data_tmp['sks']  = $row['sksmktbkmk'];
                         $data_tmp['HM']   = $row['nlakhtrnlm'];
						 $data_tmp['AM']   = $row['bobottrnlm'];
						 $data_tmp['NM']   = $nm;
						 $data_kiri[] = $data_tmp;
						 $i++;
						}else{
						   if($cnt>(($jml_data/2)+($jml_data%2==0 ? 0:1)) and $cnt<=$jml_data){
								 $data_tmp['nama'] = $row['nakmktbkmk'];
						         $data_tmp['kd']   = $row['kdkmktrnlm'];						
						         $data_tmp['sks']  = $row['sksmktbkmk'];
                                 $data_tmp['HM']   = $row['nlakhtrnlm'];
						         $data_tmp['AM']   = $row['bobottrnlm'];
						         $data_tmp['NM']   = $nm;
								 $data_kanan[] = $data_tmp;
								 $j++;
							}	
						}
						
					 $cnt++;
					 
			    }
			    
			}
			
						
			for ($k=1;$k<=($i-1);$k++)
			{
			   
			   $tbl->addRow();
			  
                  
				     $data_tmp=$data_kiri[$k-1];
				    
					 $tbl->addCell($data_tmp['nama'],null,'data');
					 $tbl->addCell($data_tmp['kd'],null,'data');	  
					 $tbl->addCell($data_tmp['sks'],null,'data');	 
					 $tbl->addCell($data_tmp['HM'],null,'data');
					 $tbl->addCell($data_tmp['AM'],null,'data');
					 $tbl->addCell($data_tmp['NM'],null,'data');	  
					 		  
					if($k<=($j-1))
     				{    
						 $data_tmp=$data_kanan[$k-1];
					  
						 $tbl->addCell($data_tmp['nama'],null,'data');
						 $tbl->addCell($data_tmp['kd'],null,'data');	  
						 $tbl->addCell($data_tmp['sks'],null,'data');	 
						 $tbl->addCell($data_tmp['HM'],null,'data');
						 $tbl->addCell($data_tmp['AM'],null,'data');
						 $tbl->addCell($data_tmp['NM'],null,'data');	  
					}else
                      {
					     $tbl->addCell('',null,'data');
						 $tbl->addCell('',null,'data');	  
						 $tbl->addCell('',null,'data');	 
						 $tbl->addCell('',null,'data');
						 $tbl->addCell('',null,'data');
						 $tbl->addCell('',null,'data');						  
					  }					
			  
			}

           
		   $this->vtrans->hitipk($vnim);
		   $ipk =  $this->vtrans->sks_nm /$this->vtrans->sks_mbl;
		   $sks = $this->vtrans->sks_mbl;
		   
		   $tbl3 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_ttd",'border'=>'1','width'=>'37%','cellpadding'=>'2'));
	   
	       $tbl3->addRow(); 
	       $tbl3->addCell('TOTAL SKS',null,'data');
	       $tbl3->addCell(':',null,'data');
           $tbl3->addCell(strval($sks),null,'data'); 		   
	       $tbl3->addRow(); 
		   $tbl3->addRow(); 
	       $tbl3->addCell('INDEX PRESTASI KUMULATIF (IPK)',null,'data');
	       $tbl3->addCell(':',null,'data');
           $tbl3->addCell(number_format($ipk, 2, ',', ' '),null,'data');
	       			
			//$objPHPExcel->getActiveSheet()->setCellValue('K'.($max+3),'Baleendah, ____________ 20___');
			
			//$objPHPExcel->getActiveSheet()->setCellValue('M'.($max+5),'___________');
			//$objPHPExcel->getActiveSheet()->setCellValue('M'.($max+8),'___________');
			
						
			
			 $html =
            '<html>'.
			'<style type="text/css">'.
			'table{font-family: Calibri; font-size: 8pt;}'.
			'</style>'.
			'<body>'.
			 $jdl.$tbl2->display().             
			 $tbl->display().
			 //$tbl1->display().
			'<br>'.$tbl3->display().
			'<br>'.'<font face="Calibri" size="9pt">Dicetak dari Sistem Informasi Akademik FMIPA UNIBBA pada tanggal '.date("d-m-Y H:i:s").'</font>'.
            '</body>'.
			'</html>';          
		  
		  $tmp="../Admin/cetak/transkrip/Transkrip Nilai - ".$vnim.".pdf";
          
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