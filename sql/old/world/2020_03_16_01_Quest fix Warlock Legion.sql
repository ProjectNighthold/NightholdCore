-- corazon del npc que hay que matar en la quest
DELETE FROM `creature_loot_template` WHERE `entry` = '101468';
INSERT INTO `creature_loot_template` (`entry`, `item`) VALUES ('101468', '132880');
UPDATE `creature_template` SET `lootid`='101468' WHERE (`entry`='101468');

DELETE FROM `quest_objectives` WHERE `ID` IN ('282106','282105','281139');


-- una traduccion en la tabla(ruso) y que el npc que da la quest invoque el demonio cuando la obtienes
UPDATE `gameobject_template` SET `name`='Cell bottom' WHERE (`entry`='245100');
UPDATE `gameobject_template` SET `name`='Cell walls' WHERE (`entry`='245347');


-- con esto hago que el npc no de misiones que no tocan en ese momento
UPDATE `quest_template_addon` SET `PrevQuestID`='40729' WHERE (`ID`='40731');
UPDATE `quest_template_addon` SET `NextQuestID`='40864' WHERE (`ID`='40731');


UPDATE `quest_template_addon` SET `PrevQuestID`='40731' WHERE (`ID`='40684');

-- añdiendo algunos npc al lugar
DELETE FROM `creature` WHERE `guid` IN (
'6700003',
'6700004',
'6700005',
'6700006',
'6700007',
'6700008',
'6700009',
'6700010');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
('6700003', '99397', '1522', '7918', '7918', '4096', '1', '', '0', '1', '3041.06', '972.101', '257.009', '5.28563', '300', '0', '0', '1247121', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'),
('6700004', '99397', '1522', '7918', '7918', '4096', '1', '', '0', '1', '3026.94', '969.155', '255.947', '4.91807', '300', '0', '0', '1247121', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'),
('6700005', '99397', '1522', '7918', '7918', '4096', '1', '', '0', '1', '3042.47', '1018.97', '265.071', '4.21749', '300', '0', '0', '1247121', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'),
('6700006', '99397', '1522', '7918', '7918', '4096', '1', '', '0', '1', '3054.18', '1012.64', '264.67', '4.21749', '300', '0', '0', '1247121', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'),
('6700007', '99397', '1522', '7918', '7918', '4096', '1', '', '0', '1', '3074.87', '1070.32', '276.795', '4.12166', '300', '0', '0', '1247121', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'),
('6700008', '99397', '1522', '7918', '7918', '4096', '1', '', '0', '1', '3087.96', '1061.54', '276.386', '4.12166', '300', '0', '0', '1247121', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'),
('6700009', '101751', '1522', '7918', '7918', '4096', '1', '', '0', '0', '3064.18', '1040.34', '270.279', '4.1256', '300', '0', '0', '1558901', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'),
('6700010', '101751', '1522', '7918', '7918', '4096', '1', '', '0', '0', '3104.35', '1105.46', '286.455', '4.11924', '300', '0', '0', '1558901', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');


