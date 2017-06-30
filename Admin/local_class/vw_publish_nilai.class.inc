<?php

  require_once 'shared.php';

class vw_publish_nilai
{
	function __construct()
	{
	  	  
	}
	
	function publish_nilai()
	{
	  
	  $txt_sem = array(1=>'Ganjil',2=>'Genap');
	  
	  $dt_riwayat = new dt_riwayat;
	  $dt_dosen = new dt_dosen;
	  $dt_publish_nilai = new dt_publish_nilai;
	  $data = $dt_publish_nilai->getgroupData("");	  
	  if(!empty($data))
	  {
	      $data1=array();
          $data2=array();
          $data3=array(); 		  
	      foreach($data as $row){		  
			  
			 
			  $tmpdt=array();
			  $thn = str_split($row['thsmstrnlm'], 4);
			  $tmpdt[]=array($txt_sem[$thn[1]]." ".$thn[0],array());
	          $tmpdt[]=array($row['kdkmktrnlm'],array());
			  $tmpdt[]=array($row['nakmktbkmk'],array()); 
			  $tmpdt[]=array($row['kelastrnlm'],array());
			  
			  $tmp=$this->hit_T($row['kdkmktrnlm'],$row['kelastrnlm'],$row['thsmstrnlm']);
			  
			  $nm=$dt_dosen->getnmdsn1($dt_riwayat->getDsn($row['thsmstrnlm'],$row['kdkmktrnlm'],$row['kelastrnlm']));
			  $tmpdt[]=array($nm,array());
			  
			  $tmpdt[]=array($tmp[2], array('align'=>'right'));
			  $tmpdt[]=array($tmp[0], array('align'=>'right'));
			  $tmpdt[]=array($tmp[1], array('align'=>'right'));
			  $tmpdt[]=array($tmp[3], array('align'=>'right'));
			  
			  $lnk="frm_lht_publish_nilai.php?&kdkmktrnlm=".$row['kdkmktrnlm']."&kelastrnlm=".$row['kelastrnlm']."&thsmstrnlm=".$row['thsmstrnlm'];
			  $tmpdt[]=array("<a href='".$lnk."'>Lihat MHS</a>",array());
			  
			  if($tmp[0]<$tmp[1]){  
				 $data1[]=$tmpdt;
			  }else{
			       if($tmp[0]>$tmp[1]){
				     $data2[]=$tmpdt;
				   }else{
				     $data3[]=$tmpdt;
				   }
			  
			  }
			  
			
			
	     }
	  }
	  
	  
	  $header = array(array(array("Semester",array("rowspan"=>2)),array("Kode",array("rowspan"=>2)),array("Matakuliah",array("rowspan"=>2)),array("Kelas",array("rowspan"=>2)),array("Dosen",array("rowspan"=>2)),array("Jml. Mhs.",array("rowspan"=>2)),array("Jml. Nilai T",array("colspan"=>2)),array("Anomali",array("rowspan"=>2)),array("Aksi",array("rowspan"=>2))),array("TRNLM","TRNLM_TRNLP"));
	  $accheader=array("Jumlah Nilai T TRNLM < Jumlah Nilai T TRNLM_TRNLP","Jumlah Nilai T TRNLM > Jumlah Nilai T TRNLM_TRNLP","Jumlah Nilai T TRNLM = Jumlah Nilai T TRNLM_TRNLP");  
	  $acccontent = array();
	  
	          $tbstat = array("id" => "tbl1",'width'=>'100%');
	          $tbl = new mytable($tbstat,$header,$data1,"");
		      $acccontent[]=$tbl->display();	  
	  
	          $tbstat = array("id" => "tbl2",'width'=>'100%');
	          $tbl = new mytable($tbstat,$header,$data2,"");
		      $acccontent[]=$tbl->display();
	 
	          $tbstat = array("id" => "tbl3",'width'=>'100%');
	          $tbl = new mytable($tbstat,$header,$data3,"");
		      $acccontent[]=$tbl->display();       
	  
	  $myaccordion = new myaccordion('accordion',$accheader,$acccontent);
	  return $myaccordion->display();
	
	}
	
	
	function hit_T($kdkmk,$kelas,$thsms)
	{
	    $dt_publish_nilai = new dt_publish_nilai;
	    $data = $dt_publish_nilai->getData("b.thsmstrnlm=".$thsms." and b.kelastrnlm='".$kelas."' and b.kdkmktrnlm='".$kdkmk."'");
		  
		  $jmlT1=0;
		  $jmlT2=0;
		  $jmlmhs=0;
		  $anomali=0;
		  if(!empty($data)){
			 foreach($data as $row){
	             
				 if ($row['nilaitrnlm']=="T") 
				    {$jmlT1=$jmlT1+1;}
				 
				 if ($row['nilaitrnlm_trnlp']=="T") 
				    {$jmlT2=$jmlT2+1;}
				 
				 if ( in_array($row['nilaitrnlm'],array("A","B","C","K")) and in_array($row['nilaitrnlm_trnlp'],array("D","E","K","T"))) 
				    {$anomali=$anomali+1;}
				
				$jmlmhs=$jmlmhs+1;	
	         }
	       }
		return array($jmlT1,$jmlT2,$jmlmhs,$anomali);   
	}
	
	
	function lht_mhs($kdkmk,$kelas,$thsms)
	{
	  
	     $user = $_SESSION['user'];
	     
		            
		 $dtuser = new dt_user;
         $hak = $dtuser->gethak($user); 	
	  
	  $tbl = new HTML_Table(null, 'display', 0, 0, 0,array("id" => "box-table-a","width" => "100%")); 
	          $tbl->addRow();
			  $tbl->addCell("NIM", null, 'header');
	          $tbl->addCell("Nama", null, 'header');
			  $tbl->addCell("Nilai TRNLM", null, 'header'); 
			  $tbl->addCell("Aksi", null, 'header');
			  $tbl->addCell("Nilai TRNLM_TRNLP", null, 'header');
	  
	  $dt_publish_nilai = new dt_publish_nilai;
	  $data = $dt_publish_nilai->getData("b.thsmstrnlm=".$thsms." and b.kelastrnlm='".$kelas."' and b.kdkmktrnlm='".$kdkmk."'");
	  if(!empty($data))
	  {
	     foreach($data as $row){
	       $tbl->addRow();
           $tbl->addCell($row['nimhstrnlm'], null, 'data');
		   $tbl->addCell($row['nmmhsmsmhs'], null, 'data'); 
		   $tbl->addCell($row['nilaitrnlm'], null, 'data'); 	
           
		     $lnk='javascript:publish_nilai("'.$row['nimhstrnlm'].'","'.$row['nilaitrnlm'].'",'.$row['bobottrnlm'].')';
		   
		   if($hak==0){
			   $tbl->addCell("->", null, 'data');
		   }else{
		    $tbl->addCell("<a href='".$lnk."'>-></a>", null, 'data');
		   }
		   $tbl->addCell($row['nilaitrnlm_trnlp'], null, 'data');  		   
	     }
	  }
	  
	  
	  
	  return "<div id='data'>".$tbl->display()."</div>";
	
	}
	
	
	function lht_mtk()
	{
	  $txt="<fieldset>";
      $txt.="<legend>Nilai yang harus di publish :</legend>";
      $txt.="<div id='data'>";	
	  $txt.=$this->publish_nilai();
	  $txt.="</div>";  
	  $txt.="</fieldset>";  
	  
	   
	  return $txt;	  
	}

}


?>