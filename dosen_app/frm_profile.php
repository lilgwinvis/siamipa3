<?php require_once 'shared.php';  
    
	$islog = $_SESSION['islog']; 
	
	if($islog==0)
	{
		header("Location: ../global_code/frm_login.php?idx=3");
		exit();
	}
	else
	{	
		
		  
		$login = new login;
		if($login->logintime()){		  
			header("Location: ../global_code/frm_login.php?idx=3&isout=1");
			exit();	
		}else{  
			
			$kode = $_SESSION['user'];
			
			
			
			$vuser = new dt_dosen;
			$data = $vuser->getData($kode);
			
			foreach ($data as $vrow) {
				$row = $vrow;
			} // foreach
			
			$nama = str_replace(' ', '&nbsp;',$row['Nama']);
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>User Profile</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	<style type="text/css">
      .ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 11px; }
     </style>
	<script type="text/javascript" src="../js/jquery-1.8.0.min.js"></script>
	<script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js"></script>
	<script type="text/javascript">

	

	$(document).ready(function () {
		         
				 

		// Dialog
				$('#dialog').dialog({
					autoOpen: true,
					width: 309,					
					resizable: false,
					draggable: false,
					modals : true,
					open : function(event,ui){$(".ui-dialog-titlebar-close").hide();},
					buttons: {
						"Ok": function() {
							$(this).dialog("close");
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
		<div id="dialog" title="User Profile">
			<table>
			<tr><td>Kode</td><td>:</td><td><?php echo $row['Kode'] ?></td></tr>
			<tr><td>Nama</td><td>:</td><td><input type="text" name="nama" value="<?php echo $nama ?>"/></td></tr>			
			<tr>
			     <td>Status Kepegawaian</td>
				 <td>:</td>
				 <td>
			         <select id="format">
						<?php
						  if($row['Tstat']=="DTT")
						  {
						?>
						<option value="DTT" selected="selected">DTT - Dosen Tidak Tetap</option>
						<?php
						  }
						  else {
						 ?>
						 <option value="DTT">DTT - Dosen Tidak Tetap</option>
						<?php 
						  }
						?>
						<?php
						  if($row['Tstat']=="DTY")
						  {
						?>
						<option value="DTY" selected="selected">DTY - Dosen Tetap Yayasan</option>	
						<?php
						  }
						  else {
						 ?>
						 <option value="DTY">DTY - Dosen Tetap Yayasan</option>
						<?php 
						  }
						?>
						<?php
						  if($row['Tstat']=="LB")
						  {
						?>
						<option value="LB" selected="selected">LB - Dosen Luar Biasa</option>	
						<?php
						  }
						  else {
						 ?>
						 <option value="LB">LB - Dosen Luar Biasa</option>
						<?php 
						  }
						?>
					</select>
			     </td>
			</tr>
			<tr>
			     <td>Status Honor Dosen</td>
				 <td>:</td>
				 <td>
			         <select id="format">
						<?php
						  if($row['Hstat']=="DTT")
						  {
						?>
						<option value="DTT" selected="selected">DTT - Dosen Tidak Tetap</option>
						<?php
						  }
						  else {
						 ?>
						 <option value="DTT">DTT - Dosen Tidak Tetap</option>
						<?php 
						  }
						?>
						<?php
						  if($row['Hstat']=="DTY")
						  {
						?>
						<option value="DTY" selected="selected">DTY - Dosen Tetap Yayasan</option>	
						<?php
						  }
						  else {
						 ?>
						 <option value="DTY">DTY - Dosen Tetap Yayasan</option>
						<?php 
						  }
						?>
						<?php
						  if($row['Hstat']=="LB")
						  {
						?>
						<option value="LB" selected="selected">LB - Dosen Luar Biasa</option>	
						<?php
						  }
						  else {
						 ?>
						 <option value="LB">LB - Dosen Luar Biasa</option>
						<?php 
						  }
						?>
					</select>
			     </td>
			</tr>
			</table>
		</div>
   
</body>

</html>
	 <?php }} ?>