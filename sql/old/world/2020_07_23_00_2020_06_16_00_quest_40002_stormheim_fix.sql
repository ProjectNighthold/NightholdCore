-- CORREGIDO SAI PARA QUE NO REPITA EL TEXTO CADE VEZ QUE TE LE ACERQUES
DELETE FROM `smart_scripts` WHERE `entryorguid`=-291392 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES (-291392, 0, 0, 0, 10, 0, 100, 0, 1, 10, 10000, 20000, 1, 3, 6000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'al acercarte a 10 yardas dice texto');
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES (-291392, 0, 1, 0, 38, 0, 100, 0, 4, 4, 0, 0, 41, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'al recivir datas despawn');