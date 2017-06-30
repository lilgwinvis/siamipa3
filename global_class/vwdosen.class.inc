<?php 
   require_once 'shared.php';

 class vwdosen
{
  
  var $vdb;
  
  function __construct()
  {
    $this->vdb = new dt_dosen;
  
  }
  
  function stat_dsn($stat)
  {
     if($stat=='LB'){
	   return "Dosen Luar Biasa";
	 }else{
	    if($stat=='DTT'){
	      return "Dosen Tidak Tetap";
	    }else{
	      if($stat=='DTY'){
	          return "Dosen Tetap Yayasan";
		  }else{
                 if($stat=='DTYLP'){
	                return "Dosen Tetap Yayasan Luar Prodi";
		         }			   
			   }		  
	    }
	 
	 }
  
  }
  
  function stat_sem($smawl)
  {
     if($smawl=='00000'){
	   return "Non Semester";
	 }else{
	    $tmp=str_split($smawl,4);
		if($tmp[1]==1){
	      return "Ganjil ".$tmp[0];
	    }else{	 
	      return "Genap ".$tmp[0];
	    }
	 
	 }
  
  }
  
  function viewdata()
  {
        $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_dsn","width"=>"100%"));
		$tbl->addRow();
        $tbl->addCell('Kode', null, 'header');	    	
		$tbl->addCell('Nama', null, 'header');
		$tbl->addCell('NIDN', null, 'header');	
		$tbl->addCell('NIDN EPSBED', null, 'header');
        $tbl->addCell('Status Dosen', null, 'header');
	    $tbl->addCell('Honor Ngajar', null, 'header');
		$tbl->addCell('Awal Ngajar', null, 'header');
	    
	    $data=$this->vdb->getAlldata("");
		
		if(!empty($data))
		{
		  foreach($data as $row)
		  {
		    $tbl->addRow();
            $tbl->addCell($row['Kode'], null, 'data');	        
			$tbl->addCell($row['Nama'], null, 'data');	
            $tbl->addCell($row['nidn'], null, 'data');  	
            $tbl->addCell($row['nidn_epsbed'], null, 'data'); 			
            $tbl->addCell($this->stat_dsn($row['Tstat']), null, 'data');
	        $tbl->addCell($this->stat_dsn($row['Hstat']), null, 'data');			 
			$tbl->addCell($this->stat_sem($row['smawl']), null, 'data');
		  }
		}
		
		     
					$txt = "<tr>";
					$txt = $txt."<th><input type='text' name='search_kode' value='Kode' class='search_init' style='width : 30px' /></th>";
					$txt = $txt."<th><input type='text' name='search_nm' value='Nama' class='search_init'/></th>";
					$txt = $txt."<th></th>";
					$txt = $txt."<th></th>";
					$txt = $txt."<th></th>";
					$txt = $txt."<th></th>";
					$txt = $txt."<th></th>";
					$txt = $txt."</tr>";
			  
	 
	 
	 return $tbl->display($txt);
  }


function viewprofile($kdds)
  {
  
          $vuser = new dt_dosen;
	      $data = $vuser->getData($kdds);
	 
	      foreach ($data as $vrow) {
                 $row = $vrow;
          } // foreach
		  
     	 $nama = $row['Nama'];
		 $frm = new HTML_Form();
		 
		 $vmythnsem = new mythnsem;
        $lst = $vmythnsem->getlstthnsem();
		   
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frm_profile_dsn","width"=>"100%"));
		$tbl->addRow();
		$tbl->addCell('Kode', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"Kode",$row['Kode'],array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Nama', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"nama",$nama), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Status Dosen', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		
		$tbl->addCell($frm->addSelectList("tstat",array('DTT'=>'DTT - Dosen Tidak Tetap','DTY'=>'DTY - Dosen Tetap Yayasan','DTYLP'=>'DTYLP - Dosen Tetap Yayasan Luar Prodi','LB'=>'LB - Dosen Luar Biasa'),true,$row['Tstat'],null,array('id'=>'tstat')), null, 'data');	
				
            $tbl->addRow();
		    $tbl->addCell('Honor Ngajar', null, 'data'); 
            $tbl->addCell(':', null, 'data');
		
		    $tbl->addCell($frm->addSelectList("hstat",array('DTT'=>'DTT - Dosen Tidak Tetap','DTY'=>'DTY - Dosen Tetap Yayasan','DTYLP'=>'DTYLP - Dosen Tetap Yayasan Luar Prodi','LB'=>'LB - Dosen Luar Biasa'),true,$row['Hstat'],null,array('id'=>'hstat')), null, 'data');				
			
		$tbl->addRow();
		$tbl->addCell('Awal Ngajar', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addSelectList('smawl',$lst,true,intval($row['smawl']),null,array('id'=>'smawl')), null, 'data');
		//$tbl->addCell($frm->addInput('text',"smawl",$row['smawl']), null, 'data');

        $tbl->addRow();
		$tbl->addCell('NIDN', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"nidn1",$row['nidn']), null, 'data');

        $tbl->addRow();
		$tbl->addCell('NIDN EPSBED', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"nidn2",$row['nidn_epsbed']), null, 'data');  			

        $tbl->addRow();
		$tbl->addCell('Link Forlap', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"link_forlap",$row['link_forlap'],array('style'=>'width:100%')), null, 'data'); 		
			     
	return $frm->startForm(null,'post','entrydsn').$tbl->display().$frm->endForm();		
  }
  
  function isiprofile()
  {
  
        $vmythnsem = new mythnsem;
        $lst = $vmythnsem->getlstthnsem();
      		
		$frm = new HTML_Form();
		 
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frm_profile_dsn","width"=>"100%"));
		$tbl->addRow();
		$tbl->addCell('Kode', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"Kode",''), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Nama', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"nama",''), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Status Dosen', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		
		$tbl->addCell($frm->addSelectList("tstat",array('DTT'=>'DTT - Dosen Tidak Tetap','DTY'=>'DTY - Dosen Tetap Yayasan','DTYLP'=>'DTYLP - Dosen Tetap Yayasan Luar Prodi','LB'=>'LB - Dosen Luar Biasa'),true,null,null,array('id'=>'tstat')), null, 'data');	
				
            $tbl->addRow();
		    $tbl->addCell('Honor Ngajar', null, 'data'); 
            $tbl->addCell(':', null, 'data');
		
		    $tbl->addCell($frm->addSelectList("hstat",array('DTT'=>'DTT - Dosen Tidak Tetap','DTY'=>'DTY - Dosen Tetap Yayasan','DTYLP'=>'DTYLP - Dosen Tetap Yayasan Luar Prodi','LB'=>'LB - Dosen Luar Biasa'),true,null,null,array('id'=>'hstat')), null, 'data');				
			
		$tbl->addRow();
		$tbl->addCell('Awal Ngajar', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addSelectList("smawl",$lst,true,null,null,array('id'=>'smawl')), null, 'data');
		//$tbl->addCell($frm->addInput('text',"smawl",''), null, 'data');	

        $tbl->addRow();
		$tbl->addCell('NIDN', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"nidn1",''), null, 'data');

        $tbl->addRow();
		$tbl->addCell('NIDN EPSBED', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"nidn2",''), null, 'data'); 

        $tbl->addRow();
		$tbl->addCell('Link Forlap', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"link_forlap",null,array('style'=>'width:100%')), null, 'data'); 		
			     
	return $frm->startForm(null,'post','entrydsn').$tbl->display().$frm->endForm();		
  }
  
  function delprofile()
  {
        $frm = new HTML_Form();
        $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_dsn","width"=>"100%"));
		$tbl->addRow();
        $tbl->addCell('Kode', null, 'header');
	    $tbl->addCell('Nama', null, 'header');
        $tbl->addCell('Pilih', null, 'header');
	    
	    
	    $data=$this->vdb->getAlldata("");
		
		if(!empty($data))
		{
		  foreach($data as $row)
		  {
		    $tbl->addRow();
            $tbl->addCell($row['Kode'], null, 'data');
	        $tbl->addCell($row['Nama'], null, 'data');
            $tbl->addCell($frm->addInput('checkbox',"plh[]",$row['Kode']), null, 'data');
		  }
		}						  
	 
	 
	 return $tbl->display();
  }
  
}
?>