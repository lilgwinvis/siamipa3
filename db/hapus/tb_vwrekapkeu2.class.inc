<?php
require_once 'default_table.class.inc';
class tb_vwrekapkeu2 extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'vw_rekapkeu2';
        //$this->dbname        = 'siafmipa';        
        $this->sql_orderby     ='thn,tahunmsmhs';
		$this->fieldlist       = $this->getfieldlist(); 
		//$this->fieldlist       = array('thn', 'tahunmsmhs', 'tran');		
    } // end class constructor

} // end class
?>