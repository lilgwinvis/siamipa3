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
		$kls = $_GET['kls'];
		$kd = isset($_GET['kd']) ? $_GET['kd']: "";
		
		
		$pg_bfr = $_SESSION['pg_bfr'];
        switch($idx)
		{
		  case 1 : $title='Add Kewajiban Perangkatan';break;
		  case 2 : $title='Edit Kewajiban Perangkatan';break;
		  case 3 : $title='Delete Kewajiban Perangkatan';break;
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
	       
	.ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 9px; }
    </style>
	
	<script type="text/javascript" src="../js/jquery-1.8.0.min.js"></script>
	<script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js"></script>
	<script type="text/javascript" src="../datatables/media/js/jquery.dataTables.js"></script>
	<script type="text/javascript">

	

	$(document).ready(function () {
		// Dialog
		        var oTable;
				$('#dialog').dialog({
					autoOpen: true,
					<?php 
					 if($idx==3)
					 {
					?>
					width: 600,
					 <?php 
					 } else {
					?>	
					  width: 250,
					 <?php 
					   }
					 ?>	
					resizable: true,
					autoHeight: true,
					open: function(){
							$('#pgload').html("");								
							oTable=$('#lst_trans').dataTable();		
						  },
					buttons: {
						
					 <?php
					   if($idx==3)
					    {						
					  ?>		
						"Delete": function() {
							$(this).dialog("close");
							$.ajax({
                                     type : "POST",
				                     url : "../global_code/entry_dt_keuangk.php",
				                     cache: false,
				                     data :$(":input",oTable.fnGetNodes()).serialize()+'&idx=<?php echo $idx ?>&thn=<?php echo $thn ?>&kls=<?php echo $kls ?>',									
									 success : function(data){					                            
												alert(data);
												window.parent.pg_bfr(<?php echo '"'.$pg_bfr.'?thn='.$thn.'&kls='.$kls.'"' ?>);			
				                               }
                                  });
						},
						
					  <?php
					    }else
					     {
					  ?>
                        "Save": function() {
							$(this).dialog("close");
							$.ajax({
                                     type : "POST",
				                     url : "../global_code/entry_dt_keuangk.php",
				                     cache: false,
				                     data : $("#entrykeuangk").serialize()+'&idx=<?php echo $idx ?>',
									 success : function(data){					                            
												alert(data);
												window.parent.pg_bfr(<?php echo '"'.$pg_bfr.'?thn='.$thn.'&kls='.$kls.'"' ?>);			
				                               }
                                  });
							
							
							
							
						},
					  <?php
					    }
					  
					  ?>	
						
						"Cancel": function() {
							$(this).dialog("close");
							window.parent.pg_bfr(<?php echo '"'.$pg_bfr.'?thn='.$thn.'&kls='.$kls.'"' ?>);
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
		     
             $vwkeuangk = new vwkeuangk;
		     switch($idx)
		    {
		      case 1 : echo $vwkeuangk->frm_add($thn,$kls);break;
		      case 2 : echo $vwkeuangk->frm_edit($thn,$kls,$kd);break;
		      case 3 : echo $vwkeuangk->frm_del($thn,$kls);break;
		    }  
		  ?>
		</div>
   
</body>

</html>
<?php } ?>