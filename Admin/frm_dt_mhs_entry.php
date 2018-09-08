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
		$pg_bfr = $_SESSION['pg_bfr'];
		$nim = isset($_GET['nim']) ? $_GET['nim']:"";
		
		$vwmhs = new vwmhs;  
		
		
		
		switch($idx)
		{
		  case 1 : $title='Add Data Mahasiswa';break;
		  case 2 : $title='Edit Data Mahasiswa';
		           $dtmhs = new dt_mhs;
				   $data = $dtmhs->getData($nim);
	               foreach ($data as $vrow) {
                      $row = $vrow;
                   } // foreach
		           break;
		  case 3 : $title='Delete Data Mahasiswa';break;
		}
		
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title><?php echo $title  ?></title>
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
	<script type="text/javascript">

	

	$(document).ready(function () {
		// Dialog
		      var oTable;
			    
				$( "#datepicker" ).datepicker({
					  dateFormat: "yyyy-mm-dd"				  
					});
			   <?php
			     if($idx==2)
				 {
			   ?>	
           		$( "#datepicker" ).datepicker( "setDate" , "<?php echo $row['tglhrmsmhs'] ?>" );
				<?php
			     }
			   ?>	
				$('#dialog').dialog({
					autoOpen: true,
					<?php 
					 if($idx==3)
					 {
					?>
					width: 450,
					 <?php 
					 } else {
					?>	
					  width: 500,
					 <?php 
					   }
					 ?>	
					resizable: true,
					autoHeight: true,
					open: function(){
							$('#pgload').html("");
							<?php 
							 if($idx==3)
							 {
							?>
							oTable=$("#lst_mhs").dataTable();	
                            <?php 
							  }
							?>							
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
				                     url : "../global_code/entry_dt_mhs.php",
				                     cache: false,
				                     data :$(":input",oTable.fnGetNodes()).serialize()+'&idx=<?php echo $idx ?>',									
									 success : function(data){					                            
												alert(data);
												window.parent.pg_bfr(<?php echo '"'.$pg_bfr.'"' ?>);			
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
				                     url : "../global_code/entry_dt_mhs.php",
				                     cache: false,
				                     data : $("#entrymhs").serialize()+'&idx=<?php echo $idx ?>',									
									 success : function(data){					                            
												alert(data);
												window.parent.pg_bfr(<?php echo '"'.$pg_bfr.'"' ?>);			
				                               }
                                  });
							
							
						},
					 <?php
					    }
					  
					  ?>	
						
						
						"Cancel": function() {
							$(this).dialog("close");
							window.parent.pg_bfr(<?php echo '"'.$pg_bfr.'"' ?>);
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
		<div id="dialog" title="<?php echo $title  ?>">
		  <?php
		   switch($idx)
		   {
		   case 1 : echo $vwmhs->isiprofile();break;
		   case 2 : echo $vwmhs->viewprofile($nim);break;
		   case 3 : echo $vwmhs->delprofile();break;
		   }

		  ?> 
		   
		   
		</div>
   
</body>

</html>


<?php } ?>