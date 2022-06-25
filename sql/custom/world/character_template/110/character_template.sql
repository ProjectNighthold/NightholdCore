/*
Navicat MySQL Data Transfer

Source Server         : Local
Source Server Version : 50505
Source Host           : localhost:3306
Source Database       : legion_world

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2020-01-22 11:43:50
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for character_template
-- ----------------------------
DROP TABLE IF EXISTS `character_template`;
CREATE TABLE `character_template` (
  `ID` int(10) unsigned NOT NULL,
  `Name` varchar(70) NOT NULL,
  `Description` varchar(100) NOT NULL,
  `level` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `ilevel` smallint(6) unsigned NOT NULL DEFAULT '0',
  `fromID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of character_template
-- ----------------------------
INSERT INTO `character_template` VALUES ('37', '100 level character', 'Create character with 100 level and 640ilvl items', '100', '0', '0');
INSERT INTO `character_template` VALUES ('38', '110 level character', 'Create character with 110 level and 810ilvl items', '110', '0', '0');
INSERT INTO `character_template` VALUES ('39', '110 level 845 ilevel', 'Create character with 110 level and 845ilvl items', '110', '845', '38');
INSERT INTO `character_template` VALUES ('40', '110 level 865 ilevel', 'Create character with 110 level and 865ilvl items', '110', '865', '38');
INSERT INTO `character_template` VALUES ('41', '110 level 895 ilevel', 'Create character with 110 level and 895ilvl items', '110', '895', '38');
INSERT INTO `character_template` VALUES ('42', '110 level 925 ilevel', 'Create character with 110 level and 925ilvl items', '110', '925', '38');
INSERT INTO `character_template` VALUES ('43', '110 level 945 ilevel', 'Create character with 110 level and 945ilvl items', '110', '945', '38');
INSERT INTO `character_template` VALUES ('44', '110 level 965 ilevel', 'Create character with 110 level and 965ilvl items', '110', '965', '38');
INSERT INTO `character_template` VALUES ('45', '110 level 985 ilevel', 'Create character with 110 level and 985ilvl items', '110', '985', '38');
