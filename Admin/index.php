<?php
   require_once 'shared.php';
   
   $menu = array("Admin"=>array(0=>"Login List",1=>"Summary Executive",2=>"List File"),
                 "Skripsi"=>array(3=>"Bimbingan",4=>"Sidang"),
				 "Kuliah"=>array(5=>"Sebaran Matakuliah",6=>"Riwayat Sebaran Matakuliah",7=>"Jadwal Kuliah",8=>"Riwayat Jadwal Kuliah",9=>"Cetak Perangkat Kuliah",10=>"Rekap BAP dan DHMD"),
				 "Ujian"=>array(11=>"Cetak Perangkat Ujian",12=>"Cetak Kartu Ujian"),
				 "Nilai"=>array(13=>"Publish Nilai",14=>"Edit Publish Nilai"),
				 "EPSBED"=>array(15=>"Master Mahasiswa",16=>"Aktivitas Dosen",17=>"Nilai Mahasiswa",18=>"Nilai Mahasiswa Pindahan",19=>"Kurikulum",20=>"Aktivitas Mahasiswa",21=>"Mahasiswa Lulus/Cuti/Non-Aktif",22=>"Data Forlap"),
				 "Mahasiswa"=>array(23=>"Summary",24=>"Data Mahasiswa",25=>"Nilai Konversi",26=>"Status Mahasiswa",27=>"Hasil Studi",28=>"Transkip Nilai",29=>"Kartu Rencana Studi (KRS)",30=>"Riwayat Kartu Rencana Studi (KRS)"),
				 "Dosen"=>array(31=>"Data Dosen",32=>"Riwayat Mengajar",33=>"Nilai Belum Masuk",34=>"Kesediaan Mengajar",35=>"Riwayat Kesediaan Mengajar",36=>"Kuosioner"),
				 "Kurikulum"=>array(37=>"Matakuliah",38=>"Riwayat Kartu Rencana Studi (KRS)"),
				 "Keuangan"=>array(39=>"Kewajiban Perangkatan",40=>"Kewajiban Permahasiswa",41=>"Transaksi Keuangan Mahasiswa",42=>"Total Trans. Keuangan Mahasiswa",43=>"Rekap Trans. Keuangan Mahasiswa",44=>"Ajuan Keuangan",45=>"Laporan Keuangan"),
				 "Menu User"=>array(46=>"User Profile",47=>"Ganti Password",48=>"Logout"));
    
   
   
?>

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
  <meta name="generator" content="HTML Tidy for HTML5 (experimental) for Windows https://github.com/w3c/tidy-html5/tree/c63cc39" />
  <meta name="robots" content="noindex">
  <meta name="googlebot" content="noindex">
   
  <title>SIA FMIPA</title>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
  <link type="text/css" href="../css/style.css" rel="stylesheet" />
  <script type="text/javascript" src="../js/jquery.js">
</script>
  <script type="text/javascript" src="../js/jquery.ui.all.js">
</script>
  <script type="text/javascript" src="../js/jquery.layout.js">
</script>
  <script type="text/javascript" src="local_js/index.js">
</script>
  <script type="text/javascript">
//<![CDATA[

	var outerLayout;

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

		$.ajaxSetup({
			type : 'POST',
			headers : {
				"cache-control" : "no-cache"
			}
		});

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
		$("#mainFrame").attr("src", "../global_code/frm_login.php?idx=1");

	});
	//]]>
  </script>
  <link rel="stylesheet" type="text/css" href="../css/jquery-ui.css" />
  <style type="text/css">
/*<![CDATA[*/
                         /**
                         *      Basic Layout Theme
                         * 
                         *      This theme uses the default layout class-names for all classes
                         *      Add any 'custom class-names', from options: paneClass, resizerClass, togglerClass
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
                        
                        .ui-layout-center {
                        /*  *background-image:url('../img/logo_unibba.png');
                         *background-size: 48% 80%;
                         *background-repeat: no-repeat;
                         *background-position:center; */          
                        }       
                        
                        .ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 11px; }
                                
  /*]]>*/
  </style>
</head>

<body style="position: relative; height: 100%; overflow: hidden; margin: 0px; padding: 0px; border: medium none;" class=
"ui-layout-container">
  <?php echo "<link rel=\"icon\" href=\"../img/unibba.ico\" type=\"image/x-icon\">"; ?>

  <div class="ui-layout-north ui-widget-content ui-layout-pane ui-layout-pane-north" style=
  "display: block; position: absolute; margin: 0px; top: 0px; bottom: auto; left: 0px; right: 0px; width: auto; z-index: 0; height: 100%; visibility: visible;">
  <center>
      <h3><span style="color:gold">Sistem Informasi Akademik</span></h3>

      <h3><span style="color:gold">Fakultas Matematika dan Ilmu Pengetahuan Alam</span></h3>
    </center>
  </div>

  <div class="ui-layout-west ui-layout-pane ui-layout-pane-west" style=
  "display: block; position: absolute; margin: 0px; left: 0px; right: auto; top: 0px; bottom: 0px; height: 100%; z-index: 0; width: 100%; visibility: visible;">
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
  <!--/><div class="ui-layout-center ui-layout-pane ui-layout-pane-center" style="display: block; position: absolute; margin: 0px; left: 306px; right: 306px; top: 52px; bottom: 48px; height: 186px; width: 666px; z-index: 0; visibility: visible;">-->

  <div class="ui-layout-center ui-layout-pane ui-layout-pane-center" style=
  "display: block; position: absolute; margin: 0px; left: 0px; right: 0px; top: 0px; bottom: 0px; height: 0px; width: 100%; z-index: 0; visibility: visible;">
  <iframe style=
  "position: absolute; margin: 0px; left: 0px; right: 0px; top: 0px; bottom: 0px; height: 100%; width: 100%; z-index: 0; display: block; visibility: visible;"
    id="mainFrame" name="mainFrame" src="#" frameborder="0" height="100%" scrolling="auto" width="100%"></iframe>
  </div><?php         
                  
                  
     ?>
	<script type="text/javascript"> 
		
	</script> 
</body>
</html>
