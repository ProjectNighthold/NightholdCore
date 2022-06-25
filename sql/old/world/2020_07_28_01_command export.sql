DELETE FROM `command`  WHERE `name` = 'export';
DELETE FROM `command`  WHERE `name` = 'export go';
DELETE FROM `command`  WHERE `name` = 'export creature';
DELETE FROM `command`  WHERE `name` = 'export quest';
DELETE FROM `command`  WHERE `name` = 'export position';

INSERT INTO `command` (`name`, `security`, `help`) VALUES 
('export', '6', 'Syntax: .export $subcommand\nType .export to see the list of possible subcommands or .help export $subcommand to see info on subcommands'),
('export go', '6', 'Syntax: .export go #gobjectID\r\n\r\nExport information of the gobject to sql file'),
('export creature', '6', 'Syntax: .export creature #creatureID\r\n\r\nExport information of the creature to sql file'),
('export quest', '6', 'Syntax: .export quest #questID\r\n\r\nExport information of the quest to sql file'),
('export position', '6', 'Syntax: .export position Export the player position to sql file');
