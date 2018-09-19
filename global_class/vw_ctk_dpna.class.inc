<?php
require_once 'shared.php';
class vw_ctk_dpna extends vw_excel_basic 
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
	   
	   $this->col_width_=array('A'=>5.00,'B'=>10.29,'C'=>8.86,'D'=>1.43,'E'=>6.14,'F'=>7.57,'G'=>9.00,'H'=>7.00,'I'=>7.00,'J'=>7.00,'K'=>7.00,'L'=>7.00,'M'=>7.14,'N'=>7.86,'O'=>19.57);
	   
	   $tmp_font = $this->build_font(true,'Times New Roman',10);
	 
	   $tmp_font1 =$tmp_font;
	   $tmp_font1['size'] = 12;
	   
	   $tmp_font2 =$tmp_font;
	   $tmp_font2['bold'] = false;
	   	  	   
	   $tmp_borders = $this->build_borders(BORDER_THIN,BORDER_MEDIUM);
	   
	   $this->jdl1=array(array('add'=>'A1','txt'=>'PROGRAM STUDI MATEMATIKA','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
	                     array('add'=>'A2','txt'=>'FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'A3','txt'=>'UNIVERSITAS BALE BANDUNG','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font), 
                       
					     array('add'=>'A6','txt'=>'DAFTAR NILAI AKHIR','madd'=>'A6:O6','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   
					     array('add'=>'A8','txt'=>'MATA KULIAH','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'A9','txt'=>'DOSEN','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'A10','txt'=>'Semester / Tahun Akademik','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'A11','txt'=>'Kelas','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					   
					     array('add'=>'D8','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'D9','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'D10','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'D11','txt'=>':','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),				   
					   	 					   
					     array('add'=>'A','row'=>13,'txt'=>'NO','madd'=>'A13:A14','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font,'wbrdawl'=>'A','wbrdakh'=>'O','wbrdjml'=>1,'wborders'=>$tmp_borders),
					     array('add'=>'B13','txt'=>'NIM','madd'=>'B13:B14','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'C13','txt'=>'NAMA','madd'=>'C13:G14','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'H13','txt'=>'KOMPONEN NILAI','madd'=>'H13:L13','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
						 array('add'=>'H14','txt'=>'Absensi','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'I14','txt'=>'Tugas','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'J14','txt'=>'Quiz','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'K14','txt'=>'UTS','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
						 array('add'=>'L14','txt'=>'UAS','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					     array('add'=>'M13','txt'=>'TOTAL NILAI','madd'=>'M13:M14','merge'=>true,'warp'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'N13','txt'=>'HURUF MUTU','madd'=>'N13:N14','merge'=>true,'warp'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
					     array('add'=>'O13','txt'=>'KETERANGAN','madd'=>'O13:O14','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font)
					   );	
    
	$this->jdlmtk = array(array('add'=>'E8','txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					       array('add'=>'E9','txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					       array('add'=>'E10','txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					       array('add'=>'E11','txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font));
	
	$this->isidata = array(array('add'=>'A','row'=>'0','txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font2),
					       array('add'=>'B','row'=>'0','txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					       array('add'=>'C','row'=>'0','txt'=>'','mawl'=>'C','makh'=>'G','mjml'=>0,'merge'=>true,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2));
	
	$this->bdr = array(array('add'=>'A','row'=>15,'wbrdawl'=>'A','wbrdakh'=>'O','wbrdjml'=>0,'wborders'=>$tmp_borders));
	
    $this->jdl2=array(array('txt'=> 'BOBOT KOMPONEN NILAI','add'=>'B','row'=>0,'merge'=>true,'mawl'=>'B','makh'=>'G','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font,'wbrdawl'=>'B','wbrdakh'=>'H','wbrdjml'=>2,'wborders'=>$tmp_borders),			
		        array('txt'=> 'TOTAL','add'=>'H','row'=>0,'merge'=>true,'mawl'=>'H','makh'=>'H','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),	
    	        array('txt'=> 'Absensi (%)','add'=>'B','row'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),		
				array('txt'=> 'Tugas (%)','add'=>'C','row'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),	
				array('txt'=> 'Quiz (%)','add'=>'D','row'=>1,'merge'=>true,'mawl'=>'D','makh'=>'E','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),	
				array('txt'=> 'UTS (%)','add'=>'F','row'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),	
				array('txt'=> 'UAS (%)','add'=>'G','row'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),		
				array('txt'=> '100%','add'=>'H','row'=>2,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
				array('txt'=> '','add'=>'D','row'=>2,'merge'=>true,'mawl'=>'D','makh'=>'E','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
			 
				array('txt'=>'RANGE NILAI','add'=>'B','row'=>4,'merge'=>true,'mawl'=>'B','makh'=>'C','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font,'wbrdawl'=>'B','wbrdakh'=>'F','wbrdjml'=>6,'wborders'=>$tmp_borders),
				array('txt'=> 'HURUF MUTU','add'=>'D','row'=>4,'merge'=>true,'mawl'=>'D','makh'=>'F','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
				array('txt'=> '.... < total nilai < 100','add'=>'B','row'=>5,'merge'=>true,'mawl'=>'B','makh'=>'C','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
				array('txt'=> '.... < total nilai < ...','add'=>'B','row'=>6,'merge'=>true,'mawl'=>'B','makh'=>'C','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
				array('txt'=> '.... < total nilai < ...','add'=>'B','row'=>7,'merge'=>true,'mawl'=>'B','makh'=>'C','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
				array('txt'=> '.... < total nilai < ...','add'=>'B','row'=>8,'merge'=>true,'mawl'=>'B','makh'=>'C','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
				array('txt'=> '0 < total nilai < ...','add'=>'B','row'=>9,'merge'=>true,'mawl'=>'B','makh'=>'C','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
				array('txt'=> 'Komponen Nilai','add'=>'B','row'=>10,'merge'=>true,'mawl'=>'B','makh'=>'C','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),  
				array('txt'=> 'A','add'=>'D','row'=>5,'merge'=>true,'mawl'=>'D','makh'=>'F','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
				array('txt'=> 'B','add'=>'D','row'=>6,'merge'=>true,'mawl'=>'D','makh'=>'F','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
				array('txt'=> 'C','add'=>'D','row'=>7,'merge'=>true,'mawl'=>'D','makh'=>'F','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
				array('txt'=> 'D','add'=>'D','row'=>8,'merge'=>true,'mawl'=>'D','makh'=>'F','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
				array('txt'=> 'E','add'=>'D','row'=>9,'merge'=>true,'mawl'=>'D','makh'=>'F','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
				array('txt'=> 'T','add'=>'D','row'=>10,'merge'=>true,'mawl'=>'D','makh'=>'F','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
			    
				array('txt'=> 'RUMUS TOTAL NILAI','add'=>'J','row'=>0,'merge'=>true,'mawl'=>'J','makh'=>'N','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font,'wbrdawl'=>'J','wbrdakh'=>'N','wbrdjml'=>2,'wborders'=>$tmp_borders),
				array('txt'=> '','add'=>'J','row'=>1,'merge'=>true,'mawl'=>'J','makh'=>'N','mjml'=>1,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
	  	        array('txt'=> 'MASUKAN UNTUK PROGRAM STUDI','add'=>'H','row'=>4,'merge'=>true,'mawl'=>'H','makh'=>'L','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font,'wbrdawl'=>'H','wbrdakh'=>'L','wbrdjml'=>6,'wborders'=>$tmp_borders),	  
				array('txt'=> '','add'=>'H','row'=>5,'merge'=>true,'mawl'=>'H','makh'=>'L','mjml'=>5,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
	            array('txt'=> 'TANDA TANGAN DOSEN','add'=>'N','row'=>4,'merge'=>true,'mawl'=>'N','makh'=>'O','mjml'=>0,'v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font,'wbrdawl'=>'N','wbrdakh'=>'O','wbrdjml'=>6,'wborders'=>$tmp_borders),	
		        array('txt'=> '','add'=>'N','row'=>5,'merge'=>true,'mawl'=>'N','makh'=>'O','mjml'=>5,'v'=>VERTICAL_BOTTOM,'h'=>HORIZONTAL_CENTER,'font'=>$tmp_font),
	                
					);					   
    
        
	    
		
	
	$this->pagefooter='&L&5Dicetak dari Sistem Informasi Akademik FMIPA UNIBBA pada tanggal : '.date("d-m-Y H:i:s").' &R&5dicetak ulang : &D &T'; 
}	   
	
   function ctk_DPNA($data,$mk,$ds,$ta,$kls,$nads)
	{
      $this->setActiveSheetIndex(0);
	  $this->setColumnWidth($this->col_width_);
	  
	  $this->tulis_data($this->jdl1);
	  	   
	  $this->jdlmtk[0]['txt'] = $mk;
	  $this->jdlmtk[1]['txt'] = $ds;
	  $this->jdlmtk[2]['txt'] = $ta;
	  $this->jdlmtk[3]['txt'] = $kls;
      
	  $this->tulis_data($this->jdlmtk);
	  
	  $start_row=14;
	  $i=1;
	  
	   if(!empty($data)){
	    
        foreach($data as $row){
		    
			$this->isidata['0']['txt']= $i;
			$this->isidata['1']['txt']= $row['nimhsmsmhs'];
			$this->isidata['2']['txt']= $row['nmmhsmsmhs'];
		   
		    $this->tulis_data($this->isidata,($start_row+$i));
			
			$i=$i+1;
		}
		
	   }	
	     $this->bdr[0]['wbrdjml']=$i-2;
		 $this->tulis_data($this->bdr);
		 
		 $this->setRowHeight($start_row+$i,6.00);
		 $this->setRowHeight($start_row+$i+4,6.00);
		 
		 $this->jdl2[28]['txt']='('.$nads.')';
		 
		 $this->tulis_data($this->jdl2,$start_row+($i+1));
		 
		 
		    $this->setPageSetup(ORIENTATION_LANDSCAPE,PAPERSIZE_A4,true,true);
			$margin = 0.5 / 2.54;
			$this->setMargin($margin,$margin,$margin,$margin);
			
			$this->setFooter($this->pagefooter);
	  
    } 	
	
}

?>