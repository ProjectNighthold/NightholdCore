-- npc 59626 sale en la cueva del espiritu del fuego ya deve hacer el visual de expulsar fuego cada cierto tiempo
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=59626;

DELETE FROM `smart_scripts` WHERE `entryorguid`=5962600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES (5962600, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 114684, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame Spout - Cast Flame Spout dmg');
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES (5962600, 9, 1, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 28, 114686, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame Spout - Remove Aura');


DELETE FROM `smart_scripts` WHERE `entryorguid`=59626 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES (59626, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame Spout - On Respawn - Set React State');
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES (59626, 0, 1, 2, 60, 0, 100, 0, 0, 6000, 12000, 18000, 11, 114686, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame Spout - Update - Cast Flame Spout visual');
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES (59626, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 5962600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame Spout - Update - Run Script');

-- textos de aysa que medita dentro de la cueva que estavan en ruso traducidos en parte
DELETE FROM `creature_text` WHERE `Entry`=59642;
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES (59642, 0, 0, 'Manten lejos a esas creaturas mientras medito. Pronto obtendremos respuestas.', 12, 0, 100, 0, 0, 27398, 59161, 0, 0, 0, 'Aysa Cloudsinger to Player');
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES (59642, 1, 0, 'And so our path lays before us. Speak to Master Shang Xi, he will tell you what comes next.', 12, 0, 100, 0, 0, 27399, 60046, 0, 0, 0, 'Aysa Cloudsinger to Player');

-- npc 55020 que sale cerca de la quest del espiritu del agua que al estar a unas 15 yardas de el te va a castear la spell para caminar arriva del agua con la condicion de que solo funcione cuando tengas la quest 29679 para prevenir algunos mareos de la spell con los players lo decidi hacer de esa manera
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=55020;

DELETE FROM `smart_scripts` WHERE `entryorguid`=55020 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES (55020, 0, 0, 0, 10, 0, 100, 0, 1, 15, 0, 0, 11, 116571, 0, 0, 0, 0, 0, 18, 15, 0, 0, 0, 0, 0, 0, 'cuando el jugador este a una distancia de 15 yardas te va a castear la spell pra caminar arriva del agua');

-- condition for npc 55020
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=55020;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES (22, 1, 55020, 0, 0, 9, 0, 29679, 0, 0, 0, 0, '', 'Only Run script if quest is taken');






