<?php require_once 'shared.php'; 
     
	 $islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;	 
     
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=2");
		 exit();
	 }
	 else
	 {	
          
		  
		  $login = new login;
		if($login->logintime()){		  
		  header("Location: ../global_code/frm_login.php?idx=2&isout=1");
		  exit();	
		}else{ 
			 $nim = $_SESSION['user'];
			 
	 
          $vwmhs = new vwmhs; 
		  $vuser = new dt_mhs;
	      $data = $vuser->getData($nim);
	 
	      foreach ($data as $vrow) {
                 $row = $vrow;
          } // foreach
	 
	      $nama = str_replace(' ', '&nbsp;',$row['nmmhsmsmhs']); 
	      $sem = str_split($row['smawlmsmhs'], 4);	 
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
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
		         
				 $( "#datepicker" ).datepicker({
					  dateFormat: "yy-mm-dd"				  
					});
				 $( "#datepicker" ).datepicker( "setDate" , "<?php echo $row['tglhrmsmhs'] ?>" );	

		// Dialog
				$('#dialog').dialog({
					autoOpen: true,
					autoResize:false,
					width : 410,
					resizable: false,
					draggable: false,
					modals : true,
					open : function(event,ui){$(".ui-dialog-titlebar-close").hide();$('#pgload').html("");},
					buttons: {
						"Save": function() {
							$(this).dialog("close");
							$.ajax({
                                     type : "POST",
				                     url : "../global_code/entry_dt_mhs.php",
				                     cache: false,
				                     data : $("#entrymhs").serialize()+'&idx=2',									
									 success : function(data){					                            
												alert(data);															
				                               }
                                  });
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
   <div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
   <!-- ui-dialog -->
		<div id="dialog" title="User Profile">
			<?php
		     echo $vwmhs->viewprofile($nim,0);
		    ?> 
		</div>
   
</body>

</html>
	 <?php }} ?>