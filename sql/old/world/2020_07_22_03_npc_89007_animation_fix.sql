-- npc 89007 que le faltava la animacion de durmiendo
DELETE FROM `creature_addon` WHERE `guid`=270018;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (270018, 0, 0, 3, 0, 0, '145953');
