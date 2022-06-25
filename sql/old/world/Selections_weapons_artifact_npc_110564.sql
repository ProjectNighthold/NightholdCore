-- NPC 110564 "Alonsus Faol" --
DELETE FROM `legion_world`.`creature_template` WHERE `entry`=110564;
INSERT INTO `legion_world`.`creature_template` (`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES 
(110564, 19157, 113, 113, 0, 0, 0, 0, 100, 0, 35, 3, 0, 1, 1.14286, 1.14286, 1, 0, 0, 0, 0, 1, 2000, 2000, 1, 33280, 2048, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 3, 1, 1, 1, 1, 0, 0, -1, '', '', 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `legion_world`.`smart_scripts` WHERE `entryorguid`=110564;
INSERT INTO `legion_world`.`smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(110564, 0, 0, 0, 20, 0, 100, 0, 43372, 0, 0, 0, 1, 2, 6000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'QR - ST'),
(110564, 0, 1, 0, 20, 0, 100, 0, 43398, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'QR - ST'),
(110564, 0, 2, 3, 19, 0, 100, 0, 43402, 0, 0, 0, 85, 222849, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'QA - ST'),
(110564, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 33, 110564, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - KC'),
(110564, 0, 4, 0, 19, 0, 100, 0, 40706, 0, 0, 0, 85, 199700, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Quest Accept - Invoker Cast Spell'),
(110564, 0, 5, 0, 62, 0, 100, 0, 19157, 0, 0, 0, 85, 199700, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gossip Select - Invoker Cast Spell'),
(101314, 0, 6, 7, 19, 0, 100, 0, 40710, 0, 0, 0, 33, 101365, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Quest Accept - Kill Credit'),

