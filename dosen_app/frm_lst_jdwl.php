<?php session_start(); 
     
     	 
     
	 $islog = $_SESSION['islog'];
	 
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=3");
		 exit();
	 }
	 else
	 {	 $kode = $_SESSION['user'];
	 
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>List Jadwal Mengajar</title>
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
					width: 600,
					buttons: {
						"Ok": function() {
							$(this).dialog("close");
						},
						"Cancel": function() {
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
		<div id="dialog" title="List Jadwal Mengajar">
			<p>On Construction !!!</p>
		</div>
   
</body>

</html>
<?php } ?>