-- Depositario de niebla SAI
SET @ENTRY := 100207;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,60,0,100,1,0,0,0,0,11,200047,0,0,0,0,0,1,0,0,0,0,0,0,0,"EU - ST"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Aggro - ST"),
(@ENTRY,0,2,0,0,0,100,1,2000,5000,5000,12000,11,199869,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - CS"),
(@ENTRY,0,3,4,6,0,100,1,0,0,0,0,205,92,48069,0,0,0,0,21,50,0,0,0,0,0,0,"On Death - CSC"),
(@ENTRY,0,4,0,61,0,100,1,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Link - ST"),
(@ENTRY,0,5,0,2,0,100,1,0,50,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"On 50 % HP - ST"),
(@ENTRY,0,6,0,8,0,100,1,3355,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"SH - Die");

-- Depositario de niebla SAI
SET @ENTRY := 100173;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,60,0,100,1,0,0,0,0,11,200047,0,0,0,0,0,1,0,0,0,0,0,0,0,"EU - ST"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Aggro - ST"),
(@ENTRY,0,2,0,0,0,100,1,2000,5000,5000,12000,11,199869,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - CS"),
(@ENTRY,0,3,0,6,0,100,1,0,0,0,0,205,92,48069,0,0,0,0,21,50,0,0,0,0,0,0,"On Death - CSC"),
(@ENTRY,0,4,0,8,0,100,1,3355,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"SH - Die");

-- Acechador ilusorio SAI
SET @ENTRY := 100259;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,1,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"JS - SA"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,205,92,47634,0,0,0,0,21,100,0,0,0,0,0,0,"OD - CSC");

-- Dakarr SAI
SET @ENTRY := 100376;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,10,54,0,100,1,0,0,0,0,1,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"JS - ST"),
(@ENTRY,0,1,0,0,0,100,1,2000,5000,5000,8000,11,200348,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - CS"),
(@ENTRY,0,2,3,2,0,100,1,0,75,0,0,45,2,2,0,0,0,0,19,100236,0,0,0,0,0,0,"On 75% HP - SD"),
(@ENTRY,0,3,4,61,0,100,1,0,0,0,0,45,4,4,0,0,0,0,19,100235,0,0,0,0,0,0,"Link - SD"),
(@ENTRY,0,4,5,61,0,100,1,0,0,0,0,205,92,47640,0,0,0,0,21,100,0,0,0,0,0,0,"Link - CSC"),
(@ENTRY,0,5,0,61,0,100,1,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Despawn"),
(@ENTRY,0,6,7,2,0,100,1,0,60,0,0,45,6,6,0,0,0,0,19,100235,0,0,0,0,0,0,"On 60% HP - SD"),
(@ENTRY,0,7,8,61,0,100,1,0,0,0,0,205,92,47640,0,0,0,0,21,100,0,0,0,0,0,0,"Link - CSC"),
(@ENTRY,0,8,0,61,0,100,1,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Despawn"),
(@ENTRY,0,9,0,60,0,100,1,0,0,0,0,42,0,70,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Set Invincibility");

-- Dakarr SAI
SET @ENTRY := 99480;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,2000,5000,5000,8000,11,200348,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - CS"),
(@ENTRY,0,1,2,6,0,100,1,0,0,0,0,205,92,47688,0,0,0,0,21,50,0,0,0,0,0,0,"On Death - CSC"),
(@ENTRY,0,2,3,61,0,100,1,0,0,0,0,12,100310,8,0,0,0,0,8,0,0,0,3879.2,1639.85,0.0130663,2.58273,"Link - Sum NPC"),
(@ENTRY,0,3,4,61,0,100,1,0,0,0,0,50,248834,3600,0,0,0,0,8,0,0,0,3879.12,1639.92,-0.0738932,0,"Link - Sum GO"),
(@ENTRY,0,4,0,6,0,100,1,0,0,0,0,33,103798,0,0,0,0,0,21,50,0,0,0,0,0,0,"Link - KC");

-- Trampa de niebla SAI
SET @ENTRY := 100367;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,1,197489,0,0,0,28,197485,0,0,0,0,0,1,0,0,0,0,0,0,0,"SH - ST"),
(@ENTRY,0,1,2,61,0,100,1,0,0,0,0,80,100367,2,0,0,0,0,1,0,0,0,0,0,0,0,"Link - RTS"),
(@ENTRY,0,2,3,61,0,100,1,0,0,0,0,45,2,2,0,0,0,0,19,100235,0,0,0,0,0,0,"Link - SD"),
(@ENTRY,0,3,4,61,0,100,1,0,0,0,0,12,100259,3,10000,0,0,0,8,0,0,0,3660,1845.78,0.531402,0,"Link - SC"),
(@ENTRY,0,4,5,61,0,100,1,0,0,0,0,12,100259,3,10000,0,0,0,8,0,0,0,3667.42,1845.37,0.923863,0,"Link - SC"),
(@ENTRY,0,5,12,61,0,100,1,0,0,0,0,12,100259,3,10000,0,0,0,8,0,0,0,3663.79,1851.6,1.00102,0,"Link - SC"),
(@ENTRY,0,6,7,8,0,100,1,197489,0,0,0,28,197485,0,0,0,0,0,1,0,0,0,0,0,0,0,"SH - ST"),
(@ENTRY,0,7,8,61,0,100,1,0,0,0,0,80,100367,2,0,0,0,0,1,0,0,0,0,0,0,0,"Link - RTS"),
(@ENTRY,0,8,9,61,0,100,1,0,0,0,0,45,3,3,0,0,0,0,19,100235,0,0,0,0,0,0,"Link - SD"),
(@ENTRY,0,9,10,61,0,100,1,0,0,0,0,12,100259,3,10000,0,0,0,8,0,0,0,3739.09,1702.78,1.23611,0,"Link - SC"),
(@ENTRY,0,10,11,61,0,100,1,0,0,0,0,12,100259,3,10000,0,0,0,8,0,0,0,3739.09,1702.78,1.23611,0,"Link - SC"),
(@ENTRY,0,11,12,61,0,100,1,0,0,0,0,12,100259,3,10000,0,0,0,8,0,0,0,3735.46,1709,0.960069,1.00102,"Link - SC"),
(@ENTRY,0,12,0,61,0,100,1,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Set Npc Flag");

-- Dorro Monte Alto SAI
SET @ENTRY := 100005;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,60,0,100,1,0,0,0,0,80,100005,2,0,0,0,0,1,0,0,0,0,0,0,0,"EU - ST");

-- List Dorro Monte Alto SAI
SET @ENTRY := 100005;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,60,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"EU - ST"),
(@ENTRY,9,1,0,61,0,100,0,0,0,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"EU - ST"),
(@ENTRY,9,2,0,61,0,100,0,0,0,0,0,50,245213,3000,0,0,0,0,8,0,0,0,3874.75,1633.76,0.2353,1.9836,"EU - Dalaran");