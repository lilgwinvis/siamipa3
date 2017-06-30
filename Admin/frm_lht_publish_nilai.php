<?php  require_once 'shared.php'; 
      
	
	$islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	 
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=1");
		 exit();
	 }
	 else
	 {	 
	 
	
	    
     $thnsms = $_GET['thsmstrnlm'];
	 $kdkmk = isset($_GET['kdkmktrnlm']) ? $_GET['kdkmktrnlm'] : " ";
	 $kelas = $_GET['kelastrnlm'];
	 
	 
	 $kode = isset($_SESSION['kode']) ? $_SESSION['kode'] : "";
	 
	 $pg_bfr = $_SESSION['pg_bfr'];
	 
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Lihat Nilai</title>
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

	

	$(document).ready(function () {
		// Dialog
				$('#dialog').dialog({
					autoOpen: true,
					width : 700,
					autoHeight:true, 
					resizable: true,
					open: function(){			
						$('#box-table-a').dataTable();
					
					},
					buttons: {
						"Ok": function() {
							$(this).dialog("close");
							window.parent.pg_bfr(<?php echo '"'.$pg_bfr.'"' ?>);
						}
					}
				});

 	});
    
	function publish_nilai(nim,hm,am)
	{
      <?php	
	   echo "var thnsms = ".$thnsms.";\n";
	   echo "var kdkmk = '". $kdkmk."';\n";
	   echo "var kelas = '". $kelas."';\n";
	  ?>
	  $("#data").html("<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>");
	                       $.ajax({
                                     type : "POST",
				                     url : "local_class/publish_nilai.php",
				                     cache: false,
				                     data :"thnsms="+thnsms+"&kdkmk="+kdkmk+"&kelas="+kelas+"&nim="+nim+"&hm="+hm+"&am="+am,
									 success : function(data){
												$("#data").html(data);
                                                $('#box-table-a').dataTable();												
				                               }
                                  });
	}
	
	</script>
	
  <style type="text/css">
     
  </style>
</head>

<body>
   <!-- ui-dialog -->
		<?php
		  
		            $dt_mtk = new dt_mtk;
									 
     				$sem = str_split($thnsms, 4);			
					 
					if($sem[1]=="1"){
					    $tmp = $dt_mtk->getnmmtk($kdkmk)." (".$kdkmk.") Kelas ".$kelas." Semester Ganjil ".$sem[0];
						
					 }else{
					   if($sem[1]=="2"){
					    $tmp = $dt_mtk->getnmmtk($kdkmk)." (".$kdkmk.") Kelas ".$kelas." Semester Genap ".$sem[0];
						
						}
					 }
					 
					 
					 
					 
             ?>  		
		<div id="dialog" title="<?php echo $tmp  ?>">
			<?php 
		      $vw_publish_nilai = new vw_publish_nilai;
		      echo $vw_publish_nilai->lht_mhs($kdkmk,$kelas,$thnsms); 
		    ?>
		</div>
   
</body>

</html>
<?php } ?>