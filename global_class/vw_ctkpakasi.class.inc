<?php
require_once 'shared.php';

class vw_ctkpakasi extends vw_excel_basic 
{ 
   
   var $col_width_;
   var $jdlR;
   var $jdlN;
   var $formatmtk;
   var $formatnm;
   var $formattotal;   
   
   var $pagefooter;
  

   function __construct()
   {
     parent::__construct();
	 
	 $this->col_width_=array("A"=>5.00,"B"=>27.00,"C"=>21.00,"D"=>7.00,"E"=>16.00,"F"=>2.00,"G"=>10.00,"H"=>16.00,"I"=>2.00,"J"=>10.00,"K"=>13.00,"L"=>8.00);
		 
	 $tmp_font = $this->build_font(true,'Times New Roman',18);
	 
	 $tmp_font1 =$tmp_font;
	 $tmp_font1['size'] = 12;

	 $tmp_font2 = $this->build_font(false,'Arial Narrow',10);;
        
     $tmp_font3 =$tmp_font2;
	 $tmp_font3['bold'] = true;	 
	 
	 $tmp_borders = $this->build_borders(PHPExcel_Style_Border::BORDER_MEDIUM,PHPExcel_Style_Border::BORDER_MEDIUM);
	 $tmp_borders1 = $this->build_borders(PHPExcel_Style_Border::BORDER_THIN,PHPExcel_Style_Border::BORDER_MEDIUM);
	 $tmp_borders2 = $this->build_borders(PHPExcel_Style_Border::BORDER_NONE,PHPExcel_Style_Border::BORDER_MEDIUM);
	
	 
	 $this->jdlR=array(array('add'=>'A2','txt'=>'LAMPIRAN SURAT','font'=>$tmp_font),
	                   array('add'=>'A4','txt'=>'Prodi Matematika','font'=>$tmp_font),
					   array('add'=>'A5','txt'=>'Kelas Reguler','font'=>$tmp_font),
					   array('add'=>'A','row'=>7,'txt'=>'NO.','merge'=>true,'mawl'=>'A','makh'=>'A','mjml'=>1,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font1,'borders'=>$tmp_borders),
	                   array('add'=>'B','row'=>7,'txt'=>'NAMA DOSEN/ASISTEN','merge'=>true,'mawl'=>'B','makh'=>'B','mjml'=>1,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   array('add'=>'C','row'=>7,'txt'=>'MATA KULIAH','merge'=>true,'mawl'=>'C','makh'=>'C','mjml'=>1,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   array('add'=>'D','row'=>7,'txt'=>'SMT','merge'=>true,'mawl'=>'D','makh'=>'D','mjml'=>1,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   
					   array('add'=>'E','row'=>7,'txt'=>'NASKAH','merge'=>true,'mawl'=>'E','makh'=>'G','mjml'=>0,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   array('add'=>'E','row'=>8,'txt'=>'JML NASKAH','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1,'wbrdawl'=>'E','wbrdakh'=>'G','wbrdjml'=>0,'wborders'=>$tmp_borders2),
					   array('add'=>'G','row'=>8,'txt'=>'HONOR','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   
					   array('add'=>'H','row'=>7,'txt'=>'PEMERIKSAAN','merge'=>true,'mawl'=>'H','makh'=>'J','mjml'=>0,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   array('add'=>'H','row'=>8,'txt'=>'JML MHS','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1,'wbrdawl'=>'H','wbrdakh'=>'J','wbrdjml'=>0,'wborders'=>$tmp_borders2),
					   array('add'=>'J','row'=>8,'txt'=>'HONOR','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1),
					   
					   array('add'=>'K','row'=>7,'txt'=>'JML UANG','merge'=>true,'mawl'=>'K','makh'=>'K','mjml'=>1,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders),
					   array('add'=>'L','row'=>7,'txt'=>'TTD','merge'=>true,'mawl'=>'L','makh'=>'L','mjml'=>1,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font1,'borders'=>$tmp_borders)
					   );
					   
	$this->formatmtk=array(array('add'=>'C','row'=>0,'txt'=>'','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font2,'shrinktofit'=>true),
						   array('add'=>'D','row'=>0,'txt'=>'','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font2),
						   
						   array('add'=>'E','row'=>0,'txt'=>1,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font2),
						   array('add'=>'F','row'=>0,'txt'=>'x','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font2),
						   array('add'=>'G','row'=>0,'txt'=>25000,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_RIGHT,'font'=>$tmp_font2,'format'=>'#,##0'),
						   						   
						   array('add'=>'H','row'=>0,'txt'=>0,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font2),
						   array('add'=>'I','row'=>0,'txt'=>'x','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font2),
						   array('add'=>'J','row'=>0,'txt'=>2000,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_RIGHT,'font'=>$tmp_font2,'format'=>'#,##0'),
						   
						   array('add'=>'K','row'=>0,'txt'=>'','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_RIGHT,'font'=>$tmp_font2,'format'=>'#,##0')
						   
						   );	

     $this->formatnm=array(array('add'=>'A','row'=>0,'txt'=>'','merge'=>true,'mawl'=>'A','makh'=>'A','mjml'=>1,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font2,'wbrdawl'=>'A','wbrdakh'=>'L','wbrdjml'=>1,'wborders'=>$tmp_borders1,'shrinktofit'=>true),
						   array('add'=>'B','row'=>0,'txt'=>'','merge'=>true,'mawl'=>'B','makh'=>'B','mjml'=>1,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_LEFT,'font'=>$tmp_font2),
						   
						   array('add'=>'C','row'=>1,'txt'=>'Jumlah','merge'=>true,'mawl'=>'C','makh'=>'J','mjml'=>0,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font3),
						   array('add'=>'K','row'=>1,'txt'=>'','v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_RIGHT,'font'=>$tmp_font3,'format'=>'#,##0'),
						   array('add'=>'L','row'=>0,'txt'=>'','merge'=>true,'mawl'=>'L','makh'=>'L','mjml'=>1,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font2),
						   						   
						   );

 	  $this->formattotal=array(array('add'=>'A','row'=>0,'txt'=>'TOTAL','merge'=>true,'mawl'=>'A','makh'=>'J','mjml'=>0,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_CENTER,'font'=>$tmp_font3,'wbrdawl'=>'A','wbrdakh'=>'L','wbrdjml'=>0,'wborders'=>$tmp_borders1),
	                           array('add'=>'K','row'=>0,'txt'=>0,'v'=>PHPExcel_Style_Alignment::VERTICAL_CENTER,'h'=>PHPExcel_Style_Alignment::HORIZONTAL_RIGHT,'font'=>$tmp_font3,'format'=>'#,##0'));					   
	  				   
	  $this->jdlN= $this->jdlR;
	  $this->jdlN[2]['txt']= 'Kelas Non Reguler'; 
	  						 
	  $this->pagefooter='&L&5Dicetak dari Sistem Informasi Akademik FMIPA UNIBBA pada tanggal : '.date("d-m-Y H:i:s").' &R&5dicetak ulang : &D &T';						 
     				 
					   
   }

   
  
   
   
   function buatpakasi($dtPR,$dtPN,$dtsebaran)
   {
      
	  $this->setActiveSheetIndex(0);
      $this->setSheetTittle("Reguler");
	  
	  
	  
	  if(!empty($dtPR))
      {
	      $this->setColumnWidth($this->col_width_);
	      $this->tulis_data($this->jdlR);
		  $start_row=9;
          $start_merge=9;
          $ht=0;		  
		  $i=0;
		  $j=0;
		  $nmds='';
		  $ctk=false;
		  $tot='=';
		  foreach($dtPR as $row)
		  {
		     if($nmds=='')
			 {
			   $nmds=$row['nama'];			   
			   $ctk=true;
			 }else{
			       if($nmds!=$row['nama'])
			       {
                      $nmds=$row['nama'];				
				      $ctk=true;
				      $i++;
					  $tot.='K'.($start_row+($i-1)).'+';
					  					  
					  $this->formatnm[0]['mjml']=$ht;
					  $this->formatnm[0]['wbrdjml']=$ht;
					  $this->formatnm[1]['mjml']=$ht;
					  $this->formatnm[2]['row']=$ht;
					  $this->formatnm[3]['row']=$ht;
					  $this->formatnm[3]['txt']='=sum(K'.$start_merge.':K'.($start_merge+($ht-1)).')';
					  $this->tulis_data($this->formatnm,$start_merge);
					  
					  
					  $start_merge=($start_row+$i);
				      $ht=0;
                   }else {
                           $ctk=false;
                         }				   
			 
			 }
			 
			 if($ctk)
			 { 
			   $this->formatnm[0]['txt']=($j+1);
			   $this->formatnm[1]['txt']=$row['nama'];			   
			   $j++;
			 }
			 
			 $this->formatmtk[1]['txt']=$row['sem'];		 
			 $jml=$dtsebaran->getjmlmhs($row['kdkmk'],$row['shift'],$row['sem']);
			 
			 $jml_mhs=0;
			 foreach($jml as $row)
			 {
			   $jml_mhs=$row['jml'];
			 }
			  
			  $this->formatmtk[0]['txt']=$row['nakmktbkmk'];			 
			  $this->formatmtk[5]['txt']=$jml_mhs;			  
			  $this->formatmtk[8]['txt']='=(E'.($start_row+$i).'*G'.($start_row+$i).')+(H'.($start_row+$i).'*J'.($start_row+$i).')';
			  
              $this->tulis_data($this->formatmtk,$start_row+$i); 			  
			 
			  $i++;
			  $ht++;
		  
		  }
	        $i++; 
                      $tot.='K'.($start_row+($i-1));
					  $this->formatnm[0]['mjml']=$ht;
					  $this->formatnm[0]['wbrdjml']=$ht;
					  $this->formatnm[1]['mjml']=$ht;
					  $this->formatnm[2]['row']=$ht;
					  $this->formatnm[3]['row']=$ht;
					  $this->formatnm[3]['txt']='=sum(K'.$start_merge.':K'.($start_merge+($ht-1)).')';
					  $this->tulis_data($this->formatnm,$start_merge);
					  			
	       $i++;
		   $this->formattotal[1]['txt']=rtrim($tot,'+');
	       $this->tulis_data($this->formattotal,$start_row+($i-1));
	  }
	     
	      
		     		 
	  
	  $this->setPageSetup(PHPExcel_Worksheet_PageSetup::ORIENTATION_LANDSCAPE,PHPExcel_Worksheet_PageSetup::PAPERSIZE_A4,true,false,100,7,8);
	  $margin = 0.5 / 2.54;
	  $this->setMargin($margin,$margin,$margin,$margin);
	  
	  	  
	  
	  $this->setFooter($this->pagefooter);
	  
      
	  
	  
	  if(!empty($dtPN))
      {
	      $this->createSheet(); 
	      $this->setActiveSheetIndex(1);
	      $this->setSheetTittle("NonReg");
	  
		  $this->setColumnWidth($this->col_width_);
	      $this->tulis_data($this->jdlN);    
		  $start_row=9;
          $start_merge=9;
          $ht=0;		  
		  $i=0;
		  $j=0;
		  $nmds='';
		  $ctk=false;
		  $tot='=';
		  foreach($dtPN as $row)
		  {
		     if($nmds=='')
			 {
			   $nmds=$row['nama'];			   
			   $ctk=true;
			 }else{
			       if($nmds!=$row['nama'])
			       {
                      $nmds=$row['nama'];				
				      $ctk=true;
				      $i++;
					  $tot.='K'.($start_row+($i-1)).'+';
					  
					  $this->formatnm[0]['mjml']=$ht;
					  $this->formatnm[0]['wbrdjml']=$ht;
					  $this->formatnm[1]['mjml']=$ht;
					  $this->formatnm[2]['row']=$ht;
					  $this->formatnm[3]['row']=$ht;
					  $this->formatnm[3]['txt']='=sum(K'.$start_merge.':K'.($start_merge+($ht-1)).')';
					  $this->tulis_data($this->formatnm,$start_merge);
					  					  
					  
					  $start_merge=($start_row+$i);
				      $ht=0;
                   }else {
                           $ctk=false;
                         }				   
			 
			 }
			 
			 if($ctk)
			 { 
			   $this->formatnm[0]['txt']=($j+1);
			   $this->formatnm[1]['txt']=$row['nama'];
			   $j++;
			 }
			 
			 
			 $this->formatmtk[1]['txt']=$row['sem'];
			 $jml=$dtsebaran->getjmlmhs($row['kdkmk'],$row['shift'],$row['sem']);
			 
			 $jml_mhs=0;
			 foreach($jml as $row)
			 {
			   $jml_mhs=$row['jml'];
			 }
			 
			  $this->formatmtk[0]['txt']=$row['nakmktbkmk'];			 
			  $this->formatmtk[5]['txt']=$jml_mhs;			  
			  $this->formatmtk[8]['txt']='=(E'.($start_row+$i).'*G'.($start_row+$i).')+(H'.($start_row+$i).'*J'.($start_row+$i).')';
			  
              $this->tulis_data($this->formatmtk,$start_row+$i);  
			 
			  $i++;
			  $ht++;
		  
		  }
	        $i++; 
	                  $tot.='K'.($start_row+($i-1));
					  $this->formatnm[0]['mjml']=$ht;
					  $this->formatnm[0]['wbrdjml']=$ht;
					  $this->formatnm[1]['mjml']=$ht;
					  $this->formatnm[2]['row']=$ht;
					  $this->formatnm[3]['row']=$ht;
					  $this->formatnm[3]['txt']='=sum(K'.$start_merge.':K'.($start_merge+($ht-1)).')';
					  $this->tulis_data($this->formatnm,$start_merge);
		   
		   $i++;
		   $this->formattotal[1]['txt']=rtrim($tot,'+');
	       $this->tulis_data($this->formattotal,$start_row+($i-1));		  
	  
	  }
	  
	  	  
	  $this->setPageSetup(PHPExcel_Worksheet_PageSetup::ORIENTATION_LANDSCAPE,PHPExcel_Worksheet_PageSetup::PAPERSIZE_A4,true,false,100,7,8);
	  $margin = 0.5 / 2.54;
	  $this->setMargin($margin,$margin,$margin,$margin);
	  
	  $this->setFooter($this->pagefooter);
	  
   }
   
   
   
   
   
   

   
}

?>