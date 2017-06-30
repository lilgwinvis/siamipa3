<?php
   require_once 'shared.php';

class vw_trnlp
{ 
  function __construct()
 {
	
 }

  function lst_mhs()
  {
    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_mhs","width"=>"100%"));
	   
	   $tbl->addRow();
	   $tbl->addCell("Angkatan", null, 'header');
	   $tbl->addCell("NIM", null, 'header');
	   $tbl->addCell("Nama", null, 'header');	   
	   $tbl->addCell("SKS Konversi", null, 'header');
	   $tbl->addCell("Aksi", null, 'header');	  
				 
		     $tb = new tb_gen('vw_trnlp_jn_msmhs_jn_tbkmk');
		     $data = $tb->getData("");		 
			 
			 if(!empty($data)){
			     $tmp="";
				 
				 foreach($data as $row){    
					
					
					
					$tbl->addRow();		 			
                   
                   		$tbl->addCell($row['tahunmsmhs'], null, 'data');
						$tbl->addCell($row['nimhsmsmhs'], null, 'data');
						$tbl->addCell($row['nmmhsmsmhs'], null, 'data');
						$tbl->addCell($row['jml_sks']==null ? 0 : $row['jml_sks'] , null, 'data',array('align'=>'right'));						
						
						$link="frm_edit_trnlp.php?nim=".$row['nimhsmsmhs'];						
					    $tbl->addCell("<a href='$link'>Edit Konversi</a>", null, 'data',array('align'=>'center'));
		  			
				 }		 
			 
			 }
			 
		 return $tbl->display();
  
  }
  
  function lht_trnlp($nim)
  {
         $user = $_SESSION['user'];
	     
		            
		 $dtuser = new dt_user;
         $hak = $dtuser->gethak($user); 	
	  
	  
	  $html_txt  = "<fieldset>";
	   $html_txt .= "<legend>Aksi</legend>";
	  
       $tbl = new HTML_Table(null, 'aksi', 0, 0, 0,array("id" => "aksi"));
	   
	    $tbl->addRow();
		$tbl->addCell("<button type='submit' id='ambil'".($hak==0 ? 'disabled':'').">Tambah Mtk</button>", null, 'data');
	   	$tbl->addCell("<button type='submit' id='edit'".($hak==0 ? 'disabled':'')." >Edit HM</button>", null, 'data');
		$tbl->addCell("<button type='submit' id='hapus'".($hak==0 ? 'disabled':'')." >Hapus Mtk.</button>", null, 'data');
		$tbl->addCell("<button type='submit' id='export'".($hak==0 ? 'disabled':'')." >Publikasi</button>", null, 'data');
       
	   $html_txt .= $tbl->display();
       $html_txt .= "</fieldset>";
       $html_txt .= "<fieldset>";	   
	   $html_txt .= "<legend>Nilai Konversi</legend>";
	   $html_txt .= "<div>";
	   $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_konversi","width"=>"100%"));
	   
	    $tbl->addRow();
		$tbl->addCell("Sem", null, 'header');
		$tbl->addCell("Kode Mata Kuliah", null, 'header');
		$tbl->addCell("Nama Mata Kuliah", null, 'header');
		$tbl->addCell("SKS", null, 'header');
		$tbl->addCell("HM", null, 'header');
		$tbl->addCell("NM", null, 'header');
		$tbl->addCell("Kelas", null, 'header');		  
		  
		 
		  $tb = new tb_gen('vw_trnlp_jn_tbkmk');
		  $data = $tb->getData("nimhstrnlp='$nim'");
		    
			if(!empty($data)){ 
			  foreach($data as $row){	  
			   
				 
				 $tbl->addRow();
				 $tbl->addCell($row['semestbkmk'], null, 'data');
				 $tbl->addCell($row['kdkmktrnlp'], null, 'data');
				 $tbl->addCell($row['nakmktbkmk'], null, 'data');
				 $tbl->addCell($row['sksmktbkmk'], null, 'data');
				 $tbl->addCell($row['nlakhtrnlp'], null, 'data');
				 $tbl->addCell($row['bobottrnlp'], null, 'data');
				 $tbl->addCell($row['kelastrnlp'], null, 'data');			
				 
              }			  
            }
       $html_txt .= $tbl->display();
       $html_txt .= "</div>";	   
	   $html_txt .= "</fieldset>";	   
	  
	   return $html_txt;
  
  }
  
  function build_trnlp($nim,$baru=1)
  {
        $html_txt  = "<fieldset>";
		$html_txt .= "<legend>Daftar Matakuliah</legend>";
	    $html_txt .= "<div>";
		$frm = new HTML_Form();
		$html_txt .= $frm->startForm(null,'post','entrytrnlp');
		//$html_txt .= "<form name='inputtrnlp' id='inputtrnlp' method='post' action='isitrnlp.php'>";
	    //$html_txt .= "<input type='hidden' name='nim' value='$nim'>";
	    $html_txt .= $frm->addInput('hidden',"nim",$nim);
		
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_mtk","width"=>"100%"));
	     
	    $tbl->addRow();
		$tbl->addCell("Sem", null, 'header');
		$tbl->addCell("Kode Mata Kuliah", null, 'header');
		$tbl->addCell("Nama Mata Kuliah", null, 'header');
		$tbl->addCell("SKS", null, 'header');
		if($baru==1 | $baru==3){
		  $tbl->addCell("Pilih", null, 'header');
		}
		
		if($baru!=3){
		$tbl->addCell("A", null, 'header');
		$tbl->addCell("B", null, 'header');
		$tbl->addCell("C", null, 'header');
		$tbl->addCell("D", null, 'header');
		$tbl->addCell("E", null, 'header');
		}
		$dt_trnlp = new dt_trnlp; 
		
		$data=$dt_trnlp->data_trnlp($nim,$baru);
		
		if(!empty($data))
		{
		  $i=1;
		      
		  
		  foreach($data as $row)
		  {
		    $tbl->addRow();
			$tbl->addCell($row['semestbkmk'], null, 'data');
		    if($baru==1){
			  $tbl->addCell($row['kdkmktbkmk'], null, 'data');
		    }else{
			  $tbl->addCell($row['kdkmktrnlp'], null, 'data');
			}
			$tbl->addCell($row['nakmktbkmk'], null, 'data');
		    $tbl->addCell($row['sksmktbkmk'], null, 'data');
		  
		  if($baru==1){
		    $tbl->addCell($frm->addInput('checkbox',"mk[]",$row['kdkmktbkmk'],array('id'=>'mk')), null, 'data');
		   }else{
		    if($baru==3){
		    $tbl->addCell($frm->addInput('checkbox',"mk[]",$row['kdkmktrnlp'],array('id'=>'mk')), null, 'data');
		   }
		   
		   }
          
		  if($baru!=3){  		  
			if($baru==1){			  
			  $tbl->addCell($frm->addInput('radio',"nilai[".$row['kdkmktbkmk']."]","A",array('id'=>'nilaiA'.$i)), null, 'data');
		      $tbl->addCell($frm->addInput('radio',"nilai[".$row['kdkmktbkmk']."]","B",array('id'=>'nilaiB'.$i)), null, 'data');
		      $tbl->addCell($frm->addInput('radio',"nilai[".$row['kdkmktbkmk']."]","C",array('id'=>'nilaiC'.$i)), null, 'data');
		      $tbl->addCell($frm->addInput('radio',"nilai[".$row['kdkmktbkmk']."]","D",array('id'=>'nilaiD'.$i)), null, 'data');
		      $tbl->addCell($frm->addInput('radio',"nilai[".$row['kdkmktbkmk']."]","E",array('id'=>'nilaiE'.$i)), null, 'data');				
			} else 
			{
			  
			  if(trim($row['nlakhtrnlp'])=='A')
			  {
			    $tbl->addCell($frm->addInput('radio',"nilai[".$row['kdkmktrnlp']."]","A",array('id'=>'nilaiA'.$i,'checked'=>'checked')), null, 'data');
			  }else{
			    $tbl->addCell($frm->addInput('radio',"nilai[".$row['kdkmktrnlp']."]","A",array('id'=>'nilaiA'.$i)), null, 'data');
		      }
			  
			  if(trim($row['nlakhtrnlp'])=='B')
			  {
			    
				$tbl->addCell($frm->addInput('radio',"nilai[".$row['kdkmktrnlp']."]","B",array('id'=>'nilaiB'.$i,'checked'=>'checked')), null, 'data');
			  }else{
			    
				$tbl->addCell($frm->addInput('radio',"nilai[".$row['kdkmktrnlp']."]","B",array('id'=>'nilaiB'.$i)), null, 'data');
		      }
			  
			  if(trim($row['nlakhtrnlp'])=='C')
			  {
			    $tbl->addCell($frm->addInput('radio',"nilai[".$row['kdkmktrnlp']."]","C",array('id'=>'nilaiC'.$i,'checked'=>'checked')), null, 'data');
			  }else{
			    $tbl->addCell($frm->addInput('radio',"nilai[".$row['kdkmktrnlp']."]","C",array('id'=>'nilaiC'.$i)), null, 'data');
		      }
			  
			  if(trim($row['nlakhtrnlp'])=='D')
			  {
			    $tbl->addCell($frm->addInput('radio',"nilai[".$row['kdkmktrnlp']."]","D",array('id'=>'nilaiD'.$i,'checked'=>'checked')), null, 'data');
			  }else{
			    $tbl->addCell($frm->addInput('radio',"nilai[".$row['kdkmktrnlp']."]","D",array('id'=>'nilaiD'.$i)), null, 'data');
		      }
			  
			  if(trim($row['nlakhtrnlp'])=='E')
			  {
			    $tbl->addCell($frm->addInput('radio',"nilai[".$row['kdkmktrnlp']."]","E",array('id'=>'nilaiE'.$i,'checked'=>'checked')), null, 'data');
			  }else{
			    $tbl->addCell($frm->addInput('radio',"nilai[".$row['kdkmktrnlp']."]","E",array('id'=>'nilaiE'.$i)), null, 'data');
              }			
			
			
			} 
		   } 
              	
			
			$i++;
		  }
		}
		
	   if($baru==1){
	    $tbl1 = new HTML_Table(null, 'jml_sks', 0, 0, 0,array("id" => "jml_sks","width"=>"100%"));
	    $tbl1->addRow();
	    $tbl1->addCell("<b>JUMLAH SKS YANG DIAMBIL</b>", null, 'data',array('colspan'=>3,'align'=>'center'));		
        $tmp_input =	"<input type='text' name='totalsks' size='3' maxlength='3' id='jsks' readonly='readonly' style='text-align:center; color:red;'>";	
	    $tbl1->addCell($tmp_input, null, 'data',array('align'=>'center'));   
        $html_txt .= $tbl->display().$tbl1->display().$frm->endForm();
	   }else {
	     $html_txt .= $tbl->display().$frm->endForm();
	   }	
	    $html_txt .= "</div>";
	    $html_txt .= "</fieldset>";
	   
	    return $html_txt;
  }
  
}

?>