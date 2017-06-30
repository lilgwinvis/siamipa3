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
    <title>Summary Executive</title>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	<style type="text/css">
	.ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 11px; }
	</style>
	<script type="text/javascript" src="../js/jquery-1.8.0.min.js"></script>
	<script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js"></script>
	<script type="text/javascript" src="../js/siamipa.js"></script>
	<script type="text/javascript" src="local_js/frm_sum_exec.js"></script>
	<script type="text/javascript" src="../canvasjs/jquery.canvasjs.min.js"></script>
	 <script type = "text/javascript">

		$(document).ready(function () {
			// Dialog


			$('#dialog').dialog({
				autoOpen : true,
				width : 1000,
				open : function () {
					$('#pgload').html("");
					fgambarchart("chartContainer", 1);
					fgambarchart("chartContainer1", 2);
					fgambarchart("chartContainer2", 3);
					fgambarchart1("chartContainer3", 4);
					fgambarchart1("chartContainer4", 5);
					fgambarchart1("chartContainer5", 6);

					$("#tabs").tabs();

				},
				buttons : {
					"Ok" : function () {
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
   <div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
   <!-- ui-dialog -->
		<div id="dialog" title="Summary Executive">
		  <div id="tabs">
              <ul>
                 <li><a href='#tabs-1'>Rekap Status Mahasiswa</a></li>
                 <li><a href='#tabs-2'>Rekap Keuangan</a></li>
              </ul>		 
              <div id='tabs-1'>			   
			    <fieldset>
				 <div id="chartContainer" style="height: 300px; width: 100%"><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
			    </fieldset>
				<fieldset>
				<div id="chartContainer1" style="height: 300px; width: 100%"><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
			    </fieldset>
				<fieldset>
				<div id="chartContainer2" style="height: 300px; width: 100%"><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
	            </fieldset> 		 
			 </div>
			 <div id='tabs-2'>			     
				 <fieldset>  
				  <div id="chartContainer3" style="height: 300px; width: 100%"><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>			    
				  </fieldset>
				<fieldset>
				  <div id="chartContainer4" style="height: 300px; width: 100%"><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
			      </fieldset>
				<fieldset>
				  <div id="chartContainer5" style="height: 300px; width: 100%"><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
				</fieldset>  
			 </div>
			 
		  </div>	
		</div>
        
</body>

</html>
	 <?php }} ?>