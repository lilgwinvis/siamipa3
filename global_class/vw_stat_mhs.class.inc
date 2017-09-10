<?php 
   require_once 'shared.php';
class vw_stat_mhs
{

  function __construct()
	{
	  
	}
	
  function sem_filter($thnsms='')
	{
	  $html = new html_element;
	  $mythnsem = new mythnsem;
	  $dtsem = $mythnsem->getlstthnsem();
	  
	  $thnsms = empty($thnsms) ? key($dtsem) : $thnsms;
	  
	  $vtemp = $dtsem[$thnsms];
	  
	  $user = $_SESSION['user'];
	  
		            
      $dtuser = new dt_user;
      $hak = $dtuser->gethak($user); 
	  
	  $frm = new HTML_Form();
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmfilter"));
	  $tbl->addRow();
      $tbl->addCell('Semester'.$frm->addSelectList("semester",$dtsem,true,intval($thnsms),null,array('id'=>'semester')).$frm->addInput('submit',"Filter","Filter",array('id'=>'filter')).$frm->addInput('submit',"ctkexcel","Cetak Ke Excel",array('id'=>'ctkexcel')), null, 'data');
	  
	  $frm = new HTML_Form();
	  $tbl1 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmAksi"));
	  $tbl1->addRow();
	  
	  $addattr = array();
	  $addattr['id']='Add';
	  
	  $editattr = array();
	  $editattr['id']='Edit';
	  
	  $delattr = array();
	  $delattr['id']='Del';
	  
	  $importattr = array();
	  $importattr['id']='Import';
	  
	  if($hak==0){
		 $addattr['disabled']='disabled';
         $editattr['disabled']='disabled';
         $delattr['disabled']='disabled';
         $importattr['disabled']='disabled';	 
	  }
	  
	  
	  $tbl1->addCell($frm->addInput('submit',"Add","Add",$addattr).$frm->addInput('submit',"Edit","Edit",$editattr).$frm->addInput('submit',"Delete","Delete",$delattr).$frm->addInput('submit',"Import","TA-1 -> TA",$importattr), null, 'data');
	  
	  $fieldset_aksi=$html->addfieldset('Aksi',$tbl1->display());
	  
	  $html_data="<div id='data'>";
	  $html_data.=$this->stat_mhs($thnsms);
	  $html_data.="</div>";
	  
	  $html_txt=$html->addfieldset('Filter',$tbl->display());
	  $html_txt.=$html->addfieldset('Status Mahasiswa : '.$vtemp,$fieldset_aksi.$html_data,array('id'=>'hsl_filter'));
	         	  
	  
	  return $html_txt;
	}	
	
	function stat_mhs($thnsms)
	{
	  $html = new html_element;
	  $mythnsem = new mythnsem;
	  $thnsms1=$mythnsem->substhnsem($thnsms,1);
	  
	  $tbstat = array("id" => "lst_stat");
	  $header = array(array('Angkatan','NIM','Nama','Kelas',$mythnsem->gettxtthnsem($thnsms1),$mythnsem->gettxtthnsem($thnsms)));
	  $data_table	= array();
		  	    
	  $tmp=$mythnsem->getlstthnsem('',$thnsms);
	  $tmp=implode(',', array_keys($tmp));
	  $txt_filter =rtrim($tmp, ',');	  
	  
	  $dt_mhs = new dt_mhs;  
	  $dt_stat_mhs = new dt_stat_mhs; 
	  
	  $data = $dt_mhs->getAllData("smawlmsmhs in ($txt_filter)");
	  
	  if(!empty($data))
	  {
        foreach($data as $row)
		{
		 $temp_data=array();
		 $temp_data[]=array($row["tahunmsmhs"],array());
		 $temp_data[]=array($row["nimhsmsmhs"],array());
	     $temp_data[]=array($row["nmmhsmsmhs"],array());		 
		 $temp_data[]=array($row["shiftmsmhs"]=="R" ? "Reguler" : "Non Reguler",array());		
		 $temp_data[]=array($dt_stat_mhs->getstatmhs($thnsms1,$row["nimhsmsmhs"]),array());
	     $temp_data[]=array($dt_stat_mhs->getstatmhs($thnsms,$row["nimhsmsmhs"]),array());
		 $data_table[]=$temp_data;
		}	  
	  }
	  
	 
	 $tbstat1 = array("id" => "lst_summary");
	 $header1 = array(array(
	 	                    array('Angkatan',array('rowspan'=>2)), 
	 	                    array('Kelas',array('rowspan'=>2)), 
	 	                    array('Aktif',array('colspan'=>2)),
	 	                    array('Cuti',array('colspan'=>2)),
	 	                    array('DO',array('colspan'=>2)),
	 	                    array('Keluar',array('colspan'=>2)),
	 	                    array('Lulus',array('colspan'=>2)),
	 	                    array('Non Aktif',array('colspan'=>2)), 
	 	                    array('Total',array('rowspan'=>2))
	 	                    ),
	 	              array('L','P','L','P','L','P','L','P','L','P','L','P'));
	 $data_table1 = array();	 
	 
	 $data = $dt_stat_mhs->getAngkatan($txt_filter);
	  
	  if(!empty($data))
	  {
        $jmltot = array('1'=>array('L'=>0,'P'=>0,'jml'=>0),
        	            '2'=>array('L'=>0,'P'=>0,'jml'=>0),
        	            '3'=>array('L'=>0,'P'=>0,'jml'=>0),
        	            '4'=>array('L'=>0,'P'=>0,'jml'=>0),
        	            '5'=>array('L'=>0,'P'=>0,'jml'=>0),
        	            '6'=>array('L'=>0,'P'=>0,'jml'=>0),
        	            'T'=>array('L'=>0,'P'=>0,'jml'=>0)
        	            );
		$kls = array('R','N');
		foreach($data as $row)
		{
		   
		   foreach($kls as $kls1)
		   {
			  $temp_data=array();
			  $temp_data[]=array($row['tahunmsmhs'],array());
			  $temp_data[]=array($kls1=='R' ? "Reguler" : "Non Reguler",array());
			  $jml=$dt_stat_mhs->getjmlmhs_jmlstat($thnsms,$row['tahunmsmhs'],$kls1);      
			  			  
			  array_walk($jmltot,function(&$value,$key) use (&$temp_data,$jml){
				  if($key!='T'){
                    $temp_data[]=array($tmp=$jml[$key]['L'],array());
                    $value['L']+=$tmp;  
                    $temp_data[]=array($tmp=$jml[$key]['P'],array());
                    $value['P']+=$tmp;
                    $tmp=$jml[$key]['jml'];
				  }else{
   			        $temp_data[]=array($tmp=$jml[$key]['jml'],array());
   			      }
				  
				  $value['jml']+=$tmp;
			  });
			  
			  $data_table1[]=$temp_data;
			}
		}
          $temp_data=array();   
          $temp_data[]=array('Jumlah',array());
		  $temp_data[]=array('',array());
		  
          array_walk($jmltot,function($value,$key) use (&$temp_data){
				 if($key!='T'){
                    $temp_data[]=array($value['L'],array());
                    $temp_data[]=array($value['P'],array());                    
				  }else{ 
				   $temp_data[]=array($value['jml'],array());
			      }
			  });
			  
          $data_table1[]=$temp_data;		  
	  }	
	 
	 $tbl = new mytable($tbstat,$header,$data_table,"");
	 $html_txt=$html->addfieldset('',$tbl->display());
	 $tbl1 = new mytable($tbstat1,$header1,$data_table1,"");
	 $html_txt.=$html->addfieldset('Summary',$tbl1->display());	 
	 
	 return $html_txt;
	}
	
	function frm_add($thnsms)
	{
	 $html = new html_element;
	 $frm = new HTML_Form(); 
	 
	 $tbstat = array("id" => "lst_stat");
	 $header = array(array('Angkatan','NIM','Nama','Status'));
	 $data_table	= array();
	 
	  $mythnsem = new mythnsem;
	  $tmp=$mythnsem->getlstthnsem('',$thnsms);
	  $tmp=implode(',', array_keys($tmp));
	  $txt_filter =rtrim($tmp, ',');	  
	
	  $dt_mhs = new dt_mhs;  
	 	  
	  $data = $dt_mhs->getAllData("smawlmsmhs in ($txt_filter) and nimhsmsmhs not in (select nimstat_mhs from stat_mhs where thnsmsstat_mhs=$thnsms)");
	  
	  if(!empty($data))
	  {
        foreach($data as $row)
		{
		 $temp_data=array();
		 $temp_data[]=array($row["tahunmsmhs"], null, 'data');		 
		 $temp_data[]=array($row["nimhsmsmhs"], null, 'data');
	     $temp_data[]=array($row["nmmhsmsmhs"], null, 'data');
		 $idx=$row["nimhsmsmhs"];
		 $temp_data[]=array($frm->addSelectList("stat[$idx]",array(1=>"Aktif",2=>"Cuti",3=>"DO",4=>"Keluar",5=>"Lulus",6=>"Non Aktif"),true,null,null,array('id'=>'stat')),array('align'=>'center'));
		 $data_table[]=$temp_data;
		}	  
	  }
	  
	 $tbl = new mytable($tbstat,$header,$data_table,"");
	 $html_txt=$html->addfieldset($mythnsem->gettxtthnsem($thnsms),$frm->startForm(null,'post','entrystatmhs').$tbl->display().$frm->endForm());
	 return $html_txt;
	}
	function frm_edit($thnsms)
	{
	 $html = new html_element;
	 $frm = new HTML_Form(); 
	 
	 
	 $tbstat = array("id" => "lst_stat");
	 $header = array(array('Angkatan','NIM','Nama','Status'));
	 $data_table	= array();    		
	 	 
	  $mythnsem = new mythnsem;
	  $tmp=$mythnsem->getlstthnsem('',$thnsms);
	  $tmp=implode(',', array_keys($tmp));
	  $txt_filter =rtrim($tmp, ',');
	    
	  $dt_mhs = new dt_mhs;  
	  $dt_stat_mhs = new dt_stat_mhs; 
	  
	  $data = $dt_mhs->getAllData("smawlmsmhs in ($txt_filter) and nimhsmsmhs in (select nimstat_mhs from stat_mhs where thnsmsstat_mhs=$thnsms)");
	  
	  if(!empty($data))
	  {
        foreach($data as $row)
		{
		 $temp_data=array();
		 $temp_data[]=array($row["tahunmsmhs"], array());
		 $temp_data[]=array($row["nimhsmsmhs"], array());
	     $temp_data[]=array($row["nmmhsmsmhs"], array());
		 $tmp=$dt_stat_mhs->getstatmhs($thnsms,$row["nimhsmsmhs"],-1);
		 $idx=$row["nimhsmsmhs"];
		 $temp_data[]=array($frm->addSelectList("stat[$idx]",array(1=>"Aktif",2=>"Cuti",3=>"DO",4=>"Keluar",5=>"Lulus",6=>"Non Aktif"),true,intval($tmp),null,array('id'=>'stat')),array('align'=>'center'));
		 $data_table[]=$temp_data;
		}	  
	  }
	  
	 
	 $tbl = new mytable($tbstat,$header,$data_table,"");
	 $html_txt=$html->addfieldset($mythnsem->gettxtthnsem($thnsms),$frm->startForm(null,'post','entrystatmhs').$tbl->display().$frm->endForm());
	 return $html_txt;
	}
	
	function frm_del($thnsms)
	{
	 $html = new html_element;
	 $frm = new HTML_Form(); 	 
	 
	 $tbstat = array("id" => "lst_stat");
	 $header = array(array('Angkatan','NIM','Nama','Status','Hapus'));
	 $data_table	= array();      		
	  
	  $mythnsem = new mythnsem;
	  $tmp=$mythnsem->getlstthnsem('',$thnsms);
	  $tmp=implode(',', array_keys($tmp));
	  $txt_filter =rtrim($tmp, ',');
	    
	  $dt_mhs = new dt_mhs;  
	  $dt_stat_mhs = new dt_stat_mhs; 
	  
	  $data = $dt_mhs->getAllData("smawlmsmhs in ($txt_filter) and nimhsmsmhs in (select nimstat_mhs from stat_mhs where thnsmsstat_mhs=$thnsms)");
	  
	  if(!empty($data))
	  {
        foreach($data as $row)
		{
		 $temp_data=array();
		 $temp_data[]=array($row["tahunmsmhs"],array());
		 $temp_data[]=array($row["nimhsmsmhs"],array());
	     $temp_data[]=array($row["nmmhsmsmhs"],array());
		 $tmp=$dt_stat_mhs->getstatmhs($thnsms,$row["nimhsmsmhs"]);
		 $temp_data[]=array($tmp,array());
		 $temp_data[]=array($frm->addInput('checkbox',"plh[]",$row["nimhsmsmhs"]), array('align'=>'center'));
		 $data_table[]=$temp_data;
		}	  
	  }
	  	 
	 $tbl = new mytable($tbstat,$header,$data_table,"");
	 $html_txt=$html->addfieldset($mythnsem->gettxtthnsem($thnsms),$frm->startForm(null,'post','entrystatmhs').$tbl->display().$frm->endForm());
	 return $html_txt;
	}
	
	function ctk_excel($thnsms)
	{
	 $dt_mhs = new dt_mhs;
	 $dt_stat_mhs = new dt_stat_mhs;
	 $mythnsem = new mythnsem;
	 
	  $tmp=$mythnsem->getlstthnsem('',$thnsms);
	  $tmp=implode(',', array_keys($tmp));
	  $txt_filter =rtrim($tmp, ',');
	  
	  $datalstmhs = $dt_mhs->getAllData("smawlmsmhs in ($txt_filter)");	  
	  $datasumstat = $dt_stat_mhs->getAngkatan($txt_filter);
	       
			$tmp="../Admin/cetak/stat_mhs/status mahasiswa ".$thnsms.".xls";
			$vwctkstat = new vw_ctkstat;
	        $vwctkstat->ctk_stat($datalstmhs,$datasumstat,$thnsms);
	        $vwctkstat->save($tmp);
			
			
			
			return $tmp;	
	}

} 