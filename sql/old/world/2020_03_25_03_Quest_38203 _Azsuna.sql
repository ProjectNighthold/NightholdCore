/* Npc quest giver in azsunas - quest  38203*/
DELETE FROM `creature` WHERE `id`='91065';
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES ('147086100', '91065', '1220', '7334', '7517', '1', '1', '', '0', '0', '1251.55', '6705.11', '114.207', '6.20224', '300', '0', '0', '831414', '1100000', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');

/*
quest 38203 Viñedos Challiane
Modificando el loot por WoW freak
son npc elites que estan spanados 1 sola vez y tieenn el looteo bajo
*/

UPDATE `creature_loot_template` SET `ChanceOrQuestChance`='-100' WHERE `item`='122393';
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`='-100' WHERE `item`='122394';
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`='-100' WHERE `item`='122395';