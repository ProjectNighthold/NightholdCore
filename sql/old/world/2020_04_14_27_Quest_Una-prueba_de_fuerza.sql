-- Una prueba de fuerza (QuestID:39594)  

/*Table_Creature_template*/
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 96175;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 89817;

/*Table_creature_text*/
DELETE FROM `creature_text` WHERE `Entry` = 96175;

INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `comment`) VALUES 
(96175, 1, 0, 'Espero que lo tengas todo listo para afrontar tu primera prueba', 14, 0, 100, 1, 0, 0, 0,  'Inicio'),
(96175, 2, 0, 'Como vigia de esta camara es mi deber poner a prueba la fuerza de los q desean acceder', 14, 0, 100, 1, 0, 0, 0, 'Text 2'),
(96175, 3, 0, '¡Preparate!', 14, 0, 100, 1, 0, 0, 0, 'Text 3');

/*Table_smart_scripts*/
SET @PoweredConsole := 243817; -- Gobject Powered Console
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@PoweredConsole;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PoweredConsole AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@PoweredConsole,1,0,0,64,0,100,0,0,0,0,0,33,96290,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gameobject - Event - Action (phase) (dungeon difficulty)");

SET @Yotnar := 96175;  -- Creature Yotnar
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@Yotnar;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Yotnar AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Yotnar,0,0,0,0,0,100,0,4000,5000,6000,6000,1,1,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Yotnar - In Combat - No Action Type"),
(@Yotnar,0,1,0,52,0,100,0,1,96175,0,0,1,2,7000,0,0,0,0,1,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)"),
(@Yotnar,0,2,0,52,0,100,0,2,96175,0,0,1,3,8000,0,0,0,0,1,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)"),
(@Yotnar,0,3,0,0,0,100,0,3000,3500,4000,4100,11,255773,0,0,0,0,0,2,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)"),
(@Yotnar,0,4,0,0,0,100,0,3000,3500,4000,4100,11,252828,0,0,0,0,0,2,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)"),
(@Yotnar,0,5,0,0,0,100,0,9000,9000,9000,9000,11,26662,0,0,0,0,0,2,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)"),
(@Yotnar,0,6,0,0,0,100,0,3000,3500,4000,4100,11,256893,0,0,0,0,0,2,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)");
