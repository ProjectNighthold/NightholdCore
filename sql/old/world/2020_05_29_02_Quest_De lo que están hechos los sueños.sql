/* [La Pesadilla Esmeralda: De lo que están hechos los sueños][ID: 43362] */

/* Xavius {NPCID:103769} */

DELETE FROM `quest_objectives` WHERE (`ID`='285234');
DELETE FROM `quest_objectives` WHERE (`ID`='286321');
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES 
('286321', '43362', '0', '1', '103769', '1', '0', '0', '0', NULL, '22045');
