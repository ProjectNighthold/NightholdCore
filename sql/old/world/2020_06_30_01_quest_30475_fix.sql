-- http://10.96.2.10/bugtracker/view.php?id=102
DELETE FROM `creature_loot_template` WHERE `entry`=59641 AND `item`=80233;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES (59641, 80233, -100, 1, 0, 1, 1, 0);
