/*
Navicat MySQL Data Transfer

Source Server         : Local
Source Server Version : 50505
Source Host           : localhost:3306
Source Database       : legion_world

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2020-01-23 22:51:09
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for character_template_spell
-- ----------------------------
DROP TABLE IF EXISTS `character_template_spell`;
CREATE TABLE `character_template_spell` (
  `TemplateID` int(10) NOT NULL DEFAULT '37',
  `ClassID` tinyint(3) NOT NULL DEFAULT '0',
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `FactionGroup` tinyint(3) NOT NULL DEFAULT '0',
  `RaceMask` bigint(20) unsigned NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of character_template_spell
-- ----------------------------
INSERT INTO `character_template_spell` VALUES ('37', '12', '200175', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '6', '48778', '0', '0');

INSERT INTO `character_template_spell` VALUES ('37', '1', '33388', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '1', '33391', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '1', '34090', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '1', '34091', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '1', '90265', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '1', '32290', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '1', '25532', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '1', '32246', '0', '0');

INSERT INTO `character_template_spell` VALUES ('37', '2', '33388', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '2', '33391', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '2', '34090', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '2', '34091', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '2', '90265', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '2', '32290', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '2', '25532', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '2', '32246', '0', '0');

INSERT INTO `character_template_spell` VALUES ('37', '3', '33388', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '3', '33391', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '3', '34090', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '3', '34091', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '3', '90265', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '3', '32290', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '3', '25532', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '3', '32246', '0', '0');

INSERT INTO `character_template_spell` VALUES ('37', '4', '33388', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '4', '33391', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '4', '34090', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '4', '34091', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '4', '90265', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '4', '32290', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '4', '25532', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '4', '32246', '0', '0');

INSERT INTO `character_template_spell` VALUES ('37', '5', '33388', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '5', '33391', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '5', '34090', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '5', '34091', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '5', '90265', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '5', '32290', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '5', '25532', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '5', '32246', '0', '0');

INSERT INTO `character_template_spell` VALUES ('37', '6', '33388', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '6', '33391', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '6', '34090', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '6', '34091', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '6', '90265', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '6', '32290', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '6', '25532', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '6', '32246', '0', '0');

INSERT INTO `character_template_spell` VALUES ('37', '7', '33388', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '7', '33391', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '7', '34090', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '7', '34091', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '7', '90265', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '7', '32290', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '7', '25532', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '7', '32246', '0', '0');

INSERT INTO `character_template_spell` VALUES ('37', '8', '33388', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '8', '33391', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '8', '34090', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '8', '34091', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '8', '90265', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '8', '32290', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '8', '25532', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '8', '32246', '0', '0');

INSERT INTO `character_template_spell` VALUES ('37', '9', '33388', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '9', '33391', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '9', '34090', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '9', '34091', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '9', '90265', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '9', '32290', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '9', '25532', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '9', '32246', '0', '0');

INSERT INTO `character_template_spell` VALUES ('37', '10', '33388', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '10', '33391', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '10', '34090', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '10', '34091', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '10', '90265', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '10', '32290', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '10', '25532', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '10', '32246', '0', '0');

INSERT INTO `character_template_spell` VALUES ('37', '11', '33388', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '11', '33391', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '11', '34090', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '11', '34091', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '11', '90265', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '11', '32290', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '11', '25532', '0', '0');
INSERT INTO `character_template_spell` VALUES ('37', '11', '32246', '0', '0');
