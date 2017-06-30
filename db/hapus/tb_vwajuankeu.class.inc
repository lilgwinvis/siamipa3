<?php
require_once 'default_table.class.inc';
class tb_vwajuankeu extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'vw_ajuankeu';
        //$this->dbname          = 'siafmipa';
        $this->fieldlist       = $this->getfieldlist(); 
		
		//$this->fieldlist       = array('thn','idajuan', 'noajuan', 'tglajuan', 'perihalajuan',  'jmlajuan',  'jmlcair', 'tglcair' , 'dibagikan', 'dilpjkan', 'tgllpj','tgl_input','accoutlvl1');
        //$this->fieldlist['idajuan'] = array('pkey' => 'y');
		       
			
    } // end class constructor

} // end class


?>