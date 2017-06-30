<?php
require_once 'default_table.class.inc';
class tb_staff extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'staff';
        //$this->dbname          = 'siafmipa';
        $this->fieldlist       = $this->getfieldlist(); 
		//$this->fieldlist       = array('user_id', 'nm_user', 'hak_akses', 'pass');
        //$this->fieldlist['user_id'] = array('pkey' => 'y');
		
				
    } // end class constructor

} // end class
?>