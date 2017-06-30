<?php
	require_once 'shared.php';
	
	class vw_krs
    {
      var $shift_;
	  function __construct()
	 {
	    $this->shift_ = array('R'=>'Reguler','N'=>'Non Reguler');
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
	 
	 function lht_krs($nim,$admin=1){
	   
	   $vmythnsem = new mythnsem;
	   $vbaca_krs = new dt_krs;
	   $vbaca_stat = new dt_stat_mhs;
	   $vbaca_poll = new dt_poll;
	   $vhtml = new html_element;
	   
	   $thnsms = $vmythnsem->getthnsem();	   
	   $thnsms_tmp = $vmythnsem->substhnsem('',1);
	   
        $dtbtn=array(array('type'=>'submit','id'=>'ambil','txt'=>'Ambil Mtk. Baru','attr_ar'=>array()),
		            array('type'=>'submit','id'=>'ulang','txt'=>'Ulang Mtk.','attr_ar'=>array()),
		            array('type'=>'submit','id'=>'edit','txt'=>'Edit Kelas','attr_ar'=>array()),
		            array('type'=>'submit','id'=>'hapus','txt'=>'Hapus Mtk.','attr_ar'=>array()));

	   
		$btn="";
		$jdl="Aksi";
		if($admin==1){		 
		 
		 $user = $_SESSION['user'];
	     
		            
		 $dtuser = new dt_user;
         $hak = $dtuser->gethak($user); 	
		 
		 if($hak==0)
		 {
			$dtbtn=array(array('type'=>'submit','id'=>'ambil','txt'=>'Ambil Mtk. Baru','attr_ar'=>array('disabled'=>'disabled')),
		            array('type'=>'submit','id'=>'ulang','txt'=>'Ulang Mtk.','attr_ar'=>array('disabled'=>'disabled')),
		            array('type'=>'submit','id'=>'edit','txt'=>'Edit Kelas','attr_ar'=>array('disabled'=>'disabled')),
		            array('type'=>'submit','id'=>'hapus','txt'=>'Hapus Mtk.','attr_ar'=>array('disabled'=>'disabled'))); 
		 }
		 
		 $dtbtn[]=array('type'=>'submit','id'=>'ctkexcel','txt'=>'Cetak ke Excel','attr_ar'=>array());
		 $dtbtn[]=array('type'=>'submit','id'=>'ctkpdf','txt'=>'Cetak Ke PDF','attr_ar'=>array());
		 $mybutton = new mybutton($dtbtn);
		 $btn = $mybutton->display(); 
		}else{
		   if($vbaca_stat->getstatmhs($thnsms,$nim,1)=="A")
		   {		  
		      if($vbaca_poll->cek_poll($thnsms_tmp,$nim)==0)
			  {
		   		         
			     $dtbtn[]=array('type'=>'submit','id'=>'ctkpdf','txt'=>'Cetak Ke PDF','attr_ar'=>array());
				 $mybutton = new mybutton($dtbtn);
		         $btn = $mybutton->display(); 
			  }else{
			  	$btn="<p>Sebelum mengisi Kartu Rencana Studi (KRS), Harap di isi beberapa kuosioner dibawah ini !!!</p>";
                $jdl="Pemberitahuan";				
			  }
			  
			  
		   }else{
		      $btn="<p>Anda berstatus '".$vbaca_stat->getstatmhs($thnsms,$nim)."' untuk dapat mengisi Kartu Rencana Studi (KRS) anda harus berstatus 'Aktif'</p>";
		      $jdl="Pemberitahuan";  
		   }
		}
			  
	   $html_txt = $vhtml->addfieldset($jdl,$btn,array());
	          
       
	   if(($vbaca_poll->cek_poll($thnsms_tmp,$nim)==1) and $admin==0)
	   {         
					   $vw_poll = new vw_poll;
					   $data= $vw_poll->view_mpoll($thnsms_tmp,$nim);					  
					   $html_txt .= $vhtml->addfieldset('Kuosioner',$data,array());
	   }   
	   else
       {
					   
					   $tbstat = array("id" => "lst_krs","width"=>"100%");
					   $header = array(array("Sem","Kode Mata Kuliah","Nama Mata Kuliah","SKS","Kelas","Tanggal Input"));
					   						 
						    $data = $vbaca_krs->getMtk($thnsms,$nim);
							$jmlsks=0;
							$dataisi = array();
							
							if(!empty($data)){ 
							  
							  foreach($data as $row){
							  
								if($row['sksprtbkmk']>0){
								   $sks=number_format($row['sksmktbkmk']-1, 2, '.', '');
								   $jmlsks+=$row['sksmktbkmk']-1;
								}else{
								   $sks=$row['sksmktbkmk'];
								   $jmlsks+=$row['sksmktbkmk'];				   
								}
											
								 
								 $tmp1=$this->shift_[$row['shiftkrs']];
								 
								 $tmpdt = array();
								 $tmpdt[]=array($row['semestbkmk'],array());
								 $tmpdt[]=array($row['kdkmkkrs'],array());
								 $tmpdt[]=array($this->ismrhitl($row['wp'],$row['nakmktbkmk']),array());
								 $tmpdt[]=array($this->ismrhitl($row['wp'],$sks),array());
								 $tmpdt[]=array($tmp1,array());
								 $tmpdt[]=array($row['tgl_input'],array());
								 $dataisi[]=$tmpdt;
								 
							  }			  
							}
					   
					   
					   
					   $tbl = new mytable($tbstat,$header,$dataisi,"");
					   $data= $tbl->display();					   
                       $html_txt .= $vhtml->addfieldset("Kartu Rencana Studi (KRS) ".$vmythnsem->gettxtthnsem(),$data,array());					   
	   
					   
					   $data= "<p>Jumlah SKS yg diambil = ".$jmlsks."</p>";					   
					   $html_txt .= $vhtml->addfieldset('Statistik',$data,array());
	   
					   if($admin==0)
					   {
						  $semester= $vmythnsem->gettxtthnsem($thnsms_tmp);	
						  $data = array("Dikarenakan Nilai ".$semester." belum keluar, perhitungan IPK menggunakan nilai yang sudah keluar.",
						                "Cetak KRS Online sebanyak 3 rangkap, 1 untuk dokumentasi anda, 1 untuk TU Fakultas, 1 untuk Dosen Wali.",
						                "Cetak Transkrip Online sebanyak 3 rangkap, 1 untuk dokumentasi anda, 1 untuk TU Fakultas, 1 untuk Dosen Wali.");
                          $data = $vhtml->addol($data);  										
						  $html_txt .= $vhtml->addfieldset('Informasi',$data,array());
						}
	   
	   }
	   
	   
	   
	   return $html_txt;
	 
	 } 
	 
	 function build_krs($nim,$baru=1){
	    		
		$vhtml = new html_element; 
		$vform = new html_form;
		$vdt_mhs = new dt_mhs;
		
		$tbstat = array("id" => "lst_mtk","width"=>"100%");
		$header = array(array("Sem","Kode Mata Kuliah","Nama Mata Kuliah","SKS","Ambil","Kelas"));
		$dataisi = array();
		
		$kls = $vdt_mhs->getshiftmhs($nim);	
		
		$vbuild_krs = new dt_krs;
		$data = $vbuild_krs->buildkrs($nim,$baru);
		
		if(!empty($data)){
		$i=0;
		  foreach($data as $row){
		         $tmpdt = array();
				 $tmpdt[]=array($row['semestbkmk'], array());
				 $tmpdt[]=array($row['kdkmktbkmk'], array());
				 $tmpdt[]=array($this->ismrhitl($row['wp'],$row['nakmktbkmk']), array());
				 $tmpdt[]=array($this->ismrhitl($row['wp'], $row['sksmktbkmk']), array()); 
			     $tmp_kd=$row['kdkmktbkmk'];
				 $tmp_input = $vform->addInput('checkbox','mk[]',$tmp_kd,array('id'=>'mk'));
				 $tmpdt[]=array($tmp_input,array('align'=>'center')); 
				 $tmp_input = $vform->addSelectList("kls[".$tmp_kd."]",array('R'=>'Reguler','N'=>'Non Reguler'),true,$kls,null,array('id'=>'kls'));				
				 $tmpdt[]=array($tmp_input, array()); 
				 $i++;
				 $dataisi[]=$tmpdt;
		  }
		}
	   
	   $tb1stat = array("id" => "jml_sks","width"=>"100%");
	   $data1isi = array();
	   $tmp_input =	$vform->addInput('text','Jumlah','0',array('id'=>'jsks','name'=>'totalsks','size'=>'3','maxlength'=>'3','readonly'=>'readonly','style'=>'text-align:center; color:red;'));	
	   $data1isi[] =array(array("<b>JUMLAH SKS YANG DIAMBIL</b>",array('colspan'=>3,'align'=>'center')),array($tmp_input,array('align'=>'center')));  
	   
	   $tbl = new mytable($tbstat,$header,$dataisi,"");
	   $tbl1 = new mytable($tb1stat,NULL,$data1isi,"");
       
	   $html_txt = $vform->startForm('isikrs.php','post','inputkrs');
	   $html_txt .= $vform->addInput('hidden','nim',$nim);
	   $html_txt .= $tbl->display().$tbl1->display().$vform->endForm(); 	   
	   
	   
	   $html_txt = $vhtml->addfieldset("Daftar Matakuliah",$html_txt,array());
	   
	   return $html_txt;
	 }
	 
	 function olah_krs($nim,$hapus=0){
	   
	   $vhtml = new html_element; 
	   $vform = new html_form;
	  
      
	    $tbstat = array("id" => "lst_krs","width"=>"100%");
		$header = array(array("Sem","Kode Mata Kuliah","Nama Mata Kuliah","SKS"));
		$dataisi = array();	  
	   	    
		$header[0][]=$hapus==0 ? "Kelas" : "Hapus";
		
		  
		  $vbaca_krs = new dt_krs;
		  $thnsms = $vbaca_krs->TA();
		 
		  $data = $vbaca_krs->getMtk($thnsms,$nim,0);
		    $jmlsks=0;
			if(!empty($data)){ 
			  foreach($data as $row){
			  
			    if($row['sksprtbkmk']>0 and $hapus==0){
                   $sks=number_format($row['sksmktbkmk']-1, 2, '.', '');
                   $jmlsks+=$row['sksmktbkmk']-1;
				}else{
				   $sks=$row['sksmktbkmk'];
                   $jmlsks+=$row['sksmktbkmk'];				   
				}
							
                 		 
				 $tmpdt = array();
				 $tmpdt[]=array($row['semestbkmk'], array());
				 $tmpdt[]=array($row['kdkmkkrs'], array());
				 $tmpdt[]=array($this->ismrhitl($row['wp'],$row['nakmktbkmk']), array());
				 $tmpdt[]=array($this->ismrhitl($row['wp'],$sks), array()); 
			    if($hapus==0)
				{ 						
					 $tmp_kd=$row['kdkmkkrs'];
				     $tmp_input = $vform->addSelectList("kls[".$tmp_kd."]",array('R'=>'Reguler','N'=>'Non Reguler'),true,$row['shiftkrs'],null,array('id'=>'kls'));	
				 
				}else{
				   $tmp_kd=$row['kdkmkkrs'];
				   $tmp_input = $vform->addInput('checkbox','mk[]',$tmp_kd,array('id'=>'mk')); 
				 }
				  $tmpdt[]=array($tmp_input, array());
				  $dataisi[]=$tmpdt;  
                }			  
            }
       
	   
	   
	   $html_txt  = $vform->startForm('isikrs.php','post','inputkrs');
	   $html_txt .= $vform->addInput('hidden','nim',$nim);
	   $tbl = new mytable($tbstat,$header,$dataisi,"");
	   $html_txt .= $tbl->display().$vform->endForm();
         
	   $html_txt = $vhtml->addfieldset("Kartu Rencana Studi (KRS)",$html_txt,array());
	   return $html_txt;
	 
	 } 
	 
	 
	 function lst_mhs()
	 {
	    	 $vmythnsem = new mythnsem;
			 $vhtml = new html_element;
		     $vdata_mhs = new dt_mhs;
		     $data = $vdata_mhs->getData("");
			 
			 $vbaca_trans = new dt_trans;
			 $vbaca_krs = new dt_krs; 
			 $vbaca_stat = new dt_stat_mhs;
			 
			 
			 $TA = $vmythnsem->getthnsem();
			 
			 if(!empty($data)){
			     $tmp="";
				 $ctk=0;
				 $dataisi=array();
		         $datanoisi=array();
		         $dataisi1=array();
		         $datanoisi1=array();				 
				 
				 foreach($data as $row){
				    if(empty($tmp)){
					    $tmp=$row['tahunmsmhs'];
                        $ctk=1;					   
					 }else{
					    if($tmp!=$row['tahunmsmhs']){
						  $tmp=$row['tahunmsmhs'];
                          $ctk=1;
						}
					 }
					if($ctk==1){ 
		 		       $ctk=0;
					}
					
					    
					
					    $tmpdt=array();		 			
                   
                   		 $tmpdt[]=array($row["tahunmsmhs"],array());
		                 $tmpdt[]=array($row["nimhsmsmhs"],array());
	                     $tmpdt[]=array($row["nmmhsmsmhs"],array());
						
						 $tmp=$row['shiftmsmhs'];
		                 $tmpdt[]=array($this->shift_[$tmp],array());						
						
						$tmp_stat = $vbaca_stat->getstatmhs($TA,$row['nimhsmsmhs']);
                        $tmpdt[]=array($tmp_stat, array());
                        
                        $data1 = $vbaca_trans->hitipk_krs($row['nimhsmsmhs']);
						
						$ipk=0;
					 	if($vbaca_trans->sks_mbl_krs>0){ 
	  						$ipk = round($vbaca_trans->sks_nm_krs/$vbaca_trans->sks_mbl_krs,2);
						}	 
          
		               if($ipk>2.99){
                           $sks_blh=24;
                       } else{
			                   if(($ipk>=2.50) and($ipk<=2.99)){
				                  $sks_blh=21;
			                 } else{
				                     if(($ipk>=2.00) and ($ipk<=2.49)){
					                     $sks_blh=18;
				                   } else{
					                    	  if(($ipk>=1.50) and ($ipk<=1.99)){
						                      $sks_blh=16;
					                      } else{  
										          if(($ipk>0.00) and ($ipk<=1.49)){
						                              $sks_blh=14;
					                              } else{  
										              $sks_blh=20;
					                                }
					                            }

				                         }

			                       }
                             }  								   
						
						//$sks_blh=24;
						
						 $tmpdt[]=array(number_format($ipk, 2, '.', ''),array('align'=>'right'));
		                 $tmpdt[]=array($sks_blh,array('align'=>'right'));
						
						$jml_sks=$vbaca_krs->hitsks($row['nimhsmsmhs']);
						
						$tmpdt[]=array($jml_sks, array('align'=>'right'));
						
						
						$link="frm_edit_krs.php?nim=".$row['nimhsmsmhs'];
						//$link="../global_code/frm_lht_krs.php?thsmskrs=". $row['thsmskrs']."&nim=".$row['nimhsmsmhs'];
						//$link1="../global_code/frm_edit_krs.php?nim=".$row['nimhsmsmhs']."&nama=".$row['nmmhsmsmhs'];					
				        //$tbl->addCell("<a href='$link'>Lihat KRS</a>", null, 'data');
					   $tmpdt[]=array("<a href='$link'>Edit KRS</a>",array('align'=>'center'));
		  			   
                       switch($tmp_stat)
						  {
							case "Aktif" : $jml_sks>0 ? $dataisi[]=$tmpdt : $datanoisi[]=$tmpdt ;break;
							default: $jml_sks>0 ? $dataisi1[]=$tmpdt :  $datanoisi1[]=$tmpdt;break;
						  } 					   
				 }		 
			 
			 }
		
	 $header = array(array("Angkatan","NIM","Nama","Kelas","Status","IPK","Batas SKS","Ambil SKS","Aksi")); 
	 
	 $accheader=array("Mahasiswa Aktif","Mahasiswa Dengan Status Lain");  
	 $acccontent = array();

		     $tbstat = array("id" => "tb_krs",'width'=>'100%');
			 $tbl = new mytable($tbstat,$header,$dataisi,"");
		     $html_txt=$vhtml->addfieldset("Mengisi KRS",$tbl->display(),array());
	      
		     $tbstat = array("id" => "tb_krs1",'width'=>'100%');
			 $tbl = new mytable($tbstat,$header,$datanoisi,"");
		     $html_txt.=$vhtml->addfieldset("Tidak Mengisi KRS",$tbl->display(),array());
	 
	         $acccontent[] = $html_txt;
	 	      
		     $tbstat = array("id" => "tb_krs2",'width'=>'100%');
			 $tbl = new mytable($tbstat,$header,$dataisi1,"");
		     $html_txt=$vhtml->addfieldset("Mengisi KRS",$tbl->display(),array());
		 
		     $tbstat = array("id" => "tb_krs3",'width'=>'100%');
			 $tbl = new mytable($tbstat,$header,$datanoisi1,"");
		     $html_txt.=$vhtml->addfieldset("Tidak Mengisi KRS",$tbl->display(),array()); 
          
		     $acccontent[] = $html_txt;		
		  
	      $myaccordion = new myaccordion('accordion',$accheader,$acccontent);
	      $html_txt=$vhtml->addfieldset("Kartu Rencana Studi ".$vmythnsem->gettxtthnsem(),$myaccordion->display(),array());		  
		  return $html_txt;
	 }
	 
	 function ctk_krs_topdf($vnim){
	   
	   
	   $dt_krs = new dt_krs();
       $TA = $dt_krs->TA();	
	   
	   
	   $tbl4 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_jdl",'cellpadding'=>'2'));
	   
	   $tbl4->addRow();		  
		  $tbl4->addCell('<img src="../img/logo_fak.jpg" alt="logo" width="55" height="55">','data');
          $tbl4->addCell('<font face="Times New Roman" size="10pt">'.
	                     '<b>PROGRAM STUDI MATEMATIKA<br>'.
				             'FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM<br>'.
					         'UNIVERSITAS BALE BANDUNG'.
				         '</b>'.
			             '</font>',null,'data');
	   
	   $jdl = $tbl4->display().			  
			  '<br><br>'.
	          '<center>'.
			            '<font face="Times New Roman" size="10pt">'.
						       '<b>KARTU RENCANA STUDI (KRS)</b>'.
					    '</font>'.
			  '</center><br><br>';
	
       $dt_mhs = new dt_mhs;
	   $data = $dt_mhs->getData($vnim);
	
	  $txt_sem = array(1=>'Ganjil',2=>'Genap');
	  foreach($data as $row)
      {  
	   $tbl2 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_mhs","width"=>"100%"));       
	   $tbl2->addRow();		  
		  $tbl2->addCell('NIM','data');
          $tbl2->addCell(':',null,'data');
		  $tbl2->addCell($vnim,null,'data');
		  $tbl2->addCell('Sem. Awal','data');
          $tbl2->addCell(':',null,'data');
		  $thn = str_split($row['smawlmsmhs'], 4);
		  $tbl2->addCell($txt_sem[$thn[1]]." ".$thn[0],null,'data');
	   $tbl2->addRow();		  
		  $tbl2->addCell('Nama','data');
          $tbl2->addCell(':',null,'data');
		  $tbl2->addCell($row['nmmhsmsmhs'],null,'data');
		  $tbl2->addCell('Tahun Ajaran','data');
          $tbl2->addCell(':',null,'data');
		  $thn = str_split($TA, 4);
		  $tbl2->addCell( $thn[0].'/'.($thn[0]+1),null,'data');	  
	   $tbl2->addRow();		  
		  $tbl2->addCell('Dosen Wali','data');
          $tbl2->addCell(':',null,'data');
		  $tbl2->addCell('',null,'data');
		  $tbl2->addCell('Semester','data');
          $tbl2->addCell(':',null,'data');
		  $tbl2->addCell( $txt_sem[$thn[1]]." ".$thn[0],null,'data');
	  }
	  
	 
	  
       $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_mtk","width"=>"100%",'border'=>'1','cellpadding'=>'2'));
	   
	   $tbl->addRow(); 
	   $tbl->addCell('NO',null,'header',array('width'=>'5%'));
	   $tbl->addCell('KODE',null,'header',array('width'=>'15%'));	  
	   $tbl->addCell('NAMA',null,'header',array('width'=>'70%'));	 
	   $tbl->addCell('SKS',null,'header',array('width'=>'10%'));
	   
	  $data = $dt_krs->getMtk($TA,$vnim,0);
	  
	  $jml_mtk = 1;
	  $jml_sks = 0.00;
	  if(!empty($data)){
	     
	     foreach($data as $row){
		  $tbl->addRow();
		  
		  $tbl->addCell($jml_mtk,null,'data',array('align'=>'right'));
          $tbl->addCell($row['kdkmkkrs'],null,'data',array('align'=>'center'));
		  $tbl->addCell($row['nakmktbkmk'],null,'data',array('align'=>'left'));
		  $tbl->addCell($row['sksmktbkmk'],null,'data',array('align'=>'center'));
		   
		  $jml_sks+=$row['sksmktbkmk'];  
		  $jml_mtk++;			
		 }  
	  }	
	      $tbl->addRow();		  
		  $tbl->addCell('',null,'data',array('align'=>'right','height'=>'18px'));
          $tbl->addCell('',null,'data',array('align'=>'center','height'=>'18px'));
		  $tbl->addCell('',null,'data',array('align'=>'left','height'=>'18px'));
		  $tbl->addCell('',null,'data',array('align'=>'center','height'=>'18px'));
		  
		  $tbl->addRow();
		  $tbl->addCell('Jumlah',null,'data',array('colspan'=>'3','align'=>'center'));
		  $tbl->addCell($jml_sks,null,'data',array('align'=>'center'));
		  
	   $tbl1 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_prak",'border'=>'1','width'=>'90%','cellpadding'=>'2'));
	   
	   $tbl1->addRow(); 
	   $tbl1->addCell('NO',null,'header',array('width'=>'5%'));
	   $tbl1->addCell('KODE',null,'header',array('width'=>'15%'));	  
	   $tbl1->addCell('NAMA',null,'header',array('width'=>'70%'));	 
	   

	  $data = $dt_krs->getMtk($TA,$vnim,1);
      
	  $jml_mtk = 1;
	  
	  if(!empty($data)){
	     
	     foreach($data as $row){
		   $kd = str_split($row['kdkmkkrs'],4); 
		    if($kd[0]=='MATP'){  
		       $tbl1->addRow();
		       $tbl1->addCell($jml_mtk,null,'data',array('align'=>'right'));
               $tbl1->addCell($row['kdkmkkrs'],null,'data',array('align'=>'center'));
		       $tbl1->addCell($row['nakmktbkmk'],null,'data',array('align'=>'left'));
		      $jml_mtk++;
            }  		  
		 }  
	  }		   
	   
	    $tbl1->addRow();
		$tbl1->addCell('',null,'data',array('align'=>'right','height'=>'18px'));
        $tbl1->addCell('',null,'data',array('align'=>'center','height'=>'18px'));
		$tbl1->addCell('',null,'data',array('align'=>'left','height'=>'18px'));
	   
	   $tbl3 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_ttd",'border'=>'1','width'=>'60%','cellpadding'=>'2'));
	   
	   $tbl3->addRow(); 
	   $tbl3->addCell('MAHASISWA',null,'header',array('width'=>'50%'));
	   $tbl3->addCell('DOSEN WALI',null,'header',array('width'=>'50%'));	  
	   $tbl3->addRow(); 
	   $tbl3->addCell(' ',null,'data',array('height'=>'50px'));
	   $tbl3->addCell(' ',null,'data',array('height'=>'50px'));
	   
	   
	   $html =
            '<html>'.
			'<style type="text/css">'.
			'table{font-family: Calibri; font-size: 9pt;}'.
			'</style>'.
			'<body>'.
			 $jdl.$tbl2->display().             
			'<br>Matakuliah : <br>'.$tbl->display().
			'<br>Praktikum : <br>'.$tbl1->display().
			'<br><br>'.$tbl3->display().
			'<br><br>'.'<font face="Calibri" size="9pt">Dicetak dari Sistem Informasi Akademik FMIPA UNIBBA pada tanggal '.date("d-m-Y H:i:s").'</font>'.
            '</body>'.
			'</html>';          
		  
		  $tmp = "../Admin/cetak/kartu/KRS - ".$vnim." - ".$TA.".pdf";
          
		  $dompdf = new DOMPDF();
          $dompdf->load_html($html);
          $dompdf->set_paper('a4', 'portrait');
		  $dompdf->render();
          $output = $dompdf->output();
          file_put_contents($tmp, $output);   
	   
	   return $tmp;
	 }
	 
	 
	 function ctk_krs_toexcel($vnim){
	  	  
	  $vmythnsem = new mythnsem;
	  $dt_krs = new dt_krs();
      $TA = $vmythnsem->getthnsem();	  
	 
      $dt_mhs = new dt_mhs;
	  $datamhs = $dt_mhs->getData($vnim); 
	  
	  $datamtk = $dt_krs->getMtk($TA,$vnim,0);	
      $dataprtk = $dt_krs->getMtk($TA,$vnim,1);
	  
	  $tmp = "../Admin/cetak/kartu/KRS - ".$vnim." - ".$TA.".xls";
	  $vwctkkrs = new vw_ctkkrs;
	  $vwctkkrs->ctk_KRS($datamhs,$datamtk,$dataprtk);
	  $vwctkkrs->save($tmp);	  	  
	  
	  return $tmp;
	 
	 }
	 
	 
	 function ctk_kartu($vnim,$idx=1){
	  $objPHPExcel = new PHPExcel();
	  $objPHPExcel->setActiveSheetIndex(0);
	  
	
      $objPHPExcel->getActiveSheet()->getColumnDimension('A')->setWidth(3.57);
	  $objPHPExcel->getActiveSheet()->getColumnDimension('B')->setWidth(11.14);
	  $objPHPExcel->getActiveSheet()->getColumnDimension('C')->setWidth(0.83);
	  $objPHPExcel->getActiveSheet()->getColumnDimension('D')->setWidth(32.00);	
	  $objPHPExcel->getActiveSheet()->getColumnDimension('E')->setWidth(6.00);
	  $objPHPExcel->getActiveSheet()->getColumnDimension('F')->setWidth(8.43);
	  $objPHPExcel->getActiveSheet()->getColumnDimension('G')->setWidth(2.86);
	  $objPHPExcel->getActiveSheet()->getColumnDimension('H')->setWidth(7.00); 
	  $objPHPExcel->getActiveSheet()->getColumnDimension('I')->setWidth(0.83); 
	  $objPHPExcel->getActiveSheet()->getColumnDimension('J')->setWidth(16.00); 
     	  
	  $objPHPExcel->getActiveSheet()->getRowDimension(1)->setRowHeight(26.25);  
	  $objPHPExcel->getActiveSheet()->getRowDimension(5)->setRowHeight(20.25);
      		
      
	  $objPHPExcel->getActiveSheet()->mergeCells('D1:J1');
	  $objPHPExcel->getActiveSheet()->getStyle('D1:J1')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('D1:J1')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->setCellValue('D1', 'UNIVERSITAS BALE BANDUNG');	  
	  $objPHPExcel->getActiveSheet()->getStyle('D1')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Arial',
							'size'      => 20
						)
					)
			);
			
	  $objPHPExcel->getActiveSheet()->mergeCells('D2:J2');
	  $objPHPExcel->getActiveSheet()->getStyle('D2:J2')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('D2:J2')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->setCellValue('D2', 'Kampus : Jl. RAA. Wiranatakusumah Baleendah Telp./Fax 5940443 Bandung 40258');	  
	  $objPHPExcel->getActiveSheet()->getStyle('D2')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => false,
							'name'      => 'Arial',
							'size'      => 10
						)
					)
			);		
	  $objPHPExcel->getActiveSheet()->mergeCells('D4:J4');
	  $objPHPExcel->getActiveSheet()->getStyle('D4:J4')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('D4:J4')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 
	  
	  $objDrawing = new PHPExcel_Worksheet_Drawing(); 
	  $objDrawing->setPath('../img/logo_unibba.png');
	  $objDrawing->setWidth(60);
	  $objDrawing->setOffsetX(10);
      $objDrawing->setOffsetY(0);
	  $objDrawing->setWorksheet($objPHPExcel->getActiveSheet());
	  $objDrawing->setCoordinates('B1'); 
	  
	  if($idx==2){
	    $objPHPExcel->getActiveSheet()->setCellValue('D4', 'KARTU UJIAN AKHIR SEMESTER');	 
	  }else{
	    $objPHPExcel->getActiveSheet()->setCellValue('D4', 'KARTU UJIAN TENGAH SEMESTER');
	  }
	  $objPHPExcel->getActiveSheet()->getStyle('D4')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Arial',
							'size'      => 16
						)
					)
			);	
      
	  $objPHPExcel->getActiveSheet()->setCellValue('A6', 'NAMA MAHASISWA'); 
	  $objPHPExcel->getActiveSheet()->mergeCells('A6:B6'); 
	  $objPHPExcel->getActiveSheet()->setCellValue('A7', 'NIM');
	  $objPHPExcel->getActiveSheet()->mergeCells('A7:B7'); 
      $objPHPExcel->getActiveSheet()->setCellValue('A8', 'FAKULTAS');
      $objPHPExcel->getActiveSheet()->mergeCells('A8:B8'); 	  
      $objPHPExcel->getActiveSheet()->setCellValue('A9', 'PRODI'); 
       $objPHPExcel->getActiveSheet()->mergeCells('A9:B9'); 	  
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('C6', ':'); 
	  $objPHPExcel->getActiveSheet()->setCellValue('C7', ':');
      $objPHPExcel->getActiveSheet()->setCellValue('C8', ':');	
      $objPHPExcel->getActiveSheet()->setCellValue('C9', ':');  
	  
	    $vdt_mhs = new dt_mhs;
		$data = $vdt_mhs->getData($vnim);
		
		if(!empty($data))
		{
		  foreach($data as $row){
		     $nmmhs = $row['nmmhsmsmhs'];
			 $objPHPExcel->getActiveSheet()->setCellValue('D6', $row['nmmhsmsmhs']); 
	         $objPHPExcel->getActiveSheet()->setCellValue('D7', $row['nimhsmsmhs']);
		     }		  
		}
	  
	  
	  
      
	  $objPHPExcel->getActiveSheet()->setCellValue('D8', 'MATEMATIKA DAN ILMU PENGETAHUAN ALAM');	
      $objPHPExcel->getActiveSheet()->setCellValue('D9', 'MATEMATIKA'); 

	  $objPHPExcel->getActiveSheet()->setCellValue('G6', 'SEMESTER'); 
	  $objPHPExcel->getActiveSheet()->setCellValue('G7', 'JENJANG');
      $objPHPExcel->getActiveSheet()->setCellValue('G8', 'JUMLAH SKS');	
      $objPHPExcel->getActiveSheet()->setCellValue('G9', 'T.A.');  
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('I6', ':'); 
	  $objPHPExcel->getActiveSheet()->setCellValue('I7', ':');
      $objPHPExcel->getActiveSheet()->setCellValue('I8', ':');	
      $objPHPExcel->getActiveSheet()->setCellValue('I9', ':'); 
      
	      $vbaca_krs = new dt_krs;
		  $thnsms = $vbaca_krs->TA();
		 
		  $data = $vbaca_krs->getMtk($thnsms,$vnim,1);
	  
	  $sem=array(1=>'Ganjil',2=>'Genap');
	  
	  $tmp = str_split($thnsms, 4);
	  
	  $thn=$tmp[0];
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('J6', $sem[$tmp[1]]); 
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('J7', 'S1');
      
	  
	  
      $objPHPExcel->getActiveSheet()->setCellValue('J9',$thn.'/'.($thn+1) ); 
      
      $objPHPExcel->getActiveSheet()->getStyle('A6:J9')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Arial',
							'size'      => 9
						)
					)
			);
       
      $objPHPExcel->getActiveSheet()->setCellValue('A10', 'NO');
      $objPHPExcel->getActiveSheet()->setCellValue('B10', 'KODE MK'); 
	  $objPHPExcel->getActiveSheet()->mergeCells('B10:C10');
      $objPHPExcel->getActiveSheet()->setCellValue('D10', 'MATAKULIAH'); 
      $objPHPExcel->getActiveSheet()->setCellValue('E10', 'SKS'); 
      $objPHPExcel->getActiveSheet()->setCellValue('F10', 'Tgl.UJIAN'); 
	  $objPHPExcel->getActiveSheet()->mergeCells('F10:G10');
      $objPHPExcel->getActiveSheet()->setCellValue('H10', 'KLS'); 
      $objPHPExcel->getActiveSheet()->setCellValue('I10', 'Paraf'); 
      $objPHPExcel->getActiveSheet()->mergeCells('I10:J10');	  
      
	  $objPHPExcel->getActiveSheet()->getStyle('A10:J10')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('A10:J10')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 
      $objPHPExcel->getActiveSheet()->getStyle('A10:J10')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Arial',
							'size'      => 10
						),
						'borders' => array(
							'inside'     => array(
								'style' => PHPExcel_Style_Border::BORDER_THIN
							),
							'outline'     => array(
								'style' => PHPExcel_Style_Border::BORDER_MEDIUM
							)
						)
					)
			);	  
	  
	  if(!empty($data)){
	     $i=11;
		 $no=1;
		 $jmlsks=0;
		 foreach($data as $row){
	        if(!in_array($row['kdkmkkrs'],array('UBB106','MAT352','MAT353'))){
			    if($row['sksprtbkmk']>0){
                   $sks=number_format($row['sksmktbkmk']-1, 2, '.', '');
                   $jmlsks+=$row['sksmktbkmk']-1;
				}else{
				   $sks=$row['sksmktbkmk'];
                   $jmlsks+=$row['sksmktbkmk'];				   
				}
			
				$objPHPExcel->getActiveSheet()->setCellValue('A'.$i, $no);
				$objPHPExcel->getActiveSheet()->setCellValue('B'.$i, $row['kdkmkkrs']);
				$objPHPExcel->getActiveSheet()->mergeCells('B'.$i.':C'.$i);
				$objPHPExcel->getActiveSheet()->setCellValue('D'.$i, $row['nakmktbkmk']);
				$objPHPExcel->getActiveSheet()->setCellValue('E'.$i, $sks);
				$objPHPExcel->getActiveSheet()->mergeCells('F'.$i.':G'.$i);
				$objPHPExcel->getActiveSheet()->mergeCells('I'.$i.':J'.$i);
				$no++;
				$i++;
			}	
	     }
	  }
	  $objPHPExcel->getActiveSheet()->mergeCells('B'.$i.':C'.$i);
	  $objPHPExcel->getActiveSheet()->mergeCells('F'.$i.':G'.$i);
	  $objPHPExcel->getActiveSheet()->mergeCells('I'.$i.':J'.$i);
	  
	  $objPHPExcel->getActiveSheet()->getStyle('A11:J'.($i))->applyFromArray(
					array(						
						'borders' => array(
							'inside'     => array(
								'style' => PHPExcel_Style_Border::BORDER_THIN
							),
							'outline'     => array(
								'style' => PHPExcel_Style_Border::BORDER_MEDIUM
							)
						)
					)
			);
	  $i++;
	  $objPHPExcel->getActiveSheet()->getRowDimension($i)->setRowHeight(3.75);	  
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('J8', $jmlsks);	
	  $objPHPExcel->getActiveSheet()->getStyle('J8')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_LEFT);
	  
	  $i++;
	  $tmp='="Baleendah,  " & TEXT(NOW(),"dd mmm YYYY")';
	  $objPHPExcel->getActiveSheet()->setCellValue('G'.$i, $tmp);
	  
	  $i++;
	  $objPHPExcel->getActiveSheet()->setCellValue('B'.$i, 'Ketua Panitia Ujian,');
	  $objPHPExcel->getActiveSheet()->setCellValue('G'.$i, 'Peserta Ujian,');
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('G'.($i+4), $nmmhs);
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('B'.($i+4), '                              ');
	  
	  
	  $objPHPExcel->getActiveSheet()->getStyle('A11:J'.($i))->applyFromArray(
					array(						
						'font'    => array(
							'bold'      => false,
							'name'      => 'Arial',
							'size'      => 10
						)
					)
			);
			
		$objPHPExcel->getActiveSheet()->getStyle('A'.($i+4).':J'.($i+4))->applyFromArray(
					array(						
						'font'    => array(
							'bold'      => true,
							'name'      => 'Arial',
							'size'      => 10,
							'underline' => true
						)
					)
			);	
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('A'.($i+6), 'Dicetak dari Sistem Informasi Akademik FMIPA UNIBBA pada tanggal : '.date("d-m-Y H:i:s"));
	  
	  $objPHPExcel->getActiveSheet()->getStyle('A'.($i+6))->applyFromArray(
					array(						
						'font'    => array(
							'bold'      => false,
							'name'      => 'Calibri',
							'size'      => 8
						)
					)
			);
	  
	  switch($idx){
	    case 1 : $tmp="../Admin/cetak/kartu/Kartu UTS - ".$vnim.".xls";break;
		case 2 : $tmp="../Admin/cetak/kartu/Kartu UAS - ".$vnim.".xls";break;
	  }
	  $objWriter = PHPExcel_IOFactory::createWriter($objPHPExcel, 'Excel5');
      $objWriter->save($tmp);
	  return $tmp;
	 }
	 
	 
	 function viewdatamhs($nimshow=0)
	{   
	       
    	
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_mhs","Width"=>"100%"));
		$tbl->addRow();
        $tbl->addCell('Angkatan', null, 'header');
		if($nimshow==0){ 
		 $tbl->addCell('NIM', null, 'header');
		} 
		$tbl->addCell('Nama', null, 'header');
		
	    $vdb = new dt_krs;	
		$data = $vdb->getDataMhs("");
		
		if(!empty($data))
		{
		
		  foreach($data as $row)
		  {
		      $tbl->addRow();
			  $tbl->addCell($row['tahunmsmhs'], null, 'data');
			  if($nimshow==0){
			   $tbl->addCell($row['nimhsmsmhs'], null, 'data');
		      }
			  $tbl->addCell($row['nmmhsmsmhs'], null, 'data');
			  
			  
			  
		  }
		
		}
		
		return $tbl->display();
	}
	function viewdatamtk()
	{   
	       
    	
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_mtk","Width"=>"100%"));
		$tbl->addRow();
        $tbl->addCell('Semester', null, 'header');
		$tbl->addCell('Kode', null, 'header');
		$tbl->addCell('Nama', null, 'header');
		
	    $vdb = new dt_krs;	
		$data = $vdb->getDataMtk("");
		
		if(!empty($data))
		{
		
		  foreach($data as $row)
		  {
		      $tbl->addRow();
			  $tbl->addCell($row['semestbkmk'], null, 'data');
			  $tbl->addCell($row['kdkmkkrs'], null, 'data');
		      $tbl->addCell($row['nakmktbkmk'], null, 'data');
			  
			  
			  
		  }
		
		}
		
		return $tbl->display();
	}
	 
    }
?>