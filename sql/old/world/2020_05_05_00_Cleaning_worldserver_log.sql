/* Cleaning LoadQuestPOI() log */
DELETE FROM `quest_poi` WHERE `QuestID`='3092';
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `WorldMapAreaId`, `Floor`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `WoDUnk1`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES ('3092', '0', '0', '-1', '256641', '9565', '1', '221', '0', '0', '1', '0', '0', '0', '0', '23877');
DELETE FROM `quest_poi_points` WHERE `QuestID`='3092';
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES ('3092', '0', '0', '-2905', '-263', '23877');
/* Quest do not have objectives in quest_objetive */
DELETE FROM `quest_poi` WHERE `QuestID`='31035';




