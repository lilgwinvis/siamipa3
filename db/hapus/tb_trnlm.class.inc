<?php
require_once 'default_table.class.inc';
class tb_trnlm extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'trnlm';
        //$this->dbname          = 'siafmipa';
        $this->fieldlist       = $this->getfieldlist(); 
		// $this->fieldlist       = array('thsmstrnlm', 'nimhstrnlm', 'kdkmktrnlm', 'nlakhtrnlm', 'bobottrnlm', 'kelastrnlm', 'shifttrnlm', 'tgl_input','semestrnlm');
        // $this->fieldlist['thsmstrnlm'] = array('pkey' => 'y');
		// $this->fieldlist['nimhstrnlm'] = array('pkey' => 'y');
		// $this->fieldlist['kdkmktrnlm'] = array('pkey' => 'y');
		
				
    } // end class constructor

} // end class
?>