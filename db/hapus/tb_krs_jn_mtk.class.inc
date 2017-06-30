<?php
require_once 'default_table.class.inc';
class tb_krs_jn_mtk extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->sql_select      = 'thsmskrs,nimhskrs,kdkmkkrs,nakmktbkmk,sksmktbkmk,sksprtbkmk,shiftkrs,semestbkmk,wp';
		$this->tablename       = 'krs INNER JOIN tbkmk ON kdkmkkrs=kdkmktbkmk';
        $this->fieldlist       = array('thsmskrs','nimhskrs','kdkmkkrs','nakmktbkmk','sksmktbkmk','sksprtbkmk','shiftkrs','semestbkmk','wp');
                
				
    } // end class constructor

} // end class


?>