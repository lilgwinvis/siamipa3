<?php require_once 'shared.php'; 
     
     
	 $islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	 
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=1");
		 exit();
	 }
	 else
	 {	 
	    $user = $_SESSION['user'];
	    
	    $pg_bfr = $_SESSION['pg_bfr'];
		
		
		 $thn = $_GET['thn'];
		 $sem = $_GET['sem'];
		 $rn=$_GET['rn'];
		 $kelas=$_GET['kelas'];		 
		 $kdkmk=$_GET['kdkmk'];
		 
		 $_SESSION['pg_bfr1']="../Admin/frm_entry_bap_dhmd.php?thn=".$thn.'&kdkmk='.$kdkmk.'&rn='.$rn.'&kelas='.$kelas.'&sem='.$sem;
		
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Ganti Password</title>
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
	<script type="text/javascript" src="../js/siamipa.js"></script>
	<script type="text/javascript" src="local_js/frm_entry_bap_dhmd.js"></script>
	<script type="text/javascript">

	

	$(document).ready(function () {
		// Dialog
				$('#dialog').dialog({
					autoOpen: true,
					width: 600,
					open: function(){
							$('#pgload').html("");
							init_tb();
						  },
					buttons: {
						"Ok": function() {
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
		<div id="dialog" title="Entry BAP dan DHMD">
			<?php 
		      $vwentrybapdhmd = new vwentrybapdhmd;
		      echo $vwentrybapdhmd->entrybapdhmd($thn,$kdkmk,$sem,$kelas,$rn); 
		    ?> 
		</div>
   
</body>

</html>
<?php } ?>