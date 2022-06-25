--  SAI
SET @ENTRY := 106335;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,3,54,0,100,1,0,0,0,0,11,210755,2,0,0,0,0,1,0,0,0,0,0,0,0,"JS - CS"),
(@ENTRY,0,1,0,0,0,100,0,3000,8000,6000,10000,11,186488,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,45,3,3,0,0,0,0,19,104949,0,0,0,0,0,0,"On Death - Send Data"),
(@ENTRY,0,3,4,61,0,100,1,0,0,0,0,11,210758,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - CS"),
(@ENTRY,0,4,0,61,0,100,1,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Link - Start Attack");

--  SAI
SET @ENTRY := 106344;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,3,54,0,100,1,0,0,0,0,11,210755,2,0,0,0,0,1,0,0,0,0,0,0,0,"JS - CS"),
(@ENTRY,0,1,0,0,0,100,0,3000,8000,6000,10000,11,214430,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,45,4,4,0,0,0,0,19,104949,0,0,0,0,0,0,"On Death - Send Data"),
(@ENTRY,0,3,4,61,0,100,1,0,0,0,0,11,210777,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - CS"),
(@ENTRY,0,4,0,61,0,100,1,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Link - Start Attack");

--  SAI
SET @ENTRY := 106341;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,3,54,0,100,1,0,0,0,0,11,210755,2,0,0,0,0,1,0,0,0,0,0,0,0,"JS - CS"),
(@ENTRY,0,1,0,0,0,100,0,3000,8000,6000,10000,11,194584,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,45,5,5,0,0,0,0,19,104949,0,0,0,0,0,0,"On Death - Send Data"),
(@ENTRY,0,3,4,61,0,100,1,0,0,0,0,11,210772,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - CS"),
(@ENTRY,0,4,0,61,0,100,1,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Link - Start Attack");

--  SAI
SET @ENTRY := 106354;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,2,8,0,100,1,210845,0,0,0,128,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"On Aggro - Stop AIEmote"),
(@ENTRY,0,1,0,60,0,100,1,0,0,0,0,128,10589,1,0,0,0,0,1,0,0,0,0,0,0,0,"Event Update - Play AIEmote"),
(@ENTRY,0,2,3,61,0,100,1,0,0,0,0,19,33555200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Remove Unit flag"),
(@ENTRY,0,3,0,61,0,100,1,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Link - Start Attack"),
(@ENTRY,0,4,0,0,0,100,0,3000,8000,6000,10000,11,211736,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell");

--  SAI
SET @ENTRY := 106347;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,210118,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spawn - Cast Visual Form"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Say Text 0"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,107,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summon Group"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,39,20,0,0,0,0,0,1,0,0,0,0,0,0,0,"Call for help"),
(@ENTRY,0,4,0,0,0,100,0,4000,4000,9000,9000,11,186480,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Buff"),
(@ENTRY,0,5,0,0,0,100,0,7000,7000,13000,16000,11,186488,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Overhead Slash");

--  SAI
SET @ENTRY := 104956;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,1,0,0,0,0,11,211008,0,0,0,0,0,1,0,0,0,0,0,0,0,"JS - CS"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,11,211017,0,0,0,0,0,1,0,0,0,0,0,0,0,"JS - CS"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,211018,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Aggro - CS"),
(@ENTRY,0,3,9,6,0,100,1,0,0,0,0,85,211034,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Death - CS"),
(@ENTRY,0,4,0,2,0,100,1,0,75,0,0,11,211019,0,0,0,0,0,1,0,0,0,0,0,0,0,"On 75% HP - CS"),
(@ENTRY,0,5,0,2,0,100,1,0,50,0,0,11,211028,0,0,0,0,0,1,0,0,0,0,0,0,0,"On 50% HP - CS"),
(@ENTRY,0,6,0,2,0,100,1,0,25,0,0,11,211032,0,0,0,0,0,1,0,0,0,0,0,0,0,"On 25% HP - CS"),
(@ENTRY,0,7,0,0,0,100,0,5000,9000,7000,12000,11,186476,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - CS"),
(@ENTRY,0,8,0,0,0,100,1,2000,4000,4000,8000,11,214433,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - CS"),
(@ENTRY,0,9,0,61,0,100,1,0,0,0,0,205,92,50631,0,0,0,0,21,50,0,0,0,0,0,0,"On Death - CSC");
