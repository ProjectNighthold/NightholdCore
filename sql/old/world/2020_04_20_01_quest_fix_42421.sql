/* spawns para quest https://es.wowhead.com/quest=42421/ca%C3%ADdos-de-la-noche */
DELETE FROM `creature` where guid = 6700028;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) values
('6700028', '115736', '1220', '7637', '8173', '1', '1', '', '0', '1', '1703', '4641.56', '170.732', '5.27055', '300', '0', '0', '831414', '1100000', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');
DELETE FROM `gameobject` where guid in (25684792);
INSERT INTO  `gameobject`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `AiID`, `state`, `isActive`, `personal_size`) values
('25684792', '251273', '1220', '7558', '8268', '1', '1', '', '1977.62', '6250.02', '67.1853', '1.42199', '-0', '-0', '-0.652588', '-0.757713', '300', '0', '0', '1', '0', '0');
