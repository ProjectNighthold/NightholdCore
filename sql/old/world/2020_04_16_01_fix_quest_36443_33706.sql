/* ZONA draenor spawns y delete de accion no funcionando*/
UPDATE `quest_template` SET `QuestType` = 0 WHERE `id` = 36443;
UPDATE `quest_template` SET `QuestType` = 0 WHERE `id` = 33706;
delete from `creature` where `guid` = 304756;
delete from `creature` where `guid` = 6700025;
delete from `creature` where `guid` = 6700026;
delete from `creature` where `guid` = 6700027;
insert into `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) values
("6700025", "73395", "1116", "6719", "7120", "1", "1", "", "0", "1", "1488.02", "-2116.87", "92.484", "1.79605", "300", "0", "0", "46975", "7400", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("6700026", "85436", "1116", "6721", "7304", "1", "1", "", "0", "1", "6786.5", "911.729", "148.734", "4.9464", "300", "0", "0", "379734", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("6700027", "82302", "1116", "6721", "7190", "1", "1", "", "0", "0", "7002.01", "959.523", "79.5772", "4.15709", "300", "0", "0", "379734", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");


