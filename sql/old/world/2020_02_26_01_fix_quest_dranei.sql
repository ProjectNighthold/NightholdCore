/* quest obsoleta dranei*/
DELETE FROM `disables` WHERE `entry` = 26970;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES 
('1', '26970', '0', '', '', 'Deprecated Quest Dranei');