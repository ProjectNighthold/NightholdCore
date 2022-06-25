-- United As One (QuestID: 43397)

/*creature*/
DELETE FROM `creature` WHERE `guid` = 11317979;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES
(11317979, 111616, 0, 139, 2268, 1, 1, '0', 0, 0, 2346.57, -5375.95, 53.9016, 0.861085, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

/*creature_queststarter*/
DELETE FROM `creature_queststarter` WHERE `id` = 111616 AND `quest` = 45143;
INSERT INTO `creature_queststarter`(`id`, `quest`) VALUES (111616, 45143);

/*Gossip_menu*/
DELETE FROM `gossip_menu` WHERE `Entry` = 20169 AND `TextID` = 30016;
INSERT INTO `gossip_menu`(`Entry`, `TextID`, `FriendshipFactionID`) VALUES (20169, 30016, 0);

/*Gossip_menu_option*/
DELETE FROM `gossip_menu_option` WHERE `MenuID` = 20169 AND `OptionIndex` = 0;
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionIndex`, `OptionNPC`, `OptionText`, `OptionType`, `OptionNpcflag`, `OptionNpcflag2`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxCurrency`, `BoxText`, `OptionBroadcastTextID`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES (20169, 0, 0, 'Хорошо, пусть совет обсудит этот вопрос.', 1, 1, 0, 0, 0, 0, 0, 0, '', 120178, 0, 0);

/*smart_scripts*/
DELETE FROM `smart_scripts` WHERE `entryorguid` = 111616;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(111616, 0, 0, 0, 62, 0, 100, 0, 20169, 0, 0, 0, 1, 0, 8000, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'GS - ST'),
(111616, 0, 1, 0, 52, 0, 100, 0, 0, 111616, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 94175, 0, 0, 0, 0, 0, 0, 'TO - SD'),
(111616, 0, 2, 3, 38, 0, 100, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'UD - ST'),
(111616, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 224193, 0, 0, 0, 0, 0, 18, 20, 0, 0, 0, 0, 0, 0, 'Link - ICS'),
(111616, 0, 4, 0, 62, 0, 100, 0, 20169, 0, 0, 0, 33, 111195, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'GS - ST');