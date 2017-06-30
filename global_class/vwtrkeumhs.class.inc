<?php
   require_once 'shared.php';
class vwtrkeumhs
{
  function __construct()
	{
	  
	}
	
	function filter_mhs($vthn,$vkls,$vnim1)
	{
	  
	  $user = $_SESSION['user'];
	     
		            
		 $dtuser = new dt_user;
         $hak = $dtuser->gethak($user);
	  
	  $html_txt="<fieldset>";
	  $html_txt.="<legend>Filter</legend>";
	  
	  $vmhs = new dt_mhs;
	  $data = $vmhs->getAngkatan();
	  $thn = $vthn;
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
	   $kls=$vkls;
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
	  $vnim = $vnim1;
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
	  $tbl->addCell('Angkatan '.$frm->addSelectList("Angkatan",$ang,true,$vthn,null,array('id'=>'Angkatan')).' Kelas '.$frm->addSelectList("kls",$kelas,true,$vkls,null,array('id'=>'kls')).' Mahasiswa '.$frm->addSelectList("Mhs",$Mhs,true,$vnim1,null,array('id'=>'Mhs')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')), null, 'data');
	   
	  $html_txt.=$tbl->display()."</fieldset>";

      $html_txt.="<fieldset>";
	  $html_txt.="<legend  id='hsl_filter'> Daftar Transaksi Keuangan : ".$vtemp."</legend>";
      
	  $html_txt.="<fieldset>";
	  $html_txt.="<legend>Aksi</legend>";
	  $frm = new HTML_Form();
	  $tbl1 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmAksi"));
	  $tbl1->addRow();
	  
	  $addattr = array();
	  $addattr['id']='Add';
	  $editattr = array();
	  $editattr['id']='Edit';
	  $delattr= array();
	  $delattr['id']='Del';
	  $transattr= array();
	  $transattr['id']='Trans';
	  
	  if($hak==0)
	  {
		 $addattr['disabled']='disabled'; 
         $editattr['disabled']='disabled'; 
         $delattr['disabled']='disabled'; 
         $transattr['disabled']='disabled';		 
	  }	  
	  
	  $tbl1->addCell($frm->addInput('submit',"Add","Add",$addattr).
	  	             $frm->addInput('submit',"Edit","Edit",$editattr).
	  	             $frm->addInput('submit',"Delete","Delete",$delattr).
	  	             $frm->addInput('submit',"Trans","Perbaiki Transaksi",$transattr).
	  	             $frm->addInput('submit',"Cetak","Cetak",array('id'=>'Cetak')), null, 'data');
	  
	  
	  
	  $html_txt.=$tbl1->display()."</fieldset>";
	  
	  $html_txt.="<div id='data'>";
	  $html_txt.=$this->trankeumhs($vnim);
	  $html_txt.="</div>";
	  
	  $html_txt.="</fieldset>";
        	  
	  
	  return $html_txt;
	  
	}
	
	function trankeumhs($nim)
	{
	  
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_trans"));
	    $tbl->addRow();
        $tbl->addCell('Tanggal1', null, 'header');
        $tbl->addCell('ID Transaksi', null, 'header');
		$tbl->addCell('Tanggal', null, 'header');
		$tbl->addCell('Kode', null, 'header');
	    $tbl->addCell('Pembayaran', null, 'header');
        $tbl->addCell('Total', null, 'header');
		$tbl->addCell('Keterangan', null, 'header');
        
		
        $dt = new dt_trkeumhs;   		
	    $data = $dt->gettrkeumhs($nim);
	    
		$ttl=0;
		$tmp="";
	    if(!empty($data))		
		{
		  
		  foreach($data as $row)
		  {
		     $tbl->addRow();
             
			 $tmp=date("d/m/Y",strtotime($row['trkeumhstgl']));
			 $tbl->addCell($row['trkeumhstgl'], null, 'data'); 
			 $tbl->addCell($row['ID'], null, 'data');
			 $tbl->addCell($tmp, null, 'data');
		     $tbl->addCell($row['trkeumhsacclvl1'].'-'.$row['nmacclvl1'], null, 'data');
	         $tbl->addCell(number_format($row['trkeumhsbayar'], 2, ',', '.'), null, 'data',array('align'=>'right'));
             $ttl+=$row['trkeumhsbayar'];
			 $tbl->addCell(number_format($ttl, 2, ',', '.'), null, 'data',array('align'=>'right'));
		     $tbl->addCell($row['trkeumhsket'], null, 'data');
			 
		  }
		}
	  
	             $txt = '';
					$txt = $txt."<tr>";
						$txt = $txt."<th></th>";
						$txt = $txt."<th align='left'>".$row['ID']."</th>";	
						$txt = $txt."<th align='left'>$tmp</th>";						
						$txt = $txt."<th align='left'>".$row['trkeumhsacclvl1'].'-'.$row['nmacclvl1']."</th>";
						$txt = $txt."<th align='right'>".number_format($row['trkeumhsbayar'], 2, ',', '.')."</th>";											
						$txt = $txt."<th align='right'>".number_format($ttl, 2, ',', '.')."</th>";
						$txt = $txt."<th align='left'>".$row['trkeumhsket']."</th>";
						
											
					$txt = $txt."</tr>";
	  
	  $html_txt="<fieldset>".$tbl->display($txt)."</fieldset>";
	  
	   $tbl1 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "summary"));
	   $tbl1->addRow();
	   $tbl1->addCell("Total Bayar : ".number_format($ttl, 2, ',', '.'), null, 'data');
	   $tbl1->addCell("Tgl Tran. Terakhir : ".$tmp, null, 'data');
	   
	   //$html_txt.="<fieldset>".$tbl1->display()."</fieldset>";
	   
	  return $html_txt;
	}
	
	function frm_add($nim)
	{
	   $frm = new HTML_Form();
	  /*$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmAdd"));
	  
	  $tbl->addRow();
	  $tbl->addCell("NIM", null, 'data');
      $tbl->addCell(":", null, 'data');	 
      $tbl->addCell($frm->addInput('text',"nim",$nim,array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');	  
	  	  
	  $dt = new dt_trkeumhs;   		
	  $data = $dt->getnoacclvl1($nim);
	  
	  $noacc =array();
	  if(!empty($data))
	  {
	    foreach($data as $row)
		{
		  $noacc[$row['acclvl1keumhs']]=$row['acclvl1keumhs']." - ".$row['nmacclvl1'];		  
		}
	  
	  }
	  
	  $tbl->addRow();
	  $tbl->addCell("Tanggal Transaksi", null, 'data');
	  $tbl->addCell(":", null, 'data');
	  $tbl->addCell($frm->addInput('text',"datepicker",null,array('id'=>'datepicker')), null, 'data');   
	  
	  
	  $tbl->addRow();
	  $tbl->addCell("Akun", null, 'data');
	  $tbl->addCell(":", null, 'data');
	  $tbl->addCell($frm->addSelectList("acc",$noacc,true,null,null,array('id'=>'acc')), null, 'data');  
	  
	  $tbl->addRow();
	  $tbl->addCell("Bayar", null, 'data');
      $tbl->addCell(":", null, 'data');	 
      $tbl->addCell($frm->addInput('text',"bayar",0.00), null, 'data');	  
	  
	  $tbl->addRow();
	  $tbl->addCell("Keterangan", null, 'data');
      $tbl->addCell(":", null, 'data');	 
      $tbl->addCell($frm->addInput('text',"ket",null), null, 'data');	
	  $frm->startForm(null,'post','entrytrkeumhs').$tbl->display().$frm->endForm() */
	  
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_trkeumhs"));
	    $tbl->addRow();
        $tbl->addCell('Kode', null, 'header');
	    $tbl->addCell('Nama Akun', null, 'header');
        $tbl->addCell('Kewajiban', null, 'header');
		$tbl->addCell('Pembayaran', null, 'header');
		$tbl->addCell('Tanggal', null, 'header');
		$tbl->addCell('Jumlah Pembayaran', null, 'header');
        $tbl->addCell('Keterangan', null, 'header');      
		
        $dt = new dt_tot_trkeumhs;   		
	    $data = $dt->gettottrkeumhs($nim);	  
		  
		if(!empty($data))		
		{		  
		  foreach($data as $row)
		  {
		     $tbl->addRow();		 
			 $tbl->addCell($row['acclvl1keumhs'], null, 'data'); 
			 $tbl->addCell($row['nmacclvl1'], null, 'data');
	         $tbl->addCell(number_format($row['wajibByr'], 2, ',', '.'), null, 'data',array('align'=>'right'));
             $tbl->addCell(number_format($row['jmlbyr'], 2, ',', '.'), null, 'data',array('align'=>'right'));
             $tbl->addCell($frm->addInput('text',"datepicker[$row[acclvl1keumhs]]",null,array('class'=>'datepicker')), null, 'data');	
             $tbl->addCell($frm->addInput('text',"bayar[$row[acclvl1keumhs]]",( ($row['wajibByr']>$row['jmlbyr']) ? ($row['wajibByr']-$row['jmlbyr']) : 0.00)), null, 'data');
             $tbl->addCell($frm->addInput('text',"ket[$row[acclvl1keumhs]]",''), null, 'data');			 
		  }
		}
	    
	  return $tbl->display();
	}
	
	function frm_edit($nim,$tgl,$kd)
	{
	  
	  $frm = new HTML_Form();
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmAdd"));
	  
	  $tbl->addRow();
	  $tbl->addCell("NIM", null, 'data');
      $tbl->addCell(":", null, 'data');	 
      $tbl->addCell($frm->addInput('text',"nim",$nim,array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');	  
	  	  
	  $dt = new dt_trkeumhs;   		
	  $data = $dt->getnoacclvl1($nim);
	  
	  $noacc =array();
	  if(!empty($data))
	  {
	    foreach($data as $row)
		{
		  $noacc[$row['acclvl1keumhs']]=$row['acclvl1keumhs']." - ".$row['nmacclvl1'];		  
		}
	  
	  }
	  $tgl=explode('/',$tgl);
	  
	  
	  
	  $tbl->addRow();
	  $tbl->addCell("Tanggal Transaksi", null, 'data');
	  $tbl->addCell(":", null, 'data');
	  $tbl->addCell($frm->addInput('text',"tgl",$tgl[2].'-'.$tgl[1].'-'.$tgl[0],array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');   
	  
	  
	  $tmp = explode('-',$kd);
	  
	  
	  $tbl->addRow();
	  $tbl->addCell("Akun", null, 'data');
	  $tbl->addCell(":", null, 'data');
	  $tbl->addCell($frm->addSelectList("acc",$noacc,true,intval($tmp[0]),null,array('id'=>'acc','readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');  
	  
	  
	  $byr = $dt->getbyr($nim,$tgl[2].'-'.$tgl[1].'-'.$tgl[0],$tmp[0]);
	  $ket = $dt->getket($nim,$tgl[2].'-'.$tgl[1].'-'.$tgl[0],$tmp[0]);
	  
	  $tbl->addRow();
	  $tbl->addCell("Bayar", null, 'data');
      $tbl->addCell(":", null, 'data');	 
      $tbl->addCell($frm->addInput('text',"bayar",$byr), null, 'data');	  
	  
	  $tbl->addRow();
	  $tbl->addCell("Keterangan", null, 'data');
      $tbl->addCell(":", null, 'data');	 
      $tbl->addCell($frm->addInput('text',"ket",$ket), null, 'data');
	  
	  return $frm->startForm(null,'post','entrytrkeumhs').$tbl->display().$frm->endForm();
	}
	
	function frm_del($nim)
	{
	    $frm = new HTML_Form();
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_trkeumhs"));
	    $tbl->addRow();
        $tbl->addCell('Tanggal1', null, 'header');
		$tbl->addCell('Tanggal', null, 'header');
		$tbl->addCell('Kode', null, 'header');
	    $tbl->addCell('Pembayaran', null, 'header');        
		$tbl->addCell('Keterangan', null, 'header');
        $tbl->addCell('Total', null, 'header');
		
        $dt = new dt_trkeumhs;   		
	    $data = $dt->gettrkeumhs($nim);
	    
		$ttl=0;
	    if(!empty($data))		
		{
		  
		  foreach($data as $row)
		  {
		     $tbl->addRow();
             
			 $tmp=date("d/m/Y",strtotime($row['trkeumhstgl']));
			 $tbl->addCell($row['trkeumhstgl'], null, 'data'); 
			 $tbl->addCell($tmp, null, 'data');
		     $tbl->addCell($row['trkeumhsacclvl1'].'-'.$row['nmacclvl1'], null, 'data');
	         $tbl->addCell(number_format($row['trkeumhsbayar'], 2, ',', '.'), null, 'data',array('align'=>'right'));
             $tbl->addCell($row['trkeumhsket'], null, 'data');
			 $tbl->addCell($frm->addInput('checkbox',"plh[]",$row['ID']), null, 'data',array('align'=>'center'));
		  }
		}
	  
	  $html_txt="<fieldset>".$frm->startForm(null,'post','entrytrkeumhs').$tbl->display().$frm->endForm()."</fieldset>";
	  
	  
	   
	  return $html_txt;
	  
	}

	
	function ctk_trkeumhs($nim)
	{
	   $objPHPExcel = new PHPExcel();
	   $objPHPExcel->setActiveSheetIndex(0);
	   
	   $vmhs = new dt_mhs;
	   $data = $vmhs->getData($nim);
	  
	   $nm="";
	   if(!empty($data))
	   {
	     foreach($data as $row)
		 {
		   $nm=$row['nmmhsmsmhs'];
           $thn=$row['tahunmsmhs'];
           $awl=$row['smawlmsmhs'];		   
		 }
	   }
	   
	   $tmp = str_split($awl,4);
	   
	   if($tmp[1]==1)
	   {
	     $awl = 'Semster Ganjil '.$tmp[0];
	   }else{
	     $awl = 'Semster Genap '.$tmp[0];
	   }
	   
	   $objPHPExcel->getActiveSheet()->getColumnDimension('A')->setWidth(10.71);
       $objPHPExcel->getActiveSheet()->getColumnDimension('B')->setWidth(0.83);
       $objPHPExcel->getActiveSheet()->getColumnDimension('C')->setWidth(16.86);
	   $objPHPExcel->getActiveSheet()->getColumnDimension('D')->setWidth(15.71);
       $objPHPExcel->getActiveSheet()->getColumnDimension('E')->setWidth(15.71);

       $objPHPExcel->getActiveSheet()->getColumnDimension('F')->setWidth(26.00);
       
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('A1', 'PROGRAM STUDI MATEMATIKA');
	  $objPHPExcel->getActiveSheet()->mergeCells('A1:F1');
	  $objPHPExcel->getActiveSheet()->setCellValue('A2', 'FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM');
	  $objPHPExcel->getActiveSheet()->mergeCells('A2:F2');
	  $objPHPExcel->getActiveSheet()->setCellValue('A3', 'UNIVERSITAS BALE BANDUNG');
	  $objPHPExcel->getActiveSheet()->mergeCells('A3:F3');
	  $objPHPExcel->getActiveSheet()->getStyle('A1:A3')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Times New Roman',
							'size'      => 10
						)
					)
			);
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('A6', 'DAFTAR TRANSAKSI KEUANGAN');
	  $objPHPExcel->getActiveSheet()->mergeCells('A6:F6');
	  $objPHPExcel->getActiveSheet()->getStyle('A6:F6')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('A6:F6')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER); 		
	  
	  $objPHPExcel->getActiveSheet()->getStyle('A6:F6')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Times New Roman',
							'size'      => 12
						)
					)
			);		
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('A8', 'NAMA');
	  $objPHPExcel->getActiveSheet()->setCellValue('A9', 'NIM');
	  $objPHPExcel->getActiveSheet()->setCellValue('A10', 'ANGKATAN');
	  $objPHPExcel->getActiveSheet()->setCellValue('A11', 'SEM. AWAL');
	  
	  
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('B8',  ': ');
	  $objPHPExcel->getActiveSheet()->setCellValue('B9', ': ');
	  $objPHPExcel->getActiveSheet()->setCellValue('B10', ': ');
	  $objPHPExcel->getActiveSheet()->setCellValue('B11', ': ');
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('C8',  $nm);
	  $objPHPExcel->getActiveSheet()->setCellValue('C9', $nim);
	  $objPHPExcel->getActiveSheet()->setCellValue('C10', $thn);
	  $objPHPExcel->getActiveSheet()->getStyle('C10')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_LEFT); 
	  $objPHPExcel->getActiveSheet()->setCellValue('C11', $awl);
	  
	  
	  $objPHPExcel->getActiveSheet()->getStyle('A8:D11')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Times New Roman',
							'size'      => 10
						)
					)
			);
	  
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('A13',  'TANGGAL');
	  $objPHPExcel->getActiveSheet()->setCellValue('B13', 'KODE');
	  $objPHPExcel->getActiveSheet()->mergeCells('B13:C13');
	  $objPHPExcel->getActiveSheet()->getStyle('B13:C13')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('B13:C13')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
	  
	  $objPHPExcel->getActiveSheet()->setCellValue('D13', 'PEMBAYARAN');
	  $objPHPExcel->getActiveSheet()->setCellValue('E13', 'TOTAL');
	  $objPHPExcel->getActiveSheet()->setCellValue('F13', 'KET');
	  $objPHPExcel->getActiveSheet()->getStyle('A13:F13')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER); 
	  $objPHPExcel->getActiveSheet()->getStyle('A13:F13')->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
	  
	  
	  $objPHPExcel->getActiveSheet()->getStyle('A13:F13')->applyFromArray(
					array(
						'font'    => array(
							'bold'      => true,
							'name'      => 'Times New Roman',
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

       $dt = new dt_trkeumhs;   		
	   $data = $dt->gettrkeumhs($nim);
	    
		$ttl=0;
		$tmp="";
	    if(!empty($data))		
		{
		  $i=14;
		  foreach($data as $row)
		  {
		     
			 $tmp=date("d/m/Y",strtotime($row['trkeumhstgl']));
			 $objPHPExcel->getActiveSheet()->setCellValue('A'.$i,  $tmp);
			 $objPHPExcel->getActiveSheet()->setCellValue('B'.$i,$row['trkeumhsacclvl1'].'-'.$row['nmacclvl1']);
	         $objPHPExcel->getActiveSheet()->mergeCells('B'.$i.':C'.$i);
			 
			 $objPHPExcel->getActiveSheet()->setCellValue('D'.$i,$row['trkeumhsbayar']);
			 $objPHPExcel->getActiveSheet()->getStyle('D'.$i)->getNumberFormat()->setFormatCode('#,##0');
			 $objPHPExcel->getActiveSheet()->getStyle('D'.$i)->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_RIGHT); 
	         $objPHPExcel->getActiveSheet()->getStyle('D'.$i)->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
	 		 
			 
             $ttl+=$row['trkeumhsbayar'];
			 $objPHPExcel->getActiveSheet()->setCellValue('E'.$i,$ttl);
			  $objPHPExcel->getActiveSheet()->getStyle('E'.$i)->getNumberFormat()->setFormatCode('#,##0');
			 $objPHPExcel->getActiveSheet()->getStyle('E'.$i)->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_RIGHT); 
	         $objPHPExcel->getActiveSheet()->getStyle('E'.$i)->getAlignment()->setVertical(PHPExcel_Style_Alignment::VERTICAL_CENTER);
	 
			 
			 
		     $objPHPExcel->getActiveSheet()->setCellValue('F'.$i,$row['trkeumhsket']);
			 $i++;
			 
		  }
		}  			
		
		$objPHPExcel->getActiveSheet()->getStyle('A14:'.'F'.($i-1))->applyFromArray(
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
	  
	   
	   
	     $tmp="../Admin/cetak/keuangan/Transaksi Keuangan ".$nim." ".$nm.".xls";
	     $objWriter = PHPExcel_IOFactory::createWriter($objPHPExcel, 'Excel5');
		 $objWriter->save($tmp);
       
	   
	   
	   return $tmp;
	}
	

}

?>