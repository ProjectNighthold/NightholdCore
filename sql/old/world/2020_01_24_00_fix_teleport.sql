/*INSERTANDO TELEPORT NO EXISTENTES*/
DELETE FROM `game_tele` WHERE `id` IN (
'3000',
'3001',
'3002');

INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES 
('3000', '0.902778', '5765.17', '3.36364', '1.57663', '1220', 'Eyeofazshara'),
('3001', '-1821.23', '6655.28', '147.37', '1.27657', '1220', 'Bovedaceladora'),
('3002', '2734.52', '-1012.13', '457.565', '6.00253', '870', 'pandaria');

