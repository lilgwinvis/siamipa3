<?php require_once 'shared.php';     
     
	 $islog = $_SESSION['islog'];
	 $pg_bfr = $_SESSION['pg_bfr'];
	 if($islog==0)
	 {
		header("Location: ../global_code/frm_login.php?idx=$idx");
		exit();
	 }
	 else
	 {	  $thnsms = $_GET['thnsms'];
	      $kdkmk = $_GET['kdkmk'];
	      $kelas = $_GET['kelas'];
          $kelas1 = $_GET['kelas1'];
	      $sem1 = $_GET['sem'];     
	 
          $user = $_SESSION['user'];
	      
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Lihat Nilai</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	<!-- <link type="text/css" href="../css/style.css" rel="stylesheet" /> -->
	<style type="text/css">
      @import "../datatables/media/css/demo_page.css";
	  @import "../datatables/media/css/demo_table.css";
	  .ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 9px; }
     </style>
	<script type="text/javascript" src="../js/jquery-1.8.0.min.js"></script>
	<script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js"></script>
	<script type="text/javascript" src="../datatables/media/js/jquery.dataTables.js"></script>
	<script type="text/javascript">

	

	$(document).ready(function () {
		// Dialog
				var oTable;
				$('#dialog').dialog({
					autoOpen: true,
					width : 700,
					autoHeight:true, 
					resizable: true,
					open: function(){
							oTable=$("#frmentrynilai").dataTable();			
					    },
					buttons: {
						"Simpan": function() {
							$(this).dialog("close");
							$.ajax({
                                     type : "POST",
				                     url : "entry.php",
				                     cache: false,
				                     data :  $('input[type=hidden]').serialize()+"&"+$('input:text').serialize()+"&"+$(":input",oTable.fnGetNodes()).serialize(),
									 success : function(data){
					                            alert(data);
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
   <!-- ui-dialog -->
		<?php
		  
		            $vriwayat_mtk = new tb_gen('vw_pengajar_jn_tbkmk');
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
		<form name="entry" id="entry" method="post" action="entry.php">
		    <input type="hidden" name="kdkmk" value="<?php echo $kdkmk ?>">
			<input type="hidden" name="thnsms" value="<?php echo $thnsms ?>">
			<input type="hidden" name="kelas" value="<?php echo $kelas ?>">
			<input type="hidden" name="idx" value="<?php echo $idx ?>">
			<table class="display" id="frmentrynilai" >
				   <thead>
				   <tr>
				        <th scope="col">NO </th>
						<th scope="col">NIM </th>
						<th scope="col">NAMA</th>
					 
						<th scope="col" align='center'>A</th>
						<th scope="col" align='center'>B</th>
						<th scope="col" align='center'>C</th>
						<th scope="col" align='center'>D</th>
						<th scope="col" align='center'>E</th>
						<th scope="col" align='center'>T</th>
						<th scope="col" align='center'>K</th>
						<th scope="col" align='center'>S</th>
				   </tr>
				   </thead>
				   <tbody>
				     <?php
					    $vriwayat_nilai = new tb_gen('trnlm_jn_msmhs');
					    $where = "thsmstrnlm='$thnsms' and kdkmktrnlm='$kdkmk' and shifttrnlm='$kelas' and kelastrnlm='$kelas1' and semestrnlm='$sem1'"; 
      	                $data = $vriwayat_nilai->getData($where); 
					    $i=1;
						foreach($data as $row){
						 $Acheck="";
						 $Bcheck="";
						 $Ccheck="";
						 $Dcheck="";
						 $Echeck="";
						 $Tcheck="";
						 $Kcheck="";
						 $Scheck="";
						 switch($row['nlakhtrnlm']){
						 case 'A' : $Acheck="checked";
						            break;
						 case 'B' : $Bcheck="checked";
						            break;
                         case 'C' : $Ccheck="checked";
						            break;
                         case 'D' : $Dcheck="checked";
						            break;
                         case 'E' : $Echeck="checked";
						            break;
                         case 'T' : $Tcheck="checked";
						            break;									
						 case 'K' : $Kcheck="checked";
						            break;
						 case 'S' : $Scheck="checked";
						            break; 			
						 }
						
					 ?> 
					     <tr>
				            <td><?php echo $i ?></td>
							<td><?php echo $row['nimhstrnlm'] ?></td>
						    <td><?php echo $row['nmmhsmsmhs'] ?></td>
                          
  						    <td ><input type="radio" name="nilai[<?php echo trim($row['nimhstrnlm']) ?>]" value="A" id="nilaiA<?php echo $i ?>"  <?php echo $Acheck ?>></td>	
                            <td ><input type="radio" name="nilai[<?php echo trim($row['nimhstrnlm']) ?>]" value="B" id="nilaiB<?php echo $i ?>"  <?php echo $Bcheck ?>></td>
							<td ><input type="radio" name="nilai[<?php echo trim($row['nimhstrnlm']) ?>]" value="C" id="nilaiC<?php echo $i ?>"  <?php echo $Ccheck ?>></td>	
                            <td ><input type="radio" name="nilai[<?php echo trim($row['nimhstrnlm']) ?>]" value="D" id="nilaiD<?php echo $i ?>"  <?php echo $Dcheck ?>></td>
							<td ><input type="radio" name="nilai[<?php echo trim($row['nimhstrnlm']) ?>]" value="E" id="nilaiE<?php echo $i ?>"  <?php echo $Echeck ?>></td>
							<td ><input type="radio" name="nilai[<?php echo trim($row['nimhstrnlm']) ?>]" value="T" id="nilaiT<?php echo $i ?>"  <?php echo $Tcheck ?>></td>
							<td ><input type="radio" name="nilai[<?php echo trim($row['nimhstrnlm']) ?>]" value="K" id="nilaiK<?php echo $i ?>"  <?php echo $Kcheck ?>></td>
							<td ><input type="radio" name="nilai[<?php echo trim($row['nimhstrnlm']) ?>]" value="S" id="nilaiS<?php echo $i ?>"  <?php echo $Scheck ?>></td>
				            
						  </tr>
					 
				     <?php
					      $i++;
						 }
					 ?>
			       
				   </tbody>
				   			   
			</table>
		</form>	   
		</div>
   
</body>

</html>
<?php } ?>