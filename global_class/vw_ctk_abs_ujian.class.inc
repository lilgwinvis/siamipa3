<?php
require_once 'shared.php';

class vw_ctk_Abs_Ujian extends vw_excel_basic 
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
	   
	   $this->col_width_=array("A"=>4.00,"B"=>18.29,"C"=>2.14,"D"=>47.86,"E"=>2.14,"F"=>16.00,"G"=>2.14,"H"=>16.00);
	   
	   $tmp_font = $this->build_font(true,'Times New Roman',10);
	 
	   $tmp_font1 =$tmp_font;
	   $tmp_font1['size'] = 12;
	   
	   $tmp_font2 =$tmp_font;
	   $tmp_font2['bold'] = false;
	   
	   $tmp_font3 =$tmp_font;
	   $tmp_font3['size'] = 11;
	   
	   $tmp_font4 =$tmp_font2;
	   $tmp_font4['size'] = 11;
	   
	   $tmp_borders = $this->build_borders(PHPExcel_Style_Border::BORDER_THIN,PHPExcel_Style_Border::BORDER_MEDIUM);
	   
	   $this->jdl1=array(array('add'=>'A1','txt'=>'PROGRAM STUDI MATEMATIKA','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font),
	                     array('add'=>'A2','txt'=>'FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'A3','txt'=>'UNIVERSITAS BALE BANDUNG','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font), 
                       
					     array('add'=>'A6','txt'=>'','madd'=>'A6:H6','merge'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   
					     array('add'=>'A8','txt'=>'MATA KULIAH','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'A9','txt'=>'DOSEN','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'A10','txt'=>'Semester / Tahun Akademik','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'A11','txt'=>'Kelas','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font),
					   
					     array('add'=>'C8','txt'=>':','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'C9','txt'=>':','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'C10','txt'=>':','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'C11','txt'=>':','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font),				   
					   
					     array('add'=>'E8','txt'=>'PENGAWAS','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'E9','txt'=>'Hari/Tgl Ujian','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'E10','txt'=>'Jam Ujian','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'E11','txt'=>'Lama Ujian','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font),
					   
					     array('add'=>'G8','txt'=>':','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'G9','txt'=>':','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'G10','txt'=>':','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'G11','txt'=>':','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font),	

                         array('add'=>'H8','txt'=>'.....................................','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'H9','txt'=>'........ / ..... - ...... - ........','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'H10','txt'=>'..... : .....  s/d  ..... : ..... ','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'H11','txt'=>'..... Jam ..... Menit','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font),						 
					   
					     array('add'=>'A','row'=>13,'txt'=>'NO','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font,'wbrdawl'=>'A','wbrdakh'=>'H','wbrdjml'=>0,'wborders'=>$tmp_borders),
					     array('add'=>'B13','txt'=>'NIM','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'C13','txt'=>'NAMA','madd'=>'C13:D13','merge'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'E13','txt'=>'TANDA TANGAN','madd'=>'E13:H13','merge'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font),
					   );	
    
	$this->jdlmtk = array(array('add'=>'D8','txt'=>'','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font,'shrinktofit'=>true),
					       array('add'=>'D9','txt'=>'','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font,'shrinktofit'=>true),
					       array('add'=>'D10','txt'=>'','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font),
					       array('add'=>'D11','txt'=>'','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font));
	
	$this->isidata = array(array('add'=>'A','row'=>'0','txt'=>'','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font2),
					       array('add'=>'B','row'=>'0','txt'=>'','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font2),
					       array('add'=>'C','row'=>'0','txt'=>'','mawl'=>'C','makh'=>'D','mjml'=>0,'merge'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font2));
	
	$this->ttd = array(array('add'=>'E','row'=>0,'txt'=>'','mawl'=>'E','makh'=>'F','mjml'=>1,'merge'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_TOP,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font2),
		               array('add'=>'G','row'=>0,'txt'=>'','mawl'=>'G','makh'=>'H','mjml'=>1,'merge'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_TOP,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font2));
	
	$this->bdr = array(array('add'=>'A','row'=>14,'wbrdawl'=>'A','wbrdakh'=>'H','wbrdjml'=>0,'wborders'=>$tmp_borders));
	
    $this->jdl2=array(array('txt'=>'Pengawas Ujian','add'=>"G",'row'=>0,'merge'=>true,'mawl'=>'G','makh'=>'H','mjml'=>0,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font3,'wbrdawl'=>'G','wbrdakh'=>'H','wbrdjml'=>4,'wborders'=>$tmp_borders),
	                  array('txt'=>'( ......................... )','add'=>"G",'row'=>1,'merge'=>true,'mawl'=>'G','makh'=>'H','mjml'=>3,'v'=>PHPExcel_Style_Alignment::VERTICAL_BOTTOM,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font3),
					 				  
					  array('txt'=>'Pemberitahuan :','add'=>"A",'row'=>0,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font4),
	                  array('txt'=>'1. Jika nama anda tidak tercantum mohon segera lapor ke TU FMIPA','add'=>"A",'row'=>1,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font4),
					  array('txt'=>'2. Mahasiswa yang tidak tercantum namanya tidak berhak mengikuti ujian','add'=>"A",'row'=>2,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font4),
					  array('txt'=>'3. Sebelum ujian dimulai semua mahaasiswa harus memperlihatkan Kartu Ujian','add'=>"A",'row'=>3,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font4),
					  array('txt'=>'4. Serahkan kembali daftar hadir ini ke TU FMIPA','add'=>"A",'row'=>4,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font4),
					                    
	                 );					   
    						
	$this->pagefooter='&L&5Dicetak dari Sistem Informasi Akademik FMIPA UNIBBA pada tanggal : '.date("d-m-Y H:i:s").' &R&5dicetak ulang : &D &T'; 
	   
	   
	}

    function ctk_Abs_Ujian($data,$mk,$ds,$ta,$kls,$idx)
	{
	  $this->setActiveSheetIndex(0);
	  $this->setColumnWidth($this->col_width_);
	  
	  switch($idx){
	    case 1 : $this->jdl1[3]['txt'] = 'DAFTAR HADIR UJIAN TENGAH SEMESTER (UTS)';break;
		case 2 : $this->jdl1[3]['txt'] = 'DAFTAR HADIR UJIAN AKHIR SEMESTER (UAS)';break;
	  }
	  
	  
	  $this->tulis_data($this->jdl1);
	  	   
	  $this->jdlmtk[0]['txt'] = $mk;
	  $this->jdlmtk[1]['txt'] = $ds;
	  $this->jdlmtk[2]['txt'] = $ta;
	  $this->jdlmtk[3]['txt'] = $kls;
      
	  $this->tulis_data($this->jdlmtk);
	  
	  $start_row=13;
	  $i=1; 
		
	  if(!empty($data)){
	    
        foreach($data as $row){
		    
			$this->isidata['0']['txt']= $i;
			$this->isidata['1']['txt']= $row['nimhsmsmhs'];
			$this->isidata['2']['txt']= $row['nmmhsmsmhs'];
		   
		    $this->tulis_data($this->isidata,($start_row+$i));
			
			if(($i%2)!=0){
		         $this->ttd[0]['txt'] = $i;
		         $this->ttd[1]['txt'] = $i+1;
				 $this->tulis_data($this->ttd,($start_row+$i));
			}
		   
		    
		  $i=$i+1;
		}
		
		 if(($i%2)==0){
	         $this->isidata['0']['txt']= $i;
			 $this->isidata['1']['txt']= '';
			 $this->isidata['2']['txt']= '';
		   
		     $this->tulis_data($this->isidata,($start_row+$i));
	     }else{
	       $i--;
	     }		
	  }	
	     $this->bdr[0]['wbrdjml']=$i-1;
		 $this->tulis_data($this->bdr);			
		 $this->tulis_data($this->jdl2,$start_row+($i+2));		
         
		 	$this->setPageSetup(PHPExcel_Worksheet_PageSetup::ORIENTATION_LANDSCAPE,PHPExcel_Worksheet_PageSetup::PAPERSIZE_A4,true,true);
			$margin = 0.5 / 2.54;
			$this->setMargin($margin,$margin,$margin,$margin);
			
			$this->setFooter($this->pagefooter);
	  
	
	}

	
}

?>