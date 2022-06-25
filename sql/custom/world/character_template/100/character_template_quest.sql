/*
Navicat MySQL Data Transfer

Source Server         : Local
Source Server Version : 50505
Source Host           : localhost:3306
Source Database       : legion_world

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2020-07-26 22:57:48
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for character_template_quest
-- ----------------------------
DROP TABLE IF EXISTS `character_template_quest`;
CREATE TABLE `character_template_quest` (
  `TemplateID` int(10) NOT NULL DEFAULT '38',
  `ClassID` tinyint(3) NOT NULL DEFAULT '0',
  `QuestID` int(10) NOT NULL DEFAULT '0',
  `FactionGroup` tinyint(3) NOT NULL DEFAULT '0',
  `RaceMask` bigint(20) unsigned NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of character_template_quest
-- ----------------------------
INSERT INTO `character_template_quest` VALUES ('37', '6', '12593', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12619', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12842', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12848', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12636', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12641', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12657', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12850', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12670', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12678', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12697', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12698', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12700', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12701', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12706', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12714', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12715', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12719', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12720', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12723', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12724', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12725', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12727', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12738', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12751', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12754', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12755', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12756', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12757', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12778', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12800', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '12801', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '13165', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '13166', '0', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '13189', '5', '0');
INSERT INTO `character_template_quest` VALUES ('37', '6', '13188', '3', '0');
INSERT INTO `character_template_quest` VALUES ('37', '0', '25267', '0', '256');
INSERT INTO `character_template_quest` VALUES ('37', '0', '43341', '0', '0');
