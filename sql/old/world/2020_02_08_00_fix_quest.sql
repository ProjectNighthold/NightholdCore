/*
Fix Quest: 	Estofado de champiñones brillantes:id(12483)
Report: http://10.96.2.9/bugtracker/view.php?id=113
*/

UPDATE `gameobject_template` SET `type`='3' WHERE (`entry`='188345');
UPDATE `gameobject_template` SET `type`='3' WHERE (`entry`='188601');


/*
Fix Quest: Rompe el bloqueo:id(11153)
Report: http://10.96.2.9/bugtracker/view.php?id=112
*/
DELETE FROM `quest_poi` WHERE `QuestID` = 11153;
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `WorldMapAreaId`, `Floor`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `WoDUnk1`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES 
('11153', '8', '8', '-1', '0', '0', '571', '491', '0', '0', '1', '0', '0', '0', '0', '26365'),
('11153', '7', '7', '0', '254182', '23771', '571', '491', '0', '0', '1', '0', '0', '0', '0', '26365'),
('11153', '6', '6', '0', '254182', '23771', '571', '491', '0', '0', '1', '0', '0', '0', '0', '26365'),
('11153', '5', '5', '0', '254182', '23771', '571', '491', '0', '0', '1', '0', '0', '0', '0', '26365'),
('11153', '4', '4', '0', '254182', '23771', '571', '491', '0', '0', '1', '0', '0', '0', '0', '26365'),
('11153', '3', '3', '0', '254182', '23771', '571', '491', '0', '0', '1', '0', '0', '0', '0', '26365'),
('11153', '2', '2', '0', '254181', '23755', '571', '491', '0', '0', '1', '0', '0', '0', '0', '26365'),
('11153', '1', '1', '0', '254181', '23755', '571', '491', '0', '0', '1', '0', '0', '0', '0', '26365'),
('11153', '0', '0', '0', '254181', '23755', '571', '491', '0', '0', '1', '0', '0', '0', '0', '26365');

DELETE FROM `quest_poi_points` WHERE `QuestID` = 11153;
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES 
('11153', '8', '0', '1427', '-3149', '26365'),
('11153', '7', '3', '1595', '-2285', '26365'),
('11153', '7', '2', '1604', '-2271', '26365'),
('11153', '7', '1', '1614', '-2277', '26365'),
('11153', '7', '0', '1607', '-2291', '26365'),
('11153', '6', '3', '1213', '-2688', '26365'),
('11153', '6', '2', '1223', '-2680', '26365'),
('11153', '6', '1', '1235', '-2691', '26365'),
('11153', '6', '0', '1220', '-2700', '26365'),
('11153', '5', '3', '1697', '-2538', '26365'),
('11153', '5', '2', '1705', '-2529', '26365'),
('11153', '5', '1', '1716', '-2541', '26365'),
('11153', '5', '0', '1706', '-2549', '26365'),
('11153', '4', '3', '1064', '-2320', '26365'),
('11153', '4', '2', '1075', '-2316', '26365'),
('11153', '4', '1', '1082', '-2328', '26365'),
('11153', '4', '0', '1067', '-2338', '26365'),
('11153', '3', '3', '1455', '-2644', '26365'),
('11153', '3', '2', '1460', '-2629', '26365'),
('11153', '3', '1', '1477', '-2635', '26365'),
('11153', '3', '0', '1466', '-2648', '26365'),
('11153', '2', '5', '1608', '-2288', '26365'),
('11153', '2', '4', '1597', '-2283', '26365'),
('11153', '2', '3', '1583', '-2269', '26365'),
('11153', '2', '2', '1602', '-2274', '26365'),
('11153', '2', '1', '1638', '-2295', '26365'),
('11153', '2', '0', '1634', '-2297', '26365'),
('11153', '1', '5', '1468', '-2645', '26365'),
('11153', '1', '4', '1428', '-2631', '26365'),
('11153', '1', '3', '1431', '-2627', '26365'),
('11153', '1', '2', '1459', '-2633', '26365'),
('11153', '1', '1', '1475', '-2637', '26365'),
('11153', '1', '0', '1486', '-2647', '26365'),
('11153', '0', '4', '1678', '-2562', '26365'),
('11153', '0', '3', '1679', '-2538', '26365'),
('11153', '0', '2', '1722', '-2522', '26365'),
('11153', '0', '1', '1714', '-2539', '26365'),
('11153', '0', '0', '1682', '-2563', '26365');

DELETE FROM `conditions` WHERE `SourceEntry` = '42406' AND `ConditionValue1` = '4064';
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
('17', '0', '42406', '0', '0', '23', '0', '4064', '0', '0', '0', '0', '', 'spell only in area');


/*
Fix Quest: 	Tregua:id(11989)
Report: http://10.96.2.9/bugtracker/view.php?id=114
*/
-- Drakuru SAI
SET @ENTRY := 26423;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,9615,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Drakuru - On Gossip Select - Close Gossip"),
(@ENTRY,0,1,0,61,0,100,0,9615,0,0,0,85,50016,2,0,0,0,0,7,0,0,0,0,0,0,0,"Drakuru - On Gossip Select - Give kill credit"),
(@ENTRY,0,2,3,62,0,100,0,9615,1,0,0,85,50021,0,0,0,0,0,7,0,0,0,0,0,0,0,"Drakuru - On gossip option select - Invoker spellcast Replace Drakuru's Elixir"),
(@ENTRY,0,3,0,61,0,100,0,9615,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Drakuru - On gossip option select - Close gossip");


/*
Fix Quest: QuestID[11956]: Encuentra la filacteria
Report: http://10.96.2.9/bugtracker/view.php?id=165
*/
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`='100' WHERE (`entry`='26225') AND (`item`='35687');

