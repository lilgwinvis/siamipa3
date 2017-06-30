<?php
require_once 'default_table.class.inc';
class tb_vwrekapkeu3 extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'vw_rekapkeu3';
        //$this->dbname        = 'siafmipa';
        $this->sql_orderby     ='thn,kd';
		$this->fieldlist       = $this->getfieldlist(); 
		//$this->fieldlist       = array('thn', 'kd','nm', 'tran');
        
				
    } // end class constructor

} // end class
?>