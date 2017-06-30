<?php
require_once 'epsbed_table.class.inc';
class tb_epsbed_trlsm extends epsbed_table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'epsbed/TRLSM.DBF';
        $this->dbname        = 'siafmipa';
        $this->fieldname     = array('THSMSTRLSM','KDPTITRLSM','KDJENTRLSM','KDPSTTRLSM','NIMHSTRLSM','STMHSTRLSM','TGLLSTRLSM','SKSTTTRLSM','NLIPKTRLSM','NOSKRTRLSM','TGLRETRLSM','NOIJATRLSM','STLLSTRLSM','JNLLSTRLSM','BLAWLTRLSM','BLAKHTRLSM','NODS1TRLSM','NODS2TRLSM','NODS3TRLSM','NODS4TRLSM','NODS5TRLSM');
		
         $this->keyfield = array('THSMSTRLSM','KDPTITRLSM','KDJENTRLSM','KDPSTTRLSM','NIMHSTRLSM'); 
		
		$this->fieldlist = array(
		array("THSMSTRLSM" , DBFFIELD_TYPE_CHAR, 5),	
		array("KDPTITRLSM" , DBFFIELD_TYPE_CHAR, 6),	
		array("KDJENTRLSM" , DBFFIELD_TYPE_CHAR, 1),	
		array("KDPSTTRLSM" , DBFFIELD_TYPE_CHAR, 5),	
		array("NIMHSTRLSM" , DBFFIELD_TYPE_CHAR, 15),	
		array("STMHSTRLSM" , DBFFIELD_TYPE_CHAR, 1),	
		array("TGLLSTRLSM" , DBFFIELD_TYPE_DATE, 8),	
		array("SKSTTTRLSM" , DBFFIELD_TYPE_NUMERIC, 3),	
		array("NLIPKTRLSM" , DBFFIELD_TYPE_NUMERIC, 4),	
		array("NOSKRTRLSM" , DBFFIELD_TYPE_CHAR, 30),	
		array("TGLRETRLSM" , DBFFIELD_TYPE_DATE, 8),	
		array("NOIJATRLSM" , DBFFIELD_TYPE_CHAR, 40),	
		array("STLLSTRLSM" , DBFFIELD_TYPE_CHAR, 1),	
		array("JNLLSTRLSM" , DBFFIELD_TYPE_CHAR, 1),	
		array("BLAWLTRLSM" , DBFFIELD_TYPE_CHAR, 6),	
		array("BLAKHTRLSM" , DBFFIELD_TYPE_CHAR, 6),	
		array("NODS1TRLSM" , DBFFIELD_TYPE_CHAR, 10),	
		array("NODS2TRLSM" , DBFFIELD_TYPE_CHAR, 10),	
		array("NODS3TRLSM" , DBFFIELD_TYPE_CHAR, 10),
		array("NODS4TRLSM" , DBFFIELD_TYPE_CHAR, 10),	
		array("NODS5TRLSM" , DBFFIELD_TYPE_CHAR, 10),
       ); 
		

		
		$server = dirname(dirname(__FILE__));
   	   	$this->base_path1 = $server .'/db/';
				
    } // end class constructor

} // end class
?>

         