<?php
   require_once 'shared.php';
   
   $menu = array("Nilai"=>array(0=>"Summary",1=>"Kartu Hasil Studi (KHS)",2=>"Transkip Nilai"),
                 "Kartu Rencana Studi (KRS)"=>array(3=>"Kartu Rencana Studi (KRS)"),
				 "Kurikulum"=>array(4=>"Matakuliah"),
				 "Informasi Akademik"=>array(5=>"Sebaran Matakuliah",6=>"Jadwal Kuliah"),
				 "Keuangan"=>array(7=>"Transaksi Keuangan Mahasiswa",8=>"Total Trans. Keuangan Mahasiswa"),
				 "Menu User"=>array(9=>"User Profile",10=>"Ganti Password",11=>"Logout"));
   
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">

<head>
    <title>SIA FMIPA</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <meta name="robots" content="noindex">
    <meta name="googlebot" content="noindex">
	<script type="text/javascript" src="../js/jquery.js"></script>
	<script type="text/javascript" src="../js/jquery.ui.all.js"></script>
	<script type="text/javascript" src="../js/jquery.layout.js"></script>	
    <script type="text/javascript" src="local_js/index.js"></script>
	
    <script type="text/javascript">

	var outerLayout;

	function init_app() {

		window.frames['mainFrame'].location.replace("../mhs_app/frm_profile.php");
	}

	function pg_bfr(txt) {
		window.frames['mainFrame'].location.replace(txt);
	}

	function buka_dlg(txt) {
		window.frames['mainFrame'].location.replace(txt);
	}
	function home() {
		window.location.href = "http://www.fmipa-unibba.org/";

	}
	
	
	

	$(document).ready(function () {
		outerLayout = $('body').layout({
				minSize : 100 // ALL panes
			,
				west__size : 300,
				north__size : 120,
				useStateCookie : true,
				north__resizable : false,
				north__closable : false,
				west__resizable : false

			});

		$("#accordion").accordion({
			header : "h3",
			fillSpace : true
		});
	});

	</script>
	
	<link rel="stylesheet" type="text/css" href="../css/jquery-ui.css" />
	<style type="text/css">
	 /**
	 *	Basic Layout Theme
	 * 
	 *	This theme uses the default layout class-names for all classes
	 *	Add any 'custom class-names', from options: paneClass, resizerClass, togglerClass
	 */

	
	.ui-layout-pane {  
		background: #FFF; 
		border: 1px solid #BBB; 
		padding: 10px; 
		overflow: auto;
	} 

	.ui-layout-resizer {  
		background: #DDD; 
	} 

	.ui-layout-toggler { 
		background: #AAA; 
	}
	
	 
    .ui-layout-north {
      background-image:url('../img/fmipa.jpg');
	  background-size: 100% 100%;
	  background-repeat: no-repeat;
	}  	
    
	/*.ui-layout-center {
     *background-image:url('../img/logo_unibba.png');
	 *background-size: 48% 80%;
	 *background-repeat: no-repeat;
	 *background-position:center;	  
	}*/	
	
	.ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 11px; }
		
	</style>

	
</head>
<body style="position: relative; height: 100%; overflow: hidden; margin: 0px; padding: 0px; border: medium none;" class="ui-layout-container">
    <?php echo "<link rel=\"icon\" href=\"../img/unibba.ico\" type=\"image/x-icon\">"; ?>
	
	<div class="ui-layout-north ui-widget-content ui-layout-pane ui-layout-pane-north" style="display: block; position: absolute; margin: 0px; top: 0px; bottom: auto; left: 0px; right: 0px; width: auto; z-index: 0; height: 100%; visibility: visible;">
	 <center> <span style="color:gold">
	  <h3>Sistem Informasi Akademik<h3> 
	  <h3>Fakultas Matematika dan Ilmu Pengetahuan Alam</h3>
	   
	  </span>
     </center>
     	 
    </div>
	<div class="ui-layout-west ui-layout-pane ui-layout-pane-west" style="display: block; position: absolute; margin: 0px; left: 0px; right: auto; top: 0px; bottom: 0px; height: 100%; z-index: 0; width: 100%; visibility: visible;"">
	  <div role="tablist" class="ui-accordion ui-widget ui-helper-reset ui-accordion-icons" id="accordion">
				<?php
				$tabindex=0;
				$stat='true';
				$icon = 'ui-icon ui-icon-triangle-1-s';
				$ui1 = 'ui-accordion-content-active';
				$ui2 = 'ui-state-active ui-corner-top';
				$ui3 = '';
				foreach($menu as $item=>$arr){ 
					?>
	  <div>				
				<h3 tabindex="<?php echo $tabindex; ?>" aria-selected="<?php echo $stat; ?>" aria-expanded="<?php echo $stat; ?>" role="tab" class="ui-accordion-header ui-helper-reset ui-state-default <?php echo $ui2; ?>"><span class="<?php echo $icon; ?>"></span><a tabindex="<?php echo $tabindex; ?>" href="#"><?php echo $item; ?></a></h3>
				<div role="tabpanel" style="height: auto; <?php echo $ui3; ?>" class="ui-accordion-content ui-helper-reset ui-widget-content ui-corner-bottom <?php echo $ui1; ?>">
				 <ul style="font-color: #0000FF; ">
              <?php           
			     foreach($arr as $idx=>$nm){
			  ?>
			    <li>
				  <a target="mainFrame" href="javascript:void(0);" onclick="menu(<?php echo $idx; ?>)" ><?php echo $nm; ?></a>
				</li>
			   <?php           
		            $icon = 'ui-icon ui-icon-triangle-1-e';
					$ui1 = '';
					$ui2 = 'ui-corner-all';
					$ui3 = 'display: none;';
					$stat='false';
					$tabindex++;
				  }
			   ?>            
          </ul>
        </div>
      </div>
     <?php
	   }
	 ?> 			
		</div>	
		
    </div>
	<div class="ui-layout-center ui-layout-pane ui-layout-pane-center" style="display: block; position: absolute; margin: 0px; left: 0px; right: 0px; top: 0px; bottom: 0px; height: 0px; width: 100%; z-index: 0; visibility: visible;">
    
	<iframe style="position: absolute; margin: 0px; left: 0px; right: 0px; top: 0px; bottom: 0px; height: 100%; width: 100%; z-index: 0; display: block; visibility: visible;" id="mainFrame" name="mainFrame"  src="../global_code/frm_login.php?idx=2" frameborder="0" height="100%" scrolling="auto" width="100%">
	
	</iframe>  
	
	</div> 

</body>
</html>