<?php
require_once 'shared.php';

class vw_ctkdhmd extends vw_excel_basic 
{  var $col_width_;
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
	 
	 $this->col_width_=array("A"=>4.29,"B"=>7.57,"C"=>7.57,"D"=>7.57,"E"=>0.92,"F"=>7.57,"G"=>7.57,"H"=>7.57,"I"=>7.57,"J"=>2.57,"K"=>16,"L"=>2.57,"M"=>16);
	 	 	 
	 $tmp_font =$this->build_font(true,'Times New Roman',12);
	 
	$tmp_font1 = $tmp_font;
	$tmp_font1['size']=10;
	 
	 $tmp_font2 = $tmp_font;
	 $tmp_font2['size']=11;
	  
	 $tmp_font3 = $tmp_font;
	 $tmp_font3['size']=18;
	 
	 $tmp_font4 = $tmp_font1;
	 $tmp_font4['bold']=false; 
	 
     $tmp_borders = $this->build_borders(BORDER_THIN,BORDER_MEDIUM);	 
	 
	 $this->jdl1=array(array('add'=>'A1','txt'=>'PROGRAM STUDI MATEMATIKA','madd'=>'','merge'=>false,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font1),
	                   array('add'=>'A2','txt'=>'FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM','madd'=>'','merge'=>false,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font1),
					   array('add'=>'A3','txt'=>'UNIVERSITAS BALE BANDUNG','madd'=>'','merge'=>false,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font1), 
                       
					   array('add'=>'A6','txt'=>'DAFTAR HADIR KULIAH','madd'=>'A6:M6','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					   
					   array('add'=>'A8','txt'=>'MATA KULIAH','madd'=>'','merge'=>false,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font1),
					   array('add'=>'A9','txt'=>'DOSEN','madd'=>'','merge'=>false,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font1),
					   array('add'=>'A10','txt'=>'Semester / Tahun Akademik','madd'=>'','merge'=>false,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font1),
					   array('add'=>'A11','txt'=>'Kelas','madd'=>'','merge'=>false,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font1),
					   
					   array('add'=>'E8','txt'=>':','madd'=>'','merge'=>false,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'E9','txt'=>':','madd'=>'','merge'=>false,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'E10','txt'=>':','madd'=>'','merge'=>false,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'E11','txt'=>':','madd'=>'','merge'=>false,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1),				   
					   
					   array('add'=>'A','row'=>13,'txt'=>'NO','madd'=>'','merge'=>false,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font1,'wbrdawl'=>'A','wbrdakh'=>'M','wbrdjml'=>0,'wborders'=>$tmp_borders),
					   array('add'=>'B13','txt'=>'NIM','madd'=>'B13:E13','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'F13','txt'=>'NAMA','madd'=>'F13:I13','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'J13','txt'=>'TANDA TANGAN','madd'=>'J13:M13','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   );	
    
	$this->jdlmtk = array(array('add'=>'F8','txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font1),
					       array('add'=>'F9','txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font1),
					       array('add'=>'F10','txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font1),
					       array('add'=>'F11','txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font1));
	
	$this->isidata = array(array('add'=>'A','row'=>'0','txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font4),
					       array('add'=>'B','row'=>'0','txt'=>'','mawl'=>'B','makh'=>'E','mjml'=>0,'merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font4),
					       array('add'=>'F','row'=>'0','txt'=>'','mawl'=>'F','makh'=>'I','mjml'=>0,'merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font4));
	
	$this->ttd = array(array('add'=>'J','row'=>0,'txt'=>'','mawl'=>'J','makh'=>'K','mjml'=>1,'merge'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_TOP,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font4),
		               array('add'=>'L','row'=>0,'txt'=>'','mawl'=>'L','makh'=>'M','mjml'=>1,'merge'=>true,'v'=>PHPExcel_Style_Alignment::VERTICAL_TOP,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font4));
	
	$this->bdr = array(array('add'=>'A','row'=>14,'wbrdawl'=>'A','wbrdakh'=>'M','wbrdjml'=>0,'wborders'=>$tmp_borders));
	
    $this->jdl2=array(array('txt'=>'Jadwal Kuliah','add'=>"A",'row'=>0,'merge'=>true,'mawl'=>'A','makh'=>'D','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2,'wbrdawl'=>'A','wbrdakh'=>'D','wbrdjml'=>2,'wborders'=>$tmp_borders),
	                  array('txt'=>'Tanggal','add'=>"A",'row'=>1,'merge'=>true,'mawl'=>'A','makh'=>'B','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					  array('txt'=>'Mulai','add'=>"C",'row'=>1,'merge'=>false,'mawl'=>'C','makh'=>'C','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					  array('txt'=>'Selesai','add'=>"D",'row'=>1,'merge'=>false,'mawl'=>'D','makh'=>'D','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
	                  array('txt'=>'... / ... / ...','add'=>"A",'row'=>2,'merge'=>true,'mawl'=>'A','makh'=>'B','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					  array('txt'=>'.... : ....','add'=>"C",'row'=>2,'merge'=>false,'mawl'=>'C','makh'=>'C','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					  array('txt'=>'.... : ....','add'=>"D",'row'=>2,'merge'=>false,'mawl'=>'D','makh'=>'D','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					  
					  array('txt'=>'Jadwal Pengganti','add'=>"F",'row'=>0,'merge'=>true,'mawl'=>'F','makh'=>'I','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2,'wbrdawl'=>'F','wbrdakh'=>'I','wbrdjml'=>2,'wborders'=>$tmp_borders),
	                  array('txt'=>'Tanggal','add'=>"F",'row'=>1,'merge'=>true,'mawl'=>'F','makh'=>'G','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					  array('txt'=>'Mulai','add'=>"H",'row'=>1,'merge'=>false,'mawl'=>'H','makh'=>'H','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					  array('txt'=>'Selesai','add'=>"I",'row'=>1,'merge'=>false,'mawl'=>'I','makh'=>'I','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
	                  array('txt'=>'... / ... / ...','add'=>"F",'row'=>2,'merge'=>true,'mawl'=>'F','makh'=>'G','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					  array('txt'=>'.... : ....','add'=>"H",'row'=>2,'merge'=>false,'mawl'=>'H','makh'=>'H','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					  array('txt'=>'.... : ....','add'=>"I",'row'=>2,'merge'=>false,'mawl'=>'I','makh'=>'I','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					  
					  array('txt'=>'Pertemuan Ke','add'=>"K",'row'=>0,'merge'=>true,'mawl'=>'K','makh'=>'L','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2,'wbrdawl'=>'K','wbrdakh'=>'L','wbrdjml'=>2,'wborders'=>$tmp_borders),
	                  array('txt'=>'1','add'=>"K",'row'=>1,'merge'=>true,'mawl'=>'K','makh'=>'L','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font3),
					  
					  array('txt'=>'Tanda Tangan','add'=>"G",'row'=>4,'merge'=>true,'mawl'=>'G','makh'=>'M','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2,'wbrdawl'=>'G','wbrdakh'=>'M','wbrdjml'=>6,'wborders'=>$tmp_borders),
	                  array('txt'=>'Tata Usaha','add'=>"G",'row'=>5,'merge'=>true,'mawl'=>'G','makh'=>'I','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					  array('txt'=>'Dosen','add'=>"J",'row'=>5,'merge'=>true,'mawl'=>'J','makh'=>'K','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					  array('txt'=>'Mahasiswa','add'=>"L",'row'=>5,'merge'=>true,'mawl'=>'L','makh'=>'M','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
	                  array('txt'=>'( ........................... )','add'=>"G",'row'=>6,'merge'=>true,'mawl'=>'G','makh'=>'I','mjml'=>4,'v'=>VERTICAL_BOTTOM,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					  array('txt'=>'( ........................... )','add'=>"J",'row'=>6,'merge'=>true,'mawl'=>'J','makh'=>'K','mjml'=>4,'v'=>VERTICAL_BOTTOM,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					  array('txt'=>'( ........................... )','add'=>"L",'row'=>6,'merge'=>true,'mawl'=>'L','makh'=>'M','mjml'=>4,'v'=>VERTICAL_BOTTOM,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					  
					  array('txt'=>'Pemberitahuan :','add'=>"A",'row'=>12,'merge'=>false,'mawl'=>'A','makh'=>'A','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font4),
	                  array('txt'=>'1. Jika nama anda tidak tercantum mohon segera lapor ke TU FMIPA','add'=>"A",'row'=>13,'merge'=>false,'mawl'=>'A','makh'=>'A','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font4),
					  array('txt'=>'2. Mahasiswa yang tidak tercantum namanya tidak berhak mengikuti perkuliahan','add'=>"A",'row'=>14,'merge'=>false,'mawl'=>'A','makh'=>'A','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font4),
					  array('txt'=>'3. Serahkan kembali daftar hadir ini ke TU FMIPA','add'=>"A",'row'=>15,'merge'=>false,'mawl'=>'A','makh'=>'A','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font4)
					  
	                  
	                 );					   
    						
	$this->pagefooter='&L&5Dicetak dari Sistem Informasi Akademik FMIPA UNIBBA pada tanggal : '.date("d-m-Y H:i:s").' &R&5dicetak ulang : &D &T'; 
   }
   
   
   
   function ctk_DHMD($data,$mk,$ds,$ta,$kls)
   {
      $this->setActiveSheetIndex(0);
	  $this->setColumnWidth($this->col_width_);
	  
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
         
		 	$this->setPageSetup(ORIENTATION_LANDSCAPE,PAPERSIZE_A4,true,true);
			$margin = 0.5 / 2.54;
			$this->setMargin($margin,$margin,$margin,$margin);
			
			$this->setFooter($this->pagefooter);
   }
   
   
}

?>