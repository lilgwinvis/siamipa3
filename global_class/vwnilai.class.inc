<?php 
   require_once 'shared.php';
   
class vwnilai
{ 
   var $vdb;
   function __construct()
	{
	  $this->vdb = new dt_nilai;
	}
	
	function viewdata($idx=1)
	{   
	       
    	
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "lst_mtk","Width"=>"100%"));
		$tbl->addRow();
        $tbl->addCell('TA', null, 'header');
		$tbl->addCell('Kode', null, 'header');
		$tbl->addCell('Matakuliah', null, 'header');
		$tbl->addCell('Semester', null, 'header');
		$tbl->addCell('Kelas', null, 'header');
		$tbl->addCell('Dosen', null, 'header');
		$tbl->addCell('Status', null, 'header');
	    
        if($idx==1){		
			$data = $this->vdb->getData("");
			
			if(!empty($data))
			{
			
			 foreach($data as $row)
			  {
				  $tbl->addRow();
				   $tbl->addCell($row['thsmstrnlm'], null, 'data');
				  $tbl->addCell($row['kdkmktrnlm'], null, 'data');
				  $tbl->addCell($row['nakmktbkmk'], null, 'data');
				  $tbl->addCell($row['semestrnlm'] , null, 'data');
				  $tbl->addCell($row['kelastrnlm'] , null, 'data');
				  $tbl->addCell($row['nama'] , null, 'data');
				  $tbl->addCell($row['jml'] > 0 ? "<font color='red'><i>Sudah Ada Nilai</i></font>":'-' , null, 'data');
				  
				  
			 }
			
			}
		}	
		
		return $tbl->display();
	}
	
	
	function ss_viewdata($param)
	{
		
				
		$data = $this->vdb->getData("");
		$totalrecords = $this->vdb->getnumrows();		
		$totaldisplayrecords=$totalrecords;
		
		$cari=$param['sSearch'];
		
		if($cari==''){
		 $this->vdb->setpageno(((intval($param['iDisplayStart']))/intval($param['iDisplayLength']))+1);
		 $this->vdb->setrows_per_page(intval($param['iDisplayLength']));
		 $data = $this->vdb->getData('');
		}
		
		$output = array(
			"sEcho" => intval($param['sEcho']),
			"iTotalRecords" => $totalrecords,
			"iTotalDisplayRecords" => $totaldisplayrecords,
			"aaData" => array()
		);
	    
		if(!empty($data)){
			
			$jml_data=0;
			$display_data=0;
			$jml_filter=0;
			
			$is_included = function ($arr,$cari){
				$tmp = array_filter($arr,function($val) use ($cari) {
						  return preg_match("/".$cari."/i",$val);
					    });
				return !empty($tmp);		
			};
			
			$add_data = function($param,&$data_arr,$tmp_row,$jml_data,&$display_data,&$jml_filter,$cari,$is_masuk){
				
				$jml_filter+= ($is_masuk) ? 1 : 0;					
					
					if(($display_data<$param['iDisplayLength']) and ((($cari == "") ? $jml_data :$jml_filter-1 )>=$param['iDisplayStart'])){ 
						 
						 if(($cari == "") or $is_masuk){  
						   $data_arr[] = $tmp_row;
						   $display_data++;
						 }
					}				
				
				return 1;
			};
			
			foreach($data as $row)
			{
				$tmp_row = array();
				$tmp_row[] = $row['thsmstrnlm'];
				$tmp_row[] = $row['kdkmktrnlm'];
				$tmp_row[] = $row['nakmktbkmk'];
				$tmp_row[] = $row['semestrnlm'];
				$tmp_row[] = $row['kelastrnlm'];
				$tmp_row[] = $row['nama'];
				$tmp_row[] = $row['jml'] > 0 ? "<font color='red'><i>Sudah Ada Nilai</i></font>":'-';
				
				if($cari==''){
				 $output['aaData'][] = $tmp_row;
				}else{
					$jml_data+=$add_data($param,$output['aaData'],$tmp_row,$jml_data,$display_data,$jml_filter,$cari,$is_included($tmp_row,$cari));
				} 
			}
			
			if($cari!=''){
				   $output['iTotalDisplayRecords']=$jml_filter;
			   }
		}
		
		return $output;
	}
	
}
?>