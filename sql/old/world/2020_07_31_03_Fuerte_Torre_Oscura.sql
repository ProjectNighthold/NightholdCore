/* Arreglo Torre Fuerte Oscura */


/* lady velandras mini-Jefe */

DELETE FROM `creature_template_spell` WHERE `entry` = 98538;
INSERT INTO `creature_template_spell`(`entry`, `spell`, `difficultyMask`, `timerCast`, `comment`) VALUES 
(98538, 196916, 7, 0, '@Glaive Toss'),
(98538, 225732, 7, 0, '@Strike Down'),
(98538, 194966, 7, 0, '@Soul Echoes'); -- and 1er boss 

DELETE FROM `smart_scripts` WHERE `entryorguid`=98538;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(98538, 0, 0, 0, 0, 0, 100, 0, 6000, 6000, 7000, 7000, 11, 196916, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'BRH, cast every 7s (Glazzer)'),
(98538, 0, 1, 0, 0, 0, 100, 0, 8000, 8000, 10000, 10000, 11, 225732, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'BRH, cast every 10s (Glazzer)'),
(98538, 0, 2, 0, 0, 0, 100, 0, 18000, 18000, 20000, 20000, 11, 194966, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Fear target player selet 40s ');

/* (Amalgam of Souls)[NPCID:98542] 1er boss */


-- Restless Soul [NPCID:99664]
UPDATE `creature_template` SET 
`speed_walk` = 0.2, 
`speed_run` = 0.2, 
`speed_fly` = 0.2 
WHERE `entry` = 99664;

-- Spell
DELETE FROM `creature_template_spell` WHERE `entry` = 98542;
INSERT INTO `creature_template_spell`(`entry`, `spell`, `difficultyMask`, `timerCast`, `comment`) VALUES 
(98542, 194956, 7, 0, '@Reap Soul'),
(98542, 194966, 7, 0, '@Soul Echoes'), -- Fear target player selet  
(98542, 195254, 7, 0, '@Swirling Scythe'),
(98542, 196078, 6, 0, '@Call Souls'),
(98542, 196587, 6, 0, '@Soul Burst');

/* Risen Archer [NPCID:98275]*/

DELETE FROM `creature_equip_template` WHERE `CreatureID` = 98275 AND `ID` = 1;
INSERT INTO `creature_equip_template`(`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `ItemID4`, `ItemID5`, `ItemID6`) VALUES 
(98275, 1, 0, 0, 0, 0, 36613, 0);

DELETE FROM `creature_template_addon` WHERE `entry` = 98275;
INSERT INTO `creature_template_addon`(`entry`, `bytes2`, `auras`) VALUES (98275, 2, '52147');

DELETE FROM `creature_model_info` WHERE `DisplayID` = 98275;
INSERT INTO `creature_model_info`(`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `hostileId`) VALUES (98275, 0.3, 11, 0, 0);

/* Rook Spiderling[NPCID:98677] */
-- Veneno de alma
DELETE FROM `smart_scripts` WHERE `entryorguid` = 98677;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(98677, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 225908, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'BRH, ApplyAura (Glazzer)'),
(98677, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 225917, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'BRH, if dead -> cast (Glazzer)');

UPDATE `creature_template` SET 
`baseattacktime` = 5000, 
`rangeattacktime` = 5000 
WHERE `entry` = 98677;

/* Felspite Dominator [NPCID:102788] */

DELETE FROM `smart_scripts` WHERE `entryorguid` = 102788;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(102788, 0, 0, 0, 0, 0, 100, 0, 15000, 15000, 18000, 18000, 11, 227913, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'BRH, cast every 26s (Glazzer)'),
(102788, 0, 1, 2, 0, 0, 100, 0, 12000, 12000, 15000, 15000, 11, 203163, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'BRH, cast every 14s (Glazzer)');


UPDATE `creature_template` SET 
`AIName` = 'SmarAI', 
`ScriptName` = '' 
WHERE `entry` = 102781;

/* (Ghostly Councilor)[NPCID:98370] */

DELETE FROM `smart_scripts` WHERE `entryorguid` = 98370;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(98370, 0, 0, 0, 0, 0, 100, 0, 500, 500, 3500, 3500, 11, 199663, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'BRH, cast every 3.5s (Glazzer)'),
(98370, 0, 1, 0, 0, 0, 100, 0, 16000, 16000, 27000, 27000, 11, 225573, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'cast 33s (Glazzer)'),
(98370, 0, 2, 0, 0, 0, 100, 0, 17000, 17000, 28000, 28000, 11, 225832, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'cast @Nightglow Wisp');

DELETE FROM `creature_template_spell` WHERE `entry` = 98370;
INSERT INTO `creature_template_spell`(`entry`, `spell`, `difficultyMask`, `timerCast`, `comment`) VALUES 
(98370, 199663, 7, 0, '@Soul Blast'),
(98370, 225573, 4, 0, '@Dark Mending'),
(98370, 225832, 2, 0, '@Nightglow Wisp');

/* Delete Creature */
DELETE FROM `creature` WHERE `guid` = 14507199;
DELETE FROM `creature` WHERE `guid` = 146728087;

/* lost soul  */

UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 600100;
UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 600101;

DELETE FROM `creature_template_wdb` WHERE `Entry` = 103102;
INSERT INTO `creature_template_wdb`(`Entry`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `Title`, `TitleAlt`, `CursorName`, `TypeFlags`, `TypeFlags2`, `Type`, `Family`, `Classification`, `KillCredit1`, `KillCredit2`, `VignetteID`, `Displayid1`, `Displayid2`, `Displayid3`, `Displayid4`, `HpMulti`, `PowerMulti`, `Leader`, `QuestItem1`, `QuestItem2`, `QuestItem3`, `QuestItem4`, `QuestItem5`, `QuestItem6`, `QuestItem7`, `QuestItem8`, `QuestItem9`, `QuestItem10`, `MovementInfoID`, `RequiredExpansion`, `FlagQuest`, `VerifiedBuild`) VALUES 
(103102, 'Lost Soul', '', '', '', '', '', '', '', '', '', '', 1048576, 0, 6, 0, 0, 0, 0, 0, 68011, 68012, 68013, 68014, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22566);

DELETE FROM `creature_template` WHERE `entry` = 103102;
INSERT INTO `creature_template`(`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES 
(103102, 0, 1, 1, 0, 0, 0, 0, 100, 0, 35, 0, 0, 1, 1.14286, 1.14286, 1, 0, 0, 0, 0, 1, 2000, 2000, 1, 33555200, 2048, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 0, 0, -1, '', '', 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `creature_template_wdb_locale` WHERE `ID` = 103102;
INSERT INTO `creature_template_wdb_locale`(`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES
(103102, 'ruRU', '', '', 'Заблудшая душа', '', '', '', 'Заблудшая душа', '', '', '', 26124),
(103102, 'esES', '', '', 'Alma perdida', '', '', '', 'Alma perdida', '', '', '', 26124),
(103102, 'deDE', '', '', 'Verlorene Seele', '', '', '', 'Verlorene Seele', '', '', '', 26124),
(103102, 'enUS', '', '', 'Lost Soul', '', '', '', '', '', '', '', 26124),
(103102, 'frFR', '', '', 'Ame égarée', '', '', '', 'Ame égarée', '', '', '', 26124),
(103102, 'itIT', '', '', 'Anima Perduta', '', '', '', 'Anima Perduta', '', '', '', 26124),
(103102, 'zhTW', '', '', '失落的靈魂', '', '', '', '失落的靈魂', '', '', '', 26124),
(103102, 'koKR', '', '', '길 잃은 영혼', '', '', '', '길 잃은 영혼', '', '', '', 26124),
(103102, 'ptBR', '', '', 'Alma Perdida', '', '', '', 'Alma Perdida', '', '', '', 26124),
(103102, 'zhCN', '', '', '失落的灵魂', '', '', '', '失落的灵魂', '', '', '', 26124),
(103102, 'esMX', '', '', 'Alma perdida', '', '', '', 'Alma perdida', '', '', '', 26124);


/* nuevos insert */

-- Spawm

DELETE FROM `creature` WHERE `guid` = 11565697;
DELETE FROM `creature` WHERE `guid` = 11565695;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(11565697, 600100, 1501, 7805, 7805, 8388870, 1, '', 0, 0, 3148.97, 7489.1, 28.3399, 0.275524, 14400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(11565695, 600101, 1501, 7805, 7805, 8388870, 1, '', 0, 0, 3150.04, 7491.22, 28.3029, 5.57055, 14400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);



/* NPC-1 */

UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 600100;
UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 600101;

DELETE FROM `creature_template_wdb` WHERE `Entry` = 600100;
INSERT INTO `creature_template_wdb`(`Entry`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `Title`, `TitleAlt`, `CursorName`, `TypeFlags`, `TypeFlags2`, `Type`, `Family`, `Classification`, `KillCredit1`, `KillCredit2`, `VignetteID`, `Displayid1`, `Displayid2`, `Displayid3`, `Displayid4`, `HpMulti`, `PowerMulti`, `Leader`, `QuestItem1`, `QuestItem2`, `QuestItem3`, `QuestItem4`, `QuestItem5`, `QuestItem6`, `QuestItem7`, `QuestItem8`, `QuestItem9`, `QuestItem10`, `MovementInfoID`, `RequiredExpansion`, `FlagQuest`, `VerifiedBuild`) VALUES 
(600100, 'Lost Soul', '', '', '', '', '', '', '', '', '', '', 1048576, 0, 6, 0, 0, 0, 0, 0, 68011, 68012, 68013, 68014, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22566);

DELETE FROM `creature_template` WHERE `entry` = 600100;
INSERT INTO `creature_template`(`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES 
(600100, 0, 1, 1, 0, 0, 0, 0, 100, 0, 35, 0, 0, 1, 1.14286, 1.14286, 1, 0, 0, 0, 0, 1, 2000, 2000, 1, 33555200, 2048, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 0, 0, -1, '', '', 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `creature_template_wdb_locale` WHERE `ID` = 600100;
INSERT INTO `creature_template_wdb_locale`(`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES
(600100, 'ruRU', '', '', 'Заблудшая душа', '', '', '', 'Заблудшая душа', '', '', '', 26124),
(600100, 'esES', '', '', 'Alma perdida', '', '', '', 'Alma perdida', '', '', '', 26124),
(600100, 'deDE', '', '', 'Verlorene Seele', '', '', '', 'Verlorene Seele', '', '', '', 26124),
(600100, 'enUS', '', '', 'Lost Soul', '', '', '', '', '', '', '', 26124),
(600100, 'frFR', '', '', 'Ame égarée', '', '', '', 'Ame égarée', '', '', '', 26124),
(600100, 'itIT', '', '', 'Anima Perduta', '', '', '', 'Anima Perduta', '', '', '', 26124),
(600100, 'zhTW', '', '', '失落的靈魂', '', '', '', '失落的靈魂', '', '', '', 26124),
(600100, 'koKR', '', '', '길 잃은 영혼', '', '', '', '길 잃은 영혼', '', '', '', 26124),
(600100, 'ptBR', '', '', 'Alma Perdida', '', '', '', 'Alma Perdida', '', '', '', 26124),
(600100, 'zhCN', '', '', '失落的灵魂', '', '', '', '失落的灵魂', '', '', '', 26124),
(600100, 'esMX', '', '', 'Alma perdida', '', '', '', 'Alma perdida', '', '', '', 26124);

DELETE FROM `creature_text` WHERE `Entry` = 600100;
INSERT INTO `creature_text`(`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
(600100, 0, 0, 'text 0 ', 12, 0, 100, 0, 0, 0, 105765, 0, 0, 0, 'tex-over'),
(600100, 1, 0, 'text 1', 12, 0, 100, 0, 0, 0, 105773, 0, 0, 0, 'tex-over-self');

UPDATE `creature_template` SET 
`AIName` = 'SmartAI' 
WHERE `entry` = 600100;

/* NPC- 2 */

DELETE FROM `creature_template_wdb` WHERE `Entry` = 600101;
INSERT INTO `creature_template_wdb`(`Entry`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `Title`, `TitleAlt`, `CursorName`, `TypeFlags`, `TypeFlags2`, `Type`, `Family`, `Classification`, `KillCredit1`, `KillCredit2`, `VignetteID`, `Displayid1`, `Displayid2`, `Displayid3`, `Displayid4`, `HpMulti`, `PowerMulti`, `Leader`, `QuestItem1`, `QuestItem2`, `QuestItem3`, `QuestItem4`, `QuestItem5`, `QuestItem6`, `QuestItem7`, `QuestItem8`, `QuestItem9`, `QuestItem10`, `MovementInfoID`, `RequiredExpansion`, `FlagQuest`, `VerifiedBuild`) VALUES 
(600101, 'Lost Soul', '', '', '', '', '', '', '', '', '', '', 1048576, 0, 6, 0, 0, 0, 0, 0, 68011, 68012, 68013, 68014, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22566);

DELETE FROM `creature_template` WHERE `entry` = 600101;
INSERT INTO `creature_template`(`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES 
(600101, 0, 1, 1, 0, 0, 0, 0, 100, 0, 35, 0, 0, 1, 1.14286, 1.14286, 1, 0, 0, 0, 0, 1, 2000, 2000, 1, 33555200, 2048, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 0, 0, -1, '', '', 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `creature_template_wdb_locale` WHERE `ID` = 600101;
INSERT INTO `creature_template_wdb_locale`(`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES
(600101, 'ruRU', '', '', 'Заблудшая душа', '', '', '', 'Заблудшая душа', '', '', '', 26124),
(600101, 'esES', '', '', 'Alma perdida', '', '', '', 'Alma perdida', '', '', '', 26124),
(600101, 'deDE', '', '', 'Verlorene Seele', '', '', '', 'Verlorene Seele', '', '', '', 26124),
(600101, 'enUS', '', '', 'Lost Soul', '', '', '', '', '', '', '', 26124),
(600101, 'frFR', '', '', 'Ame égarée', '', '', '', 'Ame égarée', '', '', '', 26124),
(600101, 'itIT', '', '', 'Anima Perduta', '', '', '', 'Anima Perduta', '', '', '', 26124),
(600101, 'zhTW', '', '', '失落的靈魂', '', '', '', '失落的靈魂', '', '', '', 26124),
(600101, 'koKR', '', '', '길 잃은 영혼', '', '', '', '길 잃은 영혼', '', '', '', 26124),
(600101, 'ptBR', '', '', 'Alma Perdida', '', '', '', 'Alma Perdida', '', '', '', 26124),
(600101, 'zhCN', '', '', '失落的灵魂', '', '', '', '失落的灵魂', '', '', '', 26124),
(600101, 'esMX', '', '', 'Alma perdida', '', '', '', 'Alma perdida', '', '', '', 26124);

DELETE FROM `creature_text` WHERE `Entry` = 600101;
INSERT INTO `creature_text`(`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
(600101, 0, 0, 'text 0 ', 12, 0, 100, 0, 0, 0, 105767, 0, 0, 0, 'tex-over');

UPDATE `creature_template` SET 
`AIName` = 'SmartAI' 
WHERE `entry` = 600101;

/* Sai-npc 1*/


DELETE FROM `smart_scripts` WHERE `entryorguid`=600100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(600100,0,0,0,10,0,100,1,1,20,0,0,1,0,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Aoe - Talk"),
(600100,0,1,0,52,0,100,0,0,600101,0,0,1,1,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Text-1 Of-Combat");

/* Sai-npc 2*/
DELETE FROM `smart_scripts` WHERE `entryorguid`=600101;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(600101,0,0,0,52,0,100,0,0,600100,0,0,1,0,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Text-1 Of-Combat");

/* Cosmeticos */

UPDATE `creature_template` SET 
`AIName` = 'SmartAI' 
WHERE `entry` = 103857;

DELETE FROM `creature` WHERE `id` = 103857;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(262881, 103857, 1501, 7805, 7805, 8388870, 1, '', 0, 0, 3170.5, 7369.71, 228.183, 4.34429, 14400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(262878, 103857, 1501, 7805, 7805, 8388870, 1, '', 0, 0, 3154.47, 7400.49, 215.603, 5.83325, 14400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(262875, 103857, 1501, 7805, 7805, 8388870, 1, '', 0, 0, 3194.39, 7369.96, 246.365, 5.23303, 14400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);


/* Fel Bat Pup [NPCID:102781] npc_brh_fel_bat */

/* Fel Bat Pup [NPCID:102781] npc_brh_fel_bat

Delete Creature 102781

 */

DELETE FROM `creature_difficulty_stat` WHERE `entry` = 102781;
DELETE FROM `creature_template` WHERE `entry` = 102781;
DELETE FROM `creature_template_spell` WHERE `entry` = 102781 AND `spell` = 215377;
DELETE FROM `creature_template_wdb` WHERE `Entry` = 102781;
DELETE FROM `creature_template_wdb_locale` WHERE `ID` = 102781;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 102781;

/* Delete npc_brh_fel_bat */
DELETE FROM `creature_template` WHERE `entry` = 102781;
INSERT INTO `creature_template`(`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES 
(102781, 0, 110, 110, 0, 0, 0, 0, 100, 6, 16, 0, 0, 1, 1.14286, 1.14286, 1, 0, 0, 0, 0, 1, 2000, 2000, 1, 32768, 2048, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 1, 0, -1, '', '', 0, 0, 0, 0, 0, 15871, 0, 'npc_brh_fel_bat');

/* Fel Bat Pup [NPCID:600102] SmarAI */

DELETE FROM `creature_difficulty_stat` WHERE `entry` = 600102;
INSERT INTO `creature_difficulty_stat`(`entry`, `difficulty`, `dmg_multiplier`, `HealthModifier`) VALUES 
(600102, 2, 1, 1.625),
(600102, 23, 1, 2.1125);


DELETE FROM `creature_template` WHERE `entry` = 600102;
INSERT INTO `creature_template`(`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES 
(600102, 0, 110, 110, 0, 0, 0, 0, 100, 6, 16, 0, 0, 1, 1.14286, 1.14286, 1, 0, 0, 0, 0, 1, 2000, 2000, 1, 32768, 2048, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 3, 1, 1, 1, 1, 1, 0, -1, '', '', 0, 0, 0, 0, 0, 0, 0, '');

UPDATE `creature_template` SET 
`AffixState` = 15871 
WHERE `entry` = 600102; -- 15971 Inmune a los Affix

DELETE FROM `creature_template_spell` WHERE `entry` = 600102 AND `spell` = 215377;
INSERT INTO `creature_template_spell`(`entry`, `spell`, `difficultyMask`, `timerCast`, `comment`) VALUES (600102, 215377, 7, 0, '@The Maw Must Feed');



DELETE FROM `creature_template_wdb` WHERE `Entry` = 600102;
INSERT INTO `creature_template_wdb`(`Entry`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `Title`, `TitleAlt`, `CursorName`, `TypeFlags`, `TypeFlags2`, `Type`, `Family`, `Classification`, `KillCredit1`, `KillCredit2`, `VignetteID`, `Displayid1`, `Displayid2`, `Displayid3`, `Displayid4`, `HpMulti`, `PowerMulti`, `Leader`, `QuestItem1`, `QuestItem2`, `QuestItem3`, `QuestItem4`, `QuestItem5`, `QuestItem6`, `QuestItem7`, `QuestItem8`, `QuestItem9`, `QuestItem10`, `MovementInfoID`, `RequiredExpansion`, `FlagQuest`, `VerifiedBuild`) VALUES 
(600102, 'Fel Bat Pup', '', '', '', '', '', '', '', '', '', '', 2097224, 0, 3, 0, 0, 0, 0, 0, 67783, 0, 0, 0, 0.75, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 22566);


DELETE FROM `creature_template_wdb_locale` WHERE `ID` = 600102;
INSERT INTO `creature_template_wdb_locale`(`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES
(600102, 'ruRU', '', '', 'Детеныш сквернотопыря', '', '', '', '', '', '', '', 26124),
(600102, 'esES', '', '', 'Cría de murciélago vil', '', '', '', '', '', '', '', 26124),
(600102, 'deDE', '', '', 'Teufelsfledermausjunges', '', '', '', '', '', '', '', 26124),
(600102, 'enUS', '', '', 'Fel Bat Pup', '', '', '', '', '', '', '', 26124),
(600102, 'frFR', '', '', 'Jeune gangroptère', '', '', '', '', '', '', '', 26124),
(600102, 'itIT', '', '', 'Cucciolo di Vilpipistrello', '', '', '', '', '', '', '', 26124),
(600102, 'zhTW', '', '', '魔化幼蝠', '', '', '', '', '', '', '', 26124),
(600102, 'koKR', '', '', '새끼 지옥 박쥐', '', '', '', '', '', '', '', 26124),
(600102, 'ptBR', '', '', 'Filhote Morcevil', '', '', '', '', '', '', '', 26124),
(600102, 'zhCN', '', '', '魔蝠幼崽', '', '', '', '', '', '', '', 26124),
(600102, 'esMX', '', '', 'Murciélago vil cachorro', '', '', '', '', '', '', '', 26124);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 600102;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES (600102, 0, 0, 0, 0, 0, 100, 0, 8000, 9000, 8000, 9000, 11, 215377, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '@The Maw Must Feed');



DELETE FROM `waypoint_data` WHERE `id` = 1467061401;
DELETE FROM `waypoint_data` WHERE `id` = 1467061402;
DELETE FROM `waypoint_data` WHERE `id` = 1467061403;
DELETE FROM `waypoint_data` WHERE `id` = 1467061404;
INSERT INTO `waypoint_data`(`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `delay_chance`, `move_flag`, `speed`, `action`, `action_chance`, `entry`, `wpguid`) VALUES
(1467061401, 1, 3150.62, 7358, 214.288, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061401, 2, 3141.19, 7371.87, 206.195, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061401, 3, 3139.45, 7394.59, 196.659, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061401, 4, 3141.19, 7371.87, 206.195, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061401, 5, 3150.62, 7358, 214.288, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061402, 1, 3153.45, 7361.27, 214.177, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061402, 2, 3146.82, 7372.78, 207.144, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061402, 3, 3144.12, 7393.6, 196.659, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061402, 4, 3146.82, 7372.78, 207.144, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061402, 5, 3153.45, 7361.27, 214.177, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061404, 1, 3192.64, 7355.54, 223.719, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061404, 2, 3187.56, 7353.12, 223.719, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061404, 3, 3174.29, 7352.1, 215.991, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061404, 4, 3166.96, 7352.52, 215.61, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061404, 5, 3174.29, 7352.1, 215.991, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061404, 6, 3187.56, 7353.12, 223.719, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061404, 7, 3192.64, 7355.54, 223.719, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061403, 1, 3193.61, 7349.74, 223.719, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061403, 2, 3187.97, 7347.86, 223.719, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061403, 3, 3174.83, 7347.7, 216.352, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061403, 4, 3163.47, 7351.65, 215.61, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061403, 5, 3174.83, 7347.7, 216.352, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061403, 6, 3187.97, 7347.86, 223.719, 0, 0, 0, 0, 7, 0, 100, 600102, 0),
(1467061403, 7, 3193.61, 7349.74, 223.719, 0, 0, 0, 0, 7, 0, 100, 600102, 0);


DELETE FROM `creature` WHERE `id` = 600102;
DELETE FROM `creature` WHERE `id` = 102781;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES
(146727702, 600102, 1501, 7805, 7805, 8388608, 65535, '', 0, 0, 3151.28, 7357.65, 214.605, 2.29794, 86400, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(146727704, 600102, 1501, 7805, 7805, 8388608, 65535, '', 0, 0, 3153.84, 7360.83, 214.455, 2.34899, 86400, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(146728055, 600102, 1501, 7805, 7805, 8388608, 65535, '', 0, 0, 3194.22, 7350.24, 223.718, 3.48849, 86400, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(146728053, 600102, 1501, 7805, 7805, 8388608, 65535, '', 0, 0, 3193.78, 7355.65, 223.718, 3.67306, 86400, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(262903, 600102, 1501, 7805, 7805, 8388870, 1, '', 0, 0, 3230.58, 7338, 226.404, 4.61208, 14400, 4, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(262901, 600102, 1501, 7805, 7805, 8388870, 1, '', 0, 0, 3226.12, 7339.62, 226.165, 0.692318, 14400, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(262899, 600102, 1501, 7805, 7805, 8388870, 1, '', 0, 0, 3228.19, 7335.11, 226.2, 0.84556, 14400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(262898, 600102, 1501, 7805, 7805, 8388870, 1, '', 0, 0, 3221.72, 7332.62, 226.186, 0.422225, 14400, 3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(262895, 600102, 1501, 7805, 7805, 8388870, 1, '', 0, 0, 3221.34, 7332.64, 226.182, 2.72841, 14400, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(262893, 600102, 1501, 7805, 7805, 8388870, 1, '', 0, 0, 3200.43, 7352.45, 223.883, 4.05184, 14400, 4, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(262894, 600102, 1501, 7805, 7805, 8388870, 1, '', 0, 0, 3161.62, 7351.83, 215.765, 4.35366, 14400, 3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(262888, 600102, 1501, 7805, 7805, 8388870, 1, '', 0, 0, 3205.21, 7358.77, 223.921, 0.42403, 14400, 7, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(262886, 600102, 1501, 7805, 7805, 8388870, 1, '', 0, 0, 3169.69, 7352.68, 215.765, 0.877419, 14400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(262884, 600102, 1501, 7805, 7805, 8388870, 1, '', 0, 0, 3203.13, 7362.57, 223.935, 3.66387, 14400, 5, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(262880, 600102, 1501, 7805, 7805, 8388870, 1, '', 0, 0, 3201.58, 7359.15, 223.891, 6.10131, 14400, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(262871, 600102, 1501, 7805, 7805, 8388870, 1, '', 0, 0, 3149.14, 7392.58, 196.389, 5.31051, 14400, 3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(262870, 600102, 1501, 7805, 7805, 8388870, 1, '', 0, 0, 3141.18, 7390.94, 196.755, 1.47543, 14400, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

/* Sai Cria */
DELETE FROM `smart_scripts` WHERE `entryorguid` = 600102;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(600102, 0, 0, 0, 0, 0, 100, 0, 8000, 8000, 9000, 10000, 11, 215377, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@The Maw Must Feed');

