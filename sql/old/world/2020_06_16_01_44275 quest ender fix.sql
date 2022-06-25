-- reporte de quest http://10.96.2.10/Soporte/index.php?threads/ayuda-con-esta-mision.1432/#post-7905
DELETE FROM `creature_questender` WHERE `id`=103023 AND `quest`=44275;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES (103023, 44275);
