UPDATE `creature_template` SET `minlevel`='100', `maxlevel`='100' WHERE (`entry`='99875');
UPDATE `creature_template` SET `minlevel`='100', `maxlevel`='100' WHERE (`entry`='100346');
UPDATE `creature_template` SET `minlevel`='100', `maxlevel`='100' WHERE (`entry`='100704');
UPDATE `creature_template` SET `minlevel`='100', `maxlevel`='100' WHERE (`entry`='100708');
UPDATE `creature_template` SET `minlevel`='100', `maxlevel`='100' WHERE (`entry`='100707');
UPDATE `creature_template` SET `minlevel`='100', `maxlevel`='100' WHERE (`entry`='100735');

-- altar de los brujo
UPDATE `gameobject_template` SET `name`='Felblood Altar' WHERE (`entry`='245004');
DELETE FROM `gameobject` where (`id` = '245004');
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `AiID`, `state`, `isActive`, `personal_size`) VALUES ('25666439', '245004', '1107', '7875', '7875', '1', '1', '', '3133.47', '1131.35', '286.626', '4.0795', '-0', '-0', '-0.892041', '0.451954', '300', '0', '0', '1', '0', '0');
