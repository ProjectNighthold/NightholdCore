-- http://10.96.2.10/bugtracker/view.php?id=290
DELETE FROM `creature_loot_template` WHERE `entry`=111022 AND `item`=140198;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES (111022, 140198, -100, 1, 0, 1, 1, 0);
