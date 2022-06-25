-- fix for missing spawn for npc Dawn-Seeker Krisek--

delete from `creature` where `guid` = 6760000;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
('6760000', '95424', '1464', '6723', '7522', '1', '65535', '', '0', '0', '3855.37', '-1335.47', '91.1532', '2.53788', '300', '0', '0', '108727', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');
