/* https://es.wowhead.com/quest=35970/capitalizaci%C3%B3n-de-la-preservaci%C3%B3n */
delete from `gameobject` where `guid` in (25675738,25675737,25675736);
insert into `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `AiID`, `state`, `isActive`, `personal_size`) values
("25675738", "233510", "1116", "6755", "7303", "1", "1", "", "3951.51", "7156.27", "78.254", "0.444443", "-0", "-0", "-0.220397", "-0.97541", "300", "0", "0", "1", "0", "0"),
("25675737", "233516", "1116", "6755", "7303", "1", "1", "", "4117.01", "7224.53", "94.2352", "1.03643", "-0", "-0", "-0.495332", "-0.868704", "300", "0", "0", "1", "0", "0"),
("25675736", "233554", "1116", "6755", "7303", "1", "1", "", "4213.06", "7283.02", "98.2483", "2.26558", "-0", "-0", "-0.9056", "-0.424133", "300", "0", "0", "1", "0", "0");

/*  npc spawn https://es.wowhead.com/quest=35970/capitalizaci%C3%B3n-de-la-preservaci%C3%B3n */
delete from `creature` where guid in (6700028);
insert into `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) values
("6700028", "83734", "1116", "6755", "7303", "1", "1", "", "0", "0", "3990.73", "7057.45", "67.1014", "0.343812", "300", "0", "0", "102486", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");

/* https://es.wowhead.com/npc=83750/posesi%C3%B3n-preciada-de-brokyo */
UPDATE `creature_template` SET `AIname`='SmartAI' WHERE `entry`=83750 LIMIT 1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=83750 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`id`,`link`,`event_type`,`event_phase_mask`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(83750, 0, 0, 0, 0, 0, 2500, 8000, 28000, 28000, 11, 177989, 2, 'Brokyo\'s Prized Possession  - On Combat - Cast Kill Credit - Nagrand 6.0:JP3 - Broken Precipice - Brokyo''s Prized Possession');

