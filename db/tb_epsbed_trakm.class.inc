<?php
require_once 'epsbed_table.class.inc';
class tb_epsbed_trakm extends epsbed_table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'epsbed/TRAKM.DBF';
        $this->dbname        = 'siafmipa';
        $this->fieldname     = array('THSMSTRAKM','KDPTITRAKM','KDJENTRAKM','KDPSTTRAKM','NIMHSTRAKM','SKSEMTRAKM','NLIPSTRAKM','SKSTTTRAKM','NLIPKTRAKM');
			
		$this->keyfield = array('THSMSTRAKM','KDPTITRAKM','KDJENTRAKM','KDPSTTRAKM','NIMHSTRAKM');
		
		$this->fieldlist = array(
		array("THSMSTRAKM" , DBFFIELD_TYPE_CHAR, 5),	
		array("KDPTITRAKM" , DBFFIELD_TYPE_CHAR, 6),	
		array("KDJENTRAKM" , DBFFIELD_TYPE_CHAR, 1),	
		array("KDPSTTRAKM" , DBFFIELD_TYPE_CHAR, 5),	
		array("NIMHSTRAKM" , DBFFIELD_TYPE_CHAR, 15),	
		array("SKSEMTRAKM" , DBFFIELD_TYPE_NUMERIC, 6),	
		array("NLIPSTRAKM" , DBFFIELD_TYPE_NUMERIC, 4),	
		array("SKSTTTRAKM" , DBFFIELD_TYPE_NUMERIC, 6),	
		array("NLIPKTRAKM" , DBFFIELD_TYPE_NUMERIC, 4),
		 );
		
		$server = dirname(dirname(__FILE__));
   	   	$this->base_path1 = $server .'/db/';
				
    } // end class constructor

} // end class
?>

         