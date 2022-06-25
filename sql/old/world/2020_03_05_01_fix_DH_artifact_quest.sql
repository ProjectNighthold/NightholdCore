/*
Fix quest 41804
El objeto 248822 no tiene el loot necesario

NPC con textos en ruso 90417

NPC daño excesivo 99046

*/


DELETE FROM `gameobject_loot_template`  WHERE `entry` = '248822';
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('248822', '136385', '100', '1', '0', '1', '1');


DELETE FROM `creature_text` WHERE `Entry` = 90417 AND `GroupID` IN (0, 1, 2, 3, 4, 5, 6);
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
('90417', '0', '0', 'I have a just the thing. Fallow me.', '12', '0', '100', '1', '0', '0', '0', '0', '0', '0', 'Верховный маг Кадгар to Player'),
('90417', '1', '0', 'Hold on just a moment. I fear I\'m a bit of a pack rat.', '12', '0', '100', '1', '0', '0', '0', '0', '0', '0', 'Верховный маг Кадгар to Player'),
('90417', '2', '0', 'Now let\'s see... apexis crystals? No, no, those won\'t do at all', '12', '0', '100', '0', '0', '0', '0', '0', '0', '0', 'Верховный маг Кадгар to Player'),
('90417', '3', '0', 'Hmm. I must\'ve put it over here.', '12', '0', '100', '25', '0', '0', '0', '0', '0', '0', 'Верховный маг Кадгар to Player'),
('90417', '4', '0', 'Arcane powder... soul shards... that\'s definitely not it...', '12', '0', '100', '0', '0', '0', '0', '0', '0', '0', 'Верховный маг Кадгар to Player'),
('90417', '5', '0', 'A-ha! Here we are... a crystallized sould. That ought to do the trick!', '12', '0', '100', '0', '0', '0', '0', '0', '0', '0', 'Верховный маг Кадгар to Player'),
('90417', '6', '0', 'Would you mind grabbing it? These crystals tend to have an adverse effect on non-demonic beings.', '12', '0', '100', '6', '0', '0', '0', '0', '0', '0', 'Верховный маг Кадгар to Player');


UPDATE `creature_template_wdb` SET `HpMulti`='1', `PowerMulti`='1' WHERE (`Entry`='99046');

DELETE FROM `creature` WHERE `guid` = '12843697';
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
('12843697', '121014', '1220', '7502', '7505', '1', '1', '4602', '0', '0', '-857.828', '4268.08', '746.282', '0.194795', '180', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');
