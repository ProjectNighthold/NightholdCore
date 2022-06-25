-- Fix Quest 34585
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=81360;

DELETE FROM `creature` WHERE `guid`=280001217;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(280001217, 81360, 1116, 0, 0, 1, 1, '', 0, 0, 1687.4, 225.875, 61.0682, 1.58579, 300, 0, 0, 187900, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `smart_scripts` WHERE `entryorguid`=81360 AND `source_type`=0 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-280001217 AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-280001217, 0, 0, 0, 4, 0, 100, 0, 3000, 5000, 15000, 15000, 11, 161781, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Smash');

-- quest 9570 -listo para testear
UPDATE `creature_template_wdb` SET `Name1`='El Kurken' WHERE (`Entry`='17447');
DELETE FROM `creature_loot_template` WHERE `entry`=17447 AND `item`=23860;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES (17447, 23860, -100, 1, 0, 1, 1, 0);
-- quest 9473 -listo para testear
DELETE FROM `gameobject_loot_template` WHERE `entry`=181644 AND `item`=23692;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (181644, 23692, -100, 1, 0, 1, 1);
-- quest 9506 -listo para testear
DELETE FROM `gameobject_loot_template` WHERE `entry`=181675 AND `item`=23738;
DELETE FROM `gameobject_loot_template` WHERE `entry`=181674 AND `item`=23739;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (181675, 23738, -100, 1, 0, 1, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (181674, 23739, -100, 1, 0, 1, 1);
DELETE FROM `gameobject` WHERE `guid`=7767;
DELETE FROM `gameobject` WHERE `guid`=7768;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `AiID`, `state`, `isActive`, `personal_size`) VALUES ('7767', '181674', '530', '3524', '3577', '1', '1', '', '-4600.9', '-12873.7', '8.27113', '3.09959', '-0', '-0', '-0.999779', '-0.0209998', '600', '100', '0', '1', '0', '0');
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `AiID`, `state`, `isActive`, `personal_size`) VALUES ('7768', '181675', '530', '3524', '3577', '1', '1', '', '-4630.08', '-12925.3', '9.627', '-2.35619', '0', '0', '0', '0', '121', '100', '0', '1', '0', '0');
-- quest 9527 -listo para testear
DELETE FROM `creature_loot_template` WHERE `entry`=17186 AND `item`=23789;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES (17186, 23789, -50, 0, 0, 1, 1, 0);
DELETE FROM `creature_loot_template` WHERE `entry`=17187 AND `item`=23789;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES (17187, 23789, -50, 0, 0, 1, 1, 0);
DELETE FROM `creature_loot_template` WHERE `entry`=17188 AND `item`=23789;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES (17188, 23789, -25, 0, 0, 1, 1, 0);
-- quest 9515 -listo para testear
DELETE FROM `quest_poi` WHERE `QuestID`=9515 AND `BlobIndex`=1 AND `Idx1`=1;
DELETE FROM `quest_poi` WHERE `QuestID`=9515 AND `BlobIndex`=0 AND `Idx1`=0;
DELETE FROM `quest_poi` WHERE `QuestID`=9515 AND `BlobIndex`=1 AND `Idx1`=3;
DELETE FROM `quest_poi` WHERE `QuestID`=9515 AND `BlobIndex`=0 AND `Idx1`=2;
DELETE FROM `quest_poi` WHERE `QuestID`=9515 AND `BlobIndex`=0 AND `Idx1`=1;
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `WorldMapAreaId`, `Floor`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `WoDUnk1`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (9515, 1, 1, -1, 0, 0, 530, 464, 0, 0, 1, 0, 0, 0, 0, 23877);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `WorldMapAreaId`, `Floor`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `WoDUnk1`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (9515, 0, 0, 0, 261253, 17298, 530, 464, 0, 0, 1, 0, 0, 0, 0, 23877);
