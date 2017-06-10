/*
SQLyog Community
MySQL - 5.5.53-log : Database - personagens
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
/*Table structure for table `custom_reforging` */

DROP TABLE IF EXISTS `custom_reforging`;

CREATE TABLE `custom_reforging` (
  `GUID` int(10) unsigned NOT NULL COMMENT 'item guid low',
  `increase` int(10) unsigned NOT NULL COMMENT 'stat_type',
  `decrease` int(10) unsigned NOT NULL COMMENT 'stat_type',
  `stat_value` int(10) NOT NULL DEFAULT '0' COMMENT 'stat change',
  `Owner` int(10) unsigned DEFAULT NULL COMMENT 'player guid',
  PRIMARY KEY (`GUID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
