<?php
require_once 'default_table.class.inc';
class tb_sidang extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'tbsidang';
        //$this->dbname          = 'siafmipa';
        
		$this->fieldlist       = $this->getfieldlist(); 
		
		//$this->fieldlist       = array('idsidang','thsmssidang','nimhssidang','tglskpenguji','noskpenguji','jdlskripsi','abs_indo','abs_ing','tglsidang','sesi','tgllls','idbimbingan','nidn_pemb1','nidn_pemb2','tglinput');
        //$this->fieldlist['idsidang'] = array('pkey' => 'y');
		    
			
    } // end class constructor

} // end class


?>