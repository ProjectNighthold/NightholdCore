/*
Quest ID 29347 - Cebo vivo 
 Eliminando Smart_Script para este areatrigger dado que el funcionamiento se ejecuta en los script de las auras */
DELETE FROM `spell_script_names` WHERE `spell_id`='18960';

/* Auras utilziadas en la mision */
DELETE FROM `spell_script_names` WHERE `spell_id` IN('99435','99424');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('99435', 'spell_q29347_bait');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('99424', 'spell_q29347_crayfish');
