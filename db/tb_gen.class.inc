<?php
require_once 'default_table.class.inc';
require_once 'query_string.class.inc';
class tb_gen extends Default_Table
{
	// additional class variables go here
	function __construct($tb_name)
	{
		if(!in_array($tb_name,array('riwayat_jdwl_klh','publish_nilai','rekap_acclvl0','trnlm_jn_msmhs','trnlm_jn_mtk','pengajar_jn_tbkmk'))){
			$this->tablename       = $tb_name;        		
			$this->fieldlist       = $this->getfieldlist();
		}
		
		switch ($tb_name){
		case 'log' :
			$this->fieldlist['lg_time'] = array('pkey' => 'y');
			$this->fieldlist['user'] = array('pkey' => 'y'); 
			$this->fieldlist['season_id'] = array('pkey' => 'y');
			break;
		case 'msmhs' :
			$this->sql_orderby='tahunmsmhs,nimhsmsmhs';
			break;
		case 'tbdos' :
			$this->sql_select  = 'Kode,Nama,Tstat,Hstat,smawl,pass,nidn,nidn_epsbed,link_forlap';
			$this->sql_orderby = 'Kode';
			break;
		case 'tbkmk' :
			$this->sql_orderby='semestbkmk,wp,kdkmktbkmk';
			break;
		case 'acclvl1' :
			$this->sql_select   = 'noacclvl0,noacclvl1,nmacclvl1';
			$this->sql_orderby  = 'noacclvl1';
			break;
		case 'accoutlvl1' :
			$this->sql_select   = 'noaccoutlvl0,noaccoutlvl1,nmaccoutlvl1';
			$this->sql_orderby  = 'noaccoutlvl1';
			break;
		case 'tb_bap' :
			$this->sql_select   = 'id,tgl,materi1,materi2,mtd';
			$this->sql_orderby  = 'id,tgl';
			break;	
		case 'tb_dhmd' :
			$this->sql_select     = 'id,nim,presensi';
			$this->sql_orderby    = 'id';
			break;
		case 'hnr_ngajar' :
			$this->sql_orderby     = 'shift,Hstat';
			break;
		case 'vw_tbhutangmtk' :
			$this->sql_select ='thnsmspengajar,kddspengajar,kdkmkpengajar,nakmktbkmk,shiftpengajar,semespengajar,kelaspengajar,wp';
			$this->sql_orderby='thnsmspengajar,kddspengajar,kdkmkpengajar';
			break; 
		case 'vw_jdwlklh' :
			$this->sql_select ='hariklh,jawalklh,jakhirklh,sem,shift,kdkmk,nakmktbkmk,sksmktbkmk,kdds,nama,kdass,rklh,hnr,Hstat';
			$this->sql_orderby='hariklh,jawalklh,sem,shift,kdds,kdkmk';
			break;
		case 'ksd_ngajar':
			$this->sql_select      = 'Kdkmk,kdds,shift,thnsms,sem,jawalklh,jakhirklh,hariklh,klsklh,tgl_input,kdass,disetujui,hnr';
			$this->orderby         = 'sem';
			$this->fieldlist['klsklh'] = array('pkey' => 'y');
			break;  
		case 'vw_tbnilai':
			$this->sql_select ='thsmstrnlm,kdkmktrnlm,nakmktbkmk,nama,shifttrnlm,semestrnlm,kelastrnlm,jml';
			$this->sql_orderby  = 'thsmstrnlm desc,semestrnlm,kelastrnlm,kdkmktrnlm,nama,shifttrnlm';
			break; 
		case 'pengajar' :
			$this->fieldlist['thnsmspengajar'] = array('pkey' => 'y');
			$this->fieldlist['kdkmkpengajar'] = array('pkey' => 'y');
			$this->fieldlist['shiftpengajar'] = array('pkey' => 'y');
			$this->fieldlist['kddspengajar'] = array('pkey' => 'y');
			$this->fieldlist['semespengajar'] = array('pkey' => 'y');
			$this->fieldlist['kelaspengajar'] = array('pkey' => 'y');	
			break;
		case 'vw_tbrekaptrkeumhs' :
			$this->sql_select ='tahunmsmhs,shiftmsmhs,nimhsmsmhs,nmmhsmsmhs,kewajiban,tran';
			$this->sql_orderby='tahunmsmhs,nimhsmsmhs'; 
			break; 
		case 'trkeumhs':
			$this->fieldlist['trkeumhsnim'] = array('pkey' => 'y');
			$this->fieldlist['trkeumhstgl'] = array('pkey' => 'y');
			$this->fieldlist['trkeumhsacclvl1'] = array('pkey' => 'y');
			break;
		case 'vw_semjdwl' :
			$this->sql_select      = 'sem,hariklh';
			$this->sql_orderby         = 'sem,hariklh';	
			break;	
		case 'vw_rekapstatmhs':
			$this->sql_orderby     ='tahunmsmhs asc,thnsmsstat_mhs desc';
			break;
		case 'vw_rekapkeutotal' :
			$this->sql_select ='thn,danamasuk,jmlajuan,surflus,defisit';           
			$this->sql_orderby='thn';
			break;	
		case 'vw_rekapkeuoperasional' :
			$this->sql_select ='thn,danaoprasional,jmlajuan,surflus,defisit';			
			$this->sql_orderby='thn';		
			break;
		case 'vw_rekapkeu3':
			$this->sql_orderby     ='thn,kd';
			break;
		case 'vw_rekapkeu2' :               
			$this->sql_orderby     ='thn,tahunmsmhs';
			break;	
		case 'vw_rekapkeu1':                         
			$this->sql_orderby     ='thn,bln';
			break;
		case 'vw_kdssjdwl':
			$this->sql_select      = 'kdds,hariklh';		
			$this->fieldlist       = array('kdds','hariklh','bentrok');
			$this->sql_orderby     = 'kdds,hariklh';
			break;
		case 'vw_tbtrnlptrnlmjnmtk':
			$this->sql_select ='thsmstrnlm,nimhstrnlm,kdkmktrnlm,nakmktbkmk,sksmktbkmk,nlakhtrnlm,bobottrnlm,wp,semestbkmk';        
			$this->sql_orderby='thsmstrnlm,semestbkmk,kdkmktrnlm'; 
			break;	
		case 'trnlp':            
			$this->fieldlist['thsmstrnlp'] = array('pkey' => 'y');
			$this->fieldlist['nimhstrnlp'] = array('pkey' => 'y');
			$this->fieldlist['kdkmktrnlp'] = array('pkey' => 'y');
			break;
		case 'riwayat_jdwl_klh':			
			
			$qstr = new query_string;
			
			$this->sql_select ='haripengajar,jawalpengajar,jakhirpengajar,semestrnlm,shifttrnlm,kdkmktrnlm,nakmktbkmk,kddspengajar,nama,kdass,ruangpengajar,hnrpengajar,Hstat,sksmktbkmk';
			
			$fieldsubquery='thsmstrnlm,kdkmktrnlm,semestrnlm,shifttrnlm,kelastrnlm';
			$subquery='('.$qstr->select('trnlm',array('field'=>$fieldsubquery,'groupby'=>$fieldsubquery)).')';			
			
			$jointb=array('pengajar',"$subquery a",'tbdos','tbkmk');
			$jointype=array('RIGHT','LEFT','LEFT');
			
			$ands = $qstr->f_and(array('thnsmspengajar=thsmstrnlm','kdkmktrnlm=kdkmkpengajar','semestrnlm=semespengajar','shifttrnlm=shiftpengajar','kelastrnlm=kelaspengajar'));
			
			$onquery =array($ands,
			'Kode=kddspengajar',
			'kdkmktrnlm=kdkmktbkmk');
			
			$this->tablename ='('. $qstr->join($jointb,$jointype,$onquery).')';			
			
			$this->sql_orderby='haripengajar,jawalpengajar,semestrnlm,shifttrnlm,kdkmktrnlm,kddspengajar';  
			
			$this->fieldlist = array('haripengajar','jawalpengajar','jakhirpengajar','semestrnlm','shifttrnlm','kdkmktrnlm','nakmktbkmk','kddspengajar','nama','kdass','ruangpengajar','hnrpengajar','Hstat','sksmktbkmk');
			
			break; 
		case 'publish_nilai':
			$qstr = new query_string;
			$jointb=array('trnlm_trnlp a',"trnlm b",'tbkmk','msmhs');
			$jointype=array('','INNER','INNER');
			$ands = $qstr->f_and(array('a.thsmstrnlm=b.thsmstrnlm','a.nimhstrnlm=b.nimhstrnlm','a.kdkmktrnlm=b.kdkmktrnlm','a.kelastrnlm=b.kelastrnlm'));
			$onquery =array($ands,
			'b.kdkmktrnlm=kdkmktbkmk',
			'b.nimhstrnlm=nimhsmsmhs');
			
			$this->tablename  = $qstr->join($jointb,$jointype,$onquery);
			$this->sql_select = 'b.thsmstrnlm,b.nimhstrnlm,nmmhsmsmhs,b.kdkmktrnlm,nakmktbkmk,b.kelastrnlm,b.nlakhtrnlm nilaitrnlm,a.nlakhtrnlm nilaitrnlm_trnlp,b.bobottrnlm bobottrnlm,a.bobottrnlm bobottrnlm_trnlp';
			$this->sql_where  = 'b.nlakhtrnlm<>a.nlakhtrnlm';
			$this->sql_orderby = 'b.thsmstrnlm desc,b.kdkmktrnlm,b.kelastrnlm,b.nimhstrnlm';	
			break;
		case 'rekap_acclvl0' :
			$this->sql_select ='noacclvl0,nmacclvl0,kewajiban,jml';
			
			$qstr = new query_string;
			
			$jointb=array('keumhs','msmhs','keuangk','acclvl1');
			$jointype=array('INNER','LEFT','INNER');
			$ands = $qstr->f_and(array('angkkeuangk=tahunmsmhs','shiftkeuangk=shiftmsmhs','acclvl1keumhs=noacclvl1keuangk'));
			$onquery =array('nimhsmsmhs=nimkeumhs',
			$ands,
			'noacclvl1=noacclvl1keuangk');
			$firstjoin = $qstr->join($jointb,$jointype,$onquery);
			
			$subquery1 = '('.$qstr->select($firstjoin,array('field'=>'noacclvl0,SUM(pengalikeumhs*jmlbyrkeuangk) AS kewajiban',
			'groupby'=>'noacclvl0' 
			)).')'; 
			
			
			$jointb=array('trkeumhs','acclvl1','acclvl0');
			$jointype=array('INNER','INNER');		
			$onquery =array('trkeumhsacclvl1=noacclvl1',		                
			'acclvl1.noacclvl0=acclvl0.noacclvl0');
			$secondjoin = $qstr->join($jointb,$jointype,$onquery);
			
			$subquery2 = '('.$qstr->select($secondjoin,array('field'=>'acclvl1.noacclvl0,nmacclvl0,SUM(trkeumhsbayar) AS jml',
			'groupby'=>'noacclvl0' 
			)).')';				  
			
			
			$jointb=array("$subquery2 a","$subquery1 b");
			$jointype=array('INNER');		
			$onquery =array('a.noacclvl0=b.noacclvl0');
			
			$thirdjoin = $qstr->join($jointb,$jointype,$onquery);
			
			$this->sql_from ='('.$qstr->select($thirdjoin,array('field'=>'a.noacclvl0,nmacclvl0,kewajiban,jml')).') c';
			//$this->dbname          = 'siafmipa';
			$this->fieldlist       = array('noacclvl0','nmacclvl0','kewajiban','jml');
			break;	
		case 'trnlm_jn_msmhs':
			$this->sql_select ='thsmstrnlm,semestrnlm,kdkmktrnlm,shifttrnlm,kelastrnlm,nimhstrnlm,nmmhsmsmhs,tahunmsmhs,trim(nlakhtrnlm) as nlakhtrnlm';
			$this->sql_from ='trnlm INNER JOIN msmhs ON nimhstrnlm=nimhsmsmhs';
			$this->sql_orderby='thsmstrnlm,shifttrnlm,kdkmktrnlm,tahunmsmhs';			
			$this->fieldlist       = array('thsmstrnlm','semestrnlm','kdkmktrnlm','shifttrnlm','kelastrnlm','nimhstrnlm','nmmhsmsmhs','tahunmsmhs','nlakhtrnlm');		
			break;
		case 'trnlm_jn_mtk':
			$this->sql_select      = 'thsmstrnlm,nimhstrnlm,kdkmktrnlm,nakmktbkmk,sksmktbkmk,sksprtbkmk,shifttrnlm,semestbkmk,wp';
			$this->tablename       = 'trnlm INNER JOIN tbkmk ON kdkmktrnlm=kdkmktbkmk';
			$this->fieldlist       = array('thsmstrnlm','nimhstrnlm','kdkmktrnlm','nakmktbkmk','sksmktbkmk','sksprtbkmk','shifttrnlm','semestbkmk','wp');			
			break;	
		case 'pengajar_jn_tbkmk' :
			$this->sql_select ='thnsmspengajar,kddspengajar,kdkmkpengajar,nakmktbkmk,semestbkmk,sksmktbkmk,sksprtbkmk,shiftpengajar,semespengajar,kelaspengajar,haripengajar,jawalpengajar,jakhirpengajar,tgl_input,hnrpengajar,wp,kdass';
			$this->sql_from ='pengajar INNER JOIN tbkmk ON kdkmkpengajar=kdkmktbkmk';
			$this->sql_orderby='thnsmspengajar,kddspengajar,semestbkmk,kdkmkpengajar';		
			$this->fieldlist       = array('thnsmspengajar','kddspengajar','kdkmkpengajar','nakmktbkmk','semestbkmk','sksmktbkmk','sksprtbkmk','shiftpengajar','semespengajar','kelaspengajar','haripengajar','jawalpengajar','jakhirpengajar','tgl_input','hnrpengajar','wp');              
			break;		
		}
	} // end class constructor

} // end class


?>