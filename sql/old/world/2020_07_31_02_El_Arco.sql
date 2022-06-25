/* [El Arco] */

/* Moco Inestable */

/* 

-- Slime

[NPCID:98425]- (Amalgama Instabile)o(Unstable Amalgamation)

[NPCID:98728]- (Bilis ácidaa)o(Acidic Bile)

[NPCID:98426]- (Moco inestable)o(Unstable Ooze)

[NPCID:98435]- (Moquito inestable)o(Unstable Oozeling)

-- Ratas

[NPCID:98732]-  (Rata apestada)o(Plagued Rat)

-- Vidente

[NPCID:105651]- (Vidente Terrornato)o(Dreadborne Seer)

-- Malignos
98733 Maligno Marchitado 
*/
-- Elite 

DELETE FROM `creature_template` WHERE `entry` = 98425;
INSERT INTO `creature_template`(`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES 
(98425, 0, 110, 110, 0, 0, 0, 0, 100, 6, 16, 0, 0, 1.2, 1.57143, 1.14286, 1, 0, 0, 0, 0, 1, 2000, 2000, 1, 32768, 35653632, 0, 0, 0, 0, 0, 0, 0, 0, 0, 98425, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 3, 1, 1, 1, 1, 0, 0, -1, '', '', 0, 0, 0, 0, 0, 0, 0, 'npc_unstable_amalgamation');

-- Elite 
UPDATE `creature_template` SET 
`dmg_multiplier` = 1
 WHERE `entry` = 98728;
 
 
-- Raro
UPDATE `creature_template` SET 
`dmg_multiplier` = 0.8, 
`AffixState` = 15871
 WHERE `entry` = 98426;
 
-- Normal 
 UPDATE `creature_template` SET 
`dmg_multiplier` = 0.6, 
`AffixState` = 15871
 WHERE `entry` = 98435;
 
 -- Rata
 
 UPDATE `creature_template` SET 
`dmg_multiplier` = 0.7
 WHERE `entry` = 98732;
 
 -- Vidente 

DELETE FROM `smart_scripts` WHERE `entryorguid` = 105651;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(105651, 0, 0, 0, 0, 0, 100, 0, 18000, 19000, 18000, 19000, 11, 211771, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'AW - ever 18- cast'),
(105651, 0, 1, 0, 0, 0, 100, 0, 15000, 15000, 16000, 16000, 11, 211775, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'AW - ever 8- cast');

-- Maligno
DELETE FROM `creature` WHERE `guid` = 14507251;
DELETE FROM `creature` WHERE `guid` = 14507249;
DELETE FROM `creature` WHERE `guid` = 14507250;

/* Evento Cosmetico 1er jefe */

DELETE FROM `creature_template` WHERE `entry` = 600103;
INSERT INTO `creature_template`(`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES 
(600103, 0, 110, 110, 0, 0, 0, 0, 100, 6, 35, 0, 0, 1, 1.14286, 1.14286, 1, 0, 0, 0, 0, 1, 2000, 2000, 1, 32768, 2048, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 7, 1, 1, 1, 1, 1, 0, -1, '', '', 0, 0, 0, 0, 0, 0, 0, '');


DELETE FROM `creature_template_spell` WHERE `entry` = 600103 AND `spell` = 196392;
INSERT INTO `creature_template_spell`(`entry`, `spell`, `difficultyMask`, `timerCast`, `comment`) VALUES (600103, 196392, 6, 0, '@Overcharge Mana');



DELETE FROM `creature_template_wdb` WHERE `Entry` = 600103;
INSERT INTO `creature_template_wdb`(`Entry`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `Title`, `TitleAlt`, `CursorName`, `TypeFlags`, `TypeFlags2`, `Type`, `Family`, `Classification`, `KillCredit1`, `KillCredit2`, `VignetteID`, `Displayid1`, `Displayid2`, `Displayid3`, `Displayid4`, `HpMulti`, `PowerMulti`, `Leader`, `QuestItem1`, `QuestItem2`, `QuestItem3`, `QuestItem4`, `QuestItem5`, `QuestItem6`, `QuestItem7`, `QuestItem8`, `QuestItem9`, `QuestItem10`, `MovementInfoID`, `RequiredExpansion`, `FlagQuest`, `VerifiedBuild`) VALUES 
(600103, 'Bunny cast ', '', '', '', '', '', '', '', '', '', '', 2097224, 0, 3, 0, 0, 0, 0, 0, 69493, 0, 0, 0, 0.75, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 22566);

-- <Could not generate name> SAI
SET @Mana := 600103;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Mana;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Mana,0,0,0,1,0,100,0,300,300,500,500,11,196392,0,0,0,0,0,11,98734,40,0,0,0,0,0,"Off combat cast spell"),
(@Mana,0,1,0,10,0,100,1,1,10,0,0,51,0,0,0,0,0,0,10,14507249,600103,0,0,0,0,0,"PLayer AOE Despaw");

DELETE FROM `creature` WHERE `guid` = 14507249; 
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(14507249, 600103, 1516, 7855, 7855, 8388868, 1, '', 0, 0, 3146.52, 5118.35, 626.404, 1.96159, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

/* Caster 105617 y 98776 diablillos */

UPDATE `creature_template` SET 
`spell1` = 211571
WHERE `entry` = 105617;



-- SpellID:1098 Esclavizar demonio
UPDATE `creature_template_wdb` 
SET `Family` = 23 
WHERE `Entry` = 105617;

UPDATE `creature_template` SET 
`unit_class` = 4, 
`unit_flags` = 32832,
`unit_flags2` = 2048
WHERE `entry` = 105617;

UPDATE `creature_template` SET 
`rangeattacktime` = 4000 
WHERE `entry` = 105617;

DELETE FROM `smart_scripts` WHERE `entryorguid`=105617;
DELETE FROM `smart_scripts` WHERE `entryorguid`=98776;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(105617, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 1000, 1000, 11, 211571, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'ever 6 - cast'),
(105617, 0, 1, 0, 0, 0, 100, 0, 20000, 25000, 24000, 25000, 11, 211632, 0, 0, 0, 0, 0, 26, 20, 0, 0, 0, 0, 0, 0, 'ever 25 - cast'),
(98776, 0, 0, 0, 60, 0, 100, 1, 1, 3, 34000, 35000, 11, 211762, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'on pull - cast'),
(98776, 0, 1, 0, 0, 0, 100, 0, 1000, 2000, 1000, 2000, 11, 211769, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'ever 1 - cast'),
(98776, 0, 2, 0, 1, 0, 100, 0, 5000, 7000, 1000, 2000, 41, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'ever 1 - cast'),
(98776, 0, 3, 0, 25, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, '');