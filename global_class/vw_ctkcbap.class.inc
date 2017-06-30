<?php
require_once 'shared.php';
class vw_ctkcbap extends vw_excel_basic 
{
   
   var $jdl1;
   var $jdlmtk;
   
   
   function __construct()
   {
      parent::__construct();
	 
	    
	  $tmp_font =$this->build_font(true,'Times New Roman',12);
	 
	  $tmp_font1 = $tmp_font;
	  $tmp_font1['size']=20;
	    
	  $tmp_font2 = $tmp_font;
	  $tmp_font2['size']=16;
	  
	  
	  $tmp_borders = $this->build_borders(PHPExcel_Style_Border::BORDER_THIN,PHPExcel_Style_Border::BORDER_MEDIUM);	 
	  
	  $this->jdl1=array(array('add'=>'A1','txt'=>'PROGRAM STUDI MATEMATIKA','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font),
	                   array('add'=>'A2','txt'=>'FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font),
					   array('add'=>'A3','txt'=>'UNIVERSITAS BALE BANDUNG','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font), 
                       
					   array('add'=>'A6','txt'=>'BERITA ACARA PERKULIAHAN','madd'=>'A6:O6','merge'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   
					   array('add'=>'B9','txt'=>'MATA KULIAH','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font2),
					   array('add'=>'B10','txt'=>'DOSEN','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font2),
					   array('add'=>'B11','txt'=>'Semester / Tahun Akademik','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font2),
					   array('add'=>'B12','txt'=>'Kelas','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font2)					   				   
					   
					   );

      $this->jdlmtk = array(array('add'=>'F9','txt'=>'','madd'=>'F9:O9','merge'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font2,'shrinktofit'=>true),
					       array('add'=>'F10','txt'=>'','madd'=>'F10:O10','merge'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font2,'shrinktofit'=>true),
					       array('add'=>'F11','txt'=>'','madd'=>'F11:O11','merge'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font2,'shrinktofit'=>true),
					       array('add'=>'F12','txt'=>'','madd'=>'F12:O12','merge'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font2,'shrinktofit'=>true)); 
      
       
	  
   }
   
   function ctk_CBAP($mk,$ds,$ta,$kls)
   {
      $this->setActiveSheetIndex(0);	  
	  
	  $this->tulis_data($this->jdl1);
	  
	  $this->jdlmtk[0]['txt'] = ': '.$mk;
	  $this->jdlmtk[1]['txt'] = ': '.$ds;
	  $this->jdlmtk[2]['txt'] = ': '.$ta;
	  $this->jdlmtk[3]['txt'] = ': '.$kls;
      
	  $this->tulis_data($this->jdlmtk);	  	  
	  
	   $this->setPageSetup(PHPExcel_Worksheet_PageSetup::ORIENTATION_LANDSCAPE,PHPExcel_Worksheet_PageSetup::PAPERSIZE_A4,true,true);
	   	   
	   $margin = 0.5 / 2.54;
	   $this->setMargin($margin,$margin,$margin,$margin);
	   
   
   }

}

?>