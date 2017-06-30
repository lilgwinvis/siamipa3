<?php
require_once 'default_table.class.inc';
class tb_trkeumhs extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'trkeumhs';
        //$this->dbname          = 'siafmipa';
        $this->fieldlist       = array('ID','trkeumhsnim','trkeumhstgl','trkeumhsacclvl1','trkeumhsbayar','trkeumhsket');
        $this->fieldlist['trkeumhsnim'] = array('pkey' => 'y');
		$this->fieldlist['trkeumhstgl'] = array('pkey' => 'y');
		$this->fieldlist['trkeumhsacclvl1'] = array('pkey' => 'y');
		             
			
    } // end class constructor

} // end class


?>