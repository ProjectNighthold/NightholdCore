-- http://10.96.2.10/bugtracker/view.php?id=159
DELETE FROM `creature_loot_template` WHERE `entry`=25716 AND `item`=35668;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES (25716, 35668, -100, 1, 0, 1, 1, 0);
