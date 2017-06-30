<?php
require_once 'epsbed_table.class.inc';
class tb_epsbed_trakd extends epsbed_table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'epsbed/TRAKD.DBF';
        $this->dbname        = 'siafmipa';
        $this->fieldname     = array('THSMSTRAKD','KDPTITRAKD','KDJENTRAKD','KDPSTTRAKD','NODOSTRAKD','KDKMKTRAKD','KELASTRAKD','TMRENTRAKD','TMRELTRAKD');
		
		 $this->keyfield = array('THSMSTRAKD','KDPTITRAKD','KDJENTRAKD','KDPSTTRAKD','NODOSTRAKD','KDKMKTRAKD','KELASTRAKD'); 
		
		$this->fieldlist = array(
		  array("THSMSTRAKD" , DBFFIELD_TYPE_CHAR, 5),
		  array("KDPTITRAKD" , DBFFIELD_TYPE_CHAR, 6),
		  array("KDJENTRAKD" , DBFFIELD_TYPE_CHAR, 1),
		  array("KDPSTTRAKD" , DBFFIELD_TYPE_CHAR, 5),
		  array("NODOSTRAKD" , DBFFIELD_TYPE_CHAR, 10),
		  array("KDKMKTRAKD" , DBFFIELD_TYPE_CHAR, 10),
		  array("KELASTRAKD" , DBFFIELD_TYPE_CHAR, 2),
		  array("TMRENTRAKD" , DBFFIELD_TYPE_NUMERIC, 2),
		  array("TMRELTRAKD" , DBFFIELD_TYPE_NUMERIC, 2),
	   );
		
		
		$server = dirname(dirname(__FILE__));
   	   	$this->base_path1 = $server .'/db/';
				
    } // end class constructor

} // end class
?>

         