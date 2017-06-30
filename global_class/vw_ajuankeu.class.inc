<?php
require_once 'shared.php';
class vw_ajuankeu {
    
	
	
	function __construct() {
		
	}
	function view_ajuan()
	{
		$user = $_SESSION['user'];
	    
		            
        $dtuser = new dt_user;
        $hak = $dtuser->gethak($user); 
		
		  $html = new html_element;
		  $frm = new HTML_Form();
		  $tbl1 = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "frmAksi"));
		  $tbl1->addRow();
		  
		  $addattr = array();
		  $addattr['id']='Add';
		  
		  $editattr = array();
		  $editattr['id']='Edit';
		  
		  $delattr = array();
		  $delattr['id']='Del';
		  
		  $ctkexcel = array();
		  $ctkexcel['id']='Ctkexcel';
		  
		  if($hak==0){
			 $addattr['disabled']='disabled';
			 $editattr['disabled']='disabled';
			 $delattr['disabled']='disabled';
			 $ctkexcel['disabled']='disabled';	 
		  }
		  
		  
		  $tbl1->addCell($frm->addInput('submit',"Add","Add",$addattr).$frm->addInput('submit',"Edit","Edit",$editattr).$frm->addInput('submit',"Delete","Delete",$delattr).$frm->addInput('submit',"Ctkexcel","Cetak to Excel",$ctkexcel), null, 'data');
		  
		  $fieldset_aksi=$html->addfieldset('Aksi',$tbl1->display());
		  
		  $html_data="<div id='data'>";
	      $html_data.=$this->lst_ajuan();
	      $html_data.="</div>";
		  
		  $html_txt=$fieldset_aksi;
	      $html_txt.=$html->addfieldset('List Ajuan',$html_data,array('id'=>'hsl_filter'));
		
		  return $html_txt;
	}
	
	function lst_ajuan()
	{
		
		$tbstat = array('id' => 'lst_ajuan','width'=>'100%');
	    $header = array(array('Tahun','Id Ajuan','No Ajuan','Perihal','Tanggal Ajuan','Tanggal Pencairan','Jumlah Ajuan','Jumlah Pencairan'));
	    $data_table	= array();
		
		$dtajuankeu = new dt_ajuankeu;
		$data=$dtajuankeu->getvwdtajuankeu('');
		
		if($dtajuankeu->numrows>0)
		{
			foreach($data as $row)
			{
				 $temp_data=array();
				 $temp_data[]=array($row["thn"],array());
				 $temp_data[]=array($row["idajuan"],array());
				 $temp_data[]=array($row["noajuan"],array());		 
				 $temp_data[]=array($row["perihalajuan"],array());		
				 $temp_data[]=array($row["tglajuan"],array());
				 $temp_data[]=array($row["tglcair"],array());
				 $temp_data[]=array(number_format($row["jmlajuan"], 2, ',', '.'),array('align'=>'right'));
				 $temp_data[]=array(number_format($row["jmlcair"], 2, ',', '.'),array('align'=>'right'));
				 $data_table[]=$temp_data;
			}
			
		}	
		
		
		$tbl = new mytable($tbstat,$header,$data_table,"");
		$html_txt=$tbl->display();
		return $html_txt;
	}
	
	
	function isiajuankeu()
	{
		$dt = new dt_ajuankeu;
		$dt_accoutlvl1=$dt->getaccoutlvl1();
		
		$frm = new HTML_Form();
		$tbstat = array('id' => 'form_ajuankeu');
		$data_table	= array();
		$data_table[]=array(array('Tanggal Ajuan',array()),array($frm->addInput('text',"tglajuan",'',array('id'=>'tglajuan')),array()));	
		$data_table[]=array(array('Nomor Ajuan',array()),array($frm->addInput('text',"noajuan",''),array()));
		$data_table[]=array(array('Perihal Ajuan',array()),array($frm->addInput('text',"perihalajuan",''),array()));
		$data_table[]=array(array('Jumlah Ajuan',array()),array($frm->addInput('text',"jmlajuan",''),array()));
		$data_table[]=array(array('Tanggal Pencairan',array()),array($frm->addInput('text',"tglcair",'',array('id'=>'tglcair')),array()));
		$data_table[]=array(array('Jumlah Pencairan',array()),array($frm->addInput('text',"jmlcair",''),array()));
		$data_table[]=array(array('Tanggal LPJ',array()),array($frm->addInput('text',"tgllpj",'',array('id'=>'tgllpj')),array()));
		$data_table[]=array(array('Sudah di Lpjkan',array()),array($frm->addInput('checkbox',"dilpjkan",1,array('id'=>'dilpjkan')),array()));
		$data_table[]=array(array('Sudah di bagikan',array()),array($frm->addInput('checkbox',"dibagikan",1,array('id'=>'dibagikan')),array()));
		$data_table[]=array(array('Jenis Pengeluaran',array()),array($frm->addSelectList('accoutlvl1',$dt_accoutlvl1,true,null,'',array('id'=>'accoutlvl1')),array()));
		
		$tbl = new mytable($tbstat,null,$data_table,"");		
		return $frm->startForm(null,'post','entryajuankeu').$tbl->display().$frm->endForm();
	}
	
	function viewajuankeu($idajuan)
	{
		$dt = new dt_ajuankeu;
		$dt_accoutlvl1=$dt->getaccoutlvl1();
				
		$ajuankeu = new dt_ajuankeu;
	    $data = $ajuankeu->getData("idajuan=$idajuan");
	 
	      foreach ($data as $vrow) {
                 $row = $vrow;
          } // foreach
		
		$frm = new HTML_Form();
		$tbstat = array('id' => 'form_ajuankeu');
		$data_table	= array();
		$data_table[]=array(array('Id Ajuan',array()),array($frm->addInput('text',"idajuan",$row['idajuan'],array('id'=>'idajuan','readonly'=>'true')),array()));
		$data_table[]=array(array('Tanggal Ajuan',array()),array($frm->addInput('text',"tglajuan",$row['tglajuan'],array('id'=>'tglajuan')),array()));	
		$data_table[]=array(array('Nomor Ajuan',array()),array($frm->addInput('text',"noajuan",$row['noajuan']),array()));
		$data_table[]=array(array('Perihal Ajuan',array()),array($frm->addInput('text',"perihalajuan",$row['perihalajuan']),array()));
		$data_table[]=array(array('Jumlah Ajuan',array()),array($frm->addInput('text',"jmlajuan",$row['jmlajuan']),array()));
		$data_table[]=array(array('Tanggal Pencairan',array()),array($frm->addInput('text',"tglcair",$row['tglcair'],array('id'=>'tglcair')),array()));
		$data_table[]=array(array('Jumlah Pencairan',array()),array($frm->addInput('text',"jmlcair",$row['jmlcair']),array()));
		$data_table[]=array(array('Tanggal LPJ',array()),array($frm->addInput('text',"tgllpj",$row['tgllpj'],array('id'=>'tgllpj')),array()));
		
		if($row['dilpjkan']==1){
		   $data_table[]=array(array('Sudah di Lpjkan',array()),array($frm->addInput('checkbox',"dilpjkan",1,array('checked'=>'checked','id'=>'dilpjkan')),array()));
		}else{
		   $data_table[]=array(array('Sudah di Lpjkan',array()),array($frm->addInput('checkbox',"dilpjkan",1,array('id'=>'dilpjkan')),array()));  	
		}
		if($row['dibagikan']==1){
		   $data_table[]=array(array('Sudah di bagikan',array()),array($frm->addInput('checkbox',"dibagikan",1,array('checked'=>'checked','id'=>'dibagikan')),array()));
		}else{
		   $data_table[]=array(array('Sudah di bagikan',array()),array($frm->addInput('checkbox',"dibagikan",1,array('id'=>'dibagikan')),array()));
		}
		
		$data_table[]=array(array('Jenis Pengeluaran',array()),array($frm->addSelectList('accoutlvl1',$dt_accoutlvl1,true,intval($row['accoutlvl1']),'',array('id'=>'accoutlvl1')),array()));

		
		$tbl = new mytable($tbstat,null,$data_table,"");		
		return $frm->startForm(null,'post','entryajuankeu').$tbl->display().$frm->endForm();
	}
	function delajuankeu()
	{
		
	}
}
?>