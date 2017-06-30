<?php
require_once 'default_table.class.inc';
class tb_hnr_ngajar extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'hnr_ngajar';
        $this->dbname          = 'siafmipa';
        $this->sql_orderby     = 'shift,Hstat';
		
		
		$this->fieldlist       = $this->getfieldlist(); 
		
		// $this->fieldlist       = array('shift', 'Hstat', 'honor', 'trans', 'lebih');
        // $this->fieldlist['shift'] = array('pkey' => 'y');
		// $this->fieldlist['Hstat'] = array('pkey' => 'y');
		
				
    } // end class constructor

} // end class
?>