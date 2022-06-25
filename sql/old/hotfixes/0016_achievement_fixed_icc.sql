-- Hotfix_Data
REPLACE INTO hotfix_data SELECT ID, 1255424668, ID, 0, 0 FROM legion_hotfixes.criteria_tree WHERE ID = 14348;
REPLACE INTO hotfix_data SELECT ID, 1255424668, ID, 0, 0 FROM legion_hotfixes.criteria_tree WHERE ID = 14702;
REPLACE INTO hotfix_data SELECT ID, 4012104832, ID, 0, 0 FROM legion_hotfixes.criteria WHERE ID = 13125;
REPLACE INTO hotfix_data SELECT ID, 4012104832, ID, 0, 0 FROM legion_hotfixes.criteria WHERE ID = 12757;
REPLACE INTO hotfix_data SELECT ID, 4218319612, ID, 0, 0 FROM legion_hotfixes.dungeon_encounter WHERE ID = 1098;

-- Buggy Achiev fix ICC 10 Player
DELETE FROM criteria_tree WHERE `ID` = 14348;
INSERT INTO criteria_tree (ID, Description, Amount, Flags, Operator, CriteriaID, Parent, OrderIndex, VerifiedBuild) VALUES (14348, 'Rescure Valithria Dreamwalker', 1, 0, 0, 13125, 14346, 1, 0);
DELETE FROM criteria WHERE `ID` = 13125;
INSERT INTO criteria (ID, Asset, StartAsset, FailAsset, ModifierTreeId, StartTimer, EligibilityWorldStateId, Type, StartEvent, FailEvent, Flags, EligibilityWorldStateValue, VerifiedBuild) VALUES (13125, 72706, 0, 0, 43, 0, 0, 28, 0, 0, 0, 0, 0);
DELETE FROM criteria_tree WHERE `ID` = 14702;
INSERT INTO criteria_tree (ID, Description, Amount, Flags, Operator, CriteriaID, Parent, OrderIndex, VerifiedBuild) VALUES (14702, 'Rescure Valithria Dreamwalker', 1, 0, 0, 12757, 14700, 1, 0);
DELETE FROM criteria WHERE `ID` = 12757;
INSERT INTO criteria (ID, Asset, StartAsset, FailAsset, ModifierTreeId, StartTimer, EligibilityWorldStateId, Type, StartEvent, FailEvent, Flags, EligibilityWorldStateValue, VerifiedBuild) VALUES (12757, 72706, 0, 0, 713, 0, 0, 28, 0, 0, 0, 0, 0);
DELETE FROM dungeon_encounter WHERE ID = 1098;
INSERT INTO dungeon_encounter (Name, CreatureDisplayID, MapID, DifficultyID, Bit, Flags, ID, OrderIndex, SpellIconFileID, VerifiedBuild) VALUES ('Valithria Dreamwalker', 30318, 631, 0, 3, 6, 1098, 10000, 0, 0); 
