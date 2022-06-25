-- New Achiev 80 Exalted
DELETE FROM `achievement` WHERE `ID`=12463;
INSERT INTO `achievement` (`Title`, `Description`, `Reward`, `Flags`, `InstanceID`, `Supercedes`, `Category`, `UiOrder`, `SharesCriteria`, `Faction`, `Points`, `MinimumCriteria`, `ID`, `IconFileID`, `CriteriaTree`, `VerifiedBuild`) VALUES ('80 Exalted Reputations', 'Raise 80 reputations to Exalted.', 'Title: the Admired', 12288, -1, 11177, 201, 14, 0, -1, 10, 0, 12463, 236688, 65612, 0);
REPLACE INTO hotfix_data SELECT ID, 3538824359, ID, 0, 0 FROM legion_hotfixes.achievement WHERE ID = 12463;

-- New Achiev Criteria 80 Exalted
DELETE FROM `criteria_tree` WHERE `ID`=65612;
INSERT INTO `criteria_tree` (`ID`, `Description`, `Amount`, `Flags`, `Operator`, `CriteriaID`, `Parent`, `OrderIndex`, `VerifiedBuild`) VALUES (65612, 'Raise 80 reputations to Exalted.', 0, 0, 4, 0, 0, 0, 0);
DELETE FROM `criteria_tree` WHERE `ID`=65613;
INSERT INTO `criteria_tree` (`ID`, `Description`, `Amount`, `Flags`, `Operator`, `CriteriaID`, `Parent`, `OrderIndex`, `VerifiedBuild`) VALUES (65613, '(NULL)', 80, 1, 0, 982, 65612, 0, 0);
REPLACE INTO hotfix_data SELECT ID, 1255424668, ID, 0, 0 FROM legion_hotfixes.criteria_tree WHERE ID = 65612;
REPLACE INTO hotfix_data SELECT ID, 1255424668, ID, 0, 0 FROM legion_hotfixes.criteria_tree WHERE ID = 65613;

-- New Title for 80 Exalted
DELETE FROM `char_titles` WHERE `ID`=562;
INSERT INTO `char_titles` (`ID`, `Name`, `Name1`, `MaskID`, `Flags`, `VerifiedBuild`) VALUES (562, '%s the Admired', '%s the Admired', 380, 0, 0);
REPLACE INTO hotfix_data SELECT ID, 2246024846, ID, 0, 0 FROM legion_hotfixes.char_titles WHERE ID = 562;

-- Achievement Variety is the Spice of Life
-- Change 100 World Quest Achiev to 10 WQ
DELETE FROM achievement WHERE ID=11189;
INSERT INTO achievement (Title, Description, Reward, Flags, InstanceID, Supercedes, Category, UiOrder, SharesCriteria, Faction, Points, MinimumCriteria, ID, IconFileID, CriteriaTree, VerifiedBuild) VALUES ('Variety is the Spice of Life', 'Complete 10 World Quests.', NULL, 131200, -1, 0, 15252, 31, 0, -1, 10, 0, 11189, 1060986, 54305, 4200);
DELETE FROM criteria_tree WHERE ID=54305;
INSERT INTO criteria_tree (ID, Description, Amount, Flags, Operator, CriteriaID, Parent, OrderIndex, VerifiedBuild) VALUES (54305, 'Achievement - 10 Diffrent World Quests', 10, 0, 8, 0, 0, 0, 4200);
-- hotfixdata
REPLACE INTO hotfix_data SELECT ID, 3538824359, ID, 0, 0 FROM legion_hotfixes.achievement WHERE ID = 11189;
REPLACE INTO hotfix_data SELECT ID, 1255424668, ID, 0, 0 FROM legion_hotfixes.criteria_tree WHERE ID = 54305;