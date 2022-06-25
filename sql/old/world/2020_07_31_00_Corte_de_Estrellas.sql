/* Corte de Estrellas */ 

/* 

*/

/* Señal */
DELETE FROM `creature` WHERE `id` = 105729;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(365506, 105729, 1571, 8079, 8079, 8388868, 1, '', 0, 0, 1014.3, 3781.63, 2.85591, 1.80145, 300, 0, 0, 1714790, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);


DELETE FROM `creature_template` WHERE `entry` = 105729;
INSERT INTO `creature_template`(`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES 
(105729, 19515, 110, 110, 0, 98, 110, 0, 100, 6, 35, 1, 0, 1, 1, 1.14286, 1, 0, 0, 0, 0, 1, 2000, 2000, 1, 256, 69240832, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 0, 0, -1, '2100 ', '', 0, 0, 0, 0, 0, 0, 0, 'npc_signal_lantern');

DELETE FROM `creature_template_wdb` WHERE `Entry` = 105729;
INSERT INTO `creature_template_wdb`(`Entry`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `Title`, `TitleAlt`, `CursorName`, `TypeFlags`, `TypeFlags2`, `Type`, `Family`, `Classification`, `KillCredit1`, `KillCredit2`, `VignetteID`, `Displayid1`, `Displayid2`, `Displayid3`, `Displayid4`, `HpMulti`, `PowerMulti`, `Leader`, `QuestItem1`, `QuestItem2`, `QuestItem3`, `QuestItem4`, `QuestItem5`, `QuestItem6`, `QuestItem7`, `QuestItem8`, `QuestItem9`, `QuestItem10`, `MovementInfoID`, `RequiredExpansion`, `FlagQuest`, `VerifiedBuild`) VALUES 
(105729, 'Signal Lantern', '', '', '', '', '', '', '', '', '', 'interact', 1611661328, 6, 10, 0, 1, 0, 0, 0, 74786, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 22566);

DELETE FROM `creature_template` WHERE `entry` = 105264;
DELETE FROM `creature_template_wdb` WHERE `Entry` = 105264;
INSERT INTO `creature_template` (`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES 
('105264', '0', '98', '110', '0', '0', '0', '0', '100', '5', '35', '0', '0', '1', '1.42857', '1.14286', '1', '0', '0', '0', '0', '1', '2000', '2000', '1', '33587264', '2048', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '4711', '0', '0', 'SmartAI', '0', '7', '1', '1', '1', '1', '0', '0', '-1', '', '', '0', '0', '0', '0', '0', '0', '0', 'npc_nightborne_boat');
INSERT INTO `creature_template_wdb` (`Entry`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `Title`, `TitleAlt`, `CursorName`, `TypeFlags`, `TypeFlags2`, `Type`, `Family`, `Classification`, `KillCredit1`, `KillCredit2`, `VignetteID`, `Displayid1`, `Displayid2`, `Displayid3`, `Displayid4`, `HpMulti`, `PowerMulti`, `Leader`, `QuestItem1`, `QuestItem2`, `QuestItem3`, `QuestItem4`, `QuestItem5`, `QuestItem6`, `QuestItem7`, `QuestItem8`, `QuestItem9`, `QuestItem10`, `MovementInfoID`, `RequiredExpansion`, `FlagQuest`, `VerifiedBuild`) VALUES 
('105264', 'Nightborne Boat', '', '', '', '', '', '', '', '', '', '', '2097224', '0', '10', '0', '1', '0', '0', '0', '69057', '0', '0', '0', '5', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '144', '6', '0', '22566');

/* bote */
UPDATE `creature_template` SET 
`speed_walk` = 3, 
`speed_run` = 3, 
`speed_fly` = 3 
WHERE `entry` = 105264;

UPDATE `creature_template` SET `AIName` = 'SmartAI', 
`InhabitType` = 7 
WHERE `entry` = 91655;

UPDATE `creature_template_wdb` SET 
`Displayid1` = 68992 WHERE 
`Entry` = 91655;

SET @Despaw := 91655;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Despaw;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Despaw,0,0,0,10,0,100,0,1,20,0,0,51,0,0,0,0,0,0,11,105264,4,0,0,0,0,0,"Kill-104274"),
(@Despaw,0,1,0,10,0,100,0,1,20,0,0,51,0,0,0,0,0,0,11,105296,4,0,0,0,0,0,"Kill-104273");

DELETE FROM `creature` WHERE `guid` = 6760138;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(6760138, 91655, 1571, 8079, 8181, 8388868, 1, '', 0, 0, 987.44, 3594.77, 0.00134411, 4.60165, 300, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);


DELETE FROM `smart_scripts` WHERE `entryorguid` = 105264;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(105264, 0, 0, 0, 60, 0, 100, 1, 100, 1000, 0, 0, 53, 0, 9100402, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'CoS'),
(105264, 0, 1, 0, 40, 0, 100, 1, 5, 9100402, 0, 0, 86, 213507, 1, 21, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'CoS'),
(105264, 0, 2, 0, 27, 0, 100, 0, 10, 100, 0, 0, 53, 1, 9100403, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'CoS'),
(105264, 0, 3, 0, 40, 0, 100, 1, 4, 9100403, 0, 0, 41, 2, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'CoS');


DELETE FROM `waypoint_data_script` WHERE `id` = 9100403;
INSERT INTO `waypoint_data_script`(`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `speed`, `action`, `action_chance`, `entry`, `wpguid`) VALUES
(9100403, 1, 1022.07, 3762.41, 0.000280395, 0, 0, 0, 0, 0, 100, 0, 0),
(9100403, 2, 1005.5, 3696.37, 0.000280395, 0, 0, 0, 0, 0, 100, 0, 0),
(9100403, 3, 1010.66, 3635.03, 0.000280395, 0, 0, 0, 0, 0, 100, 0, 0),
(9100403, 4, 970.645, 3478.13, 0.000280395, 0, 0, 0, 0, 0, 100, 0, 0);

/* Tele end */
DELETE FROM `gameobject_template` WHERE `entry` = 1915068;
INSERT INTO `gameobject_template`(`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `unkInt32`, `AIName`, `ScriptName`, `WorldEffectID`, `StateWorldEffectID`, `SpellVisualID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `MaxVisible`, `IgnoreDynLos`, `MinGold`, `MaxGold`, `VerifiedBuild`) VALUES 
(1915068, 6, 5791, 'Tele', '', '', '', 14, 0, 0.1, 0, 0, 0, 0, 0, 0, 12, 78, 5, 208703, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12340);

DELETE FROM `gameobject` WHERE `guid` = 24668888;
INSERT INTO `gameobject`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `AiID`, `state`, `isActive`, `personal_size`) VALUES 
(24668888, 1915068, 1571, 8079, 8181, 8388868, 1, '', 970.892, 3479.1, 0.400280395, 4.46268, -0, -0, -0.789659, 0.613545, 300, 0, 0, 1, 0, 0);


/* Spawn */ 

DELETE FROM `creature` WHERE `guid` = 6760122;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(6760122, 106110, 1571, 8079, 8183, 8388868, 1, '', 0, 0, 1222.66, 3364.53, 20.8053, 2.31765, 7500, 0, 0, 1714790, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature` WHERE `guid` = 6760123;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(6760123, 105340, 1571, 8079, 8183, 8388868, 1, '', 0, 0, 1081.37, 3388.98, 23.0671, 6.06456, 300, 0, 0, 1714790, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature` WHERE `guid` = 6760124;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(6760124, 106108, 1571, 8079, 8183, 8388868, 1, '', 0, 0, 1191.53, 3329.07, 20.7535, 1.84181, 300, 0, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature` WHERE `guid` = 6760125;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(6760125, 106024, 1571, 8079, 8183, 8388868, 1	, '', 0, 0, 1170.66, 3314.76, 22.0011, 0.636315, 300, 0, 0, 1714790, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature` WHERE `guid` = 6760126;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(6760126, 105831, 1571, 8079, 8183, 8388868, 1, '', 0, 0, 1028.57, 3359.6, 19.8385, 0.544422, 300, 0, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature` WHERE `guid` = 6760127;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(6760127, 105215, 1571, 8079, 8183, 8388868, 1, '', 0, 0, 1145.73, 3256.32, 20.0004, 2.78256, 300, 0, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature` WHERE `guid` = 6760128;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(6760128, 106018, 1571, 8079, 8183, 8388868, 1, '', 0, 0, 1064.48, 3429.12, 20.1144, 0.446006, 300, 0, 0, 1714790, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature` WHERE `guid` = 6760129;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(6760129, 105157, 1571, 8079, 8182, 8388868, 1, '', 0, 0, 1184.72, 3597.28, 20.9118, 5.68573, 300, 0, 0, 1714790, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);


/* SmartAI */

UPDATE `creature_template` SET 
`AIName` = 'SmartAI' 
WHERE `entry` = 106018;

UPDATE `creature_template` SET 
`AIName` = 'SmartAI' 
WHERE `entry` = 105157;

UPDATE `creature_template` SET 
`AIName` = 'SmartAI' 
WHERE `entry` = 106113;

UPDATE `creature_template` SET 
`AIName` = 'SmartAI' 
WHERE `entry` = 105215;

UPDATE `creature_template` SET 
`AIName` = 'SmartAI' 
WHERE `entry` = 106112;

UPDATE `creature_template` SET 
`AIName` = 'SmartAI' 
WHERE `entry` = 105160;

UPDATE `creature_template` SET 
`AIName` = 'SmartAI' 
WHERE `entry` = 105831;

UPDATE `creature_template` SET 
`AIName` = 'SmartAI' 
WHERE `entry` = 106024;

UPDATE `creature_template` SET 
`AIName` = 'SmartAI' 
WHERE `entry` = 105249;

UPDATE `creature_template` SET 
`AIName` = 'SmartAI' 
WHERE `entry` = 106108;

UPDATE `creature_template` SET 
`AIName` = 'SmartAI' 
WHERE `entry` = 105340;

UPDATE `creature_template` SET 
`AIName` = 'SmartAI' 
WHERE `entry` = 106110;

/* Articulos del bazar (NPCID:106018)  Call mini-boss */

DELETE FROM `gossip_menu` WHERE `Entry` = 19557 AND `TextID` = 28914;
INSERT INTO `gossip_menu`(`Entry`, `TextID`, `FriendshipFactionID`) VALUES 
(19557, 28914, 0);

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 19557;
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionIndex`, `OptionNPC`, `OptionText`, `OptionType`, `OptionNpcflag`, `OptionNpcflag2`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxCurrency`, `BoxText`, `OptionBroadcastTextID`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES 
(19557, 0, 0, 'Esto removera a Baalgar el Atento y creara una replica de el.', 1, 1, 0, 0, 0, 0, 0, 0, '', 108969, 0, 0);


/* civil (solo healer) */

UPDATE `creature_template` SET 
`gossip_menu_id` = 61616 
WHERE `entry` = 106112;

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 61616 AND `OptionIndex` = 0;
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionIndex`, `OptionText`) VALUES 
(61616, 0, 'Esto removera a Imacu tya y creara una replica de ella detras de ti.');

/* Comida en 800 */

UPDATE `creature_template` SET 
`gossip_menu_id` = 63636 
WHERE `entry` = 105249;

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 63636;
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionIndex`, `OptionText`) VALUES 
(63636, 0, 'Devorar refrigerios de los Sombranoche aumenta el brío.');

-- <Comida-800> 
SET @COMIDA800 := 105249;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@COMIDA800 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@COMIDA800,0,0,0,62,0,100,0,63636,0,0,0,75,211102,0,0,0,0,0,17,0,70,0,0,0,0,0,"add - aura!");


-- <Orbevil> 
SET @Orbevil := 105160;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Orbevil AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Orbevil,0,0,0,62,0,100,0,64646,0,0,0,75,211081,0,0,0,0,0,17,0,70,0,0,0,0,0,"add - aura!");

UPDATE `creature_template` SET 
`gossip_menu_id` = 64646 
WHERE `entry` = @Orbevil;

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 64646;
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionIndex`, `OptionText`) VALUES 
(64646, 0, 'Una energía poderosa.');

-- <Tomo> 
SET @Tomo := 105831;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Tomo AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Tomo,0,0,0,62,0,100,0,65656,0,0,0,75,211080,0,0,0,0,0,17,0,70,0,0,0,0,0,"add - aura!");

UPDATE `creature_template` SET 
`gossip_menu_id` = 65656 
WHERE `entry` = @Tomo;

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 65656;
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionIndex`, `OptionText`) VALUES 
(65656, 0, 'La destrucción del libro infernal provoca...');

UPDATE `creature_template` SET 
`unit_flags` = 256, 
`unit_flags2` = 67143680, 
`unit_flags3` = 1, 
`flags_extra` = 0, 
`WorldEffects` = '2100 ' 
WHERE `entry` = 105831;



-- <@LinternaM> 
SET @LinternaM := 106024;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@LinternaM AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@LinternaM,0,0,0,62,0,100,0,19558,0,0,0,75,211093,0,0,0,0,0,17,0,70,0,0,0,0,0,"add - aura!");

UPDATE `gossip_menu_option` SET 
`OptionIndex` = 0 WHERE `MenuID` = 19558 AND `OptionIndex` = 1;

-- <@Barril> 
SET @Barril := 106108;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Barril AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Barril,0,0,0,62,0,100,0,19562,0,0,0,75,211071,0,0,0,0,0,17,0,70,0,0,0,0,0,"add - aura!");

UPDATE `creature_template` SET 
`unit_flags` = 256, 
`unit_flags2` = 67143680, 
`unit_flags3` = 1, 
`flags_extra` = 0, 
`WorldEffects` = '2100 ' 
WHERE `entry` = 106108;

UPDATE `creature_template` SET 
`gossip_menu_id` = 19562 
WHERE `entry` = @Barril;

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 19562;
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionIndex`, `OptionText`) VALUES 
(19562, 0, 'Beber el brebaje de rosa luz estelar...');

-- <@Flor> 
SET @Flor := 105340;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Flor AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Flor,0,0,0,62,0,100,0,66666,0,0,0,75,211110,0,0,0,0,0,17,0,70,0,0,0,0,0,"add - aura!");

UPDATE `creature_template` SET 
`gossip_menu_id` = 66666 
WHERE `entry` = @Flor;

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 66666;
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionIndex`, `OptionText`) VALUES 
(66666, 0, 'Te envalentonarás si inhalas las esporas...');

-- <@Pergamino> 
SET @Pergamino := 106110;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Pergamino AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Pergamino,0,0,0,62,0,100,0,67676,0,0,0,75,211084,0,0,0,0,0,17,0,70,0,0,0,0,0,"add - aura!");

UPDATE `creature_template` SET 
`gossip_menu_id` = 67676 
WHERE `entry` = @Pergamino;

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 67676;
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionIndex`, `OptionText`) VALUES 
(67676, 0, 'Descifrar el Pergamino...');

/* UPdate */

UPDATE `creature_template` SET `faction` = 190, `npcflag` = 1 WHERE `entry` = 105831;
UPDATE `creature_template` SET `faction` = 190, `npcflag` = 1 WHERE `entry` = 105215;
UPDATE `creature_template` SET `faction` = 190, `npcflag` = 1 WHERE `entry` = 106108;

/* Trampa para el mini-boss 85787 */

UPDATE `creature_template` SET 
`AIName` = 'SmartAI' 
WHERE `entry` = 85787;

UPDATE `creature_template_wdb` SET 
`Displayid1` = 66627 WHERE 
`Entry` = 85787;

UPDATE `creature_template_wdb` SET 
`Displayid1` = 66627,
`Displayid2` = 0
WHERE 
`Entry` = 105215;



-- <@Tramp> 
SET @Tramp := 105215;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Tramp AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Tramp,0,0,1,62,0,100,0,68686,0,0,0,12,85787,3,120000,0,0,0,1,0,0,0,0,0,0,0,"Spam-bunny"),
(@Tramp,0,1,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Despaw"),
(@Tramp,0,2,1,62,0,100,0,68686,0,0,0,51,0,0,0,0,0,0,11,104278,30,0,0,0,0,0,"kill");

/* Event kill Creature mini-boss */


SET @TrampDIE := 85787;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@TrampDIE AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@TrampDIE,0,0,0,10,0,100,0,1,20,0,0,51,0,0,0,0,0,0,11,104274,1,0,0,0,0,0,"Kill-104274"),
(@TrampDIE,0,1,0,10,0,100,0,1,20,0,0,51,0,0,0,0,0,0,11,104273,1,0,0,0,0,0,"Kill-104273"),
(@TrampDIE,0,2,0,10,0,100,0,1,20,0,0,51,0,0,0,0,0,0,11,104275,1,0,0,0,0,0,"Kill-104275");



UPDATE `creature_template` SET 
`gossip_menu_id` = 68686 
WHERE `entry` = @Tramp;

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 68686;
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionIndex`, `OptionText`) VALUES 
(68686, 0, 'Colocar Trampa...');

/* UPdate */
UPDATE `creature_template` SET 
`unit_flags` = 256, 
`unit_flags2` = 67143680, 
`unit_flags3` = 1, 
`flags_extra` = 0, 
`WorldEffects` = '2100 ' 
WHERE `entry` = 105215;

UPDATE `creature_template` SET 
`unit_flags` = 33088, 
`unit_flags2` = 2099200, 
`unit_flags3` = 0,
`minlevel` = 110, 
`maxlevel` = 110, 
`faction` = 2735, 
`npcflag` = 1, 
`scale` = 0.6, 
`PassiveSpells` = '1200' 
WHERE `entry` = 85787;


UPDATE `creature_template_wdb` SET 
`CursorName` = 'interact', 
`TypeFlags` = 1611661328 
WHERE `Entry` = 85787;

/* sicario vinculo vil  */
DELETE FROM `creature` WHERE `guid` = 14505184;


/* Disable Guardian Constructs NPCID:104270 */


-- <@GuardianConstruct> 
SET @GuardianConstruct := 105157;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GuardianConstruct;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GuardianConstruct,0,0,0,62,0,100,0,70707,0,0,0,75,189855,0,0,0,0,0,11,104270,370,0,0,0,0,0,"add - aura!"),
(@GuardianConstruct,0,2,0,62,0,100,0,70707,0,0,0,75,191821,0,0,0,0,0,11,104270,370,0,0,0,0,0,"add - aura!"),
(@GuardianConstruct,0,3,0,62,0,100,0,70707,0,0,0,2,35,0,0,0,0,0,11,104270,370,0,0,0,0,0,"set-faction!");


UPDATE `creature_template` SET 
`gossip_menu_id` = 70707 
WHERE `entry` = @GuardianConstruct;

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 70707;
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionIndex`, `OptionText`) VALUES 
(70707, 0, 'Es tiempo...');


/* Veneno model */

UPDATE `creature_template` SET `unit_flags` = 256, `unit_flags2` = 69240832 WHERE `entry` = 105117;

UPDATE `creature_template_wdb` SET 
`Displayid1` = 70094, 
`Displayid2` = 0 
WHERE `Entry` = 105117;

UPDATE `creature_template` SET 
`scale` = 0.3 WHERE 
`entry` = 105117;

UPDATE `creature_template` SET 
`scale` = 0.2 WHERE 
`entry` = 78739;

DELETE FROM `creature` WHERE `guid` = 365492;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(365492, 104215, 1571, 8079, 8182, 8388868, 1, '', 0, 0, 1309.03, 3507.45, 20.0934, 1.53823, 86400, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);



DELETE FROM `smart_scripts` WHERE `entryorguid`=105117 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(105117,0,0,0,62,0,100,0,71717,0,0,0,12,78739,7,0,0,0,0,1,0,0,0,0,0,0,0,"Spam-bunny"),
(105117,0,1,0,62,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Despaw");

/* 78739 */

UPDATE `creature_template_wdb` SET `Displayid1` = 70094 WHERE `Entry` = 78739;
UPDATE `creature_template_wdb` SET `Name1` = 'Flask' WHERE `Entry` = 78739;

UPDATE `creature_template` SET 
`gossip_menu_id` = 71717 
WHERE `entry` = 105117;

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 71717;
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionIndex`, `OptionText`) VALUES 
(71717, 0, 'Colocar veneno...');

UPDATE `creature_template` SET 
`AIName` = 'SmartAI' 
WHERE `entry` = 78739;

DELETE FROM `smart_scripts` WHERE `entryorguid`=78739 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(78739, 0, 0, 0, 10, 0, 100, 0, 1, 20, 0, 0, 51, 0, 0, 0, 0, 0, 0, 11, 104215, 3, 0, 0, 0, 0, 0, 'Flask of the Solemn Night');


DELETE FROM `creature` WHERE `guid` = 6760134;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(6760134, 85787, 1571, 8079, 8183, 8388868, 1, '', 0, 0, 1039.78, 3421.43, 45.8056, 3.76854, 300, 0, 0, 1714790, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);


/* Modelos de los NPC */

/* Orbe */
UPDATE `creature_template_wdb` SET 
`Displayid1` = 63589, 
`Displayid2` = 0
WHERE `Entry` = 105160;


/* Cooking */

UPDATE `creature_template_wdb` SET 
`Displayid1` = 46722, 
`Displayid2` = 0 
WHERE `Entry` = 105249;

UPDATE `creature_template` SET 
`scale` = 0.5 WHERE 
`entry` = 105249;

/* LinternaM */

UPDATE `creature_template_wdb` SET 
`Displayid1` = 45333, 
`Displayid2` = 0 
WHERE `Entry` = 106024 ;

UPDATE `creature_template` SET 
`scale` = 2 WHERE 
`entry` = 106024;

/* Articulos del bazar  */

UPDATE `creature_template_wdb` SET 
`Displayid1` = 69940, 
`Displayid2` = 0 
WHERE `Entry` = 106018;

UPDATE `creature_template` SET 
`scale` = 0.5 WHERE 
`entry` = 106018;

/* barril */

UPDATE `creature_template_wdb` SET 
`Displayid1` = 78334, 
`Displayid2` = 0
WHERE `Entry` = 106108;

UPDATE `creature_template` SET 
`scale` = 0.8 WHERE 
`entry` = 106108;

/* Estatua  106113 */

UPDATE `creature_template_wdb` SET 
`Displayid1` = 59640, 
`Displayid2` = 0 
WHERE `Entry` = 106113;

UPDATE `creature_template` SET 
`scale` = 0.4 WHERE 
`entry` = 106113;


/* Tomo infernal */

UPDATE `creature_template_wdb` SET 
`Displayid1` = 67430, 
`Displayid2` = 0 
WHERE `Entry` = 105831;

UPDATE `creature_template` SET 
`scale` = 1 WHERE 
`entry` = 105831;

/* flor 105340 */

UPDATE `creature_template_wdb` SET 
`Displayid1` = 35741, 
`Displayid2` = 0 
WHERE `Entry` = 105340;

UPDATE `creature_template` SET 
`scale` = 1 WHERE 
`entry` = 105340;

/* Arcane Power  */

UPDATE `creature_template_wdb` SET 
`Displayid1` = 70124, 
`Displayid2` = 0 
WHERE `Entry` = 105157;

UPDATE `creature_template` SET 
`scale` = 0.4 WHERE 
`entry` = 105157;

/* Pergamino 106110 */

UPDATE `creature_template_wdb` SET 
`Displayid1` = 75423, 
`Displayid2` = 0 
WHERE `Entry` = 106110;

UPDATE `creature_template` SET 
`scale` = 0.8 WHERE 
`entry` = 106110;

/* Natos de la fiesta */
UPDATE `creature_template_wdb` SET `Displayid2` = 70102 WHERE `Entry` = 107435;

/* Daño  */

/* Inquisidor Vigilante  105715 */
/* 
Aumentado su tiempo entre casteos y reducido su daño un 30%
*/
DELETE FROM `smart_scripts` WHERE `entryorguid`=105715 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(105715, 0, 0, 0, 0, 0, 100, 0, 14000, 15000, 14000, 15000, 11, 211293, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'CoS'),
(105715, 0, 1, 0, 0, 0, 100, 0, 15000, 16000, 15000, 16000, 11, 211299, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'CoS');

UPDATE `creature_template` SET `baseattacktime` = 4500 WHERE `entry` = 107291;
UPDATE `creature_template` SET `dmg_multiplier` = 0.7 WHERE `entry` = 105715;

/* Diablillo abrasador 104295 Daño reducido un 10% y aumentado su tiempo de casteo un 25% */

UPDATE `creature_template` SET 
`dmg_multiplier` = 0.9
WHERE `entry` = 104295;
UPDATE `creature_template` SET 
`baseattacktime` = 4000 
WHERE `entry` = 104295;


/* Estatua joyeria y Mineria */

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 19564 AND `OptionIndex` = 0;
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionIndex`, `OptionText`) VALUES 
(19564, 0, 'Esto removera a Jazshariu y creara una replica igual');

-- <Estatua> mapid:1571
SET @Estatua := 106113;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Estatua AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Estatua,0,0,0,62,0,100,0,19564,0,0,0,62,1571,0,0,0,0,0,11,104273,1870,0,1039.78,3421.43,45.8056,3.76854,"even-cros"),
(@Estatua,0,1,0,62,0,100,0,19564,0,0,0,12,104273,7,0,0,0,0,8,0,0,0,1062.24,3350.1,25.2421,2.10088,"spaw!"),
(@Estatua,0,2,0,62,0,100,0,19564,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"set flag self");


/* Articulos */
-- <Articulos> 
SET @Articulos := 106018;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Articulos AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Articulos,0,0,0,62,0,100,0,19557,0,0,0,62,1571,0,0,0,0,0,11,104274,570,0,1039.78,3421.43,45.8056,3.76854,"even-cros"),
(@Articulos,0,1,0,62,0,100,0,19557,0,0,0,12,104274,7,0,0,0,0,8,0,0,0,1073.71,3410.22,19.9632,5.75711,"SpaW"),
(@Articulos,0,2,0,62,0,100,0,19557,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"set flag self");

/* civil */

-- <civil> mapid:1571
SET @civil := 106112;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@civil AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@civil,0,0,0,62,0,100,0,61616,0,0,0,62,1571,0,0,0,0,0,11,104275,570,0,1039.78,3421.43,45.8056,3.76854,"Event-cros!"),
(@civil,0,1,0,62,0,100,0,61616,0,0,0,12,104275,7,0,0,0,0,8,0,0,0,1058.63,3395.64,19.8385,1.88378,"spaw!"),
(@civil,0,2,0,62,0,100,0,61616,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"set flag self");


/* Evento del boss final  */
-- <@Magistrix> SAI
SET @Magistrix := 110443;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Magistrix AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Magistrix,0,0,0,52,0,100,0,0,104218,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Text-1 Of-Combat"),
(@Magistrix,0,1,0,52,0,100,0,0,110443,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Text-2 Of-Combat)"),
(@Magistrix,0,2,0,52,0,100,0,2,107435,0,0,1,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Text-3 ");

UPDATE `creature_template` SET 
`AIName` = 'SmartAI' 
WHERE `entry` = 110443;

/* text y sonidos de Magistrix */
DELETE FROM `creature_text` WHERE `Entry` = 110443;
INSERT INTO `creature_text`(`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
(110443, 1, 0, 'Меландр, ты снова подвел меня, но ты можешь исправиться. Избавься от этих чужаков! Я возвращаюсь в Цитадель Ночи.', 12, 0, 100, 0, 0, 67613, 117104, 0, 0, 0, 'tex-over'),
(110443, 2, 0, 'Случайных? Тебя не удивляет, что каждое найденное тело украшает сумеречная лилия, любимый цветок Талисры?', 12, 0, 100, 0, 0, 67610, 121608, 0, 0, 0, 'tex-over-self'),
(110443, 0, 0, 'Ты хочешь, чтобы я осталась чесать языками с никчемной знатью, когда враг вот-вот нанесет удар? Глянь, бестолочь! Мы не одни.', 12, 0, 100, 0, 0, 67614, 117106, 0, 0, 0, 'Player-kill mini-boss');

/* conditions - class - race - skill - spec  */


/* Articulos del bazar Rogue-Warrior-Peleteria */ -- hecho 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 19557;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 19557, 0, 0, 1, 15, 0, 9, 0, 0, 0, 0, '', NULL), -- Rogue - Warrior
(15, 19557, 0, 0, 0, 7, 0, 165, 600, 0, 0, 0, '', NULL); -- leatherworking 

/*Gnomo - Goblin - Ingieneria*/ -- hecho
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 70707;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 70707, 0, 0, 0, 7, 0, 202, 600, 0, 0, 0, '', NULL), -- Ingieneria
(15, 70707, 0, 0, 1, 16, 0, 320, 0, 0, 0, 0, '', NULL); -- Gnomo y Goblin


/* Orbe Demon hunter y Warlock / priest y paladin */ -- hecho
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 64646;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 64646, 0, 0, 1, 15, 0, 2322, 0, 0, 0, 0, '', NULL);
/* Barril Monk-DK */ -- hecho 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 19562;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 19562, 0, 0, 1, 15, 0, 544, 0, 0, 0, 0, '', NULL);


/* Tomo Priest y paladin / demon hunter  */ -- hecho 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 65656;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 65656, 0, 0, 1, 15, 0, 2066, 0, 0, 0, 0, '', NULL);

/* Estatua jewelworking-mining*/ -- hecho
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 19564;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 19564, 0, 0, 0, 7, 0, 755, 600, 0, 0, 0, '', NULL), -- jewelworking
(15, 19564, 0, 0, 1, 7, 0, 186, 186, 0, 0, 0, '', NULL); -- mining

/*Flor druida-herbalism*/ -- hecho
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 66666;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 66666, 0, 0, 1, 15, 0, 1024, 0, 0, 0, 0, '', NULL), -- druida
(15, 66666, 0, 0, 0, 7, 0, 182, 600, 0, 0, 0, '', NULL); -- Herbalism

/*Cooking-Pandaren*/ -- hecho
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 63636;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 63636, 0, 0, 0, 16, 0, 50331648, 0, 0, 0, 0, '', NULL), -- Pandaren
(15, 63636, 0, 0, 1, 7, 0, 185, 800, 0, 0, 0, '', NULL), -- Cooking
(15, 63636, 0, 0, 2, 7, 0, 182, 600, 0, 0, 0, '', NULL); -- Herbalism

/*Elfo de la noche y de sangre - mago - encantamiento*/ -- hecho
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 19558;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 19558, 0, 0, 0, 15, 0, 128, 0, 0, 0, 0, '', NULL), -- Mago
(15, 19558, 0, 0, 1, 16, 0, 520, 0, 0, 0, 0, '', NULL), -- Elfo de la noche
(15, 19558, 0, 0, 2, 7, 0, 333, 600, 0, 0, 0, '', NULL); -- Enchanting

/*Hunter - Herreria*/ -- hecho
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 68686;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 68686, 0, 0, 1, 15, 0, 4, 0, 0, 0, 0, '', NULL), -- Hunter
(15, 68686, 0, 0, 0, 7, 0, 164, 600, 0, 0, 0, '', NULL); -- Herreria

/*First Aid - Tailoring - Heler*/ -- hecho
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 61616;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 61616, 0, 0, 0, 7, 0, 129, 600, 0, 0, 0, '', NULL), -- First Aid
(15, 61616, 0, 0, 1, 7, 0, 197, 600, 0, 0, 0, '', NULL), -- Tailoring
(15, 61616, 0, 0, 2, 3, 0, 128937, 0, 0, 0, 0, '', NULL), -- Monk
(15, 61616, 0, 0, 3, 3, 0, 128911, 0, 0, 0, 0, '', NULL), -- Shaman
(15, 61616, 0, 0, 4, 3, 0, 128823, 0, 0, 0, 0, '', NULL), -- Paladin
(15, 61616, 0, 0, 5, 3, 0, 128825, 0, 0, 0, 0, '', NULL), -- Priest Sagrado
(15, 61616, 0, 0, 6, 3, 0, 128868, 0, 0, 0, 0, '', NULL), -- Priest Disciplina
(15, 61616, 0, 0, 7, 3, 0, 128306, 0, 0, 0, 0, '', NULL); -- Druida

/*Skining - Inscription - Shaman*/ -- hecho
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 67676;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 67676, 0, 0, 0, 7, 0, 393, 600, 0, 0, 0, '', NULL), -- Skining
(15, 67676, 0, 0, 1, 7, 0, 773, 600, 0, 0, 0, '', NULL), -- Inscription
(15, 67676, 0, 0, 2, 15, 0, 64, 0, 0, 0, 0, '', NULL); -- Shaman


/* Veneno_ Alchemy - Rogue*/
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 71717;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 71717, 0, 0, 0, 7, 0, 171, 600, 0, 0, 0, '', NULL), -- Alchemy
(15, 71717, 0, 0, 1, 15, 0, 8, 0, 0, 0, 0, '', NULL); -- Rogue

/* event boss_patrol_captain_gerdo */
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=78739;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 78739, 0, 0, 38, 0, 30, 4, 0, 0, 0, 'boss_patrol_captain_gerdo', '30%');

-- Spawn random de los buffs


/*Table_pool_template*/
DELETE FROM `pool_template` WHERE `entry` IN (676030, 676031, 676032, 676033);
INSERT INTO `pool_template`(`entry`, `max_limit`, `description`) VALUES
(676030, 1, 'Items'),
(676031, 1, 'Offensive Buffs'),
(676032, 1, 'Defensive Buffs'),
(676033, 1, 'Utility');


/*Table_pool_creature*/

-- Items
DELETE FROM `pool_creature` WHERE `guid` IN (6760129, 6760128, 365819, 6760127, 365830);
INSERT INTO `pool_creature`(`guid`, `pool_entry`, `chance`, `description`) VALUES
(6760129, 676030, 20, 'Elementos funcionales'),
(6760128, 676030, 20, 'Elementos funcionales'),
(365819, 676030, 20, 'Elementos funcionales'),
(6760127, 676030, 20, 'Elementos funcionales'),
(365830, 676030, 20, 'Elementos funcionales');

-- Offensive Buffs
DELETE FROM `pool_creature` WHERE `guid` IN (6760125, 6760123, 365771);
INSERT INTO `pool_creature`(`guid`, `pool_entry`, `chance`, `description`) VALUES
(365771, 676031, 33, 'Offensive Buffs'),
(6760125, 676031, 33, 'Offensive Buffs '),
(6760123, 676031, 34, 'Offensive Buffs');

-- Defensive Buffs
DELETE FROM `pool_creature` WHERE `guid` IN (365772, 6760126);
INSERT INTO `pool_creature`(`guid`, `pool_entry`, `chance`, `description`) VALUES
(365772, 676032, 50, 'Defensive Buffs'),
(6760126, 676032, 50, 'Defensive Buffs');

-- Utility
DELETE FROM `pool_creature` WHERE `guid` IN (6760124, 6760122);
INSERT INTO `pool_creature`(`guid`, `pool_entry`, `chance`, `description`) VALUES
(6760124, 676033, 50, 'Utility'),
(6760122, 676033, 50, 'Utility');
