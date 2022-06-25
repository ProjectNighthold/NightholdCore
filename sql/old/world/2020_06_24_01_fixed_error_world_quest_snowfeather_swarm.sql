-- fixed error in quest_point and quest_poi_points tables to world quest id 44892 "Snowfeather Swarm!" spanish traslation: "¡Enjambre Plumanívea!"
DELETE FROM `quest_poi` WHERE `QuestID`= 44892 AND `BlobIndex`= 0 AND `Idx1` = 7;
UPDATE `quest_poi` SET `WoDUnk1` = 0, `BlobIndex` = 0, `Flags` = 2 WHERE `QuestID` = 44892 AND `Idx1` IN (0, 1, 2, 3, 4, 5, 6);
DELETE FROM `quest_poi_points` WHERE `QuestID`= 44892;
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES 
('44892', '0', '0', '5709', '5350', '0'),
('44892', '0', '1', '5827', '5340', '0'),
('44892', '0', '2', '5995', '5222', '0'),
('44892', '0', '3', '6124', '5045', '0'),
('44892', '0', '4', '5974', '5090', '0'),
('44892', '0', '5', '5821', '5149', '0');
