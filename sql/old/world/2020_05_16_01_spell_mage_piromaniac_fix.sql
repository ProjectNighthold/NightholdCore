/* Deleting Srcript */
DELETE FROM `spell_script_names` WHERE (`ScriptName`='spell_mage_hot_streak_big');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('2120', 'spell_mage_hot_streak_big');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('11366', 'spell_mage_hot_streak_big');


/* Inserting in spell_link_spell */
DELETE FROM  spell_linked_spell WHERE spell_trigger = '2120' AND `spell_effect`='48108' AND `type`='8';
DELETE FROM  spell_linked_spell WHERE spell_trigger = '11366' AND `spell_effect`='48108' AND `type`='8';