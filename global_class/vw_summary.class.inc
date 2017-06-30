 <?php
     
	 require_once 'shared.php';
	 
	class vw_summary 
	{  
	  
	   var $vkhs;
	   var $vmtk_ctrl;
	   var $vtrans;
	  
	  function __construct(){
	   	   	   
	  }
	  
	  
	  function filter_mhs()
	{
	  
	  //set_time_limit(90);
	  
	  $html_element = new html_element;
	  $vmhs = new dt_mhs;
	  $data = $vmhs->getAngkatan();
	  $thn = $data[0]['tahunmsmhs'];	  
	    
	   $ang = array_combine(array_column($data,'tahunmsmhs'), array_column($data,'tahunmsmhs'));
	  
	   $data = $vmhs->getkls($thn);
	   $kls=$data[0]['shiftmsmhs'];	   
	   
	   $stat_arr = array_column($data,'shiftmsmhs');
	   $txtstat_arr = array_map(function ($stat){ $tmp=($stat=='R') ? "Reguler" : "Non Reguler"; return $stat." - ".$tmp;},$stat_arr);
	   $kelas = array_combine($stat_arr, $txtstat_arr);	   
	  
	   $data = $vmhs->getmhs($thn,$kls);
	  
	   $vnim=$data[0]['nimhsmsmhs'];
	   $vtemp=$data[0]['nimhsmsmhs']."-".$data[0]['nmmhsmsmhs'];
	  
	   $nim_arr = array_column($data,'nimhsmsmhs');
	   $nm_arr = array_map(function ($arr){ return $arr['nimhsmsmhs']." - ".$arr['nmmhsmsmhs'];},$data);
	   $Mhs = array_combine($nim_arr, $nm_arr);	
	  	       
       $header= array('Summary Semua Mahasiswa','Summary Per Mahasiswa');
       
	   
	                $frm = new HTML_Form();
					$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmfilter"));
					$tbl->addRow();
					$tbl->addCell('Angkatan '.$frm->addSelectList("Angkatan",$ang,true,null,null,array('id'=>'Angkatan')).' Kelas '.$frm->addSelectList("kls",$kelas,true,null,null,array('id'=>'kls')).' Mahasiswa '.$frm->addSelectList("Mhs",$Mhs,true,null,null,array('id'=>'Mhs')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')), null, 'data');
											
					$html_txt=$html_element->addfieldset('Filter',$tbl->display());
					
					$isi_fieldset="<div id='data'>";
					$isi_fieldset.=$this->summarymhs($vnim);
					$isi_fieldset.="</div>";					  
					
					$html_txt.=$html_element->addfieldset('Hasil Filter : '.$vtemp,$isi_fieldset,array('id'=>'hsl_filter'));
	   
	   
	   $content= array($this->summaryall(),$html_txt); 	
	   
	   $mytabs = new mytabs('tabs1',$header,$content);		  
	
	  return $mytabs->display();
	  
	}
	  
	  	  
	  function summaryall()
	  {
	    
		/* $mythnsem = new mythnsem;
	    $TA = $mythnsem->getthnsem();
		
		$this->vtrans= new dt_trans;
		
		$dt_mhs = new dt_mhs;  
	    $dt_stat_mhs = new dt_stat_mhs; 
		
		$dt = new dt_rekap_trkeumhs;  
	    $data = $dt_mhs->getAllData("");
		
		
		
		if(!empty($data))
	    {   $dataaktif1=array();
		    $dataaktif2=array();
		    $datanonaktif=array();
			$datacuti=array();
			$datalulus=array();
			$datakeluar=array();			
			
			foreach($data as $row)
			{
	            $tmp=array();		  
		        $tmp[]=array($row["tahunmsmhs"],array());
		        $tmp[]=array($row["nimhsmsmhs"],array());
	            $tmp[]=array($row["nmmhsmsmhs"],array());		 			  
			    $tmp[]=array($row["shiftmsmhs"]=="R" ? "Reguler" : "Non Reguler", array());		      
			  	
                $arr_stat_mhs = $dt_stat_mhs->getRStatMhs($row["nimhsmsmhs"]);
				
			    //$tmp[]=array($tmp_stat[$row["nimhsmsmhs"]]['rstat'][$TA]['txtstat'], array());
			    
				$hsl = $this->vtrans->hitipk($row["nimhsmsmhs"]);
				$ipk = $this->vtrans->sks_mbl!=0 ? $this->vtrans->sks_nm/$this->vtrans->sks_mbl :0.00; 
				 
			    $tmp[]=array($this->vtrans->sks_mbl, null,array('align'=>'right'));
			    $tmp[]=array(number_format($ipk, 2, '.', '') ,array('align'=>'right'));
			  
			    $tmp[]=array($arr_stat_mhs[$row["nimhsmsmhs"]]['tbstd'],array('align'=>'right'));			  
			  
			    $dt_keu = $dt->getrekaptrkeumhs("nimhsmsmhs='".$row["nimhsmsmhs"]."'");
			  
				foreach($dt_keu as $rwkeu)
				{				   
				  $tmp[]=array(number_format($rwkeu['kewajiban']>$rwkeu['tran'] ? $kurang=$rwkeu['kewajiban']-$rwkeu['tran'] : $kurang=0.00 , 2, ',', '.'),array('align'=>'right'));
				}
			    
				switch($arr_stat_mhs[$row["nimhsmsmhs"]]['rstat'][$TA]['kdstat'])
				{
				  case 'A' : if($ipk>2.75)
				             {
				               $dataaktif1[]=$tmp;
							 }else{  
				               $dataaktif2[]=$tmp;
							 }
							 break;
				  case 'N' : $datanonaktif[]=$tmp;
				             break;
                  case 'L' : $datalulus[]=$tmp;
				             break;
                  case 'C' : $datacuti[]=$tmp;
				             break;
                  case 'K' : $datakeluar[]=$tmp;
				             break;				  
				}
				
				
			}
		} */	
				
		
		
		$header = array(array("Angkatan","NIM","Nama","Kelas","SKS","IPK","Batas Studi","Sisa Kewajiban"));
		
		$accheader=array("Mahasiswa Aktif","Mahasiswa Non Aktif","Mahasiswa Cuti","Mahasiswa Lulus","Mahasiswa Keluar");
		$acccontent=array();		
		
		$tbstat = array("id" => "sumaktif1",'width'=>'100%');
		$tbl1 = new mytable($tbstat,$header,null,"");//$dataaktif1
		$tbstat = array("id" => "sumaktif2",'width'=>'100%');
		$tbl2 = new mytable($tbstat,$header,null,"");//$dataaktif2
		
		$html_txt= '<fieldset>';
		$html_txt.= '<legend>IPK>2.75</legend>';
		$html_txt.= $tbl1->display();
		$html_txt.= '</fieldset>';
		$html_txt.= '<fieldset>';
		$html_txt.= '<legend>IPK<2.75</legend>';
		$html_txt.= $tbl2->display();
		$html_txt.= '</fieldset>';
		
		$acccontent[]=$html_txt;
			
		$tbstat = array("id" => "sumnonaktif",'width'=>'100%');
		$tbl = new mytable($tbstat,$header,null,"");//$datanonaktif
		$acccontent[]=$tbl->display();
				
		$tbstat = array("id" => "sumcuti",'width'=>'100%');
		$tbl = new mytable($tbstat,$header,null,"");//$datacuti
		$acccontent[]=$tbl->display();
				
		$tbstat = array("id" => "sumlulus",'width'=>'100%');
		$tbl = new mytable($tbstat,$header,null,"");//$datalulus
		$acccontent[]=$tbl->display();
		
				
		$tbstat = array("id" => "sumkeluar",'width'=>'100%');
		$tbl = new mytable($tbstat,$header,null,"");//$datakeluar
		$acccontent[]=$tbl->display();
		
		$myaccordion = new myaccordion('accordion',$accheader,$acccontent);
	    return $myaccordion->display();
	  }
	  
	  function ss_viewdata($param)
      {
		 
		 $array_nmtb = array('sumaktif1'=>1,'sumaktif2'=>1,'sumnonaktif'=>6,'sumcuti'=>2,'sumlulus'=>5,'sumkeluar'=>4);
		 
		 $mythnsem = new mythnsem;
	     $TA = $mythnsem->getthnsem();		 
		 $dt_stat_mhs = new dt_stat_mhs; 
		 
		 $totalrecords=0;
		 $totaldisplayrecords=0;		 
		 
		 $data = $dt_stat_mhs->getData('statstat_mhs='.$array_nmtb[$param['namatb']].' and thnsmsstat_mhs='.$TA);
		 $totalrecords = count($data);		 
		 $totaldisplayrecords=$totalrecords;
		 
		if($param['namatb']!='sumaktif1' and $param['namatb']!='sumaktif2' and $param['sSearch'] == ""){  
		 $dt_stat_mhs->setpageno(((intval($param['iDisplayStart']))/intval($param['iDisplayLength']))+1);
		 $dt_stat_mhs->setrows_per_page(intval($param['iDisplayLength']));
		 $data = $dt_stat_mhs->getData('statstat_mhs='.$array_nmtb[$param['namatb']].' and thnsmsstat_mhs='.$TA);		
		} 
		 		 
		 $output = array(
			"sEcho" => intval($param['sEcho']),
			"iTotalRecords" => $totalrecords,
			"iTotalDisplayRecords" => $totaldisplayrecords,
			"aaData" => array()
		);
		 
		 
		 if(!empty($data))	
         {
			
			$dt_mhs = new dt_mhs; 
		    $this->vtrans= new dt_trans;
		    $dt = new dt_rekap_trkeumhs; 
			
			$jml_data=0;
			$display_data=0;
			$jml_filter=0;
			
			$cari=$param['sSearch'];
			
			$is_included = function ($arr,$cari){
				$tmp = array_filter($arr,function($val) use ($cari) {
						  return preg_match("/".$cari."/i",$val);
					    });
				return !empty($tmp);		
			};
			
			$add_data = function($param,&$data_arr,$tmp_row,$jml_data,&$display_data,&$jml_filter,$cari,$is_masuk){
				
				$jml_filter+= ($is_masuk) ? 1 : 0;					
					
					if(($display_data<$param['iDisplayLength']) and ((($cari == "") ? $jml_data :$jml_filter-1 )>=$param['iDisplayStart'])){ 
						 
						 if(($cari == "") or $is_masuk){  
						   $data_arr[] = $tmp_row;
						   $display_data++;
						 }
					}				
				
				return 1;
			};
			
			$sumaktif1=function ($ipk){ return $ipk>2.75; };
			$sumaktif2=function ($ipk){ return $ipk<=2.75; };
			
			foreach($data as $row)
            {
				$tmp_row = array();
				
				$ipk =0;
				if( ($cari=='') or ($display_data<$param['iDisplayLength'])){
					$tmp_data = $dt_mhs->getData($row["nimstat_mhs"]);
					$tmp_row[]=$tmp_data[0]['tahunmsmhs'];
					$tmp_row[]=$tmp_data[0]['nimhsmsmhs'];
					$tmp_row[]=$tmp_data[0]['nmmhsmsmhs'];
					$tmp_row[]=$tmp_data[0]['shiftmsmhs']=="R" ? "Reguler" : "Non Reguler";
									
					$hsl = $this->vtrans->hitipk($row["nimstat_mhs"]);
					$ipk = $this->vtrans->sks_mbl!=0 ? $this->vtrans->sks_nm/$this->vtrans->sks_mbl :0.00; 
					 
					$tmp_row[]='<div align="right">'.$this->vtrans->sks_mbl.'</div>';
					$tmp_row[]='<div align="right">'.number_format($ipk, 2, '.', '').'</div>';
					
					$arr_stat_mhs = $dt_stat_mhs->getRStatMhs($row["nimstat_mhs"]);
					$tmp_row[]=$arr_stat_mhs[$row["nimstat_mhs"]]['tbstd'];
					
					$dt_keu = $dt->getrekaptrkeumhs("nimhsmsmhs='".$row["nimstat_mhs"]."'");
					$rwkeu=$dt_keu[0];								   
					$tmp_row[]='<div align="right">'.number_format($rwkeu['kewajiban']>$rwkeu['tran'] ? $kurang=$rwkeu['kewajiban']-$rwkeu['tran'] : $kurang=0.00).'</div>';
				}				    
					if($array_nmtb[$param['namatb']]==1){
						$tmp=${$param['namatb']}($ipk);
						if($tmp)
						{			    
							$jml_data+=$add_data($param,$output['aaData'],$tmp_row,$jml_data,$display_data,$jml_filter,$cari,$is_included($tmp_row,$cari));
							
						}						
			        }else{  
					   					 
						 if($cari == ""){								
							$output['aaData'][] = $tmp_row;
					     }else{							
							$jml_data+=$add_data($param,$output['aaData'],$tmp_row,$jml_data,$display_data,$jml_filter,$cari,$is_included($tmp_row,$cari));
						   
					    }					   
					   	
				    } 				
			}			 
		   
		   if($param['namatb']=='sumaktif1' or $param['namatb']=='sumaktif2'){
			$output['iTotalRecords']=$jml_data;
			$output['iTotalDisplayRecords']= ($param['sSearch'] == "") ? $jml_data : $jml_filter;
		   }else{
			   if($param['sSearch']!=''){
				   $output['iTotalDisplayRecords']=$jml_filter;
			   }
		   }
		 
		 }		
		
         return $output;		 
	  }	  
	  
	  
	  function riwayat_stat($nim)
	  {
	    		
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "rstat",'width'=>'100%'));
		
		$tbl->addRow();
	    $tbl->addCell("No", null, 'header');
		$tbl->addCell("Semester", null, 'header');
	    $tbl->addCell("Status", null, 'header');
		
		$dt_stat_mhs = new dt_stat_mhs;
		$data1 = $dt_stat_mhs->getRStatMhs($nim);
				
		if(!empty($data1))
		{
		  
		  $i=1;
		  foreach($data1[$nim]['rstat'] as $row)
		  {
		      		  
			  $tbl->addRow();
			  $tbl->addCell($i, null, 'data');		 
			  $tbl->addCell($row['txt'], null, 'data');		  
			  $tbl->addCell($row['txtstat'], null, 'data');
		      
			  $i=$i+1;
		  }
		
		}
		
		$tbl1 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "mstud",'width'=>'100%'));
		
		$tbl1->addRow();
	    $tbl1->addCell("Semester Awal", null, 'header');
	    $tbl1->addCell("Semester Akhir", null, 'header');
		$tbl1->addCell("Batas Studi", null, 'header');
		 $tbl1->addCell("Toleransi Semester Akhir", null, 'header');
		$tbl1->addCell("Toleransi Batas Studi", null, 'header');
				
		$tbl->addRow();
		$tbl1->addCell($data1[$nim]['sawal'], null, 'data');
		$tbl1->addCell($data1[$nim]['sakhir'], null, 'data');
	    $tbl1->addCell($data1[$nim]['bstd'], null, 'data');
		$tbl1->addCell($data1[$nim]['tsakhir'], null, 'data');
		$tbl1->addCell($data1[$nim]['tbstd'], null, 'data');
		
		return "<fieldset><legend>Lama Masa Studi</legend>".$tbl1->display()."</fieldset><fieldset><legend>Riwayat Status</legend>".$tbl->display()."</fieldset>";
	  }
	  
	  function pos_keu($nim)
	  {
	    
		$dt = new dt_rekap_trkeumhs;
	    $data = $dt->getrekaptrkeumhs("nimhsmsmhs='".$nim."'");
		
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "poskeu",'width'=>'100%'));
		
		$tbl->addRow();
	    $tbl->addCell("Kewajiban", null, 'header');
	    $tbl->addCell("Transaksi", null, 'header');
		$tbl->addCell("Kekurangan", null, 'header'); 
		$tbl->addCell("Kelebihan", null, 'header');
		
	    if(!empty($data))
	    {
	        foreach($data as $row)
	        {
		       $tbl->addCell(number_format($row['kewajiban'], 2, ',', '.') , null, 'data',array('align'=>'right'));
               $tbl->addCell(number_format($row['tran'], 2, ',', '.'), null, 'data',array('align'=>'right'));
		       $tbl->addCell(number_format($row['kewajiban']>$row['tran'] ? $kurang=$row['kewajiban']-$row['tran'] : $kurang=0.00 , 2, ',', '.'), null, 'data',array('align'=>'right'));
		       $tbl->addCell(number_format($row['kewajiban']<$row['tran'] ? $lebih=$row['tran']-$row['kewajiban'] : $lebih=0.00 , 2, ',', '.'), null, 'data',array('align'=>'right'));
	    
   		    }
		}	 
		
		return $tbl->display();
	  }
	  
	  
	  
	  function summarymhs($nim)
	  {
	   
	  //$html_txt="<div id='accordion'>";	
      $html_txt="<div id='tabs'>";	

       $html_txt.="<ul>";
       $html_txt.="<li><a href='#tabs-1'>SKS,IPS,IPK,Status,Keuangan</a></li>";
       $html_txt.="<li><a href='#tabs-2'>Nilai D</a></li>";
       $html_txt.="<li><a href='#tabs-3'>Nilai E</a></li>";
	   $html_txt.="<li><a href='#tabs-4'>Nilai T</a></li>";
       $html_txt.="<li><a href='#tabs-5'>Mata Kuliah Yg Belum Diambil</a></li>";
       $html_txt.="</ul>";


	  
	  
	  //$html_txt.="<h3><a href='#'>SKS,IPS,IPK</a></h3>";			  
	  $html_txt.="<div id='tabs-1'>";
	  $html_txt.="<fieldset>";
	  $html_txt.="<legend>Jumlah IPS dan SKS Persemester</legend>";						 					   							  
	  $html_txt.=$this->sks_sem($nim);
	  $html_txt.="</fieldset>";	  
	  $html_txt.="<fieldset>";
	  $html_txt.="<legend>Jumlah SKS</legend>";						 					   							  
	  $html_txt.=$this->jml_sks($nim);
	  $html_txt.="</fieldset>";		 
	  $html_txt.="<fieldset>";
	  $html_txt.="<legend>IPK anda</legend>";						 					   							  
	  $html_txt.=$this->hit_ipk($nim);
	  $html_txt.="</fieldset>";	
	  $html_txt.="<fieldset>";
	  $html_txt.="<legend>Riwayat Status : </legend>";						 					   							  
	  $html_txt.=$this->riwayat_stat($nim);
	  $html_txt.="</fieldset>";
	  $html_txt.="<fieldset>";
	  $html_txt.="<legend>Posisi Keuangan : </legend>";						 					   							  
	  $html_txt.=$this->pos_keu($nim);
	  $html_txt.="</fieldset>";
	  
	  $html_txt.="</div>";
				
	  //$html_txt.="<h3><a href='#'>Nilai D</a></h3>";
	  $html_txt.="<div id='tabs-2'>";
	  //$html_txt.="<fieldset>";	  
	  $html_txt.="<div>".$this->mytb('D',$nim)."</div>";
	  //$html_txt.="</fieldset>";
	  $html_txt.="</div>";
	  
	  //$html_txt.="<h3><a href='#'>Nilai E</a></h3>";	  
	  $html_txt.="<div id='tabs-3'>";
	  //$html_txt.="<fieldset>";
	  $html_txt.="<div>".$this->mytb('E',$nim)."</div>";
	  //$html_txt.="</fieldset>";
	  $html_txt.="</div>";
	  
      //$html_txt.="<h3><a href='#'>Nilai T</a></h3>";
	  $html_txt.="<div id='tabs-4'>";
	  //$html_txt.="<fieldset>";
	  $html_txt.="<div>".$this->mytb("T",$nim)."</div>";
	  //$html_txt.="</fieldset>";
	  $html_txt.="</div>";
	  
		
      //$html_txt.="<h3><a href='#'>Mata Kuliah Yg Belum Diambil</a></h3>";
      $html_txt.="<div id='tabs-5'>";
	  $html_txt.="<fieldset>";
      $html_txt.="<div>".$this->blm_amb($nim)."</div>";
	  $html_txt.="</fieldset>";
	  $html_txt.="</div>";	
		
	  
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
	  
	  function mytb($nl,$nim)
	  {			
				 
				 $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "coba$nl",'width'=>'100%'));
	             $tbl->addRow();
	             $tbl->addCell("thn", null, 'header');
	             $tbl->addCell("Kode", null, 'header');
				 $tbl->addCell("Matakuliah", null, 'header'); 
				 $tbl->addCell("SKS", null, 'header');
	             $tbl->addCell("HM", null, 'header');
				 $tbl->addCell("NM", null, 'header');
				 
                 $tbl1 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "coba1$nl",'width'=>'100%'));
	             $tbl1->addRow();
	             $tbl1->addCell("thn", null, 'header');
	             $tbl1->addCell("Kode", null, 'header');
				 $tbl1->addCell("Matakuliah", null, 'header'); 
				 $tbl1->addCell("SKS", null, 'header');
	             $tbl1->addCell("HM", null, 'header');
				 $tbl1->addCell("NM", null, 'header');
				 
				$this->vkhs=new dt_khs;	
                $this->vkhs->buildsem($nim);
                      		
					for($i = 0; $i < count($this->vkhs->vthsms_txt); $i++){
					
				    	$data = $this->vkhs->buildkhs_nl($nim,$this->vkhs->vthsms[$i],$nl);
                         
                          if(!empty($data)){	
						
								foreach($data as $row){		
									 $tbl->addRow();
	                                 $tbl->addCell($row['thsmstrnlm'], null, 'data');
									 $tbl->addCell($row['kdkmktrnlm'], null, 'data');
									 $tbl->addCell($this->ismrhitl($row['wp'],$row['nakmktbkmk']), null, 'data');
									 $tbl->addCell($this->ismrhitl($row['wp'],$row['sksmktbkmk']), null, 'data');								
									 $tbl->addCell($row['nlakhtrnlm'], null, 'data');
									 $tbl->addCell($row['bobottrnlm'], null, 'data');							
								
								 }     
								}		
							}	
								$data1 = $this->vkhs->buildkhs_ulang($nim,$nl);
										if(!empty($data1)){
										   foreach($data1 as $row){		
											  	 
												 $tbl1->addRow();
												 $tbl1->addCell($row['thsmstrnlm'], null, 'data');
												 $tbl1->addCell($row['kdkmktrnlm'], null, 'data');
												 $tbl1->addCell($this->ismrhitl($row['wp'],$row['nakmktbkmk']), null, 'data');
												 $tbl1->addCell($this->ismrhitl($row['wp'],$row['sksmktbkmk']), null, 'data');								
												 $tbl1->addCell($row['nlakhtrnlm'], null, 'data');
												 $tbl1->addCell($row['bobottrnlm'], null, 'data');
                                                												 
										      
										   }
										
										}
					           
							
					
                 		 
	                return "<fieldset><legend>Matakuliah dengan nilai $nl : </legend>".$tbl->display()."</fieldset><br><fieldset><legend>Nilai Awal/Mengulang dari matakuliah diatas : </legend>".$tbl1->display()."</fieldset>";
	  }
	  
	  function blm_amb($nim)
	  {
	             $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "blm_amb",'width'=>'100%'));
	             $tbl->addRow();
	             $tbl->addCell("Semester", null, 'header');
	             $tbl->addCell("Kode", null, 'header');
				 $tbl->addCell("Matakuliah", null, 'header'); 
				 $tbl->addCell("SKS", null, 'header');
				               
                	  $this->vmtk_ctrl= new dt_mtk;
                      $where = "(kdkmktbkmk NOT IN (SELECT DISTINCT kdkmktrnlm FROM trnlm_trnlp WHERE nimhstrnlm='$nim' and nlakhtrnlm!='K')) AND (kdkmktbkmk NOT LIKE 'MATP%')";
					  $data=$this->vmtk_ctrl->getData($where);
					  
					 
					  
				   $semestbkmk1 ="";
               
				if(!empty($data)){   
				
				foreach($data as $row){		    
                	$tbl->addRow();
	                $tbl->addCell($row['semestbkmk'], null, 'data');
		            $tbl->addCell($row['kdkmktbkmk'], null, 'data');
					$tbl->addCell($this->ismrhitl($row['wp'],$row['nakmktbkmk']), null, 'data');
					$tbl->addCell($this->ismrhitl($row['wp'],$row['sksmktbkmk']), null, 'data');			 
				   }
			    }
                
				 return $tbl->display();				 
	  
	  }
	  
	  
	  
	  function sks_sem($nim)
	  {
	            
	            
				$this->vkhs=new dt_khs;
				$this->vkhs->buildsem($nim);
				$this->vtrans= new dt_trans;
		        
		 
				 $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_sks_sem",'width'=>'100%'));
	             $tbl->addRow();
	             $tbl->addCell("", null, 'header');
				 $tbl->addCell("SKS", null, 'header');
	             $tbl->addCell("IPS", null, 'header');
				 $tbl->addCell("IPK", null, 'header'); 
				  
				$sem[1]='Ganjil';
		        $sem[2]='Genap';
				
				$i=1;
			 if(!empty($this->vkhs->vthsms)){	
				$tmpsms="";
				foreach($this->vkhs->vthsms as $row){	
				 
				       $tbl->addRow();
					   if($row!='0000' ){
					     $thn = str_split($row, 4); 
					     $tbl->addCell("Sem. ke - $i (sem. ".$sem[$thn[1]].' '.$thn[0].")", null, 'data');
                       }else{
					     $tbl->addCell("Konversi", null, 'data');
					   }
					   
                   		if($tmpsms==""){			   
					     $tmpsms=$row;
					    }else{
						 $tmpsms=$tmpsms.','.$row; 
						}
					   
					   $data = $this->vtrans->hitipk($nim,$tmpsms);
					   
					   $tbl->addCell($this->vkhs->hitsks($nim,$row), null, 'data',array('align'=>'right'));
                       $tbl->addCell($this->vkhs->hitip($nim,$row), null, 'data',array('align'=>'right')); 					   
					   $tbl->addCell($this->vtrans->sks_mbl!=0 ? number_format($this->vtrans->sks_nm/$this->vtrans->sks_mbl, 2, '.', '') : '0.00', null, 'data',array('align'=>'right'));
					   
					   $i+=1;
				     	  				 	
                 					 
				}
			 }	
									 
              			
				 
				  
				
				
				
			    
				
				return $tbl->display();				 
	  
	  }	  
	  
	  function jml_sks($nim)
	  {
				$this->vkhs=new dt_khs;
				$this->vkhs->buildsem($nim);
				$this->vtrans= new dt_trans;				
		        $data = $this->vtrans->getData($nim);
				
                $this->vmtk_ctrl= new dt_mtk; 
				
				
				 $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "jml_sks",'width'=>'100%'));
	             $tbl->addRow();
	             $tbl->addCell("SKS Konversi", null, 'header');
	             $tbl->addCell("SKS yg Sudah Di ambil", null, 'header');
				 $tbl->addCell("SKS yg Belum Di ambil", null, 'header'); 
				 $tbl->addCell("Total SKS", null, 'header');
				 
	             $tbl->addRow();
	             $tbl->addCell($this->vkhs->hitsks($nim,'00000'), null, 'data');
	             $tbl->addCell($this->vtrans->sks_mbl, null, 'data');
				 $tbl->addCell($this->vmtk_ctrl->sksnmbl($nim), null, 'data'); 
				 $tbl->addCell($this->vmtk_ctrl->hittotsks(), null, 'data'); 
              
                return $tbl->display();				 
	  
	  }
	  function hit_ipk($nim)
	  {	 
		 $this->vtrans= new dt_trans;
		 $data = $this->vtrans->hitipk($nim);		
		 		        
				 $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "hit_ipk",'width'=>'100%'));
	             $tbl->addRow();
	             $tbl->addCell("SKS Kumulatif", null, 'header');
	             $tbl->addCell("NM Kumulatif", null, 'header');
				 $tbl->addCell("IPK", null, 'header'); 
				 
				 $tbl->addRow();
	             $tbl->addCell($this->vtrans->sks_mbl, null, 'data');
	             $tbl->addCell($this->vtrans->sks_nm, null, 'data');
				 $tbl->addCell($this->vtrans->sks_mbl!=0 ? number_format($this->vtrans->sks_nm/$this->vtrans->sks_mbl, 2, '.', '') : '0.00', null, 'data'); 
					 	
		 return $tbl->display();
	  }
	}  
   ?>