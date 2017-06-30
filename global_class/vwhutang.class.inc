<?php
     
	 require_once 'shared.php';
	 
	 class vwhutang 
	{
      var $vhutang;
	  function __construct(){
	   	  $this->vhutang=new dt_hutang;   	   
	    }
	  
	  
	  function dsn_filter()
	  {
	      
		  
           $vmhs = new dt_dosen;
		   $data = $vmhs->getDataPenghutang("Kode != '?????'");
		   $vtemp= "";
		   $vkode="";
		   foreach($data as $row){	
                 if(empty($vtemp)){
					$vtemp = $row['Kode']." - ".$row['Nama'];
					$vkode = $row['Kode'];
				 }	
                              
            $dsn[$row['Kode']]=$row['Kode']." - ".$row['Nama'] ;
           }

		  
		  $frm = new HTML_Form();
	      $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmfilter"));
	      $tbl->addRow();
	      $tbl->addCell('Nama Dosen '.$frm->addSelectList("Kode",$dsn,true,null,null,array('id'=>'Kode')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')), null, 'data');
	      
		  $html_txt="<div id='tabs'>";
		
          $html_txt.="<ul>";
          $html_txt.="<li><a href='#tabs-1'>Seluruh Dosen</a></li>";
          $html_txt.="<li><a href='#tabs-2'>Per Dosen</a></li>";
          $html_txt.="</ul>";
		  $html_txt.="<div id='tabs-1'>"; 
			  $vwnilai = new vwnilai;
			  $html_txt.=$vwnilai->viewdata(0);
		  $html_txt.="</div>";
		  $html_txt.="<div id='tabs-2'>";  
			  
			  $html_txt.="<fieldset>";
			  $html_txt.="<legend>Filter</legend>";
			  
			  $html_txt.=$tbl->display()."</fieldset>";

			  $html_txt.="<fieldset>";
			  $html_txt.="<legend  id='hsl_filter'> Hasil Filter : ".$vtemp."</legend>";
			  
			  $html_txt.="<div id='data'>";
			  $html_txt.=$this->buildhutang($vkode);
			  $html_txt.="</div>";
		  
			  $html_txt.="</fieldset>";
		   
		   $html_txt.="</div>"; 	  
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
	  
	   function buildhutang($vkode,$idx=1){
	          
			  
			  $hak=1;
			  if($idx==1)
			  {
			    $user = $_SESSION['user'];
	                     
		        $dtuser = new dt_user;
                $hak = $dtuser->gethak($user);
			  }
			  
			  $this->vhutang->buildsem($vkode);
	          
			  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_hutang","Width"=>"100%"));
	          $tbl->addRow();
			  $tbl->addCell("TA", null, 'header');
	          $tbl->addCell("Kode", null, 'header');
			  $tbl->addCell("Matakuliah", null, 'header'); 
			  $tbl->addCell("Angkatan", null, 'header');
	          $tbl->addCell("Kelas", null, 'header');
			  $tbl->addCell("Sem. Mhs.", null, 'header');
			  $tbl->addCell("Kls. Mhs.", null, 'header');
			  $tbl->addCell("Jml. Mhs.", null, 'header');
			  $tbl->addCell("Jml. N. T", null, 'header');
	          $tbl->addCell("Aksi", null, 'header');
			  //$tbl->addCell("Aksi2", null, 'header');
			  
		   for($i = 0; $i < count($this->vhutang->vthsms_txt); $i++){
		       
			  $data = $this->vhutang->buildhutang($vkode,$this->vhutang->vthsms[$i]);
				 foreach($data as $row){
				     
  					  $tbl->addRow();

					  $hsl= $this->vhutang->detailhutang($this->vhutang->vthsms[$i],$row['kdkmkpengajar'],$row['shiftpengajar'],$row['kelaspengajar'],$row['semespengajar']);
					  
					  $link="../global_code/frm_lht_nilai.php?thnsms=".$this->vhutang->vthsms[$i]."&kdkmk=".$row['kdkmkpengajar']."&kelas=".$row['shiftpengajar']."&kelas1=".$row['kelaspengajar']."&sem=".$row['semespengajar'];
					  $link1="../global_code/frm_entry_nilai.php?thnsms=".$this->vhutang->vthsms[$i]."&kdkmk=".$row['kdkmkpengajar']."&kelas=".$row['shiftpengajar']."&kelas1=".$row['kelaspengajar']."&sem=".$row['semespengajar'];
					  $link2='javascript:ctk_excel(21,"'.$row['semespengajar'].'","'.$row['shiftpengajar'].'","'.$row['kdkmkpengajar'].'","'.$row['nakmktbkmk'].'","'.$vkode.'",'.$this->vhutang->vthsms[$i].')';
					  $link3='javascript:ctk_excel(22,"'.$row['semespengajar'].'","'.$row['shiftpengajar'].'","'.$row['kdkmkpengajar'].'","'.$row['nakmktbkmk'].'","'.$vkode.'",'.$this->vhutang->vthsms[$i].')';
					
					  $tbl->addCell($this->vhutang->vthsms[$i], null, 'data');					  
					  $tbl->addCell($this->ismrhitl($row['wp'],$row['kdkmkpengajar']), null, 'data');
					  $tbl->addCell($this->ismrhitl($row['wp'],$row['nakmktbkmk']), null, 'data');
					  $tbl->addCell($hsl['thnsms'], null, 'data');				
                      $tbl->addCell($row['shiftpengajar']=='R' ? 'Reguler' : 'Non Reguler', null, 'data');
	                  $tbl->addCell($row['semespengajar'], null, 'data');
					  $tbl->addCell($row['kelaspengajar'], null, 'data');
					  $tbl->addCell($hsl['jml_mhs'], null, 'data');
					  $tbl->addCell($hsl['jml_T'], null, 'data');  
					  $tbl->addCell( $hsl['jml_mhs']!=0 ? "<a href='$link'>Lihat Nilai</a><br><a href='".($hak==1?$link1:'')."'>Edit Nilai</a><br><a href='$link2'>DHMD</a><br><a href='$link3'>DPNA</a>" : 'Lihat Nilai<br>Edit Nilai<br>DHMD<br>DPNA', null, 'data');
					  //$tbl->addCell( $hsl['jml_mhs']!=0 ? "<a href='$link1'>Edit Nilai</a>" : 'Edit Nilai', null, 'data');	
						
				 }
              
		   }
		      
		  return $tbl->display();
	    }
    }
?>