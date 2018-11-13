<?php
  require_once 'shared.php';
  require '../vendor/autoload.php';
  use Dompdf\Dompdf;
  
  class vwtrans
  {
     var $vtrans;
	 
	 function __construct()
	 {
        $this->vtrans= new dt_trans;   
	 }   
		
      function filter_mhs()
	{
	  
	  $html_txt="<fieldset>";
	  $html_txt.="<legend>Filter</legend>";
	  
	  $vmhs = new dt_mhs;
	  $data = $vmhs->getAngkatan();
	  $thn = "";
	  foreach($data as $row)
	  {
	     foreach($row as $field => $value)
		 {
		    if(empty($thn))
			{
			  $thn=$value;
			}						
			  $ang[$value]=$value;						
		 }
	  } 			
	  
	   $data = $vmhs->getkls($thn);
	   $kls="";
	   foreach($data as $row)
	   {
		  foreach($row as $field => $value)
		  {
			if(empty($kls))
			{
			   $kls=$value;
			}
				if($value=='R')
				{
				  $tmp="Reguler";
				}else
				{
                  $tmp="Non Reguler";								
				}
						
			    $kelas[$value]=$value." - ".$tmp; 
						
			}
		} 	
	  
	  $data = $vmhs->getmhs($thn,$kls);
	  $vnim = "";
	  $vtemp= "";
	  foreach($data as $row)
	  {	
        if(empty($vnim))
		{
		  $vnim=$row['nimhsmsmhs'];
		  $vtemp = $row['nimhsmsmhs']."-".$row['nmmhsmsmhs'];
		}else{
		
		  if($vnim==$row['nimhsmsmhs'])
		  {
		    $vtemp = $row['nimhsmsmhs']."-".$row['nmmhsmsmhs'];
		  }
		
		}							   
						
		 $Mhs[$row['nimhsmsmhs']]=$row['nimhsmsmhs']."-".$row['nmmhsmsmhs']; 
						
	  }						
	  
	  $frm = new HTML_Form();
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmfilter"));
	  $tbl->addRow();
	  $tbl->addCell('Angkatan '.$frm->addSelectList("Angkatan",$ang,true,null,null,array('id'=>'Angkatan')).' Kelas '.$frm->addSelectList("kls",$kelas,true,null,null,array('id'=>'kls')).' Mahasiswa '.$frm->addSelectList("Mhs",$Mhs,true,null,null,array('id'=>'Mhs')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')).$frm->addInput('submit',"ctkexcel","Cetak Ke Excel",array('id'=>'ctkexcel')).$frm->addInput('submit',"ctkpdf","Cetak Ke Pdf",array('id'=>'ctkpdf')), null, 'data');
	   
	  $html_txt.=$tbl->display()."</fieldset>";

      $html_txt.="<fieldset>";
	  $html_txt.="<legend  id='hsl_filter'> Hasil Filter : ".$vtemp."</legend>";
      	  
	  
	  $html_txt.="<div id='data'>";
	  $html_txt.=$this->buildtrans($vnim);
	  $html_txt.="</div>";
	  
	  $html_txt.="</fieldset>";
        	  
	  
	  return $html_txt;
	  
	}
	
	  private function ismrhitl($iswp,$data)
	{
	   if($iswp=='p'){
	      return "<font color='red'><i>".$data."</i></font>";
	    }
		else{
	       return "$data";
		  
	   }
	} 
		
       function buildtrans($vnim)
	   {    
	   
	        $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_trans",'width'=>'100%'));
	        $tbl->addRow();
	        $tbl->addCell("Semester", null, 'header');
	        $tbl->addCell("Kode", null, 'header');
			$tbl->addCell("Matakuliah", null, 'header'); 
			$tbl->addCell("SKS", null, 'header');
	        $tbl->addCell("HM", null, 'header');
			$tbl->addCell("NM", null, 'header');
					   
						  
			  $data = $this->vtrans->getData($vnim);		  	  
		      $semestbkmk = "";
			if(!empty($data)){ 
			  foreach ($data as $row) 
			  {                    
			
			           $tbl->addRow();
	                   $tbl->addCell($row['semestbkmk'], null, 'data');
					   $tbl->addCell($row['kdkmktrnlm'], null, 'data');
					   $tbl->addCell($this->ismrhitl($row['wp'],$row['nakmktbkmk']), null, 'data');
		               $tbl->addCell($this->ismrhitl($row['wp'],$row['sksmktbkmk']), null, 'data');
					   $tbl->addCell($row['nlakhtrnlm'], null, 'data');
					   $tbl->addCell($row['bobottrnlm'], null, 'data');
					 
			    }
			}	
			
					$txt = "<tr>";
						$txt = $txt."<th></th>";
						$txt = $txt."<th><input type='hidden' name='search_sem' value='Search sem' class='search_init' /><input type='text' name='search_kode' value='Kode' class='search_init' style='width:150px'/></th>";
						$txt = $txt."<th><input type='text' name='search_mtk' value='Matakuliah' class='search_init' style='width:250px' /></th>";
						$txt = $txt."<th><input type='hidden' name='search_sks' value='Search sks' class='search_init' /></th>";
						$txt = $txt."<th><input type='text' name='search_hm' value='HM' class='search_init' style='width:20px'/></th>";
						$txt = $txt."<th></th>";
					$txt = $txt."</tr>";
			  
			return $tbl->display($txt);	   
		}	
        
		
		function ctk_excel($vnim)
	   {
		   			
			
						
			$dt_mhs = new dt_mhs;
			$data1=$dt_mhs->getData($vnim);
								  
			$data2 = $this->vtrans->getData($vnim);		  	  
		    								
			$dt=$this->vtrans->hitipk($vnim);
			$ipk =  $dt['jml_sksnm'] /$dt['jml_sks'];
			$sks =  $dt['jml_sks'];
					
			$tmp="../Admin/cetak/transkrip/Transkrip Nilai - ".$vnim.".xls";
			            
            $vwctktrans = new vw_ctktrans;
		    $vwctktrans->buattrans($data1,$data2,$sks,$ipk);
		    $vwctktrans->save($tmp);
			
			return $tmp;	   
		}

        function ctk_pdf($vnim)
	   {
		    
			
			$tbl4 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_jdl",'cellpadding'=>'2'));
	   
	        $tbl4->addRow();		  
		    $tbl4->addCell('<img src="../img/kop.jpg" alt="logo" width="100%" height="100%">','data');
            //$tbl4->addCell('<font face="Times New Roman" size="10pt">'.
	                     //'<b>YAYASAN PENDIDIKAN BALE BANDUNG<br>'.
					    //     'UNIVERSITAS BALE BANDUNG'.
				       //  '</b>'.
			          //   '</font>',null,'data');
	   
	        $jdl = $tbl4->display().			  
			  '<br><br>'.
	          '<center>'.
			            '<font face="Times New Roman" size="10pt">'.
						       '<b>TRANSKRIP NILAI</b>'.
					    '</font>'.
			  '</center><br><br>';
			 			
			$dt_mhs = new dt_mhs;
			$data=$dt_mhs->getData($vnim);
			foreach($data as $row){
		    	
				$tbl2 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_mhs","width"=>"100%"));       
				   $tbl2->addRow();		  
					  $tbl2->addCell('Nama','data');
					  $tbl2->addCell(':',null,'data');
					  $tbl2->addCell($row['nmmhsmsmhs'],null,'data');
					  $tbl2->addCell('Fakultas','data');
					  $tbl2->addCell(':',null,'data');
					  $tbl2->addCell('Matematika dan IPA',null,'data');				  
				   $tbl2->addRow();		  
					  $tbl2->addCell('Tempat/Tanggal Lahir','data');
					  $tbl2->addCell(':',null,'data');
					  $tbl2->addCell(trim($row['tplhrmsmhs'])." / ".date_format(date_create($row['tglhrmsmhs']),'d-m-Y'),null,'data');
					  $tbl2->addCell('Program Studi','data');
					  $tbl2->addCell(':',null,'data');
					  $tbl2->addCell('Matematika',null,'data');
				   $tbl2->addRow();		  
					  $tbl2->addCell('NIM',null,'data');
					  $tbl2->addCell(':',null,'data');
					  $tbl2->addCell($row['nimhsmsmhs'],null,'data');
					  $tbl2->addCell('Program Pendidikan','data');
					  $tbl2->addCell(':',null,'data');
					  $tbl2->addCell('S1',null,'data');
				
			}
					
			
			 $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_mtk","width"=>"100%",'border'=>'1','cellpadding'=>'2'));
	   
	         $tbl->addRow(); 
	         $tbl->addCell('Matakuliah',null,'header',array('rowspan'=>'2'));
	         $tbl->addCell('Kode',null,'header',array('rowspan'=>'2'));	  
	         $tbl->addCell('SKS',null,'header',array('rowspan'=>'2'));	 
	         $tbl->addCell('NILAI',null,'header',array('colspan'=>'3'));
			
			 $tbl->addCell('Matakuliah',null,'header',array('rowspan'=>'2'));
	         $tbl->addCell('Kode',null,'header',array('rowspan'=>'2'));	  
	         $tbl->addCell('SKS',null,'header',array('rowspan'=>'2'));	 
	         $tbl->addCell('NILAI',null,'header',array('colspan'=>'3'));
			
			
			 $tbl->addRow(); 
	         $tbl->addCell('HM',null,'header');
	         $tbl->addCell('AM',null,'header');	  
	         $tbl->addCell('NM',null,'header');	 
	         			
			 $tbl->addCell('HM',null,'header');
	         $tbl->addCell('AM',null,'header');	  
	         $tbl->addCell('NM',null,'header');	 
	         
						
						  
			  $data = $this->vtrans->getData($vnim);		  	  
		      
			  $i=1;
			  $j=1;
			  $cnt = 1;
			  $jml_data = count($data);
			if(!empty($data)){ 

			foreach ($data as $row) 
			  {
                 	$sks = $row['sksmktbkmk'];	
					$am = $row['bobottrnlm'];
					$nm = $sks*$am;
              
   			            if($cnt<=(($jml_data/2)+($jml_data%2==0 ? 0:1))){                      					   
					     $data_tmp['nama'] = $row['nakmktbkmk'];
						 $data_tmp['kd']   = $row['kdkmktrnlm'];						
						 $data_tmp['sks']  = $row['sksmktbkmk'];
                         $data_tmp['HM']   = $row['nlakhtrnlm'];
						 $data_tmp['AM']   = $row['bobottrnlm'];
						 $data_tmp['NM']   = $nm;
						 $data_kiri[] = $data_tmp;
						 $i++;
						}else{
						   if($cnt>(($jml_data/2)+($jml_data%2==0 ? 0:1)) and $cnt<=$jml_data){
								 $data_tmp['nama'] = $row['nakmktbkmk'];
						         $data_tmp['kd']   = $row['kdkmktrnlm'];						
						         $data_tmp['sks']  = $row['sksmktbkmk'];
                                 $data_tmp['HM']   = $row['nlakhtrnlm'];
						         $data_tmp['AM']   = $row['bobottrnlm'];
						         $data_tmp['NM']   = $nm;
								 $data_kanan[] = $data_tmp;
								 $j++;
							}	
						}
						
					 $cnt++;
					 
			    }
			    
			}
			
						
			for ($k=1;$k<=($i-1);$k++)
			{
			   
			   $tbl->addRow();
			  
                  
				     $data_tmp=$data_kiri[$k-1];
				    
					 $tbl->addCell($data_tmp['nama'],null,'data');
					 $tbl->addCell($data_tmp['kd'],null,'data');	  
					 $tbl->addCell($data_tmp['sks'],null,'data');	 
					 $tbl->addCell($data_tmp['HM'],null,'data');
					 $tbl->addCell($data_tmp['AM'],null,'data');
					 $tbl->addCell($data_tmp['NM'],null,'data');	  
					 		  
					if($k<=($j-1))
     				{    
						 $data_tmp=$data_kanan[$k-1];
					  
						 $tbl->addCell($data_tmp['nama'],null,'data');
						 $tbl->addCell($data_tmp['kd'],null,'data');	  
						 $tbl->addCell($data_tmp['sks'],null,'data');	 
						 $tbl->addCell($data_tmp['HM'],null,'data');
						 $tbl->addCell($data_tmp['AM'],null,'data');
						 $tbl->addCell($data_tmp['NM'],null,'data');	  
					}else
                      {
					     $tbl->addCell('',null,'data');
						 $tbl->addCell('',null,'data');	  
						 $tbl->addCell('',null,'data');	 
						 $tbl->addCell('',null,'data');
						 $tbl->addCell('',null,'data');
						 $tbl->addCell('',null,'data');						  
					  }					
			  
			}

           
		   $dt = $this->vtrans->hitipk($vnim);
		   $ipk =  $dt['jml_sksnm'] /$dt['jml_sks'];
		   $sks =  $dt['jml_sks'];
		   
		   $tbl3 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_ttd",'border'=>'1','width'=>'37%','cellpadding'=>'2'));
	   
	       $tbl3->addRow(); 
	       $tbl3->addCell('TOTAL SKS',null,'data');
	       $tbl3->addCell(':',null,'data');
           $tbl3->addCell(strval($sks),null,'data'); 		   
	       $tbl3->addRow(); 
		   $tbl3->addRow(); 
	       $tbl3->addCell('INDEX PRESTASI KUMULATIF (IPK)',null,'data');
	       $tbl3->addCell(':',null,'data');
           $tbl3->addCell(number_format($ipk, 2, ',', ' '),null,'data');
	       			
			//$objPHPExcel->getActiveSheet()->setCellValue('K'.($max+3),'Baleendah, ____________ 20___');
			
			//$objPHPExcel->getActiveSheet()->setCellValue('M'.($max+5),'___________');
			//$objPHPExcel->getActiveSheet()->setCellValue('M'.($max+8),'___________');
			
						
			
			 $html =
            '<html>'.
			'<style type="text/css">'.
			'table{font-family: Calibri; font-size: 8pt;}'.
			'</style>'.
			'<body>'.
			 $jdl.$tbl2->display().             
			 $tbl->display().
			 //$tbl1->display().
			'<br>'.$tbl3->display().
			'<br>'.'<font face="Calibri" size="9pt">Dicetak dari Sistem Informasi Akademik FMIPA UNIBBA pada tanggal '.date("d-m-Y H:i:s").'</font>'.
            '</body>'.
			'</html>';

			
		  
		  $tmp="../Admin/cetak/transkrip/Transkrip Nilai - ".$vnim.".pdf";
          
		  //$dompdf = new DOMPDF();
          //$dompdf->load_html($html);
          
          $dompdf = new Dompdf();
          $dompdf->loadHtml($html);

          $dompdf->setPaper('a4', 'portrait');
		  $dompdf->render();
          $output = $dompdf->output();
          file_put_contents($tmp, $output);
			
			
			return $tmp;	   
		}
         		
    }
?>