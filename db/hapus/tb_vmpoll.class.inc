<?php
require_once 'default_table.class.inc';
class tb_vmpoll extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->sql_select      = 'thsmsmpoll,semmpoll,shiftmpoll,kelasmpoll,kdkmkmpoll,nakmktbkmk,kddspengajar,nama,isimpoll';
		$this->tablename       = '((tbmpoll INNER JOIN pengajar ON thsmsmpoll=thnsmspengajar AND kdkmkmpoll=kdkmkpengajar AND shiftmpoll=shiftpengajar AND kelasmpoll=kelaspengajar AND semmpoll=semespengajar) INNER JOIN tbkmk ON kdkmktbkmk = kdkmkmpoll) INNER JOIN tbdos ON kddspengajar=kode';
       	$this->fieldlist       = array('thsmsmpoll','semmpoll','shiftmpoll','kelasmpoll','kdkmkmpoll','nakmktbkmk','kddspengajar','nama','isimpoll');
		$this->sql_orderby         = 'thsmsmpoll,semmpoll,shiftmpoll,kdkmkmpoll,isimpoll';	
    } // end class constructor

} // end class


?>