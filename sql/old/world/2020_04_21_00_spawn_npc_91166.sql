/* npc spawn https://es.wowhead.com/npc=91166/daglop */
delete from `creature` where `guid` in (6700029);
insert into `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) values
("6700029", "91166", "1220", "7334", "7571", "1", "1", "", "0", "0", "-438.239", "5701.3", "36.1313", "1.95369", "300", "0", "0", "831414", "1100000", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");
