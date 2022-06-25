/*
Navicat MySQL Data Transfer

Source Server         : newwow
Source Server Version : 50505
Source Host           : localhost:3310
Source Database       : legion_world

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2020-02-06 23:25:42
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for spell_pvp_balance
-- ----------------------------
DROP TABLE IF EXISTS `spell_pvp_balance`;
CREATE TABLE `spell_pvp_balance` (
  `SpellID` int(10) NOT NULL DEFAULT '0',
  `EffectIndex` tinyint(4) NOT NULL DEFAULT '1',
  `Modifier` float NOT NULL DEFAULT '1',
  `Сomment` text,
  PRIMARY KEY (`SpellID`,`EffectIndex`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of spell_pvp_balance
-- ----------------------------
INSERT INTO `spell_pvp_balance` VALUES ('133', '0', '2.5', 'Fireball');
INSERT INTO `spell_pvp_balance` VALUES ('1943', '0', '0.5', 'Rupture');
INSERT INTO `spell_pvp_balance` VALUES ('2098', '0', '0.6', 'Run Through(not sure)');
INSERT INTO `spell_pvp_balance` VALUES ('8004', '0', '1.2', 'Healing Surge');
INSERT INTO `spell_pvp_balance` VALUES ('8042', '0', '0.75', 'Earth Shock');
INSERT INTO `spell_pvp_balance` VALUES ('11366', '0', '0.7', 'Pyroblast');
INSERT INTO `spell_pvp_balance` VALUES ('19434', '1', '0.8', 'Aimed Shot');
INSERT INTO `spell_pvp_balance` VALUES ('23922', '0', '0.5', 'Shield Slam');
INSERT INTO `spell_pvp_balance` VALUES ('25912', '0', '0.5', 'Holy Shock');
INSERT INTO `spell_pvp_balance` VALUES ('31935', '0', '0.5', 'Avenger_s Shield');
INSERT INTO `spell_pvp_balance` VALUES ('50622', '1', '0.66', 'Bladestorm');
INSERT INTO `spell_pvp_balance` VALUES ('50842', '0', '0.3', 'Blood Boil');
INSERT INTO `spell_pvp_balance` VALUES ('51505', '0', '0.6', 'Lava Burst');
INSERT INTO `spell_pvp_balance` VALUES ('52042', '0', '1.25', 'Healing Stream Totem');
INSERT INTO `spell_pvp_balance` VALUES ('53600', '0', '0.5', 'Shield of the Righteous');
INSERT INTO `spell_pvp_balance` VALUES ('77472', '0', '1.35', 'Healing Wave');
INSERT INTO `spell_pvp_balance` VALUES ('83381', '0', '0.8', 'Kill Command');
INSERT INTO `spell_pvp_balance` VALUES ('95738', '1', '0.66', 'Bladestorm Off-Hand');
INSERT INTO `spell_pvp_balance` VALUES ('109304', '0', '0.6', 'Exhilaration');
INSERT INTO `spell_pvp_balance` VALUES ('115310', '0', '2', 'Revival');
INSERT INTO `spell_pvp_balance` VALUES ('116014', '0', '0.7', 'Rune of Power');
INSERT INTO `spell_pvp_balance` VALUES ('116858', '0', '1.2', 'Chaos Bolt');
INSERT INTO `spell_pvp_balance` VALUES ('117313', '0', '0.5', 'Bloodthirst Heal');
INSERT INTO `spell_pvp_balance` VALUES ('117418', '0', '0.7', 'Fists of Fury');
INSERT INTO `spell_pvp_balance` VALUES ('128594', '0', '0.6', 'Exhilaration');
INSERT INTO `spell_pvp_balance` VALUES ('130493', '0', '0.5', 'Nightstalker');
INSERT INTO `spell_pvp_balance` VALUES ('131900', '0', '0.65', 'A Murder of Crows');
INSERT INTO `spell_pvp_balance` VALUES ('132404', '1', '0.4', 'Shield Block');
INSERT INTO `spell_pvp_balance` VALUES ('162264', '3', '0.4', 'Metamorphosis');
INSERT INTO `spell_pvp_balance` VALUES ('163786', '1', '0.5', 'Death from Above');
INSERT INTO `spell_pvp_balance` VALUES ('178963', '0', '0.2', 'Consume Soul');
INSERT INTO `spell_pvp_balance` VALUES ('184092', '0', '0.5', 'Light of the Protector');
INSERT INTO `spell_pvp_balance` VALUES ('185311', '0', '0.5', 'Crimson Vial');
INSERT INTO `spell_pvp_balance` VALUES ('185438', '1', '0.7', 'Shadowstrike');
INSERT INTO `spell_pvp_balance` VALUES ('188070', '0', '0.5', 'Healing Surge');
INSERT INTO `spell_pvp_balance` VALUES ('190456', '0', '0.4', 'Ignore Pain');
INSERT INTO `spell_pvp_balance` VALUES ('190780', '0', '0.15', 'Frost Breath');
INSERT INTO `spell_pvp_balance` VALUES ('191587', '0', '0.75', 'Virulent Plague');
INSERT INTO `spell_pvp_balance` VALUES ('192925', '0', '0.3', 'Blood of the Assassinated');
INSERT INTO `spell_pvp_balance` VALUES ('193455', '1', '0.75', 'Cobra Shot');
INSERT INTO `spell_pvp_balance` VALUES ('194311', '0', '0.6', 'Festering Wound');
INSERT INTO `spell_pvp_balance` VALUES ('194316', '0', '0.5', 'Cauterizing Blink');
INSERT INTO `spell_pvp_balance` VALUES ('196819', '0', '0.75', 'Eviscerate');
INSERT INTO `spell_pvp_balance` VALUES ('197393', '0', '0.6', 'Finality: Eviscerate');
INSERT INTO `spell_pvp_balance` VALUES ('197395', '0', '0.6', 'Finality: Nightblade');
INSERT INTO `spell_pvp_balance` VALUES ('198715', '0', '0.7', 'Val_kyr Strike');
INSERT INTO `spell_pvp_balance` VALUES ('200759', '0', '0.33', 'Soothing Darkness');
INSERT INTO `spell_pvp_balance` VALUES ('203794', '0', '0.2', 'Consume Soul');
INSERT INTO `spell_pvp_balance` VALUES ('203924', '0', '0.5', 'Healing Shell');
INSERT INTO `spell_pvp_balance` VALUES ('204488', '0', '0.4', 'Focused Rage');
INSERT INTO `spell_pvp_balance` VALUES ('204945', '1', '0.6', 'Doom Winds');
INSERT INTO `spell_pvp_balance` VALUES ('205224', '0', '0.5', 'Consumption');
INSERT INTO `spell_pvp_balance` VALUES ('205414', '0', '0.7', 'Strike of the Windlord');
INSERT INTO `spell_pvp_balance` VALUES ('206930', '1', '0.75', 'Heart Strike');
INSERT INTO `spell_pvp_balance` VALUES ('207311', '1', '0.75', 'Clawing Shadows');
INSERT INTO `spell_pvp_balance` VALUES ('207982', '0', '0.4', 'Focused Rage');
INSERT INTO `spell_pvp_balance` VALUES ('210042', '0', '0.2', 'Consume Soul');
INSERT INTO `spell_pvp_balance` VALUES ('210723', '0', '0.5', 'Ashamane_s Frenzy');
INSERT INTO `spell_pvp_balance` VALUES ('210723', '1', '0.5', 'Ashamane_s Frenzy');
INSERT INTO `spell_pvp_balance` VALUES ('210723', '2', '0.5', 'Ashamane_s Frenzy');
INSERT INTO `spell_pvp_balance` VALUES ('211715', '0', '0.66', 'Thal_kiel_s Consumption');
INSERT INTO `spell_pvp_balance` VALUES ('212198', '0', '0.5', 'Crimson Vial');
INSERT INTO `spell_pvp_balance` VALUES ('212621', '1', '0.5', 'Marked Shot');
INSERT INTO `spell_pvp_balance` VALUES ('212739', '0', '0.85', 'Epidemic');
INSERT INTO `spell_pvp_balance` VALUES ('213652', '0', '0.5', 'Hand of the Protector');
INSERT INTO `spell_pvp_balance` VALUES ('213678', '1', '0.5', 'Piercing Shot');
INSERT INTO `spell_pvp_balance` VALUES ('213757', '0', '0.6', 'Execution Sentence');
INSERT INTO `spell_pvp_balance` VALUES ('215661', '0', '0.6', 'Justicar_s Vengeance');
INSERT INTO `spell_pvp_balance` VALUES ('215969', '1', '0.85', 'Epidemic');
INSERT INTO `spell_pvp_balance` VALUES ('216019', '0', '0.6', 'Unending Thirst');
INSERT INTO `spell_pvp_balance` VALUES ('218321', '0', '0.8', 'Dragged to Helheim');
INSERT INTO `spell_pvp_balance` VALUES ('219432', '0', '0.5', 'Rage of the Sleeper');
INSERT INTO `spell_pvp_balance` VALUES ('220143', '1', '0.4', 'Apocalypse');
INSERT INTO `spell_pvp_balance` VALUES ('222029', '0', '0.7', 'Strike of the Windlord');
INSERT INTO `spell_pvp_balance` VALUES ('224266', '0', '0.7', 'Templar_s Verdict');
INSERT INTO `spell_pvp_balance` VALUES ('227225', '0', '0.2', 'Soul Barrier');
INSERT INTO `spell_pvp_balance` VALUES ('228477', '3', '0.2', 'Soul Cleave');
INSERT INTO `spell_pvp_balance` VALUES ('228600', '0', '0.75', 'Glacial Spike');
INSERT INTO `spell_pvp_balance` VALUES ('235484', '0', '0.5', 'Between the Eyes');