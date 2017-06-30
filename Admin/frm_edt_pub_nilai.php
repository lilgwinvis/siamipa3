<?php require_once 'shared.php';
     
     $islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=1");
		 exit();
	 }
	 else
	 {	 
	     $login = new login;
		if($login->logintime()){		  
		  header("Location: ../global_code/frm_login.php?idx=1&isout=1");
		  exit();	
		}else{ 
	    
         
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Kartu Hasil Studi (KHS)</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	<!--<link type="text/css" href="../css/style.css" rel="stylesheet" />-->
	<!--<link type="text/css" href="../datatables/media/css/jquery.dataTables.css" rel="stylesheet" />-->
	<style type="text/css">
            @import "../datatables/media/css/demo_page.css";
			@import "../datatables/media/css/demo_table.css";
			div.giveHeight {
				/* Stop the controls at the bottom bouncing around */
				//min-height: 380px;
			}
	  .ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 9px; }
     </style>
	<script type="text/javascript" src="../js/jquery-1.8.0.min.js"></script>
	<script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js"></script>
	<script type="text/javascript" src="../datatables/media/js/jquery.dataTables.js"></script> 
	<script type="text/javascript" src="../js/siamipa.js"></script>
	<script type="text/javascript" src="local_js/frm_edt_pub_nilai.js"></script>	
	<script type="text/javascript">


	var oTable;

	$(document).ready(function () {
		// Dialog
		$.ajaxSetup({
			type : 'POST',
			headers : {
				"cache-control" : "no-cache"
			}
		});

		$('#dialog').dialog({
			autoOpen : true,
			width : 700,
			autoHeight : true,
			resizable : true,
			open : function () {
				$('#pgload').html("");
				oTable = init_tb();

			},

			buttons : {
				"Ok" : function () {
					$(this).dialog("close");
				}
			}
		});

		$("#Angkatan").change(function () {
			var thnmsmshs = $("#Angkatan").val();
			cmbangk_change(thnmsmshs);

		});

		$("#kls").change(function () {
			var thnmsmshs = $("#Angkatan").val();
			var kelas = $("#kls").val();
			cmbkelas_change(thnmsmshs, kelas);

		});

		$("#filter").click(function () {
			var nim = $("#Mhs").val();
			var tmp = $('#Mhs').find('option:selected').text();
			$("#hsl_filter").html("Hasil Filter : " + tmp);
			$("#data").html("<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>");
			filter(nim);

		});
	});

	function save(nim) {
		$("#data").html("<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>");
		btn_save(oTable, nim);

	}

	</script>
	
  <style type="text/css">
     
  </style>
</head>

<body>
   <?php echo "<link rel=\"icon\" href=\"../img/unibba.ico\" type=\"image/x-icon\">"; ?>
   <div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
   <!-- ui-dialog -->
	
		<div id="dialog" title="Edit Publish Nilai">	
				  <?php
				    $vwtrnlp_trnlm=new vw_trnlp_trnlm;
					echo $vwtrnlp_trnlm->filter_mhs();				 
        		?>
		</div>
   
</body>

</html>
	 <?php }} ?> 