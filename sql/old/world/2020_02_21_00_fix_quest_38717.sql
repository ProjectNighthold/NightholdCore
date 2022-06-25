/*https://es.wowhead.com/quest=38717/prisi%C3%B3n-grajo-negro  QUEST REPORTADA EL BUGTRACKER DISCORD*/
DELETE FROM `creature_queststarter` WHERE ID = 92842 AND QUEST = 38717;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
('92842','38717');
DELETE FROM `creature_questender` WHERE ID = 92842 AND QUEST = 38717;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
('92842','38717');
DELETE FROM `creature_loot_template` WHERE Entry = 92419;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `ChanceOrQuestChance`, `LootMode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES 
('92419', '127863', '100',  '1', '0', '1', '1', '0');

