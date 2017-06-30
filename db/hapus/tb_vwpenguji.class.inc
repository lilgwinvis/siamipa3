<?php
require_once 'default_table.class.inc';
class tb_vwpenguji extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'vw_penguji';
        //$this->dbname          = 'siafmipa';
        $this->fieldlist       = $this->getfieldlist(); 
		//$this->fieldlist       = array('id','Kode','Nama','Penugasan');
               
			
    } // end class constructor

} // end class


?>