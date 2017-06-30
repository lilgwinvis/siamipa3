<?php
  require_once 'shared.php';
   
class vwkeuangk
{
  function __construct()
	{
	  
	}
		
   function filter_mhs($vthn,$vkls)
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
	  
	  $vtemp = $thn." ".$tmp; 					
	  
	  $frm = new HTML_Form();
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmfilter"));
	  $tbl->addRow();
	  $tbl->addCell('Angkatan '.$frm->addSelectList("Angkatan",$ang,true,$vthn,null,array('id'=>'Angkatan')).' Kelas '.$frm->addSelectList("kls",$kelas,true,$vkls,null,array('id'=>'kls')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')), null, 'data');
	   
	  $html_txt.=$tbl->display()."</fieldset>";

      $html_txt.="<fieldset>";
	  $html_txt.="<legend  id='hsl_filter'>Daftar Kewajiban : ".$vtemp."</legend>";
      
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
	  $hitattr['id']='Hit';
	  
	  if($hak==0)
	  {
		 $addattr['disabled']='disabled'; 
         $editattr['disabled']='disabled'; 
         $delattr['disabled']='disabled';
         $hitattr['disabled']='disabled';  		 
	  }	  
	  
	  
	  $tbl1->addCell($frm->addInput('submit',"Add","Add",$addattr).
	  	             $frm->addInput('submit',"Edit","Edit",$editattr).
					 $frm->addInput('submit',"Delete","Delete",$delattr).
					 $frm->addInput('submit',"Hitung","Hitung",$hitattr)
					 , null, 'data');
	  $html_txt.=$tbl1->display()."</fieldset>";
	  
	  
	  $html_txt.="<div id='data'>";
	  $html_txt.=$this->keuangk($vthn,$vkls);
	  $html_txt.="</div>";
	  
	  $html_txt.="</fieldset>";
        	  
	  
	  return $html_txt;
	  
	}
	
	function keuangk($thn,$shift)
	{
	  
	    $dibyr=array(0=>'Sekali',1=>'Persemester',2=>'Persemester Per-SKS');
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_trans"));
	    $tbl->addRow();
       	$tbl->addCell('Kode', null, 'header');
	    $tbl->addCell('Nama Akun', null, 'header');
        $tbl->addCell('Dibayar', null, 'header');
		$tbl->addCell('Kewajiban', null, 'header');
	    $tbl->addCell('Total', null, 'header');
		
        $dt = new dt_keuangk;   		
	    $data = $dt->getkeuangk($thn,$shift);
	    $ttl=0;
	    if(!empty($data))		
		{
		  
		  foreach($data as $row)
		  {
		     $tbl->addRow();
             
			
			 $tbl->addCell($row['noacclvl1keuangk'], null, 'data');			 
		     $tbl->addCell($row['nmacclvl1'], null, 'data');
			 $tbl->addCell($dibyr[$row['kalibyrkeuangk']], null, 'data');
	         $tbl->addCell(number_format($row['jmlbyrkeuangk'], 2, ',', '.'), null, 'data',array('align'=>'right'));
             $ttl+=$row['jmlbyrkeuangk'];
			 $tbl->addCell(number_format($ttl, 2, ',', '.'), null, 'data',array('align'=>'right'));
		    
			 
		  }
		}
	           $txt = '';
					$txt = $txt."<tr>";
						$txt = $txt."<th></th>";											
						$txt = $txt."<th></th>";
						$txt = $txt."<th></th>";
						$txt = $txt."<th>Total</th>";
                        $txt = $txt."<th align='right'>".number_format($ttl, 2, ',', '.')."</th>";						
					$txt = $txt."</tr>";
	  
	  
	  $html_txt="<fieldset>".$tbl->display($txt)."</fieldset>";
	  return $html_txt;
	}	
	
  	function frm_add($thn,$kls)
	{
	  $frm = new HTML_Form();
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmAdd"));
	  
	  $tbl->addRow();
	  $tbl->addCell("Angkatan", null, 'data');
      $tbl->addCell(":", null, 'data');	 
      $tbl->addCell($frm->addInput('text',"thn",$thn,array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');	  
	  
	  $tbl->addRow();
	  $tbl->addCell("Kelas", null, 'data');
	  $tbl->addCell(":", null, 'data');
	  $tbl->addCell($frm->addSelectList("kls",array('R'=>'R - Reguler','N'=>'N - Non Reguler'),true,$kls,null,array('id'=>'kls','readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');  
	  
	  $dt = new dt_keuangk;   		
	  $data = $dt->getnoacclvl1($thn,$kls);
	  
	  $noacc =array();
	  if(!empty($data))
	  {
	    foreach($data as $row)
		{
		  $noacc[$row['noacclvl1']]=$row['noacclvl1']." - ".$row['nmacclvl1'];		  
		}
	  
	  }
	  
	  $tbl->addRow();
	  $tbl->addCell("Akun", null, 'data');
	  $tbl->addCell(":", null, 'data');
	  $tbl->addCell($frm->addSelectList("acc",$noacc,true,null,null,array('id'=>'acc')), null, 'data');  
	  
	  $tbl->addRow();
	  $tbl->addCell("Kewajiban", null, 'data');
      $tbl->addCell(":", null, 'data');	 
      $tbl->addCell($frm->addInput('text',"kewajiban",0.00), null, 'data');	  
	  
	  $tbl->addRow();
	  $tbl->addCell("Dibayar", null, 'data');
	  $tbl->addCell(":", null, 'data');
	  $tbl->addCell($frm->addSelectList("dibyr",array(0=>'Sekali',1=>'Persemester',2=>'Persemester Per-SKS'),true,null,null,array('id'=>'dibyr')), null, 'data');
	  
	  return $frm->startForm(null,'post','entrykeuangk').$tbl->display().$frm->endForm();
	
	}
	function frm_edit($thn,$kls,$kd)
	{
	
	  $frm = new HTML_Form();
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmAdd"));
	  
	  $tbl->addRow();
	  $tbl->addCell("Angkatan", null, 'data');
      $tbl->addCell(":", null, 'data');	 
      $tbl->addCell($frm->addInput('text',"thn",$thn,array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');	  
	  
	  $tbl->addRow();
	  $tbl->addCell("Kelas", null, 'data');
	  $tbl->addCell(":", null, 'data');
	  $tbl->addCell($frm->addSelectList("kls",array('R'=>'R - Reguler','N'=>'N - Non Reguler'),true,$kls,null,array('id'=>'kls','readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');  
	  
	  $dt = new dt_keuangk;   		
	  $data = $dt->getnoacclvl1($thn,$kls,0);
	  
	  $noacc =array();
	  if(!empty($data))
	  {
	    foreach($data as $row)
		{
		  $noacc[$row['noacclvl1']]=$row['noacclvl1']." - ".$row['nmacclvl1'];		  
		}
	  
	  }
	  
	  $tbl->addRow();
	  $tbl->addCell("Akun", null, 'data');
	  $tbl->addCell(":", null, 'data');
	  $tbl->addCell($frm->addSelectList("acc",$noacc,true,intval($kd),null,array('id'=>'acc','readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');  
	  
	  		
	  $byr = $dt->getbyr($thn,$kls,$kd);
	  
	  $tbl->addRow();
	  $tbl->addCell("Kewajiban", null, 'data');
      $tbl->addCell(":", null, 'data');	 
      $tbl->addCell($frm->addInput('text',"kewajiban",$byr), null, 'data');	  
	  
	  $dibyr=$dt->getdibyr($thn,$kls,$kd);
	  
	  $tbl->addRow();
	  $tbl->addCell("Dibayar", null, 'data');
	  $tbl->addCell(":", null, 'data');
	  $tbl->addCell($frm->addSelectList("dibyr",array(0=>'Sekali',1=>'Persemester',2=>'Persemester Per-SKS'),true,intval($dibyr),null,array('id'=>'dibyr')), null, 'data');
	  
	  return $frm->startForm(null,'post','entrykeuangk').$tbl->display().$frm->endForm();
	
	}
	
	function frm_del($thn,$kls)
	{
	    $frm = new HTML_Form();
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_trans"));
	    $tbl->addRow();
       	$tbl->addCell('Kode', null, 'header');
	    $tbl->addCell('Nama Akun', null, 'header');
        $tbl->addCell('Kewajiban', null, 'header');
	    $tbl->addCell('Hapus', null, 'header');
		
        $dt = new dt_keuangk;   		
	    $data = $dt->getkeuangk($thn,$kls);
	  
	    if(!empty($data))		
		{
		  
		  foreach($data as $row)
		  {
		     $tbl->addRow();
             
			
			 $tbl->addCell($row['noacclvl1keuangk'], null, 'data');			 
		     $tbl->addCell($row['nmacclvl1'], null, 'data');
	         $tbl->addCell(number_format($row['jmlbyrkeuangk'], 2, ',', '.'), null, 'data',array('align'=>'right'));
            
			 $tbl->addCell($frm->addInput('checkbox',"plh[]",$row['noacclvl1keuangk']), null, 'data',array('align'=>'center'));
		    
			 
		  }
		}
	  
	  
	  
	  $html_txt="<fieldset>".$frm->startForm(null,'post','entrykeuangk').$tbl->display().$frm->endForm()."</fieldset>";
	  return $html_txt;
	   
	}
}

?>	