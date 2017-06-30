<?php require_once 'shared.php';
      
	
	$islog = $_SESSION['islog'];
	if($islog==0)
	 {
		 include("../global_code/frm_login.php");
	 }
	 else
	 {	 
	 
	 
   
     $thnsms = $_GET['thnsms'];
	 $kdkmk = isset($_GET['kdkmk']) ? $_GET['kdkmk'] : " ";
	 $kelas = $_GET['kelas'];
	 $kelas1 = $_GET['kelas1'];
	 $sem1 = $_GET['sem'];
	 $kode = isset($_SESSION['kode']) ? $_SESSION['kode'] : "";
	 
	 $pg_bfr = $_SESSION['pg_bfr'];
	 
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Lihat Nilai</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	<!--<link type="text/css" href="../css/style.css" rel="stylesheet" />-->
	<link type="text/css" href="../datatables/media/css/jquery.dataTables.css" rel="stylesheet" />
	<style type="text/css">      
	  .ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 9px; }
     </style>
	<script type="text/javascript" src="../js/jquery-1.8.0.min.js"></script>
	<script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js"></script>
	<script type="text/javascript" src="../datatables/media/js/jquery.dataTables.js"></script>
	<script type="text/javascript">

	

	$(document).ready(function () {
		// Dialog
				$('#dialog').dialog({
					autoOpen: true,
					width : 700,
					autoHeight:true, 
					resizable: true,
					open: function(){			
						$('#box-table-a').dataTable();
					
					},
					buttons: {
						"Ok": function() {
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
   <!-- ui-dialog -->
		<?php
		  
		   $vriwayat_mtk = new tb_gen('pengajar_jn_tbkmk');
					$where = "thnsmspengajar='$thnsms' and kdkmkpengajar='$kdkmk' and shiftpengajar='$kelas' and kelaspengajar='$kelas1' and semespengajar='$sem1'"; 
      	            $data = $vriwayat_mtk->getData($where);
					
					if($kelas=='R'){
					  $kls="(Reguler)";
					}else{
					  $kls="(Non Reguler)"; 
					}
					
				 foreach($data as $row){
     				$sem = str_split($row['thnsmspengajar'], 4);			
					 
					if($sem[1]=="1"){
					    $tmp = $row['nakmktbkmk']." (".$row['kdkmkpengajar'].") ".$kls." Semester Ganjil ".$sem[0];
						
					 }else{
					   if($sem[1]=="2"){
					    $tmp = $row['nakmktbkmk']." (".$row['kdkmkpengajar'].") ".$kls." Semester Genap ".$sem[0];
						
						}
					 }
				}	 
					 
					 
					 
             ?>  		
		<div id="dialog" title="<?php echo $tmp  ?>">
			<table  id="box-table-a" >
				   <thead>
				   <tr>
				        <th scope="col">NO </th>
						<th scope="col">NIM </th>
						<th scope="col">NAMA</th>
						<th scope="col">HM</th>
						
				   </tr>
				   </thead>
				   <tbody>
				     <?php
					    $vriwayat_nilai = new tb_gen('trnlm_jn_msmhs');
					    $where = "thsmstrnlm='$thnsms' and kdkmktrnlm='$kdkmk' and shifttrnlm='$kelas' and kelastrnlm='$kelas1' and semestrnlm='$sem1'"; 
      	                $data = $vriwayat_nilai->getData($where); 
					    $i=1;
						foreach($data as $row){
					 ?> 
					     <tr>
				            <td><?php echo $i ?></td>
							<td><?php echo $row['nimhstrnlm'] ?></td>
						    <td><?php echo $row['nmmhsmsmhs'] ?></td>
						    <td><?php echo $row['nlakhtrnlm'] ?></td>
				          </tr>
					 
				     <?php
					      $i++;
						 }
					 ?>
			       
				   </tbody>
				   			   
				   </table>
		</div>
   
</body>

</html>
<?php } ?>