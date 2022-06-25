/* https://es.wowhead.com/quest=24976/la-variedad-es-la-sal-de-la-muerte */
/* https://es.wowhead.com/object=202421/espina-de-xavren */
UPDATE `gameobject_template` SET `type`='3' WHERE (`entry`='202421');
/* inicio orcos magos */
-- Disable Shadowglen quests deprecated between 3.3.5/WotLK and Legion
DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (25149);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  25149, 0, '', '', 'Deprecated quest: nova-de-escarcha');
/*fix loot https://es.wowhead.com/quest=42766/el-enigma-del-barril */
DELETE FROM `creature_loot_template` WHERE `entry` = '42766' AND `item`= '138624';
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES
("42766", "138624", "100", "0", "0", "1", "1", "0");
