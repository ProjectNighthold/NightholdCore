SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for autobroadcast
-- ----------------------------
DROP TABLE IF EXISTS `autobroadcast`;
CREATE TABLE `autobroadcast` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `text` longtext NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=0 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of autobroadcast
-- ----------------------------
INSERT INTO `autobroadcast` VALUES ('1', 'Bienvenido al reino de Nordrassil. Esperamos que la pase bien jugando con sus compañeros.');
INSERT INTO `autobroadcast` VALUES ('2', 'Para unirte a los canales de chat globales debes escribir /join global (Asi puedes hablar con todos los miembros del servidor)');
INSERT INTO `autobroadcast` VALUES ('3', 'Si tiene problemas no dude en pasar por el canal de Atención a Usuarios. Allí le atenderemos con mucho placer.');
INSERT INTO `autobroadcast` VALUES ('4', 'Recuerde que si es detectado haciendo trampas será sancionado y no tendrá derecho a reclamaciones. Evite ser sancionado');
