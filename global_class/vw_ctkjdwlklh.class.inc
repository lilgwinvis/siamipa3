<?php
require_once 'shared.php';
class vw_ctkjdwlklh extends vw_excel_basic 
{
   var $col_width_;
   var $jdl1;
   var $jdwl;
   var $pagefooter;
   
   function __construct()
   {
      parent::__construct();
	 
	  $this->col_width_=array("A"=>6.57,"B"=>6.29,"C"=>6.29,"D"=>3.43,"E"=>9.86,"F"=>12.43,"G"=>39.00,"H"=>30.70,"I"=>9.00);
	  
	  $tmp_font =$this->build_font(true,'Times New Roman',10);
	  $tmp_font1 = $this->build_font(true,'Calibri',9);
	 	    
	  $tmp_font2 = $tmp_font1;
	  $tmp_font2['bold']=false;
	  	  
	  $tmp_borders = $this->build_borders(BORDER_THIN,BORDER_MEDIUM);	 
	  
	  $this->jdl1=array(array('add'=>'A1','txt'=>'PROGRAM STUDI MATEMATIKA','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
	                   array('add'=>'A2','txt'=>'FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font),
					   array('add'=>'A3','txt'=>'UNIVERSITAS BALE BANDUNG','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font), 
                       
					   array('add'=>'A5','txt'=>'JADWAL KULIAH','madd'=>'A5:I5','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font),
					   array('add'=>'A6','txt'=>'','madd'=>'A6:I6','merge'=>true,'v'=>VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font),
					   
					   array('add'=>'A','row'=>8,'txt'=>'Hari','v'=>VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1,'wbrdawl'=>'A','wbrdakh'=>'I','wbrdjml'=>0,'wborders'=>$tmp_borders),
					   array('add'=>'B8','txt'=>'Awal','v'=>VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'C8','txt'=>'Akhir','v'=>VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'D8','txt'=>'Sem','v'=>VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),					   				   
					   array('add'=>'E8','txt'=>'Kelas','v'=>VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'F8','txt'=>'Kode Matakuliah','v'=>VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'G8','txt'=>'Nama Matakuliah','v'=>VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'H8','txt'=>'Nama Dosen','v'=>VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   array('add'=>'I8','txt'=>'Ruang Kelas','v'=>VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1)
					   
					   );

      $this->jdwl = array(array('add'=>'A','row'=>0,'txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2,'wbrdawl'=>'A','wbrdakh'=>'I','wbrdjml'=>0,'wborders'=>$tmp_borders),
					      array('add'=>'B','row'=>0,'txt'=>'','v'=>VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font2),
					      array('add'=>'C','row'=>0,'txt'=>'','v'=>VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font2),
					      array('add'=>'D','row'=>0,'txt'=>'','v'=>VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_RIGHT,'font'=>$tmp_font2),					   				   
					      array('add'=>'E','row'=>0,'txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					      array('add'=>'F','row'=>0,'txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					      array('add'=>'G','row'=>0,'txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					      array('add'=>'H','row'=>0,'txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2),
					      array('add'=>'I','row'=>0,'txt'=>'','v'=>VERTICAL_CENTER,'h'=>HORIZONTAL_LEFT,'font'=>$tmp_font2)
					      ); 
      
       
	  $this->pagefooter='&L&5Dicetak dari Sistem Informasi Akademik FMIPA UNIBBA pada tanggal : '.date("d-m-Y H:i:s").' &R&5dicetak ulang : &D &T'; 
   }
   
   function buatjdwlklh($dtjdwl,$dtdosen,$thn,$sem)
   {
            
			
	   if(!empty($dtjdwl))
       {		
			$this->setActiveSheetIndex(0);
			
			$this->setColumnWidth($this->col_width_);
	        
			
			$this->jdl1[4]['txt']="SEMESTER ".($sem == 1 ? "GANJIL" : "GENAP")." ".$thn."/".($thn+1);
			$this->tulis_data($this->jdl1);
			
			
			$kdds = "";
            $nmds = ""; 
			$brs=9;
	        $hari = array('','Senin','Selasa','Rabu','Kamis',"Jum"."'"."at",'Sabtu','Minggu');
			
			foreach($dtjdwl as $row)
		    {
			  foreach($row as $f=>$v)
		      {
				  switch($f){	 
					 case "hariklh"   :  $this->jdwl[0]['txt']=$hari[$v];break;
				     case "jawalklh"  :  $this->jdwl[1]['txt']=$v;break;
					 case "jakhirklh" :  $this->jdwl[2]['txt']=$v;break;
					 case "sem"       :  $this->jdwl[3]['txt']=$v;break;	 
					 case "shift"     :  $this->jdwl[4]['txt']=$v=='R' ? 'Reguler':'Non Reguler';break;
					 case "kdkmk"     :  $this->jdwl[5]['txt']=$v;break;
					 case "nakmktbkmk":  $this->jdwl[6]['txt']=$v;break;
					 case "kdds"    :  $kdds=$v;break;
					 case "nama"    :  $nmds=$v;break;
					 case "kdass"	:  $this->jdwl[7]['txt']=$v!="?????" ? $nmds.'('.$kdds.')'.'/'.$dtdosen->getnmdsn1($v).'('.$v.')' : $nmds.'('.$kdds.')';break;							 
					 case "rklh"    :  $this->jdwl[8]['txt']=$v;break;							 	
				 }			
			  }
			  $this->tulis_data($this->jdwl,$brs);			  
			  $brs++;
			}
			
			
			$this->setPageSetup(PHPExcel_Worksheet_PageSetup::ORIENTATION_LANDSCAPE,PHPExcel_Worksheet_PageSetup::PAPERSIZE_A4,true,true,100,1,4);
			$margin = 0.5 / 2.54;
			$this->setMargin($margin,$margin,$margin,$margin);
			
			$this->setFooter($this->pagefooter); 
      }			
   }

}

?>