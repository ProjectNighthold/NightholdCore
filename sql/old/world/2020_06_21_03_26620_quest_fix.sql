-- primera quest de: http://10.96.2.10/bugtracker/view.php?id=53
DELETE FROM `creature_template_addon` WHERE `entry`=45517;

DELETE FROM `creature_loot_template` WHERE `entry`=45517 AND `item`=60989;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES (45517, 60989, -100, 1, 0, 1, 1, 0);


