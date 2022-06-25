-- changed portal --
delete from `gameobject` where `guid` in( 110202, 6760000);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `AiID`, `state`, `isActive`, `personal_size`) VALUES 
('6760000', '192786', '1220', '7502', '8045', '1', '1', '', '-894.78', '4493.35', '580.459', '0.324209', '-0', '-0', '-0.161395', '-0.98689', '300', '0', '0', '1', '0', '0');
