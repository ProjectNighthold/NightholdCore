-- "Stormforged Grapple Launcher"  

/*Table_creature*/
DELETE FROM `creature` WHERE `guid` IN (6730001, 6730002);
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES
(6730001, 107840, 1220, 7541, 7564, 1, 65535, '', 0, 0, 3945.49, 2890.1, 242.745, 6.1247, 300, 0, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6730002, 107840, 1220, 7541, 7564, 1, 65535, '', 0, 0, 3946.93, 2888.01, 241.447, 1.07597, 300, 0, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
