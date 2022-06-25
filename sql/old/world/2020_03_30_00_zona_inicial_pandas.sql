/* zona inicial pandas david arreglo del maestro y cambio de npcs y spawns*/

UPDATE `creature_queststarter` SET `id`='2000000'  WHERE  `quest`= '29408';
UPDATE `creature_queststarter` SET `id`='2000000'  WHERE  `quest`= '29409';
UPDATE `creature_queststarter` SET `id`='2000001'  WHERE  `quest`='29410';
UPDATE `creature_questender` SET `id`='2000000' WHERE  `quest`='29524';
UPDATE `creature_questender` SET `id`='2000000' WHERE  `quest`='29408';
UPDATE `creature_questender` SET `id`='2000001' WHERE  `quest`='29409';

DELETE FROM `creature` WHERE `guid` = 6700021 AND `id` =2000000;
DELETE FROM `creature` WHERE `guid` = 6700022 AND `id` =2000001;
INSERT INTO  `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) values
("6700021", "2000000", "860", "5736", "5834", "1", "1", "", "0", "0", "1445.55", "3384.66", "173.803", "4.39771", "120", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("6700022", "2000001", "860", "5736", "5843", "1", "1", "", "0", "0", "1379.79", "3216.92", "141.629", "4.47704", "120", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");

DELETE FROM `creature` WHERE `guid` = '243732';


SET @ENTRY := '2000001';
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,3,0,47,0,100,0,29410,0,0,0,41,2,0,0,0,0,0,0,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)");

