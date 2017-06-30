<?php
require_once 'default_table.class.inc';
class tb_keuangk extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'keuangk';
        //$this->dbname          = 'siafmipa';
        
		$this->fieldlist       = $this->getfieldlist(); 
		
		// $this->fieldlist       = array('angkkeuangk','shiftkeuangk','noacclvl1keuangk','jmlbyrkeuangk');
        // $this->fieldlist['angkkeuangk'] = array('pkey' => 'y');
		// $this->fieldlist['shiftkeuangk'] = array('pkey' => 'y');
        // $this->fieldlist['noacclvl1keuangk'] = array('pkey' => 'y');        
			
    } // end class constructor

} // end class


?>