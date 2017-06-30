<?php
require_once 'default_table.class.inc';
class tb_trnlm_jn_mtk extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->sql_select      = 'thsmstrnlm,nimhstrnlm,kdkmktrnlm,nakmktbkmk,sksmktbkmk,sksprtbkmk,shifttrnlm,semestbkmk,wp';
		$this->tablename       = 'trnlm INNER JOIN tbkmk ON kdkmktrnlm=kdkmktbkmk';
        $this->fieldlist       = array('thsmstrnlm','nimhstrnlm','kdkmktrnlm','nakmktbkmk','sksmktbkmk','sksprtbkmk','shifttrnlm','semestbkmk','wp');
                
				
    } // end class constructor

} // end class


?>