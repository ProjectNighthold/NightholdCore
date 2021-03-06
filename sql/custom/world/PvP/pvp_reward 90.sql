DELETE FROM `pvp_reward`  WHERE `Type` IN ('0','1','2','3','4','6','7','8');
INSERT INTO `pvp_reward` (`Type`, `BracketLevel`, `BaseLevel`, `ElitLevel`, `BonusBaseLevel`, `ChanceBonusLevel`, `ChestA`, `ChestH`, `ChestChance`, `QuestAFirst`, `QuestAWin`, `QuestAlose`, `QuestHFirst`, `QuestHWin`, `QuestHLose`, `ItemCAFirst`, `ItemCAWin`, `ItemCALose`, `ItemsChance`, `ItemsA`, `ItemsH`, `ItemsAElit`, `ItemsHElit`, `Relics`, `RelicsElit`, `RateLegendary`, `Comment`) VALUES 
('0', '90', '500', '0', '5', '5', '151557', '151558', '100', '0', '0', '0', '0', '0', '0', '0', '0', '0', '5', '', '', '', '', '', '', '0.1', 'Skirmish'),
('1', '90', '500', '0', '5', '15', '151557', '151558', '100', '0', '0', '0', '0', '0', '0', '0', '0', '89112', '20', '', '', '', '', '', '', '2', 'Random BG'),
('2', '90', '500', '0', '0', '0', '151557', '151558', '20', '0', '0', '0', '0', '0', '0', '0', '89112', '0', '15', '', '', '', '', '', '', '1', 'Arena 2v2'),
('3', '90', '500', '0', '0', '0', '151557', '151558', '20', '0', '0', '0', '0', '0', '0', '0', '89112', '0', '15', '', '', '', '', '', '', '1', 'Arena 3v3'),
('4', '90', '500', '0', '0', '0', '151557', '151558', '100', '0', '0', '0', '0', '0', '0', '0', '0', '89112', '20', '', '', '', '', '', '', '2', 'Rated BG'),
('6', '90', '500', '0', '0', '0', '151557', '151558', '20', '0', '0', '0', '0', '0', '0', '0', '0', '0', '30', '', '', '', '', '', '', '0', 'Deathmatch'),
('7', '90', '0', '0', '0', '0', '151557', '151558', '0', '0', '0', '0', '0', '0', '0', '0', '0', '89112', '0', '', '', '', '', '', '', '0', 'Brawl'),
('8', '90', '0', '0', '0', '0', '151557', '151558', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '', '', '', '', '0', 'Brawl Arena');


-- ALIANCE
DELETE FROM `item_loot_template`  WHERE `entry` = 151557;
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
('151557', '137642', '80', '1', '0', '1', '2'),
('151557', '72103', '25', '1', '0', '2', '8'),
('151557', '72094', '25', '1', '0', '2', '8'),
('151557', '72238', '25', '1', '0', '2', '8'),
('151557', '89112', '25', '1', '0', '2', '5'),
('151557', '102616', '1', '1', '0', '1', '1'),
('151557', '102680', '1', '1', '0', '1', '1'),
('151557', '102706', '1', '1', '0', '1', '1'),
('151557', '102625', '1', '1', '0', '1', '1'),
('151557', '102672', '1', '1', '0', '1', '1'),
('151557', '102738', '1', '1', '0', '1', '1'),
('151557', '102643', '1', '1', '0', '1', '1'),
('151557', '102699', '1', '1', '0', '1', '1'),
('151557', '102766', '1', '1', '0', '1', '1'),
('151557', '102701', '1', '1', '0', '1', '1'),
('151557', '102746', '1', '1', '0', '1', '1'),
('151557', '102649', '1', '1', '0', '1', '1'),
('151557', '102674', '1', '1', '0', '1', '1'),
('151557', '102758', '1', '1', '0', '1', '1'),
('151557', '102736', '1', '1', '0', '1', '1'),
('151557', '102757', '1', '1', '0', '1', '1'),
('151557', '102773', '1', '1', '0', '1', '1');

-- HORDA
DELETE FROM `item_loot_template`  WHERE `entry` = 151558;
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
('151558', '137642', '80', '1', '0', '1', '2'),
('151558', '72103', '25', '1', '0', '2', '8'),
('151558', '72094', '25', '1', '0', '2', '8'),
('151558', '72238', '25', '1', '0', '2', '8'),
('151558', '89112', '25', '1', '0', '2', '5'),
('151558', '103407', '1', '1', '0', '1', '1'),
('151558', '103408', '1', '1', '0', '1', '1'),
('151558', '103409', '1', '1', '0', '1', '1'),
('151558', '103530', '1', '1', '0', '1', '1'),
('151558', '103531', '1', '1', '0', '1', '1'),
('151558', '103532', '1', '1', '0', '1', '1'),
('151558', '103347', '1', '1', '0', '1', '1'),
('151558', '103506', '1', '1', '0', '1', '1'),
('151558', '103516', '1', '1', '0', '1', '1'),
('151558', '103517', '1', '1', '0', '1', '1'),
('151558', '103518', '1', '1', '0', '1', '1'),
('151558', '103370', '1', '1', '0', '1', '1'),
('151558', '103371', '1', '1', '0', '1', '1'),
('151558', '103372', '1', '1', '0', '1', '1'),
('151558', '103367', '1', '1', '0', '1', '1'),
('151558', '103368', '1', '1', '0', '1', '1'),
('151558', '103369', '1', '1', '0', '1', '1');