<?php
require_once 'default_table.class.inc';
class tb_mtk_h extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'tbkmk_h';
        
		//$this->dbname          = 'siafmipa';
        $this->fieldlist       = array('THSMSTBKMK','KDPTITBKMK','KDJENTBKMK','KDPSTTBKMK','KDKMKTBKMK','NAKMKTBKMK','SKSMKTBKMK','SKSTMTBKMK','SKSPRTBKMK','SKSLPTBKMK','SEMESTBKMK',	
		                         'KDWPLTBKMK','KDKURTBKMK','KDKELTBKMK','NODOSTBKMK','STKMKTBKMK','SLBUSTBKMK','SAPPPTBKMK','BHNAJTBKMK','DIKTTTBKMK');
        $this->sql_orderby='THSMSTBKMK,KDPTITBKMK,KDJENTBKMK,KDPSTTBKMK,KDKMKTBKMK';
		$this->fieldlist['THSMSTBKMK'] = array('pkey' => 'y');
		$this->fieldlist['KDPTITBKMK'] = array('pkey' => 'y');
		$this->fieldlist['KDJENTBKMK'] = array('pkey' => 'y');
		$this->fieldlist['KDPSTTBKMK'] = array('pkey' => 'y');
		$this->fieldlist['KDKMKTBKMK'] = array('pkey' => 'y');
		      
				
    } // end class constructor

} // end class
?>