/* Estrellas resonantes (pasivo arma artefacto spell id 214508) */
DELETE FROM `areatrigger_actions` WHERE (`entry`='4756') AND (`customEntry`='9482') AND (`id`='4');

DELETE FROM `spell_script_names` WHERE `spell_id`='191037';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('191037', 'spell_dru_starfall_dmg');


