/* spawn de primeras misiones de llegada a pandarian horda */
DELETE FROM creature WHERE id IN (66190,66646,66667);
INSERT INTO creature (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES
("280297474", "66190", "870", "5785", "6522", "1", "1", "", "0", "0", "3183.51", "-700.946", "231.322", "1.69699", "300", "0", "0", "26268", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("280298454", "66646", "870", "5785", "6524", "1", "1", "", "0", "1", "3405.1", "-885.125", "295.783", "4.80871", "300", "0", "0", "26268", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"),
("280297471", "66667", "870", "5785", "6522", "1", "1", "", "0", "1", "3101.27", "-777.554", "282.511", "4.27918", "300", "0", "0", "21146", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");
