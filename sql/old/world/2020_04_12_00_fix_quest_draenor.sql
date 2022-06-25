/* mision https://es.wowhead.com/quest=34285/equiparse */
REPLACE INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(228990, 110229, 100, 1, 0, 1, 1) /* wynn's Armor */;
REPLACE INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(229019, 110232, 100, 1, 0, 1, 1) /* wynn's Dagger */;
REPLACE INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(228577, 110149, 100, 1, 0, 1, 1) /* wynn's Mace */;
/* spawns de los objetos de la mision q no estaban*/
REPLACE into `gameobject`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `AiID`, `state`, `isActive`, `personal_size`) values("25675443", "228577", "1116", "6720", "6968", "1", "1", "", "7629.27", "4788.77", "183.389", "1.87394", "-0", "-0", "-0.805769", "-0.59223", "300", "0", "0", "1", "0", "0"),
("25675444", "229019", "1116", "6720", "6968", "1", "1", "", "7536.42", "4742.51", "138.421", "5.45131", "-0", "-0", "-0.404046", "0.914739", "300", "0", "0", "1", "0", "0"),("25675446", "228990", "1116", "6720", "6968", "1", "1", "", "7639.8", "4482.32", "136.471", "0.170053", "-0", "-0", "-0.0849243", "-0.996387", "300", "0", "0", "1", "0", "0");
/* omito dialogo k no sale para seguir con cadena de misiones draenor */
UPDATE `quest_template` SET `QuestType` = 0 WHERE `id` = 36134;
UPDATE `quest_template` SET `QuestType` = 0 WHERE `id` = 36341;
UPDATE `quest_template` SET `QuestType` = 0 WHERE `id` = 36342;
UPDATE `quest_template` SET `QuestType` = 0 WHERE `id` = 38408;
REPLACE INTO `creature_questender`(`id`,`quest`)VALUES
("78564", "38408");
UPDATE `quest_template` SET `QuestType` = 0 WHERE `id` = 34692;
UPDATE `quest_template` SET `QuestType` = 0 WHERE `id` = 36624;
