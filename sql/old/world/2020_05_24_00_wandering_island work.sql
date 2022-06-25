-- estos npc dificultan entregar una mision cercana que te pueden hasta matar al llamar los demas que estan cerca
DELETE FROM `creature` WHERE `guid`=243837;
DELETE FROM `creature` WHERE `guid`=243835;
DELETE FROM `creature` WHERE `guid`=243836;
DELETE FROM `creature` WHERE `guid`=243891;
DELETE FROM `creature` WHERE `guid`=243827;
DELETE FROM `creature` WHERE `guid`=244050;
-- npc que no deverian estar que son duplicados sobre otro ya existente
DELETE FROM `creature` WHERE `guid`=244443;
DELETE FROM `creature` WHERE `guid`=244527;
-- npc unico que sale encima de la perla que esta spawneado 3 veces cuando deveria estar 1 sola vez
DELETE FROM `creature` WHERE `guid`=244475;
DELETE FROM `creature` WHERE `guid`=244529;
-- npc de mision que esta repetido que al matarlo completa una mision npcid 55506
DELETE FROM `creature` WHERE `guid`=244788;
-- el npc que esta puesto en la base de datos no es el correcto ademas de que da problemas en la bd por eso borre el que estaba en la bd y arregle al que era la quest 29784
DELETE FROM `creature_queststarter` WHERE `id`=65558 AND `quest`=29784;
DELETE FROM `creature_queststarter` WHERE `id`=55583 AND `quest`=29784;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES (55583, 29784);
-- al suceder la mision en la que lo derrotamos el npc no deveria salir atacando como hace en esta bd lo que no deveria atakar al los personajes pero cambiandole la faccion se arregla ese problema
DELETE FROM `creature_template` WHERE `entry`=55874;
INSERT INTO `creature_template` (`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDelta`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`, `WorldEffects`, `PassiveSpells`, `StateWorldEffectID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `IgnoreLos`, `AffixState`, `MaxVisible`, `ScriptName`) VALUES (55874, 0, 93, 93, 0, 0, 0, 0, 0, 4, 35, 0, 0, 1.44444, 1.5873, 1.14286, 1, 1, 1, 0, 4, 1, 2000, 2000, 1, 32768, 2048, 0, 0, 0, 0, 0, 0, 8, 13, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, '');


