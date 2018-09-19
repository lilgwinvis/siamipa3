<?php
require_once 'shared.php';

class vw_ctk_bau extends vw_excel_basic 
{  
    var $col_width_;
    var $jdl1;
	var $jdl2;
    var $jdlmtk;
    var $isidata;
    var $ttd;
   	var $bdr;
	var $pagefooter;

 
  function __construct()
  { 
       parent::__construct();
	   
	   $this->col_width_=array('A'=>17.14,'B'=>1.00,'C'=>9.43,'D'=>12.43,'E'=>8.43,'F'=>8.43,'G'=>8.43,'H'=>8.43);
	   
	   $tmp_font = $this->build_font(true,'Times New Roman',10);
	 
	   $tmp_font1 =$tmp_font;
	   $tmp_font1['size'] = 12;
	   
	   $tmp_font2 =$tmp_font;
	   $tmp_font2['size'] = 11;
	   	  	   
	   $tmp_borders = $this->build_borders(BORDER_THIN,BORDER_MEDIUM);
	   
	   $this->jdl1=array(array('add'=>'A1','txt'=>'PROGRAM STUDI MATEMATIKA','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
	                     array('add'=>'A2','txt'=>'FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'A3','txt'=>'UNIVERSITAS BALE BANDUNG','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font), 
                       
					     array('add'=>'A6','txt'=>'BERITA ACARA UJIAN','madd'=>'A6:H6','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   
					     array('add'=>'A8','txt'=>'Yang bertanda tangan di bawah ini :','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					   
					     array('add'=>'A10','txt'=>'Nama Pengawas','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					     array('add'=>'A11','txt'=>'Ujian','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					     array('add'=>'A12','txt'=>'Semester','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					     array('add'=>'A13','txt'=>'Tahun Akademik','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					   
					     array('add'=>'B10','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					     array('add'=>'B11','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					     array('add'=>'B12','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					     array('add'=>'B13','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),				   
					   	 
						 array('add'=>'C10','txt'=>'.....................................................................','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					     array('add'=>'C11','txt'=>'UTS / UAS','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					     array('add'=>'C12','txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					     array('add'=>'C13','txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),				   
					   	 
						 array('add'=>'A15','txt'=>'Menyatakan bahwa telah dilaksanakan ujian untuk :','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					   
					     array('add'=>'A17','txt'=>'Matakuliah','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					     array('add'=>'A18','txt'=>'Semester/Kelas','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					     array('add'=>'A19','txt'=>'Dosen','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					     array('add'=>'A20','txt'=>'Hari/Tanggal','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					     array('add'=>'A21','txt'=>'Waktu','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					   
					     array('add'=>'B17','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					     array('add'=>'B18','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					     array('add'=>'B19','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					     array('add'=>'B20','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),		
                         array('add'=>'B21','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),							 
					   	 
						 array('add'=>'C17','txt'=>'','madd'=>'C17:H17','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2,'shrinktofit'=>true),
					     array('add'=>'C18','txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					     array('add'=>'C19','txt'=>'','madd'=>'C19:H19','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2,'shrinktofit'=>true),
					     array('add'=>'C20','txt'=>'........................ / ............ - ............. - .............','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),	
                         array('add'=>'C21','txt'=>'.............. : ............. s/d .............. : ..................','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2), 
						 
						 array('add'=>'C','row'=>23,'txt'=>'Jumlah Mahasiswa','madd'=>'C23:E23','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2,'wbrdawl'=>'C','wbrdakh'=>'E','wbrdjml'=>2,'wborders'=>$tmp_borders),
					     array('add'=>'C24','txt'=>'Hadir','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					     array('add'=>'D24','txt'=>'Tidak Hadir','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					     array('add'=>'E24','txt'=>'Total','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
						 
						 array('add'=>'C','row'=>27,'txt'=>'Kartu Ujian','madd'=>'C27:E27','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2,'wbrdawl'=>'C','wbrdakh'=>'E','wbrdjml'=>2,'wborders'=>$tmp_borders),
					     array('add'=>'C28','txt'=>'Punya','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					     array('add'=>'D28','txt'=>'Tidak Punya','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					     array('add'=>'E28','txt'=>'Total','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
						 
					     array('add'=>'C','row'=>31,'txt'=>'Mahasiswa Tidak Punya Kartu Ujian','madd'=>'C31:F31','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2,'wbrdawl'=>'C','wbrdakh'=>'F','wbrdjml'=>5,'wborders'=>$tmp_borders),
					     array('add'=>'C32','txt'=>'NIM','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					     array('add'=>'D32','txt'=>'NAMA','madd'=>'D32:F32','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					    
						 array('add'=>'A38','txt'=>'Demikian Berita Acara ini saya buat sesuai dengan kondisi dilapangan dan  saya','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					     array('add'=>'A39','txt'=>'bersedia dikonfirmasi mengenai kebenaran data tertulis di atas.','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
						 
						 array('add'=>'A38','txt'=>'Demikian Berita Acara ini saya buat sesuai dengan kondisi dilapangan dan  saya','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					     array('add'=>'A39','txt'=>'bersedia dikonfirmasi mengenai kebenaran data tertulis di atas.','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
						 
						 array('add'=>'E42','txt'=>'Baleendah, .......... - ............-.............','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					     array('add'=>'E43','txt'=>'Pengawas Ujian','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
						 
						 array('add'=>'E47','txt'=>'( ....................................................... )','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
						
					   );	
    
	
	
	
			
	$this->pagefooter='&L&5Dicetak dari Sistem Informasi Akademik FMIPA UNIBBA pada tanggal : '.date("d-m-Y H:i:s").' &R&5dicetak ulang : &D &T'; 
}	   
	
   function ctk_BAU($mk,$ds,$sem,$ta,$kls,$isganjil)
	{
      $this->setActiveSheetIndex(0);
	  $this->setColumnWidth($this->col_width_);
	  
	  $this->jdl1[15]['txt'] = $isganjil == 1 ? 'GANJIL' : 'GENAP';
	  $this->jdl1[16]['txt'] = $ta;
	  
	  
	  $this->jdl1[28]['txt'] = $mk;
	  $this->jdl1[29]['txt'] = $sem.'/'.$kls;
	  $this->jdl1[30]['txt'] = $ds;
	  
	  $this->tulis_data($this->jdl1);
	  	   
	        $this->setPageSetup(ORIENTATION_PORTRAIT,PAPERSIZE_A4,true,true);
			$margin = 0.5 / 2.54;
			$this->setMargin($margin,$margin,$margin,$margin);
			
			$this->setFooter($this->pagefooter);
	  
    } 	
	
}

?>