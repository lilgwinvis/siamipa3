<?php

require_once 'shared.php';
//require '../vendor/autoload.php';

//use PhpOffice\PhpSpreadsheet\Spreadsheet;
//use PhpOffice\PhpSpreadsheet\Writer\Xlsx;

define('BORDER_MEDIUM', PHPExcel_Style_Border::BORDER_MEDIUM);
define('BORDER_THIN', PHPExcel_Style_Border::BORDER_THIN);
define('BORDER_NONE', PHPExcel_Style_Border::BORDER_NONE);

define('HORIZONTAL_LEFT', PHPExcel_Style_Alignment::HORIZONTAL_LEFT);
define('HORIZONTAL_CENTER', PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
define('HORIZONTAL_RIGHT', PHPExcel_Style_Alignment::HORIZONTAL_RIGHT);


define('VERTICAL_CENTER', PHPExcel_Style_Alignment::VERTICAL_CENTER);
define('VERTICAL_BOTTOM', PHPExcel_Style_Alignment::VERTICAL_BOTTOM);
define('VERTICAL_TOP', PHPExcel_Style_Alignment::VERTICAL_TOP);

define('ORIENTATION_PORTRAIT', PHPExcel_Worksheet_PageSetup::ORIENTATION_PORTRAIT);
define('ORIENTATION_LANDSCAPE', PHPExcel_Worksheet_PageSetup::ORIENTATION_LANDSCAPE);
define('PAPERSIZE_LEGAL', PHPExcel_Worksheet_PageSetup::PAPERSIZE_LEGAL);
define('PAPERSIZE_A4', PHPExcel_Worksheet_PageSetup::PAPERSIZE_A4);

define('BREAK_ROW', PHPExcel_Worksheet::BREAK_ROW);


class vw_excel_basic
{ 
  private $objPHPExcel;
  
  function __construct()
  {
    $this->objPHPExcel = new PHPExcel();
    //$this->objPHPExcel = new Spreadsheet();

    

  }
  
  function createSheet()
   {
     $this->objPHPExcel->createSheet(NULL, 1);
   }
   
   function setActiveSheetIndex($idx)
   {
     $this->objPHPExcel->setActiveSheetIndex($idx);   
   }
   
   function setSheetTittle($title)
   {
     $this->objPHPExcel->getActiveSheet()->setTitle($title);   
   }
   
   function setColumnWidth($col_width)
   {
     foreach($col_width as $col=>$width)
	 {
	   $this->objPHPExcel->getActiveSheet()->getColumnDimension($col)->setWidth($width);
	 }
   }
   
   function setRowHeight($row,$row_height)
   {
    $this->objPHPExcel->getActiveSheet()->getRowDimension($row)->setRowHeight($row_height);
   }
   
   function setBreak($add,$jns_break)
   {
     $this->objPHPExcel->getActiveSheet()->setBreak($add , $jns_break );   
   }
   
   function setFooter($txt)
   {
     $this->objPHPExcel->getActiveSheet()->getHeaderFooter()->setOddFooter($txt);
     $this->objPHPExcel->getActiveSheet()->getHeaderFooter()->setEvenFooter($txt);
   }
   
   function setCellValue($add,$txt)
   {
      $this->objPHPExcel->getActiveSheet()->setCellValue($add,$txt);   
   }
   
   function mergeCells($add)
   {
     $this->objPHPExcel->getActiveSheet()->mergeCells($add);   
   }
   
   function setStyle($add,$font,$borders=array())
   {
     $this->objPHPExcel->getActiveSheet()->getStyle($add)->applyFromArray(
					array(
						'font'    => $font,
						'borders' => $borders
					)
			);	   
   }
   
   function setAlignment($add,$h,$v)
   {
     $this->objPHPExcel->getActiveSheet()->getStyle($add)->getAlignment()->setHorizontal($h); 
	 $this->objPHPExcel->getActiveSheet()->getStyle($add)->getAlignment()->setVertical($v); 
   }
   
   function setWrapText($add,$stat)
   {
     $this->objPHPExcel->getActiveSheet()->getStyle($add)->getAlignment()->setWrapText($stat);
   }
   
   function setShrinkToFit($add,$stat)
   {
     $this->objPHPExcel->getActiveSheet()->getStyle($add)->getAlignment()->setShrinkToFit($stat);
   }
   
   function setFormatCode($add,$format)
   {   
    $this->objPHPExcel->getActiveSheet()->getStyle($add)->getNumberFormat()->setFormatCode($format);
   }
   
   function setPageSetup($orientation,$papersize,$hcen,$vcen,$scale=100,$rowawl=0,$rowakh=0,$fitpage=false)
   {
      $this->objPHPExcel->getActiveSheet()->getPageSetup()->setOrientation($orientation);
      $this->objPHPExcel->getActiveSheet()->getPageSetup()->setPaperSize($papersize);
	  $this->objPHPExcel->getActiveSheet()->getPageSetup()->setHorizontalCentered($hcen);
	  $this->objPHPExcel->getActiveSheet()->getPageSetup()->setVerticalCentered($vcen);
	  $this->objPHPExcel->getActiveSheet()->getPageSetup()->setScale($scale);
	  $this->objPHPExcel->getActiveSheet()->getPageSetup()->setFitToPage($fitpage);
	  
	  if($rowawl!=0 and $rowakh !=0)
	  {
	   $this->objPHPExcel->getActiveSheet()->getPageSetup()->setRowsToRepeatAtTopByStartAndEnd($rowawl, $rowakh);	  
	  }
	  
	  
   }
   
   function setMargin($top,$bottom,$left,$right)
   {
      $this->objPHPExcel->getActiveSheet()->getPageMargins()->setTop($top);
	  $this->objPHPExcel->getActiveSheet()->getPageMargins()->setBottom($bottom);
      $this->objPHPExcel->getActiveSheet()->getPageMargins()->setLeft($left);
      $this->objPHPExcel->getActiveSheet()->getPageMargins()->setRight($right);

   }   
   
   function save($nm_file)
   {
      //$objWriter = new Xlsx($this->objPHPExcel);
      $objWriter = PHPExcel_IOFactory::createWriter($this->objPHPExcel, 'Excel5');
      $objWriter->save($nm_file);   
   }
  
  function tulis_data($jdl,$idx=0)
   {
     foreach($jdl as $data)
	 {
       
	   
	   
	   if(isset($data['txt']))
	   {	   	  
		  if(isset($data['add']) and isset($data['row']))
		  {  		
  		     $this->setCellValue($data['add'].($idx+$data['row']),$data['txt']);
	      } else {
		           $this->setCellValue($data['add'],$data['txt']);		  
		         }
		}
		
		$ismerge = false;
		
		if(isset($data['merge']))
	   {		
				if($data['merge'])
				{
				  if(isset($data['mawl']) and isset($data['makh']) and isset($data['row']) and isset($data['mjml']))
				  {  		
					 $this->mergeCells($data['mawl'].($idx+$data['row']).':'.$data['makh'].($idx+$data['row']+$data['mjml'])); 
				     $ismerge = true;
					 
				  } else {
						   if(isset($data['madd'])){	
							  $this->mergeCells($data['madd']); 
				           }
						 }
				}
        }
		
		if(isset($data['warp']))
	   {		
			if($data['warp'])
			{	
				if($ismerge)
				{
				  if(isset($data['mawl']) and isset($data['makh']) and isset($data['row']) and isset($data['mjml']))
				  {  		
					 $this->setWrapText($data['mawl'].($idx+$data['row']).':'.$data['makh'].($idx+$data['row']+$data['mjml']),true); 				    
					 
				  } else {
						   if(isset($data['madd'])){	
							  $this->setWrapText($data['madd'],true); 
				           }
						 }
				}else{	  
					  if(isset($data['add']) and isset($data['row']))
					  {
						 $this->setWrapText($data['add'].($idx+$data['row']),true);
					  }else{
						  if(isset($data['add'])){  
							 $this->setWrapText($data['add'],true);
						  }	 
						} 
				   }
			} 	
        }
		
		if(isset($data['format']))
		{
		   if($ismerge)
		   {
		    if(isset($data['mawl']) and isset($data['makh']) and isset($data['row']) and isset($data['mjml']))
				  {  		
					$this->setFormatCode($data['mawl'].($idx+$data['row']).':'.$data['makh'].($idx+$data['row']+$data['mjml']),$data['format']); 				    
					 
				  } else {
						   if(isset($data['madd'])){	
							  $this->setFormatCode($data['madd'],$data['format']); 
				           }
						 }
		   }else{
		             if(isset($data['add']) and isset($data['row']))
					  {
						$this->setFormatCode($data['add'].($idx+$data['row']),$data['format']);
					  }else{
						  if(isset($data['add'])){  
							 $this->setFormatCode($data['add'],$data['format']);
						  }	 
						} 
		   
		   }
		
		}
		
		
		if(isset($data['h']) and isset($data['v'])){
		   
		  if($ismerge)
		  {
   		      if(isset($data['mawl']) and isset($data['makh']) and isset($data['row']) and isset($data['mjml']))
			  { 
			     $this->setAlignment($data['mawl'].($idx+$data['row']).':'.$data['makh'].($idx+$data['row']+$data['mjml']),$data['h'],$data['v']);
		      }else{
		             if(isset($data['madd'])){ 
					    $this->setAlignment($data['madd'],$data['h'],$data['v']);
					 }	
				   }
		  }else{	  
		      if(isset($data['add']) and isset($data['row']))
		      {
		         $this->setAlignment($data['add'].($idx+$data['row']),$data['h'],$data['v']);
		      }else{
		          if(isset($data['add'])){  
				     $this->setAlignment($data['add'],$data['h'],$data['v']);
				  }	 
				} 
		   }
		}
		
		if(isset($data['font']) or isset($data['borders'])){
		    $tmp_font= isset($data['font']) ? $data['font']  :array();
			$tmp_borders=isset($data['borders']) ? $data['borders']  :array();
		   
		    if($ismerge) { 
			  if(isset($data['mawl']) and isset($data['makh']) and isset($data['row']) and isset($data['mjml']))
			  { 
			    $this->setStyle($data['mawl'].($idx+$data['row']).':'.$data['makh'].($idx+$data['row']+$data['mjml']),$tmp_font,$tmp_borders);
		      }else{
			      if(isset($data['madd'])){  
				   $this->setStyle($data['madd'],$tmp_font,$tmp_borders);
                  }				   
		       }
			}else{		
		       if(isset($data['add']) and isset($data['row']))
		       { 
				 $this->setStyle($data['add'].($idx+$data['row']),$tmp_font,$tmp_borders);
		       }else{
			       if(isset($data['add'])){ 
					  $this->setStyle($data['add'],$tmp_font,$tmp_borders);
					}
				  } 
			}  
		}
		
		if(isset($data['wborders'])){
		    $tmp_font= isset($data['font']) ? $data['font']  :array();
			$tmp_borders=isset($data['wborders']) ? $data['wborders']  :array();
		   
		    
			  if(isset($data['wbrdawl']) and isset($data['wbrdakh']) and isset($data['row']) and isset($data['wbrdjml']))
			  { 
			    $this->setStyle($data['wbrdawl'].($idx+$data['row']).':'.$data['wbrdakh'].($idx+$data['row']+$data['wbrdjml']),$tmp_font,$tmp_borders);
		      }
			
		}
		
		if(isset($data['row_height'])){
		  if(isset($data['row'])){
		  	$this->setRowHeight($data['row']+$idx,$data['row_height']);	
		  }		
		}
		
		
		if(isset($data['row_break'])){
		  if($data['row_break']){  
			if(isset($data['row']) and isset($data['jns_break'])){
		  	   $this->setBreak($data['add'].($idx+$data['row']),$data['jns_break']);
		    }
          } 			
		}
		
		if(isset($data['shrinktofit'])){
          
		  if($data['shrinktofit']){
		      if($ismerge) { 
			      if(isset($data['mawl']) and isset($data['makh']) and isset($data['row']) and isset($data['mjml']))
			      { 
			         $this->setShrinkToFit($data['mawl'].($idx+$data['row']).':'.$data['makh'].($idx+$data['row']+$data['mjml']),$data['shrinktofit']);
		          }else{
			              if(isset($data['madd'])){  
				                $this->setShrinkToFit($data['madd'],$data['shrinktofit']);
                          }				   
		               }
			  }else{
			       if(isset($data['add']) and isset($data['row']))
		           { 
				       $this->setShrinkToFit($data['add'].($idx+$data['row']),$data['shrinktofit']);
		           }else{
			             if(isset($data['add'])){ 
					       $this->setShrinkToFit($data['add'],$data['shrinktofit']);
					     }
				   }   
			   
			  }
		  }
		 
		}		
		
	 }    
   }
   
   function build_font($bold,$name,$size)
   {
             $tmp_font = array(
							'bold'      => $bold,
							'name'      => $name,
							'size'      => $size
						);
			  return $tmp_font; 			
   }
   
   function build_borders($inside,$outline)
   {
   
      $tmp_borders = array(
							'inside'     => array(
								'style' => $inside
							),
							'outline'     => array(
								'style' => $outline
							)
						);
	  return $tmp_borders;					
   
   }
   
   function insert_image($position,$x,$y,$width,$image)
   {
      $objDrawing = new PHPExcel_Worksheet_Drawing(); 
	  $objDrawing->setPath($image);
	  $objDrawing->setWidth($width);
	  $objDrawing->setOffsetX($x);
      $objDrawing->setOffsetY($y);
	  $objDrawing->setWorksheet($this->objPHPExcel->getActiveSheet());
	  $objDrawing->setCoordinates($position);
			
   }
   
  
}

?>