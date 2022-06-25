/* spawns de las miones*/
/*https://es.wowhead.com/quest=34804/aqu%C3%AD-jam%C3%A1s*/
/*https://es.wowhead.com/quest=35554/noticias-de-las-cumbres-de-arak*/
/*https://es.wowhead.com/npc=78937/rexxar*/
/*https://www.wowhead.com/npc=56114/kang-bramblestaff*/


DELETE FROM `creature` WHERE `ID` IN (56114,78937,80058,81492,81912,79457);
insert into `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES
("243513", "56114", "870", "6134", "6009", "1", "1", "", "0", "0", "-1140.89", "-207.615", "31.3663", "5.60923", "120", "0", "0", "1", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("243514", "56114", "870", "6134", "6016", "1", "1", "", "0", "0", "-1189.73", "1766.66", "15.3717", "3.22886", "120", "0", "0", "1", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("146772019", "56114", "870", "6134", "6378", "1", "1", "", "0", "1", "-1372.45", "1817.46", "13.5963", "5.06924", "300", "0", "0", "26268", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("146768412", "78937", "1116", "6719", "6910", "1", "65535", "", "0", "1", "-1364.27", "-2284.47", "22.2807", "4.82031", "300", "0", "0", "21745400", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("146767707", "80058", "1116", "6662", "6662", "1", "1", "", "0", "1", "3617.12", "1820.71", "214.877", "4.24968", "300", "0", "0", "386745", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("146767864", "81492", "1116", "6719", "7078", "1", "65535", "", "0", "0", "1936.56", "309.613", "89.7237", "1.33298", "300", "0", "0", "59632", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("261106", "81492", "1331", "7078", "7211", "2", "1", "", "0", "0", "1924.06", "284", "89.0492", "1.83406", "7200", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("261387", "81492", "1159", "7078", "7086", "2", "1", "", "0", "0", "1922.84", "284.095", "89.0492", "1.86505", "7200", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("351725", "81492", "1158", "7078", "7085", "2", "1", "", "0", "0", "1941.73", "330.436", "89.0492", "1.76089", "7200", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("351768", "79457", "1158", "7078", "7085", "2", "1", "", "0", "0", "1848.15", "244.564", "76.8859", "6.02785", "7200", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("351769", "81912", "1158", "7078", "7085", "2", "1", "", "0", "0", "1858.77", "243", "77.0764", "3.10395", "7200", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("352621", "81912", "1116", "6719", "7117", "1", "1", "", "0", "0", "1203.88", "-1482.67", "-6.27526", "2.24579", "120", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");



/* add quest 34778*/
DELETE FROM `creature_queststarter` WHERE `quest` IN (34778);
insert into `creature_queststarter` (id, quest) VALUES
(79457, 34778);

/* repracion de flag de npc*/
DELETE FROM `creature_template` WHERE `entry` IN (78275);
insert into `creature_template` (`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) values
("78275", "0", "90", "90", "72", "90", "100", "0", "2000", "4", "634", "0", "0", "1", "1.14286", "1.14286", "1", "0", "0", "0", "0", "1", "2000", "2000", "1", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "", "0", "3", "1", "1", "1", "1", "0", "0", "-1", "", "", "0", "0", "0", "0", "0", "0", "0", "");

