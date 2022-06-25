/* https://www.wowhead.com/quest=25272/lycanthoth-the-corruptor  */
delete from creature where guid= 280227561;
insert into creature (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) values
("280227561", "39622", "1", "616", "4980", "1", "1", "", "0", "0", "5143.99", "-2302.21", "1278.46", "0.722994", "300", "0", "0", "87", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");
