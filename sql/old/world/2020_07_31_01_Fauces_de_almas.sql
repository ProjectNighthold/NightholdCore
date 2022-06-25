/* 

   Arreglado el daño de la Bengala 
   de la criatura Esclavo tallarrunas[NPCID:102375]  
   en Fauces de almas, añadidos los textos y el spell (Sabor a sangre)
   
 */

DELETE FROM `creature_template_spell` WHERE `entry` = 102375;
INSERT INTO `creature_template_spell`(`entry`, `spell`, `difficultyMask`, `timerCast`, `comment`) VALUES
(102375, 202365, 7, 0, '@Fire Blast'),
(102375, 213738, 7, 0, '@Taste of Blood'),
(102375, 232332, 7, 0, '@Flare');


/*  Esclavo tallarrunas[NPCID:102375] 
 npc_mos_runecarver_slave */ 


UPDATE `creature_template` SET 
`AIName` = 'SmartAI', 
`ScriptName` = '' 
WHERE `entry` = 102375;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 102375;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(102375, 0, 0, 0, 0, 0, 100, 0, 3000, 4000, 5000, 7000, 11, 202365, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'cast @Fire Blast 5s'),
(102375, 0, 1, 0, 0, 0, 100, 0, 9000, 9000, 11000, 11000, 11, 232332, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, ' cast Flare 11s'),
(102375, 0, 2, 0, 0, 0, 100, 0, 10000, 10000, 12000, 12000, 11, 213738, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ' cast Taste of Blood 15s'),
(102375, 0, 3, 0, 0, 0, 100, 0, 16000, 16000, 20000, 20000, 1, 0, 9000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ' cast talk '),
(102375, 0, 4, 0, 0, 0, 100, 0, 20000, 20000, 27000, 27000, 1, 1, 12000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ' cast talk');

DELETE FROM `creature_text` WHERE `Entry` = 102375;
INSERT INTO `creature_text`(`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
(102375, 1, 0, 'Болван. Наше проклятие тебя погубит...', 14, 0, 100, 0, 0, 0, 100515, 0, 0, 0, 'Проклятый морем работорговец to Player'),
(102375, 0, 0, 'Молчать! Теперь твоя душа принадлежит Хелии.', 14, 0, 100, 0, 0, 0, 100494, 0, 0, 0, 'Проклятый морем работорговец to Player');

/* Captured */
DELETE FROM `creature_template_addon` WHERE `entry` = 104906;
INSERT INTO `creature_template_addon`(`entry`, `bytes1`, `auras`) VALUES (104906, 8, 'Captured Val\'kyr');


/* del  */
DELETE FROM `creature` WHERE `guid` = 280265118;

/* Spell Rain */

DELETE FROM `spell_area` WHERE `spell` = 193982 AND `area` = 7811;
INSERT INTO `spell_area`(`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `classmask`, `active_event`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(193982, 7811, 0, 0, 0, 0, 0, 0, 2, 1, 64, 11);

/* Guadaña */
UPDATE `creature_template` SET 
`scale` = 0.6 
WHERE `entry` = 100839;

/* Mist */

DELETE FROM `creature_template` WHERE `entry` = 600104;
INSERT INTO `creature_template`(`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES 
(600104, 0, 110, 110, 0, 0, 0, 0, 100, 6, 35, 0, 0, 1, 1.14286, 1.14286, 2, 0, 0, 0, 0, 1, 2000, 2000, 1, 33554432, 2048, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 7, 1, 1, 1, 1, 1, 0, -1, '', '', 0, 0, 0, 0, 0, 0, 0, '');


DELETE FROM `creature_template_wdb` WHERE `Entry` = 600104;
INSERT INTO `creature_template_wdb`(`Entry`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `Title`, `TitleAlt`, `CursorName`, `TypeFlags`, `TypeFlags2`, `Type`, `Family`, `Classification`, `KillCredit1`, `KillCredit2`, `VignetteID`, `Displayid1`, `Displayid2`, `Displayid3`, `Displayid4`, `HpMulti`, `PowerMulti`, `Leader`, `QuestItem1`, `QuestItem2`, `QuestItem3`, `QuestItem4`, `QuestItem5`, `QuestItem6`, `QuestItem7`, `QuestItem8`, `QuestItem9`, `QuestItem10`, `MovementInfoID`, `RequiredExpansion`, `FlagQuest`, `VerifiedBuild`) VALUES 
(600104, 'Mist', '', '', '', '', '', '', '', '', '', '', 2097224, 0, 3, 0, 0, 0, 0, 0, 42944, 0, 0, 0, 0.75, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 22566);

-- <Mist> SAI
SET @Mist := 600104;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Mist;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Mist,0,0,0,10,0,100,0,1,10,0,0,41,5000,0,0,0,0,0,10,14507250,600104,0,0,0,0,0,"PLayer AOE Despaw");


DELETE FROM `creature` WHERE `guid` = 14507250;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(14507250, 600104, 1492, 7812, 7811, 8388870, 1, '', 0, 1, 2933.48, 851.615, 550.69, 4.67738, 7200, 0, 0, 33194422, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
