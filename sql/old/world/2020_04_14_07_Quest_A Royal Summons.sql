-- A Royal Summons (QuestID: 38035)

/*Table_gossip_menu*/
DELETE FROM `gossip_menu` WHERE (`Entry`='19356') AND (`TextID`='0');
INSERT INTO `gossip_menu` (`Entry`) VALUES ('19356');

/*Table_gossip_menu_option*/
DELETE FROM `gossip_menu_option` WHERE (`MenuID`='19356') AND (`OptionIndex`='0');
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionNPC`, `OptionText`, `OptionType`, `OptionNpcflag`, `OptionNpcflag2`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxCurrency`, `BoxText`, `OptionBroadcastTextID`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
('19356', '0', '0', 'Listo!', '1', '1', '0', '0', '0', '0', '0', '0', '', '0', '0', '0');

/*Table_Creature_template*/
DELETE FROM `creature_template` WHERE (`entry`='96663');
INSERT INTO `creature_template` (`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES 
('96663', '19356', '106', '106', '0', '0', '0', '0', '100', '6', '1819', '3', '0', '1', '1', '1.14286', '1', '0', '0', '0', '0', '1', '2000', '2000', '2', '32768', '2048', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'SmartAI', '0', '3', '1', '1', '1', '1', '0', '0', '-1', '', '', '0', '0', '0', '0', '0', '0', '0', '');

/*Table_quest_objetives*/
DELETE FROM `quest_objectives` WHERE `ID` = 280241;
INSERT INTO `quest_objectives`(`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES
(280241, 38035, 0, 1, 92122, 1, 2, 0, 0, NULL, 21737);

/*Table_smarts_scripts*/
SET @wolf := 96663;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@wolf;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@wolf AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@wolf,0,0,3,62,0,100,0,19356,0,0,0,1,0,4000,0,0,0,0,1,0,0,0,0,0,0,0,"UD - ST"),
(@wolf,0,1,0,52,0,100,0,0,96663,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"TO - ST"),
(@wolf,0,2,0,19,0,100,0,39800,0,0,0,62,1220,0,0,0,0,0,7,0,0,0,3208.51,3075.9,440.21,1.1,"QA - TP"),
(@wolf,0,3,0,62,0,100,0,19356,0,0,0,33,92122,0,0,0,0,0,7,0,0,0,0,0,0,0,"kill credi");

