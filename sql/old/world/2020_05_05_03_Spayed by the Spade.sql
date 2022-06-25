-- "Spayed by the Spade" (QuestID: 40014)

/*Table_creature_loot_template*/
DELETE FROM `gameobject_loot_template` WHERE `entry` = 244774 AND `item` IN (129128, 129131);
INSERT INTO `gameobject_loot_template`(`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(244774, 129128, 2, 1, 0, 1, 1),
(244774, 129131, 2, 1, 0, 1, 1);
