/*
SQLyog Community v12.12 (64 bit)
MySQL - 5.6.17-log : Database - siafmipa
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
/*Table structure for table `vw_rekapkeu1` */

DROP TABLE IF EXISTS `vw_rekapkeu1`;

/*!50001 DROP VIEW IF EXISTS `vw_rekapkeu1` */;
/*!50001 DROP TABLE IF EXISTS `vw_rekapkeu1` */;

/*!50001 CREATE TABLE  `vw_rekapkeu1`(
 `thn` int(4) ,
 `bln` int(2) ,
 `tran` decimal(41,4) 
)*/;

/*Table structure for table `vw_rekapkeu2` */

DROP TABLE IF EXISTS `vw_rekapkeu2`;

/*!50001 DROP VIEW IF EXISTS `vw_rekapkeu2` */;
/*!50001 DROP TABLE IF EXISTS `vw_rekapkeu2` */;

/*!50001 CREATE TABLE  `vw_rekapkeu2`(
 `thn` int(4) ,
 `tahunmsmhs` varchar(4) ,
 `tran` decimal(41,4) 
)*/;

/*Table structure for table `vw_rekapkeu3` */

DROP TABLE IF EXISTS `vw_rekapkeu3`;

/*!50001 DROP VIEW IF EXISTS `vw_rekapkeu3` */;
/*!50001 DROP TABLE IF EXISTS `vw_rekapkeu3` */;

/*!50001 CREATE TABLE  `vw_rekapkeu3`(
 `thn` int(4) ,
 `kd` double ,
 `nm` varchar(255) ,
 `tran` decimal(41,4) 
)*/;

/*View structure for view vw_rekapkeu1 */

/*!50001 DROP TABLE IF EXISTS `vw_rekapkeu1` */;
/*!50001 DROP VIEW IF EXISTS `vw_rekapkeu1` */;

/*!50001 CREATE ALGORITHM=UNDEFINED SQL SECURITY DEFINER VIEW `vw_rekapkeu1` AS (select year(`trkeumhs`.`trkeumhstgl`) AS `thn`,month(`trkeumhs`.`trkeumhstgl`) AS `bln`,sum(`trkeumhs`.`trkeumhsbayar`) AS `tran` from `trkeumhs` group by `thn`,`bln` order by `thn`) */;

/*View structure for view vw_rekapkeu2 */

/*!50001 DROP TABLE IF EXISTS `vw_rekapkeu2` */;
/*!50001 DROP VIEW IF EXISTS `vw_rekapkeu2` */;

/*!50001 CREATE ALGORITHM=UNDEFINED SQL SECURITY DEFINER VIEW `vw_rekapkeu2` AS (select year(`trkeumhs`.`trkeumhstgl`) AS `thn`,`msmhs`.`tahunmsmhs` AS `tahunmsmhs`,sum(`trkeumhs`.`trkeumhsbayar`) AS `tran` from (`trkeumhs` join `msmhs` on((`msmhs`.`nimhsmsmhs` = `trkeumhs`.`trkeumhsnim`))) group by `thn`,`msmhs`.`tahunmsmhs` order by `thn`,`msmhs`.`tahunmsmhs`) */;

/*View structure for view vw_rekapkeu3 */

/*!50001 DROP TABLE IF EXISTS `vw_rekapkeu3` */;
/*!50001 DROP VIEW IF EXISTS `vw_rekapkeu3` */;

/*!50001 CREATE ALGORITHM=UNDEFINED SQL SECURITY DEFINER VIEW `vw_rekapkeu3` AS (select year(`trkeumhs`.`trkeumhstgl`) AS `thn`,`acclvl1`.`noacclvl0` AS `kd`,`acclvl0`.`nmacclvl0` AS `nm`,sum(`trkeumhs`.`trkeumhsbayar`) AS `tran` from ((`trkeumhs` join `acclvl1` on((`acclvl1`.`noacclvl1` = `trkeumhs`.`trkeumhsacclvl1`))) join `acclvl0` on((`acclvl0`.`noacclvl0` = `acclvl1`.`noacclvl0`))) group by `thn`,`kd` order by `thn`,`kd`) */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
