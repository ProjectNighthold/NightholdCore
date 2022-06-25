/*
Navicat MySQL Data Transfer

Source Server         : Testeo
Source Server Version : 50505
Source Host           : localhost:3306
Source Database       : legion_world

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2020-06-22 17:51:40
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for pvp_spec_stat_balance
-- ----------------------------
DROP TABLE IF EXISTS `pvp_spec_stat_balance`;
CREATE TABLE `pvp_spec_stat_balance` (
  `spec` int(11) NOT NULL,
  `pstat` float(11,3) NOT NULL,
  `stamina` float(11,3) NOT NULL,
  `crit` float(11,3) NOT NULL,
  `haste` float(11,3) NOT NULL,
  `vers` float(11,3) NOT NULL,
  `mast` float(11,3) NOT NULL,
  `reddmg` float(11,3) NOT NULL,
  `mana` float(11,3) NOT NULL,
  `vuln` float(11,3) NOT NULL,
  `name` text,
  PRIMARY KEY (`spec`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of pvp_spec_stat_balance
-- ----------------------------
INSERT INTO `pvp_spec_stat_balance` VALUES ('62', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.200', '0.000', '0.000', '0.000', 'mage_arcane');
INSERT INTO `pvp_spec_stat_balance` VALUES ('63', '0.000', '0.000', '0.000', '0.000', '0.000', '0.000', '5.000', '0.000', '0.000', 'mage_fire');
INSERT INTO `pvp_spec_stat_balance` VALUES ('64', '0.000', '0.000', '0.000', '0.000', '0.000', '0.000', '-5.000', '0.000', '0.000', 'mage_frost');
INSERT INTO `pvp_spec_stat_balance` VALUES ('65', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.150', '0.000', '0.000', '0.000', 'paladin_holy');
INSERT INTO `pvp_spec_stat_balance` VALUES ('66', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.200', '0.000', '0.000', '0.000', 'paladin_protection');
INSERT INTO `pvp_spec_stat_balance` VALUES ('70', '0.000', '0.000', '0.000', '0.000', '0.000', '0.000', '-15.000', '0.000', '0.000', 'paladin_retribution');
INSERT INTO `pvp_spec_stat_balance` VALUES ('71', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.250', '-10.000', '0.000', '0.000', 'warrior_arms');
INSERT INTO `pvp_spec_stat_balance` VALUES ('72', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.250', '-10.000', '0.000', '0.000', 'warrior_fury');
INSERT INTO `pvp_spec_stat_balance` VALUES ('73', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.200', '0.000', '0.000', '0.000', 'warrior_protection');
INSERT INTO `pvp_spec_stat_balance` VALUES ('102', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.200', '0.000', '0.000', '0.000', 'druid_balance');
INSERT INTO `pvp_spec_stat_balance` VALUES ('103', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.200', '0.000', '0.000', '0.000', 'druid_feral');
INSERT INTO `pvp_spec_stat_balance` VALUES ('104', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.150', '0.000', '0.000', '0.000', 'druid_guardian');
INSERT INTO `pvp_spec_stat_balance` VALUES ('105', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.150', '0.000', '0.000', '0.000', 'druid_restoration');
INSERT INTO `pvp_spec_stat_balance` VALUES ('250', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.200', '0.000', '0.000', '0.000', 'deathknight_blood');
INSERT INTO `pvp_spec_stat_balance` VALUES ('251', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.250', '-13.000', '0.000', '0.000', 'deathknight_frost');
INSERT INTO `pvp_spec_stat_balance` VALUES ('252', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.150', '0.000', '0.000', '0.000', 'deathknight_unholy');
INSERT INTO `pvp_spec_stat_balance` VALUES ('253', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.200', '0.000', '0.000', '0.000', 'hunter_beastmastery');
INSERT INTO `pvp_spec_stat_balance` VALUES ('254', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.200', '0.000', '0.000', '0.000', 'hunter_marksmanship');
INSERT INTO `pvp_spec_stat_balance` VALUES ('255', '0.000', '0.000', '0.000', '0.000', '0.000', '0.000', '0.000', '0.000', '0.000', 'hunter_survival');
INSERT INTO `pvp_spec_stat_balance` VALUES ('256', '0.000', '0.000', '0.000', '0.000', '0.000', '0.000', '-10.000', '0.000', '0.000', 'priest_discipline');
INSERT INTO `pvp_spec_stat_balance` VALUES ('257', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.150', '0.000', '0.000', '0.000', 'priest_holy');
INSERT INTO `pvp_spec_stat_balance` VALUES ('258', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.250', '0.000', '0.000', '0.000', 'priest_shadow');
INSERT INTO `pvp_spec_stat_balance` VALUES ('259', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.250', '-13.000', '0.000', '0.000', 'rogue_assassination');
INSERT INTO `pvp_spec_stat_balance` VALUES ('260', '0.000', '0.000', '0.000', '0.000', '0.000', '0.000', '0.000', '0.000', '0.000', 'rogue_outlaw');
INSERT INTO `pvp_spec_stat_balance` VALUES ('261', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.200', '0.000', '0.000', '0.000', 'rogue_subtlety');
INSERT INTO `pvp_spec_stat_balance` VALUES ('262', '0.000', '0.000', '0.000', '0.000', '0.000', '0.000', '-12.000', '0.000', '0.000', 'shaman_elemental');
INSERT INTO `pvp_spec_stat_balance` VALUES ('263', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.250', '-10.000', '0.000', '0.000', 'shaman_enhancement');
INSERT INTO `pvp_spec_stat_balance` VALUES ('264', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.200', '0.000', '0.000', '0.000', 'shaman_restoration');
INSERT INTO `pvp_spec_stat_balance` VALUES ('265', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.250', '-10.000', '0.000', '0.000', 'warlock_affliction');
INSERT INTO `pvp_spec_stat_balance` VALUES ('266', '0.000', '0.000', '0.000', '0.000', '0.000', '0.000', '0.000', '0.000', '0.000', 'warlock_demonology');
INSERT INTO `pvp_spec_stat_balance` VALUES ('267', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.250', '0.000', '0.000', '0.000', 'warlock_destruction');
INSERT INTO `pvp_spec_stat_balance` VALUES ('268', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.200', '0.000', '0.000', '0.000', 'monk_brewmaster');
INSERT INTO `pvp_spec_stat_balance` VALUES ('269', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.250', '-10.000', '0.000', '0.000', 'monk_windwalker');
INSERT INTO `pvp_spec_stat_balance` VALUES ('270', '-0.100', '0.000', '0.000', '0.000', '0.000', '-0.250', '0.000', '0.000', '0.000', 'monk_mistweaver');
INSERT INTO `pvp_spec_stat_balance` VALUES ('577', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.250', '-10.000', '0.000', '0.000', 'demon_hunter_havoc');
INSERT INTO `pvp_spec_stat_balance` VALUES ('581', '0.000', '0.000', '0.000', '0.000', '0.000', '-0.200', '0.000', '0.000', '0.000', 'demon_hunter_veangeance');
