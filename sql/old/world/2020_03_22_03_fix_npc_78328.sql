/* reparacion de npc retiro de aura, mision Supresor de trituradoras*/
DELETE FROM `creature_template_addon` WHERE `entry` IN (78328);
INSERT INTO  `creature_template_addon`(`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
("78328", "0", "0", "0", "1", "0", "");
