<?php
require_once 'default_table.class.inc';
class tb_bap extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'tb_bap';
        $this->dbname          = 'siafmipa';
        
		$this->sql_select      = 'id,tgl,materi1,materi2,mtd';
		$this->sql_orderby     = 'id,tgl';
		
		$this->fieldlist       = $this->getfieldlist(); 
		
		//$this->fieldlist         = array('Kode', 'Nama', 'Tstat', 'Hstat','smawl', 'pass','nidn','nidn_epsbed','link_forlap');
        //$this->fieldlist['Kode'] = array('pkey' => 'y');
		
				
    } // end class constructor

} // end class
?>