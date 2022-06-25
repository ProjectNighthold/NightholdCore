/* reparacion de npc mision defensor de marea oscura  retiro de aura al npc */
DELETE FROM `creature_template_addon` WHERE `entry` IN (83494);
INSERT INTO  `creature_template_addon`(`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
("83494", "0", "0", "0", "1", "0", "");

/* spawnd npc 77982*/
DELETE FROM `creature` WHERE `guid` =  6700012 AND `id`= 77982;
insert into `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) values
("6700012", "77982", "1116", "6719", "6910", "1", "1", "", "0", "1", "-1011.48", "-1686.2", "6.78107", "4.18378", "300", "0", "0", "21745400", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");