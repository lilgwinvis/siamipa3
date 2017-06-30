<?php 

  require_once 'shared.php';
	

class vw_epsbed_trlsm
 {
	 function __construct()
	 {
	    
	 } 
	
	 function sem_filter()
	{
	  $dtkrs = new dt_krs;
	  $TA = $dtkrs->TA();
      	  	
		
	  $thn = str_split($TA, 4);
	  
	  $dtsem = array();
	  $txt_sem = array(1=>'Ganjil',2=>'Genap');
	  $vtemp = "";	  
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
	      if($vtemp=="")
          {
		    $vtemp = 'Semester '.$txt_sem[$j].' '.$i;
			$thnsms =$i.$j;
		  }
		  
		  $dtsem[$i.$j]='Semester '.$txt_sem[$j].' '.$i;
	    } 
	  }	  
	  
	  if($thn[1]==1)
	  {
	    $dtsem[$thn[0].'1']='Semester Ganjil '.$thn[0];
	  }
	  
	 
     $html_txt="<fieldset>";
	 $html_txt.="<legend>Statistik</legend>";
	 $html_txt.="<div id='stat'>";
	 $html_txt.=$this->stat('stat1_epsbedtrnlm');
	 $html_txt.="</div>";
	 $html_txt.="</fieldset>";      

	  
	  $frm = new HTML_Form();
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmfilter"));
	  $tbl->addRow();
      $tbl->addCell('Semester'.$frm->addSelectList("semester",$dtsem,true,null,null,array('id'=>'semester')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')), null, 'data');
	  
	  $html_txt.="<fieldset>";
	  $html_txt.="<legend>Filter</legend>";
	  $html_txt.=$tbl->display()."</fieldset>";

      $html_txt.="<fieldset>";
	  $html_txt.="<legend  id='hsl_filter'>Hasil Filter : ".$vtemp."</legend>";
      
	  $html_txt.="<fieldset>";
	  $html_txt.="<legend>Aksi</legend>";
	  $frm = new HTML_Form();
	  $tbl1 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmAksi"));
	  $tbl1->addRow();
	  $tbl1->addCell($frm->addInput('submit',"Add","SIA->EPSBED",array('id'=>'Add')).$frm->addInput('submit',"Delete","Delete",array('id'=>'Del')).$frm->addInput('submit',"Down","Download TRLSM.DBF",array('id'=>'Down')), null, 'data');
	  
	  
	  
	  $html_txt.=$tbl1->display()."</fieldset>";
	  
	  
	  $html_txt.="<div id='data'>";
	  $html_txt.=$this->epsbed_trlsm($thnsms);
	  $html_txt.="</div>";
	  
	  $html_txt.="</fieldset>";
        	  
	  
	  return $html_txt;
	
	}
	 
	 function epsbed_trlsm($thnsms)
	 {	 
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_epsbedtrakd"));
	    $tbl->addRow();
        $tbl->addCell('NIM', null, 'header');
	    $tbl->addCell('Nama', null, 'header');
	    $tbl->addCell('Status', null, 'header');
        	    
		
		$stat=array('A'=>'Aktif','C'=>'Cuti','D'=>'DO','K'=>'Keluar','L'=>'Lulus','N'=>'Non-Aktif');
		
		$dt = new dt_epsbed_trlsm;
	    $data = $dt->getviewdata($thnsms);
		
		if(!empty($data)){
		   
		    $dt_mhs = new dt_mhs;
		   foreach($data as $row)
		   {
		      
			  $tbl->addRow();
              $tbl->addCell($row['NIMHSTRLSM'], null, 'data');
	          $tbl->addCell($dt_mhs->getnmmhs($row['NIMHSTRLSM']), null, 'data');
	          $tbl->addCell($stat[$row['STMHSTRLSM']], null, 'data');              
		    
		   }
		   
		}
		           $txt = '';
					$txt = $txt."<tr>";
						$txt = $txt."<th><input type='text' name='search_nim' value='NIM' class='search_init' style='width:51px' /></th>";
						$txt = $txt."<th><input type='text' name='search_nm' value='nm mhs' class='search_init' /></th>";	
						$txt = $txt."<th><input type='text' name='search_stat' value='Stat' class='search_init' style='width:30px'/></th>";
																	
					$txt = $txt."</tr>";
	 
	 
	 $html_txt="<fieldset>";
	 $html_txt.="<legend>Statistik</legend>";
	 $html_txt.=$this->stat('stat2_epsbedtrnlm',$thnsms);
	 $html_txt.="</fieldset>";
	 
	 $html_txt.="<fieldset>";
	 $html_txt.="<legend>List Status Mahasiswa</legend>"; 
	 $html_txt.=$tbl->display($txt);
	 $html_txt.="</fieldset>";
	 return $html_txt;
	 }
	 
	 function stat($tbid,$thn=0)
	 {
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => $tbid));
	    
        if($thn==0){
		   $tbl->addRow();
		    $tbl->addCell('Semester', null, 'header',array("rowspan"=>2));
		    $tbl->addCell('Status Mahasiswa', null, 'header',array("colspan"=>4));
		    $tbl->addCell('Total', null, 'header',array("rowspan"=>2));
		    $tbl->addRow();
		    $tbl->addCell('Cuti', null, 'header');
			$tbl->addCell('Keluar', null, 'header');
		    $tbl->addCell('Lulus', null, 'header');
		    $tbl->addCell('Non Aktif', null, 'header');	
		    
		  
		}else{
		  $tbl->addRow();
		    $tbl->addCell('Angkatan', null, 'header',array("rowspan"=>2));
		    $tbl->addCell('Status Mahasiswa', null, 'header',array("colspan"=>4));
		    $tbl->addCell('Total', null, 'header',array("rowspan"=>2));
		    $tbl->addRow();
		    $tbl->addCell('Cuti', null, 'header');
			$tbl->addCell('Keluar', null, 'header');
		    $tbl->addCell('Lulus', null, 'header');
		    $tbl->addCell('Non Aktif', null, 'header');
		}
		
	    
        
		$dt = new dt_epsbed_trlsm;
	    $data = $dt->stat($thn);
	    $txt='';
		if(!empty($data)){   
		      
              if($thn==0){
					   
					 foreach($data as $f=>$v)
		            {  
					   $tbl->addRow();
					   $tmp=str_split($f,4);
					   $tbl->addCell($tmp[1]==1 ? 'Ganjil '.$tmp[0] : 'Genap '.$tmp[0] , null, 'data');
					   $tbl->addCell(isset($v['C']) ? $v['C'] : 0, null, 'data',array('align'=>'center'));
					   $tbl->addCell(isset($v['K']) ? $v['K'] : 0, null, 'data',array('align'=>'center'));
					   $tbl->addCell(isset($v['L']) ? $v['L'] : 0, null, 'data',array('align'=>'center'));
					   $tbl->addCell(isset($v['N']) ? $v['N'] : 0, null, 'data',array('align'=>'center'));
					   $tbl->addCell(isset($v['Total']) ? $v['Total'] : 0, null, 'data',array('align'=>'center'));
			        } 
			  }else{
                           
			   foreach($data as $f=>$v)
		       {
			        if($f!='Jumlah'){  
   					   $tbl->addRow();
					   $tbl->addCell($f, null, 'data');					   
					   $tbl->addCell(isset($v['C']) ? $v['C'] : 0, null, 'data',array('align'=>'center'));
					   $tbl->addCell(isset($v['K']) ? $v['K'] : 0, null, 'data',array('align'=>'center'));
					   $tbl->addCell(isset($v['L']) ? $v['L'] : 0, null, 'data',array('align'=>'center'));
					   $tbl->addCell(isset($v['N']) ? $v['N'] : 0, null, 'data',array('align'=>'center'));
					   $tbl->addCell(isset($v['Total']) ? $v['Total'] : 0, null, 'data',array('align'=>'center'));
					}else{
                          $txt = $txt."<tr>";
						  $txt = $txt."<th>Jumlah</th>";						 
						  $txt = $txt."<th  align='center' >".(isset($v['C']) ? $v['C'] : 0)."</th>";						  
						  $txt = $txt."<th  align='center' >".(isset($v['K']) ? $v['K'] : 0)."</th>";						  
						  $txt = $txt."<th  align='center' >".(isset($v['L']) ? $v['L'] : 0)."</th>";						  
						  $txt = $txt."<th  align='center' >".(isset($v['N']) ? $v['N'] : 0)."</th>";						 
						  $txt = $txt."<th  align='center' >".(isset($v['Total']) ? $v['Total'] : 0)."</th>";						  
						  $txt = $txt."</tr>";

                    } 					
                      			   
			   } 
			  			  
			  	
		   }
		
		}
         
		
	  return $tbl->display($txt);
	 }
	 
	 
	
}
?>