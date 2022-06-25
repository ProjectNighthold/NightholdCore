/* Todo lo necesario esta implementado en spell_warrior.cpp 
 Blazing Tail Glyph - Modifc Charge (spell id 100)
*/
DELETE FROM `spell_script_names` WHERE `spell_id`= '126664';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('126664', 'spell_warr_charge_damage');
