UPDATE `creature_template` SET `gossip_menu_id` = '65020' WHERE `entry` = '4000002'; 
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = '4000002';
DELETE FROM `smart_scripts` WHERE `entryorguid` = '4000002'; 
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
('4000002','0','0','0','62','0','100','0','65020','0','0','0','62','870','0','0','0','0','0','7','0','0','0','-293.21','-1768.84','62','2.1307','On gossip select - Teleport España'),
('4000002','0','1','0','62','0','100','0','65020','1','0','0','62','870','0','0','0','0','0','7','0','0','0','-293.21','-1768.84','62','2.1307','On gossip select - Teleport Japon');
DELETE FROM `gossip_menu_option` WHERE `MenuId` = '65020'; 
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionNPC`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
('65020','0','0','Llevame a España!','0','1','1','29416'),
('65020','1','0','Llevame a Japon!','0','1','1','29416');

-- Quest 31745
DELETE FROM `smart_scripts` WHERE `entryorguid` = '67067'; 
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
('67067','0','0','0','62','0','100','512','67067','0','0','0','33','67070','0','0','0','0','0','7','0','0','0','0','0','0','0','On gossip select - Give credit'),
('67067','0','1','0','62','0','100','0','67067','0','0','0','62','870','0','0','0','0','0','7','0','0','0','-293.21','-1768.84','62','2.1307','On gossip select - Teleport'),
('67067','0','2','0','10','0','100','0','1','10','10000','11000','33','67070','0','0','0','0','0','7','0','0','0','0','0','0','0','On gossip select - Give credit');
DELETE FROM `gossip_menu_option` WHERE `MenuId` = '67067'; 
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionNPC`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
('67067','0','0','Lets Go!','0','1','1','29416');
DELETE FROM `creature` WHERE `id` IN (67067, 65910, 66292, 66583); 
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
('67067','870','5785','6517','1','0','0','0','-53.5207','-1449.18','138.418','2.42526','300','0','0','1','0','0','0','0','0'),
('65910','870','5785','6516','1','0','0','0','-463.33','-1900.88','53.5129','5.1869','120','0','0','1','0','0','0','0','0'),
('66292','870','5785','6516','1','0','0','0','-463.317','-1904.94','53.5756','1.26051','300','0','0','1','0','0','0','0','0'),
('66583','870','5785','6516','1','0','0','0','-460.45','-1902.26','53.4059','3.53263','300','0','0','1','0','0','0','0','0');

UPDATE `creature_template` SET `gossip_menu_id` = '67067' , `npcflag` = '1', `AIName` = 'SmartAI' WHERE `entry` = '67067'; 
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = '66292';
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = '67067'; 

-- quest 31230
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = '59160';
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = '55809';
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = '59173';
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (59160, 55809, 59173); 
 INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
 ('59160','0','0','0','64','0','100','0','0','0','0','0','33','59160','0','0','0','0','0','7','0','0','0','0','0','0','0','On spellclick - Give quest credit'),
 ('55809','0','0','0','64','0','100','0','0','0','0','0','33','55809','0','0','0','0','0','7','0','0','0','0','0','0','0','On spellclick - Give quest credit'),
 ('59173','0','0','0','64','0','100','0','0','0','0','0','33','59173','0','0','0','0','0','7','0','0','0','0','0','0','0','On spellclick - Give quest credit');

-- Quest 30774 spawm more npc 60730
DELETE FROM `creature` WHERE `id` = '60730'; 
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES
('60730','870','5842','6163','1','1','','41871','0','2874.03','3246.93','433.852','1.29893','600','0','0','542752','9470','0','0','0','0','0','0','0','0','0','0','0','0','0'),
('60730','870','5842','6163','1','1','','41871','0','2842.44','3294.23','433.88','3.91465','600','0','0','542752','9470','0','0','0','0','0','0','0','0','0','0','0','0','0'),
('60730','870','5842','6163','1','1','','41871','0','2623.79','3356.3','434.388','4.88462','600','0','0','542752','9470','0','0','0','0','0','0','0','0','0','0','0','0','0'),
('60730','870','5842','6163','1','1','','41871','0','2823.49','3249.36','433.846','1.201','600','0','0','542752','9470','0','0','0','0','0','0','0','0','0','0','0','0','0'),
('60730','870','5842','6163','1','1','','41871','0','2803.28','3228.71','426.403','3.82158','600','0','0','542752','9470','0','0','0','0','0','0','0','0','0','0','0','0','0'),
('60730','870','5842','6163','1','1','','41871','0','2785','3208.34','425.704','1.64284','600','0','0','542752','9470','0','0','0','0','0','0','0','0','0','0','0','0','0'),
('60730','870','5842','6163','1','1','','41871','0','2761.75','3201.98','426.17','2.7179','600','0','0','542752','9470','0','0','0','0','0','0','0','0','0','0','0','0','0'),
('60730','870','5842','6163','1','1','','41871','0','2760.09','3264.72','429.485','4.83938','600','0','0','542752','9470','0','0','0','0','0','0','0','0','0','0','0','0','0'),
('60730','870','5842','6163','1','1','','41871','0','2787.82','3279.82','432.838','5.81239','600','0','0','542752','9470','0','0','0','0','0','0','0','0','0','0','0','0','0'),
('60730','870','5842','6163','1','1','','41871','0','2718.25','3245.12','429.074','5.47199','600','0','0','542752','9470','0','0','0','0','0','0','0','0','0','0','0','0','0'),
('60730','870','5842','6163','1','1','','41871','0','2666.92','3307.23','424.197','4.0232','600','0','0','542752','9470','0','0','0','0','0','0','0','0','0','0','0','0','0'),
('60730','870','5842','6163','1','1','','41871','0','2688.7','3280.69','425.894','4.4281','600','0','0','542752','9470','0','0','0','0','0','0','0','0','0','0','0','0','0'),
('60730','870','5842','6163','1','1','','41871','0','2662.6','3168.84','421.941','1.19932','600','0','0','542752','9470','0','0','0','0','0','0','0','0','0','0','0','0','0'),
('60730','870','5842','6163','1','1','','41871','0','2662.66','3214.79','425.144','4.05518','600','0','0','542752','9470','0','0','0','0','0','0','0','0','0','0','0','0','0'),
('60730','870','5842','6163','1','1','','41871','0','2587.08','3273.5','422.509','5.40924','600','0','0','542752','9470','0','0','0','0','0','0','0','0','0','0','0','0','0'),
('60730','870','5842','6163','1','1','','41871','0','2562.05','3285.02','421.498','4.62209','600','0','0','542752','9470','0','0','0','0','0','0','0','0','0','0','0','0','0'),
('60730','870','5842','6163','1','1','','41871','0','2612.21','3175.61','423.267','0.988884','600','0','0','542752','9470','0','0','0','0','0','0','0','0','0','0','0','0','0'),
('60730','870','5842','6163','1','1','','41871','0','2591.55','3214.39','423.28','0.821527','600','0','0','542752','9470','0','0','0','0','0','0','0','0','0','0','0','0','0');

DELETE FROM `creature_loot_template` WHERE `item` = '60679'; 
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
('44473','60679','-80','1','0','1','1'),
('1815','60679','-80','1','0','1','1');

replace INTO `quest_template_locale` (`ID`, `locale`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `QuestCompletionLog`, `VerifiedBuild`) VALUES
('40110','enGB','Disrupt the Inkbinders','','','','','','','','','21287'),
('40110','esMX','Sabotear a los vinculadores de tinta','','','','','','','','','21287');

replace INTO `quest_template_locale` (`ID`, `locale`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `QuestCompletionLog`, `VerifiedBuild`) VALUES
('41927','enGB','Ruining the Runewood','','','','','','','','','26124');

REPLACE INTO `gossip_menu_option_locale` (`MenuID`, `ID`, `Locale`, `OptionText`) VALUES
('21072', '8', 'enGB', 'Send me TO Exodar.'),
('21072', '8', 'enUS', 'Send me TO Exodar.'),
('21072', '8', 'esMX', 'Envíame a Exodar.'),
('21072', '8', 'esES', 'Envíame a Exodar.');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = '94346';
DELETE FROM `smart_scripts` WHERE `entryorguid` = '94346'; 
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
('94346','0','0','0','62','0','100','0','18656','0','0','0','62','1220','0','0','0','0','0','7','0','0','0','2867.648','877.716','79.496','2.4745','On gossip select - Teleport');


DELETE FROM `smart_scripts` WHERE `entryorguid` IN (107020, 107463, 109942, 109967); 
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
('107020','0','0','1','2','0','100','1','0','10','0','0','2','35','0','0','0','0','0','1','0','0','0','0','0','0','0','On 10% HP - SF'),
('107020','0','1','2','61','0','100','1','0','0','0','0','81','16777216','0','0','0','0','0','1','0','0','0','0','0','0','0','L - SNPCF'),
('107020','0','2','3','61','0','100','1','0','0','0','0','75','220649','0','0','0','0','0','1','0','0','0','0','0','0','0','L - AA'),
('107020','0','3','4','61','0','100','1','0','0','0','0','41','5000','0','0','0','0','0','1','0','0','0','0','0','0','0','L - D'),
('107020','0','4','8','61','0','100','1','0','0','0','0','1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','L - ST'),
('107020','0','5','10','73','0','100','1','0','0','0','0','11','210262','0','0','0','0','0','1','0','0','0','0','0','0','0','SC - CS'),
('107020','0','6','0','0','0','100','0','5000','6000','19000','20000','11','214424','0','0','0','0','0','2','0','0','0','0','0','0','0','IC - CS'),
('107020','0','7','0','0','0','100','0','9000','10000','10000','11000','11','185409','0','0','0','0','0','2','0','0','0','0','0','0','0','IC - CS'),
('107020','0','8','0','61','0','100','1','0','0','0','0','33','110585','0','0','0','0','0','7','0','0','0','0','0','0','0','L - KC'),
('107020','0','9','0','60','0','100','1','0','0','0','0','42','1','0','0','0','0','0','1','0','0','0','0','0','0','0','EU - SI'),
('107020','0','10','0','61','0','100','1','0','0','0','0','41','1000','0','0','0','0','0','1','0','0','0','0','0','0','0','L - D'),
('107463','0','0','1','2','0','100','1','0','10','0','0','2','35','0','0','0','0','0','1','0','0','0','0','0','0','0','On 10% HP - SF'),
('107463','0','1','2','61','0','100','1','0','0','0','0','81','16777216','0','0','0','0','0','1','0','0','0','0','0','0','0','L - SNPCF'),
('107463','0','2','3','61','0','100','1','0','0','0','0','75','220649','0','0','0','0','0','1','0','0','0','0','0','0','0','L - AA'),
('107463','0','3','4','61','0','100','1','0','0','0','0','41','5000','0','0','0','0','0','1','0','0','0','0','0','0','0','L - D'),
('107463','0','4','8','61','0','100','1','0','0','0','0','1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','L - ST'),
('107463','0','5','10','73','0','100','1','0','0','0','0','11','210262','0','0','0','0','0','1','0','0','0','0','0','0','0','SC - CS'),
('107463','0','6','0','0','0','100','0','5000','6000','11100','12000','11','196255','0','0','0','0','0','2','0','0','0','0','0','0','0','IC - CS'),
('107463','0','7','0','0','0','100','0','9000','10000','10000','11000','11','185409','0','0','0','0','0','2','0','0','0','0','0','0','0','IC - CS'),
('107463','0','8','0','61','0','100','1','0','0','0','0','33','110585','0','0','0','0','0','7','0','0','0','0','0','0','0','L - KC'),
('107463','0','9','0','60','0','100','1','0','0','0','0','42','1','0','0','0','0','0','1','0','0','0','0','0','0','0','EU - SI'),
('107463','0','10','0','61','0','100','1','0','0','0','0','41','1000','0','0','0','0','0','1','0','0','0','0','0','0','0','L - D'),
('109942','0','0','1','2','0','100','1','0','10','0','0','2','35','0','0','0','0','0','1','0','0','0','0','0','0','0','On 10% HP - SF'),
('109942','0','1','2','61','0','100','1','0','0','0','0','81','16777216','0','0','0','0','0','1','0','0','0','0','0','0','0','L - SNPCF'),
('109942','0','2','3','61','0','100','1','0','0','0','0','75','220649','0','0','0','0','0','1','0','0','0','0','0','0','0','L - AA'),
('109942','0','3','4','61','0','100','1','0','0','0','0','41','5000','0','0','0','0','0','1','0','0','0','0','0','0','0','L - D'),
('109942','0','4','8','61','0','100','1','0','0','0','0','1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','L - ST'),
('109942','0','5','9','73','0','100','1','0','0','0','0','11','210262','0','0','0','0','0','1','0','0','0','0','0','0','0','SC - CS'),
('109942','0','6','0','0','0','100','0','1000','2000','4000','6000','11','214593','0','0','0','0','0','2','0','0','0','0','0','0','0','IC - CS'),
('109942','0','7','0','0','0','100','0','3000','5000','4000','6000','11','214596','0','0','0','0','0','2','0','0','0','0','0','0','0','IC - CS'),
('109942','0','8','0','61','0','100','1','0','0','0','0','33','110585','0','0','0','0','0','7','0','0','0','0','0','0','0','daun'),
('109942','0','9','0','61','0','100','1','0','0','0','0','41','1000','0','0','0','0','0','1','0','0','0','0','0','0','0','L - D'),
('109942','0','10','0','60','0','100','1','0','0','0','0','42','1','0','0','0','0','0','1','0','0','0','0','0','0','0','EU - SI'),
('109967','0','0','1','2','0','100','1','0','10','0','0','2','35','0','0','0','0','0','1','0','0','0','0','0','0','0','On 10% HP - SF'),
('109967','0','1','2','61','0','100','1','0','0','0','0','81','16777216','0','0','0','0','0','1','0','0','0','0','0','0','0','L - SNPCF'),
('109967','0','2','3','61','0','100','1','0','0','0','0','75','220649','0','0','0','0','0','1','0','0','0','0','0','0','0','L - AA'),
('109967','0','3','4','61','0','100','1','0','0','0','0','41','5000','0','0','0','0','0','1','0','0','0','0','0','0','0','L - D'),
('109967','0','4','8','61','0','100','1','0','0','0','0','1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','L - ST'),
('109967','0','5','10','73','0','100','1','0','0','0','0','11','210262','0','0','0','0','0','1','0','0','0','0','0','0','0','SC - CS'),
('109967','0','6','0','0','0','100','0','5000','6000','11100','12000','11','181346','0','0','0','0','0','2','0','0','0','0','0','0','0','IC - CS'),
('109967','0','7','0','0','0','100','0','5000','6000','5100','6000','11','212207','0','0','0','0','0','2','0','0','0','0','0','0','0','IC - CS'),
('109967','0','8','0','61','0','100','1','0','0','0','0','33','110585','0','0','0','0','0','7','0','0','0','0','0','0','0','L - KC'),
('109967','0','9','0','60','0','100','1','0','0','0','0','42','1','0','0','0','0','0','1','0','0','0','0','0','0','0','EU - SI'),
('109967','0','10','0','61','0','100','1','0','0','0','0','41','1000','0','0','0','0','0','1','0','0','0','0','0','0','0','L - D');

REPLACE INTO `quest_template_locale` (`ID`, `locale`, `LogTitle`) VALUES ('39589', 'esMX', 'A Mysterious Summons'); 
 UPDATE `quest_template_locale` SET `LogDescription` = 'Meet Havi outside of Aggramar\'s Vault.' WHERE `ID` = '39589' AND `locale` = 'esMX'; 
 UPDATE `quest_template_locale` SET `QuestDescription` = '$C, heed my call. I am aware that you come to Stormheim seeking the Aegis of Aggramar. \r\n\r\nKnow that this will be a monumental task.\r\n\r\nHowever, I see promise in you, and thus will guide you through the ancient trials. I must warn you that no mortal has passed even the first of these trials in the recorded history of Stormheim, though countless champions have tried.\r\n\r\nIf you believe yourself worthy, outsider, seek me outside Aggramar\'s Vault. Your first test will await you there.' , `AreaDescription` = '' , `PortraitGiverText` = '' , `PortraitGiverName` = '' , `PortraitTurnInText` = '' , `PortraitTurnInName` = '' , `QuestCompletionLog` = '' , `VerifiedBuild` = '21287' WHERE `ID` = '39589' AND `locale` = 'esMX'; 

REPLACE INTO `quest_template_locale` (`ID`, `locale`, `LogTitle`) VALUES ('39589', 'enGB', 'A Mysterious Summons'); 
 UPDATE `quest_template_locale` SET `LogDescription` = 'Meet Havi outside of Aggramar\'s Vault.' WHERE `ID` = '39589' AND `locale` = 'enGB'; 
 UPDATE `quest_template_locale` SET `QuestDescription` = '$C, heed my call. I am aware that you come to Stormheim seeking the Aegis of Aggramar. \r\n\r\nKnow that this will be a monumental task.\r\n\r\nHowever, I see promise in you, and thus will guide you through the ancient trials. I must warn you that no mortal has passed even the first of these trials in the recorded history of Stormheim, though countless champions have tried.\r\n\r\nIf you believe yourself worthy, outsider, seek me outside Aggramar\'s Vault. Your first test will await you there.' , `AreaDescription` = '' , `PortraitGiverText` = '' , `PortraitGiverName` = '' , `PortraitTurnInText` = '' , `PortraitTurnInName` = '' , `QuestCompletionLog` = '' , `VerifiedBuild` = '21287' WHERE `ID` = '39589' AND `locale` = 'enGB'; 

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (96176); 
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
('96176','0','0','1','54','0','100','1','0','0','0','0','207','0','0','0','0','0','0','7','0','0','0','0','0','0','0','JS - SPI'),
('96176','0','1','0','61','0','100','1','0','0','0','0','80','96176','2','0','0','0','0','1','0','0','0','0','0','0','0','L - RTS'),
('96176','9','0','0','0','0','100','1','1800','1800','0','0','1','3','4000','0','0','0','0','1','0','0','0','0','0','0','0','TS - ST'),
('96176','9','1','0','0','0','100','0','0','0','0','0','12','96175','3','45000','0','0','0','8','0','0','0','3503.06','2164.7','231.29','6.25475','summon npc 96175');

UPDATE `quest_objectives` SET `Amount` = '10' , `TaskStep` = '10' WHERE `ID` = '285173'; 
UPDATE `quest_objectives` SET `Amount` = '17' , `TaskStep` = '6' WHERE `ID` = '285171'; 
UPDATE `quest_objectives` SET `Amount` = '34' , `TaskStep` = '3' WHERE `ID` = '285172'; 


REPLACE INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES
('285211','43341','6','-1','1948','3000','0','0','0',NULL,'21737'),
('285210','43341','6','-1','1883','3000','0','0','0',NULL,'21737'),
('285209','43341','6','-1','1828','3000','0','0','0',NULL,'21737'),
('285208','43341','6','-1','1900','3000','0','0','0',NULL,'21737'),
('286697','43341','6','-1','1859','3000','0','0','0',NULL,'23877');



