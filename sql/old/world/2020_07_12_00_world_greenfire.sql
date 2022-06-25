DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1040);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
('1040','10','0','0','75','0','100','0','0','0','0','0','205','92','49592','0','0','0','0','7','0','0','0','0','0','0','0','SmartAI');

DELETE FROM `eventobject` WHERE `id`=1040;
INSERT INTO `eventobject` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES 
('1040', '1489', '7737', '7737', '4096', '5586', '311.657', '1650.550', '-70.890', '4.6043'); 

UPDATE `instance_template` SET `script`='instance_pursuing_the_black_harvest', `allowMount`='1' WHERE `map`='1112';

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1503,1504,1505,1506,1507,1508,1509);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
('1503','10','0','0','75','0','100','0','0','0','0','0','45','0','2','0','0','0','0','11','168137','2000','0','0','0','0','0','SmartAI'),
('1504','10','0','0','75','0','100','0','0','0','0','0','205','92','34552','0','0','0','0','7','0','0','0','0','0','0','0','SmartAI'),
('1506','10','0','0','75','0','100','0','0','0','0','0','45','0','2','0','0','0','0','11','168137','30','0','0','0','0','0','SmartAI'),
('1507','10','0','1','75','0','100','0','0','0','0','0','33','168137','0','0','0','0','0','7','0','0','0','0','0','0','0','SmartAI'),
('1508','10','0','1','75','0','100','1','0','0','0','0','205','92','34558','0','0','0','0','7','0','0','0','0','0','0','0','SmartAI'),
('1508','10','1','2','61','0','100','0','0','0','0','0','205','92','34579','0','0','0','0','7','0','0','0','0','0','0','0','SmartAI'),
('1508','10','2','3','61','0','100','0','0','0','0','0','9','0','0','0','0','0','0','15','185482','200','0','0','0','0','0','SmartAI'),
('1508','10','3','0','61','0','100','0','0','0','0','0','50','286452','0','0','0','0','0','8','0','0','0','945.2','148.9','197.07','1.54','SmartAI'),
('1509','10','0','1','75','0','100','0','0','0','0','0','205','92','34559','0','0','0','0','7','0','0','0','0','0','0','0','SmartAI'),
('1509','10','1','0','61','0','100','0','0','0','0','0','62','1112','0','0','0','0','0','7','0','0','0','798.21','304.11','319.76','0.05','SmartAI');

UPDATE `eventobject` SET `spawnMask` = 4096 WHERE `map` = 1112; 
UPDATE `creature` SET `spawnMask` = 4096 WHERE `map` = 1112; 
UPDATE `gameobject` SET `spawnMask` = 4096 WHERE `map` = 1112; 

DELETE FROM `eventobject` WHERE `map`=1112;
INSERT INTO `eventobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(10003,1503,1112,6613,6613,4096,1,'',794.08,111.89,112.3,0),
(10004,1504,1112,6613,6613,4096,1,'',496.71,155.98,94.74,0),
(10005,1505,1112,6613,6613,4096,1,'',703.59,363.37,125.12,0),
(10006,1506,1112,6613,6613,4096,1,'',794.08,111.89,112.3,0),
(10007,1507,1112,6613,6613,4096,1,'',806.82,379.79,112.74,0),
(10008,1508,1112,6613,6613,4096,1,'',945.11,163.92,197.07,0),
(10009,1509,1112,6613,6613,4096,1,'',883.51,148.75,194.72,0);

-- Ashtongue Primalist SAI
SET @ENTRY := 68096;
UPDATE `creature_template` SET `AIName`="SmartAI" , `scriptname` ="" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,10,0,100,0,0,30,100,100,11,134112,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ashtongue Primalist - on range 30 yards - Cast stun in player"),
(@ENTRY,0,1,2,61,0,100,0,100,100,0,0,1,0,100,100,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Primalist - say text0"),
(@ENTRY,0,2,0,61,0,100,0,100,100,0,0,62,1112,0,0,0,0,0,7,0,0,0,712.492,996.786,53.3855,4.69817,"Ashtongue Primalist - Teleport player outside of black temple");

--  SAI
SET @ENTRY := 168137;
UPDATE `creature_template` SET `AIName`="SmartAI" , `scriptname` ="" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,25,0,100,0,0,0,0,0,75,134205,0,0,0,0,0,18,10,0,0,0,0,0,0,"SmartAI"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"SmartAI"),
(@ENTRY,0,2,3,62,0,100,0,15250,0,0,0,53,1,168137,0,0,0,0,1,0,0,0,0,0,0,0,"SmartAI"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"SmartAI"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"SmartAI"),
(@ENTRY,0,5,6,40,0,100,0,4,168137,0,0,54,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,"SmartAI"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"SmartAI"),
(@ENTRY,0,7,0,40,0,100,0,7,168137,0,0,1,5,7000,0,0,0,0,1,0,0,0,0,0,0,0,"SmartAI"),
(@ENTRY,0,8,9,52,0,100,0,5,168137,0,0,205,92,34545,0,0,0,0,18,10,0,0,0,0,0,0,"SmartAI"),
(@ENTRY,0,9,16,61,0,100,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"SmartAI"),
(@ENTRY,0,10,0,38,0,100,0,0,1,0,0,62,1112,0,0,0,0,0,8,0,0,0,794.08,111.89,112.3,3.44,"SmartAI"),
(@ENTRY,0,11,12,38,0,100,0,0,2,0,0,205,92,34554,0,0,0,0,18,2000,0,0,0,0,0,0,"SmartAI"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,752.68,149.39,112.74,1.81,"SmartAI"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,7,32340,0,0,0,0,0,18,20,0,0,0,0,0,0,"SmartAI"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,9,0,0,0,0,0,0,15,185479,500,0,0,0,0,0,"SmartAI"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"SmartAI"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,80,16981837,2,0,0,0,0,1,0,0,0,0,0,0,0,"SmartAI"),
(@ENTRY,0,60,0,60,0,100,0,1110,1110,11110,11110,9,0,0,0,0,0,0,15,185479,500,0,0,0,0,0,"SmartAI");

-- Actionlist SAI
SET @ENTRY := 16981837;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,7000,7000,0,0,69,0,0,0,0,0,0,8,0,0,0,794.08,111.89,112.3,3.44,"SmartAI"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,11,52370,0,0,0,0,0,1,0,0,0,0,0,0,0,"SmartAI");

-- Actionlist SAI
SET @ENTRY := 16813700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"SmartAI"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"SmartAI"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,75,134206,0,0,0,0,0,18,10,0,0,0,0,0,0,"SmartAI"),
(@ENTRY,9,3,0,0,0,100,0,3500,3500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"SmartAI"),
(@ENTRY,9,4,0,0,0,100,0,7500,7500,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"SmartAI"),
(@ENTRY,9,5,0,0,0,100,0,3000,3000,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"SmartAI");

UPDATE `smart_scripts` SET `event_param2` = '10' WHERE `entryorguid` = '68129' AND `source_type` = '0' AND `id` = '0' AND `link` = '1'; 

-- Actionlist SAI
SET @ENTRY := 16981837;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,7000,7000,0,0,69,0,0,0,0,0,0,8,0,0,0,794.08,111.89,112.3,3.44,"SmartAI"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,11,52370,0,0,0,0,0,1,0,0,0,0,0,0,0,"SmartAI");

DELETE FROM `lfg_entrances` WHERE `dungeonId` = '594';
INSERT INTO `lfg_entrances` (`dungeonId`, `name`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
('594', 'Pursuing the Black Harvest', '710.279', '988.731', '52.8447', '4.71239');

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (8696, 8698);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
('8696', 'at_pursuing_the_black_harvest_main'),
('8698', 'at_pursuing_the_black_harvest_main');

DELETE FROM `areatrigger_polygon` WHERE `entry` = '3764';
INSERT INTO  `areatrigger_polygon` (`entry`, `spellId`, `id`, `x`, `y`) VALUES
('3764', '134110', '0', '30', '0'),
('3764', '134110', '1', '27.71631', '11.48047'),
('3764', '134110', '2', '21.21338', '21.21338'),
('3764', '134110', '3', '11.48047', '27.71631'),
('3764', '134110', '4', '0', '30'),
('3764', '134110', '5', '-11.48047', '27.71631'),
('3764', '134110', '6', '-21.21338', '21.21338'),
('3764', '134110', '7', '-27.71631', '11.48047'),
('3764', '134110', '8', '-30', '0'),
('3764', '134110', '9', '-27.71631', '-11.48047'),
('3764', '134110', '10', '-21.21338', '-21.21338'),
('3764', '134110', '11', '-11.48047', '-27.71631'),
('3764', '134110', '12', '0', '-30'),
('3764', '134110', '13', '11.48047', '-27.71631'),
('3764', '134110', '14', '21.21338', '-21.21338'),
('3764', '134110', '15', '27.71631', '-11.48047');

DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (68098, 68137, 68129, 68096, 68204, 68175, 68176);
INSERT INTO `creature_equip_template` (`CreatureID`, `ItemID1`, `ItemID2`, `ItemID3`) VALUES
(68096, 29651, 0, 13924), -- 68096
(68204, 32731, 32731, 0), -- 68204
(68175, 32731, 0, 0), -- 68175
(68176, 32729, 0, 0), -- 68176
(68129, 29681, 0, 13924), -- 68129
(68137, 30699, 0, 0), -- 68137
(68098, 14707, 0, 0); -- 68098

DELETE FROM `scenario_poi` WHERE `criteriaTreeId` IN (31009, 31011, 31013, 31020, 31018, 31022, 31035);
INSERT INTO `scenario_poi` (`criteriaTreeId`, `BlobID`, `mapid`, `WorldMapAreaId`, `Floor`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`) VALUES
('31009', '0', '1112', '919', '0', '0', '0', '1359', '0'),
('31011', '1', '1112', '919', '2', '0', '0', '1566', '0'),
('31013', '2', '1112', '919', '3', '0', '0', '0', '0'),
('31020', '3', '1112', '919', '3', '0', '0', '0', '0'),
('31018', '4', '1112', '919', '3', '0', '0', '658', '0'),
('31022', '5', '1112', '919', '3', '0', '0', '0', '0'),
('31035', '5', '1112', '919', '7', '0', '0', '0', '0');

DELETE FROM `scenario_poi_points` WHERE `criteriaTreeId` IN (31009, 31011, 31013, 31020, 31018, 31022, 31035);
INSERT INTO `scenario_poi_points` (`criteriaTreeId`, `id`, `idx`, `x`, `y`) VALUES 
('31009', '0', '0', '702', '593'),
('31011', '0', '0', '702', '364'),
('31013', '0', '0', '687', '62'),
('31020', '0', '0', '496', '168'),
('31018', '0', '0', '494', '164'),
('31022', '0', '0', '779', '62'),
('31035', '0', '0', '677', '305');

UPDATE `gossip_menu_option` SET `MenuID` = '15258' WHERE `MenuID` = '15257' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `MenuID` = '15258' WHERE `MenuID` = '15257' AND `OptionIndex` = '2'; 

DELETE FROM `areatrigger_polygon` WHERE `entry` = '3764';
INSERT INTO  `areatrigger_polygon` (`entry`, `spellId`, `id`, `x`, `y`) VALUES
('3764', '134110', '0', '30', '0'),
('3764', '134110', '1', '27.71631', '11.48047'),
('3764', '134110', '2', '21.21338', '21.21338'),
('3764', '134110', '3', '11.48047', '27.71631'),
('3764', '134110', '4', '0', '30'),
('3764', '134110', '5', '-11.48047', '27.71631'),
('3764', '134110', '6', '-21.21338', '21.21338'),
('3764', '134110', '7', '-27.71631', '11.48047'),
('3764', '134110', '8', '-30', '0'),
('3764', '134110', '9', '-27.71631', '-11.48047'),
('3764', '134110', '10', '-21.21338', '-21.21338'),
('3764', '134110', '11', '-11.48047', '-27.71631'),
('3764', '134110', '12', '0', '-30'),
('3764', '134110', '13', '11.48047', '-27.71631'),
('3764', '134110', '14', '21.21338', '-21.21338'),
('3764', '134110', '15', '27.71631', '-11.48047');


DELETE FROM `areatrigger_scripts` WHERE `entry` IN ('8696', '8699', '8698', '8701', '8706', '8702', '8708', '8908');
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
('8696', 'at_pursuing_the_black_harvest_main'),
('8699', 'at_pursuing_the_black_harvest_main'),
('8698', 'at_pursuing_the_black_harvest_main'),
('8701', 'at_pursuing_the_black_harvest_main'),
('8706', 'at_pursuing_the_black_harvest_main'),
('8702', 'at_pursuing_the_black_harvest_main'),
('8708', 'at_pursuing_the_black_harvest_main'),
('8908', 'at_pursuing_the_black_harvest_main');