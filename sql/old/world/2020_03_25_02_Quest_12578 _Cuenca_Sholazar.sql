/* [ El Gorloc Enfadado]Quest id: 12578
spaneando al npc que recive la quest
*/
DELETE FROM `creature` WHERE `id`='28122';
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES ('146777541', '28122', '571', '3711', '4297', '1', '1', '', '0', '0', '5802.16', '3678.21', '-19.5695', '1.71562', '300', '0', '0', '26268', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');
