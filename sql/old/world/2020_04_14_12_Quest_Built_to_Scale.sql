-- Built to Scale (QuestID:38337) 

/*Table_smart_Script*/
SET @Drake1 := 91920; -- Stormwing Drake
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@Drake1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Drake1 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Drake1,0,0,0,6,0,100,0,0,0,0,0,7,38337,0,0,0,0,0,7,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)");


SET @Drake2 := 91202; -- Stormwing Drake 2
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@Drake2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Drake2 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Drake2,0,0,0,6,0,100,0,0,0,0,0,7,38337,0,0,0,0,0,7,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)");

/*TAble_Creature_loot_template*/
DELETE FROM `creature_loot_template` WHERE `entry` = 91486 AND `item` IN (124037, 122610);
INSERT INTO `creature_loot_template`(`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES
(91486, 122610, 100, 0, 0, 1, 1, 0),
(91486, 124037, 100, 0, 0, 1, 1, 0);
