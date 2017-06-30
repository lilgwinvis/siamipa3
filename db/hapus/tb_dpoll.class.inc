<?php
require_once 'default_table.class.inc';
class tb_dpoll extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'tbdpoll';
        //$this->dbname          = 'siafmipa';
        
		$this->fieldlist       = $this->getfieldlist(); 
		
		// $this->fieldlist       = array('iddpoll','thsmsdpoll','kdkmkdpoll','shiftdpoll','kelasdpoll','semdpoll','nopolldpoll','jwbdpoll','tgl_input');        
		// $this->fieldlist['iddpoll'] = array('pkey' => 'y');
        // $this->fieldlist['nopolldpoll'] = array('pkey' => 'y');        
			
    } // end class constructor

} // end class


?>