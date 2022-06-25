-- Vanessa VanCleef SAI
SET @ENTRY := 102534;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,1,0,0,0,0,207,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"JS - SPI"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,1,0,10000,0,0,0,0,7,0,0,0,0,0,0,0,"Link - ST"),
(@ENTRY,0,2,0,52,0,100,1,0,102534,0,0,1,1,10000,0,0,0,0,7,0,0,0,0,0,0,0,"TO - ST"),
(@ENTRY,0,3,0,52,0,100,1,1,102534,0,0,1,2,8000,0,0,0,0,7,0,0,0,0,0,0,0,"TO - ST"),
(@ENTRY,0,4,0,52,0,100,1,2,102534,0,0,1,3,5000,0,0,0,0,7,0,0,0,0,0,0,0,"TO - ST"),
(@ENTRY,0,5,6,52,0,100,1,3,102534,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,"TO - SF"),
(@ENTRY,0,6,7,61,0,100,1,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - RUF"),
(@ENTRY,0,7,8,61,0,100,1,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Link - SA"),
(@ENTRY,0,8,0,61,0,100,1,0,0,0,0,1,4,0,0,0,0,0,7,0,0,0,0,0,0,0,"Link - ST"),
(@ENTRY,0,9,0,2,0,100,1,0,80,0,0,1,5,0,0,0,0,0,7,0,0,0,0,0,0,0,"On 80 % HP - ST"),
(@ENTRY,0,10,0,2,0,100,1,0,40,0,0,1,6,0,0,0,0,0,7,0,0,0,0,0,0,0,"On 80 % HP - ST"),
(@ENTRY,0,11,13,2,0,100,1,0,1,0,0,1,7,0,0,0,0,0,7,0,0,0,0,0,0,0,"On 1 % HP - ST"),
(@ENTRY,0,12,0,60,0,100,1,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Event Update - Set Invincibility"),
(@ENTRY,0,13,14,61,0,100,1,0,0,0,0,33,102534,0,0,0,0,0,7,0,0,0,0,0,0,0,"Link - KC"),
(@ENTRY,0,14,0,61,0,100,1,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Despawn");

-- Mision de Notas Conocimiento de Artefacto ya aliminadas
DELETE FROM `creature_queststarter` WHERE `id` = '102641' AND `quest` = '43823'; 
DELETE FROM `creature_queststarter` WHERE `id` = '102641' AND `quest` = '43885'; 
DELETE FROM `creature_queststarter` WHERE `id` = '102641' AND `quest` = '46129'; 
DELETE FROM `creature_queststarter` WHERE `id` = '102641' AND `quest` = '46148'; 