<?php
	require_once 'shared.php';
	
	class vw_poll
    {

	  function __construct()
	  {
	    
	  } 
	  
	  function view_mpoll($thn,$nim)
	  {
	   $vbaca_poll = new dt_poll;
       $data=$vbaca_poll->getDataVMpoll('nimhsmpoll="'.$nim.'" AND thsmsmpoll<='.$thn.' AND isimpoll=0');	   
	   $html_txt=''; 
	   
	   $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_kuosioner","width"=>"100%"));
	   $tbl->addRow();
	   $tbl->addCell("Sem", null, 'header');
	   $tbl->addCell("Kode Mata Kuliah", null, 'header');
	   $tbl->addCell("Nama Mata Kuliah", null, 'header');
	   $tbl->addCell("Kode Dosen", null, 'header');
	   $tbl->addCell("Nama Dosen", null, 'header');
	   $tbl->addCell("Aksi", null, 'header');
	   
	   if(!empty($data))
	   {
	     foreach($data as $row)
		 {
		   $tbl->addRow();		   
		   $tbl->addCell($row['thsmsmpoll'], null, 'data');
		   $tbl->addCell($row['kdkmkmpoll'], null, 'data');
		   $tbl->addCell($row['nakmktbkmk'], null, 'data');
		   $tbl->addCell($row['kddspengajar'], null, 'data');
		   $tbl->addCell($row['nama'], null, 'data');  
		   //'thsmsmpoll,semmpoll,shiftmpoll,kelasmpoll,kdkmkmpoll,nakmktbkmk,kddspengajar,nama'
		   $link="frm_kuosioner.php?thn=".$row['thsmsmpoll']."&sem=".$row['semmpoll']."&shift=".$row['shiftmpoll']."&kelas=".$row['kelasmpoll']."&nim=".$nim."&kdkmk=".$row['kdkmkmpoll']."&nmkmk=".$row['nakmktbkmk']."&kdds=".$row['kddspengajar']."&nmds=".$row['nama'];
		   $tbl->addCell("<a href='$link'>Isi</a>", null, 'data'); 
		 }   
	   }
	   
	   $html_txt=$tbl->display();
       return $html_txt;	   
	  }
	
	  function admin_view_mpoll()
	  {
	    		
		$dtkrs = new dt_krs;		
		$TA = $dtkrs->TA();
		
		$dt_poll = new dt_poll;
		$data1 = $dt_poll->getDataadminVMpoll();
		$data2 = $dt_poll->getDataadminVMpoll1();
		
		$header = array(array("TA","Semester","Kelas","Kode Matakuliah","Nama Matakuliah","Kode Dosen","Nama Dosen","Jumlah Siswa","Jumlah Kuosioner Diisi","Aksi"));
		$tbstat = array("id" => "poll1",'width'=>'100%');		
		$tbl1 = new mytable($tbstat,$header,$data1,"");		
		$tbstat = array("id" => "poll2",'width'=>'100%');		
		$tbl2 = new mytable($tbstat,$header,$data2,"");	
		
		
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
	 
    }
?>