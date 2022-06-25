-- Pagado con sangre vital (QuestID:39855)     

/*Table_condition*/
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=18790 AND `SourceEntry`=1 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 18790, 1, 0, 0, 9, 0, 39855, 0, 0, 0, 0, '', 'Show gossip menu 18790 option id 1 if quest Paid in Lifeblood has been taken.');

/*Table_Creature_Template*/
UPDATE `creature_template` SET `gossip_menu_id` = 0 WHERE `entry` = 97664;
UPDATE `creature_template` SET `AIName` = 'SmarAI' WHERE `entry` = 91387;

/* Table_creature_Text*/

DELETE FROM `creature_text` WHERE `Entry` = 91387; -- Helya
INSERT INTO `creature_text`(`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
(91387, 0, 0, 'Such insolence! None will leave Helheim while I rule!', 12, 0, 0, 1, 0, 0, 98498, 0, 0, 0, ''),
(91387, 1, 0, 'What? This cannot be!', 12, 0, 0, 1, 0, 0, 98499, 0, 0, 0, ''),
(91387, 2, 0, 'No one leaves Helheim! No one!', 12, 0, 0, 1, 0, 0, 98501, 0, 0, 0, ''),
(91387, 3, 0, 'Nooooo!', 12, 0, 0, 1, 0, 0, 98503, 0, 0, 0, '');

DELETE FROM `creature_text` WHERE `Entry` = 97664; -- Valkyr
INSERT INTO `creature_text`(`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
(97664, 0, 0, 'It is done, Helya! We have fulfilled your bargain, and we will collect our payment!', 12, 0, 0, 1, 0, 0, 98497, 0, 0, 0, ''),
(97664, 1, 0, 'Her hold is weakening. She cannot keep us here!', 12, 0, 0, 1, 0, 0, 98500, 0, 0, 0, ''),
(97664, 2, 0, 'Your terms were met, Helya. It seems even you must honor your word.', 12, 0, 0, 1, 0, 0, 98502, 0, 0, 0, '');


/*Table_smart_scripts*/
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=244559; -- Evento Helya
DELETE FROM `smart_scripts` WHERE `entryorguid`IN (2445590, 244559);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(244559,1,0,0,62,0,100,0,18790,0,0,0,33,97479,0,0,0,0,0,7,0,0,0,0,0,0,0,"Helya's Altar - On Gossip Option 0 Selected - Quest Credit ''"),
(244559,1,1,0,62,0,100,0,18790,1,0,0,80,2445590,2,0,0,0,0,1,0,0,0,0,0,0,0,"Helya's Altar - On Gossip Option 1 Selected - Run Script"),
(244559,1,2,0,62,0,100,0,18790,1,0,0,33,97479,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gameobject - Event - Action (phase) (dungeon difficulty)"),
(2445590,9,0,0,1,0,100,0,500,4000,0,0,1,0,1000,0,0,0,0,11,97664,40,0,0,0,0,0,"Helya's Altar - On Gossip Option 1 Selected - Say Line 0"),
(2445590,9,1,0,1,0,100,0,3500,5000,0,0,1,0,1000,0,0,0,0,10,600001061,91387,0,0,0,0,0,"Helya's Altar -Say Line 0"),
(2445590,9,2,0,1,0,100,0,4500,5500,0,0,1,1,1000,0,0,0,0,10,600001061,91387,0,0,0,0,0,"Helya's Altar - Say Line 1"),
(2445590,9,3,0,1,0,100,0,4000,5500,0,0,1,1,1000,0,0,0,0,11,97664,40,0,0,0,0,0,"Helya's Altar -Say Line 1"),
(2445590,9,4,0,1,0,100,0,5000,6500,0,0,1,2,1000,0,0,0,0,10,600001061,91387,0,0,0,0,0,"Helya's Altar - Say Line 2"),
(2445590,9,5,0,1,0,100,0,6000,7500,0,0,1,2,1000,0,0,0,0,11,97664,40,0,0,0,0,0,"Helya's Altar - Say Line 2"),
(2445590,9,6,0,1,0,100,0,7000,7500,0,0,1,3,1000,0,0,0,0,10,600001061,91387,0,0,0,0,0,"Helya's Altar - Say Line 3"),
(2445590,9,7,0,0,0,100,0,0,0,0,0,62,1220,0,0,0,0,0,7,0,0,0,3149.79,1536.71,181.52,5.93726,"Helya's Altar - On Script - Teleport");


SET @Ashildir:= 97480; -- Ashildir 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@Ashildir;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Ashildir AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Ashildir,0,0,0,19,0,100,0,39855,0,0,0,53,1,974800,0,0,0,0,0,0,0,0,0,0,0,0,"Ashildir - On Quest '' Taken - Start Waypoint"),
(@Ashildir,0,1,0,40,0,100,0,20,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashildir - On Waypoint 20 Reached - Despawn Instant"),
(@Ashildir,0,2,0,40,0,100,0,20,0,0,0,12,97664,3,1080000,0,0,0,1,0,0,0,0,0,0,0,"Ashildir - On Waypoint 20 Reached - Summon Creature 'Ashildir'");


/*Table_waypoints*/
DELETE FROM `waypoints` WHERE `entry` = 974800;
INSERT INTO `waypoints`(`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(974800, 1, 324.624, 583.424, 5.79154, 'Waypoint AshildirPoint 1'),
(974800, 2, 326.368, 599.262, 5.78858, 'Waypoint Ashildir Point 2'),
(974800, 3, 332.736, 611.474, 3.26192, 'Waypoint Ashildir Point 3'),
(974800, 4, 335.614, 638.886, 0.645219, 'Waypoint Ashildir Point 4'),
(974800, 5, 358.827, 647.485, 0.440602, 'Waypoint Ashildir Point 5'),
(974800, 6, 384.184, 655.014, 0.500789, 'Waypoint Ashildir Point 6'),
(974800, 7, 396.719, 654.925, 2.03973, 'Waypoint Ashildir Point 7'),
(974800, 8, 407.625, 655.041, 4.50805, 'Waypoint Ashildir Point 8'),
(974800, 9, 422.608, 659.081, 5.01158, 'Waypoint Ashildir Point 9'),
(974800, 10, 428.067, 661.233, 6.0051, 'Waypoint Ashildir Point 10'),
(974800, 11, 432.864, 665.07, 6.82609, 'Waypoint Ashildir Point 11'),
(974800, 12, 439.162, 681.016, 8.11943, 'Waypoint Ashildir Point 12'),
(974800, 13, 439.916, 690.952, 10.4867, 'Waypoint Ashildir Point 13'),
(974800, 14, 439.239, 697.508, 14.0616, 'Waypoint Ashildir Point 14'),
(974800, 15, 454.451, 701.804, 19.6246, 'Waypoint Ashildir Point 15'),
(974800, 16, 463.223, 704.78, 19.6247, 'Waypoint Ashildir Point 16'),
(974800, 17, 471.598, 707.988, 19.6914, 'Waypoint Ashildir Point 17'),
(974800, 18, 476.335, 710.513, 21.6087, 'Waypoint Ashildir Point 18'),
(974800, 19, 482.745, 712.583, 23.3226, 'Waypoint Ashildir Point 19'),
(974800, 20, 489.265, 716.225, 23.2534, 'Waypoint Ashildir Point 20');


/*Table_Creature*/
DELETE FROM `creature` WHERE `guid` = 6730000;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES
(6730000, 91387, 1463, 7588, 7629, 0, 1, '', 0, 0, 498.976776, 769.413757, 0.000190, 3.846030, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

UPDATE `creature` SET `spawntimesecs` = 60 WHERE `guid` = 20529168;
UPDATE `creature_template` SET `npcflag` = 2 WHERE `entry` IN (97480, 97664);

/*Table_quest_objetives*/
DELETE FROM `quest_objectives` WHERE `ID` = 280035;
INSERT INTO `quest_objectives`(`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `Taskstep`, `Description`, `VerifiedBuild`) VALUES
(280035, 39855, 0, 0, 97479, 1, 0, 0, 0, 'Helheim Escaped', 25996);
