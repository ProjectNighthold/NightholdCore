-- Arreglado x PEGA-PEGA(WoW-Legion)
-- Expansion (Legion)
-- Misiones del DK 

-- La fortaleza nocturna: Alto botanista Tel arn(questid-43910)
-- La pesadilla esmeralda: la caida de cenarius(questid-43908)
-- La pesadilla esmeralda: Xavius(questid-43905)

DELETE FROM `creature_questender` WHERE `id`=97111 AND `quest`=43910;
DELETE FROM `creature_questender` WHERE `id`=97111 AND `quest`=43908;
DELETE FROM `creature_questender` WHERE `id`=97111 AND `quest`=43905;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES (97111, 43910);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES (97111, 43908);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES (97111, 43905);
