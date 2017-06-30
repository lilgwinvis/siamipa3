<?php   
 if (session_status() == PHP_SESSION_NONE) {
   session_start();
}
 if(!defined('DS')){
	define('DS', DIRECTORY_SEPARATOR);
	define('ROOT', dirname(dirname(__FILE__))); 
 }
 if(!defined('GLOBAL_CLASS')){	
	define('GLOBAL_CLASS', ROOT.DS.'global_class');
	define('GLOBAL_CODE', ROOT.DS.'global_code');
	define('BASIC_CLASS', ROOT.DS.'basic_class');
	define('PHPExcel', ROOT.DS.'Classes');
	define('TABLE_CLASS', ROOT.DS.'db');
	define('DOMPdf', ROOT.DS.'dompdf');
 }
define('LOCAL_CLASS', ROOT.DS.'Admin'.DS.'local_class');


function myautoload($className) {
    if (file_exists(GLOBAL_CLASS. DS . strtolower($className) . '.class.inc')) {
        require_once(GLOBAL_CLASS. DS . strtolower($className) . '.class.inc');
    }else {
		
		if (file_exists(BASIC_CLASS. DS . strtolower($className) . '.class.php')) {
            require_once(BASIC_CLASS. DS . strtolower($className) . '.class.php');
        } else {		
		       if (file_exists(LOCAL_CLASS. DS . strtolower($className) . '.class.inc')) {
                  require_once(LOCAL_CLASS. DS . strtolower($className) . '.class.inc');
               } else {
				   	  if (file_exists(TABLE_CLASS. DS . strtolower($className) . '.class.inc')) {
                         require_once(TABLE_CLASS. DS . strtolower($className) . '.class.inc');
                      } else {  

					
				              if (file_exists(PHPExcel. DS . $className . '.php')) {
                                 require_once(PHPExcel. DS . $className . '.php');
                              } else {
				   				   
				                        if (file_exists(PHPExcel. DS .'PHPExcel'.DS. $className . '.php')) {
                                            require_once(PHPExcel. DS .'PHPExcel'.DS. $className . '.php');
                                        } else {
				   			                   if ((class_exists($className,FALSE)==FALSE) and (strpos($className, 'PHPExcel') == 0)) {
							  	                   $ClassFilePath = PHPExcel.DS.str_replace('_',DS,$className).'.php';
                                                   if (file_exists($ClassFilePath)) {
                                                      require_once($ClassFilePath);
                                                   }else {
								                          echo 'Shared Admin, Kelas : '.$className.' tidak ditemukan !!!<br>' ; 
							                             }  
							                   }else {
								                      echo 'Shared Admin, Kelas : '.$className.' tidak ditemukan !!!<br>' ; 
							                         }
							 				              			   
			                           }
				   
			                    }
					  }
			   }
	     }
		
	}	
	
	
}
date_default_timezone_set("Asia/Jakarta");
spl_autoload_register('myautoload');
 
?>