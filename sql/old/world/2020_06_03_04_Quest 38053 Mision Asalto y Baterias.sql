-- Quest 38053 "Mision Asalto y Baterias"
-- DB: Nordrassil Databse 
-- Core: Legion 7.3.5
-- Author: MistiX (andy.gg@cubava.cu)
-- Date: 03.06.2020
-- Report http://10.96.2.10/bugtracker/view.php?id=286

/*Demasiados Spawn de esta msima creature este npc en ese lugar solo tiene que estar una sola ves*/
DELETE FROM `creature` WHERE `guid`='290783';
DELETE FROM `creature` WHERE `guid`='12817333';
DELETE FROM `creature` WHERE `guid`='365179';
DELETE FROM `creature` WHERE `guid`='12817332';

delete from `creature` where `guid` = '146730733';
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`)
 VALUES 
(

146730733, 90902, 1220, 7541, 7542, 1, 0, '10150', 0, 1, 3080.67, 2978.34, 433.073, 0.831433, 300, 0, 0, 2598168, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

);

delete from `conditions` where `ConditionValue1` = '38053';
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) 
VALUES 
(

23, 7541, 3, 0, 0, 9, 0, 38053, 0, 0, 0, 0, '', 'Quest Objetive Visibility'

);

delete from `phase_definitions` where `entry` = '640';
INSERT INTO `phase_definitions` (`zoneId`, `entry`, `phasemask`, `phaseId`, `PreloadMapID`, `VisibleMapID`, `UiWorldMapAreaID`, `flags`, `comment`)
VALUES 
(

7541, 640, 0, 10150, 0, 0, 0, 16, 'Quest 38053 Visibilidad Objetive Quest'

);
