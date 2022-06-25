/* kunzen ritual candle */
update `gameobject_template` set `type`= 22 where `entry` = 210955;
update `gameobject_template` set `Data0`= 114439 where `entry` = 210955;
update `gameobject_template` set `Data1`= 0 where `entry` = 210955;
update `gameobject_template` set `Data1`= 0 where `entry` = 210955;
update `gameobject_template` set `Data3`= 0 where `entry` = 210955;
update `gameobject_template` set `Data5`= 0 where `entry` = 210955;
update `gameobject_template` set `Data10`= 0 where `entry` = 210955;
update `gameobject_template` set `Data23`= 0 where `entry` = 210955;


/* blazing ember */
update `gameobject_template` set `type`= 22 where `entry` = 210890;
update `gameobject_template` set `Data0`= 113891 where `entry` = 210890;
update `gameobject_template` set `Data1`= 0 where `entry` = 210890;
update `gameobject_template` set `Data3`= 0 where `entry` = 210890;
update `gameobject_template` set `Data5`= 0 where `entry` = 210890;
update `gameobject_template` set `Data10`= 0 where `entry` = 210890;
update `gameobject_template` set `Data23`= 0 where `entry` = 210890;

/* game_object table */
update `gameobject` set `spawntimesecs` = 150 where `id` = 210955;
update `gameobject` set `spawntimesecs` = 150 where `id` = 210890;


/* ritual candle bunny */

delete from `creature_template` where `entry` = 1000000;
INSERT INTO `creature_template` (`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`)
VALUES ('1000000', '0', '100', '100', '0', '0', '0', '0', '100', '0', '35', '0', '0', '1', '1.14286', '1.14286', '1', '0', '0', '0', '0', '1', '2000', '2000', '1', '131072', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '0', '3', '1', '1', '1', '1', '0', '128', '-1', '', '', '0', '0', '0', '0', '0', '0', '0', '');

delete from `creature` where `guid` = 146728595;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) 
VALUES ('146728595', '1000000', '870', '5805', '6064', '1', '1', '', '0', '0', '194.96', '1514.56', '427.41', '4.04', '300', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');

delete from `creature_template_wdb` where `entry` = 1000000;
INSERT INTO `creature_template_wdb` (`Entry`, `Name1`, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `Title`, `TitleAlt`, `CursorName`, `TypeFlags`, `TypeFlags2`, `Type`, `Family`, `Classification`, `KillCredit1`, `KillCredit2`, `VignetteID`, `Displayid1`, `Displayid2`, `Displayid3`, `Displayid4`, `HpMulti`, `PowerMulti`, `Leader`, `QuestItem1`, `QuestItem2`, `QuestItem3`, `QuestItem4`, `QuestItem5`, `QuestItem6`, `QuestItem7`, `QuestItem8`, `QuestItem9`, `QuestItem10`, `MovementInfoID`, `RequiredExpansion`, `FlagQuest`, `VerifiedBuild`) 
VALUES ('1000000', 'bunny', '', '', '', '', '', '', '', '', '', '', '0', '0', '7', '0', '0', '0', '0', '0', '373', '0', '0', '0', '1', '1', '0', '773', '772', '0', '0', '0', '0', '0', '0', '0', '0', '100', '0', '0', '22566');

/* burning ember bunny */
delete from `creature` where `guid` =207741;
delete from `creature` where `guid` =207743;
update `creature_template` set `unit_flags`= 131072 where `entry` = 59260;
update `creature_template` set `faction`= 35 where `entry` = 59260;
update `creature_template_wdb` set `Name1`= "Blazing Ember kicked" where `entry` = 59260;


 /* quest objectives for quest id 30325 */
update `quest_objectives` set `Type` = 0 where `ID`= 259828;
update `quest_objectives` set `Type` = 0 where `ID`= 259827;
update `quest_objectives` set `ObjectID` = 1000000 where `ID`= 259827;
update `quest_objectives` set `ObjectID` = 59260 where `ID`= 259828;
 
 
/* Kunzen Ritual Candle SAI */
SET @ENTRY := 210955;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
('210955', '1', '0', '0', '64', '0', '100', '0', '0', '0', '0', '0', '33', '1000000', '0', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', 'ritual candle'),
('210955', '1', '1', '0', '64', '0', '100', '0', '0', '0', '0', '0', '41', '1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'ritual candle'),
('210955', '1', '2', '1', '64', '0', '100', '0', '0', '0', '0', '0', '70', '60', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'ritual candle');

/* burning ember SAI */
SET @ENTRY := 210890;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
('210890', '1', '0', '0', '64', '0', '100', '0', '0', '0', '0', '0', '33', '59260', '0', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', 'burning ember'),
('210890', '1', '1', '0', '64', '0', '100', '0', '0', '0', '0', '0', '41', '1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'burning ember'),
('210890', '1', '2', '1', '64', '0', '100', '0', '0', '0', '0', '0', '70', '60', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'burning ember');

