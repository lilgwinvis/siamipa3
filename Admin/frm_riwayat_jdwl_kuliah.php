<?php require_once 'shared.php';
     
	 
	 $islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	 $idx = $_GET['idx'];
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=".$idx);
		 exit();
	 }
	 else
	 {	
		$login = new login;
		if($login->logintime()){		  
		  header("Location: ../global_code/frm_login.php?idx=$idx&isout=1");
		  exit();	
		}else{ 
	    
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Riwayat Jadwal Kuliah</title>
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
    
	var asInitVals = new Array();
	var oTable;
	var oTable1;

	var hari = new Array();
	hari['1'] = 'Senin';
	hari['2'] = 'Selasa';
	hari['3'] = 'Rabu';
	hari['4'] = 'Kamis';
	hari['5'] = 'Jumat';
	hari['6'] = 'Sabtu';
	hari['7'] = 'Minggu';
	hari[''] = '';

	function init_tb() {

		oTable = $('#box-table-a').dataTable({
				"aoColumnDefs" : [{
						"fnRender" : function (oObj, sVal) {
							return hari[sVal];
						},
						"aTargets" : [0]
					}
				]
			});
		$("tfoot input").keyup(function () {
			/* Filter on the column (the index) of this element */
			oTable.fnFilter(this.value, $("tfoot input").index(this));
		});

		/*
		 * Support functions to provide a little bit of 'user friendlyness' to the textboxes in
		 * the footer
		 */
		$("tfoot input").each(function (i) {
			asInitVals[i] = this.value;
		});

		$("tfoot input").focus(function () {
			if (this.className == "search_init") {
				this.className = "";
				this.value = "";
			}
		});

		$("tfoot input").blur(function (i) {
			if (this.value == "") {
				this.className = "search_init";
				this.value = asInitVals[$("tfoot input").index(this)];
			}
		});

	}
	
	
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
			autoWidth : true,
			autoHeight : true,
			minWidth : 925,
			open : function () {
				$('#pgload').html("");
				init_tb();
			},
			buttons : {
				"Ok" : function () {
					$(this).dialog("close");
				}
			}
		});

		$("#filter").click(function () {
			var thn = $("#semester").val();
			var tmp = $('#semester').find('option:selected').text();
			$("#hsl_filter").html("Jadwal Kuliah : " + tmp);
			$("#data").html("<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>");
			$.ajax({
				type : "POST",
				url : "../global_class/chg_conten.php",
				cache : false,
				data : "thn=" + thn + "&idx=15",
				success : function (data) {
					$("#data").html(data);
					init_tb();
				}
			});
		});

	});

	</script>
	
  <style type="text/css">
     
  </style>
</head>

<body>
   <?php echo "<link rel=\"icon\" href=\"../img/unibba.ico\" type=\"image/x-icon\">"; ?>
   <!-- ui-dialog -->
		<div id="dialog" title="Riwayat Jadwal Kuliah">
			
		      <?php 
		        $vwjdwlklh = new vwjdwlklh;
		        echo $vwjdwlklh->sem_filter();               				
		      ?> 
		 
			 
		</div>
   <div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
</body>

</html>
	 <?php } }?>