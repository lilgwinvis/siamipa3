<?php require_once 'shared.php'; 
     
        
	 $islog = $_SESSION['islog'];
	 $pg_bfr = $_SESSION['pg_bfr'];
	 if($islog==0)
	 {
		 include("../global_code/frm_login.php");
	 }
	 else
	 {	  require_once 'shared.php';
	      $user = $_SESSION['user'];
	      
		  $nim = $_GET['nim'];
		  $build_krs = new vw_krs;
		   
          $vbuild_krs = new dt_krs;
          $data = $vbuild_krs->buildkrs($nim,1);
		$kode_matkul=array();
		if(!empty($data)){ 
		 foreach ($data as $row) {	
		
		      $kode_matkul[] = $row['kdkmktbkmk'];
			  $nama_matkul[] = $row['nakmktbkmk'];
			  $sks[] = $row['sksmktbkmk'];
			  $sem[] = $row['semestbkmk'];
              $wp[] = $row['wp'];	
		      $cek[] = $row['cek'];
		}
		}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Kartu Rencana Studi (KRS): Ambil Matakuliah Baru</title>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
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
	<script type="text/javascript" src="local_js/frm_krs_mtk_baru.js"></script>
	<script type="text/javascript">

	   <?php
		echo "var jum = 0;\n";
		echo "var jumlah = ".count($kode_matkul).";\n";
		echo "var sks = new Array();\n";
		//mengambil sks matakuliah dan memasukkan ke array javascript
		for($j=0; $j<count($kode_matkul); $j++){		    
			echo "sks['".$kode_matkul[$j]."'] = ".$sks[$j].";\n";
		}
	   ?>
	   
	 var oTable; 
	
	$(document).ready(function () {
	   $('#dialog').dialog({
					autoOpen: true,
					width: 650,
					open: function(){					       
						    var vmydatatable = new mydatatable;
							vmydatatable.id = 'lst_mtk';
							vmydatatable.template = 1;
							vmydatatable.title = 1;
							vmydatatable.settemplate();
							vmydatatable.footerfilter();
							oTable=vmydatatable.create();
						  },
					buttons: {
					  <?php
					   if(!empty($data)){	
					  ?> 	
						"Save": function() {
							$('#dialog').dialog("close");
							save(oTable,<?php echo '"'.$pg_bfr.'"' ?>);
						},
					 <?php 
					   }	
					  ?>
						"Cancel": function() {
							$('#dialog').dialog("close");
							window.parent.pg_bfr(<?php echo '"'.$pg_bfr.'"' ?>);
						}
					}
					});
					
					$('#mk').live('click',function() {
						 if(this.checked){
							 jum += sks[this.value];
						 } else {
							 jum -= sks[this.value];
						 }
						 document.getElementById("jsks").value = jum;
					});
	});

	</script>
</head>

<body>
    <?php echo "<link rel=\"icon\" href=\"../img/unibba.ico\" type=\"image/x-icon\">"; ?>	
   <!-- ui-dialog -->
	<div id="dialog" title="Kartu Rencana Studi &#40KRS&#41 : Ambil Matakuliah Baru ">	
	    <?php echo $build_krs->build_krs($nim,1) ?>
	</div>	
</body>

</html>	
<?php } ?>