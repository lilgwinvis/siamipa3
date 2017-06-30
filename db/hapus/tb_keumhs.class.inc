<?php
require_once 'default_table.class.inc';
class tb_keumhs extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'keumhs';
        //$this->dbname        = 'siafmipa';
        $this->fieldlist       = $this->getfieldlist(); 
		
		// $this->fieldlist       = array('nimkeumhs','acclvl1keumhs','pengalikeumhs');
        // $this->fieldlist['nimkeumhs'] = array('pkey' => 'y');
		// $this->fieldlist['acclvl1keumhs'] = array('pkey' => 'y');              
			
    } // end class constructor

} // end class


?>