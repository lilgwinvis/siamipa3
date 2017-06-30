<?php
require_once 'shared.php';
class vwcetak
{   var $dtcetak;
	function __construct()
	{
	  	$this->dtcetak = new dt_cetak; 
	}
	
	function build_cetak_klh()
	{
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "box-table-a","width"=>"100%"));
		$tbl->addRow();
        $tbl->addCell('Sem', null, 'header');
	    $tbl->addCell('Kelas', null, 'header');	   
		$tbl->addCell('Kode Matakuliah', null, 'header');
	    $tbl->addCell('Nama Matakuliah', null, 'header');	    
        $tbl->addCell('Kode Dosen', null, 'header');
	    $tbl->addCell('Nama Dosen', null, 'header');
	    
	       
		$data = $this->dtcetak->get_dt_jdwl_klh(); 
		 if(!empty($data))
      {	 
		foreach($data as $row)
		{
		  $tbl->addRow();        
		  $tbl->addCell($row['sem'], null, 'data');
	      $tbl->addCell($row['shift'], null, 'data');	
          $tbl->addCell($row['kdkmk'], null, 'data');
          $tbl->addCell($row['nakmktbkmk'], null, 'data');
          $tbl->addCell($row['kdds'], null, 'data');
          $tbl->addCell($row['nama'], null, 'data'); 		  
		} 
      }
                    $txt = '';
					$txt = $txt."<tr>";
						$txt = $txt."<th><input type='text' name='search_sem' value='Sem' class='search_init' style='width:20px'/></th>";
						$txt = $txt."<th><input type='text' name='search_RgNrg' value='Reg/NReg' class='search_init' style='width:50px'/></th>";	
						$txt = $txt."<th><input type='text' name='search_KdMtk' value='Kd Mtk' class='search_init' style='width:45px'/></th>";
						$txt = $txt."<th><input type='text' name='search_NmMtk' value='Nama Mtk' class='search_init' style='width:100px'/></th>";											
						$txt = $txt."<th><input type='text' name='search_KdDsn' value='Kd Dosen' class='search_init' style='width:45px'/></th>";
						$txt = $txt."<th><input type='text' name='search_NmDsn' value='Nama Dosen' class='search_init' style='width:100px'/></th>";
											
					$txt = $txt."</tr>";		
	  return $tbl->display($txt);
	}
	
	function build_cetak_krs_mhs()
	{
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "krs_mhs","width"=>"100%"));
		$tbl->addRow();
        $tbl->addCell('Angkatan', null, 'header');
	    $tbl->addCell('NIM', null, 'header');	   
		$tbl->addCell('Nama', null, 'header');
	    $tbl->addCell('Kelas', null, 'header');	    
         		
	    $data = $this->dtcetak->get_dt_kartu();
		   
	  if(!empty($data))
      {	  
		foreach($data as $row){
		    $tbl->addRow();
			$tbl->addCell($row['tahunmsmhs'], null, 'data');
	        $tbl->addCell($row['nimhsmsmhs'], null, 'data');	   
		    $tbl->addCell($row['nmmhsmsmhs'], null, 'data');
	        $tbl->addCell($row['shiftmsmhs'], null, 'data');
    	 }
	 }	           $txt = "<tr>";
						$txt = $txt."<th><input type='text' name='search_Angkatan' value='Angkatan' class='search_init' style='width:40px'/></th>";
						$txt = $txt."<th><input type='text' name='search_NIM' value='NIM' class='search_init' style='width:45px'/></th>";	
						$txt = $txt."<th><input type='text' name='search_Nama' value='Nama' class='search_init' style='width:100px'/></th>";
						$txt = $txt."<th><input type='text' name='search_RgNrg' value='Reg/NReg' class='search_init' style='width:50px'/></th>";											
											
					$txt = $txt."</tr>";
		return $tbl->display($txt);
	}
}
?>