-- quest 14017 _____loot npc 35113 mision___ For sargero sacado de wowhead
DELETE FROM `creature_loot_template` WHERE `entry`=35113 AND `item`=47048;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES (35113, 47048, 100, 0, 0, 1, 1, 0);