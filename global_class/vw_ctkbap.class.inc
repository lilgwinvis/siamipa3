<?php
require_once 'shared.php';

class vw_ctkbap extends vw_excel_basic 
{
   var $col_width_;
   var $jdl1;
   var $jdlmtk;
   var $bdr;
   var $rw_ujian;
   var $footer;
   
   function __construct()
   {
      parent::__construct();
	 
	  $this->col_width_=array("A"=>9.71,"B"=>13.00,"C"=>8.43,"D"=>8.43,"E"=>36.71,"F"=>44.14,"G"=>14.00,"H"=>10.00,"I"=>8.57,"J"=>8.43);
	  
	  
	  $tmp_font =$this->build_font(true,'Times New Roman',12);
	 
	  $tmp_font1 = $tmp_font;
	  $tmp_font1['size']=10;
	  
	  $tmp_font2 = $this->build_font(false,'Arial',10);
	  
	  $tmp_font3 = $tmp_font;
	  $tmp_font3['size']=20;
	  
	  
	  $tmp_borders = $this->build_borders(PHPExcel_Style_Border::BORDER_THIN,PHPExcel_Style_Border::BORDER_MEDIUM);	 
	  
	  $this->jdl1=array(array('add'=>'A1','txt'=>'PROGRAM STUDI MATEMATIKA','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font1),
	                   array('add'=>'A2','txt'=>'FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font1),
					   array('add'=>'A3','txt'=>'UNIVERSITAS BALE BANDUNG','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font1), 
                       
					   array('add'=>'A5','txt'=>'BERITA ACARA PERKULIAHAN','madd'=>'A5:J5','merge'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font),
					   
					   array('add'=>'A7','txt'=>'MATA KULIAH','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font1),
					   array('add'=>'A8','txt'=>'DOSEN','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font1),
					   array('add'=>'A9','txt'=>'Semester / Tahun Akademik','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font1),
					   array('add'=>'A10','txt'=>'Kelas','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font1),
					   				   
					   array('add'=>'A','row'=>12,'txt'=>'Pertemuan Ke','madd'=>'A12:A13','merge'=>true,'warp'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1,'wbrdawl'=>'A','wbrdakh'=>'J','wbrdjml'=>1,'wborders'=>$tmp_borders),
					   array('add'=>'B12','txt'=>'Tanggal (tgl/bln/th)','madd'=>'B12:B13','merge'=>true,'warp'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'C12','txt'=>'Waktu','madd'=>'C12:D12','merge'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'C13','txt'=>'Awal','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'D13','txt'=>'Akhir','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'E12','txt'=>'Materi (Rencana)','madd'=>'E12:E13','merge'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'F12','txt'=>'Materi (Realisasi)','madd'=>'F12:F13','merge'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'G12','txt'=>'Metode  Pembelajar-an *)','madd'=>'G12:G13','merge'=>true,'warp'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'H12','txt'=>'Jumlah siswa hadir','madd'=>'H12:H13','merge'=>true,'warp'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'I12','txt'=>'TTD  dosen','madd'=>'I12:I13','merge'=>true,'warp'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'J12','txt'=>'TTD Mhs','madd'=>'J12:J13','merge'=>true,'warp'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   );

      $this->jdlmtk = array(array('add'=>'C7','txt'=>'','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font1),
					       array('add'=>'C8','txt'=>'','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font1),
					       array('add'=>'C9','txt'=>'','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font1),
					       array('add'=>'C10','txt'=>'','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font1)); 
      
      $this->isidata = array(array('add'=>'A','row'=>'0','txt'=>'','row_height'=>50.25,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font2),
					         array('add'=>'B','row'=>'0','txt'=>'','font'=>$tmp_font2),
					         array('add'=>'C','row'=>'0','txt'=>'','font'=>$tmp_font2),
							 array('add'=>'D','row'=>'0','txt'=>'','font'=>$tmp_font2),
					         array('add'=>'E','row'=>'0','txt'=>'','font'=>$tmp_font2),
					         array('add'=>'F','row'=>'0','txt'=>'','font'=>$tmp_font2),
							 array('add'=>'G','row'=>'0','txt'=>'','font'=>$tmp_font2),
					         array('add'=>'H','row'=>'0','txt'=>'','font'=>$tmp_font2),
					         array('add'=>'I','row'=>'0','txt'=>'','font'=>$tmp_font2),
                             array('add'=>'I','row'=>'0','txt'=>'','font'=>$tmp_font2)
							 );	
      $this->bdr = array(array('add'=>'A','row'=>14,'wbrdawl'=>'A','wbrdakh'=>'J','wbrdjml'=>0,'wborders'=>$tmp_borders));	
      
      $this->rw_ujian = array(array('add'=>'A','row'=>0,'txt'=>'','row_height'=>20,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font2,'row_break'=>true,'jns_break'=>PHPExcel_Worksheet::BREAK_ROW),
	                          array('add'=>'B','row'=>0,'txt'=>'','mawl'=>'B','makh'=>'J','mjml'=>0,'merge'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font3) );   	  
	  
	   $tmp_font1['bold'] = false;
       $this->footer = array(array('add'=>'A','row'=>0,'txt'=>'*) Metode Pembalajaran cukup diisikan nomor yang dipilih saja (boleh memilih lebih dari satu metode pembelajaran dalam satu pertemuan)','font'=>$tmp_font1),
					         array('add'=>'A','row'=>2,'txt'=>'No','font'=>$tmp_font1),
					         array('add'=>'B','row'=>2,'txt'=>'Metode Pembelajaran','font'=>$tmp_font1),
					         array('add'=>'A','row'=>3,'txt'=>'1','font'=>$tmp_font1),
					         array('add'=>'B','row'=>3,'txt'=>'tutorial','font'=>$tmp_font1),
							 array('add'=>'A','row'=>4,'txt'=>'2','font'=>$tmp_font1),
					         array('add'=>'B','row'=>4,'txt'=>'diskusi','font'=>$tmp_font1),
							 array('add'=>'A','row'=>5,'txt'=>'3','font'=>$tmp_font1),
					         array('add'=>'B','row'=>5,'txt'=>'presentasi','font'=>$tmp_font1),
							 array('add'=>'A','row'=>6,'txt'=>'4','font'=>$tmp_font1),
					         array('add'=>'B','row'=>6,'txt'=>'evaluasi dengan quiz','font'=>$tmp_font1),
							 array('add'=>'A','row'=>7,'txt'=>'5','font'=>$tmp_font1),
					         array('add'=>'B','row'=>7,'txt'=>'evaluasi dengan tanya jawab lisan','font'=>$tmp_font1),
							 array('add'=>'A','row'=>8,'txt'=>'6','font'=>$tmp_font1),
					         array('add'=>'B','row'=>8,'txt'=>'evaluasi dengan penyelesaian masalah nyata','font'=>$tmp_font1),
							 );  
	  
   }
   
   function ctk_BAP($mk,$ds,$ta,$kls)
   {
      $this->setActiveSheetIndex(0);
	  $this->setColumnWidth($this->col_width_);
	  
	  $this->tulis_data($this->jdl1);
	  
	  $this->jdlmtk[0]['txt'] = ': '.$mk;
	  $this->jdlmtk[1]['txt'] = ': '.$ds;
	  $this->jdlmtk[2]['txt'] = ': '.$ta;
	  $this->jdlmtk[3]['txt'] = ': '.$kls;
      
	  $this->tulis_data($this->jdlmtk);
	  
	  $start_row=13;
	  
	  for ($i = 1; $i <= 16; $i++) 
	  {
	    if($i==8){
            $this->rw_ujian['0']['txt']= $i;
			$this->rw_ujian['0']['row_break']= true;
			$this->rw_ujian['1']['txt']= 'UTS';
		    $this->tulis_data($this->rw_ujian,($start_row+$i));
        }else{		
		  
		  if($i==16){
             $this->rw_ujian['0']['txt']= $i;
			 $this->rw_ujian['0']['row_break']= false;
			$this->rw_ujian['1']['txt']= 'UAS';
		    $this->tulis_data($this->rw_ujian,($start_row+$i));
          }else	{	  
			$this->isidata['0']['txt']= $i;
		    $this->tulis_data($this->isidata,($start_row+$i));
		   }
		}  
		  
	  }
	  
	   $this->bdr[0]['wbrdjml']=$i-2;
	   $this->tulis_data($this->bdr);	
	   
	   $this->tulis_data($this->footer,($start_row+$i+1));
	  
	   $this->setPageSetup(PHPExcel_Worksheet_PageSetup::ORIENTATION_LANDSCAPE,PHPExcel_Worksheet_PageSetup::PAPERSIZE_A4,true,false,86,12,13);
	   
	   
	   $margin = 0.5 / 2.54;
	   $this->setMargin($margin,$margin,$margin,$margin);
	   
   
   }

}

?>