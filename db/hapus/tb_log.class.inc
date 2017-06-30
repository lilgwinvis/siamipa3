<?php
require_once 'default_table.class.inc';
class tb_log extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'log';
        //$this->dbname          = 'siafmipa';
        
		$this->fieldlist       = $this->getfieldlist(); 
		
		//$this->fieldlist       = array('lg_time', 'out_time', 'user', 'net_id', 'browser', 'os','tg','season_id');
        $this->fieldlist['lg_time'] = array('pkey' => 'y');
		$this->fieldlist['user'] = array('pkey' => 'y'); 
        $this->fieldlist['season_id'] = array('pkey' => 'y');		
				
    } // end class constructor

} // end class


?>