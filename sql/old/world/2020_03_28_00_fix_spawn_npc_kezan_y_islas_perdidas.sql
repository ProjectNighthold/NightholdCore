/*spwn npc garajo necesario para mision goblin kezan y islas perdidas*/
DELETE FROM `creature` WHERE `guid` = 6700017 AND `id` =34954;
DELETE FROM `creature` WHERE `guid` = 6700018 AND `id` =84185;
INSERT INTO  `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES
("6700017", "34954", "648", "4737", "4765", "1", "65535", "", "0", "0", "-8425.59", "1305.85", "102.157", "1.30191", "300", "0", "0", "144", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("6700018", "84185", "1116", "6721", "7319", "1", "65535", "", "0", "1", "7252.58", "1718.03", "98.1326", "3.72068", "300", "0", "0", "108727", "32000", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");
/*cambio de phases para mision islas perdidas */
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='35875');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='35882');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='39655');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36417');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36432');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='35894');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='35893');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='35897');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='35896');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='35995');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='35875');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36578');
UPDATE `creature` SET `PhaseMask`='15' WHERE (`id`='36145');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36149');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36176');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36161');
UPDATE `gameobject` SET `PhaseMask`='15' WHERE (`id`='195707');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='35904');
UPDATE `creature` SET `PhaseMask`='15' WHERE (`id`='36104');
UPDATE `creature` SET `PhaseMask`='15' WHERE (`id`='36117');
UPDATE `creature` SET `PhaseMask`='15' WHERE (`id`='36115');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36513');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36525');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36161');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36463');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36520');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36179');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36467');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36439');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36519');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36468');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36524');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36518');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36428');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36429');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36501');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36423');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36421');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36063');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36092');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36422');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36424');
UPDATE `gameobject` SET `PhaseMask`='65535' WHERE (`id`='196881');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='35917');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36469');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36523');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36600');
UPDATE `creature` SET `PhaseMask`='65535' WHERE (`id`='36650');

/* reacomodo de npc */
DELETE FROM `creature` WHERE `guid` = 190064 AND `id` =36188;
insert into `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) values
("190064", "36188", "648", "4720", "4781", "1", "65535", "", "0", "0", "874.364", "2756.3", "120.2", "5.01377", "300", "0", "0", "29874", "6800", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");

DELETE FROM `creature` WHERE `guid` = 190086 AND `id` =36425;
insert into `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) values
("190086", "36425", "648", "4720", "4781", "1", "1", "", "0", "0", "851.925", "2754.51", "117.437", "1.35112", "300", "0", "0", "187", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");

/*elimina speel de area que mataba al goblin*/
DELETE FROM `spell_area` WHERE  spell = 69010 AND `area` = "4720";
insert into `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `classmask`, `active_event`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) values
("69010", "4720", "14126", "14239", "0", "0", "0", "0", "2", "1", "64", "74");

/* spawn npc necesario de mision */
DELETE FROM `creature` WHERE `guid` = 6700019 AND `id` =39199;
DELETE FROM `creature` WHERE `guid` = 6700020 AND `id` =36608;
insert into `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) values
("6700019", "39199", "648", "4720", "4924", "1", "16384", "", "0", "0", "1906.87", "1874.45", "173.619", "0.329304", "300", "0", "0", "338", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("6700020", "36608", "648", "4720", "4721", "1", "65535", "", "0", "1", "537.478", "3272.21", "0.177854", "3.27755", "300", "0", "0", "87", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");
