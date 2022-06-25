/*NPC DUPLICADO IN PANDARIA*/
DELETE FROM `creature` WHERE `guid`= '203660';
DELETE FROM `creature` WHERE `guid`= '214915';
DELETE FROM `creature` WHERE `guid`= '243684';
DELETE FROM `creature` WHERE `guid`= '243686';
DELETE FROM `creature` WHERE `guid`= '243673';
DELETE FROM `creature` WHERE `guid`= '243685';
DELETE FROM `creature` WHERE `guid`= '807356';
DELETE FROM `creature` WHERE `guid`= '807306';
DELETE FROM `creature` WHERE `guid`= '807342';

/*FINX ZONE PANDAREN */
UPDATE `creature_template` SET `ScriptName` = 'mob_tushui_trainee' WHERE `entry` = '54587';
UPDATE `creature_template` SET `ScriptName` = 'mob_tushui_trainee' WHERE `entry` = '65471';
UPDATE `creature_template` SET `ScriptName` = 'boss_jaomin_ro' WHERE `entry` = '54611';

DELETE FROM `creature_template_wdb` WHERE `Entry` = '2000000';
INSERT INTO `creature_template_wdb` (`Entry`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `Title`, `TitleAlt`, `CursorName`, `TypeFlags`, `TypeFlags2`, `Type`, `Family`, `Classification`, `KillCredit1`, `KillCredit2`, `VignetteID`, `Displayid1`, `Displayid2`, `Displayid3`, `Displayid4`, `HpMulti`, `PowerMulti`, `Leader`, `QuestItem1`, `QuestItem2`, `QuestItem3`, `QuestItem4`, `QuestItem5`, `QuestItem6`, `QuestItem7`, `QuestItem8`, `QuestItem9`, `QuestItem10`, `MovementInfoID`, `RequiredExpansion`, `FlagQuest`, `VerifiedBuild`) VALUES ('2000000', 'Master Shang Xi', '', '', '', '', '', '', '', '', '', '', '0', '0', '7', '0', '0', '0', '0', '0', '39574', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '4', '0', '22566');

DELETE FROM `creature_template_wdb` WHERE `Entry` = '2000001';
INSERT INTO `creature_template_wdb` (`Entry`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `Title`, `TitleAlt`, `CursorName`, `TypeFlags`, `TypeFlags2`, `Type`, `Family`, `Classification`, `KillCredit1`, `KillCredit2`, `VignetteID`, `Displayid1`, `Displayid2`, `Displayid3`, `Displayid4`, `HpMulti`, `PowerMulti`, `Leader`, `QuestItem1`, `QuestItem2`, `QuestItem3`, `QuestItem4`, `QuestItem5`, `QuestItem6`, `QuestItem7`, `QuestItem8`, `QuestItem9`, `QuestItem10`, `MovementInfoID`, `RequiredExpansion`, `FlagQuest`, `VerifiedBuild`) VALUES ('2000001', 'Master Shang Xi', '', '', '', '', '', '', '', '', '', '', '0', '0', '7', '0', '0', '0', '0', '0', '39574', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '4', '0', '22566');


DELETE FROM `creature_template` WHERE `Entry` = '2000000';
INSERT INTO `creature_template` (`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES ('2000000', '0', '90', '90', '0', '0', '0', '0', '0', '4', '35', '3', '0', '1', '1.14286', '1.14286', '1', '450', '540', '0', '45', '1', '2000', '2000', '1', '32768', '32768', '0', '0', '0', '0', '0', '0', '464', '696', '174', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1416', '0', '0', 'SmartAI', '0', '3', '1', '1', '1', '1', '0', '0', '0', '', '', '0', '0', '0', '0', '0', '0', '0', '');

DELETE FROM `creature_template` WHERE `Entry` = '2000001';
INSERT INTO `creature_template` (`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES ('2000001', '0', '90', '90', '0', '0', '0', '0', '0', '4', '35', '3', '0', '1', '1.14286', '1.14286', '1', '450', '540', '0', '45', '1', '2000', '2000', '1', '32768', '32768', '0', '0', '0', '0', '0', '0', '464', '696', '174', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1416', '0', '0', 'SmartAI', '0', '3', '1', '1', '1', '1', '0', '0', '0', '', '', '0', '0', '0', '0', '0', '0', '0', '');


DELETE FROM `creature_template_wdb_locale` WHERE `ID` = '2000000';
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000000', 'deDE', '', '', 'Meister Shang Xi', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000000', 'enUS', '', '', 'Master Shang Xi', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000000', 'esES', '', '', 'Maestro Shang Xi', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000000', 'esMX', '', '', 'Maestro Shang Xi', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000000', 'frFR', '', '', 'Maître Shang Xi', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000000', 'itIT', '', '', 'Maestro Shang Xi', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000000', 'koKR', '', '', '사부 샹 시', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000000', 'ptBR', '', '', 'Mestre Shang Xi', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000000', 'ruRU', '', '', 'Мастер Шан Си', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000000', 'zhCN', '', '', '尚喜师父', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000000', 'zhTW', '', '', '尚羲大師', '', '', '', '', '', '', '', '26124');

DELETE FROM `creature_template_wdb_locale` WHERE `ID` = '2000001';
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000001', 'deDE', '', '', 'Meister Shang Xi', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000001', 'enUS', '', '', 'Master Shang Xi', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000001', 'esES', '', '', 'Maestro Shang Xi', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000001', 'esMX', '', '', 'Maestro Shang Xi', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000001', 'frFR', '', '', 'Maître Shang Xi', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000001', 'itIT', '', '', 'Maestro Shang Xi', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000001', 'koKR', '', '', '사부 샹 시', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000001', 'ptBR', '', '', 'Mestre Shang Xi', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000001', 'ruRU', '', '', 'Мастер Шан Си', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000001', 'zhCN', '', '', '尚喜师父', '', '', '', '', '', '', '', '26124');
INSERT INTO `creature_template_wdb_locale` (`ID`, `Locale`, `Title`, `TitleAlt`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `VerifiedBuild`) VALUES ('2000001', 'zhTW', '', '', '尚羲大師', '', '', '', '', '', '', '', '26124');


UPDATE `creature_queststarter` SET `id`='53566' WHERE `quest`= '29524';


/*SAI MASTER SHAN XI QUEST INCIAL*/
SET @ENTRY := '2000000';
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,1,64,0,100,0,0,0,0,0,85,114611,0,0,0,0,0,7,0,0,0,0,0,0,0,"on gossip hello - give item"),
(@ENTRY,0,2,0,19,0,100,0,29408,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"link - say text"),
(@ENTRY,0,3,0,47,0,100,0,29409,0,0,0,41,2,0,0,0,0,0,0,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)");


DELETE FROM `creature_text` WHERE `Entry` = '2000000';
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES ('2000000', '0', '0', 'On your firt try! Now, Take the flame to the top of the temple and burn the scrpll that you find there.', '12', '0', '50', '0', '0', '27795', '59672', '0', '0', '0', 'Master Shan XI');


UPDATE creature_queststarter SET id=55583 WHERE quest=29784;

UPDATE creature_template_wdb SET typeflags= 0 WHERE entry=54734;
UPDATE creature_template_wdb SET HpMulti= 10 WHERE entry=54734;





