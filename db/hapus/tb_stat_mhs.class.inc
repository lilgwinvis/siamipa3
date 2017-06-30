<?php
require_once 'default_table.class.inc';
class tb_stat_mhs extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'stat_mhs';
        //$this->dbname          = 'siafmipa';
        $this->fieldlist       = $this->getfieldlist(); 
		//$this->fieldlist       = array('thnsmsstat_mhs', 'nimstat_mhs', 'statstat_mhs');
        //$this->fieldlist['thnsmsstat_mhs'] = array('pkey' => 'y');
		//$this->fieldlist['nimstat_mhs'] = array('pkey' => 'y');
				
    } // end class constructor

} // end class
?>