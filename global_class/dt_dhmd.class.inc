<?php
require_once 'shared.php';
class dt_dhmd {
    function __construct() {
		
	}	
	
	function save($arr){
		$tb = new tb_gen('tb_dhmd');
		$tb->insertRecord($arr);
	}
	
    function update($arr){
		$tb = new tb_gen('tb_dhmd');
		$tb->updateRecord($arr);
	}	
	
	function jmlmhspertemu($id)
    {
		$tb = new tb_gen('tb_dhmd');
		$tb->sql_select='count(nim) as jml';
		$data = $tb->getData("id='$id' and presensi=1");
		return (empty($data) ? 0 : $data[0]['jml']);
	}	
	
	function jmlratapertemu($id)
	{
	    $tb = new tb_gen('tb_dhmd');
		$tb->sql_select='avg(a.jml) as avgjml';
		$tb->sql_from="(select count(nim) as jml from tb_dhmd where id like '$id%' and presensi=1 group by id) a";
		$tb->sql_orderby='';
		$data = $tb->getData("");
		return (empty($data) ? 0 : $data[0]['avgjml']);	
	}
	
	function getpresensimhs($id)
	{
		$tmp=array();
		
		$tb = new tb_gen('tb_dhmd');
		$data = $tb->getData("id='$id'");
		
		if(!empty($data))
		{
			foreach($data as $row)
			{
				$tmp[$row['nim']]=$row['presensi'];
			}
		}
		
		
		return $tmp;
	}
	
}
?>