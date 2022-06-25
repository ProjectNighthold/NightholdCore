/* [La venganza del Jefe de Guerra] 14243 */

UPDATE `creature_template` SET 
`faction`='35' WHERE 
(`entry`='36178');

/* Spaw */
DELETE FROM `creature` WHERE (`guid`='190064');
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
('190064', '36188', '648', '4720', '4781', '1', '1032', '', '0', '0', '873.692', '2760.87', '119.407', '2.03069', '300', '0', '0', '29874', '6800', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');

DELETE FROM `creature` WHERE (`guid`='190065');
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
('190065', '36418', '648', '4720', '4781', '1', '1032', '', '0', '1', '870.603', '2760.01', '119.358', '2.00085', '300', '0', '0', '338', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');


/* [¡La Kaja'Cola te da IDEAS! (TM)] 25110 */
DELETE FROM `creature_loot_template` WHERE (`entry`='39193') AND (`item`='52483');
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES 
('39193', '52483', '18,7', '0', '0', '1', '1', '0');

/* [Liberar la mente] 25122 */

DELETE FROM `creature` WHERE (`guid`='6740123');
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
('6740123', '38441', '648', '4720', '4899', '1', '16384', '', '0', '1', '1764.71', '1912.5', '174.707', '2.79472', '300', '0', '0', '207', '0', '0', '0', '0', '34816', '0', '0', '0', '0', '0', '0', '0', '0', '0');


/* [¡Tíralo al suelo!] 25123 */
DELETE FROM `creature` WHERE (`guid`='6740124');
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
('6740124', '39199', '648', '4720', '4899', '1', '16384', '', '0', '0', '1763.51', '1966.58', '172.714', '5.63236', '300', '0', '0', '338', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');

/* [Una luz al final del túnel] 25125  */

DELETE FROM `creature_questender` WHERE (`id`='39341') AND (`quest`='25125');
INSERT INTO `creature_questender` (`id`, `quest`) VALUES 
('39341', '25125');

DELETE FROM `creature` WHERE (`guid`='6740125');
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
('6740125', '39199', '648', '4720', '4924', '1', '16384', '', '0', '0', '2059.6', '1837.28', '139.702', '1.88445', '300', '0', '0', '338', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');
