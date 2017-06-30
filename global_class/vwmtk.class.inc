<?php
   require_once 'shared.php';
class vwmtk
{ 
    var $vdb;
	var $vdbsyarat;
	var $vdbdosen;
	
    function __construct()
	{
	   $this->vdb = new dt_mtk;
	   $this->vdbsyarat = new dt_syarat;
	   $this->vdbdosen = new dt_dosen;
	}
	
	private function ismrhitl($iswp,$data)
	{
	   if($iswp=='p'){
	      return "<font color='red'><i>".$data."</i></font>";
	   }else{
	      return "$data";
	   }
	}
	
    function viewdata()
	{
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_mtk","width"=>"100%"));
		$tbl->addRow();
        $tbl->addCell('Semester', null, 'header');
		$tbl->addCell('Kode', null, 'header');
	    $tbl->addCell('Nama', null, 'header');
        $tbl->addCell('sks', null, 'header');
		$tbl->addCell('Pengampu', null, 'header');
		$tbl->addCell('Prasyarat', null, 'header');	
		
		$data=$this->vdb->getData("");
		
		if(!empty($data))
		{
		  foreach($data as $row)
		  {
		    $tbl->addRow(); 
            $tbl->addCell($row['semestbkmk'], null, 'data');
	        $tbl->addCell($this->ismrhitl($row['wp'],$row['kdkmktbkmk']), null, 'data');
            $tbl->addCell($this->ismrhitl($row['wp'],$row['nakmktbkmk']), null, 'data');
	        $tbl->addCell($this->ismrhitl($row['wp'],floor($row['sksmktbkmk']).'  ('.$row['skstmtbkmk'].'-'.$row['sksprtbkmk'].')'), null, 'data');
            
            $tmp_nm='';
			if($row['nodostbkmk']!=""){
			  $tmp_nm=$this->vdbdosen->getnmdsn($row['nodostbkmk']); 
			}
			$tbl->addCell($tmp_nm, null, 'data');
			
			$kd=$row['kdkmktbkmk'];
			$dt_syarat=$this->vdbsyarat->getData("kdkmksyarat='$kd'");
			
			$txt='';
			if(!empty($dt_syarat))
			{
			   foreach($dt_syarat as $dt)
			   {
			     $txt.=$dt['syaratkmk'].',';			   
			   }			
			}
			$txt  = rtrim($txt, ',');
			$tbl->addCell($txt, null, 'data');	        			
		  }
		}
		
		
		$txt = "<tr>";
	    $txt = $txt."<th></th>";
		$txt = $txt."<th><input type='hidden' name='search_sem' value='Search sem' class='search_init' /><input type='text' name='search_kode' value='Kode' class='search_init' style='width:30px' /></th>";
	    $txt = $txt."<th><input type='text' name='search_nm' value='Nama' class='search_init' style='width:150px'/></th>";
	    $txt = $txt."<th></th>";
		$txt = $txt."<th></th>";
		$txt = $txt."<th></th>";
	    $txt = $txt."</tr>";
		
		return $tbl->display($txt);
	}
	
	function viewmtk($kdmtk)
  {
  
          
	      $data=$this->vdb->getData("kdkmktbkmk = '$kdmtk'");
	 
	      foreach ($data as $vrow) {
                 $row = $vrow;
          } // foreach
		  
     	 $nama = str_replace(' ', '&nbsp;',$row['nakmktbkmk']);
		 $frm = new HTML_Form();
		 
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frm_mtk","width"=>"100%"));
		$tbl->addRow();
		$tbl->addCell('Kode', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"kdkmk",$row['kdkmktbkmk'],array('readonly'=>'readonly','onfocus'=>'blur();')), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Nama', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"nama",$nama), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('SKS Tatap Muka', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"skstmtbkmk",$row['skstmtbkmk']), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('SKS Praktikum', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"sksprtbkmk",$row['sksprtbkmk']), null, 'data');
		
        $tbl->addRow();
		$tbl->addCell('SKS Lapangan', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"skslptbkmk",$row['skslptbkmk']), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Semester', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addSelectList("sem",array('01'=>'01','02'=>'02','03'=>'03','03'=>'03','04'=>'04','05'=>'05','06'=>'06','07'=>'07','08'=>'08'),true,$row['semestbkmk'],null,array('id'=>'sem')), null, 'data');

        $tbl->addRow();
		$tbl->addCell('Wajib/Pilihan', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addSelectList("wp",array('w'=>'Wajib','p'=>'Pilihan'),true,$row['wp'],null,array('id'=>'wp')), null, 'data'); 		
				
        $tbl->addRow();
		$tbl->addCell('Kode Praktikum', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		
		$data=$this->vdb->getData("kdkmktbkmk like 'MATP%'");
		
		$kdprtk['']='Tidak ada praktikum';
		if(!empty($data))
		{
		  foreach($data as $row1)
		  {
	        $kd=$row1['kdkmktbkmk'];
			$nama = str_replace(' ', '&nbsp;',$row1['nakmktbkmk']);	  
		    $kdprtk[$kd]=$nama;
		  
		  }
		
		}
		
		$tbl->addCell($frm->addSelectList("kdprtk",$kdprtk,true,$row['kdprtk'],null,array('id'=>'kdprtk')), null, 'data');     
		
		
		$tbl->addRow();
		$tbl->addCell('Dosen Pengampu', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		
		$data=$this->vdbdosen->getAllData("nidn<>'' and kode<>'?????' ");
		
		$kddsn['']='Tidak Ditentukan';
		if(!empty($data))
		{
		  foreach($data as $row1)
		  {
	        $kd=$row1['nidn'];
			$nama = str_replace(' ', '&nbsp;',$row1['Nama']);	  
		    $kddsn[$kd]=$nama;
		  
		  }
		
		}
		
         $tbl->addCell($frm->addSelectList("kddsn",$kddsn,true,$row['nodostbkmk'],null,array('id'=>'kddsn')), null, 'data'); 
			
			         
			     
	return $frm->startForm(null,'post','entrymtk').$tbl->display().$frm->endForm();		
  }
  
  function isimtk()
  {
  
		 $frm = new HTML_Form();
		 
		$tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frm_mtk","width"=>"100%"));
		$tbl->addRow();
		$tbl->addCell('Kode', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"kdkmk",null,null), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Nama', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"nama",null), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('SKS Tatap Muka', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"skstmtbkmk",0), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('SKS Praktikum', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"sksprtbkmk",0), null, 'data');
		
        $tbl->addRow();
		$tbl->addCell('SKS Lapangan', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addInput('text',"skslptbkmk",0), null, 'data');
		
		$tbl->addRow();
		$tbl->addCell('Semester', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addSelectList("sem",array('01'=>'01','02'=>'02','03'=>'03','03'=>'03','04'=>'04','05'=>'05','06'=>'06','07'=>'07','08'=>'08'),true,null,null,array('id'=>'sem')), null, 'data');

        $tbl->addRow();
		$tbl->addCell('Wajib/Pilihan', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		$tbl->addCell($frm->addSelectList("wp",array('w'=>'Wajib','p'=>'Pilihan'),true,null,null,array('id'=>'wp')), null, 'data'); 		
				
        $tbl->addRow();
		$tbl->addCell('Kode Praktikum', null, 'data'); 
        $tbl->addCell(':', null, 'data');
		
		$data=$this->vdb->getData("kdkmktbkmk like 'MATP%'");
		
		$kdprtk['']='Tidak ada praktikum';
		if(!empty($data))
		{
		  foreach($data as $row1)
		  {
	        $kd=$row1['kdkmktbkmk'];
			$nama = str_replace(' ', '&nbsp;',$row1['nakmktbkmk']);	  
		    $kdprtk[$kd]=$nama;
		  
		  }
		
		}
		
		$tbl->addCell($frm->addSelectList("kdprtk",$kdprtk,true,null,null,array('id'=>'kdprtk')), null, 'data');     
		
		$tbl->addRow();
		$tbl->addCell('Dosen Pengampu', null, 'data'); 
        $tbl->addCell(':', null, 'data');
        

		$data=$this->vdbdosen->getAllData("nidn<>'' and kode<>'?????' ");
		
		$kddsn['']='Tidak Ditentukan';
		if(!empty($data))
		{
		  foreach($data as $row1)
		  {
	        $kd=$row1['nidn'];
			$nama = str_replace(' ', '&nbsp;',$row1['Nama']);	  
		    $kddsn[$kd]=$nama;
		  
		  }
		
		}
		
         $tbl->addCell($frm->addSelectList("kddsn",$kddsn,true,null,null,array('id'=>'kddsn')), null, 'data'); 		
			         
			     
	return $frm->startForm(null,'post','entrymtk').$tbl->display().$frm->endForm();		
  }
  
  function delmtk($idx=3,$kdkmk=null)
  {
        $frm = new HTML_Form();
        $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_mtk","width"=>"100%"));
		$tbl->addRow();
        $tbl->addCell('Semester', null, 'header');
		$tbl->addCell('Kode', null, 'header');
	    $tbl->addCell('Nama', null, 'header');
        $tbl->addCell('Pilih', null, 'header');
	    
	    
	    if($idx==4)
		{
		 $data=$this->vdb->getdata("kdkmktbkmk not like 'MATP%' and kdkmktbkmk not in ('UBB106','MAT370','MAT352','MAT353')");
		}
	    else
        {		
    		$data=$this->vdb->getdata("");
		}
		
		if(!empty($data))
		{
		  foreach($data as $row)
		  {
		    $tbl->addRow();
			$tbl->addCell($row['semestbkmk'], null, 'data');
            $tbl->addCell($this->ismrhitl($row['wp'],$row['kdkmktbkmk']), null, 'data');
			$nama = str_replace(' ', '&nbsp;',$row['nakmktbkmk']);
	        $tbl->addCell($this->ismrhitl($row['wp'],$nama), null, 'data');
            
			if($idx==4)
			{
			  
			  $kd=$row['kdkmktbkmk'];
			  $dt_syarat=$this->vdbsyarat->getData("kdkmksyarat='$kdkmk' and syaratkmk='$kd'");
			  
			  if(!empty($dt_syarat)){
			     $tbl->addCell($frm->addInput('checkbox',"plh[]",$row['kdkmktbkmk'],array('checked'=>'checked')), null, 'data');
			  }else{
			    $tbl->addCell($frm->addInput('checkbox',"plh[]",$row['kdkmktbkmk']), null, 'data');
			  }
			  
            }else{
              $tbl->addCell($frm->addInput('checkbox',"plh[]",$row['kdkmktbkmk']), null, 'data');
			}  
		  }
		}						  
	 
	 
	 return $frm->startForm(null,'post','entrymtk').$tbl->display().$frm->endForm();
  }
	
}

?>