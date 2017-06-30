<?php


require_once "../phpxbase/Column.class.php";
require_once "../phpxbase/Record.class.php";
require_once "../phpxbase/Table.class.php";
require_once "../phpxbase/WritableTable.class.php";

class epsbed_Table
{

	var $tablename;
	var $fieldlist;
	var $keyfield;
	var $fieldname; 

	var $data_array;
	var $base_path1;

	var $epsbed_select;
	var $epsbed_from;
	var $epsbed_where;
	var $epsbed_groupby;
	var $epsbed_having;
	var $epsbed_orderby;  

	function __construct()
	{
		$this->tablename       = 'default';
		//$this->dbname          = 'default';
		$this->rows_per_page   = 10;
		
		$this->fieldlist = array('column1', 'column2', 'column3');
		$this->fieldlist['column1'] = array('type' => DBFFIELD_TYPE_CHAR,'size'=>255);
		
	}

	function getData()
	{
		
		$this->data_array = array();    
		if (!file_exists($this->base_path1.$this->tablename)){	    
			$isconnect=false;		 
		}else{
			$isconnect=true;
		}
		
		if($isconnect){			 
			
			$table = new XBaseTable($this->base_path1.$this->tablename);
			$table->open();
			
			while ($record=$table->nextRecord()) {
				$tmp = array();
				foreach ($table->getColumns() as $i=>$c) {
					
					if($c->getType()==DBFFIELD_TYPE_DATE){
						$tmp[$c->getName()]=$record->getDate($c);
					}else{
						$tmp[$c->getName()]=$record->getString($c);
					}
					
					
				}
				
				$this->data_array[] = $tmp;
				
			}
			
			$table->close();
			
		}
		
		
		
		return $this->data_array;

	}


	function clonestruct($newtb)
	{
		
		$nmtb=$this->base_path1.$newtb;
		$fields = $this->fieldlist; 
		$tableNew=XBaseWritableTable::create($nmtb,$fields);
		$tableNew->close();
	}

	function clonedata($newtb)
	{
		
		$tableParent = new XBaseTable($this->base_path1.$this->tablename);
		$tableParent->open();
		
		
		$tableNew = XBaseWritableTable::cloneFrom($tableParent);
		$tableNew->openWrite($this->base_path1.$newtb,true);
		while ($record=$tableParent->nextRecord()) {
			$tableNew->appendRecord();
			$tableNew->record->copyFrom($record);
			$tableNew->writeRecord();
		}
		$tableNew->close();
		$tableParent->close();
		
	}
	

	function writedata($fieldarray)
	{
		
		$tableNew = XBaseWritableTable::create($this->base_path1.$this->tablename,$this->fieldlist);
		
		if(!empty($fieldarray)){
			foreach($fieldarray as $row){
				$r = $tableNew->appendRecord();	    
				foreach($row as $f=>$v){
					$r->setObjectByName($f,$v);
				}
				$tableNew->writeRecord();
			}		
		}
		$tableNew->close();
		
	}

	function insertRecord ($fieldarray)
	{
		$new_data = array();
		$data=$this->getData();
		
		if(!empty($data))
		{
			foreach($data as $row)
			{
				$new_data[] = $row;	    
			}	 
		}
		
		if(!empty($fieldarray))
		{     
			foreach($fieldarray as $row){	   
				$new_data[] = $row;
			}	   
		}
		
		$this->writedata($new_data);
		return;
		
	}

	function getTablePath()
	{
		$base_path2 ="";
		$server = $_SERVER['DOCUMENT_ROOT'];
		if($server=="C:/xampp/htdocs")
		{
			$base_path2 = "../db/";		
		}else {
			
			$base_path2 ='http://sia.fmipa-unibba.org/db/';
		}
		
		
		
		return $base_path2.$this->tablename;   
	}

	function updateRecord ($wherearray,$updatearray)
	{
		foreach ($wherearray as $field) {
			if (!in_array($field, $this->fieldname)) {
				unset ($wherearray[$field]);
			} // if
		} // foreach
		
		foreach ($updatearray as $field) {
			
			if (!in_array($field, $this->fieldname)) {
				unset ($updatearray[$field]);
			} // if
		} // foreach
		
		$new_data = array();
		$data=$this->getData();
		
		
		if(!empty($data))
		{
			
			$stat=true;
			foreach($data as $row)
			{
				if(!empty($wherearray)){
					$stat=$this->cek_kondisi($row,$wherearray);
				}    
				if($stat)
				{			
					foreach($updatearray as $f=>$v)
					{
						
						$row[$f]=$v;
					}				    
				} 
				$new_data[] = $row;
				
			}	 
		}
		
		if(!empty($new_data)){
			$this->writedata($new_data);
		}
		return;
		
	}

	function cek_kondisi($dt,$kond)
	{
		$stat=true;
		foreach($kond as $f=>$v)
		{
			$stat = $stat && ($dt[$f]==$v);	 
		}
		return $stat;
	}


	function deleteRecord ($fieldarray)
	{
		
		foreach ($fieldarray as $field) {
			if (!in_array($field, $this->keyfield)) {
				unset ($fieldarray[$field]);
			} // if
		} // foreach
		
		
		$new_data = array();
		$data=$this->getData();
		
		if(!empty($data))
		{
			foreach($data as $row)
			{
				if(!$this->cek_kondisi($row,$fieldarray)){
					$new_data[] = $row;	    
				}
			}	 
		}
		
		$this->writedata($new_data);
		return;
	}


}

?>