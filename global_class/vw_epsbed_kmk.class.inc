<?php 

    
	require_once 'shared.php';
	

class vw_epsbed_kmk
 {
	 function __construct()
	 {
	    
	 } 
	
	 function sem_filter()
	{
	  set_time_limit(120);
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
	  	  
	  $dtsem[20072]='Semester '.$txt_sem[2].' 2007';
	  $vtemp = 'Semester '.$txt_sem[2].' 2007';
	  $thnsms =20072;
			
	  for($i=2008;$i<=$bts;$i++)
	  {
	    for($j=1;$j<=2;$j++)
	    {
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
	 $html_txt.=$this->stat('stat1_epsbedtbkmk');
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
	  $tbl1->addCell($frm->addInput('submit',"Add","SIA->EPSBED",array('id'=>'Add')).$frm->addInput('submit',"Delete","Delete",array('id'=>'Del')).$frm->addInput('submit',"Salin","TA-1->tbkmk_h",array('id'=>'Salin')).$frm->addInput('submit',"Down","Download TBKMK.DBF",array('id'=>'Down')), null, 'data');
	  
	  
	  
	  $html_txt.=$tbl1->display()."</fieldset>";
	  
	  
	  $html_txt.="<div id='data'>";
	  $html_txt.=$this->epsbed_kmk($thnsms);
	  $html_txt.="</div>";
	  
	  $html_txt.="</fieldset>";
        	  
	  
	  return $html_txt;
	
	}
	 
	 function epsbed_kmk($thnsms)
	 {	 
	    set_time_limit(120);
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_epsbedkmk"));
	    $tbl->addRow();
        $tbl->addCell('Sem.', null, 'header');
		$tbl->addCell('Kode', null, 'header');
        $tbl->addCell('Matakuliah', null, 'header');
	    $tbl->addCell('SKS M.K.', null, 'header');
	    $tbl->addCell('TTP M.K', null, 'header');
	    $tbl->addCell('Pra. kum', null, 'header');
		$tbl->addCell('Pra. Lap.', null, 'header');		
		$tbl->addCell('Pengampu', null, 'header');
	    $tbl->addCell('Nama', null, 'header');
		$tbl->addCell('Status', null, 'header');
		
		$dt = new dt_epsbed_kmk;
	    $data = $dt->getviewdata($thnsms);
		
		if(!empty($data)){
		   $dt_mtk = new dt_mtk;
		    $dt_dsn = new dt_dosen;
		   foreach($data as $row)
		   {
		     
			  $tbl->addRow();
              $tbl->addCell($row['SEMESTBKMK'], null, 'data');
			  $tbl->addCell($row['KDKMKTBKMK'], null, 'data');
              $tbl->addCell($row['NAKMKTBKMK'], null, 'data');
	          $tbl->addCell($row['SKSMKTBKMK'], null, 'data',array('align'=>'center'));
	          $tbl->addCell($row['SKSTMTBKMK'], null, 'data',array('align'=>'center'));
	          $tbl->addCell($row['SKSPRTBKMK'], null, 'data',array('align'=>'center'));
			  $tbl->addCell($row['SKSLPTBKMK'], null, 'data',array('align'=>'center'));			  
			  $tbl->addCell($row['NODOSTBKMK'], null, 'data');
			  $tbl->addCell($row['NODOSTBKMK'] == "" ? "" : $dt_dsn->getnmdsn($row['NODOSTBKMK']), null, 'data');
			  $tbl->addCell($row['STKMKTBKMK'], null, 'data',array('align'=>'center'));
		    
		   }
		   
		}
		           $txt = '';
					$txt = $txt."<tr>";
						$txt = $txt."<th><input type='text' name='search_sem' value='Sem' class='search_init' style='width:20px' /></th>";
						$txt = $txt."<th><input type='text' name='search_kd' value='Kode' class='search_init' style='width:30px' /></th>";
						$txt = $txt."<th><input type='text' name='search_mtk' value='nm mtk' class='search_init' style='width:60px' /></th>";	
						$txt = $txt."<th></th>";
						$txt = $txt."<th></th>";											
						$txt = $txt."<th></th>";
						$txt = $txt."<th></th>";
						$txt = $txt."<th></th>";
						$txt = $txt."<th></th>";
                        $txt = $txt."<th></th>";						
					$txt = $txt."</tr>";
					
					
	 $html_txt="<fieldset>";
	 $html_txt.="<legend>Statistik</legend>";
	 $html_txt.=$this->stat('stat2_epsbedtbkmk',$thnsms);
	 $html_txt.="</fieldset>"; 				
					
	 $html_txt.="<fieldset><legend>List Matakuliah</legend>".$tbl->display($txt)."</fieldset>";
	 return $html_txt;
	 }
	 
	 function stat($tbid,$thn=0)
	 {
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => $tbid));
	    $tbl->addRow();
        if($thn==0){
		   $tbl->addRow();
		   $tbl->addCell('Semester', null, 'header',array("rowspan"=>2));
	       $tbl->addCell('Jumlah', null, 'header',array("colspan"=>5));
		   $tbl->addRow();
		   $tbl->addCell('Total Matakuliah.', null, 'header');
		   $tbl->addCell('Total SKS', null, 'header');
		   $tbl->addCell('Mtk. Wajib', null, 'header');
		   $tbl->addCell('SKS Wajib', null, 'header');
		   $tbl->addCell('Dosen Pengampu', null, 'header');
		}else{
		  $tbl->addRow();
		  $tbl->addCell('NIDN', null, 'header',array("rowspan"=>2));
	      $tbl->addCell('Nama', null, 'header',array("rowspan"=>2));
		  $tbl->addCell('Jumlah Matakuliah', null, 'header',array("colspan"=>4));
		  $tbl->addCell('Jumlah SKS', null, 'header',array("colspan"=>4));
		  $tbl->addRow();
		  $tbl->addCell('Total', null, 'header');
		  $tbl->addCell('Sem. Ganjil', null, 'header');
		  $tbl->addCell('Sem. Genap', null, 'header');
		  $tbl->addCell('Pilihan', null, 'header');
		  $tbl->addCell('Total', null, 'header');
		  $tbl->addCell('Sem. Ganjil', null, 'header');
		  $tbl->addCell('Sem. Genap', null, 'header');
		  $tbl->addCell('Pilihan', null, 'header');
		}
		    
		$dt = new dt_epsbed_kmk;
	    $data = $dt->stat($thn);
	    
		$txt='';
		
		if(!empty($data)){	      
              if($thn==0){
			    foreach($data as $f=>$v)
		        {
					   $tbl->addRow();
					   $tmp=str_split($f,4);
					   $tbl->addCell($tmp[1]==1 ? 'Ganjil '.$tmp[0] : 'Genap '.$tmp[0], null, 'data');			  
					   $tbl->addCell($v['jml_mtk'], null, 'data',array('align'=>'center'));
					   $tbl->addCell($v['jml_sks'], null, 'data',array('align'=>'center'));	
					   $tbl->addCell($v['jml_mtk_wjb'], null, 'data',array('align'=>'center'));
					   $tbl->addCell($v['jml_sks_wjb'], null, 'data',array('align'=>'center'));					   				   
					   $tbl->addCell($v['jml_dsn'], null, 'data',array('align'=>'center'));
				}	  
			  }else{
                    $dt_dsn = new dt_dosen;
			        foreach($data as $f=>$v)
		            { 
						if($f!='Jumlah'){  
						  $tbl->addRow();
						  $tbl->addCell($f, null, 'data');
						  $tbl->addCell($dt_dsn->getnmdsn($f), null, 'data');
						  $tbl->addCell($v['jml_mtk'], null, 'data',array('align'=>'center'));
						  
						  $tmp=isset($v['jml_mtk_gnjl']) ? $v['jml_mtk_gnjl'] : 0;
						  $tbl->addCell($tmp, null, 'data',array('align'=>'center'));
						  
						  $tmp=isset($v['jml_mtk_gnp']) ? $v['jml_mtk_gnp'] : 0;
						  $tbl->addCell($tmp, null, 'data',array('align'=>'center'));
						  
						  $tmp=isset($v['jml_mtk_pp']) ? $v['jml_mtk_pp'] : 0;
						  $tbl->addCell($tmp, null, 'data',array('align'=>'center'));
						  
						  $tbl->addCell($v['jml_sks'], null, 'data',array('align'=>'center'));
						  
						  $tmp=isset($v['jml_sks_gnjl']) ? $v['jml_sks_gnjl']:0;
						  $tbl->addCell($tmp, null, 'data',array('align'=>'center'));
						  
						  $tmp=isset($v['jml_sks_gnp']) ? $v['jml_sks_gnp']: 0;
						  $tbl->addCell($tmp, null, 'data',array('align'=>'center'));
						  
						  $tmp=isset($v['jml_sks_pp']) ? $v['jml_sks_pp']: 0;
						  $tbl->addCell($tmp, null, 'data',array('align'=>'center'));
						}else{
						
						  $txt = $txt."<tr>";
						  $txt = $txt."<th colspan='2'>Jumlah</th>";											
						  
						  $txt = $txt."<th  align='center' >".$v['jml_mtk']."</th>";
						  $tmp=isset($v['jml_mtk_gnjl']) ? $v['jml_mtk_gnjl'] : 0;
						  $txt = $txt."<th  align='center' >$tmp</th>";
						  $tmp=isset($v['jml_mtk_gnp']) ? $v['jml_mtk_gnp'] : 0;
						  $txt = $txt."<th  align='center' >$tmp</th>";
						  $tmp=isset($v['jml_mtk_pp']) ? $v['jml_mtk_pp'] : 0;
						  $txt = $txt."<th  align='center' >$tmp</th>";
						  
						  $txt = $txt."<th  align='center' >".$v['jml_sks']."</th>";
						  
						  $tmp=isset($v['jml_sks_gnjl']) ? $v['jml_sks_gnjl']:0;
						  $txt = $txt."<th  align='center' >$tmp</th>";
						  $tmp=isset($v['jml_sks_gnp']) ? $v['jml_sks_gnp']: 0;
						  $txt = $txt."<th  align='center' >$tmp</th>";
						  $tmp=isset($v['jml_sks_pp']) ? $v['jml_sks_pp']: 0;				
					      $txt = $txt."<th  align='center' >$tmp</th>";
						  $txt = $txt."</tr>";
						  
                        }						
			       }
			  }			  
			  	
		   
		
		}
         
		
	  return $tbl->display($txt);
	 }
	
}
?>