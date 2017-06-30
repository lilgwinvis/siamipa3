<?php require_once 'shared.php';  
        	 
     
	 $islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	 $pg_bfr = $_SESSION['pg_bfr'];
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=2");
		 exit();
	 }
	 else
	 {	 
            
         $nim = $_SESSION['user'];
	     
		 $thn = $_GET['thn'];
		 $sem = $_GET['sem'];
		 $shift=$_GET['shift'];
		 $kelas=$_GET['kelas'];		 
		 $kdkmk=$_GET['kdkmk'];
		 $nmkmk=$_GET['nmkmk'];
		 $kdds=$_GET['kdds'];
		 $nmds=$_GET['nmds'];
		 
		 $dtpoll = new dt_poll;
		 $data = $dtpoll->getDataadminVDpoll($thn,$sem,$shift,$kelas,$kdkmk);
		 
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Kuosioner</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	<style type="text/css">
	  @import "../datatables/media/css/demo_page.css";
	  @import "../datatables/media/css/demo_table.css";
	.ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 8px; }
	</style>
	<script type="text/javascript" src="../js/jquery-1.8.0.min.js"></script>
	<script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js"></script>
	<script type="text/javascript" src="../datatables/media/js/jquery.dataTables.js"></script>
	<script type="text/javascript" src="../js/siamipa.js"></script>
	<script type="text/javascript" src="local_js/frm_hsl_kuosioner.js"></script>
	<script type="text/javascript">



$(document).ready(function () {
	// Dialog
	$('#dialog').dialog({
		autoOpen : true,
		width : 800,
		open : function () {
			$('#pgload').html("");
			init_tb();
		},
		buttons : {
			"Ok" : function () {
				window.parent.pg_bfr( <?php echo '"'.$pg_bfr.'"' ?> );
			}
		}
	});

});

	</script>
	
  <style type="text/css">
     
  </style>
</head>

<body>
   <div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
   <!-- ui-dialog -->
		<div id="dialog" title="Kuosioner">
			<div>
			
			<fieldset>
			<center>KUISIONER PENYELENGGARAAN PROSES PEMBELAJARAN<br>(Mahasiswa Terhadap Dosen)<br><br></center>
			<table>
			   <tr>
			     <td>Program Studi</td>
				 <td>:</td>
				 <td>Matematika</td>
			   </tr>
			   <tr>
			     <td>Dosen</td>
				 <td>:</td>
				 <td><?php echo $nmds; ?></td>
			   </tr>
			   <tr>
			     <td>Mata Kuliah</td>
				 <td>:</td>
				 <td><?php echo $nmkmk; ?></td>
			   </tr>
			   <tr>
			     <td>Jumlah Kehadiran Dosen</td>
				 <td>:</td>
				 <td></td>
			   </tr>
			   
			</table>
			
			

			
		    <form name="entry" id="entry" method="post" action="poll.php">
						
				
				
				<table id="frmentrypoll" width='100%'>	
				  <thead>
				  <tr>
					  <th rowspan='2'> No </th>	
					  <th rowspan='2'> PERTANYAAN </th>	
					  <th colspan='5'> NILAI </th>
				  </tr> 
				  <tr>
					   <th>Sangat baik</th>	
					   <th>Baik</th>	
					   <th>Sedang</th>	
					   <th>Kurang</th>	
					   <th>Sangat Buruk</th>
				  </tr>
				  </thead>
				  <tbody>
				  <tr>
					  <td>1</td>	
					  <td>Dosen menyampaikan RP (Rancangan Pembelajaran)/Silabus/SAP (Satuan Acara Pengajaran) di awal perkuliahan</td>
					  <td><?php echo (isset($data[1][5]) ?  $data[1][5] : 0); ?></td>	
					  <td><?php echo (isset($data[1][4]) ?  $data[1][4] : 0); ?></td>	
					  <td><?php echo (isset($data[1][3]) ?  $data[1][3] : 0); ?></td>	
					  <td><?php echo (isset($data[1][2]) ?  $data[1][2] : 0); ?></td>	
					  <td><?php echo (isset($data[1][1]) ?  $data[1][1] : 0); ?></td>			  
				  </tr>
				  <tr>
					  <td>2</td>	
					  <td>Dosen memberikan informasi mengenai buku teks atau rujukan yang digunakan.</td>		
					  <td><?php echo (isset($data[2][5]) ?  $data[2][5] : 0); ?></td>	
					  <td><?php echo (isset($data[2][4]) ?  $data[2][4] : 0); ?></td>	
					  <td><?php echo (isset($data[2][3]) ?  $data[2][3] : 0); ?></td>	
					  <td><?php echo (isset($data[2][2]) ?  $data[2][2] : 0); ?></td>	
					  <td><?php echo (isset($data[2][1]) ?  $data[2][1] : 0); ?></td>	
				  </tr>
				  <tr>
					  <td>3</td>	
					  <td>Dosen menyediakan/memberikan bahan ajar di luar buku rujukan (contoh : hand out/transparant sheet/power point slide) yang cukup jelas untuk setiap materi</td> 					
					  <td><?php echo (isset($data[3][5]) ?  $data[3][5] : 0); ?></td>	
					  <td><?php echo (isset($data[3][4]) ?  $data[3][4] : 0); ?></td>	
					  <td><?php echo (isset($data[3][3]) ?  $data[3][3] : 0); ?></td>	
					  <td><?php echo (isset($data[3][2]) ?  $data[3][2] : 0); ?></td>	
					  <td><?php echo (isset($data[3][1]) ?  $data[3][1] : 0); ?></td>	
				  </tr>
				  <tr>
					  <td>4</td>	
					  <td>Tugas yang diberikan relevan denngan materi pelajaran dan tujuan pembelajaran.</td>					
					  <td><?php echo (isset($data[4][5]) ?  $data[4][5] : 0); ?></td>	
					  <td><?php echo (isset($data[4][4]) ?  $data[4][4] : 0); ?></td>	
					  <td><?php echo (isset($data[4][3]) ?  $data[4][3] : 0); ?></td>	
					  <td><?php echo (isset($data[4][2]) ?  $data[4][2] : 0); ?></td>	
					  <td><?php echo (isset($data[4][1]) ?  $data[4][1] : 0); ?></td>	
				  </tr>
				  <tr>
					  <td>5</td>	
					  <td>Materi yang disampaikan sesuai dengan RP/Silabus/SAP.</td>					
					  <td><?php echo (isset($data[5][5]) ?  $data[5][5] : 0); ?></td>	
					  <td><?php echo (isset($data[5][4]) ?  $data[5][4] : 0); ?></td>	
					  <td><?php echo (isset($data[5][3]) ?  $data[5][3] : 0); ?></td>	
					  <td><?php echo (isset($data[5][2]) ?  $data[5][2] : 0); ?></td>	
					  <td><?php echo (isset($data[5][1]) ?  $data[5][1] : 0); ?></td>	
				  </tr>
				  <tr>
					  <td>6</td>	
					  <td>Materi kuliah disampaikan secara sistematis dan jelas.</td>					
					  <td><?php echo (isset($data[6][5]) ?  $data[6][5] : 0); ?></td>	
					  <td><?php echo (isset($data[6][4]) ?  $data[6][4] : 0); ?></td>	
					  <td><?php echo (isset($data[6][3]) ?  $data[6][3] : 0); ?></td>	
					  <td><?php echo (isset($data[6][2]) ?  $data[6][2] : 0); ?></td>	
					  <td><?php echo (isset($data[6][1]) ?  $data[6][1] : 0); ?></td>	
				  </tr>
				  <tr>
					  <td>7</td>	
					  <td>Dosen menjawab pertanyaan mahasiswa secara komprehensif </td>					
					  <td><?php echo (isset($data[7][5]) ?  $data[7][5] : 0); ?></td>	
					  <td><?php echo (isset($data[7][4]) ?  $data[7][4] : 0); ?></td>	
					  <td><?php echo (isset($data[7][3]) ?  $data[7][3] : 0); ?></td>	
					  <td><?php echo (isset($data[7][2]) ?  $data[7][2] : 0); ?></td>	
					  <td><?php echo (isset($data[7][1]) ?  $data[7][1] : 0); ?></td>	
				  </tr>
				  <tr>
					  <td>8</td>	
					  <td>Contoh dan aplikasi materi diberikan dengan jelas.</td>					
					  <td><?php echo (isset($data[8][5]) ?  $data[8][5] : 0); ?></td>	
					  <td><?php echo (isset($data[8][4]) ?  $data[8][4] : 0); ?></td>	
					  <td><?php echo (isset($data[8][3]) ?  $data[8][3] : 0); ?></td>	
					  <td><?php echo (isset($data[8][2]) ?  $data[8][2] : 0); ?></td>	
					  <td><?php echo (isset($data[8][1]) ?  $data[8][1] : 0); ?></td>	
				   </tr>
				  <tr>
					  <td>9</td>	
					  <td>Dosen mendorong mahasiswa untuk aktif di kelas (contoh : bertanya, berdiskusi, berlatih)</td>					
					  <td><?php echo (isset($data[9][5]) ?  $data[9][5] : 0); ?></td>	
					  <td><?php echo (isset($data[9][4]) ?  $data[9][4] : 0); ?></td>	
					  <td><?php echo (isset($data[9][3]) ?  $data[9][3] : 0); ?></td>	
					  <td><?php echo (isset($data[9][2]) ?  $data[9][2] : 0); ?></td>	
					  <td><?php echo (isset($data[9][1]) ?  $data[9][1] : 0); ?></td>	
				  </tr>
				  <tr>
					  <td>10</td>	
					  <td>Setelah penyampaian materi saya menjadi tertarik untuk mengetahui lebih jauh/menguasai mata ajaran ini.</td>					
					  <td><?php echo (isset($data[10][5]) ?  $data[10][5] : 0); ?></td>	
					  <td><?php echo (isset($data[10][4]) ?  $data[10][4] : 0); ?></td>	
					  <td><?php echo (isset($data[10][3]) ?  $data[10][3] : 0); ?></td>	
					  <td><?php echo (isset($data[10][2]) ?  $data[10][2] : 0); ?></td>	
					  <td><?php echo (isset($data[10][1]) ?  $data[10][1] : 0); ?></td>	
				  </tr>
				  <tr>
					  <td>11</td>	
					  <td>Kuliah dilaksanakan tepat waktu.</td>					
					  <td><?php echo (isset($data[11][5]) ?  $data[11][5] : 0); ?></td>	
					  <td><?php echo (isset($data[11][4]) ?  $data[11][4] : 0); ?></td>	
					  <td><?php echo (isset($data[11][3]) ?  $data[11][3] : 0); ?></td>	
					  <td><?php echo (isset($data[11][2]) ?  $data[11][2] : 0); ?></td>	
					  <td><?php echo (isset($data[11][1]) ?  $data[11][1] : 0); ?></td>	
				  </tr>
				  <tr>
					  <td>12</td>	
					  <td>Pertanyaan ujian (UTS/UAS) sesuai dengan lingkup materi yang diberikan.</td>					
					  <td><?php echo (isset($data[12][5]) ?  $data[12][5] : 0); ?></td>	
					  <td><?php echo (isset($data[12][4]) ?  $data[12][4] : 0); ?></td>	
					  <td><?php echo (isset($data[12][3]) ?  $data[12][3] : 0); ?></td>	
					  <td><?php echo (isset($data[12][2]) ?  $data[12][2] : 0); ?></td>	
					  <td><?php echo (isset($data[12][1]) ?  $data[12][1] : 0); ?></td>	
				  </tr>
				  </tbody>
			   </table>
			</form>				  
			 </fieldset> 
			</div>
		</div>
   
</body>

</html>
<?php } ?>