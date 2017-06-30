<?php
require_once 'default_table.class.inc';
class tb_mtk extends Default_Table
{
	// additional class variables go here
	function __construct()
	{
		$this->tablename       = 'tbkmk';
		
		//$this->dbname          = 'siafmipa';
		
		$this->fieldlist       = $this->getfieldlist(); 
		
		//$this->fieldlist       = array('kdkmktbkmk','nakmktbkmk','sksmktbkmk','skstmtbkmk','sksprtbkmk','skslptbkmk','semestbkmk','kdprtk','wp','nodostbkmk');
		$this->sql_orderby='semestbkmk,wp,kdkmktbkmk';
		//$this->fieldlist['kdkmktbkmk'] = array('pkey' => 'y');
		
		
	} // end class constructor

} // end class
?>