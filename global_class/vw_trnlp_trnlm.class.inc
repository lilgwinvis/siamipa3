<?php
   
  
  require_once 'shared.php';
   
   
   class vw_trnlp_trnlm 
	{
	  
	  function __construct(){
	   	   	   
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
	  $tbl->addCell('Angkatan '.$frm->addSelectList("Angkatan",$ang,true,null,null,array('id'=>'Angkatan')).' Kelas '.$frm->addSelectList("kls",$kelas,true,null,null,array('id'=>'kls')).' Mahasiswa '.$frm->addSelectList("Mhs",$Mhs,true,null,null,array('id'=>'Mhs')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')), null, 'data');
	   
	  $html_txt.=$tbl->display()."</fieldset>";

      $html_txt.="<fieldset>";
	  $html_txt.="<legend  id='hsl_filter'> Hasil Filter : ".$vtemp."</legend>";
      	  
	  
	  $html_txt.="<div id='data'>";
	  $html_txt.=$this->edt_trnlp_trnlm($vnim);
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
	  
	  function edt_trnlp_trnlm($vnim){
	  	     
           $user = $_SESSION['user'];
	     
		            
		 $dtuser = new dt_user;
         $hak = $dtuser->gethak($user); 			 

			  
		  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "tb_filter",'width'=>'100%'));
	          $tbl->addRow();
	          $tbl->addCell("Semester", null, 'header');
	          $tbl->addCell("Kode", null, 'header');
		  $tbl->addCell("Matakuliah", null, 'header'); 
		  $tbl->addCell("A", null, 'header');
	          $tbl->addCell("B", null, 'header');	  			  
		  $tbl->addCell("C", null, 'header');	  
	          $tbl->addCell("D", null, 'header');
		  $tbl->addCell("E", null, 'header');
		  $tbl->addCell("T", null, 'header');
		  $tbl->addCell("K", null, 'header');
		  $tbl->addCell("S", null, 'header');	
		
		  $tb = new dt_trnlp_trnlm;
		  $data = $tb->getData('nimhstrnlm="'.$vnim.'"');
		  if(!empty($data))
		  {  $i=1;
		     foreach($data as $row)
		     {
			   $tbl->addRow();
			   $tbl->addCell($row['thsmstrnlm'], null, 'data');
			   $tbl->addCell($row['kdkmktrnlm'], null, 'data');
			   $tbl->addCell($row['nakmktbkmk'], null, 'data'); 
			   
			   
						 $Acheck="";
						 $Bcheck="";
						 $Ccheck="";
						 $Dcheck="";
						 $Echeck="";
						 $Tcheck="";
						 $Kcheck="";
						 $Scheck="";
						 switch($row['nlakhtrnlm']){
						   case 'A' : $Acheck="checked";
						            break;
						   case 'B' : $Bcheck="checked";
						            break;
						   case 'C' : $Ccheck="checked";
						            break;
						   case 'D' : $Dcheck="checked";
						            break;
						   case 'E' : $Echeck="checked";
						            break;
						   case 'T' : $Tcheck="checked";
						            break;									
						   case 'K' : $Kcheck="checked";
						            break;
						   case 'S' : $Scheck="checked";
						            break; 			
						 }
			   
			   
			   $tbl->addCell('<input type="radio" name="nilai['.trim($row['thsmstrnlm']).'_'.trim($row['kdkmktrnlm']).']" value="A" id="nilaiA'.$i.'"  '.$Acheck.' >', null, 'data');
			   $tbl->addCell('<input type="radio" name="nilai['.trim($row['thsmstrnlm']).'_'.trim($row['kdkmktrnlm']).']" value="B" id="nilaiB'.$i.'"  '.$Bcheck.' >', null, 'data');	  			  
			   $tbl->addCell('<input type="radio" name="nilai['.trim($row['thsmstrnlm']).'_'.trim($row['kdkmktrnlm']).']" value="C" id="nilaiC'.$i.'"  '.$Ccheck.' >', null, 'data');	  
			   $tbl->addCell('<input type="radio" name="nilai['.trim($row['thsmstrnlm']).'_'.trim($row['kdkmktrnlm']).']" value="D" id="nilaiD'.$i.'"  '.$Dcheck.' >', null, 'data');
			   $tbl->addCell('<input type="radio" name="nilai['.trim($row['thsmstrnlm']).'_'.trim($row['kdkmktrnlm']).']" value="E" id="nilaiE'.$i.'"  '.$Echeck.' >', null, 'data');
			   $tbl->addCell('<input type="radio" name="nilai['.trim($row['thsmstrnlm']).'_'.trim($row['kdkmktrnlm']).']" value="T" id="nilaiT'.$i.'"  '.$Tcheck.' >', null, 'data');
			   $tbl->addCell('<input type="radio" name="nilai['.trim($row['thsmstrnlm']).'_'.trim($row['kdkmktrnlm']).']" value="K" id="nilaiK'.$i.'"  '.$Kcheck.' >', null, 'data');
			   $tbl->addCell('<input type="radio" name="nilai['.trim($row['thsmstrnlm']).'_'.trim($row['kdkmktrnlm']).']" value="S" id="nilaiS'.$i.'"  '.$Scheck.' >', null, 'data');
			   $i=$i+1;
						 
		     }
		     $txt="'".$vnim."'";
		     return $tbl->display("").'<BR>'.'<button type="button" id="btn_save" onclick="save('.$txt.')" '.($hak==0 ? 'disabled':'').'>Save</button>';
		  }else{
		    return $tbl->display("");
		  }
	  }
	  
	  
	  
	}

?>