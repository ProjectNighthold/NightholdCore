/* reparaciones para entregar en zona pandarian */
DELETE FROM `creature_questender` WHERE  `quest` IN (
31846,
31843,
31842,
31833,
31840,
31837,
31836,
31835,
31841,
31839);



INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(66207, 31846),
(66255, 31843),
(66253, 31842),
(65960, 31833),
(66258, 31840),
(66256, 31837),
(66255, 31836),
(66253, 31835),
(65960, 31841),
(66207, 31839);


/* para que los npc reciban la mision */
UPDATE `creature_template` SET `Npcflag` = 3 WHERE `entry` = 66207;
UPDATE `creature_template` SET `Npcflag` = 3 WHERE `entry` = 66149;
UPDATE `creature_template` SET `Npcflag` = 3 WHERE `entry` = 66255;
UPDATE `creature_template` SET `Npcflag` = 3 WHERE `entry` = 66253;
UPDATE `creature_template` SET `Npcflag` = 3 WHERE `entry` = 65960;
UPDATE `creature_template` SET `Npcflag` = 3 WHERE `entry` = 66258;
UPDATE `creature_template` SET `Npcflag` = 3 WHERE `entry` = 66256;
UPDATE `creature_template` SET `Npcflag` = 3 WHERE `entry` = 66149;

/*quita dialogo no saliente */
UPDATE `quest_template` SET `QuestType` = 2 WHERE `id` = 31835;
UPDATE `quest_template` SET `QuestType` = 2 WHERE `id` = 31836;
UPDATE `quest_template` SET `QuestType` = 2 WHERE `id` = 31837;
UPDATE `quest_template` SET `QuestType` = 2 WHERE `id` = 31838;
UPDATE `quest_template` SET `QuestType` = 2 WHERE `id` = 31839;
UPDATE `quest_template` SET `QuestType` = 2 WHERE `id` = 31846;
UPDATE `quest_template` SET `QuestType` = 2 WHERE `id` = 31845;
UPDATE `quest_template` SET `QuestType` = 2 WHERE `id` = 31843;
UPDATE `quest_template` SET `QuestType` = 2 WHERE `id` = 31842;
UPDATE `quest_template` SET `QuestType` = 2 WHERE `id` = 31841;
UPDATE `quest_template` SET `QuestType` = 2 WHERE `id` = 31840;
UPDATE `quest_template` SET `QuestType` = 0 WHERE `id` = 31944;
UPDATE `quest_template` SET `QuestType` = 2 WHERE `id` = 31833;

/* spawn de npc necesario */
replace into `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) values
("280109133", "65960", "870", "5841", "6526", "1", "65535", "", "0", "0", "3965.2", "1794.89", "907.161", "2.32857", "300", "0", "0", "8070", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");

/* borra quest que termina npc incorrecto y objetivos de dialogo se simplifica para seguir el leveo */	
DELETE FROM `creature_questender` WHERE `quest` IN (31833,31834,31835,31836,31837,31846,31843,31842,31841,31840,31839) and `id`= 66260;
DELETE FROM `quest_objectives` WHERE `QuestID` IN (31833,31834,31835,31836,31837,31846,31843,31842,31841,31840,31839,31845,31838,31845,31844) and `id`= 66260;

