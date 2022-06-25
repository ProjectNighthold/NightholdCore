/* spawn npc necesario de quest */
DELETE FROM `creature` WHERE `guid`=6700024 AND `id`= 77184;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) values
("6700024", "77184", "1116", "6719", "6796", "1", "65535", "", "0", "1", "1515.88", "307.317", "66.5111", "6.15021", "300", "0", "0", "60757200", "19500000", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");
