UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=39323;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (39323, 3932300);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(39323,0,0,1,19,0,100,0,25187,0,0,0,80,3932300,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thonk - Quest Accept - Action List'),
(3932300,9,1,2,1,0,100,0,3000,3000,0,0,33,39357,0,0,0,0,0,7,0,0,0,0,0,0,0,'Action List - Quest KC - Raggaran'),
(3932300,9,2,3,1,0,100,0,3000,3000,0,0,33,39358,0,0,0,0,0,7,0,0,0,0,0,0,0,'Action List - Quest KC - Flooded Hut'),
(3932300,9,3,4,1,0,100,0,3000,3000,0,0,33,39359,0,0,0,0,0,7,0,0,0,0,0,0,0,'Action List - Quest KC - Misha'),
(3932300,9,4,5,1,0,100,0,3000,3000,0,0,33,39360,0,0,0,0,0,7,0,0,0,0,0,0,0,'Action List - Quest KC - Zen''Taji');

--  SAI
SET @ENTRY := 38560;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,79,0,100,1,0,73436,5,0,33,38560,0,0,0,0,0,18,10,0,0,0,0,0,0,""),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,11,73436,10,0,0,0,0,0,"");

UPDATE `quest_objectives` SET `ObjectID` = '38560' WHERE `ID` = '267327'; 

--  SAI
SET @ENTRY := 106720;
UPDATE `creature_template` SET `AIName`="SmartAI" , `scriptname` ="" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,1,0,0,0,0,80,10672000,2,0,0,0,0,1,0,0,0,0,0,0,0,"JS - ST"),
(@ENTRY,0,1,2,20,0,100,0,42650,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"QR - ST"),
(@ENTRY,0,2,0,61,0,100,1,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - KC");

--  SAI
SET @ENTRY := 10672000;
UPDATE `creature_template` SET `AIName`="SmartAI" , `scriptname` ="" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Npc_AI"),
(@ENTRY,9,1,0,0,0,100,0,2000,2500,0,0,33,108229,0,0,0,0,0,18,20,0,0,0,0,0,0,"Npc_AI");