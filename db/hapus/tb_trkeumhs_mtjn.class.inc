<?php
require_once 'default_table.class.inc';
class tb_trkeumhs_mtjn extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->sql_select      = 'nimkeumhs,acclvl1keumhs,nmacclvl1,(pengalikeumhs*jmlbyrkeuangk) AS wajibByr,jmlbyr';
		$this->tablename       = '(((keumhs INNER JOIN acclvl1 ON acclvl1keumhs=noacclvl1) INNER JOIN msmhs ON nimhsmsmhs = nimkeumhs) INNER JOIN keuangk ON angkkeuangk=tahunmsmhs AND shiftkeuangk=shiftmsmhs AND noacclvl1keuangk=acclvl1keumhs)LEFT JOIN (SELECT trkeumhsnim AS nimtbl1,trkeumhsacclvl1 AS acclvl1tbl1,SUM(trkeumhsbayar) AS jmlbyr FROM trkeumhs GROUP BY trkeumhsnim,trkeumhsacclvl1) tbl1 ON nimkeumhs=tbl1.nimtbl1 AND acclvl1keumhs=tbl1.acclvl1tbl1';
       	$this->fieldlist       = array('nimkeumhs','acclvl1keumhs','nmacclvl1','wajibByr','jmlbyr');
              
				
    } // end class constructor

} // end class


?>