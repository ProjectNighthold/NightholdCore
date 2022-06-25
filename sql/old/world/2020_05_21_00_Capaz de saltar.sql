/* [Capaz de saltar](QuestID:42754) */


/* SPAW Phase*/

DELETE FROM `gameobject` WHERE (`guid`='141081');
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `AiID`, `state`, `isActive`, `personal_size`) VALUES 
('141081', '247027', '1220', '7637', '7844', '1', '1', '', '293.339', '4937.03', '-82.665', '5.9061', '0', '0', '0.187425', '-0.982279', '300', '0', '0', '1', '0', '0');


DELETE FROM `gameobject` WHERE (`guid`='110947');
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `AiID`, `state`, `isActive`, `personal_size`) VALUES ('110947', '251771', '1220', '7637', '7844', '1', '1', '', '689.967', '4804.1', '-71.1918', '2.62953', '-0', '-0', '-0.967402', '-0.253245', '300', '0', '0', '1', '0', '0');


/* SmarAI-Cred */
DELETE FROM `smart_scripts` WHERE (`entryorguid`='247027');
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
('247027', '1', '0', '0', '64', '0', '100', '0', '0', '0', '0', '0', '33', '109799', '0', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', 'Portal- SD');
