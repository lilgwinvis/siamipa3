<?php
  
   require_once 'shared.php';
   
class vwrekapkeumhs
{
  function __construct()
	{
	  
	}
	
	function tbl_rekap()
	{
	 $html = new html_element;
	 
	 	 
	 //$html_txt.="<legend>Rekap Permahasiswa</legend>"; 
	    
		$tbstat = array("id" => "lst_rekap","width"=>"100%");
		$header = array(array('Angkatan','NIM','Nama','Status','Kewajiban','Transaksi','Kekurangan','Kelebihan'));
	    $dataisi = array(); 
     
	 $dt_stat_mhs = new dt_stat_mhs;
	 
	 $tot_kewajiban['total'] = 0.00;
	 $tot_tran['total']= 0.00;
	 
	    $stat = array(1,6,5,4,2);
		foreach($stat as $idx)
		{
		 $tot_kewajiban[$dt_stat_mhs->stattostr($idx)] = 0.00;
		 $tot_tran[$dt_stat_mhs->stattostr($idx)]= 0.00;
	    }
	 	 
	 $tot_lebih =0.00;
	 $tot_kurang = 0.00;
	 
	 $mythnsem = new mythnsem;
	 $TA = $mythnsem->getthnsem();
	 $dt = new dt_rekap_trkeumhs;
	 $data = $dt->getrekaptrkeumhs();	 	 
	  
	 
	 if(!empty($data))
	 {
	   foreach($data as $row)
	   {
	    $tmpdt = array();
        $tmpdt[]=array($row['tahunmsmhs'], array());
		$tmpdt[]=array($row['nimhsmsmhs'], array());
		$tmpdt[]=array($row['nmmhsmsmhs'], array());		
		$tmpdt[]=array($dt_stat_mhs->getstatmhs($TA,$row['nimhsmsmhs']),array());		
		$tmpdt[]=array(number_format($kewajiban=$row['kewajiban'], 2, ',', '.') ,array('align'=>'right'));
        $tmpdt[]=array(number_format($tran=$row['tran'], 2, ',', '.'),array('align'=>'right'));
		$tmpdt[]=array(number_format($row['kewajiban']>$row['tran'] ? $kurang=$row['kewajiban']-$row['tran'] : $kurang=0.00 , 2, ',', '.') ,array('align'=>'right'));
		$tmpdt[]=array(number_format($row['kewajiban']<$row['tran'] ? $lebih=$row['tran']-$row['kewajiban'] : $lebih=0.00 , 2, ',', '.'),array('align'=>'right'));
	    $dataisi[]=$tmpdt;
		
		$tot_kewajiban['total'] +=$kewajiban;
		$tot_tran['total'] +=$tran;
		
		$tot_lebih +=$lebih;
	    $tot_kurang += $kurang;
		
		$stat=$dt_stat_mhs->getstatmhs($TA,$row['nimhsmsmhs'],-1);
		 		 		
		$tot_kewajiban[$dt_stat_mhs->stattostr($stat)] +=$kewajiban;
		$tot_tran[$dt_stat_mhs->stattostr($stat)] +=$tran;
		
		
		
	   }
	 }
	 
	 
	              $txt = '';
					$txt = $txt."<tr>";
												
						$txt = $txt."<th colspan='4'>Total</th>";
						$txt = $txt."<th align='right'>".number_format($tot_kewajiban['total'], 2, ',', '.')."</th>";											
						$txt = $txt."<th align='right'>".number_format($tot_tran['total'], 2, ',', '.')."</th>";
						$txt = $txt."<th align='right'>".number_format($tot_kurang, 2, ',', '.')."</th>";
                        $txt = $txt."<th align='right'>".number_format($tot_lebih, 2, ',', '.')."</th>";						
					$txt = $txt."</tr>";	 
	 
	 
	 $tbl = new mytable($tbstat,$header,$dataisi,$txt);	 
	 $tab1= $html->addfieldset(null,$tbl->display());
	 
	   $txt="Kewajian Yang Belum Dibayar = Total Kewajiban - Total Pembayaran = ".number_format($tot_kewajiban['total'], 2, ',', '.')." - ".number_format($tot_tran['total'], 2, ',', '.')." = ".number_format($tot_kewajiban['total']-$tot_tran['total'], 2, ',', '.');	   	   
	   $txt.="<br>Kekurangan Yang Belum Dibayar = Total Kekurangan - Total Kelebihanan = ".number_format($tot_kurang, 2, ',', '.')." - ".number_format($tot_lebih, 2, ',', '.')." = ".number_format($tot_kurang-$tot_lebih, 2, ',', '.');
	   	   
	   $tab1.=$html->addfieldset(null,$txt);
	 
	 
	 
	
	    
        $tbstat = array("id" => "lst_rekap_kewajiban","width"=>"100%");
		$header = array(array('Kode','Nama Akun','Kewajiban', 'Pembayaran','Kekurangan', 'Kelebihan'));
	    $dataisi = array();   
	   
		$data = $dt->getrekapacclvl0();
		  $ttl=0;
		  $tmp_kurang = 0;
		  $tmp_lebih = 0;
		  $ttl_kurang = 0;
		  $ttl_lebih = 0;
		  $ttl_wajib = 0;
		if(!empty($data))
		{
		  foreach($data as $row)
		  {
		   $tmpdt = array();
		   $tmpdt[]=array($row['noacclvl0'], array());
		   $tmpdt[]=array($row['nmacclvl0'], array());
		   $tmpdt[]=array(number_format($row['kewajiban'], 2, ',', '.'), array('align'=>'right'));
           $tmpdt[]=array(number_format($row['jml'], 2, ',', '.'), array('align'=>'right'));
		   $tmpdt[]=array($row['kewajiban']>$row['jml'] ? number_format($tmp_kurang=($row['kewajiban']-$row['jml']), 2, ',', '.') : number_format($tmp_kurang=0.00, 2, ',', '.'), array('align'=>'right'));
		   $tmpdt[]=array($row['kewajiban']<$row['jml'] ? number_format($tmp_lebih=($row['jml']-$row['kewajiban']), 2, ',', '.') : number_format($tmp_lebih=0.00, 2, ',', '.'), array('align'=>'right'));
		   $dataisi[]=$tmpdt;
		   $ttl+=$row['jml'];
		   $ttl_wajib += $row['kewajiban'];
		   $ttl_kurang += $tmp_kurang;
		   $ttl_lebih += $tmp_lebih;
		  }
		  
        } 		

             $txt = '';
					$txt = $txt."<tr>";
						$txt = $txt."<th></th>";
						$txt = $txt."<th>Total</th>";	
						$txt = $txt."<th align='right'>".number_format($ttl_wajib, 2, ',', '.')."</th>";
						$txt = $txt."<th align='right'>".number_format($ttl, 2, ',', '.')."</th>";											
						$txt = $txt."<th align='right'>".number_format($ttl_kurang, 2, ',', '.')."</th>";
						$txt = $txt."<th align='right'>".number_format($ttl_lebih, 2, ',', '.')."</th>";										
					$txt = $txt."</tr>";		
	 
	 
	 $tbl = new mytable($tbstat,$header,$dataisi,$txt);	 
	 $tab2= $html->addfieldset(null,$tbl->display());
	 
	   	
       $txt="Kewajian Yang Belum Dibayar = Total Kewajiban - Total Pembayaran = ".number_format($ttl_wajib, 2, ',', '.')." - ".number_format($ttl, 2, ',', '.')." = ".number_format($ttl_wajib-$ttl, 2, ',', '.');
	   $txt.="<br>Kekurangan Yang Belum Dibayar = Total Kekurangan - Total Kelebihanan = ".number_format($ttl_kurang, 2, ',', '.')." - ".number_format($ttl_lebih, 2, ',', '.')." = ".number_format($ttl_kurang-$ttl_lebih, 2, ',', '.');
	   	   
	   $tab2.=$html->addfieldset(null,$txt);;
	 
	 
	   
		$tbstat = array("id" => "lst_rekap_thn","width"=>"100%");
		$header = array(array('Tahun', 'Jumlah Pendapatan'));
	    $dataisi = array();  
		
	    $data = $dt->getpendperthn();
		$tot = 0.00;
		$byr = 0.00;
		if(!empty($data))
		{
		  foreach($data as $f)
		  {
		   $tmpdt = array();
		   $tmpdt[]=array($f['thn'], array());
           $tmpdt[]=array(number_format($byr=$f['jml'], 2, ',', '.'), array('align'=>'right'));
		   $dataisi[]=$tmpdt;
		   $tot += $byr;
		  }
		 
		}
		   $txt = '';
					$txt = $txt."<tr>";
		   
		   $txt = $txt.'<th>Total</th>';
           $txt = $txt.'<th align="right">'.number_format($tot, 2, ',', '.')."</th>";
		   $txt = $txt."</tr>";
	 
	 $tbl = new mytable($tbstat,$header,$dataisi,$txt);	 
	 $tab3= $html->addfieldset(null,$tbl->display());
	 
	 
	 
	 //$html_txt.="<legend>Rekap Total</legend>";
	 
	    $tbstat = array("id" => "lst_summary","width"=>"100%");
		$header = array(array('Status Mahasiswa', 'Kewajiban Belum Masuk', 'Kewajiban Sudah Masuk','Total Kewajiban'));
	    $dataisi = array();		
	    
        $stat = array(1,6,5,4,2);
		foreach($stat as $idx)
		{
			$tmpdt = array();
			$tmp = $dt_stat_mhs->stattostr($idx);
			$tmpdt[]=array($tmp, array());
			$tmpdt[]=array(number_format($tot_kewajiban[$tmp]-$tot_tran[$tmp], 2, ',', '.'), array('align'=>'right'));
			$tmpdt[]=array(number_format($tot_tran[$tmp], 2, ',', '.'), array('align'=>'right'));
			$tmpdt[]=array('<font color="blue">'.number_format($tot_kewajiban[$tmp], 2, ',', '.')."</font>", array('align'=>'right'));
			$dataisi[]=$tmpdt;
		}
		
	   	
	           $txt = '';
					$txt = $txt."<tr>";
						$txt = $txt."<th>Total</th>";	
						$txt = $txt."<th align='right'>".number_format($tot_kewajiban['total']-$tot_tran['total'], 2, ',', '.')."</th>";
						$txt = $txt."<th align='right'>".number_format($tot_tran['total'], 2, ',', '.')."</th>";											
						$txt = $txt."<th align='right'>".number_format($tot_kewajiban['total'], 2, ',', '.')."</th>";																
					$txt = $txt."</tr>";
	 
	 
	 $tbl = new mytable($tbstat,$header,$dataisi,$txt);	 
	 $tab4= $html->addfieldset(null,$tbl->display());
      
	 
	 $html_txt="<div id='tabs'>";	

		   $html_txt.="<ul>";
		   $html_txt.="<li><a href='#tabs-1'>Rekap Permahasiswa</a></li>";
		   $html_txt.="<li><a href='#tabs-2'>Rekap Perkewajiban (Total)</a></li>";
		   $html_txt.="<li><a href='#tabs-3'>Rekap Pendapatan</a></li>";
		   $html_txt.="<li><a href='#tabs-4'>Rekap Total</a></li>";
		   $html_txt.="</ul>";
	 
		 $html_txt.="<div id='tabs-1'>".$tab1."</div>";
		 $html_txt.="<div id='tabs-2'>".$tab2."</div>";
		 $html_txt.="<div id='tabs-3'>".$tab3."</div>";		 
		 $html_txt.="<div id='tabs-4'>".$tab4."</div>";
	 $html_txt.="</div>";
	 
	  return $html_txt;
	 
	}

}

?>