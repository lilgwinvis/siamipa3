<?php
require_once 'default_table.class.inc';
class tb_mpoll extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'tbmpoll';
        //$this->dbname          = 'siafmipa';
        $this->fieldlist       = $this->getfieldlist(); 
		
		// $this->fieldlist       = array('thsmsmpoll','nimhsmpoll','kdkmkmpoll','shiftmpoll','kelasmpoll','semmpoll','isimpoll','tgl_input');
        // $this->fieldlist['thsmsmpoll'] = array('pkey' => 'y');
		// $this->fieldlist['nimhsmpoll'] = array('pkey' => 'y');
        // $this->fieldlist['kdkmkmpoll'] = array('pkey' => 'y');        
			
    } // end class constructor

} // end class


?>