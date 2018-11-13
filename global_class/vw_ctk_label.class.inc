<?php
require_once 'shared.php';
class vw_ctk_label extends vw_excel_basic 
{  
    var $col_width_;
    var $row_height_;
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
	   
	   $this->col_width_=array('A'=>27.86,'B'=>1.57,'C'=>2.14,'D'=>1.43,'E'=>8.43,'F'=>8.43,'G'=>1.14,'H'=>4.29,'I'=>8.43,'J'=>8.43);
	   $this->row_height_=array(14=>6.00,16=>6.00,18=>6.00,20=>6.00);

	   $tmp_font = $this->build_font(true,'Times New Roman',12);
	 
	   $tmp_font1 =$tmp_font;
	   $tmp_font1['size'] = 16;  
	  
	   	  	   
	   
	   $tmp_borders = $this->build_borders(BORDER_NONE,BORDER_MEDIUM);
	   
	   $this->jdl1=array(array('add'=>'A1','txt'=>'PROGRAM STUDI MATEMATIKA','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
	                     array('add'=>'A2','txt'=>'FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'A3','txt'=>'UNIVERSITAS BALE BANDUNG','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font), 
                       
					     array('add'=>'A6','txt'=>'BERKAS UJIAN','madd'=>'A6:J6','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   
					     array('add'=>'A8','txt'=>'Ujian','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'A9','txt'=>'Matakuliah','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'A10','txt'=>'Dosen','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'A11','txt'=>'Semester/Tahun Akademik','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'A12','txt'=>'Kelas','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'A13','txt'=>'Isi Amplop','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     
					     array('add'=>'B8','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'B9','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'B10','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'B11','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'B12','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'B13','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),				   
					   	 
					   	 array('add'=>'C8','txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					   	 array('add'=>'C9','txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
						 array('add'=>'C10','txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'C11','txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'C12','txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     
					     /*array('add'=>'C','row'=>15,'txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font,'borders'=>$tmp_borders),
					     array('add'=>'C','row'=>17,'txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font,'borders'=>$tmp_borders),
					     array('add'=>'C','row'=>19,'txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font,'borders'=>$tmp_borders),
					     array('add'=>'C','row'=>21,'txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font,'borders'=>$tmp_borders),*/				   
					   	 
						 array('add'=>'E15','txt'=>'Soal Ujian','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'E17','txt'=>'Lembar Jawaban','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'E19','txt'=>'Berita Acara','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'E21','txt'=>'Daftar Hadir','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					   
					     array('add'=>'G15','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'G17','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'G19','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'G21','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),							 
					   	 
						 array('add'=>'H15','txt'=>'...','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'H17','txt'=>'...','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'H19','txt'=>'3','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'H21','txt'=>'3','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
						 
						 array('add'=>'I15','txt'=>'Lembar','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'I17','txt'=>'Lembar','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'I19','txt'=>'Lembar','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'I21','txt'=>'Lembar','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font)				 
						
					   );	
    
	
	$this->bdr = array(array('add'=>'A','row'=>1,'wbrdawl'=>'A','wbrdakh'=>'J','wbrdjml'=>23,'wborders'=>$tmp_borders));

	$this->bdr1 = array(array('add'=>'C','row'=>15,'wbrdawl'=>'C','wbrdakh'=>'C','wbrdjml'=>0,'wborders'=>$tmp_borders));
	$this->bdr2 = array(array('add'=>'C','row'=>17,'wbrdawl'=>'C','wbrdakh'=>'C','wbrdjml'=>0,'wborders'=>$tmp_borders));
	$this->bdr3 = array(array('add'=>'C','row'=>19,'wbrdawl'=>'C','wbrdakh'=>'C','wbrdjml'=>0,'wborders'=>$tmp_borders));
	$this->bdr4 = array(array('add'=>'C','row'=>21,'wbrdawl'=>'C','wbrdakh'=>'C','wbrdjml'=>0,'wborders'=>$tmp_borders));
	
			
	//$this->pagefooter='&L&5Dicetak dari Sistem Informasi Akademik FMIPA UNIBBA pada tanggal : '.date("d-m-Y H:i:s").' &R&5dicetak ulang : &D &T'; 
}	   
	
   function ctk_label($mk,$ds,$sem,$ta,$kls)
	{
      $this->setActiveSheetIndex(0);
	  $this->setColumnWidth($this->col_width_);
	  $this->setRowHeight($this->row_height_);
	  
	  
	  $this->jdl1[16]['txt'] = 'UTS / UAS';  
	  $this->jdl1[17]['txt'] = $mk;
	  $this->jdl1[18]['txt'] = $ds;
	  $this->jdl1[19]['txt'] = $sem.'/'.$ta.'-'.($ta+1);
	  $this->jdl1[20]['txt'] = $kls;

	  
	  $this->tulis_data($this->jdl1);
	  $this->tulis_data($this->bdr);
	  $this->tulis_data($this->bdr1);
	  $this->tulis_data($this->bdr2);
	  $this->tulis_data($this->bdr3);
	  $this->tulis_data($this->bdr4);
	  	   
	        $this->setPageSetup(ORIENTATION_PORTRAIT,PAPERSIZE_A4,true,true);
			$margin = 0.5 / 2.54;
			$this->setMargin($margin,$margin,$margin,$margin);
			
			$this->setFooter($this->pagefooter);
	  
    } 	
	
}

?>