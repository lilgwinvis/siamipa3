<?php
  require_once 'shared.php';
  class vw_log
  {
     var $lg;
     function __construct()
	 {
	   $this->lg=new login;
	 }
	 
	 
	 function filter_user()
	 {
	   
	  $frm = new HTML_Form();
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frm_filter"));
	  $tbl->addRow();
      $tbl->addCell("Jenis User".$frm->addSelectList("jns_user",array(1=>"Admin",2=>"Mahasiswa",3=>"Dosen"),true,null,null,array('id'=>'jns_user')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')), null, 'data');
	  
	 
	  $html_txt="<fieldset>"; 
	  $html_txt.="<legend>Filter</legend>";
	  $html_txt.=$tbl->display()."</fieldset>"; 
	  
	  $html_txt.="<fieldset>"; 
	  $html_txt.="<legend>Login List</legend>";
	  $html_txt.="<div id='data'>";
	  $html_txt.=$this->buildlst(1);
	  $html_txt.="</div>";
	  $html_txt.="</fieldset>";
	  return $html_txt;
	 
	 }
	 
	 
	 function buildlst($tg)
	 {
	    
		$tbl = new HTML_Table(null, 'lst_lg', 0, 0, 0,array("id" => "lst_lg","width"=>"100%"));
		$tbl->addRow();
		$tbl->addCell("No", null, 'header');
		$tbl->addCell("Log In Time", null, 'header');
		$tbl->addCell("Log Out Time", null, 'header');
		$tbl->addCell("User", null, 'header');
		$tbl->addCell("IP Address", null, 'header');
		$tbl->addCell("Alamat", null, 'header');
		
		$data=$this->lg->getData($tg);
		
		if(!empty($data))
		{ 
		  $i=1;
		  foreach($data as $row)
		  {
		    $tbl->addRow();
			$tbl->addCell($i, null, 'data');
		    $tbl->addCell($row['lg_time'], null, 'data');
		    $tbl->addCell($row['out_time'], null, 'data');
		    $tbl->addCell($row['user'], null, 'data');
			$tbl->addCell($row['net_id'], null, 'data');
			$tbl->addCell($row['alamat'], null, 'data');
			$i++;
		  }
		}
		
	   $html_txt ="";	
	   $html_txt .= $tbl->display(); 	   
	   
	   return $html_txt;
	 
	 }
  
  
  }

?>