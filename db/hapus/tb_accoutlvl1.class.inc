<?php
require_once 'default_table.class.inc';
class tb_accoutlvl1 extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'accoutlvl1';
        $this->dbname          = 'siafmipa';
        
		$this->sql_select      = 'noaccoutlvl0,noaccoutlvl1,nmaccoutlvl1';
		$this->sql_orderby     = 'noaccoutlvl1';
		
		$this->fieldlist       = $this->getfieldlist(); 
		
		// $this->fieldlist       = array('noaccoutlvl0','noaccoutlvl1','nmaccoutlvl1');
        // $this->fieldlist['noaccoutlvl1'] = array('pkey' => 'y');
		
				
    } // end class constructor

} // end class
?>