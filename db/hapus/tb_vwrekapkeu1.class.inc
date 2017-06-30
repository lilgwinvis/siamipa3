<?php
require_once 'default_table.class.inc';
class tb_vwrekapkeu1 extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'vw_rekapkeu1';
        //$this->dbname        = 'siafmipa';        
        $this->sql_orderby     ='thn,bln';
		$this->fieldlist       = $this->getfieldlist(); 
		//$this->fieldlist       = array('thn', 'bln', 'tran');		
    } // end class constructor

} // end class
?>