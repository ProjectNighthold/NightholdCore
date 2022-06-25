-- Quest 1456 "El Naufragio de Karnitol"
-- DB: Nordrassil Databse 
-- Core: Legion 7.3.5
-- Author: MistiX (andy.gg@cubava.cu)
-- Date: 05.04.2020

/* REPORTE http://10.96.2.10/bugtracker/view.php?id=141*/
DELETE FROM `creature_loot_template` WHERE `entry` = '4719';
DELETE FROM `creature_loot_template` WHERE `entry` = '4716';
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES ('4719', '6245', '-100', '0', '0', '1', '1', '0');
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES ('4716', '6245', '-100', '0', '0', '1', '1', '0');
