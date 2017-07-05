<?php
	require_once 'shared.php';
	
	class vw_ta
    {

	  function __construct()
	  {
	    
	  } 
	  
	  
	  function addsidang($thn,$nim,$id)
	  {
	     $frm = new HTML_Form();
		 
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tabelentry","width"=>"100%"));
		$tbl->addRow();
		$tbl->addCell('Semester', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"thn",$thn,array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('NIM', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"nim",$nim,array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Nama', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$dt_mhs = new dt_mhs;
		$nm = $dt_mhs->getnmmhs($nim);
		$tbl->addCell($frm->addInput('text',"nama",$nm,array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Judul Skripsi', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$dtta = new dt_ta;
		$tema= $dtta->gettema($id);
		$tbl->addCell($frm->addTextarea("judultxt",4,50,$tema), null, 'data');

        $tbl->addRow();
		$tbl->addCell('Abstrak Indonesia', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addTextarea("absindotxt",4,50), null, 'data');

        $tbl->addRow();
		$tbl->addCell('Abstrak Inggris', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addTextarea("absingtxt",4,50), null, 'data'); 	
		
        $tbl->addRow();
		$tbl->addCell('Tanggal Sidang', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"tglsid",null,array('id'=>'tglsid')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Sesi', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"sesi",null,array('id'=>'sesi')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Tanggal Lulus', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"tgllls",null,array('id'=>'tgllls')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Tanggal SK Penguji', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"tglsk",null,array('id'=>'tglsk')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('No SK Penguji', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"nosk",null), null, 'data');		
				
        $tbl->addRow();
		$tbl->addCell('Penguji 1', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		
		$dt_dsn = new dt_dosen;
		$data=$dt_dsn->getAllData("kode<>'?????'");
		
		$kddsn['']='Tidak Ditentukan';
		if(!empty($data))
		{
		  foreach($data as $row1)
		  {
	        $kd=$row1['Kode'];
			$nama = str_replace(' ', '&nbsp;',$row1['Nama']);	  
		    $kddsn[$kd]=$nama;
		  
		  }
		
		}
		
        $tbl->addCell($frm->addSelectList("Penguji1",$kddsn,true,null,null,array('id'=>'kddsn')), null, 'data');    
		
		$tbl->addRow();
		$tbl->addCell('Penguji 2', null, 'data'); 
        $tbl->addCell(':', null, 'data');
        
		
        $tbl->addCell($frm->addSelectList("Penguji2",$kddsn,true,null,null,array('id'=>'kddsn1')), null, 'data');	

        $tbl->addRow();
		$tbl->addCell('Penguji 3', null, 'data'); 
        $tbl->addCell(':', null, 'data');
        
		
        $tbl->addCell($frm->addSelectList("Penguji3",$kddsn,true,null,null,array('id'=>'kddsn2')), null, 'data');   		 
			         
		$tbl->addRow();
		$tbl->addCell('NIDN Pembimbing 1', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		
        
		$data=$dt_dsn->getAllData("(kode<>'?????') and (nidn_epsbed!='') and (nidn_epsbed=nidn) and (Tstat='DTY') and (Hstat in ('DTY','LB'))");
		$kddsn=array();
		$kddsn['']='Tidak Ditentukan';
		if(!empty($data))
		{
		  foreach($data as $row1)
		  {
	        $kd=$row1['nidn_epsbed'];
			$nama = str_replace(' ', '&nbsp;',$row1['Nama']);	  
		    $kddsn[$kd]=$nama;
		  
		  }
		
		}
		
        $tbl->addCell($frm->addSelectList("Pemb1",$kddsn,true,null,null,array('id'=>'pemb1')), null, 'data');    
		
		$tbl->addRow();
		$tbl->addCell('NIDN Pembimbing 2', null, 'data'); 
        $tbl->addCell(':', null, 'data');
        
		
        $tbl->addCell($frm->addSelectList("Pemb2",$kddsn,true,null,null,array('id'=>'pemb2')), null, 'data');	
    
		
	     return $frm->startForm(null,'post','frmsidang').$tbl->display().$frm->endForm();	
	  }
	  
	  function editsidang($id)
	  {
	    $thn='';
		$nim='';
		$nosk='';
		$tglsk='';
		$tglsidang='';
		$tgllls='';
		$jdlskripsi='';
		$absindo='';
		$absing='';
		$sesi='';
		$pemb1='';
		$pemb2='';
		$dtsidang = new tb_gen('tbsidang');
        $data = $dtsidang->getData('idsidang = "'.$id.'"');
			 if(!empty($data))
			 {
			   foreach($data as $row)
			   {
			     $thn=$row['thsmssidang'];
				 $nim=$row['nimhssidang'];
				 $nosk=$row['noskpenguji'];
				 $tglsk=$row['tglskpenguji'];
				 $tglsidang=$row['tglsidang'];
				 $tgllls=$row['tgllls'];
				 $jdlskripsi=$row['jdlskripsi'];
				 $absindo=$row['abs_indo'];
				 $absing=$row['abs_ing'];
				 $sesi=$row['sesi'];
				 $pemb1=$row['nidn_pemb1'];
				 $pemb2=$row['nidn_pemb2'];
			   }
			 }
				
		$pemb=array(1=>'',2=>'',3=>'');		
		$dtvpenguji = new tb_gen('vw_penguji');
		
		$data1 = $dtvpenguji->getData('id = "'.$id.'"');
			 if(!empty($data1))
			 {
			   foreach($data1 as $row1)
			   {
			     $pemb[$row1['penugasan']]=$row1['Kode'];
			   }
			 }
		
		
		 $frm = new HTML_Form();
		 
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tabelentry","width"=>"100%"));
		$tbl->addRow();
		$tbl->addCell('Semester', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"thn",$thn,array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('NIM', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"nim",$nim,array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Nama', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$dt_mhs = new dt_mhs;
		$nm = $dt_mhs->getnmmhs($nim);
		$tbl->addCell($frm->addInput('text',"nama",$nm,array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Judul Skripsi', null, 'data'); 
        $tbl->addCell(':', null, 'data');		
		$tbl->addCell($frm->addTextarea("judultxt",4,50,$jdlskripsi), null, 'data');

        $tbl->addRow();
		$tbl->addCell('Abstrak Indonesia', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addTextarea("absindotxt",4,50,$absindo), null, 'data');

        $tbl->addRow();
		$tbl->addCell('Abstrak Inggris', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addTextarea("absingtxt",4,50,$absing), null, 'data'); 	
		
        $tbl->addRow();
		$tbl->addCell('Tanggal Sidang', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"tglsid",$tglsidang,array('id'=>'tglsid')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Sesi', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"sesi",$sesi,array('id'=>'sesi')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Tanggal Lulus', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"tgllls",$tgllls,array('id'=>'tgllls')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Tanggal SK Penguji', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"tglsk",$tglsk,array('id'=>'tglsk')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('No SK Penguji', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"nosk",$nosk), null, 'data');		
				
        $tbl->addRow();
		$tbl->addCell('Penguji 1', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		
		$dt_dsn = new dt_dosen;
		$data=$dt_dsn->getAllData("kode<>'?????'");
		
		$kddsn['']='Tidak Ditentukan';
		if(!empty($data))
		{
		  foreach($data as $row1)
		  {
	        $kd=$row1['Kode'];
			$nama = str_replace(' ', '&nbsp;',$row1['Nama']);	  
		    $kddsn[$kd]=$nama;
		  
		  }
		
		}
		
        $tbl->addCell($frm->addSelectList("Penguji1",$kddsn,true,$pemb[1],null,array('id'=>'kddsn')), null, 'data');    
		
		$tbl->addRow();
		$tbl->addCell('Penguji 2', null, 'data'); 
        $tbl->addCell(':', null, 'data');
        
		
        $tbl->addCell($frm->addSelectList("Penguji2",$kddsn,true,$pemb[2],null,array('id'=>'kddsn1')), null, 'data');	

        $tbl->addRow();
		$tbl->addCell('Penguji 3', null, 'data'); 
        $tbl->addCell(':', null, 'data');
        
		
        $tbl->addCell($frm->addSelectList("Penguji3",$kddsn,true,$pemb[3],null,array('id'=>'kddsn2')), null, 'data');   		 
		
        $tbl->addRow();
		$tbl->addCell('NIDN Pembimbing 1', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		
		$data=$dt_dsn->getAllData("(kode<>'?????') and (nidn_epsbed!='') and (nidn_epsbed=nidn) and (Tstat='DTY') and (Hstat in ('DTY','LB'))");
		$kddsn=array();
		$kddsn['']='Tidak Ditentukan';
		if(!empty($data))
		{
		  foreach($data as $row1)
		  {
	        $kd=$row1['nidn_epsbed'];
			$nama = str_replace(' ', '&nbsp;',$row1['Nama']);	  
		    $kddsn[$kd]=$nama;
		  
		  }
		
		}
		
        $tbl->addCell($frm->addSelectList("Pemb1",$kddsn,true,$pemb1,null,array('id'=>'pemb1')), null, 'data');    
		
		$tbl->addRow();
		$tbl->addCell('NIDN Pembimbing 2', null, 'data'); 
        $tbl->addCell(':', null, 'data');
        
		
        $tbl->addCell($frm->addSelectList("Pemb2",$kddsn,true,$pemb2,null,array('id'=>'pemb2')), null, 'data');	
		
			     
	     return $frm->startForm(null,'post','frmsidang').$tbl->display().$frm->endForm();	
	  }
	  
	  
	  function addbimbingan($thn,$nim)
	  {
	     $frm = new HTML_Form();
		 
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tabelentry","width"=>"100%"));
		$tbl->addRow();
		$tbl->addCell('Semester', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"thn",$thn,array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('NIM', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"nim",$nim,array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Nama', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$dt_mhs = new dt_mhs;
		$nm = $dt_mhs->getnmmhs($nim);
		$tbl->addCell($frm->addInput('text',"nama",$nm,array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Tema', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addTextarea("tema",4,50), null, 'data');		
				
		$tbl->addRow();
		$tbl->addCell('Tanggal Surat Tugas', null, 'data'); 
        $tbl->addCell(':', null, 'data');		
		$tbl->addCell($frm->addInput('text',"tglsrttgs",null,array('id'=>'tglsrttgs')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('No Surat Tugas', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"nosrttgs",null), null, 'data');		
				
		$tbl->addRow();
		$tbl->addCell('Tanggal SK Bimbingan', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"tglsk",null,array('id'=>'tglsk')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('No SK Bimbingan', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"noskbimbingan",null), null, 'data');		
				
        $tbl->addRow();
		$tbl->addCell('Pembimbing 1', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		
		$dt_dsn = new dt_dosen;
		$data=$dt_dsn->getAllData("kode<>'?????'");
		
		$kddsn['']='Tidak Ditentukan';
		if(!empty($data))
		{
		  foreach($data as $row1)
		  {
	        $kd=$row1['Kode'];
			$nama = str_replace(' ', '&nbsp;',$row1['Nama']);	  
		    $kddsn[$kd]=$nama;
		  
		  }
		
		}
		
         $tbl->addCell($frm->addSelectList("Pembimbing1",$kddsn,true,null,null,array('id'=>'kddsn')), null, 'data');    
		
		$tbl->addRow();
		$tbl->addCell('Pembimbing 2', null, 'data'); 
        $tbl->addCell(':', null, 'data');
        
		
         $tbl->addCell($frm->addSelectList("Pembimbing2",$kddsn,true,null,null,array('id'=>'kddsn1')), null, 'data');		
			         
			     
	     return $frm->startForm(null,'post','frmbimbingan').$tbl->display().$frm->endForm();	
	  }
	  
	  function editbimbingan($id)
	  {
	    $thn='';
		$nim='';
		$nosrttgs='';
		$noskbimbingan='';
		$tglsk='';
		$tglsrttgs='';
		$tema='';
		$dtbimbingan = new tb_gen('tbbimbingan');
        $data = $dtbimbingan->getData('idbimbingan = "'.$id.'"');
			 if(!empty($data))
			 {
			   foreach($data as $row)
			   {
			     $thn=$row['thsmsbimbingan'];
				 $nim=$row['nimhsbimbingan'];
				 $noskbimbingan=$row['nosk'];
				 $nosrttgs=$row['nosrttgs'];
				 $tglsk=$row['tglsk'];
				 $tglsrttgs=$row['tglsrttgs'];
				 $tema=$row['temabimbingan'];
			   }
			 }
				
		$pemb=array(1=>'',2=>'');		
		$dtvpembimbing = new tb_gen('vw_pembimbing');
		
		$data1 = $dtvpembimbing->getData('id = "'.$id.'"');
			 if(!empty($data1))
			 {
			   foreach($data1 as $row1)
			   {
			     $pemb[$row1['penugasan']]=$row1['Kode'];
			   }
			 }
		
		
		$frm = new HTML_Form();		
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tabelentry","width"=>"100%"));
		$tbl->addRow();
		$tbl->addCell('Semester', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"thn",$thn,array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('NIM', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"nim",$nim,array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Nama', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$dt_mhs = new dt_mhs;
		$nm = $dt_mhs->getnmmhs($nim);
		$tbl->addCell($frm->addInput('text',"nama",$nm,array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Tema', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addTextarea("tema",4,50,$tema), null, 'data');		
				
		$tbl->addRow();
		$tbl->addCell('Tanggal Surat Tugas', null, 'data'); 
        $tbl->addCell(':', null, 'data');		
		$tbl->addCell($frm->addInput('text',"tglsrttgs",$tglsrttgs,array('id'=>'tglsrttgs')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('No Surat Tugas', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"nosrttgs",$nosrttgs), null, 'data');		
				
		$tbl->addRow();
		$tbl->addCell('Tanggal SK Bimbingan', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"tglsk",$tglsk,array('id'=>'tglsk')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('No SK Bimbingan', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"noskbimbingan",$noskbimbingan), null, 'data');		
				
        $tbl->addRow();
		$tbl->addCell('Pembimbing 1', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		
		$dt_dsn = new dt_dosen;
		$data=$dt_dsn->getAllData("kode<>'?????'");
		
		$kddsn['']='Tidak Ditentukan';
		if(!empty($data))
		{
		  foreach($data as $row1)
		  {
	        $kd=$row1['Kode'];
			$nama = str_replace(' ', '&nbsp;',$row1['Nama']);	  
		    $kddsn[$kd]=$nama;
		  
		  }
		
		}
		
         $tbl->addCell($frm->addSelectList("Pembimbing1",$kddsn,true,$pemb[1],null,array('id'=>'kddsn')), null, 'data');    
		
		$tbl->addRow();
		$tbl->addCell('Pembimbing 2', null, 'data'); 
        $tbl->addCell(':', null, 'data');
        
		
         $tbl->addCell($frm->addSelectList("Pembimbing2",$kddsn,true,$pemb[2],null,array('id'=>'kddsn1')), null, 'data');		
			         
			     
	     return $frm->startForm(null,'post','frmbimbingan').$tbl->display().$frm->endForm();
	  }
	  
	  
	  function view_bimbingan()
	  {
	    		
		$dtkrs = new dt_krs;		
		$TA = $dtkrs->TA();
		
		$dt_ta = new dt_ta;
		$data1 = $dt_ta->getDataViewBimbingan();
		$data2 = $dt_ta->getDataViewHBimbingan();
		
		$header = array(array("TA",'NIM','Nama','Tema','Pembimbing','Dokumen',"Aksi"));
		$tbstat = array("id" => "poll1",'width'=>'100%');		
		$tbl1 = new mytable($tbstat,$header,$data2,"");		
		$tbstat = array("id" => "poll2",'width'=>'100%');		
		$tbl2 = new mytable($tbstat,$header,$data1,"");	
		
		
		$html_txt='';
		$html_txt="<div id='tabs'>";
		
	    $html_txt.="<ul>";
        $html_txt.="<li><a href='#tabs-1'><".$TA."</a></li>";
        $html_txt.="<li><a href='#tabs-2'>".$TA."</a></li>";      
        $html_txt.="</ul>";
			
		$html_txt.="<div id='tabs-1'>";		
		$html_txt.= $tbl1->display();
		$html_txt.="</div>";
		
		$html_txt.="<div id='tabs-2'>";
		$html_txt.= $tbl2->display();		
		$html_txt.="</div>";
		
		return $html_txt;
	  }

	   function view_bimbingan1()
	  {
	    $dt_ta = new dt_ta;
		$data = $dt_ta->getDataViewBimbingan1();		
		
		$header = array(array('NIM','Nama','Tema','Pembimbing'));
		$tbstat = array("id" => "tbbimbingan",'width'=>'100%');		
		$tbl = new mytable($tbstat,$header,$data,"");
		
		return $tbl->display();		
	  }
	
	  function view_sidang()
	  {
	    		
		$dtkrs = new dt_krs;		
		$TA = $dtkrs->TA();
		
		$dt_ta = new dt_ta;
		$data1 = $dt_ta->getDataViewSidang();
		$data2 = $dt_ta->getDataViewHSidang();
		
		$header = array(array("TA",'NIM','Nama','Judul','Penguji','Tanggal','Sesi','Dokumen',"Aksi"));
		$tbstat = array("id" => "poll1",'width'=>'100%');		
		$tbl1 = new mytable($tbstat,$header,$data2,"");		
		$tbstat = array("id" => "poll2",'width'=>'100%');		
		$tbl2 = new mytable($tbstat,$header,$data1,"");	
		
		
		$html_txt='';
		$html_txt="<div id='tabs'>";
		
	    $html_txt.="<ul>";
        $html_txt.="<li><a href='#tabs-1'><".$TA."</a></li>";
        $html_txt.="<li><a href='#tabs-2'>".$TA."</a></li>";      
        $html_txt.="</ul>";
			
		$html_txt.="<div id='tabs-1'>";		
		$html_txt.= $tbl1->display();
		$html_txt.="</div>";
		
		$html_txt.="<div id='tabs-2'>";
		$html_txt.= $tbl2->display();		
		$html_txt.="</div>";
		
		return $html_txt;
	  } 
	  
	  function view_sidang1()
	  {
	    					
		$dt_ta = new dt_ta;
		$data = $dt_ta->getDataViewHSidang1();		
		
		$header = array(array('Tanggal','Sesi','Nama','Judul','Penguji 1','Penguji 2','Penguji 3'));
		$tbstat = array("id" => "tbsidang",'width'=>'100%');		
		$tbl = new mytable($tbstat,$header,$data,"");
		
		return $tbl->display();
	  } 
	  
	  function view_judulskripsi()
	  {
	    					
		$dt_ta = new dt_ta;
		$data = $dt_ta->getJudulSkripsi();		
		
		$header = array(array('No','Tanggal Lulus','Nama','Judul','Pembimbing 1','Pembimbing 2'));
		$tbstat = array("id" => "tbjudul",'width'=>'100%');		
		$tbl = new mytable($tbstat,$header,$data,"");
		
		return $tbl->display();
	  } 
	 
    }
?>