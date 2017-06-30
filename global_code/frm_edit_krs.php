<?php require_once 'shared.php';     
     
     
     $nim = $_GET['nim'];
     $nama = $_GET['nama'];     
	 
     $user = $_SESSION['user'];
	 
	 $islog = $_SESSION['islog'];
	 $pg_bfr = $_SESSION['pg_bfr'];
	 
	
	 
	 if($islog==0)
	 {
		 include("../global_code/frm_login.php");
	 }
	 else
	 {	 
	     $jml_sks = 0;
         $ventri_krs = new dt_krs;
         $data = $ventri_krs->buildkrs($nim);
		 $jml_sks = $ventri_krs->jml_sks;
     	 foreach ($data as $row) {	
		
		      $kode_matkul[] = $row['kdkmktbkmk'];
			  $nama_matkul[] = $row['nakmktbkmk'];
			  $sks[] = $row['sksmktbkmk'];
			  $sem[] = $row['semestbkmk'];
              $wp[] = $row['wp'];	
		      $cek[] = $row['cek'];
		}
		
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Kartu Rencana Studi (KRS)</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	 <link type="text/css" href="../css/style.css" rel="stylesheet" />
	<style type="text/css">
	.ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 11px; }
	</style>
	<script type="text/javascript" src="../js/jquery-1.8.0.min.js"></script>
	<script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js"></script>
	<script type="text/javascript">

		<?php
		echo "var jumlah = ".count($kode_matkul).";\n";
		echo "var sks = new Array();\n";
		//mengambil sks matakuliah dan memasukkan ke array javascript
		for($j=0; $j<count($kode_matkul); $j++){
		    
			echo "sks['".$kode_matkul[$j]."'] = ".$sks[$j].";\n";
		}
		?>
		function hitungtotal(){
			jum = 0;
			for(i=0;i<jumlah;i++){
			id = "mk"+i;
			td1 = "k1"+i;
			td2 = "k2"+i;
			td3 = "k3"+i;
			td4 = "k4"+i;
			if(document.getElementById(id).checked){
			kode_matkul = document.getElementById(id).value
			jum = jum + sks[kode_matkul];
			//untuk mengubah warna latar tabel apabila diceklist
			
			}else {
			
			}
			}
			//menampilkan total jumlah SKS yang diambil
			document.getElementById("jsks").value = jum;
	    }

	$(document).ready(function () {
		// Dialog
				$('#dialog').dialog({
					autoOpen: true,
					width: 650,
					open: function(){
							$('#pgload').html("");
						  },
					buttons: {
						"Ok": function() {
							$('#dialog').dialog("close");
							$('#pgload').html("<div id='pgload'><font size='1' color='red'>Menyimpan Data ....</font> <img src='../img/ajax-loader.gif' /></div>");
							$.ajax({
                                     type : "POST",
				                     url : "outputkrs.php",
				                     cache: false,
				                     data : $("#inputkrs").serialize(),
									 success : function(data){
					                            alert(data);
												if(data=="Kartu Rencana Studi (KRS) Disimpan !!!"){
												   $('#pgload').html("");
												}
												window.parent.pg_bfr(<?php echo '"'.$pg_bfr.'"' ?>);
				                               }
                                  });
							
							
						},
						"Cancel": function() {
							$(this).dialog("close");
							window.parent.pg_bfr(<?php echo '"'.$pg_bfr.'"' ?>);
						}
					}
				});

 	});

	</script>
	
  <style type="text/css">
     
  </style>
</head>

<body>
     <?php echo "<link rel=\"icon\" href=\"../img/unibba.ico\" type=\"image/x-icon\">"; ?>
	<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>  
   <!-- ui-dialog -->
	
	<div id="dialog" title="<?php echo 'Edit Kartu Rencana Studi &#40KRS&#41 :' . $nim ." - ". $nama ?> ">	
	<form name="inputkrs" id="inputkrs" method="post" action="outputkrs.php">
	    <input type="hidden" name="nim" value="<?php echo $nim ?>">
		<table id="box-table-a">
		  <thead> 	
			<tr>
			<th>Kode Mata Kuliah</th>
			<th>Nama Mata Kuliah</th>
			<th>SKS</th>
			<th>Ambil</th>
			</tr>
		  </thead>
          <tbody>		  
		<?php
		//menampilkan matakuliah ke dalam tabel
			$temp="0";
			for($i=0; $i<count($kode_matkul); $i++){
			
			   if($temp!=$sem[$i]){
			      $temp=$sem[$i];
		?>
                <tr>
				  <td colspan="4" align="center" ><?php echo "Semester ".$sem[$i] ?></td>
				</tr>
		<?php 		
			   }
		?>
				<tr>
				 <?php 
                       if($wp[$i]=='p'){
                      ?>
				<td id="k1<?php echo $i ?>"><font color='red'><i><?php echo $kode_matkul[$i]?></i></font></td>
				<td id="k2<?php echo $i ?>"><font color='red'><i><?php echo $nama_matkul[$i] ?></i></font></td>
				<td id="k3<?php echo $i ?>" align="center" ><font color='red'><i><?php echo $sks[$i] ?></i></font></td>
				<?php	
						}else{
						?>
				<td id="k1<?php echo $i ?>"><?php echo $kode_matkul[$i]?></td>
				<td id="k2<?php echo $i ?>"><?php echo $nama_matkul[$i] ?></td>
				<td id="k3<?php echo $i ?>" align="center" ><?php echo $sks[$i] ?></td>		
				<?php
						}
						?>		
				<td id="k4<?php echo $i ?>" align="center">
				<?php
				  if($cek[$i]=="1"){
				?>
				  <input type="checkbox" name="mk[]" onclick="hitungtotal()" value="<?php echo $kode_matkul[$i]?>" id="mk<?php echo $i ?>" checked="yes">
				<?php
				  } else {
				?>				
				  <input type="checkbox" name="mk[]" onclick="hitungtotal()" value="<?php echo $kode_matkul[$i]?>" id="mk<?php echo $i ?>" >
				<?php
				  }
				?>
				
				</tr>
		<?php
		}
		?>
			<tr>
				<td colspan="3" align="center" >
				   <b>JUMLAH YANG DIAMBIL</b>
				</td>
				<td align="center">
				  <?php
				  if($cek[$i]==1){
				?>
				  <input type="text" name="totalsks" size="3" maxlength="3" id="jsks" readonly="readonly" style="text-align:center; color:red;">
				 <?php
				  } else {
				?>	
				  <input type="text" name="totalsks" size="3" maxlength="3" id="jsks" readonly="readonly" style="text-align:center; color:red;" value="<?php  echo $jml_sks ?>">
				 <?php
				  }
				?> 
				</td>
			</tr>
			</tbody>
		</table>
	</form>
	</div>	
   
</body>

</html>
<?php } ?> 