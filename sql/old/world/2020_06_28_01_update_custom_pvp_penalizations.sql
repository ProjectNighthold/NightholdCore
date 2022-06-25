/*
Navicat MySQL Data Transfer

Source Server         : Testeo
Source Server Version : 50505
Source Host           : localhost:3306
Source Database       : legion_world

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2020-06-28 00:11:42
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for custom_pvp_penalizations
-- ----------------------------
DROP TABLE IF EXISTS `custom_pvp_penalizations`;
CREATE TABLE `custom_pvp_penalizations` (
  `specialization_id` int(11) NOT NULL,
  `specialization_name` varchar(255) NOT NULL,
  `damage_penalization` int(11) NOT NULL DEFAULT '0',
  `healing_penalization` int(11) NOT NULL DEFAULT '0',
  `mastery` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`specialization_id`,`specialization_name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of custom_pvp_penalizations
-- ----------------------------
INSERT INTO `custom_pvp_penalizations` VALUES ('62', 'Mago Arcano', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('63', 'Mago Fuego', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('64', 'Mago Escarcha', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('65', 'Paladin Sagrado', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('66', 'Paladin Proteccion', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('70', 'Paladin Retribucion', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('71', 'Warrior Arma', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('72', 'Warrior Furia', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('73', 'Warrior Proteccion', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('102', 'Druida Equilibrio', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('103', 'Druida Feral', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('104', 'Druida Guardian', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('105', 'Druida Restauracion', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('250', 'Caballero de la Muerte Sangre', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('251', 'Caballero de la Muerte Escarcha', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('252', 'Caballero de la Muerte Profano', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('253', 'Hunter Bestia', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('254', 'Hunter Punteria', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('255', 'Hunter Supervivencia', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('256', 'Sacerdote Disciplina', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('257', 'Sacerdote Sagrado', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('258', 'Sacerdote Sombra', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('259', 'Picaro Asesinato', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('260', 'Picaro Forajido', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('261', 'Picaro Sutileza', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('262', 'Shaman Elemental', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('263', 'Shaman Mejora', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('264', 'Shaman Restauracion', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('265', 'Brujo Afliccion', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('266', 'Brujo Demonologia', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('267', 'Brujo Destruccion', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('268', 'Monje Maestro Cervecero', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('269', 'Monje Caminaviento', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('270', 'Monje Tejedor de la Niebla', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('577', 'Cazador de Demonio Destruccion', '0', '0', '0');
INSERT INTO `custom_pvp_penalizations` VALUES ('581', 'Cazador de Demonio Venganza', '0', '0', '0');
