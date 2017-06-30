<?php
require_once 'epsbed_table.class.inc';
class tb_epsbed_trnlm extends epsbed_table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'epsbed/TRNLM.DBF';
        $this->dbname        = 'siafmipa';
        $this->fieldname     = array('THSMSTRNLM','KDPTITRNLM','KDJENTRNLM','KDPSTTRNLM','NIMHSTRNLM','KDKMKTRNLM','NLAKHTRNLM','BOBOTTRNLM','KELASTRNLM');
		
		 $this->keyfield = array('THSMSTRNLM','KDPTITRNLM','KDJENTRNLM','KDPSTTRNLM','NIMHSTRNLM','KDKMKTRNLM','KELASTRNLM'); 
		
		$this->fieldlist = array(
		  array("THSMSTRNLM" , DBFFIELD_TYPE_CHAR, 5),
		  array("KDPTITRNLM" , DBFFIELD_TYPE_CHAR, 6),
		  array("KDJENTRNLM" , DBFFIELD_TYPE_CHAR, 1),
		  array("KDPSTTRNLM" , DBFFIELD_TYPE_CHAR, 5),
		  array("NIMHSTRNLM" , DBFFIELD_TYPE_CHAR, 15),
		  array("KDKMKTRNLM" , DBFFIELD_TYPE_CHAR, 10),
		  array("NLAKHTRNLM" , DBFFIELD_TYPE_CHAR, 2),
		  array("BOBOTTRNLM" , DBFFIELD_TYPE_NUMERIC, 4),
		  array("KELASTRNLM" , DBFFIELD_TYPE_CHAR, 2),
	   );
		
		
		$server = dirname(dirname(__FILE__));
   	   	$this->base_path1 = $server .'/db/';
				
    } // end class constructor

} // end class
?>

         