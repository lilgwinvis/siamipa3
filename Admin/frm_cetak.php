<?php require_once 'shared.php'; 
     
	 
	 $islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	 $idx = $_GET['idx'];
	 
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=".$idx);
		 exit();
	 }
	 else
	 {	
	   $login = new login;
		if($login->logintime()){		  
		  header("Location: ../global_code/frm_login.php?idx=$idx&isout=1");
		  exit();	
		}else{  
		
		$idx = $_GET['ctk_idx'];
        
	    
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>
	  <?php
	      switch($idx)
          {		  
    		case 1 : $ttl="Cetak Perangkat Kuliah"; break;
			case 2 : $ttl="Cetak Perangkat Ujian"; break;
			case 3 : $ttl="Cetak Kartu Ujian"; break;
		  }
            echo $ttl;		  
	   ?>
	</title>
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
	<script type="text/javascript" src="../js/siamipa.js"></script>
	<script type="text/javascript" src="local_js/frm_cetak.js"></script>
	<script type="text/javascript">
	    
	       
           var oTable;
		   <?php echo "var idx=$idx; ";?>
		    
			

		   $(document).ready(function () {
		   	
			$('#dialog').dialog({
		   		autoOpen : true,
		   		autoWidth : true,
		   		autoHeight : true,
		   		minWidth : 750,
		   		open : function () {
		   			if (idx == 1 || idx == 2) {
		   				oTable=init_tb('box-table-a', 1);
		   			} else {
		   				oTable=init_tb('krs_mhs', 3);
		   			}
		   		},
		   		buttons : {
		   			"Ok" : function () {
		   				$(this).dialog("close");
		   			}
		   		}
		   	});

		   	binding(oTable,idx);
		   	

		   });
		
		
		
	</script>
</head>

<body>
   <?php echo "<link rel=\"icon\" href=\"../img/unibba.ico\" type=\"image/x-icon\">"; ?>
   <div id="dialog" title="<?php echo $ttl ?>">
      <fieldset> 
	         <legend>Aksi</legend>	
			 <?php
			     $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "Aksi","width"=>"0%"));
				 $tbl->addRow();
				 switch($idx){
				   case 1 : 
							$tbl->addCell("<button type='submit' id='DHMD'>Cetak Daftar Hadir</button><button type='submit'  id='BAP'>Cetak BAP</button><button type='submit' id='CBAP'>Cetak Cover BAP</button><button type='submit' id='Honor4'>Honor Dosen 4 Per.</button><button type='submit' id='Honor2'>Honor Dosen 2 Per. </button>", null, 'data');														
				            break;
				   case 2 : $tbl->addCell("<button type='submit' id='Absen_UTS'>Cetak Absen UTS</button><button type='submit' id='Absen_UAS'>Cetak Absen UAS</button><button type='submit'  id='DPNA'>Cetak DPNA</button><button type='submit'  id='BAU'>Berita Acara Ujian</button><button type='submit'  id='label'>Label Amplop</button><button type='submit'  id='pakasi'>Pakasi Ujian</button>", null, 'data');
							break;
				   case 3 : $tbl->addCell("<button type='submit' id='Kartu_UTS'>Cetak Kartu UTS</button><button type='submit'  id='Kartu_UAS'>Cetak Kartu UAS</button>", null, 'data');
							break;
				 }
				 echo $tbl->display();
			 ?>
	  </fieldset> 
     <fieldset> 
	         <legend>
			        <?php 
 					  switch($idx){					   
					   case 3 : $ttl = "Data Mahasiswa";break; 
					   default :
					     $ttl = "Data Matakuliah dan Dosen";break;
					  }
					  echo $ttl;				
					?>  
			 </legend>	
			 <?php
				    $vwcetak = new vwcetak;
	               if($idx==1 or $idx==2){
     				   echo $vwcetak->build_cetak_klh();
					} else{
                       echo $vwcetak->build_cetak_krs_mhs(); 
                    }					
			 ?>		
	  </fieldset> 
     	  
   </div> 
</body>

</html>
	 <?php }} ?>	