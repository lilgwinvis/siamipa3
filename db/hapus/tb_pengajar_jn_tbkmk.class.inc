<?php
require_once 'default_table.class.inc';
class tb_pengajar_jn_tbkmk extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        //$this->tablename       = 'msmhs';
        $this->sql_select ='thnsmspengajar,kddspengajar,kdkmkpengajar,nakmktbkmk,semestbkmk,sksmktbkmk,sksprtbkmk,shiftpengajar,semespengajar,kelaspengajar,haripengajar,jawalpengajar,jakhirpengajar,tgl_input,hnrpengajar,wp,kdass';
        $this->sql_from ='pengajar INNER JOIN tbkmk ON kdkmkpengajar=kdkmktbkmk';
        $this->sql_orderby='thnsmspengajar,kddspengajar,semestbkmk,kdkmkpengajar';  
		
		//$this->dbname          = 'siafmipa';
        $this->fieldlist       = array('thnsmspengajar','kddspengajar','kdkmkpengajar','nakmktbkmk','semestbkmk','sksmktbkmk','sksprtbkmk','shiftpengajar','semespengajar','kelaspengajar','haripengajar','jawalpengajar','jakhirpengajar','tgl_input','hnrpengajar','wp');
              
				
    } // end class constructor

} // end class


?>