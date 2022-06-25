-- Where Dragons Rule (Quest 39652)  

/*Table_creature_Template*/

UPDATE `creature_template` SET `gossip_menu_id` = 0 WHERE `entry` = 92218;


/*Table_Smart_Scripts*/
SET @EXTRA := 240029;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@EXTRA;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@EXTRA AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@EXTRA,0,0,0,10,0,100,0,1,6,0,0,33,240029,0,0,0,0,0,7,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)");

-- Credit - Fly to the Top SAI
SET @MONTANANEVADA := 96466; 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@MONTANANEVADA;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@MONTANANEVADA AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MONTANANEVADA,0,0,0,10,0,100,0,1,6,0,0,33,96466,0,0,0,0,0,7,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)");

-- Credit - Fly to the Top SAI 2
SET @MONTANANEVADA2 := 96467; 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@MONTANANEVADA2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@MONTANANEVADA2 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MONTANANEVADA2,0,0,0,10,0,100,0,1,6,0,0,33,96467,0,0,0,0,0,7,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)");


/* Table_Creature_Text*/
DELETE FROM `creature_text` WHERE `Entry` = 92218;
INSERT INTO `creature_text`(`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(92218, 1, 0, 'Tex1', 12, 0, 100, 1, 0, 0, 98429, 'Inicio'),
(92218, 2, 0, 'tex2', 12, 0, 100, 1, 0, 0, 98430, 'Text 2'),
(92218, 3, 0, 'END TEXT', 12, 0, 100, 1, 0, 0, 98431, 'Text 3'),
(92218, 4, 0, 'END TEXT2', 12, 0, 100, 1, 0, 0, 98432, 'Text 4');
