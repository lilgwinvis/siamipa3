<?php
require_once 'default_table.class.inc';
class tb_pengajar extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'pengajar';
        //$this->dbname          = 'siafmipa';
        $this->fieldlist       = $this->getfieldlist(); 
		//$this->fieldlist       = array('kdkmkpengajar', 'kddspengajar', 'shiftpengajar', 'thnsmspengajar','semespengajar','kelaspengajar','jawalpengajar','jakhirpengajar','haripengajar','hnrpengajar','ruangpengajar','tgl_input','kdass');
        
		$this->fieldlist['thnsmspengajar'] = array('pkey' => 'y');
		$this->fieldlist['kdkmkpengajar'] = array('pkey' => 'y');
		$this->fieldlist['shiftpengajar'] = array('pkey' => 'y');
		$this->fieldlist['kddspengajar'] = array('pkey' => 'y');
		$this->fieldlist['semespengajar'] = array('pkey' => 'y');
		$this->fieldlist['kelaspengajar'] = array('pkey' => 'y');
		
				
    } // end class constructor

} // end class
?>