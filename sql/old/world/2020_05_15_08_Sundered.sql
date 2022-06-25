-- "Sundered" (QuestID: 39850)

/*creature*/
DELETE FROM `creature` WHERE `guid` IN (146728281, 146728276, 146728280) AND `id` IN (97571, 97356, 97570);
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES
(146728281, 97571, 1463, 7588, 7630, 1, 1, '', 0, 0, 112.366, 704.08, 17.823, 5.49779, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(146728276, 97356, 1463, 7588, 7630, 1, 1, '', 0, 0, 231.622, 378.858, 6.28104, 1.41372, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(146728280, 97570, 1463, 7588, 7630, 1, 1, '', 0, 0, 109.45, 449.408, -14.6794, 1.25664, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);


/*npc_spellclick_spells*/
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (97571, 97356, 97570);
INSERT INTO `npc_spellclick_spells`(`npc_entry`, `spell_id`, `cast_flags`, `user_type`, `add_npc_flag`) VALUES
(97571, 192493, 1, 0, 1),
(97356, 192493, 1, 0, 1),
(97570, 192493, 1, 0, 1);

/*smart_scripts*/
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (97571, 97356, 97570);
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(97571, 0, 0, 0, 73, 0, 100, 0, 97571, 0, 0, 0, 33, 97484, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, ''),
(97356, 0, 0, 0, 73, 0, 100, 0, 97356, 0, 0, 0, 33, 97482, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, ''),
(97570, 0, 0, 0, 73, 0, 100, 0, 97570, 0, 0, 0, 33, 97483, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '');
