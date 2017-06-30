<?php
require_once 'default_table.class.inc';
class tb_keumhs_jn_acclvl1_jn_msmhs_jn_keuangk extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->sql_select      = 'nimkeumhs,acclvl1keumhs,nmacclvl1,pengalikeumhs,jmlbyrkeuangk';
		$this->tablename       = '((keumhs INNER JOIN acclvl1 ON acclvl1keumhs=noacclvl1) INNER JOIN msmhs ON nimhsmsmhs = nimkeumhs) INNER JOIN keuangk ON angkkeuangk=tahunmsmhs AND shiftkeuangk=shiftmsmhs AND noacclvl1keuangk=acclvl1keumhs';
       	$this->fieldlist       = array('nimkeumhs','acclvl1keumhs','nmacclvl1','pengalikeumhs','jmlbyrkeuangk');
              
				
    } // end class constructor

} // end class


?>