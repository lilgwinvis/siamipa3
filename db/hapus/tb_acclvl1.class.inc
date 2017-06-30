<?php
require_once 'default_table.class.inc';
class tb_acclvl1 extends Default_Table
{
	// additional class variables go here
	function __construct()
	{
		$this->tablename       = 'acclvl1';
		$this->dbname          = 'siafmipa';
		
		$this->sql_select      = 'noacclvl0,noacclvl1,nmacclvl1';
		$this->sql_orderby     = 'noacclvl1';
		
		$this->fieldlist       = $this->getfieldlist(); 
		
		// $this->fieldlist       = array('noacclvl0','noacclvl1','nmacclvl1');
		// $this->fieldlist['noacclvl1'] = array('pkey' => 'y');
		
		
	} // end class constructor

} // end class
?>