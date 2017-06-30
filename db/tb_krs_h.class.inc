<?php
require_once 'default_table.class.inc';
class tb_krs_h extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'krs_h';
        //$this->dbname          = 'siafmipa';
        
		$this->fieldlist       = $this->getfieldlist(); 
		
		//$this->fieldlist       = array('thsmskrs_h','nimhskrs_h','kdkmkkrs_h','shiftkrs_h','kelaskrs_h','semkrs_h','tgl_input','rec_stat');
        //$this->fieldlist['thsmskrs_h'] = array('pkey' => 'y');
		//$this->fieldlist['nimhskrs_h'] = array('pkey' => 'y');
        //$this->fieldlist['kdkmkkrs_h'] = array('pkey' => 'y');   
        //$this->fieldlist['tgl_input'] = array('pkey' => 'y');
        //$this->fieldlist['rec_stat'] = array('pkey' => 'y');		
			
    } // end class constructor

} // end class


?>