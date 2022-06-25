/* spawns npc durotar */
/* https://es.wowhead.com/quest=14296/vigila-tus-pasos*/
/* https://es.wowhead.com/quest=14300/la-prueba-del-fuego */
/* https://es.wowhead.com/quest=24479/la-prueba-de-las-sombras */
/* https://es.wowhead.com/quest=24478/la-prueba-de-escarcha*/
DELETE FROM `creature` WHERE `guid` =670033 AND `id`=36361;
DELETE FROM `creature` WHERE `guid` =670034 AND `id`=36335;
DELETE FROM `creature` WHERE `guid` =670035 AND `id`=36337;
DELETE FROM `creature` WHERE `guid` =670036 AND `id`=36336;

insert into `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) values
("670033", "36361", "1", "16", "4801", "1", "65535", "", "0", "0", "4932.87", "-6455.64", "160.629", "4.9285", "300", "0", "0", "35462", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("670034", "36335", "1", "16", "4799", "1", "1", "", "0", "0", "4518.26", "-5232.21", "304.05", "1.18911", "300", "0", "0", "35462", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("670035", "36337", "1", "16", "4800", "1", "1", "", "0", "0", "4350.39", "-5101.52", "335.513", "0.682524", "300", "0", "0", "35462", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("670036", "36336", "1", "16", "5333", "1", "1", "", "0", "0", "4634", "-6770.39", "214.686", "3.99298", "300", "0", "0", "35462", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");