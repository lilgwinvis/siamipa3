<?php
require_once 'default_table.class.inc';
class tb_vmpoll1 extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->sql_select      = 'thsmsmpoll,semmpoll,shiftmpoll,kelasmpoll,kdkmkmpoll,nakmktbkmk,kdds,nama,isimpoll';
		$this->tablename       = '((tbmpoll INNER JOIN ksd_ngajar ON thsmsmpoll=thnsms AND kdkmkmpoll=kdkmk AND shiftmpoll=shift AND kelasmpoll=klsklh AND semmpoll=sem) INNER JOIN tbkmk ON kdkmktbkmk = kdkmkmpoll) INNER JOIN tbdos ON kdds=kode';
       	$this->fieldlist       = array('thsmsmpoll','semmpoll','shiftmpoll','kelasmpoll','kdkmkmpoll','nakmktbkmk','kdds','nama','isimpoll');
		$this->sql_where       = 'disetujui=1';
		$this->sql_orderby         = 'thsmsmpoll,semmpoll,shiftmpoll,kdkmkmpoll,isimpoll';	
    } // end class constructor

} // end class


?>