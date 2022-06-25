-- limpiando valores incorrectos de condiciones
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 23 AND `SourceGroup` = 7502 AND `SourceEntry` = 12 AND `ConditionTypeOrReference` = 9;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 23 AND `SourceGroup` = 7502 AND `SourceEntry` = 12 AND `ConditionTypeOrReference` = 8;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 23 AND `SourceGroup` = 7502 AND `SourceEntry` = 12 AND `ConditionTypeOrReference` = 28;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 23 AND `SourceGroup` = 7502 AND `SourceEntry` = 13 AND `ConditionTypeOrReference` = 9;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 23 AND `SourceGroup` = 7502 AND `SourceEntry` = 13 AND `ConditionTypeOrReference` = 8;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 23 AND `SourceGroup` = 7502 AND `SourceEntry` = 13 AND `ConditionTypeOrReference` = 28;

-- creando valores correctos de condiciones
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
('23', '7502', '12', '0', '0', '9', '0', '41966', '0', '0', '0', '0', '', 'Activate Phase - If Player Has Quest'),
('23', '7502', '12', '0', '1', '8', '0', '41966', '0', '0', '0', '0', '', 'Activate Phase - If Player Reward Quest'),
('23', '7502', '12', '0', '2', '28', '0', '41966', '0', '0', '0', '0', '', 'Activate Phase - If Player Complete Quest'),
('23', '7502', '13', '0', '0', '9', '0', '41966', '0', '0', '0', '0', '', 'Activate Phase - If Player Has Quest'),
('23', '7502', '13', '0', '1', '8', '0', '41966', '0', '0', '0', '0', '', 'Activate Phase - If Player Reward Quest'),
('23', '7502', '13', '0', '2', '28', '0', '41966', '0', '0', '0', '0', '', 'Activate Phase - If Player Complete Quest');

-- esto es para que tenga el gossip de la mision, para entregarla y se le pueda castear spells al npc
UPDATE `creature_template` SET `npcflag`='131' WHERE (`entry`='105603');
UPDATE `creature_template` SET `unit_flags`='32840' WHERE (`entry`='105603');

DELETE FROM `creature_template_addon` WHERE `entry` = 105603;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
('105603', '0', '0', '0', '0', '0', NULL);

DELETE FROM `smart_scripts` WHERE (`entryorguid`='105603');
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
('105603', '0', '0', '0', '19', '0', '100', '0', '41967', '0', '0', '0', '45', '2', '2', '0', '0', '0', '0', '19', '105602', '5', '0', '0', '0', '0', '0', 'Quest Accept - Send Data'),
('105603', '0', '1', '0', '53', '0', '100', '0', '1', '5000000', '0', '0', '33', '105586', '0', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', 'Kill credit to complete the quest');
