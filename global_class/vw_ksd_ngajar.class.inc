<?php
    
	require_once 'shared.php';
 
class vw_ksd_ngajar
{
	var $hari;
	
	function __construct()
	{
	  $this->hari=array(0=>'',1=>'Senin',2=>'Selasa',3=>'Rabu',4=>'Kamis',5=>'Jumat',6=>'Sabtu',7=>'Minggu');
	  
	}
	private function ismrhitl($iswp,$data)
	{
	   if($iswp=='p'){
	      return "<font color='red'><i>".$data."</i></font>";
	   }else{
	      return "$data";
	   }
	}
	
	function sem_filter()
	{
	  
	  
	  $dtkrs = new dt_krs;
	  $TA = $dtkrs->TA();
	  
	  $thn = str_split($TA, 4);
	  
	  $dtsem = array();
	  $txt_sem = array(1=>'Ganjil',2=>'Genap');
	  
	  if($thn[1]==1)
	  {
	    $bts=$thn[0]-1;
	  }else
	  {
        $bts=$thn[0];	  
	  }
	  
	  for($i=2008;$i<=$bts;$i++)
	  {
	    for($j=1;$j<=2;$j++)
	    {
	      $dtsem[$i.$j]='Semester '.$txt_sem[$j].' '.$i;
	    } 
	  }	  
	  
	  if($thn[1]==2)
	  {
	    $bts=$thn[0].'1';
	  }
	  
	 
	  
	  $frm = new HTML_Form();
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmfilter"));
	  $tbl->addRow();
      $tbl->addCell('Semester'.$frm->addSelectList("semester",$dtsem,true,null,null,array('id'=>'semester')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')), null, 'data');
	  
	  
	  $txt=$tbl->display();
	   
	  return $txt; 
	}
	
	function lst_mtk($kdds,$admin=0)
    {
        $html_txt  = "<fieldset>";
	    $html_txt .= "<legend>Aksi</legend>";
		$tbl = new HTML_Table(null, 'aksi', 0, 0, 0,array("id" => "aksi"));
	   
	    $tbl->addRow();
		
        if($admin==1)
		{
		 $user = $_SESSION['user'];
	     
		            
		 $dtuser = new dt_user;
         $hak = $dtuser->gethak($user);
		
		$tbl->addCell("<button type='submit' id='baru' ".($hak==0 ? 'disabled':'').">Ngajar Mtk. Baru</button>", null, 'data');
	    $tbl->addCell("<button type='submit'  id='lama' ".($hak==0 ? 'disabled':'').">Ngajar Mtk. Lama</button>", null, 'data');
		$tbl->addCell("<button type='submit' id='edit' ".($hak==0 ? 'disabled':'').">Edit Jadwal</button>", null, 'data');
		$tbl->addCell("<button type='submit' id='hapus' ".($hak==0 ? 'disabled':'').">Hapus Mtk.</button>", null, 'data');			
		$tbl->addCell("<button type='submit' id='acc' ".($hak==0 ? 'disabled':'').">Disetujui+Honor</button>", null, 'data');
		}else{
			$tbl->addCell("<button type='submit' id='baru'>Ngajar Mtk. Baru</button>", null, 'data');
	        $tbl->addCell("<button type='submit'  id='lama'>Ngajar Mtk. Lama</button>", null, 'data');
		    $tbl->addCell("<button type='submit' id='edit'>Edit Jadwal</button>", null, 'data');
		    $tbl->addCell("<button type='submit' id='hapus'>Hapus Mtk.</button>", null, 'data');
		}
		$html_txt .= $tbl->display();
		$html_txt .= "</fieldset>";
        $html_txt .= "<fieldset>";	   
	    $html_txt .= "<legend>Sedia Mengajar Matakuliah</legend>";
        
		$tbl = new HTML_Table(null, 'lst_mtk', 0, 0, 0,array("id" => "lst_mtk","width"=>"100%"));
		$tbl->addRow();
        $tbl->addCell('Sem', null, 'header');
	    $tbl->addCell('Kode', null, 'header');
        $tbl->addCell('Nama', null, 'header');
	    $tbl->addCell('SKS', null, 'header');
	    $tbl->addCell('Reg/Non Reg', null, 'header');
	    $tbl->addCell('Sem. Mhs.', null, 'header');
	    $tbl->addCell('Kls. Mhs.', null, 'header');
	    $tbl->addCell('Hari', null, 'header'); 
	    $tbl->addCell('Jam Mulai', null, 'header');
        $tbl->addCell('Jam Selesai', null, 'header');
	    $tbl->addCell('Asisten', null, 'header');
		$tbl->addCell('Tanggal Input', null, 'header');
		$tbl->addCell('Assesment', null, 'header');
		if($admin==1)
		{
		$tbl->addCell('Honor', null, 'header');
		}
		
		
		$dt_dosen= new dt_dosen;
		$ksd_ngajar = new dt_ksd_ngajar();
		$data = $ksd_ngajar->getDataMtk($kdds);
		if(!empty($data)){
		  foreach($data as $row)
		 {
		   $tbl->addRow();
		   $tbl->addCell($row['semestbkmk'], null, 'data');
		   $tbl->addCell($row['Kdkmk'], null, 'data');
		   $tbl->addCell($row['nakmktbkmk'], null, 'data');
		   $tbl->addCell($row['sksprtbkmk'] > 0 ? number_format($row['sksmktbkmk']-1, 2, '.', ' ') : $row['sksmktbkmk'] , null, 'data');
		   
		   if($row['shift']=='R'){
		     $tbl->addCell('Reguler', null, 'data');
		   }else
		   {
		     $tbl->addCell('Non Reguler', null, 'data');
		   }
		   $tbl->addCell($row['sem'], null, 'data');
		   $tbl->addCell($row['klsklh'], null, 'data');
		   $tbl->addCell($this->hari[$row['hariklh']], null, 'data');
		   $tbl->addCell($row['jawalklh'], null, 'data');
		   $tbl->addCell($row['jakhirklh'], null, 'data');
		   
		   $nm=$dt_dosen->getnmdsn1($row['kdass']);
		   $tbl->addCell($nm, null, 'data');
		   
		   $tbl->addCell(date_format(new DateTime($row['tgl_input']), 'd-m-Y'), null, 'data');
		   $tbl->addCell($row['disetujui'] == 1 ? 'Disetujui' : '', null, 'data');
		  
		  if($admin==1)
		  { 
		     if($row['hnr']=='R'){
		       $tbl->addCell('Reguler', null, 'data');
		     }else
		     {   $tbl->addCell('Non Reguler', null, 'data');				
		     }
		   }
		   
		 }
	    }
		$html_txt .= $tbl->display();
		$html_txt .= "</fieldset>";	   
	    //$html_txt .= "<fieldset>";	   
	    //$html_txt .= "<legend>Statistik</legend>";
		//$html_txt .= "</fieldset>";
	    return $html_txt;
    }

    function lst_riwayat_mtk($kdds,$admin=0,$thn)
    {
        $html_txt  = "<fieldset>";
	    $html_txt .= "<legend>Aksi</legend>";
		$tbl = new HTML_Table(null, 'aksi', 0, 0, 0,array("id" => "aksi"));
	   
	    $tbl->addRow();
		
        if($admin==1)
		{
			$user = $_SESSION['user'];
	        
		            
		    $dtuser = new dt_user;
            $hak = $dtuser->gethak($user);
		 
			$tbl->addCell("<button type='submit' id='baru' ".($hak==0 ? 'disabled':'').">Ngajar Mtk.</button>", null, 'data');
	        $tbl->addCell("<button type='submit' id='edit' ".($hak==0 ? 'disabled':'').">Edit Jadwal</button>", null, 'data');
		    $tbl->addCell("<button type='submit' id='hapus' ".($hak==0 ? 'disabled':'').">Hapus Mtk.</button>", null, 'data');
		    $tbl->addCell("<button type='submit' id='hnr' ".($hak==0 ? 'disabled':'').">Honor</button>", null, 'data');
		}else{
			$tbl->addCell("<button type='submit' id='baru'>Ngajar Mtk.</button>", null, 'data');
	        $tbl->addCell("<button type='submit' id='edit'>Edit Jadwal</button>", null, 'data');
		    $tbl->addCell("<button type='submit' id='hapus'>Hapus Mtk.</button>", null, 'data');
		}
		$html_txt .= $tbl->display();
		$html_txt .= "</fieldset>";
        $html_txt .= "<fieldset>";	   
	    $html_txt .= "<legend>Sedia Mengajar Matakuliah</legend>";
        
		$tbl = new HTML_Table(null, 'lst_mtk', 0, 0, 0,array("id" => "lst_mtk","width"=>"100%"));
		$tbl->addRow();
        $tbl->addCell('Sem', null, 'header');
	    $tbl->addCell('Kode', null, 'header');
        $tbl->addCell('Nama', null, 'header');
	    $tbl->addCell('SKS', null, 'header');
	    $tbl->addCell('Reg/Non Reg', null, 'header');
	    $tbl->addCell('Sem. Mhs.', null, 'header');
	    $tbl->addCell('Kls. Mhs.', null, 'header');
	    $tbl->addCell('Hari', null, 'header'); 
	    $tbl->addCell('Jam Mulai', null, 'header');
        $tbl->addCell('Jam Selesai', null, 'header');
	    $tbl->addCell('Asisten', null, 'header');
		$tbl->addCell('Tanggal Input', null, 'header');
		
		if($admin==1)
		{
		$tbl->addCell('Honor', null, 'header');
		}
		
		$dt_dosen= new dt_dosen;
		$ksd_ngajar = new dt_ksd_ngajar();
		$data = $ksd_ngajar->getDataRiwayatMtk($kdds,$thn);
		if(!empty($data)){
		  foreach($data as $row)
		 {
		   $tbl->addRow();
		   $tbl->addCell($row['semestbkmk'], null, 'data');
		   
		   $tbl->addCell($this->ismrhitl( isset($row['wp']) ? $row['wp']:"" ,$row['kdkmkpengajar']),null,'data');
		   $tbl->addCell($this->ismrhitl( isset($row['wp']) ? $row['wp']:"" ,$row['nakmktbkmk']),null,'data');
		   $tbl->addCell($this->ismrhitl( isset($row['wp']) ? $row['wp']:"" ,$row['sksprtbkmk'] > 0 ? number_format($row['sksmktbkmk']-1, 2, '.', ' ') : $row['sksmktbkmk']),null,'data',array('align'=>'center'));
		   
		   
		   
		   if($row['shiftpengajar']=='R'){
		     $tbl->addCell('Reguler', null, 'data');
		   }else
		   {
		     $tbl->addCell('Non Reguler', null, 'data');
		   }
		   $tbl->addCell($row['semespengajar'], null, 'data');
		   $tbl->addCell($row['kelaspengajar'], null, 'data');
		   $tbl->addCell($this->hari[$row['haripengajar']], null, 'data');
		   $tbl->addCell($row['jawalpengajar'], null, 'data');
		   $tbl->addCell($row['jakhirpengajar'], null, 'data');
		   
		   $nm=$dt_dosen->getnmdsn1($row['kdass']);
		   $tbl->addCell($nm, null, 'data');
		   
		   $tbl->addCell(date_format(new DateTime($row['tgl_input']), 'd-m-Y'), null, 'data');
		   
		  
		  if($admin==1)
		  { 
		     if($row['hnrpengajar']=='R'){
		       $tbl->addCell('Reguler', null, 'data');
		     }else
		     {   $tbl->addCell('Non Reguler', null, 'data');				
		     }
		   }
		   
		 }
	    }
		$html_txt .= $tbl->display();
		$html_txt .= "</fieldset>";	   
	    //$html_txt .= "<fieldset>";	   
	    //$html_txt .= "<legend>Statistik</legend>";
		//$html_txt .= "</fieldset>";
	    return $html_txt;
    }	
	
	function lst_dsn()
    {
	  $tbl = new HTML_Table(null, 'lst_dsn', 0, 0, 0,array("id" => "lst_dsn","width"=>"100%"));
	  
	    $html_txt = '';
	    $tbl->addRow();
        $tbl->addCell('Kode', null, 'header');
	    $tbl->addCell('Nama', null, 'header');
        $tbl->addCell('Beban SKS', null, 'header');
	    $tbl->addCell('SKS Disetujui', null, 'header');
	    $tbl->addCell('Aksi', null, 'header');
		
		$dt_dosen= new dt_dosen;
		$data = $dt_dosen->getAllData('');
		
		if(!empty($data))
		{
		   foreach($data as $row)
		   {
		     $tbl->addRow();
			 $tbl->addCell($row['Kode'], null, 'data');
	         $tbl->addCell($row['Nama'], null, 'data');
			 
			 $ksd_ngajar = new dt_ksd_ngajar();
    		 $tbl->addCell($ksd_ngajar->getBebanSKS($row['Kode'],0), null, 'data');
			 
			 $tbl->addCell($ksd_ngajar->getBebanSKS($row['Kode'],1), null, 'data');
			 
			 
			 $link="frm_edt_ksd_ngajar.php?kdds=".$row['Kode'];
			 $tbl->addCell("<a href='$link'>Edit</a>", null, 'data');
		   }
		}
		
	  $html_txt .= $tbl->display();  
	  return $html_txt;
	}
	
	function lst_riwayat_dsn($thn)
    {
	  $tbl = new HTML_Table(null, 'lst_dsn', 0, 0, 0,array("id" => "lst_dsn","width"=>"100%"));
	  
	    $html_txt = '';
	    $tbl->addRow();
        $tbl->addCell('Kode', null, 'header');
	    $tbl->addCell('Nama', null, 'header');
        $tbl->addCell('Beban SKS', null, 'header');
	    $tbl->addCell('Aksi', null, 'header');
		
		$tmp = str_split($thn, 4);
		
		 if($tmp[1]==1)
	  {
	    $bts=$tmp[0]-1;
	  }else
	  {
        $bts=$tmp[0];	  
	  }
		$txt_filter="00000,";
		for($i=2008;$i<=$bts;$i++)
	   {
	    for($j=1;$j<=2;$j++)
	    {
	      $txt_filter.="'".$i.$j."',";
	    } 
	   }
        
		if($tmp[1]==1)
	  {
	   $txt_filter.=$thn;
	  }else{
	   $txt_filter = rtrim($txt_filter, ',');
	  }
        		
		$dt_dosen= new dt_dosen;
		$data = $dt_dosen->getAllData("smawl in ($txt_filter)");
		
		if(!empty($data))
		{
		   foreach($data as $row)
		   {
		     $tbl->addRow();
			 $tbl->addCell($row['Kode'], null, 'data');
	         $tbl->addCell($row['Nama'], null, 'data');
			 
			 $ksd_ngajar = new dt_ksd_ngajar();
    		 $tbl->addCell($ksd_ngajar->getBebanRiwayatSKS($thn,$row['Kode'],0), null, 'data');
			 
			 
			 $link="frm_edt_riwayat_ksd_ngajar.php?kdds=".$row['Kode']."&thn=".$thn;
			 $tbl->addCell("<a href='$link'>Edit</a>", null, 'data');
		   }
		}
		
	  $html_txt .= $tbl->display();  
	  return $html_txt;
	}
	
	function build_ksd($kdds,$baru=1)
	{
	    $html_txt  = "<fieldset>";
		$html_txt .= "<legend>Sebaran Matakuliah</legend>";
	    $html_txt .= "<div>";
			
	  
	  $tbl = new HTML_Table(null, 'sebaran', 0, 0, 0,array("id" => "sebaran","width"=>"100%"));
	  
	  $frm = new HTML_Form();
	  
	  $ksd_ngajar = new dt_ksd_ngajar();
	  
	  $tbl->addRow();
      $tbl->addCell('Sem', null, 'header');
	  $tbl->addCell('Kode', null, 'header');
      $tbl->addCell('Nama', null, 'header');
	  $tbl->addCell('SKS', null, 'header');
	  $tbl->addCell('Reg/Non Reg', null, 'header');
	  $tbl->addCell('Sem. Mhs.', null, 'header');
	  $tbl->addCell('Kls. Mhs.', null, 'header');
	  $tbl->addCell('Bersedia', null, 'header');
	  $tbl->addCell('Hari', null, 'header'); 
	  $tbl->addCell('Jam Mulai', null, 'header');
      $tbl->addCell('Asisten', null, 'header');
	  //$tbl->addCell('ACC', null, 'header');
	  
				$dt_dosen= new dt_dosen;
                $dsn = $dt_dosen->getDataArray($kdds);
				
			   $frm_hiden = $frm->addInput('hidden', 'kdds', $kdds);			 
			   		   
			   $dt_mtk = $ksd_ngajar->getSebaranData($kdds,$baru);
			  if(!empty($dt_mtk)){			   
			   foreach($dt_mtk as $row){
			           $tbl->addRow();
				       
					   $tbl->addCell($row['semestbkmk'], null, 'data');
					   $tbl->addCell($this->ismrhitl($row['wp'],$row['kdkmkkrs']),null,'data');
					   $tbl->addCell($this->ismrhitl($row['wp'],$row['nakmktbkmk']),null,'data');
					   
					   
				       $tbl->addCell($this->ismrhitl($row['wp'],$row['sksmktbkmk']),null,'data',array('align'=>'center'));
					   
					   $tmp1= ($row['shiftkrs']=='R') ? "Reguler" : "Non Reguler";
					   $tbl->addCell($tmp1,null,'data');
					   
					  
                       
					   $tbl->addCell($row['semkrs'],null,'data');
					  					   
					   $tbl->addCell($row['kelaskrs'],null,'data');
					   	   
			           
					   $idx_arry=$row['kdkmkkrs']."_".$row['shiftkrs']."_".$row['semkrs']."_".$row['kelaskrs'];				   
					   
					   $tbl->addCell($frm->addInput('checkbox',"plh[]",$idx_arry),null,'data',array('id'=>'plh','align'=>'center'));	
					   $tbl->addCell($frm->addSelectList("hari['".$idx_arry."']",array(0=>'',1=>'Senin',2=>'Selasa',3=>'Rabu',4=>'Kamis',5=>'Jumat',6=>'Sabtu',7=>'Minggu'),true,null,null,array('id'=>'hari')),null,'data',array('align'=>'center'));
					   $tbl->addCell($frm->addInput('text',"mulai['".$idx_arry."']",'00:00:00'),null,'data',array('id'=>'mulai','align'=>'center'));	
					   
					   
					   $tbl->addCell($frm->addSelectList("ass['".$idx_arry."']",$dsn,true,"?????",null,array('id'=>'ass')),null,'data',array('align'=>'center'));
					   //$tbl->addCell($frm->addInput('text',"ass['".$idx_arry."']",'00:00:00'),null,'data',array('id'=>'ass','align'=>'center'));
					   
					   //$tbl->addCell($frm->addInput('checkbox',"acc['".$idx_arry."']",1),null,'data',array('id'=>'acc','align'=>'center'));	
					   				   
			    }
			   } 
			   
			 
			  //$tbl->addRow();
              //$tbl->addCell($frm->addInput('submit', 'save', 'Save',array('id'=>'save')), null, 'data',array('colspan'=>12,'align'=>'center'));
		
             $html_txt .= $frm_hiden.$tbl->display()."</form>"; 	   
	         $html_txt .= "</div>";
	         $html_txt .= "</fieldset>";
		
		$frmStr =$html_txt;
		
	  return $frmStr;
	}
	
	function build_riwayat_ksd($kdds,$thn)
	{
	    $html_txt  = "<fieldset>";
		$html_txt .= "<legend>Sebaran Matakuliah</legend>";
	    $html_txt .= "<div>";
			
	  
	  $tbl = new HTML_Table(null, 'sebaran', 0, 0, 0,array("id" => "sebaran","width"=>"100%"));
	  
	  $frm = new HTML_Form();
	  
	  $ksd_ngajar = new dt_ksd_ngajar();
	  
	  $tbl->addRow();
      $tbl->addCell('Sem', null, 'header');
	  $tbl->addCell('Kode', null, 'header');
      $tbl->addCell('Nama', null, 'header');
	  $tbl->addCell('SKS', null, 'header');
	  $tbl->addCell('Reg/Non Reg', null, 'header');
	  $tbl->addCell('Sem. Mhs.', null, 'header');
	  $tbl->addCell('Kls. Mhs.', null, 'header');
	  $tbl->addCell('Bersedia', null, 'header');
	  $tbl->addCell('Hari', null, 'header'); 
	  $tbl->addCell('Jam Mulai', null, 'header');
      $tbl->addCell('Asisten', null, 'header');
	  //$tbl->addCell('ACC', null, 'header');
	  
             $dt_dosen= new dt_dosen;
             $dsn = $dt_dosen->getDataArray($kdds);			
			
			 $frm_hiden = $frm->addInput('hidden', 'kdds', $kdds);
             $frm_hiden .= $frm->addInput('hidden', 'thn', $thn);			 
			   		   
			   $dt_mtk = $ksd_ngajar->getRiwayatSebaranData($kdds,$thn);
			  if(!empty($dt_mtk)){			   
			   foreach($dt_mtk as $row){
			           $tbl->addRow();
				       
					   $tbl->addCell($row['semestbkmk'], null, 'data');
					   $tbl->addCell($this->ismrhitl($row['wp'],$row['kdkmktrnlm']),null,'data');
					   $tbl->addCell($this->ismrhitl($row['wp'],$row['nakmktbkmk']),null,'data');
					   
					   
				       $tbl->addCell($this->ismrhitl($row['wp'],$row['sksmktbkmk']),null,'data',array('align'=>'center'));
					   
					   $tmp1= ($row['shifttrnlm']=='R') ? "Reguler" : "Non Reguler";
					   $tbl->addCell($tmp1,null,'data');
					   
					  
                       
					   $tbl->addCell($row['semestrnlm'],null,'data');
					  					   
					   $tbl->addCell($row['kelastrnlm'],null,'data');
					   	   
			           
					   $idx_arry=$row['kdkmktrnlm']."_".$row['shifttrnlm']."_".$row['semestrnlm']."_".$row['kelastrnlm'];				   
					   
					   $tbl->addCell($frm->addInput('checkbox',"plh[]",$idx_arry),null,'data',array('id'=>'plh','align'=>'center'));	
					   $tbl->addCell($frm->addSelectList("hari['".$idx_arry."']",array(0=>'',1=>'Senin',2=>'Selasa',3=>'Rabu',4=>'Kamis',5=>'Jumat',6=>'Sabtu',7=>'Minggu'),true,null,null,array('id'=>'hari')),null,'data',array('align'=>'center'));
					   $tbl->addCell($frm->addInput('text',"mulai['".$idx_arry."']",'00:00:00'),null,'data',array('id'=>'mulai','align'=>'center'));	
					   
					   $tbl->addCell($frm->addSelectList("ass['".$idx_arry."']",$dsn,true,"?????",null,array('id'=>'ass')),null,'data',array('align'=>'center'));
					   //$tbl->addCell($frm->addInput('text',"akhir['".$idx_arry."']",'00:00:00'),null,'data',array('id'=>'akhir','align'=>'center'));
					   
					   //$tbl->addCell($frm->addInput('checkbox',"acc['".$idx_arry."']",1),null,'data',array('id'=>'acc','align'=>'center'));	
					   				   
			    }
			   } 
			   
			 
			  //$tbl->addRow();
              //$tbl->addCell($frm->addInput('submit', 'save', 'Save',array('id'=>'save')), null, 'data',array('colspan'=>12,'align'=>'center'));
		
             $html_txt .= $frm_hiden.$tbl->display()."</form>"; 	   
	         $html_txt .= "</div>";
	         $html_txt .= "</fieldset>";
		
		$frmStr =$html_txt;
		
	  return $frmStr;
	}
	
	function edt_jadwal($kdds,$idx=1)
	{
	    $html_txt  = "<fieldset>";
		$html_txt .= "<legend>Sebaran Matakuliah</legend>";
	    $html_txt .= "<div>";
			
	  
	  $tbl = new HTML_Table(null, 'sebaran', 0, 0, 0,array("id" => "sebaran","width"=>"100%"));
	  
	  $frm = new HTML_Form();
	  
	  $ksd_ngajar = new dt_ksd_ngajar();
	  
	  $tbl->addRow();
      $tbl->addCell('Sem', null, 'header');
	  $tbl->addCell('Kode', null, 'header');
      $tbl->addCell('Nama', null, 'header');
	  $tbl->addCell('SKS', null, 'header');
	  $tbl->addCell('Reg/Non Reg', null, 'header');
	  $tbl->addCell('Sem. Mhs.', null, 'header');
	  $tbl->addCell('Kls. Mhs.', null, 'header');
	 if($idx==1)
	 {
	   $tbl->addCell('Hari', null, 'header'); 
	   $tbl->addCell('Jam Mulai', null, 'header');
       $tbl->addCell('Asisten', null, 'header');
	   
	  }else
	  {
	    if($idx==2)
        {
		  $tbl->addCell('Disetujui', null, 'header');
		  $tbl->addCell('Honor', null, 'header');
		} 		
		 else
		{
		 $tbl->addCell('Hapus', null, 'header');
		}  
	  }
			    $dt_dosen= new dt_dosen;
                $dsn = $dt_dosen->getDataArray($kdds);
				
			 $frm_hiden = $frm->addInput('hidden', 'kdds', $kdds);			 
			   		   
			   $dt_mtk = $ksd_ngajar->getDataMtk($kdds);
			  if(!empty($dt_mtk)){			   
			   foreach($dt_mtk as $row){
			           $tbl->addRow();
				       
					   $tbl->addCell($row['semestbkmk'], null, 'data');
					   $tbl->addCell($this->ismrhitl( isset($row['wp']) ? $row['wp']:"" ,$row['Kdkmk']),null,'data');
					   $tbl->addCell($this->ismrhitl( isset($row['wp']) ? $row['wp']:"" ,$row['nakmktbkmk']),null,'data');
					   
					   
				       $tbl->addCell($this->ismrhitl( isset($row['wp']) ? $row['wp']:"" ,$row['sksprtbkmk'] > 0 ? number_format($row['sksmktbkmk']-1, 2, '.', ' ') : $row['sksmktbkmk']),null,'data',array('align'=>'center'));
					   
					   $tmp1= ($row['shift']=='R') ? "Reguler" : "Non Reguler";
					   $tbl->addCell($tmp1,null,'data');
					   
					  
                       
					   $tbl->addCell($row['sem'],null,'data');
					  					   
					   $tbl->addCell($row['klsklh'],null,'data');
					   	   
			           
					   $idx_arry=$row['Kdkmk']."_".$row['shift']."_".$row['sem']."_".$row['klsklh'];				   	
					 if($idx==1)  
					 { 
					   $tbl->addCell($frm->addSelectList("hari['".$idx_arry."']",array(0=>'',1=>'Senin',2=>'Selasa',3=>'Rabu',4=>'Kamis',5=>'Jumat',6=>'Sabtu',7=>'Minggu'),true,intval($row['hariklh']),null,array('id'=>'hari')),null,'data',array('align'=>'center'));
					   $tbl->addCell($frm->addInput('text',"mulai['".$idx_arry."']",$row['jawalklh']),null,'data',array('id'=>'mulai','align'=>'center'));	
					   
					   $tbl->addCell($frm->addSelectList("ass['".$idx_arry."']",$dsn,true,$row['kdass'],null,array('id'=>'ass')),null,'data',array('align'=>'center'));
					   //$tbl->addCell($frm->addInput('text',"akhir['".$idx_arry."']",$row['jakhirklh']),null,'data',array('id'=>'akhir','align'=>'center'));
					   
					   
					   $frm_hiden .= $frm->addInput('hidden', "acc['".$idx_arry."']", $row['disetujui']);
					   $frm_hiden .= $frm->addInput('hidden',"hnr['".$idx_arry."']", $row['hnr']);
					  }
                      else
                       { if($idx==2)
					     {
						   $frm_hiden .= $frm->addInput('hidden',"hari['".$idx_arry."']",intval($row['hariklh']));
						   $frm_hiden .= $frm->addInput('hidden',"mulai['".$idx_arry."']",$row['jawalklh']);	
					       
						   $frm_hiden .= $frm->addInput('hidden',"ass['".$idx_arry."']",$row['kdass']);					       
						  
						  $tbl->addCell($frm->addInput('checkbox',"acc['".$idx_arry."']",1),null,'data',array('id'=>'acc','align'=>'center'));	
						  $tbl->addCell($frm->addSelectList("hnr['".$idx_arry."']",array('R'=>'Reguler','N'=>'Non Reguler'),true,$row['hnr'],null,array('id'=>'hnr')),null,'data',array('align'=>'center'));
						 }
						 else
						 {
						  $tbl->addCell($frm->addInput('checkbox',"plh[]",$idx_arry),null,'data',array('id'=>'plh','align'=>'center'));
						 } 
					   }					  
					   
					   
					   				   
			    }
			   } 
			   
			 
			  //$tbl->addRow();
              //$tbl->addCell($frm->addInput('submit', 'save', 'Save',array('id'=>'save')), null, 'data',array('colspan'=>12,'align'=>'center'));
		
             $html_txt .= $frm_hiden.$tbl->display()."</form>"; 	   
	         $html_txt .= "</div>";
	         $html_txt .= "</fieldset>";
		
		$frmStr =$html_txt;
		
	  return $frmStr;
	}
	
	function edt_riwayat_jadwal($kdds,$idx=1,$thn)
	{
	    $html_txt  = "<fieldset>";
		$html_txt .= "<legend>Sebaran Matakuliah</legend>";
	    $html_txt .= "<div>";
			
	  
	  $tbl = new HTML_Table(null, 'sebaran', 0, 0, 0,array("id" => "sebaran","width"=>"100%"));
	  
	  $frm = new HTML_Form();
	  
	  $ksd_ngajar = new dt_ksd_ngajar();
	  
	  $tbl->addRow();
      $tbl->addCell('Sem', null, 'header');
	  $tbl->addCell('Kode', null, 'header');
      $tbl->addCell('Nama', null, 'header');
	  $tbl->addCell('SKS', null, 'header');
	  $tbl->addCell('Reg/Non Reg', null, 'header');
	  $tbl->addCell('Sem. Mhs.', null, 'header');
	  $tbl->addCell('Kls. Mhs.', null, 'header');
	 if($idx==1)
	 {
	   $tbl->addCell('Hari', null, 'header'); 
	   $tbl->addCell('Jam Mulai', null, 'header');
       $tbl->addCell('Asisten', null, 'header');
	   
	  }else
	  {
	    if($idx==2)
        {
		  
		  $tbl->addCell('Honor', null, 'header');
		} 		
		 else
		{
		 $tbl->addCell('Hapus', null, 'header');
		}  
	  }
					 
			 
			 $dt_dosen= new dt_dosen;
             $dsn = $dt_dosen->getDataArray($kdds);	
			 
			 $frm_hiden = $frm->addInput('hidden', 'kdds', $kdds);
             $frm_hiden .= $frm->addInput('hidden', 'thn', $thn);			 
			   		   
			   $dt_mtk = $ksd_ngajar->getDataRiwayatMtk($kdds,$thn);
			  if(!empty($dt_mtk)){			   
			   foreach($dt_mtk as $row){
			           $tbl->addRow();
				       
					   $tbl->addCell($row['semestbkmk'], null, 'data');
					   $tbl->addCell($this->ismrhitl( isset($row['wp']) ? $row['wp']:"" ,$row['kdkmkpengajar']),null,'data');
					   $tbl->addCell($this->ismrhitl( isset($row['wp']) ? $row['wp']:"" ,$row['nakmktbkmk']),null,'data');
					   
					   
				       $tbl->addCell($this->ismrhitl( isset($row['wp']) ? $row['wp']:"" ,$row['sksprtbkmk'] > 0 ? number_format($row['sksmktbkmk']-1, 2, '.', ' ') : $row['sksmktbkmk']),null,'data',array('align'=>'center'));
					   
					   $tmp1= ($row['shiftpengajar']=='R') ? "Reguler" : "Non Reguler";
					   $tbl->addCell($tmp1,null,'data');
					   
					  
                       
					   $tbl->addCell($row['semespengajar'],null,'data');
					  					   
					   $tbl->addCell($row['kelaspengajar'],null,'data');
					   	   
			           
					   $idx_arry=$row['kdkmkpengajar']."_".$row['shiftpengajar']."_".$row['semespengajar']."_".$row['kelaspengajar'];				   	
					 if($idx==1)  
					 { 
					   $tbl->addCell($frm->addSelectList("hari['".$idx_arry."']",array(0=>'',1=>'Senin',2=>'Selasa',3=>'Rabu',4=>'Kamis',5=>'Jumat',6=>'Sabtu',7=>'Minggu'),true,intval($row['haripengajar']),null,array('id'=>'hari')),null,'data',array('align'=>'center'));
					   $tbl->addCell($frm->addInput('text',"mulai['".$idx_arry."']",$row['jawalpengajar']),null,'data',array('id'=>'mulai','align'=>'center'));	
					   $tbl->addCell($frm->addSelectList("ass['".$idx_arry."']",$dsn,true,$row['kdass'],null,array('id'=>'ass')),null,'data',array('align'=>'center'));
					   
					   //$tbl->addCell($frm->addInput('text',"akhir['".$idx_arry."']",$row['jakhirpengajar']),null,'data',array('id'=>'akhir','align'=>'center'));
					   	
					  }
                      else
                       { if($idx==2)
					     {
						   $frm_hiden .= $frm->addInput('hidden',"hari['".$idx_arry."']",intval($row['haripengajar']));
						   $frm_hiden .= $frm->addInput('hidden',"mulai['".$idx_arry."']",$row['jawalpengajar']);	
					       $frm_hiden .= $frm->addInput('hidden',"ass['".$idx_arry."']",$row['kdass']);					       
						  
						  
						  	
						  $tbl->addCell($frm->addSelectList("hnr['".$idx_arry."']",array('R'=>'Reguler','N'=>'Non Reguler'),true,$row['hnrpengajar'],null,array('id'=>'hnr')),null,'data',array('align'=>'center'));
						 }
						 else
						 {
						  $tbl->addCell($frm->addInput('checkbox',"plh[]",$idx_arry),null,'data',array('id'=>'plh','align'=>'center'));
						 } 
					   }					  
					   
					   
					   				   
			    }
			   } 
			   
			 
			  //$tbl->addRow();
              //$tbl->addCell($frm->addInput('submit', 'save', 'Save',array('id'=>'save')), null, 'data',array('colspan'=>12,'align'=>'center'));
		
             $html_txt .= $frm_hiden.$tbl->display()."</form>"; 	   
	         $html_txt .= "</div>";
	         $html_txt .= "</fieldset>";
		
		$frmStr =$html_txt;
		
	  return $frmStr;
	}
	
}	

?>