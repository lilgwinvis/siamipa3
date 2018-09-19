<?php
require_once 'shared.php';

class vw_ctkhnr extends vw_excel_basic 
{ 
   
   var $col_width_;
   var $jdl4per;
   var $jdl2per;
   var $jdlLB;
   var $jdlDTY;
   var $tblformat;
   var $tblformat4per;
   var $tblformat2per;
   
   var $footerLB1;
   var $footerLB2;
   
   var $footerDTY;
   var $pagefooter;
  

   function __construct()
   {
     parent::__construct();
	 
	 //$this->col_width_=array("A"=>3.00,"B"=>13.43,"C"=>4.29,"D"=>7.43,"E"=>15.86,"F"=>6.71,"G"=>1.86,"I"=>1.71,"J"=>6.86,"K"=>6.71,"L"=>6.86,"M"=>6.71,"N"=>6.86,"O"=>6.71,"P"=>6.86,"Q"=>6.71,"R"=>6.86,"S"=>14.71);
	 $this->col_width_=array("A"=>3.00,"B"=>13.43,"C"=>4.29,"D"=>7.43,"E"=>15.86,"F"=>6.71,"G"=>7.43,"H"=>7.43,"I"=>15.86,"J"=>15.86,"K"=>15.86);
	 
	 $tmp_font = $this->build_font(true,'Arial Narrow',10);
	 
	 $tmp_font1 =$tmp_font;
	 $tmp_font1['size'] = 12;

	 $tmp_font2 =$tmp_font;
     $tmp_font2['size'] = 9;					
     
	 $tmp_font3 = $this->build_font(true,'Berlin Sans FB Demi',10);
	 
	 $tmp_font4 = $this->build_font(true,'Bookman Old Style',12);
	 
	 $tmp_font5 = $tmp_font3;
	 $tmp_font5['size'] = 14;
	 
	 $tmp_font6 = $tmp_font;
	 $tmp_font6['bold'] = false;
	 
	 $tmp_font7 = $tmp_font;
	 $tmp_font7['bold'] = false; 
	 
	 
	 $tmp_borders = $this->build_borders(BORDER_MEDIUM,BORDER_MEDIUM);
	 $tmp_borders1 = $this->build_borders(BORDER_THIN,BORDER_MEDIUM);
	 
	 /*$this->jdlLB=array(array('add'=>'C','row'=>1,'txt'=>'No.Peng. Dana: .../S.Ad/FMIPA-UNIBBA/..../....','merge'=>true,'mawl'=>'C','makh'=>'K','mjml'=>0,'font'=>$tmp_font1,'borders'=>$tmp_borders),
	                   array('add'=>'M','row'=>1,'txt'=>'No.Mata Anggaran:','merge'=>true,'mawl'=>'M','makh'=>'P','mjml'=>0,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   array('add'=>'R','row'=>1,'txt'=>'No.Bukti:','merge'=>true,'mawl'=>'R','makh'=>'S','mjml'=>0,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   array('add'=>'A3','txt'=>'HONOR DAN TRANSPORT DOSEN LB PRODI MATEMATIKA','merge'=>true,'madd'=>'A3:S3','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font4),
	                   array('add'=>'A4','txt'=>'FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM (FMIPA)','merge'=>true,'madd'=>'A4:S4','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font4),
					   array('add'=>'A5','txt'=>'PERTEMUAN PERKULIAHAN PADA BULAN ... ...','merge'=>true,'madd'=>'A5:S5','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font4),
					   array('add'=>'A7','txt'=>'TAHUN AKADEMIK ...-...','merge'=>true,'madd'=>'A7:S7','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font4),
					   array('add'=>'A9','txt'=>'A. DOSEN LB PRODI MATEMATIKA','merge'=>true,'madd'=>'A9:S9','font'=>$tmp_font5),
					   array('add'=>'A','row'=>10,'txt'=>'NO.','merge'=>true,'mawl'=>'A','makh'=>'A','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font1,'borders'=>$tmp_borders),
	                   array('add'=>'B','row'=>10,'txt'=>'DOSEN/ASISTEN','merge'=>true,'mawl'=>'B','makh'=>'B','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   array('add'=>'C','row'=>10,'txt'=>'SMT','merge'=>true,'mawl'=>'C','makh'=>'C','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   array('add'=>'D','row'=>10,'txt'=>'KELAS','merge'=>true,'mawl'=>'D','makh'=>'D','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   array('add'=>'E','row'=>10,'txt'=>'MATA KULIAH','merge'=>true,'mawl'=>'E','makh'=>'E','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   array('add'=>'F','row'=>10,'txt'=>'SKS','merge'=>true,'mawl'=>'F','makh'=>'F','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'wbrdawl'=>'F','wbrdakh'=>'J','wbrdjml'=>1,'wborders'=>$tmp_borders1),
					   array('add'=>'G','row'=>10,'txt'=>'','merge'=>true,'mawl'=>'G','makh'=>'G','mjml'=>1,),
					   array('add'=>'H','row'=>10,'txt'=>'HONOR','merge'=>true,'mawl'=>'H','makh'=>'H','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'I','row'=>10,'txt'=>'','merge'=>true,'mawl'=>'I','makh'=>'I','mjml'=>1,),
					   array('add'=>'J','row'=>10,'txt'=>'TRANS.','merge'=>true,'mawl'=>'J','makh'=>'J','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1)
					   );*/
					   
      $this->jdlLB=array(array('add'=>'A','row'=>1,'txt'=>'No.Peng. Dana','font'=>$tmp_font1),
	                     array('add'=>'A','row'=>2,'txt'=>'No.Mata Anggaran','font'=>$tmp_font1),
					     array('add'=>'A','row'=>3,'txt'=>'No.Bukti','font'=>$tmp_font1),
					     array('add'=>'C','row'=>1,'txt'=>':','font'=>$tmp_font1),
	                     array('add'=>'C','row'=>2,'txt'=>':','font'=>$tmp_font1),
					     array('add'=>'C','row'=>3,'txt'=>':','font'=>$tmp_font1),
					     array('add'=>'D','row'=>1,'txt'=>'.../S.Ad/FMIPA-UNIBBA/..../....','font'=>$tmp_font1),
	                     array('add'=>'D','row'=>2,'txt'=>'...............................','font'=>$tmp_font1),
					     array('add'=>'D','row'=>3,'txt'=>'...............................','font'=>$tmp_font1),
					   
					   array('add'=>'A5','txt'=>'HONOR DAN TRANSPORT DOSEN LB PRODI MATEMATIKA','merge'=>true,'madd'=>'A5:K5','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font4),
	                   array('add'=>'A6','txt'=>'FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM (FMIPA)','merge'=>true,'madd'=>'A6:K6','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font4),
					   array('add'=>'A7','txt'=>'PERTEMUAN PERKULIAHAN PADA BULAN ... ...','merge'=>true,'madd'=>'A7:K7','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font4),
					   array('add'=>'A9','txt'=>'TAHUN AKADEMIK ...-...','merge'=>true,'madd'=>'A9:K9','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font4),
					   array('add'=>'A11','txt'=>'A. DOSEN LB PRODI MATEMATIKA','merge'=>true,'madd'=>'A11:K11','font'=>$tmp_font5),
					   array('add'=>'A','row'=>12,'txt'=>'NO.','merge'=>true,'mawl'=>'A','makh'=>'A','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font1,'borders'=>$tmp_borders),
	                   array('add'=>'B','row'=>12,'txt'=>'DOSEN/ASISTEN','merge'=>true,'mawl'=>'B','makh'=>'B','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   array('add'=>'C','row'=>12,'txt'=>'SMT','merge'=>true,'mawl'=>'C','makh'=>'C','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   array('add'=>'D','row'=>12,'txt'=>'KELAS','merge'=>true,'mawl'=>'D','makh'=>'D','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   array('add'=>'E','row'=>12,'txt'=>'MATA KULIAH','merge'=>true,'mawl'=>'E','makh'=>'E','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   array('add'=>'F','row'=>12,'txt'=>'SKS','merge'=>true,'mawl'=>'F','makh'=>'F','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),					  
					   array('add'=>'G','row'=>12,'txt'=>'HONOR','merge'=>true,'mawl'=>'G','makh'=>'H','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   array('add'=>'G','row'=>13,'txt'=>'NGAJAR','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),					   
					   array('add'=>'H','row'=>13,'txt'=>'TRANS.','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   array('add'=>'I','row'=>12,'txt'=>'JML. PERTEMUAN','merge'=>true,'mawl'=>'I','makh'=>'I','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   array('add'=>'J','row'=>12,'txt'=>'TOTAL HONOR','merge'=>true,'mawl'=>'J','makh'=>'J','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   array('add'=>'K','row'=>12,'txt'=>'TTD','merge'=>true,'mawl'=>'K','makh'=>'K','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders)
					   );
      

	  $this->jdlDTY= $this->jdlLB;
	  $this->jdlDTY[9]= array('add'=>'A5','txt'=>'HONOR DAN TRANSPORT DOSEN TETAP UNIBBA','merge'=>true,'madd'=>'A5:K5','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font4);
	  $this->jdlDTY[13]= array('add'=>'A11','txt'=>'B. HONOR DAN TRANSPORT DOSEN TETAP UNIBBA','merge'=>true,'madd'=>'A11:K11','font'=>$tmp_font5);
	 
	 
	  $this->jdl4per= array(array('add'=>'K','row'=>10,'txt'=>'Minggu ke ...','merge'=>true,'mawl'=>'K','makh'=>'L','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
	                          array('add'=>'K','row'=>11,'txt'=>'Pertemuan','font'=>$tmp_font2,'wbrdawl'=>'K','wbrdakh'=>'L','wbrdjml'=>0,'wborders'=>$tmp_borders1),
	                          array('add'=>'L11','txt'=>'Paraf','font'=>$tmp_font2),					   
	                          array('add'=>'M','row'=>10,'txt'=>'Minggu ke ...','merge'=>true,'mawl'=>'M','makh'=>'N','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
	                          array('add'=>'M','row'=>11,'txt'=>'Pertemuan','font'=>$tmp_font2,'wbrdawl'=>'M','wbrdakh'=>'N','wbrdjml'=>0,'wborders'=>$tmp_borders1),
	                          array('add'=>'N11','txt'=>'Paraf','font'=>$tmp_font2),
	                          array('add'=>'O','row'=>10,'txt'=>'Minggu ke ...','merge'=>true,'mawl'=>'O','makh'=>'P','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
	                          array('add'=>'O','row'=>11,'txt'=>'Pertemuan','font'=>$tmp_font2,'wbrdawl'=>'O','wbrdakh'=>'P','wbrdjml'=>0,'wborders'=>$tmp_borders1),
	                          array('add'=>'P11','txt'=>'Paraf','font'=>$tmp_font2),
	                          array('add'=>'Q','row'=>10,'txt'=>'Minggu ke ...','merge'=>true,'mawl'=>'Q','makh'=>'R','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
                              array('add'=>'Q','row'=>11,'txt'=>'Pertemuan','font'=>$tmp_font2,'wbrdawl'=>'Q','wbrdakh'=>'R','wbrdjml'=>0,'wborders'=>$tmp_borders1),
	                          array('add'=>'R11','txt'=>'Paraf','font'=>$tmp_font2),
	                          array('add'=>'S','row'=>10,'txt'=>'TOTAL HONOR','merge'=>true,'mawl'=>'S','makh'=>'S','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders));					   
	 
	  $this->jdl2per= array(array('add'=>'K','row'=>10,'txt'=>'Minggu ke ...','merge'=>true,'mawl'=>'K','makh'=>'L','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
	                          array('add'=>'K','row'=>11,'txt'=>'Pertemuan','font'=>$tmp_font2,'wbrdawl'=>'K','wbrdakh'=>'L','wbrdjml'=>0,'wborders'=>$tmp_borders1),
	                          array('add'=>'L11','txt'=>'Paraf','font'=>$tmp_font2),					   
	                          array('add'=>'M','row'=>10,'txt'=>'Minggu ke ...','merge'=>true,'mawl'=>'M','makh'=>'N','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
	                          array('add'=>'M','row'=>11,'txt'=>'Pertemuan','font'=>$tmp_font2,'wbrdawl'=>'M','wbrdakh'=>'N','wbrdjml'=>0,'wborders'=>$tmp_borders1),
	                          array('add'=>'N11','txt'=>'Paraf','font'=>$tmp_font2),
                              array('add'=>'O','row'=>10,'txt'=>'TOTAL HONOR','merge'=>true,'mawl'=>'O','makh'=>'O','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders));					   					   				   
								
      /*$this->tblformat = array(  array('txt'=>'','add'=>'A','row'=>0,'merge'=> true,'mawl'=>'A','makh'=>'A','mjml'=>2,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font6,'borders'=>$tmp_borders),
	                             array('txt'=>'','add'=>'B','row'=>0,'merge'=> true,'mawl'=>'B','makh'=>'B','mjml'=>2,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font6,'warp'=>true,'borders'=>$tmp_borders),
								 array('txt'=>'','add'=>'C','row'=>0,'merge'=> true,'mawl'=>'C','makh'=>'C','mjml'=>2,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font6,'borders'=>$tmp_borders),
								 array('txt'=>'','add'=>'D','row'=>0,'merge'=> true,'mawl'=>'D','makh'=>'D','mjml'=>2,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font6,'borders'=>$tmp_borders),
								 array('txt'=>'','add'=>'E','row'=>0,'merge'=> true,'mawl'=>'E','makh'=>'E','mjml'=>2,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font6,'warp'=>true,'borders'=>$tmp_borders),
								 array('txt'=>'','add'=>'F','row'=>0,'merge'=> true,'mawl'=>'F','makh'=>'F','mjml'=>2,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font6,'wbrdawl'=>'F','wbrdakh'=>'J','wbrdjml'=>2,'wborders'=>$tmp_borders1),
	                             array('txt'=>'x','add'=>'G','row'=>0,'merge'=> true,'mawl'=>'G','makh'=>'G','mjml'=>2,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font6),
								 array('txt'=>'','add'=>'H','row'=>0,'merge'=> true,'mawl'=>'H','makh'=>'H','mjml'=>2,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font6,'format'=>'#,##0'),
								 array('txt'=>'+','add'=>'I','row'=>0,'merge'=> true,'mawl'=>'I','makh'=>'I','mjml'=>2,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font6),
								 array('txt'=>'','add'=>'J','row'=>0,'merge'=> true,'mawl'=>'J','makh'=>'J','mjml'=>2,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font6,'format'=>'#,##0'),
								 array('txt'=>'','add'=>'S','row'=>0,'merge'=> true,'mawl'=>'S','makh'=>'S','mjml'=>2,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font7,'format'=>'#,##0','borders'=>$tmp_borders)	  
	                           );*/

       $this->tblformat = array(  array('txt'=>'','add'=>'A','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font6,'borders'=>$tmp_borders),
	                             array('txt'=>'','add'=>'B','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font6,'warp'=>true,'borders'=>$tmp_borders),
								 array('txt'=>'','add'=>'C','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font6,'borders'=>$tmp_borders),
								 array('txt'=>'','add'=>'D','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font6,'borders'=>$tmp_borders),
								 array('txt'=>'','add'=>'E','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font6,'warp'=>true,'borders'=>$tmp_borders),
								 array('txt'=>'','add'=>'F','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font6,'wbrdawl'=>'F','wbrdakh'=>'J','wbrdjml'=>2,'wborders'=>$tmp_borders1),
	                             array('txt'=>'','add'=>'G','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font6,'format'=>'#,##0','borders'=>$tmp_borders),
								 array('txt'=>'','add'=>'H','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font6,'format'=>'#,##0','borders'=>$tmp_borders),
								 array('txt'=>'','add'=>'I','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font6,'borders'=>$tmp_borders),
								 array('txt'=>'','add'=>'J','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font7,'format'=>'#,##0','borders'=>$tmp_borders),
								 array('txt'=>'','add'=>'K','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font6,'borders'=>$tmp_borders)	  
	                           );
	
      $this->tblformat4per=array(array('txt'=>'Ke:','add'=>'K','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font7,'wbrdawl'=>'K','wbrdakh'=>'L','wbrdjml'=>2,'wborders'=>$tmp_borders1),
	                             array('txt'=>'Tgl:','add'=>'K','row'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font7),
								 array('txt'=>'','add'=>'L','row'=>0,'merge'=> true,'mawl'=>'L','makh'=>'L','mjml'=>1),
								 array('txt'=>'','add'=>'K','row'=>2,'merge'=> true,'mawl'=>'K','makh'=>'L','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font7,'format'=>'#,##0'),
								 array('txt'=>'Ke:','add'=>'M','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font7,'wbrdawl'=>'M','wbrdakh'=>'N','wbrdjml'=>2,'wborders'=>$tmp_borders1),
	                             array('txt'=>'Tgl:','add'=>'M','row'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font7),
								 array('txt'=>'','add'=>'N','row'=>0,'merge'=> true,'mawl'=>'N','makh'=>'N','mjml'=>1),
								 array('txt'=>'','add'=>'M','row'=>2,'merge'=> true,'mawl'=>'M','makh'=>'N','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font7,'format'=>'#,##0'),
                                 array('txt'=>'Ke:','add'=>'O','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font7,'wbrdawl'=>'O','wbrdakh'=>'P','wbrdjml'=>2,'wborders'=>$tmp_borders1),
	                             array('txt'=>'Tgl:','add'=>'O','row'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font7),
								 array('txt'=>'','add'=>'P','row'=>0,'merge'=> true,'mawl'=>'P','makh'=>'P','mjml'=>1),
								 array('txt'=>'','add'=>'O','row'=>2,'merge'=> true,'mawl'=>'O','makh'=>'P','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font7,'format'=>'#,##0'),
                                 array('txt'=>'Ke:','add'=>'Q','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font7,'wbrdawl'=>'Q','wbrdakh'=>'R','wbrdjml'=>2,'wborders'=>$tmp_borders1),
	                             array('txt'=>'Tgl:','add'=>'Q','row'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font7),
								 array('txt'=>'','add'=>'R','row'=>0,'merge'=> true,'mawl'=>'R','makh'=>'R','mjml'=>1),
								 array('txt'=>'','add'=>'Q','row'=>2,'merge'=> true,'mawl'=>'Q','makh'=>'R','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font7,'format'=>'#,##0')								 
	                           );	
							   
      $this->tblformat2per=array(array('txt'=>'Ke:','add'=>'K','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font7,'wbrdawl'=>'K','wbrdakh'=>'L','wbrdjml'=>2,'wborders'=>$tmp_borders1),
	                             array('txt'=>'Tgl:','add'=>'K','row'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font7),
								 array('txt'=>'','add'=>'L','row'=>0,'merge'=> true,'mawl'=>'L','makh'=>'L','mjml'=>1),
								 array('txt'=>'','add'=>'K','row'=>2,'merge'=> true,'mawl'=>'K','makh'=>'L','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font7,'format'=>'#,##0'),
								 array('txt'=>'Ke:','add'=>'M','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font7,'wbrdawl'=>'M','wbrdakh'=>'N','wbrdjml'=>2,'wborders'=>$tmp_borders1),
	                             array('txt'=>'Tgl:','add'=>'M','row'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font7),
								 array('txt'=>'','add'=>'N','row'=>0,'merge'=> true,'mawl'=>'N','makh'=>'N','mjml'=>1),
								 array('txt'=>'','add'=>'M','row'=>2,'merge'=> true,'mawl'=>'M','makh'=>'N','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font7,'format'=>'#,##0'));
							   
	 
     						
							
     /*$this->footerLB1=array(   array('txt'=>'SUB TOTAL HONOR DAN TRANSPORT DOSEN LB FAK. MIPA BULAN ....','add'=>'A','row'=>0,'merge'=>true,'mawl'=>'A','makh'=>'R','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'borders'=>$tmp_borders),
	                          array('txt'=>'0','add'=>'S','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'format'=>'#,##0','borders'=>$tmp_borders),
	                       );  
  	 $this->footerLB2=array(  array('txt'=>'TOTAL HONOR DAN TRANSPORT DOSEN LB FAK. MIPA BULAN ....','add'=>'A','row'=>0,'merge'=>true,'mawl'=>'A','makh'=>'R','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'borders'=>$tmp_borders),
	                          array('txt'=>'0','add'=>'S','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'format'=>'#,##0','borders'=>$tmp_borders)
							 ); 
     $this->footerDTY=array(   array('txt'=>'SUB TOTAL HONOR DAN TRANSPORT DOSEN TETAP FAK. MIPA BULAN ....','add'=>'A','row'=>0,'merge'=>true,'mawl'=>'A','makh'=>'R','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'borders'=>$tmp_borders),
	                           array('txt'=>'0','add'=>'S','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'format'=>'#,##0','borders'=>$tmp_borders),
							   array('txt'=>'TOTAL HONOR DAN TRANSPORT DOSEN TETAP FAK. MIPA BULAN ....','add'=>'A','row'=>1,'merge'=>true,'mawl'=>'A','makh'=>'R','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'borders'=>$tmp_borders),
							   array('txt'=>'0','add'=>'S','row'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'format'=>'#,##0','borders'=>$tmp_borders),
							   array('txt'=>'TOTAL HONOR & TRANSPORT DOSEN FAK. MATEMATIKA & ILMU PENGETAHUAN ALAM (FMIPA) BULAN ...','add'=>'A','row'=>2,'merge'=>true,'mawl'=>'A','makh'=>'R','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'borders'=>$tmp_borders),
							   array('txt'=>'0','add'=>'S','row'=>2,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'format'=>'#,##0','borders'=>$tmp_borders)
							 );*/

	 $this->footerLB1=array(   array('txt'=>'SUB TOTAL HONOR DAN TRANSPORT DOSEN LB FAK. MIPA BULAN ....','add'=>'A','row'=>0,'merge'=>true,'mawl'=>'A','makh'=>'I','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'borders'=>$tmp_borders),
	                          array('txt'=>'0','add'=>'J','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'format'=>'#,##0','borders'=>$tmp_borders),
	                       );  
  	 $this->footerLB2=array(  array('txt'=>'TOTAL HONOR DAN TRANSPORT DOSEN LB FAK. MIPA BULAN ....','add'=>'A','row'=>0,'merge'=>true,'mawl'=>'A','makh'=>'I','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'borders'=>$tmp_borders),
	                          array('txt'=>'0','add'=>'J','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'format'=>'#,##0','borders'=>$tmp_borders)
							 ); 
     

     $this->footerDTY=array(   array('txt'=>'SUB TOTAL HONOR DAN TRANSPORT DOSEN TETAP FAK. MIPA BULAN ....','add'=>'A','row'=>0,'merge'=>true,'mawl'=>'A','makh'=>'I','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'borders'=>$tmp_borders),
	                           array('txt'=>'0','add'=>'J','row'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'format'=>'#,##0','borders'=>$tmp_borders),
							   array('txt'=>'TOTAL HONOR DAN TRANSPORT DOSEN TETAP FAK. MIPA BULAN ....','add'=>'A','row'=>1,'merge'=>true,'mawl'=>'A','makh'=>'I','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'borders'=>$tmp_borders),
							   array('txt'=>'0','add'=>'J','row'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'format'=>'#,##0','borders'=>$tmp_borders),
							   array('txt'=>'TOTAL HONOR & TRANSPORT DOSEN FAK. MATEMATIKA & ILMU PENGETAHUAN ALAM (FMIPA) BULAN ...','add'=>'A','row'=>2,'merge'=>true,'mawl'=>'A','makh'=>'I','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'borders'=>$tmp_borders),
							   array('txt'=>'0','add'=>'J','row'=>2,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_RIGHT,'font'=>$tmp_font3,'format'=>'#,##0','borders'=>$tmp_borders)
							 );						  							 
							 
	 $this->pagefooter='&L&5Dicetak dari Sistem Informasi Akademik FMIPA UNIBBA pada tanggal : '.date("d-m-Y H:i:s").' &R&5dicetak ulang : &D &T';						 
     				 
					   
   }

   
   function isi_data($awl,$row,$ctknm,$islb,$dthnrLB,$dthnrDTY,$is4per,$i) 
   {
      $this->tblformat[0]['txt']=($i+1);
	  $this->tblformat[1]['txt']= $ctknm ? $row['nama'] : '';
	  $this->tblformat[2]['txt']=$row['sem'];            
	  $this->tblformat[3]['txt']=$row['hnr'] == "R" ? "REG" : "NON REG";           
	  $this->tblformat[4]['txt']=$row['nakmktbkmk']; 			
	  $this->tblformat[5]['txt']=$row['sksmktbkmk'];
						
	  $hnr_ngajar = $islb ? $dthnrLB->getHonor($row['hnr'],$row['Hstat']) : $dthnrDTY->getHonor($row['hnr'],$row['Hstat']);
			
	  //$this->tblformat[7]['txt']=$hnr_ngajar;
	  $this->tblformat[6]['txt']=$hnr_ngajar;		
			
	  $trans_ngajar = $islb ? $dthnrLB->getTrans($row['hnr'],$row['Hstat']) : $dthnrDTY->getTrans($row['hnr'],$row['Hstat']);				
			
	  //$this->tblformat[9]['txt']=$trans_ngajar;
	  $this->tblformat[7]['txt']=$trans_ngajar;
	
      $this->tblformat[8]['txt']= $is4per ? 4 : 2;
      $this->tblformat[9]['txt']= '=(I'.$awl.'*(F'.$awl.'*G'.$awl.'))+(I'.$awl.'*H'.$awl.')';

	  /*$this->tblformat[10]['add']=  $is4per ? 'S' : 'O';
	  $this->tblformat[10]['mawl']=  $is4per ? 'S' : 'O';
	  $this->tblformat[10]['makh']=  $is4per ? 'S' : 'O';
	  $this->tblformat[10]['txt']=  $is4per ? "=K".($awl+2).'+M'.($awl+2).'+O'.($awl+2).'+Q'.($awl+2) : "=K".($awl+2).'+M'.($awl+2);*/


	  
	  /*if($is4per){
	    $this->tblformat4per[3]['txt']= "=F".$awl.'*H'.$awl."+J".$awl;
		$this->tblformat4per[7]['txt']= "=F".$awl.'*H'.$awl."+J".$awl;
		$this->tblformat4per[11]['txt']= "=F".$awl.'*H'.$awl."+J".$awl;
		$this->tblformat4per[15]['txt']= "=F".$awl.'*H'.$awl."+J".$awl;
	  
	  }else{
	    $this->tblformat2per[3]['txt']= "=F".$awl.'*H'.$awl."+J".$awl;
		$this->tblformat2per[7]['txt']= "=F".$awl.'*H'.$awl."+J".$awl;
	  
	  }*/
   
   }
   
   
   function buathnr($dtLB,$dthnrLB,$dtDTY,$dthnrDTY)
   {
      $this->setActiveSheetIndex(0);
      $this->setSheetTittle("HD LB");
	  
	  $this->setColumnWidth($this->col_width_);
	  
	  $this->tulis_data($this->jdlLB);
	  //$this->tulis_data($this->jdl4per);
	 
    if(!empty($dtLB))
        {
		  //$start_row=12;
		  $start_row=14;

		  $sub_start_row=$start_row;
		  $i=0;
		  
		  $nm_sm="";
		  $row_smawl=0;
		  $row_smakh=0;
		  $jml_sm=0;
		  
		  $isbreak=false;
		  $jml_break = 0;
		  $sub_total = array();
		  
		  foreach($dtLB as $row)
		  {
		    
			
			  //$awl = $start_row+($i*3)+$jml_break;			
			  $awl = $start_row+$i+$jml_break;			
			  //$akh = $awl+2;
			  $akh = $awl;
		   		    
					$idx_break = (($i>0) and (($i+1)<=9)) ? 20 : 21 ;  
					
					if((($i+1) % $idx_break)==0)
						{				     		 
						  $this->setBreak('A'.($akh+1),BREAK_ROW); 
						  
						  $this->footerLB1[1]['txt']= "=sum(".$this->footerLB1[1]['add'].$sub_start_row.":".$this->footerLB1[1]['add'].$akh.")";
						  $this->tulis_data($this->footerLB1,$akh+1);
						  $sub_total[]=$akh+1;
						  $sub_start_row=$akh+2;
						  
						  $isbreak=true;
						  $jml_break = $jml_break+1;				  
						}
			
			if($nm_sm!=$row['nama'])
			{
			   if($jml_sm>0)
			   {
			     $this->mergeCells("B". $row_smawl.":B".$row_smakh);
			     $this->mergeCells("K". $row_smawl.":K".$row_smakh);
			   }
			   
			   $this->isi_data($awl,$row,true,true,$dthnrLB,$dthnrDTY,true,$i);
			   
			   $row_smawl=$awl;			   
			   $nm_sm=$row['nama'];
			   $jml_sm=0;
               
               if($isbreak){
			    $row_smawl=$akh+2;			   
			   }
			   
               $isbreak=false;			   
			   
            }else{
			      $this->isi_data($awl,$row,true,true,$dthnrLB,$dthnrDTY,true,$i);
				  $row_smakh=$akh;	
				  
				  if($isbreak){
				      $this->mergeCells("B". $row_smawl.":B".$row_smakh);
				      $this->mergeCells("K". $row_smawl.":K".$row_smakh);
					  $row_smawl=$row_smakh+2;
					  $jml_sm=0;
				  }
				  else{				   			   
				    $jml_sm=$jml_sm+1;				   
				  } 			   
				   $isbreak=false;
				 }
			      
				 
			
			
			$this->tulis_data($this->tblformat,$awl);
			//$this->tulis_data($this->tblformat4per,$awl);
			$i=$i+1;
		  } 		  
			//$awl = $start_row+($i*3)+$jml_break;
            //$akh = $awl+2;
			$awl = $start_row+$i+$jml_break;
            $akh = $awl;

            if($jml_sm>0)
			   {
			     $this->mergeCells("B". $row_smawl.":B".$row_smakh);
			     $this->mergeCells("K". $row_smawl.":K".$row_smakh);
			   }
            
			$tmp_add='';
			foreach($sub_total as $idx)
			{
			  $tmp_add = $tmp_add .$this->footerLB2[1]['add'].$idx.'+';			
			}
						
			if($sub_start_row!=$awl)
            {			
			  $this->footerLB1[1]['txt']= "=sum(".$this->footerLB1[1]['add'].$sub_start_row.":".$this->footerLB1[1]['add'].($awl-1).")";            
              $this->tulis_data($this->footerLB1,$awl);
			  $tmp_add = $tmp_add .$this->footerLB2[1]['add'].$awl;
			  $awl=$awl+1;
			}
						
			$this->footerLB2[1]['txt']= '='.rtrim($tmp_add,'+');          
		    $this->tulis_data($this->footerLB2,$awl);
		  
		}

     $last_row=$awl;
	 
	 $this->setPageSetup(ORIENTATION_LANDSCAPE,PAPERSIZE_A4,true,false,100,10,11);
	  
	 $margin = 0.5 / 2.54;
	 $this->setMargin($margin,$margin,$margin,$margin);
	 
	 $this->setFooter($this->pagefooter);
	 
	 $this->createSheet(); 
	 $this->setActiveSheetIndex(1);
	 $this->setSheetTittle("HD Tetap");
	 
	 $this->setColumnWidth($this->col_width_);
	  
	  $this->tulis_data($this->jdlDTY);
	  //$this->tulis_data($this->jdl4per);
	  
      if(!empty($dtDTY))
        {
		  //$start_row=12;
		  $start_row=14;

		  $i=0;
		  
		  $nm_sm="";
		  $row_smawl=0;
		  $row_smakh=0;
		  $jml_sm=0;
		  
		  foreach($dtDTY as $row)
		  {
		    
			//$awl = $start_row+($i*3);
			//$akh = $start_row+($i*3)+2;
		    $awl = $start_row+$i;
			$akh = $start_row+$i;
  		    
			
			if($nm_sm!=$row['nama'])
			{
			   if($jml_sm>0)
			   {
			     $this->mergeCells("B". $row_smawl.":B".$row_smakh);
			     $this->mergeCells("K". $row_smawl.":K".$row_smakh);
			   }
			   
			   
               $this->isi_data($awl,$row,true,false,$dthnrLB,$dthnrDTY,true,$i);	   
			   $row_smawl=$awl;			   
			   $nm_sm=$row['nama'];
			   $jml_sm=0;
            }else{
			       $tmp_row[]=array('data'=>"",'addawl'=>$awl,'addakh'=>$akh);
				   $this->isi_data($awl,$row,false,false,$dthnrLB,$dthnrDTY,true,$i);
				   $row_smakh=$akh;				   
				   $jml_sm=$jml_sm+1;
				 } 
            			
			$this->tulis_data($this->tblformat,$awl);
			//$this->tulis_data($this->tblformat4per,$awl);
			$i=$i+1;
		  } 		  
			//$awl = $start_row+($i*3);
            //$akh = $start_row+($i*3)+2;
		    $awl = $start_row+$i;
            $akh = $start_row+$i;

            if($jml_sm>0)
			   {
			     $this->mergeCells("B". $row_smawl.":B".$row_smakh);
			     $this->mergeCells("K". $row_smawl.":K".$row_smakh);
			   }
			
		    $this->footerDTY[1]['txt']="=sum(".$this->footerDTY[1]['add'].$start_row.":".$this->footerDTY[1]['add'].($awl-1).")";
		    $this->footerDTY[3]['txt']="=sum(".$this->footerDTY[3]['add'].$start_row.":".$this->footerDTY[3]['add'].($awl-1).")";
            $this->footerDTY[5]['txt']="=sum(".$this->footerDTY[5]['add'].$start_row.":".$this->footerDTY[5]['add'].($awl-1).")+'HD LB'!".$this->footerDTY[5]['add'].$last_row;
			$this->tulis_data($this->footerDTY,$awl); 
			
			$this->setPageSetup(ORIENTATION_LANDSCAPE,PAPERSIZE_A4,true,false,100,1,11);
	  
	        $margin = 0.5 / 2.54;
	        $this->setMargin($margin,$margin,$margin,$margin);
			$this->setFooter($this->pagefooter);
			
		}
   
   
   
   }
   
   
   function buathnr2($dtLB,$dthnrLB,$dtDTY,$dthnrDTY)
   {
      $this->setActiveSheetIndex(0);
      $this->setSheetTittle("HD LB");
	  
	  $this->setColumnWidth($this->col_width_);
	  
	  $this->tulis_data($this->jdlLB);
	  $this->tulis_data($this->jdl2per);
	  

    if(!empty($dtLB))
        {
		  $start_row=12;
		  $sub_start_row=$start_row;
		  $i=0;
		  
		  $nm_sm="";
		  $row_smawl=0;
		  $row_smakh=0;
		  $jml_sm=0;
		  
		  $isbreak=false;
		  $jml_break = 0;
		  $sub_total = array();
		  
		  $this->footerLB1[0]['makh']='N';
		  $this->footerLB1[1]['add']='O';
			
		  $this->footerLB2[0]['makh']='N';
		  $this->footerLB2[1]['add']='O';
		  
		  foreach($dtLB as $row)
		  {
		    
			 $awl = $start_row+($i*3)+$jml_break;			
			 $akh = $awl+2;
		   
  		   	        $idx_break = (($i>0) and (($i+1)<=9)) ? 8 : 9 ;  
					
					if((($i+1) % $idx_break)==0)
						{				     		 
						  $this->setBreak('A'.($akh+1),BREAK_ROW); 
						  
						  $this->footerLB1[1]['txt']= "=sum(".$this->footerLB1[1]['add'].$sub_start_row.":".$this->footerLB1[1]['add'].$akh.")";
						  $this->tulis_data($this->footerLB1,$akh+1);
						  $sub_total[]=$akh+1;
						  $sub_start_row=$akh+2;
						  
						  $isbreak=true;
						  $jml_break = $jml_break+1;				  
						}
			
			if($nm_sm!=$row['nama'])
			{
			   if($jml_sm>0)
			   {
			     $this->mergeCells("B". $row_smawl.":B".$row_smakh);
			   }
			   
			   $this->isi_data($awl,$row,true,true,$dthnrLB,$dthnrDTY,false,$i); 
			   $row_smawl=$awl;			   
			   $nm_sm=$row['nama'];
			   $jml_sm=0;
			   
			    if($isbreak){
			       $row_smawl=$akh+2;			   
			    }
			   
                $isbreak=false;
			   
			   
            }else{
			       $this->isi_data($awl,$row,true,true,$dthnrLB,$dthnrDTY,false,$i); 
				   $row_smakh=$akh;	
				  
				  if($isbreak){
				      $this->mergeCells("B". $row_smawl.":B".$row_smakh);
					  $row_smawl=$row_smakh+2;
					  $jml_sm=0;
				  }
				  else{				   			   
				    $jml_sm=$jml_sm+1;				   
				  } 			   
				   $isbreak=false;
				 }  
            
			
			$this->tulis_data($this->tblformat,$awl);
			$this->tulis_data($this->tblformat2per,$awl);
			$i=$i+1;
		  } 		  
			$awl = $start_row+($i*3)+$jml_break;
            $akh = $awl+2;	
			
		    $tmp_add='';
			foreach($sub_total as $idx)
			{
			  $tmp_add = $tmp_add .$this->footerLB2[1]['add'].$idx.'+';			
			}
			     
			if($sub_start_row!=$awl){	 
				 $this->footerLB1[1]['txt']= "=sum(".$this->footerLB1[1]['add'].$sub_start_row.":".$this->footerLB1[1]['add'].($awl-1).")"; 
            	 $this->tulis_data($this->footerLB1,$awl);
				 $tmp_add = $tmp_add .$this->footerLB2[1]['add'].$awl;
			     $awl=$awl+1;
			}
			$this->footerLB2[1]['txt']= '='.rtrim($tmp_add,'+');
          		    
			$this->tulis_data($this->footerLB2,$awl);
			
		}

     $last_row=$awl;
	 
	    $this->setPageSetup(ORIENTATION_LANDSCAPE,PAPERSIZE_A4,true,false,100,10,11);
	  
	    $margin = 0.5 / 2.54;
	    $this->setMargin($margin,$margin,$margin,$margin);
		$this->setFooter($this->pagefooter);
	 
	 $this->createSheet(); 
	 $this->setActiveSheetIndex(1);
	 $this->setSheetTittle("HD Tetap");
	 
	 $this->setColumnWidth($this->col_width_);
	  
	  $this->tulis_data($this->jdlDTY);
	  $this->tulis_data($this->jdl2per);
	  	 
   
      if(!empty($dtDTY))
        {
		  $start_row=12;
		  $i=0;
		  
		  $nm_sm="";
		  $row_smawl=0;
		  $row_smakh=0;
		  $jml_sm=0;
		  
		  foreach($dtDTY as $row)
		  {
		   
			$awl = $start_row+($i*3);
			$akh = $start_row+($i*3)+2;
		   
  		   
			
			if($nm_sm!=$row['nama'])
			{
			   if($jml_sm>0)
			   {
			     $this->mergeCells("B". $row_smawl.":B".$row_smakh);
			   }
			   
			   $this->isi_data($awl,$row,true,false,$dthnrLB,$dthnrDTY,false,$i); 
			   $row_smawl=$awl;			   
			   $nm_sm=$row['nama'];
			   $jml_sm=0;
            }else{
			       $this->isi_data($awl,$row,false,false,$dthnrLB,$dthnrDTY,false,$i); 
				   $row_smakh=$akh;				   
				   $jml_sm=$jml_sm+1;
				 } 
            
			
			$this->tulis_data($this->tblformat,$awl);
			$this->tulis_data($this->tblformat2per,$awl);
			$i=$i+1;
		  } 		  
			$awl = $start_row+($i*3);
            $akh = $start_row+($i*3)+2;
			
		    $this->footerDTY[0]['makh']='N';
			$this->footerDTY[1]['add']='O';
			$this->footerDTY[2]['makh']='N';
			$this->footerDTY[3]['add']='O';
			$this->footerDTY[4]['makh']='N';
			$this->footerDTY[5]['add']='O';
			
			$this->footerDTY[1]['txt']="=sum(".$this->footerDTY[1]['add'].$start_row.":".$this->footerDTY[1]['add'].($awl-1).")";
		    $this->footerDTY[3]['txt']="=sum(".$this->footerDTY[3]['add'].$start_row.":".$this->footerDTY[3]['add'].($awl-1).")";
            $this->footerDTY[5]['txt']="=sum(".$this->footerDTY[5]['add'].$start_row.":".$this->footerDTY[5]['add'].($awl-1).")+'HD LB'!".$this->footerDTY[5]['add'].$last_row;
			$this->tulis_data($this->footerDTY,$awl);

            $this->setPageSetup(ORIENTATION_LANDSCAPE,PAPERSIZE_A4,true,false,100,10,11);
	  
	        $margin = 0.5 / 2.54;
	        $this->setMargin($margin,$margin,$margin,$margin);
			$this->setFooter($this->pagefooter);
			
		}
   
   
   
   }
   
   
   

   
}

?>