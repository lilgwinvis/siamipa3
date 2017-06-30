<?php require_once 'shared.php';

     $pdf_path=$_GET['pdf_path'];
	 $pg_bfr = isset($_SESSION['pg_bfr']) ? $_SESSION['pg_bfr'] : '';
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>PDF - Preview</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	
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
					width: 900,
					height :400,
					resizable: true,
					open: function(){
														
									
						  },
					buttons: {
						"Ok": function() {
							$(this).dialog("close");
							<?php
							 if(!empty($pg_bfr))
							 {
							 echo  'window.parent.pg_bfr("'.$pg_bfr.'")';
							 } 
							?>
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
		<div id="dialog" title="PDF - Preview">
		   <iframe src="<?php echo $pdf_path ?>" width='100%' height='100%'>
             <p>See our <a href="news.html">newsflashes</a>.</p>
           </iframe>
		</div>
   
</body>

</html>
<?php  ?>