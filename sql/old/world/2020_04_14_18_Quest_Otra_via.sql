-- Otra vía (QuestID: 38617)  

/*Table_Creature_template_Cullen*/
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 92569;

/*Table_waypoints*/
DELETE FROM `waypoints` WHERE `entry` = 925690;
INSERT INTO `waypoints`(`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(925690, 1, 2398.67, 2310.71, 257.479, 'Waypoint Cullen Point 1'),
(925690, 2, 2387.64, 2337.32, 260.854, 'Waypoint Cullen Point 2'),
(925690, 3, 2375.02, 2352.35, 269.557, 'Waypoint Cullen Point 3'),
(925690, 4, 2370.37, 2359.75, 270.667, 'Waypoint Cullen Point 4'),
(925690, 5, 2355.81, 2374.54, 272.749, 'Waypoint Cullen Point 5'),
(925690, 6, 2348.97, 2379.68, 277.905, 'Waypoint Cullen Point 6'),
(925690, 7, 2355.56, 2385.87, 278.371, 'Waypoint Cullen Point 7'),
(925690, 8, 2358.59, 2382.47, 278.628, 'Waypoint Cullen Point 8'),
(925690, 9, 2351.61, 2374.58, 284.884, 'Waypoint Cullen Point 9'),
(925690, 10, 2348.5, 2378.06, 285.339, 'Waypoint Cullen Point 10'),
(925690, 11, 2354.09, 2384.31, 285.419, 'Waypoint Cullen Point 11'),
(925690, 12, 2360.74, 2378.42, 290.871, 'Waypoint Cullen Point 12'),
(925690, 13, 2355.96, 2372.93, 290.811, 'Waypoint Cullen Point 13'),
(925690, 14, 2348.71, 2378.93, 298.983, 'Waypoint Cullen Point 14'),
(925690, 15, 2352.88, 2384.33, 298.98, 'Waypoint Cullen Point 15'),
(925690, 16, 2361.55, 2376.34, 304.954, 'Waypoint Cullen Point 16'),
(925690, 17, 2357.88, 2372.23, 304.953, 'Waypoint Cullen Point 17'),
(925690, 18, 2346.27, 2381.78, 316.537, 'Waypoint Cullen Point 18'),
(925690, 19, 2350.34, 2387.54, 316.435, 'Waypoint Cullen Point 19'),
(925690, 20, 2360.28, 2377.77, 316.435, 'Waypoint Cullen Point 20'),
(925690, 21, 2358.5, 2373.13, 316.435, 'Waypoint Cullen Point 21');

/*Table_creature_text*/
DELETE FROM `creature_text` WHERE `Entry` = 92569;
INSERT INTO `creature_text`(`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES
(92569, 1, 0, 'Event pc1', 12, 0, 100, 1, 0, 0, 98748, 0, 0, 0, 'Inicio'),
(92569, 2, 0, 'Pc 2', 12, 0, 100, 1, 0, 0, 98749, 0, 0, 0, 'Text 2');

DELETE FROM `creature_text` WHERE `Entry` = 91240;
INSERT INTO `creature_text`(`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES
(91240, 1, 0, 'Text 1', 12, 0, 100, 0, 0, 0, 94003, 0, 0, 0, 'Inicio'),
(91240, 2, 0, 'Tex 2 final', 12, 0, 100, 0, 0, 0, 94004, 0, 0, 0, 'Text 2');

/*Table_Smart_Scripts*/

SET @Desespaw := 92573; -- Dread-Rider Cullen Event Desespaw
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@Desespaw;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Desespaw AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Desespaw,0,0,0,19,0,100,0,38617,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dread-Rider Cullen - On Quest '' Taken - Despawn Instant"),
(@Desespaw,0,1,0,19,0,100,0,38617,0,0,0,12,92569,6,0,0,0,0,1,0,0,0,0,0,0,0,"Dread-Rider Cullen - On Quest '' Taken - Summon Creature 'Dread-Rider Cullen'");

SET @TORRE := 98255; -- Kill credit
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@TORRE;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@TORRE AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@TORRE,0,0,0,10,0,100,0,4,6,0,0,33,98255,0,0,0,0,0,7,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)");

SET @Cullenquest := 92569; -- Event Wp and Text
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@Cullenquest;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Cullenquest AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Cullenquest,0,1,0,25,0,100,0,0,0,0,0,53,1,925690,0,0,0,0,7,0,0,0,0,0,0,0,"Dread-Rider Cullen - On Reset - Start Waypoint"),
(@Cullenquest,0,2,0,40,0,100,0,4,0,0,0,1,1,5000,0,0,0,0,7,0,0,0,0,0,0,0,"Dread-Rider Cullen - On Waypoint 3 Reached - Say Line 1"),
(@Cullenquest,0,5,0,40,0,100,0,21,0,0,0,1,2,5000,0,0,0,0,7,0,0,0,0,0,0,0,"Dread-Rider Cullen - On Waypoint 21 Reached - Say Line 2"),
(@Cullenquest,0,6,0,40,0,100,0,3,0,0,0,54,35000,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dread-Rider Cullen - On Waypoint 3 Reached - Pause Waypoint");

SET @WARRIOR := 91240; -- Gunnlaug Scaleheart
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@WARRIOR;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@WARRIOR AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@WARRIOR,0,0,0,2,0,100,0,50,90,12000,12000,1,1,12000,0,0,0,0,1,0,0,0,0,0,0,0,"Gunnlaug Scaleheart - In Combat - Say Line 1"),
(@WARRIOR,0,1,0,2,0,100,0,10,50,4000,4000,1,2,12000,0,0,0,0,1,0,0,0,0,0,0,0,"Gunnlaug Scaleheart - In Combat - Say Line 2"),
(@WARRIOR,0,2,0,0,0,100,0,3000,3000,3000,3000,11,871,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gunnlaug Scaleheart - In Combat - No Action Type"),
(@WARRIOR,0,3,0,0,0,100,0,3000,3500,3000,3500,11,18499,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gunnlaug Scaleheart - In Combat - No Action Type"),
(@WARRIOR,0,4,0,0,0,100,0,6000,6000,6000,6000,11,12975,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gunnlaug Scaleheart - In Combat - No Action Type"),
(@WARRIOR,0,5,0,0,0,100,0,2,2000,2000,3000,11,6343,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gunnlaug Scaleheart - In Combat - No Action Type");
