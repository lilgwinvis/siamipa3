<?php 
     require_once 'shared.php';
    
     
     $islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	 
	 
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=1");
		 exit();
	 }
	 else
	 {
        
		$user = $_SESSION['user'];
	    
		
		$idx = $_GET['idx'];
		$thn = $_GET['thn'];
				
		$pg_bfr = $_SESSION['pg_bfr'];
        switch($idx)
		{
		  case 1 : $title='Add Status Mahasiswa';break;
		  case 2 : $title='Edit Status Mahasiswa';break;
		  case 3 : $title='Delete Status Mahasiswa';break;
		}  

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title><?php echo $title ?></title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	<link type="text/css" href="../datatables/media/css/jquery.dataTables.css" rel="stylesheet" />
	<style type="text/css">
	        @import "../datatables/media/css/demo_page.css";
			@import "../datatables/media/css/demo_table.css";      
	.ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 9px; }
    </style>
	
	<script type="text/javascript" src="../js/jquery-1.8.0.min.js"></script>
	<script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js"></script>
	<script type="text/javascript" src="../datatables/media/js/jquery.dataTables.js"></script>
	<script type="text/javascript" src="../js/siamipa.js"></script>
	<script type="text/javascript" src="local_js/frm_stat_mhs_entry.js"></script>
	<script type="text/javascript">

	

	$(document).ready(function () {
		// Dialog
				$('#dialog').dialog({
					autoOpen: true,					
					width: 600,					 
					resizable: true,
					autoHeight: true,
					open: function(){
							$('#pgload').html("");	
							init_tb();
						  },
					buttons: {
						
					 <?php
					   if($idx==3)
					    {						
					  ?>		
						"Delete": function() {
							$(this).dialog("close");
							
							del( <?php echo "'$pg_bfr'" ?>,<?php echo $idx ?>,<?php echo $thn ?>);
						},
						
					  <?php
					    }else
					     {
					  ?>
                        "Save": function() {
							$(this).dialog("close");
							save( <?php echo "'$pg_bfr'" ?>,<?php echo $idx ?>,<?php echo $thn ?>);
							
							
							
						},
					  <?php
					    }
					  
					  ?>	
						
						"Cancel": function() {
							$(this).dialog("close");
							window.parent.pg_bfr(<?php echo '"'.$pg_bfr.'?thn='.$thn.'"' ?>);
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
		<div id="dialog" title="<?php echo $title ?>">
		  <?php 
		     
             $vw_stat_mhs = new vw_stat_mhs;
		     switch($idx)
		    {
		      case 1 : echo $vw_stat_mhs->frm_add($thn);break;
		      case 2 : echo $vw_stat_mhs->frm_edit($thn);break;
		      case 3 : echo $vw_stat_mhs->frm_del($thn);break;
		    }  
		  ?>
		</div>
   
</body>

</html>
<?php } ?>