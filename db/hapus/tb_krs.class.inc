<?php
require_once 'default_table.class.inc';
class tb_krs extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'krs';
        //$this->dbname          = 'siafmipa';
        
		$this->fieldlist       = $this->getfieldlist(); 
		
		//$this->fieldlist       = array('thsmskrs','nimhskrs','kdkmkkrs','shiftkrs','kelaskrs','semkrs','tgl_input');
        //$this->fieldlist['thsmskrs'] = array('pkey' => 'y');
		//$this->fieldlist['nimhskrs'] = array('pkey' => 'y');
        //$this->fieldlist['kdkmkkrs'] = array('pkey' => 'y');        
			
    } // end class constructor

} // end class


?>