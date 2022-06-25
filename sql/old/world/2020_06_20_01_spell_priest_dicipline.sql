/* spell priest Penance  */
DELETE FROM `spell_script_names` WHERE (`ScriptName`='spell_pri_penance_aura');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('47757', 'spell_pri_penance_aura');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('47758', 'spell_pri_penance_aura');

/* Removiendo script*/
DELETE FROM `spell_script_names` WHERE (`ScriptName`='spell_pri_clarity_of_will');