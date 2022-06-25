-- Arreglado x PEGA-PEGA(WoW-Legion)
-- Expansion (Legion)
-- Pociones de aumento de exp

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=146939;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=189375;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 146939, 0, 0, 27, 0, 100, 2, 0, 0, 86,"", "Item Ancient Knowledge"),
(17, 0, 189375, 0, 0, 27, 0, 100, 2, 0, 0, 86,"", "Item Ancient Knowledge");
