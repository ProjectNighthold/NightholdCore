/*
Navicat MySQL Data Transfer

Source Server         : MyHouse
Source Server Version : 50505
Source Host           : localhost:3306
Source Database       : characters

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2020-04-19 20:57:17
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for nordrassil_tournament_blood_and_heal
-- ----------------------------
DROP TABLE IF EXISTS `nordrassil_tournament_blood_and_heal`;
CREATE TABLE `nordrassil_tournament_blood_and_heal` (
  `inscription_id` bigint(20) NOT NULL AUTO_INCREMENT,
  `guid` bigint(20) NOT NULL,
  `p_name` varchar(255) NOT NULL,
  `specialization` int(11) NOT NULL,
  `is_dps` int(2) NOT NULL DEFAULT '0',
  `is_tank` int(2) NOT NULL DEFAULT '0',
  `amount` bigint(20) NOT NULL DEFAULT '0',
  `finish` tinyint(3) NOT NULL DEFAULT '0',
  `specialization_winer` int(11) NOT NULL DEFAULT '0',
  `general_winer` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`inscription_id`)
) ENGINE=InnoDB AUTO_INCREMENT=30 DEFAULT CHARSET=latin1;
