-- quest update In the Blink of an Eye y final de arma Holy
-- como encontre diferencias entre la de la Ali y la Horda las voy a igualar
UPDATE `quest_template` SET `RewardMoney`='40500' WHERE (`ID`='44184');
UPDATE `quest_template` SET `RewardItem2`='141446', `RewardAmount2`='5' WHERE (`ID`='44184');
-- arreglando mision 41957 que el npc no entra en phase al obtener la mision, al parecer la sourceEntry 13 tambien es necesaria para esto, solo tenia la 12, ni idea de porque
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 23 AND `SourceGroup`= '7502' AND `ElseGroup` = '1' AND `ConditionTypeOrReference` = 8 AND `ConditionValue1` = '41957';
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 23 AND `SourceGroup`= '7502' AND `ElseGroup` = '0' AND `ConditionTypeOrReference` = 9  AND `ConditionValue1` = '41957';
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 23 AND `SourceGroup`= '7502' AND `ElseGroup` = '2' AND `ConditionTypeOrReference` = 28 AND `ConditionValue1` = '41957';

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
('23', '7502', '13', '0', '0', '9', '0', '41957', '0', '0', '0', '0', '', 'Activate Phase - If Player Has Quest'),
('23', '7502', '13', '0', '1', '8', '0', '41957', '0', '0', '0', '0', '', 'Activate Phase - If Player Reward Quest'),
('23', '7502', '13', '0', '2', '28', '0', '41957', '0', '0', '0', '0', '', 'Activate Phase - If Player Complete Quest');
