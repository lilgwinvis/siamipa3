<?php
require_once 'default_table.class.inc';
class tb_syarat extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'syarat';
        //$this->dbname          = 'siafmipa';
        $this->fieldlist       = $this->getfieldlist(); 
		//$this->fieldlist       = array('kdkmksyarat', 'syaratkmk');
        //$this->fieldlist['kdkmksyarat'] = array('pkey' => 'y');
		//$this->fieldlist['syaratkmk'] = array('pkey' => 'y');
                
				
    } // end class constructor

} // end class


?>