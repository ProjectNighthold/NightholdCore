-- Quest 13831 "Marcas de Sentinax"
-- DB: Nordrassil Databse 
-- Core: Legion 7.3.5
-- Author: MistiX (andy.gg@cubava.cu)
-- Date: 05.04.2020

/*AQUI ESTOY TRADUCIENDO GOSSP DE NPC (Archmage Khadgar) EN DALARAN DE MISION ASALTO A LAS COSTAS QUEBRADA*/
UPDATE `gossip_menu_option` SET `MenuID`='20974', `OptionIndex`='0', `OptionNPC`='0', `OptionText`='Estoy Listo Para Partir ', `OptionType`='1', `OptionNpcflag`='1', `OptionNpcflag2`='0', `ActionMenuID`='0', `ActionPoiID`='0', `BoxCoded`='0', `BoxMoney`='0', `BoxCurrency`='0', `BoxText`='', `OptionBroadcastTextID`='0', `BoxBroadcastTextID`='0', `VerifiedBuild`='0' WHERE (`MenuID`='20974') AND (`OptionIndex`='0');

/*UPDATE Quest 13831 "Marcas de Sentinax"*/
UPDATE `quest_objectives` SET `ID`='290021', `QuestID`='47139', `Type`='1', `StorageIndex`='0', `ObjectID`='147582', `Amount`='100', `Flags`='0', `Flags2`='1', `TaskStep`='0', `Description`=NULL, `VerifiedBuild`='24015' WHERE (`ID`='290021');

DELETE FROM `creature_loot_template` WHERE `entry` = 118660;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`)
 VALUES 
(

118660, 147582, -100, 0, 0, 4, 6, 0

);

DELETE FROM `creature_loot_template` WHERE `entry` = 118657;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) 
VALUES 
(

118657, 147582, -100, 0, 0, 3, 4, 0

);

DELETE FROM `creature_loot_template` WHERE `entry` = 117086;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) 
VALUES 
(

117086, 147582, -100, 0, 0, 3, 5, 0

);

DELETE FROM `creature_loot_template` WHERE `entry` = 120583;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) 
VALUES 
(

120583, 147582, -100, 0, 0, 10, 15, 0

);

DELETE FROM `creature` WHERE `guid` = 146732564;
INSERT INTO `creature`
(
 `guid`, 
 `id`, 
 `map`, 
 `zoneId`, 
 `areaId`, 
 `spawnMask`, 
 `phaseMask`, 
 `PhaseId`, 
 `modelid`, 
 `equipment_id`, 
 `position_x`, 
 `position_y`, 
 `position_z`, 
 `orientation`,
 `spawntimesecs`,
 `spawndist`, 
 `currentwaypoint`, 
 `curhealth`, 
 `curmana`, 
 `MovementType`, 
 `npcflag`, 
 `npcflag2`, 
 `unit_flags`, 
 `dynamicflags`, 
 `AiID`, 
 `MovementID`, 
 `MeleeID`, 
 `isActive`, 
 `skipClone`, 
 `personal_size`, 
 `isTeemingSpawn`, 
 `unit_flags3`

)
VALUES
(
	
 146732564, 
 121921, 
 1220, 
 7543, 
 8584, 
 1, 
 1, 
 '', 
 0, 
 0, 
 -1143.15, 
 2939.05, 
 -10.7688, 
 4.79609, 
 300, 
 0, 
 0, 
 25981676, 
 220000, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0,
 0

);

DELETE FROM `creature` WHERE `guid` = 146732578;
INSERT INTO `creature`
(
 `guid`, 
 `id`, 
 `map`, 
 `zoneId`, 
 `areaId`, 
 `spawnMask`, 
 `phaseMask`, 
 `PhaseId`, 
 `modelid`, 
 `equipment_id`, 
 `position_x`, 
 `position_y`, 
 `position_z`, 
 `orientation`,
 `spawntimesecs`,
 `spawndist`, 
 `currentwaypoint`, 
 `curhealth`, 
 `curmana`, 
 `MovementType`, 
 `npcflag`, 
 `npcflag2`, 
 `unit_flags`, 
 `dynamicflags`, 
 `AiID`, 
 `MovementID`, 
 `MeleeID`, 
 `isActive`, 
 `skipClone`, 
 `personal_size`, 
 `isTeemingSpawn`, 
 `unit_flags3`

)
VALUES
(

 146732578, 
 120583, 
 1220, 
 7543, 
 8584, 
 1, 
 1, 
 '', 
 0, 
 0, 
 -1141.64, 
 2955.67, 
 -10.1933, 
 5.62743, 
 300, 
 0, 
 0, 
 311780096, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0

);

DELETE FROM `creature` WHERE `guid` = 146732598;
INSERT INTO `creature`
(
 `guid`, 
 `id`, 
 `map`, 
 `zoneId`, 
 `areaId`, 
 `spawnMask`, 
 `phaseMask`, 
 `PhaseId`, 
 `modelid`, 
 `equipment_id`, 
 `position_x`, 
 `position_y`, 
 `position_z`, 
 `orientation`,
 `spawntimesecs`,
 `spawndist`, 
 `currentwaypoint`, 
 `curhealth`, 
 `curmana`, 
 `MovementType`, 
 `npcflag`, 
 `npcflag2`, 
 `unit_flags`, 
 `dynamicflags`, 
 `AiID`, 
 `MovementID`, 
 `MeleeID`, 
 `isActive`, 
 `skipClone`, 
 `personal_size`, 
 `isTeemingSpawn`, 
 `unit_flags3`

)
VALUES
(

 146732598, 
 120583, 
 1220, 
 7543, 
 8584, 
 1, 
 65535, 
 '', 
 0, 
 0, 
 -1141.08, 
 2874.94, 
 -12.2496, 
 1.59169, 
 300, 
 0, 
 0, 
 311780096, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0, 
 0
);
