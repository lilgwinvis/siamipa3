<?php
require_once 'epsbed_table.class.inc';
class tb_epsbed_trnlp extends epsbed_table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'epsbed/TRNLP.DBF';
        $this->dbname        = 'siafmipa';
        $this->fieldname     = array('THSMSTRNLP','KDPTITRNLP','KDJENTRNLP','KDPSTTRNLP','NIMHSTRNLP','KDKMKTRNLP','NLAKHTRNLP','BOBOTTRNLP','KELASTRNLP');
		
		 $this->keyfield = array('THSMSTRNLP','KDPTITRNLP','KDJENTRNLP','KDPSTTRNLP','NIMHSTRNLP','KDKMKTRNLP','KELASTRNLP'); 
		
		$this->fieldlist = array(
		  array("THSMSTRNLP" , DBFFIELD_TYPE_CHAR, 5),
		  array("KDPTITRNLP" , DBFFIELD_TYPE_CHAR, 6),
		  array("KDJENTRNLP" , DBFFIELD_TYPE_CHAR, 1),
		  array("KDPSTTRNLP" , DBFFIELD_TYPE_CHAR, 5),
		  array("NIMHSTRNLP" , DBFFIELD_TYPE_CHAR, 15),
		  array("KDKMKTRNLP" , DBFFIELD_TYPE_CHAR, 10),
		  array("NLAKHTRNLP" , DBFFIELD_TYPE_CHAR, 2),
		  array("BOBOTTRNLP" , DBFFIELD_TYPE_NUMERIC, 4),
		  array("KELASTRNLP" , DBFFIELD_TYPE_CHAR, 2),
	   );
		
		
		$server = dirname(dirname(__FILE__));
   	   	$this->base_path1 = $server .'/db/';
				
    } // end class constructor

} // end class
?>

         