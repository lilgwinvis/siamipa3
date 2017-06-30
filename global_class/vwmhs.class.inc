<?php 
   require_once 'shared.php';
class vwmhs
{ 
   var $vdb;
   function __construct()
	{
	  $this->vdb = new dt_mhs;
	}
	
	function viewdata()
	{   
	
	     
        $agama = array(0 => "Islam",1 => "Kristen Protestan", 2 =>"Kristen Katolik",3 => "Hindu", 4 => "Budha");
    	
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_mhs","Width"=>"100%"));
		$tbl->addRow();
        $tbl->addCell('tahunmsmhs', null, 'header');
		$tbl->addCell('NIM', null, 'header');
		$tbl->addCell('Nama', null, 'header');
	    $tbl->addCell('Alamat', null, 'header');
		$tbl->addCell('Nomor Telpon', null, 'header');
	    $tbl->addCell('e-mail', null, 'header');
		$tbl->addCell('Agama', null, 'header');
		$tbl->addCell('Status', null, 'header');
		$tbl->addCell('Pendidikan Terakhir', null, 'header');
        $tbl->addCell('Tempat Lahir', null, 'header');		
		$tbl->addCell('Tanggal Lahir', null, 'header');	
		$tbl->addCell('Jenis Kelamin', null, 'header');
        $tbl->addCell('Kelas', null, 'header');		
		$tbl->addCell('Baru/Pindahan', null, 'header');	
		$tbl->addCell('Awal Masuk', null, 'header');	
		$tbl->addCell('Link', null, 'header');
		
		$data = $this->vdb->getAllData(null);
		
		if(!empty($data))
		{
		
		  foreach($data as $row)
		  {
		      $tbl->addRow();
			  $tbl->addCell($row['tahunmsmhs'], null, 'data');
			  $tbl->addCell($row['nimhsmsmhs'], null, 'data');
			  $tbl->addCell($row['nmmhsmsmhs'], null, 'data');
			  $tbl->addCell($row['almmsmhs'], null, 'data');
			  $tbl->addCell($row['tlpmsmhs'], null, 'data');
			  $tbl->addCell($row['emailmsmhs'], null, 'data');
			  $tbl->addCell($agama[$row['agamamsmhs']], null, 'data');
			  $tbl->addCell($row['statmsmhs']==0 ? "Lajang":"Menikah", null, 'data');
		      $tbl->addCell($row['smamsmhs'], null, 'data');			  
		      $tbl->addCell($row['tplhrmsmhs'], null, 'data');
			  $tbl->addCell($row['tglhrmsmhs'], null, 'data');
			  $tbl->addCell($row['kdjekmsmhs']=='P' ? 'Perempuan' : 'Laki-Laki', null, 'data');
			  
			  $sem = str_split($row['smawlmsmhs'], 4);
			  
			  if($sem[1]==1)
			  {
			    $tmp='Ganjil '.$sem[0];
			  }else
			  {
			    $tmp='Genap '.$sem[0];
			  }
			  $tbl->addCell($row['shiftmsmhs']=='R' ? 'Reguler' : 'Non Reguler' , null, 'data');
			  $tbl->addCell($row['bpmsmhs']==0 ? 'Baru' : 'Pindahan' , null, 'data');
			  $tbl->addCell($tmp, null, 'data');
			  $tbl->addCell($row['link_forlap'], null, 'data');
		  }
		
		}
		
		            $txt = "<tr>";
					$txt = $txt."<th></th>";
					$txt = $txt."<th></th>";
					$txt = $txt."<th><input type='hidden' name='search_angkatan' value='Search angkatan' class='search_init' /><input type='hidden' name='search_detail' value='Search angkatan' class='search_init' /><input type='text' name='search_nim' value='NIM' class='search_init' style='width:45px' /></th>";
					$txt = $txt."<th><input type='text' name='search_nm' value='Nama' class='search_init' style='width:140px'/></th>";
					$txt = $txt."<th></th>";
					$txt = $txt."<th></th>";
					$txt = $txt."<th></th>";
					$txt = $txt."<th></th>";
					$txt = $txt."<th></th>";
					$txt = $txt."<th></th>";
					$txt = $txt."<th></th>";
					$txt = $txt."<th></th>";
					$txt = $txt."<th></th>";
					$txt = $txt."<th></th>";
					$txt = $txt."<th></th>";
					$txt = $txt."<th></th>";					
					$txt = $txt."</tr>";
		
		return $tbl->display($txt);
	}
	function viewprofile($nim,$admin=1)
  {
  
          $vuser = new dt_mhs;
	      $data = $vuser->getData($nim);
	 
	      foreach ($data as $vrow) {
                 $row = $vrow;
          } // foreach
		  
     	 $nama = $row['nmmhsmsmhs'];
		 $frm = new HTML_Form();
		 
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frm_profile_dsn","width"=>"100%"));
		$tbl->addRow();
		$tbl->addCell('NIM', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"NIM",$row['nimhsmsmhs'],array('readonly'=>'readonly','disabled'=>'disabled')).$frm->addInput('hidden',"NIM",$row['nimhsmsmhs'],null), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Nama', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"nama",$nama), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Alamat', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"alamat",$row['almmsmhs'],array('style'=>'width:100%')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Nomor Telpon', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"tlp",$row['tlpmsmhs']), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('e-mail', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"email",$row['emailmsmhs']), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Agama', null, 'data'); 
        $tbl->addCell(':', null, 'data');		
		$tbl->addCell($frm->addSelectList("agama",array('0'=>'Islam','1'=>'Kristen Protestan','2'=>'Kristen Katolik','3'=>'Hindu','4'=>'Budha'),true,intval($row['agamamsmhs']),null,array('id'=>'agama')), null, 'data');	
		
		$tbl->addRow();
		$tbl->addCell('Status Pernikahan', null, 'data'); 
        $tbl->addCell(':', null, 'data');		
		$tbl->addCell($frm->addSelectList("status",array('0'=>'Lajang','1'=>'Menikah'),true,intval($row['statmsmhs']),null,array('id'=>'status')), null, 'data');				
		
		$tbl->addRow();
		$tbl->addCell('Pendidikan Terakhir', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"penddk",$row['smamsmhs'],array('style'=>'width:100%')), null, 'data');
		
        $tbl->addRow();
		$tbl->addCell('TTL', null, 'data'); 
        $tbl->addCell(':', null, 'data');
        $tbl->addCell($frm->addInput('text',"tempat",$row['tplhrmsmhs']).','.$frm->addInput('text',"datepicker",null,array('id'=>'datepicker')), null, 'data');
		
		    $tbl->addRow();
		    $tbl->addCell('Baru/Pindahan', null, 'data'); 
            $tbl->addCell(':', null, 'data');		
		    
			if($admin==0)
			{
			 $tbl->addCell($frm->addSelectList("bp",array('0'=>'Baru','1'=>'Pindahan'),true,intval($row['bpmsmhs']),null,array('id'=>'bp','disabled'=>'disabled')).$frm->addInput('hidden',"bp",$row['bpmsmhs'],null), null, 'data');
			}
			else
			{
			 $tbl->addCell($frm->addSelectList("bp",array('0'=>'Baru','1'=>'Pindahan'),true,intval($row['bpmsmhs']),null,array('id'=>'bp')), null, 'data');
            } 
			$tbl->addRow();
		    $tbl->addCell('Jenis Kelamin', null, 'data'); 
            $tbl->addCell(':', null, 'data');		
		    $tbl->addCell($frm->addSelectList("kelamin",array('L'=>'L - Laki-Laki','P'=>'P - Perempuan'),true,$row['kdjekmsmhs'],null,array('id'=>'kelamin')), null, 'data');				
		
		$tbl->addRow();
		$tbl->addCell('Kelas', null, 'data'); 
        $tbl->addCell(':', null, 'data');		
		
		 if($admin==0){
		  $tbl->addCell($frm->addSelectList("kelas",array('R'=>'R - Reguler','N'=>'N - Non Reguler'),true,$row['shiftmsmhs'],null,array('id'=>'kelas','disabled'=>'disabled')).$frm->addInput('hidden',"kelas",$row['shiftmsmhs'],null), null, 'data');	
		 }
		else
		{
    		$tbl->addCell($frm->addSelectList("kelas",array('R'=>'R - Reguler','N'=>'N - Non Reguler'),true,$row['shiftmsmhs'],null,array('id'=>'kelas')), null, 'data');	
	    }	
		
        $tbl->addRow();
		$tbl->addCell('Tahun Masuk', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		
		if($admin==0){
		  $tbl->addCell($frm->addInput('text',"thnmsk",$row['tahunmsmhs'],array('readonly'=>'readonly','disabled'=>'disabled')).$frm->addInput('hidden',"thnmsk",$row['tahunmsmhs'],null), null, 'data');		
		}
		else
		{
		  $tbl->addCell($frm->addInput('text',"thnmsk",$row['tahunmsmhs']), null, 'data');	
		}
		
		
		$sem = str_split($row['smawlmsmhs'], 4);
		
		    $tbl->addRow();
		    $tbl->addCell('Masuk di Semester', null, 'data'); 
            $tbl->addCell(':', null, 'data');		
		    
			if($admin==0){
			 $tbl->addCell($frm->addSelectList("sem",array('1'=>'Ganjil','2'=>'Genap'),true,intval($sem[1]),null,array('id'=>'sem','disabled'=>'disabled')).$frm->addInput('hidden',"sem",$sem[1],null), null, 'data');				
			}
		    else
		    {
			$tbl->addCell($frm->addSelectList("sem",array('1'=>'Ganjil','2'=>'Genap'),true,intval($sem[1]),null,array('id'=>'sem')), null, 'data');				
		    }
		
		    if($admin==1){
			 $tbl->addRow();
		     $tbl->addCell('Link Forlap', null, 'data'); 
             $tbl->addCell(':', null, 'data');
		     $tbl->addCell($frm->addInput('text',"link_forlap",$row['link_forlap'],array('style'=>'width:100%')), null, 'data');
			
			}
			     
	return $frm->startForm(null,'post','entrymhs').$tbl->display().$frm->endForm();		
  }
  
  function isiprofile()
  {
  
          $frm = new HTML_Form();
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frm_profile_dsn","width"=>"100%"));
		$tbl->addRow();
		$tbl->addCell('NIM', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"NIM",null), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Nama', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"nama",null), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Alamat', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"alamat",null,array('style'=>'width:100%')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Nomor Telpon', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"tlp",null), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('e-mail', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"email",null), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Agama', null, 'data'); 
        $tbl->addCell(':', null, 'data');		
		$tbl->addCell($frm->addSelectList("agama",array('0'=>'Islam','1'=>'Kristen Protestan','2'=>'Kristen Katolik','3'=>'Hindu','4'=>'Budha'),true,null,null,array('id'=>'agama')), null, 'data');				
		
		$tbl->addRow();
		$tbl->addCell('Status Pernikahan', null, 'data'); 
        $tbl->addCell(':', null, 'data');		
		$tbl->addCell($frm->addSelectList("status",array('0'=>'Lajang','1'=>'Menikah'),true,null,null,array('id'=>'status')), null, 'data');				
		
		$tbl->addRow();
		$tbl->addCell('Pendidikan Terakhir', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"penddk",null,array('style'=>'width:100%')), null, 'data');
		
        $tbl->addRow();
		$tbl->addCell('TTL', null, 'data'); 
        $tbl->addCell(':', null, 'data');
        $tbl->addCell($frm->addInput('text',"tempat",null).','.$frm->addInput('text',"datepicker",null,array('id'=>'datepicker')), null, 'data');
		    
			$tbl->addRow();
		    $tbl->addCell('Baru/Pindahan', null, 'data'); 
            $tbl->addCell(':', null, 'data');		
		    $tbl->addCell($frm->addSelectList("bp",array('0'=>'Baru','1'=>'Pindahan'),true,null,null,array('id'=>'bp')), null, 'data');
            
		
            $tbl->addRow();
		    $tbl->addCell('Jenis Kelamin', null, 'data'); 
            $tbl->addCell(':', null, 'data');		
		    $tbl->addCell($frm->addSelectList("kelamin",array('L'=>'L - Laki-Laki','P'=>'P - Perempuan'),true,null,null,array('id'=>'kelamin')), null, 'data');				
		
		
		$tbl->addRow();
		$tbl->addCell('Kelas', null, 'data'); 
        $tbl->addCell(':', null, 'data');		
		$tbl->addCell($frm->addSelectList("kelas",array('R'=>'R - Reguler','N'=>'N - Non Reguler'),true,null,null,array('id'=>'kelas')), null, 'data');	
		
        $tbl->addRow();
		$tbl->addCell('Tahun Masuk', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"thnmsk",null), null, 'data');		
		
		
		
		    $tbl->addRow();
		    $tbl->addCell('Masuk di Semester', null, 'data'); 
            $tbl->addCell(':', null, 'data');		
		    $tbl->addCell($frm->addSelectList("sem",array('1'=>'Ganjil','2'=>'Genap'),true,null,null,array('id'=>'sem')), null, 'data');				
		
		$tbl->addRow();
		$tbl->addCell('Link Forlap', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"link_forlap",null,array('style'=>'width:100%')), null, 'data');
		
			     
	return $frm->startForm(null,'post','entrymhs').$tbl->display().$frm->endForm();			
  }
  
  function delprofile()
  {
        $frm = new HTML_Form();
        $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_mhs","width"=>"100%"));
		$tbl->addRow();
        $tbl->addCell('NIM', null, 'header');
	    $tbl->addCell('Nama', null, 'header');
        $tbl->addCell('Pilih', null, 'header');
	    
	    
	    $data=$this->vdb->getData("");
		
		if(!empty($data))
		{
		  foreach($data as $row)
		  {
		    $tbl->addRow();
            $tbl->addCell($row['nimhsmsmhs'], null, 'data');
	        $tbl->addCell($row['nmmhsmsmhs'], null, 'data');
            $tbl->addCell($frm->addInput('checkbox',"plh[]",$row['nimhsmsmhs']), null, 'data');
		  }
		}						  
	 
	 
	 return $tbl->display();
  }
  function detail($nim)
  {
    $sOut ='hasil1';
	return $sOut;
  }
}
?>