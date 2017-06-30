<?php
require_once 'default_table.class.inc';
class tb_penugasan extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'tbpenugasan';
        //$this->dbname          = 'siafmipa';
        $this->fieldlist       = array('id','kddsn','penugasan');
        $this->fieldlist['id'] = array('pkey' => 'y');
		$this->fieldlist['kddsn'] = array('pkey' => 'y');    
			
    } // end class constructor

} // end class


?>