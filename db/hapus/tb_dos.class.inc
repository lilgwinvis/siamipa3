<?php
require_once 'default_table.class.inc';
class tb_dos extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'tbdos';
        $this->dbname        = 'siafmipa';
        
		$this->sql_select     = 'Kode,Nama,Tstat,Hstat,smawl,pass,nidn,nidn_epsbed,link_forlap';
		$this->sql_orderby     = 'Kode';
		
		$this->fieldlist = $this->getfieldlist(); 		
		
				
    } // end class constructor

} // end class
?>