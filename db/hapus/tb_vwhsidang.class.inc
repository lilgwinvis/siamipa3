<?php
require_once 'default_table.class.inc';
class tb_vwhsidang extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'vw_hsidang';
        //$this->dbname          = 'siafmipa';
        
		$this->fieldlist       = $this->getfieldlist(); 
		//$this->fieldlist       = array('idbimbingan','thsmsbimbingan','nimhsbimbingan','nmmhsmsmhs','idsidang','temabimbingan','tglskpenguji','noskpenguji','jdlskripsi','abs_indo','abs_ing','tglsidang','tgllls','sesi');
               
			
    } // end class constructor

} // end class


?>