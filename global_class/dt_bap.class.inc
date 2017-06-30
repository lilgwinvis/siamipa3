<?php
require_once 'shared.php';
class dt_bap {
    function __construct() {
		
	}
	
	function getData($where)
	{
		$tb = new tb_gen('tb_bap');
		$data = $tb->getData($where);
		return $data;
	}
		
	function save($arr){
	   $tb = new tb_gen('tb_bap');
        $tb->insertRecord($arr);	   
	}
	
    function update($arr){
		$tb = new tb_gen('tb_bap');
		$tb->updateRecord($arr);
	}

    function getjmlpertemu($id)
	{
		$tb = new tb_gen('tb_bap');
		$tb->sql_select='count(id) as jml';
		$data = $tb->getData("id like '$id%'");
		return (empty($data) ? 0 : $data[0]['jml']);
	}
	
}
?>