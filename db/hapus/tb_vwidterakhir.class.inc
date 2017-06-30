<?php
require_once 'default_table.class.inc';
class tb_vwidterakhir extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'vw_idterakhir';
        //$this->dbname          = 'siafmipa';
        
		$this->fieldlist       = $this->getfieldlist(); 
		//$this->fieldlist       = array('thn', 'id');
        
		       
			
    } // end class constructor

} // end class


?>