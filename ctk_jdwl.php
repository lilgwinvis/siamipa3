<?php 

    include_once("sia/global_class/vwjdwlklh.class.inc");
	
	$vwjdwlklh = new vwjdwlklh;
	$pdf_path = $vwjdwlklh->ctk_jdwl_topdf();	
    //header("Location: ".$pdf_path); 
?>
 <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>
	  Cetak Jadwal Kuliah
	</title>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<style type="text/css">
       html {overflow: auto;}
       html, body, div, iframe {margin: 0px; padding: 0px; height: 100%; border: none;}
       iframe {display: block; width: 100%; border: none; overflow-y: auto; overflow-x: hidden;}
</style> 
</head>

<body>
   <?php  echo "<link rel=\"icon\" href=\"http://sia.fmipa-unibba.org/img/unibba.ico\" type=\"image/x-icon\">"; ?>
   
    <iframe src="<?php echo $pdf_path; ?>" frameborder="0" marginheight="0" marginwidth="0" width="100%" height="100%" scrolling="auto">
             <p>See our <a href="news.html">newsflashes</a>.</p>
     </iframe>
   
</body>

</html> 
<?php ?>	