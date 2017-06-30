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
                
                
                $nim = $_GET['nim'];
                $kd = isset($_GET['kd']) ? $_GET['kd']: "";
                $id = isset($_GET['id']) ? $_GET['id']: "";
                $tgl = isset($_GET['tgl']) ? $_GET['tgl']: date("d/m/y");
                $thn = isset($_GET['thn']) ? $_GET['thn']: 2008;
                $kls = isset($_GET['kls']) ? $_GET['kls']: "R";
                
                
                
                $idx = $_GET['idx'];
                $pg_bfr = $_SESSION['pg_bfr'];
                switch($idx)
                {
                case 1 : $title='Add Transaksi Keuangan Mahasiswa';break;
                case 2 : $title='Edit Transaksi Keuangan Mahasiswa';break;
                case 3 : $title='Delete Transaksi Keuangan Mahasiswa';break;
                }  
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
  <meta name="generator" content="HTML Tidy for HTML5 (experimental) for Windows https://github.com/w3c/tidy-html5/tree/c63cc39" />

  <title><?php echo $title ?></title>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
  <link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
  <style type="text/css">
/*<![CDATA[*/
                @import "../datatables/media/css/demo_page.css";
                        @import "../datatables/media/css/demo_table.css";
        .ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 9px; }
  /*]]>*/
  </style>
  <script type="text/javascript" src="../js/jquery-1.8.0.min.js">
</script>
  <script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js">
</script>
  <script type="text/javascript" src="../datatables/media/js/jquery.dataTables.js">
</script>
  <script type="text/javascript">
//<![CDATA[



  $(document).ready(function () {
        // Dialog

        $(".datepicker").datepicker({
                dateFormat : "yy-mm-dd"
        });

         <?php

        if ($idx == 1) {

                 ?>
                //$("#datepicker").datepicker("setDate", "<?php echo date(" Y - m - d ") ?>");
                 <?php
        }

         ?>
        var oTable;
        $('#dialog').dialog({
                autoOpen : true,
                <?php
                if ($idx == 3) {
                        ?>
                        width : 600,
                         <?php
                }else{ 
				
				   if ($idx == 1) {
					   ?>
                        width : 650,
                         <?php
				     }else {
                         ?>
                        width : 270,
                         <?php
					 }	 
                }
                 ?>
                resizable : true,
                autoHeight : true,
                open : function () {
                        $('#pgload').html("");
                        oTable = $('#lst_trkeumhs').dataTable({
                                        "aoColumnDefs" : [{
                                                        'bSortable' : false,
                                                        'aTargets' : [1]
                                                }, {
                                                        'bVisible' : false,
                                                        'aTargets' : [0]
                                                }
                                        ]
                                });
                },
                buttons : {

                         <?php
                        if ($idx == 3) {
                                 ?>
                                "Delete" : function () {
                                        $(this).dialog("close");
                                        $.ajax({
                                                type : "POST",
                                                url : "../global_code/entry_dt_trkeumhs.php",
                                                cache : false,
                                                data : $(":input", oTable.fnGetNodes()).serialize() + '&idx=<?php echo $idx ?>&nim=<?php echo $nim ?>',
                                                success : function (data) {
                                                        alert(data);
                                                        window.parent.pg_bfr( <?php echo '"'.$pg_bfr.'?thn='.$thn.'&kls='.$kls.'&nim='.$nim.'"' ?> );
                                                }
                                        });
                                },

                                 <?php
                        } else {
							if ($idx == 2)
							 {
                                 ?>
                                "Save" : function () {
                                        $(this).dialog("close");
                                        $.ajax({
                                                type : "POST",
                                                url : "../global_code/entry_dt_trkeumhs.php",
                                                cache : false,
                                                data : $("#entrytrkeumhs").serialize() + '&idx=<?php echo $idx ?>'+ '&id=<?php echo $id ?>',
                                                success : function (data) {
                                                        alert(data);
                                                        window.parent.pg_bfr( <?php echo '"'.$pg_bfr.'?thn='.$thn.'&kls='.$kls.'&nim='.$nim.'"' ?> );
                                                }
                                        });

                                },
                                 <?php
                             } else{
								  ?>
                                "Save" : function () {
                                        $(this).dialog("close");
                                        $.ajax({
                                                type : "POST",
                                                url : "../global_code/entry_dt_trkeumhs.php",
                                                cache : false,
                                                data : $(":input", oTable.fnGetNodes()).serialize() + '&idx=<?php echo $idx ?>'+'&nim=<?php echo $nim ?>',
                                                success : function (data) {
                                                        alert(data);
                                                        window.parent.pg_bfr( <?php echo '"'.$pg_bfr.'?thn='.$thn.'&kls='.$kls.'&nim='.$nim.'"' ?> );
                                                }
                                        });

                                },
                                 <?php
							 }
						}

                         ?>

                        "Cancel" : function () {
                                $(this).dialog("close");
                                window.parent.pg_bfr( <?php echo '"'.$pg_bfr.'?thn='.$thn.'&kls='.$kls.'&nim='.$nim.'"' ?> );
                        }
                }
        });

  });

  //]]>
  </script>
  <style type="text/css">
</style>
</head>

<body>
  <div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
  <!-- ui-dialog -->

  <div id="dialog" title="<?php echo $title ?>">
    <?php 
                             
                     $vwtrkeumhs = new vwtrkeumhs;
                             switch($idx)
                            {
                              case 1 : echo $vwtrkeumhs->frm_add($nim);break;
                              case 2 : echo $vwtrkeumhs->frm_edit($nim,$tgl,$kd);break;
                              case 3 : echo $vwtrkeumhs->frm_del($nim);break;
                            }  
                          ?>
  </div><?php } ?>
</body>
</html>
