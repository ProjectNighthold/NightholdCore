/* El spell fue rectificado en SpellAuraEffect.cpp  */
DELETE FROM `spell_script_names` WHERE (`spell_id`='194022') AND (`ScriptName`='spell_pri_mental_fortitude');

/* Mind Trauma Honor Talent */
DELETE FROM `spell_script_names` WHERE (`spell_id`='247777') AND (`ScriptName`='spell_pri_mind_trauma_negative');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('247777', 'spell_pri_mind_trauma_negative');

/* Control Mental spell 605 no se podia cancelar*/
DELETE FROM `spell_script_names` WHERE (`spell_id`='605') AND (`ScriptName`='spell_pri_mind_control');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('605', 'spell_pri_mind_control');
DELETE FROM `spell_script_names` WHERE (`spell_id`='45112') AND (`ScriptName`='spell_pri_mind_control_cancel');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('45112', 'spell_pri_mind_control_cancel');

DELETE FROM `spell_target_filter` WHERE (`spellId`='15290') AND (`targetId`='56') AND (`option`='0') AND (`param1`='0') AND (`param2`='0') AND (`param3`='0');
/* Eliminado por no ser necesario
INSERT INTO `spell_target_filter` (`spellId`, `index`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) VALUES ('15290', '0', '56', '0', '0', '0', '0', '199388', '0', '1', '1', '1', '0', '2', '1', 'Объятия вампира');*/

/* Eliminando script innecesario*/
DELETE FROM `spell_script_names` WHERE (`spell_id`='15290') AND (`ScriptName`='spell_pri_vampiric_embrace_heal');
/*
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('15290', 'spell_pri_vampiric_embrace_heal');
*/
