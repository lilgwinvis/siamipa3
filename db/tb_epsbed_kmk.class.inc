<?php
require_once 'epsbed_table.class.inc';
class tb_epsbed_kmk extends epsbed_table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'epsbed/TBKMK.DBF';
        $this->dbname        = 'siafmipa';
        $this->fieldname     = array('THSMSTBKMK','KDPTITBKMK','KDJENTBKMK','KDPSTTBKMK','KDKMKTBKMK','NAKMKTBKMK','SKSMKTBKMK','SKSTMTBKMK','SKSPRTBKMK','SKSLPTBKMK','SEMESTBKMK',	
		                         'KDWPLTBKMK','KDKURTBKMK','KDKELTBKMK','NODOSTBKMK','JENJATBKMK','PRODITBKMK','STKMKTBKMK','SLBUSTBKMK','SAPPPTBKMK','BHNAJTBKMK','DIKTTTBKMK',
		                         'KDUTATBKMK','KDKUGTBKMK','KDLAITBKMK','KDMPATBKMK','KDMPBTBKMK','KDMPCTBKMK','KDMPDTBKMK','KDMPETBKMK','KDMPFTBKMK','KDMPGTBKMK','KDMPHTBKMK',
		                         'KDMPITBKMK','KDMPJTBKMK','CRMKLTBKMK','PRSTDTBKMK','SMGDSTBKMK','RPSIMTBKMK','CSSTUTBKMK','DISLNTBKMK','SDILNTBKMK','CODLNTBKMK','COLLNTBKMK',	
		                         'CTXINTBKMK','PJBLNTBKMK','PBBLNTBKMK','UJTLSTBKMK','TGMKLTBKMK','TGMODTBKMK','PSTSITBKMK','SIMULTBKMK','LAINNTBKMK','UJTL1TBKMK','TGMK1TBKMK',	
		                         'TGMO1TBKMK','PSTS1TBKMK','SIMU1TBKMK','LAIN1TBKMK');
		
		 $this->keyfield = array('THSMSTBKMK','KDPTITBKMK','KDJENTBKMK','KDPSTTBKMK','KDKMKTBKMK'); 
		
		$this->fieldlist = array(
		                   array("THSMSTBKMK" , DBFFIELD_TYPE_CHAR, 5),	
		                   array("KDPTITBKMK" , DBFFIELD_TYPE_CHAR, 6),	
		                   array("KDJENTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("KDPSTTBKMK" , DBFFIELD_TYPE_CHAR, 5),	
		                   array("KDKMKTBKMK" , DBFFIELD_TYPE_CHAR, 10),	
		                   array("NAKMKTBKMK" , DBFFIELD_TYPE_CHAR, 40),	
		                   array("SKSMKTBKMK" , DBFFIELD_TYPE_NUMERIC, 5),	
		                   array("SKSTMTBKMK" , DBFFIELD_TYPE_NUMERIC, 2),	
		                   array("SKSPRTBKMK" , DBFFIELD_TYPE_NUMERIC, 2),	
		                   array("SKSLPTBKMK" , DBFFIELD_TYPE_NUMERIC, 2),	
		                   array("SEMESTBKMK" , DBFFIELD_TYPE_CHAR, 2),	
		                   array("KDWPLTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("KDKURTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("KDKELTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("NODOSTBKMK" , DBFFIELD_TYPE_CHAR, 10),	
		                   array("JENJATBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("PRODITBKMK" , DBFFIELD_TYPE_CHAR, 5),	
		                   array("STKMKTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("SLBUSTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("SAPPPTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("BHNAJTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("DIKTTTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("KDUTATBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("KDKUGTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("KDLAITBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("KDMPATBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("KDMPBTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("KDMPCTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("KDMPDTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
	 	                   array("KDMPETBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("KDMPFTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("KDMPGTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("KDMPHTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("KDMPITBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("KDMPJTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("CRMKLTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("PRSTDTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("SMGDSTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("RPSIMTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("CSSTUTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("DISLNTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("SDILNTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("CODLNTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("COLLNTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("CTXINTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("PJBLNTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("PBBLNTBKMK" , DBFFIELD_TYPE_CHAR, 1),	
		                   array("UJTLSTBKMK" , DBFFIELD_TYPE_NUMERIC, 2),	
		                   array("TGMKLTBKMK" , DBFFIELD_TYPE_NUMERIC, 2),	
		                   array("TGMODTBKMK" , DBFFIELD_TYPE_NUMERIC, 2),	
		                   array("PSTSITBKMK" , DBFFIELD_TYPE_NUMERIC, 2),	
		                   array("SIMULTBKMK" , DBFFIELD_TYPE_NUMERIC, 2),	
		                   array("LAINNTBKMK" , DBFFIELD_TYPE_NUMERIC, 2),	
		                   array("UJTL1TBKMK" , DBFFIELD_TYPE_NUMERIC, 2),	
		                   array("TGMK1TBKMK" , DBFFIELD_TYPE_NUMERIC, 2),	
		                   array("TGMO1TBKMK" , DBFFIELD_TYPE_NUMERIC, 2),	
		                   array("PSTS1TBKMK" , DBFFIELD_TYPE_NUMERIC, 2),	
		                   array("SIMU1TBKMK" , DBFFIELD_TYPE_NUMERIC, 2),	
		                   array("LAIN1TBKMK" , DBFFIELD_TYPE_NUMERIC, 2),
		);
		$server = dirname(dirname(__FILE__));
   	   	$this->base_path1 = $server .'/db/';
		
				
    } // end class constructor

} // end class
?>

         