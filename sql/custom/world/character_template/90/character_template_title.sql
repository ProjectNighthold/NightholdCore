/*
Navicat MySQL Data Transfer

Source Server         : Local
Source Server Version : 50505
Source Host           : localhost:3306
Source Database       : legion_world

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2020-01-23 22:51:21
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for character_template_title
-- ----------------------------
DROP TABLE IF EXISTS `character_template_title`;
CREATE TABLE `character_template_title` (
  `TemplateID` int(10) NOT NULL DEFAULT '38',
  `ClassID` tinyint(3) NOT NULL DEFAULT '0',
  `TitleID` int(10) NOT NULL DEFAULT '0',
  `FactionGroup` tinyint(3) NOT NULL DEFAULT '0',
  `RaceMask` bigint(20) unsigned NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of character_template_title
-- ----------------------------
INSERT INTO `character_template_title` VALUES ('37', '12', '458', '0', '0');
