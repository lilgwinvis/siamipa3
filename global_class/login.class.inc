<?php
require_once 'shared.php';
class login
{
   var $dtuser;
   var $vlog;
   function __construct(){
	 $this->vlog = new tb_gen('log');
   }
   
   
   function getaddress($lat,$lng)
  {
     $url = 'http://maps.googleapis.com/maps/api/geocode/json?latlng='.trim($lat).','.trim($lng).'&sensor=false';
     $json = @file_get_contents($url);
     if(!empty($json)){    
		 $data=json_decode($json);     
	     if(!empty($data)){
			 $status = $data->status;     
			 if($status=="OK")
			 {
			   return $data->results[0]->formatted_address;
			 }
			 else
			 {
			   return 'Tidak Ditemukan';
			 }
		 }
	}else{
	  return 'Tidak Ditemukan';	
	}	 
  }
   
   function user_logout()
   {
         $user = $_SESSION['user'];	       
		 $id = $_SESSION['id'];		 
		 
		 
		 
		 $today = date("Y-m-d H:i:s");
		 $fieldarray = array('season_id' => $id,'out_time'=> $today,'user' => $user);
		 $this->vlog->updateRecord($fieldarray);
   }
   
   
   function user_login($user,$pass,$idx,$longi,$lati)
    {	  
         //session_start();
		 
		 switch($idx){	  
			case 1 :  $this->dtuser = new dt_user;break;					  
		    case 2 :  $this->dtuser = new dt_mhs;break;
			case 3 :  $this->dtuser = new dt_dosen;break;					  
	     }
	  
	  //$numrows=$this->vtb_user->numrows;
	  
	  if($this->dtuser->isuserexist($user,$pass)){
	      if(!$this->islogin($user,$idx)){
				if(!isset($_SESSION['user']) and !isset($_SESSION['id']) and !isset($_SESSION['islog'])){ 
				  
				  $_SESSION['id']=uniqid();				  
				  
				  $_SESSION['user']=$user;
				  //$_SESSION['pass']=$pass;
				  $_SESSION['islog']=1;
				  
                  $alamat=$this->getaddress($lati,$longi);
                  
				  
				  $today = date("Y-m-d H:i:s");
				  $tg = $idx;
				  //$_SESSION['dtm']=$today;
				  
				  $fieldarray = array('lg_time' => $today,'user' => $user,'tg' => $tg,'net_id'=>$_SERVER['REMOTE_ADDR'],'season_id'=>$_SESSION['id'],'longitude'=>$longi,'altitude'=>$lati,'alamat'=>$alamat);		  
				  $this->vlog->insertRecord($fieldarray);
				  
				  return 1;
				}else{
                  return 3;
                }				
		  }else{					
				  return 2;				
		  }
	  }else{
	     
		 return 0;
	  }	  
	}

   function islogin($user,$idx)
   {
     $data = $this->vlog->getData("USER='".$user."' AND (NOT ISNULL(lg_time) AND DATE(lg_time)=DATE(NOW())) AND ISNULL(out_time) AND tg=".$idx);
     return $this->vlog->numrows>0;
   }  
   
   function logintime()
   {
       	  
	  if(isset($_SESSION['user']) and isset($_SESSION['id']) and isset($_SESSION['islog'])){
	   
	       $id = $_SESSION['id'];
	       $data = $this->vlog->getData('season_id="'.$id.'" and (DATE(lg_time)=DATE(NOW()) AND ISNULL(out_time))AND (TIMESTAMPDIFF(MINUTE,lg_time,NOW())<30)');
     	   return !($this->vlog->numrows>0);
	   
	   }else{
		   
		   return false;
	   }	   
   }
   
   
   function getData($tg)
   {
      $where = "tg=$tg";
	  $this->vlog->sql_orderby="lg_time desc";
      $data = $this->vlog->getData($where);
      return $data; 	  
   }   
}
?>