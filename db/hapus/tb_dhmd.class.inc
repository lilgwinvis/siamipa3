<?php
require_once 'default_table.class.inc';
class tb_dhmd extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'tb_dhmd';
        $this->dbname        = 'siafmipa';
        
		$this->sql_select     = 'id,nim,presensi';
		$this->sql_orderby     = 'id';
		
		$this->fieldlist = $this->getfieldlist(); 
		
		//$this->fieldlist       = array('Kode', 'Nama', 'Tstat', 'Hstat','smawl', 'pass','nidn','nidn_epsbed','link_forlap');
        //$this->fieldlist['Kode'] = array('pkey' => 'y');
		
				
    } // end class constructor

} // end class
?>