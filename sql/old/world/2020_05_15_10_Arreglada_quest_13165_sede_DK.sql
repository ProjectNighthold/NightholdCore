-- Quest ID 13166 La Batalla por el bastion del Ebano
DELETE FROM `creature_queststarter` WHERE `id` = '29110';
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES ('29110', '12779');
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES ('29110', '12800');

-- Highlord Darion Mograine SAI
SET @ENTRY := 31084;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,13166,0,0,0,75,53642,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cast_Aura_quest"),
(@ENTRY,0,1,0,49,0,100,0,13166,0,0,0,28,53642,0,0,0,0,0,7,0,0,0,0,0,0,0,"Remove_aura_quest");

