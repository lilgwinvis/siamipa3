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
		 $nim=$_GET['nim'];
		 $kdkmk=$_GET['kdkmk'];
		 $nmkmk=$_GET['nmkmk'];
		 $kdds=$_GET['kdds'];
		 $nmds=$_GET['nmds'];
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
	.ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 9px; }
	</style>
	<script type="text/javascript" src="../js/jquery-1.8.0.min.js"></script>
	<script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js"></script>
	<script type="text/javascript" src="../datatables/media/js/jquery.dataTables.js"></script>
	
	<script type="text/javascript">

	var firstclick=true;

	$(document).ready(function () {
		// Dialog
				$('#dialog').dialog({
					autoOpen: true,
					width: 600,
					open: function(){
							$('#pgload').html("");
							oTable=$("#frmentrypoll").dataTable({
									"bProcessing": true,
									"bFilter": false,
									"bSort": false,
									"bPaginate": false,
									"bInfo": false
								});
						  },
					buttons: {
						"Save": function() {
							    if(firstclick){
									firstclick=false;
									$.ajax({
										 type : "POST",
										 url : "local_class/poll.php",
										 cache: false,
										 data :  $('input[type=hidden]').serialize()+"&"+$('input:text').serialize()+"&"+$(":input",oTable.fnGetNodes()).serialize(),
										 dataType: 'json',
										 success : function(data){					                            
													if(data.stat==0){
														alert(data.msg);
													}else{ 													
													  $(this).dialog("close");
													  window.parent.pg_bfr(<?php echo '"'.$pg_bfr.'"' ?>);		
													}
												   }
									  });
							    }else{
                                  alert('Hanya boleh save satu kali !!!');							
							    }
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
			    <p>Mohon diisi dengan jujur dan objektif agar diperoleh hasil yang benar demi perbaikan penyelenggaraan proses belajar mengajar.</p>
			    <br>
				Keterangan :<br>
				5. Sangat baik <br>
				4. Baik<br>
				3. Sedang<br>
				2. Kurang<br>
				1. Sangat Buruk<br>
			</fieldset>
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
			   <tr>
			     <td>Jumlah Kehadiran Anda</td>
				 <td>:</td>
				 <td></td>
			   </tr>
			</table>
			
			

			
		    <form name="entry" id="entry" method="post" action="poll.php">
						
				<input type="hidden" name="thn" value="<?php echo $thn ?>">
			    <input type="hidden" name="sem" value="<?php echo $sem ?>">
			    <input type="hidden" name="shift" value="<?php echo $shift ?>">
			    <input type="hidden" name="kelas" value="<?php echo $kelas ?>">
				<input type="hidden" name="kdkmk" value="<?php echo $kdkmk ?>">
				<input type="hidden" name="nim" value="<?php echo $nim ?>">
				
				<table id="frmentrypoll" width='100%'>	
				  <thead>
				  <tr>
					  <th rowspan='2'> No </th>	
					  <th rowspan='2'> PERTANYAAN </th>	
					  <th colspan='5'> NILAI </th>
				  </tr> 
				  <tr>
					   <th>5</th>	
					   <th>4</th>	
					   <th>3</th>	
					   <th>2</th>	
					   <th>1</th>
				  </tr>
				  </thead>
				  <tbody>
				  <tr>
					  <td>1</td>	
					  <td>Dosen menyampaikan RP (Rancangan Pembelajaran)/Silabus/SAP (Satuan Acara Pengajaran) di awal perkuliahan</td>
					  <td><input type="radio" name="poll[1]" value="5" id="poll15"></td>	
					  <td><input type="radio" name="poll[1]" value="4" id="poll14"></td>	
					  <td><input type="radio" name="poll[1]" value="3" id="poll13"></td>	
					  <td><input type="radio" name="poll[1]" value="2" id="poll12"></td>	
					  <td><input type="radio" name="poll[1]" value="1" id="poll11"></td>			  
				  </tr>
				  <tr>
					  <td>2</td>	
					  <td>Dosen memberikan informasi mengenai buku teks atau rujukan yang digunakan.</td>		
					  <td><input type="radio" name="poll[2]" value="5" id="poll25"></td>	
					  <td><input type="radio" name="poll[2]" value="4" id="poll24"></td>	
					  <td><input type="radio" name="poll[2]" value="3" id="poll23"></td>	
					  <td><input type="radio" name="poll[2]" value="2" id="poll22"></td>	
					  <td><input type="radio" name="poll[2]" value="1" id="poll21"></td>	
				  </tr>
				  <tr>
					  <td>3</td>	
					  <td>Dosen menyediakan/memberikan bahan ajar di luar buku rujukan (contoh : hand out/transparant sheet/power point slide) yang cukup jelas untuk setiap materi</td> 					
					  <td><input type="radio" name="poll[3]" value="5" id="poll35"></td>	
					  <td><input type="radio" name="poll[3]" value="4" id="poll34"></td>	
					  <td><input type="radio" name="poll[3]" value="3" id="poll33"></td>	
					  <td><input type="radio" name="poll[3]" value="2" id="poll32"></td>	
					  <td><input type="radio" name="poll[3]" value="1" id="poll31"></td>	
				  </tr>
				  <tr>
					  <td>4</td>	
					  <td>Tugas yang diberikan relevan denngan materi pelajaran dan tujuan pembelajaran.</td>					
					  <td><input type="radio" name="poll[4]" value="5" id="poll45"></td>	
					  <td><input type="radio" name="poll[4]" value="4" id="poll44"></td>	
					  <td><input type="radio" name="poll[4]" value="3" id="poll43"></td>	
					  <td><input type="radio" name="poll[4]" value="2" id="poll42"></td>	
					  <td><input type="radio" name="poll[4]" value="1" id="poll41"></td>	
				  </tr>
				  <tr>
					  <td>5</td>	
					  <td>Materi yang disampaikan sesuai dengan RP/Silabus/SAP.</td>					
					  <td><input type="radio" name="poll[5]" value="5" id="poll55"></td>	
					  <td><input type="radio" name="poll[5]" value="4" id="poll54"></td>	
					  <td><input type="radio" name="poll[5]" value="3" id="poll53"></td>	
					  <td><input type="radio" name="poll[5]" value="2" id="poll52"></td>	
					  <td><input type="radio" name="poll[5]" value="1" id="poll51"></td>	
				  </tr>
				  <tr>
					  <td>6</td>	
					  <td>Materi kuliah disampaikan secara sistematis dan jelas.</td>					
					  <td><input type="radio" name="poll[6]" value="5" id="poll65"></td>	
					  <td><input type="radio" name="poll[6]" value="4" id="poll64"></td>	
					  <td><input type="radio" name="poll[6]" value="3" id="poll63"></td>	
					  <td><input type="radio" name="poll[6]" value="2" id="poll62"></td>	
					  <td><input type="radio" name="poll[6]" value="1" id="poll61"></td>	
				  </tr>
				  <tr>
					  <td>7</td>	
					  <td>Dosen menjawab pertanyaan mahasiswa secara komprehensif </td>					
					  <td><input type="radio" name="poll[7]" value="5" id="poll75"></td>	
					  <td><input type="radio" name="poll[7]" value="4" id="poll74"></td>	
					  <td><input type="radio" name="poll[7]" value="3" id="poll73"></td>	
					  <td><input type="radio" name="poll[7]" value="2" id="poll72"></td>	
					  <td><input type="radio" name="poll[7]" value="1" id="poll71"></td>	
				  </tr>
				  <tr>
					  <td>8</td>	
					  <td>Contoh dan aplikasi materi diberikan dengan jelas.</td>					
					  <td><input type="radio" name="poll[8]" value="5" id="poll85"></td>	
					  <td><input type="radio" name="poll[8]" value="4" id="poll84"></td>	
					  <td><input type="radio" name="poll[8]" value="3" id="poll83"></td>	
					  <td><input type="radio" name="poll[8]" value="2" id="poll82"></td>	
					  <td><input type="radio" name="poll[8]" value="1" id="poll81"></td>	
				   </tr>
				  <tr>
					  <td>9</td>	
					  <td>Dosen mendorong mahasiswa untuk aktif di kelas (contoh : bertanya, berdiskusi, berlatih)</td>					
					  <td><input type="radio" name="poll[9]" value="5" id="poll95"></td>	
					  <td><input type="radio" name="poll[9]" value="4" id="poll94"></td>	
					  <td><input type="radio" name="poll[9]" value="3" id="poll93"></td>	
					  <td><input type="radio" name="poll[9]" value="2" id="poll92"></td>	
					  <td><input type="radio" name="poll[9]" value="1" id="poll91"></td>	
				  </tr>
				  <tr>
					  <td>10</td>	
					  <td>Setelah penyampaian materi saya menjadi tertarik untuk mengetahui lebih jauh/menguasai mata ajaran ini.</td>					
					  <td><input type="radio" name="poll[10]" value="5" id="poll105"></td>	
					  <td><input type="radio" name="poll[10]" value="4" id="poll104"></td>	
					  <td><input type="radio" name="poll[10]" value="3" id="poll103"></td>	
					  <td><input type="radio" name="poll[10]" value="2" id="poll102"></td>	
					  <td><input type="radio" name="poll[10]" value="1" id="poll101"></td>	
				  </tr>
				  <tr>
					  <td>11</td>	
					  <td>Kuliah dilaksanakan tepat waktu.</td>					
					  <td><input type="radio" name="poll[11]" value="5" id="poll115"></td>	
					  <td><input type="radio" name="poll[11]" value="4" id="poll114"></td>	
					  <td><input type="radio" name="poll[11]" value="3" id="poll113"></td>	
					  <td><input type="radio" name="poll[11]" value="2" id="poll112"></td>	
					  <td><input type="radio" name="poll[11]" value="1" id="poll111"></td>	
				  </tr>
				  <tr>
					  <td>12</td>	
					  <td>Pertanyaan ujian (UTS/UAS) sesuai dengan lingkup materi yang diberikan.</td>					
					  <td><input type="radio" name="poll[12]" value="5" id="poll125"></td>	
					  <td><input type="radio" name="poll[12]" value="4" id="poll124"></td>	
					  <td><input type="radio" name="poll[12]" value="3" id="poll123"></td>	
					  <td><input type="radio" name="poll[12]" value="2" id="poll122"></td>	
					  <td><input type="radio" name="poll[12]" value="1" id="poll121"></td>	
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