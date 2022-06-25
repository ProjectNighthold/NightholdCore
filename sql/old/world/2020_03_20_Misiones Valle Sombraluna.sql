/*
quest 36624
npc id 81003 Se le adiciono el gossip menu correspondiente y el npc_flag nencesario
*/
UPDATE creature_template SET gossip_menu_id= 16597, npcflag = 8194 WHERE entry = 81103;
/* Taxi to Spires Arak from Alliance Garrinson */
DELETE FROM smart_scripts WHERE `entryorguid` =81103 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES ('81103', '0', '4', '0', '62', '0', '100', '0', '16597', '4', '0', '0', '85', '173227', '0', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', 'Taxi to Spires Arak');


/*
npc id 16613 Se le adiciono el gossip menu correspondiente
*/
UPDATE creature_template SET gossip_menu_id= 16613 WHERE entry = 84455;

/* Fly master Horda 79407 Garrison taxi para Pinaculos de Arak*/
DELETE FROM smart_scripts WHERE `entryorguid` =79407 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES ('79407', '0', '4', '0', '62', '0', '100', '0', '42010', '4', '0', '0', '85', '173251', '0', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', 'Taxi  to Spires of Arak.');
