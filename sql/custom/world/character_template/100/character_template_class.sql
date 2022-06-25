/*
Navicat MySQL Data Transfer

Source Server         : Local
Source Server Version : 50505
Source Host           : localhost:3306
Source Database       : legion_world

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2020-07-26 22:57:30
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for character_template_class
-- ----------------------------
DROP TABLE IF EXISTS `character_template_class`;
CREATE TABLE `character_template_class` (
  `TemplateID` int(10) unsigned NOT NULL,
  `FactionGroup` tinyint(3) unsigned NOT NULL,
  `Class` tinyint(3) unsigned NOT NULL,
  `RaceMask` bigint(20) unsigned NOT NULL DEFAULT '0',
  `X` float NOT NULL DEFAULT '-880.264',
  `Y` float NOT NULL DEFAULT '4414.83',
  `Z` float NOT NULL DEFAULT '737.33',
  `O` float NOT NULL DEFAULT '4.31822',
  `MapID` mediumint(6) NOT NULL DEFAULT '1220',
  `Money` int(10) NOT NULL DEFAULT '10000',
  PRIMARY KEY (`TemplateID`,`FactionGroup`,`Class`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of character_template_class
-- ----------------------------
INSERT INTO `character_template_class` VALUES ('37', '3', '1', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '3', '2', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '3', '3', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '3', '4', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '3', '5', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '3', '6', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '3', '7', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '3', '8', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '3', '9', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '3', '10', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '3', '11', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '3', '12', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '5', '1', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '5', '2', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '5', '3', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '5', '4', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '5', '5', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '5', '6', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '5', '7', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '5', '8', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '5', '9', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '5', '10', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '5', '11', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
INSERT INTO `character_template_class` VALUES ('37', '5', '12', '0', '-880.264', '4414.83', '737.33', '4.31822', '1220', '500');
