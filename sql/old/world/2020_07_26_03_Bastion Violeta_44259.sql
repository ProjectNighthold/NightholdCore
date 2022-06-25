-- Arreglado x PEGA-PEGA(WoW-Legion)
-- Expansion (Legion)
-- [Ataque al Bastión Violeta: Hacia el Bastión Violeta] Quest-id: 44259 

DELETE FROM `creature_questender` WHERE `id`=100635 AND `quest`=44259;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES (100635, 44259);
