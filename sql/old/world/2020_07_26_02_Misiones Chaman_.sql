-- Arreglado x PEGA-PEGA(WoW-Legion)
-- Expansion (Legion)
-- Misiones del Chaman

-- Corte de las estrellas : haica la corte de las estrellas(QuestID:44275)
-- Mas avances(QuestID-46781)

DELETE FROM `creature_questender` WHERE `id`=112199 AND `quest`=46781;
DELETE FROM `creature_questender` WHERE `id`=96746 AND `quest`=44275;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES (112199, 46781);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES (96746, 44275);
