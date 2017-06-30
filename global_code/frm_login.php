<?php 
     //session_start(); 	 
     require_once 'shared.php';
     
     	 
     $idx = $_GET['idx'];
     $isout = isset($_GET['isout']) ? $_GET['isout'] : 0;	
	 $islog=isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	 $user=isset($_SESSION['user']) ? $_SESSION['user'] : '';
	 
	
	 
	 if(($islog==1) and ($isout==1))
	 {
		 $login = new login;
         $login->user_logout();
		 
		 $_SESSION['islog']=0;		 
		 session_destroy();
	 }
	 
?>



<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Login</title>
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
		 <?php
		   echo "var idx=$idx;";
		 ?>
		 
		 var lati=0.0,longi=0.0;

		$.ajaxSetup({
			type : 'POST',
			headers : {
				"cache-control" : "no-cache"
			}
		});

		function success(position) {
			 lati=position.coords.latitude;
             longi=position.coords.longitude; 
		}
		
		
		function error(msg) {		

			// console.log(arguments);
		}

		if (navigator.geolocation) {
			navigator.geolocation.getCurrentPosition(success, error);
		} else {}

		$('#dialog').dialog({
			autoOpen : true,
			resizable : false,
			width : 240,
			height : 160,
			draggable : false,
			modals : true,
			open : function (event, ui) {
				$(".ui-dialog-titlebar-close").hide();
				$('#pgload').html("");
			},
			buttons : {
				"Login" : function () {
					$('#load').html("<font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' />");

					$.ajax({
						type : "POST",
						url : "../global_code/cek_login.php",
						cache : false,
						data : $("#form-login").serialize()+'&lati='+lati+'&longi='+longi,
						dataType : "text",
						success : function (data) {
							switch (parseInt(data)) {
							case 0:
								$('#load').html("<font size='1' color='red'>User Name atau Password Salah !!!</font>");
								break;
							case 1:
								$('#load').html("<font size='1' color='red'>Anda berhasil login</font>");
								$('#dialog').dialog('close');
								if (idx > 1) {
									window.parent.init_app();
								}
								break;
							case 2:
								$('#load').html("<font size='1' color='red'>Belum logout tidak bisa login !!!</font>");
								break;
							case 3:
								$('#load').html("<font size='1' color='red'>Hanya Satu User yang boleh aktif !!!</font>");
								break;
							default:
								$('#load').html("<font size='1' color='red'>Sistem Gagal !!!</font>");
							};
						}
					});

				},
				"Home" : function () {
					window.parent.home();
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
		<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
		<div id="dialog" title="Login" >
			<form name="form-login" id="form-login" method="post" action="cek_login.php">  
             <input type="hidden" name="idx" value="<?php echo $idx ?>">
			 
			 <table> 
			 <tr> <td>User Name</td> <td>:</td> <td><input type="text" name="user" /></td>  </tr>
             <tr> <td>Password</td> <td>:</td> <td><input type="password" name="pass" /></td> </tr>
			 
			 <tr> <td colspan="3"><div id="load"></div> </td></tr>
			 </table> 
			 
            </form>  
		</div>
        
</body>

</html>