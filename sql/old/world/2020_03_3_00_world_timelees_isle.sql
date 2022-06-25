UPDATE `creature_template` SET `gossip_menu_id` = 15879 WHERE `entry` = 73343;
DELETE FROM `gossip_menu` WHERE `Entry` = 15879;
INSERT INTO `gossip_menu` (`Entry`, `TextId`, `FriendshipFactionID`) VALUES
(15879, 22858, 0);

UPDATE `creature_template` SET `gossip_menu_id` = 15832 WHERE `entry` = 73019;
DELETE FROM `gossip_menu` WHERE `Entry` = 15832;
INSERT INTO `gossip_menu` (`Entry`, `TextId`, `FriendshipFactionID`) VALUES
(15832, 22764, 0);

UPDATE `creature_template` SET `gossip_menu_id` = 15831 WHERE `entry` = 73016;
DELETE FROM `gossip_menu` WHERE `Entry` = 15831;
INSERT INTO `gossip_menu` (`Entry`, `TextId`, `FriendshipFactionID`) VALUES
(15831, 22763, 0);

UPDATE `creature_template` SET `gossip_menu_id` = 15829 WHERE `entry` = 73017;
DELETE FROM `gossip_menu` WHERE `Entry` = 15829;
INSERT INTO `gossip_menu` (`Entry`, `TextId`, `FriendshipFactionID`) VALUES
(15829, 22761, 0);

UPDATE `creature_template` SET `gossip_menu_id` = 15828 WHERE `entry` = 73020;
DELETE FROM `gossip_menu` WHERE `Entry` = 15828;
INSERT INTO `gossip_menu` (`Entry`, `TextId`, `FriendshipFactionID`) VALUES
(15828, 22760, 0);

UPDATE `creature_template` SET `gossip_menu_id` = 15884 WHERE `entry` = 73434;
DELETE FROM `gossip_menu` WHERE `Entry` = 15884;
INSERT INTO `gossip_menu` (`Entry`, `TextId`, `FriendshipFactionID`) VALUES
(15884, 22876, 0);

UPDATE `creature_template` SET `gossip_menu_id` = 15883 WHERE `entry` = 73433;
DELETE FROM `gossip_menu` WHERE `Entry` = 15883;
INSERT INTO `gossip_menu` (`Entry`, `TextId`, `FriendshipFactionID`) VALUES
(15883, 23009, 0);

UPDATE `creature_template` SET `gossip_menu_id` = 15993 WHERE `entry` = 73820;
DELETE FROM `gossip_menu` WHERE `Entry` = 15993;
INSERT INTO `gossip_menu` (`Entry`, `TextId`, `FriendshipFactionID`) VALUES
(15993, 23044, 0);

UPDATE `creature_template` SET `gossip_menu_id` = 15827 WHERE `entry` = 72994;
DELETE FROM `gossip_menu` WHERE `Entry` = 15827;
INSERT INTO `gossip_menu` (`Entry`, `TextId`, `FriendshipFactionID`) VALUES
(15827, 22759, 0);


DELETE FROM `smart_scripts` WHERE `entryorguid` IN (72045, 73161, 72765, 72764, 72763) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (73361, 73362, 71940, 71939, 73343) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (73163, 72841) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (73160, 72842, 72843, 72844) AND `source_type` = 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (72777, 72775) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(72045, 0, 0, 0, 0, 0, 100, 0, 5000, 8000, 12000, 15000, 11, 147572, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Chelon - In Combat - Cast Spell 'Geyser'"),
(72045, 0, 1, 0, 9, 0, 100, 0, 0, 8, 15000, 25000, 11, 147571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chelon - On Close < 8 Yard - Cast Spell 'Shell Spin'"),
(72045, 0, 2, 0, 2, 0, 100, 0, 0, 40, 22000, 25000, 11, 147569, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chelon - 0-40% HP - Cast 'Snapping Bite'"),
(73161, 0, 0, 0, 0, 0, 100, 0, 5000, 8000, 12000, 15000, 11, 147572, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Great Turtle Furyshell - In Combat - Cast Spell 'Geyser'"),
(73161, 0, 1, 0, 9, 0, 100, 0, 0, 8, 15000, 25000, 11, 147571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Great Turtle Furyshell - On Close < 8 Yard - Cast Spell 'Shell Spin'"),
(72765, 0, 0, 0, 0, 0, 100, 0, 5000, 8000, 12000, 15000, 11, 147573, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Elder Great Turtle - In Combat - Cast Spell 'Geyser'"),
(72764, 0, 0, 0, 2, 0, 100, 0, 0, 40, 22000, 25000, 11, 147568, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Great Turtle - 0-40% HP - Cast Spell 'Snapping Bite'"),
(72764, 0, 1, 0, 9, 0, 100, 0, 0, 8, 15000, 25000, 11, 147571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Great Turtle - On Close < 8 Yards - Cast Spell 'Shell Spin'"),
(72763, 0, 0, 0, 2, 0, 100, 0, 0, 40, 22000, 25000, 11, 147568, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Great Turtle Hatchling - 0-40% HP - Cast Spell 'Snapping Bite'"),

(73361, 0, 0, 0, 0, 0, 100, 0, 5000, 8000, 12000, 15000, 11, 19643, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Tushui Sentry - In Combat - Cast Spell 'Mortal Strike'"),
(73361, 0, 1, 0, 9, 0, 100, 0, 0, 20, 15000, 25000, 11, 81210, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Tushui Sentry - On Close < 20 Yards - Cast Spell 'Net'"),
(73361, 0, 2, 0, 13, 0, 100, 0, 12000, 15000, 0, 0, 11, 15618, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Tushui Sentry - On Target Casting - Cast Spell 'Snap Kick'"),
(73362, 0, 0, 0, 0, 0, 100, 0, 5000, 8000, 12000, 15000, 11, 19643, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Huojin Sentry - In Combat - Cast Spell 'Mortal Strike'"),
(73362, 0, 1, 0, 9, 0, 100, 0, 0, 20, 15000, 25000, 11, 81210, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Huojin Sentry - On Close < 20 Yards - Cast Spell 'Net'"),
(73362, 0, 2, 0, 13, 0, 100, 0, 12000, 15000, 0, 0, 11, 15618, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Huojin Sentry - On Target Casting - Cast Spell 'Snap Kick'"),
(71940, 0, 0, 0, 9, 0, 100, 0, 0, 20, 15000, 25000, 11, 81210, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Michi Windblossom - On Close < 20 Yards - Cast Spell 'Net'"),
(71939, 0, 0, 0, 0, 0, 100, 0, 5000, 8000, 12000, 15000, 11, 19643, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Chi-Ro the Skytamer - In Combat - Cast Spell 'Mortal Strike'"),
(71939, 0, 1, 0, 9, 0, 100, 0, 0, 20, 15000, 25000, 11, 81210, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Chi-Ro the Skytamer - On Close < 20 Yards - Cast Spell 'Net'"),
(73343, 0, 0, 0, 0, 0, 100, 0, 5000, 8000, 12000, 15000, 11, 19643, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Celestial Guard - In Combat - Cast Spell 'Mortal Strike'"),
(73343, 0, 1, 0, 9, 0, 100, 0, 0, 20, 15000, 25000, 11, 81210, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Celestial Guard - On Close < 20 Yards - Cast Spell 'Net'"),
(73343, 0, 2, 0, 13, 0, 100, 0, 12000, 15000, 0, 0, 11, 15618, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Celestial Guard - On Target Casting - Cast Spell 'Snap Kick'"),

(73163, 0, 0, 0, 0, 0, 100, 0, 5000, 8000, 12000, 15000, 11, 147290, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Imperial Python - In Combat - Cast Spell 'Huge Fang'"),
(72841, 0, 0, 0, 0, 0, 100, 0, 5000, 8000, 12000, 15000, 11, 147289, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Death Adder - In Combat - Cast Spell 'Huge Fang'"),

(73160, 0, 0, 0, 2, 0, 100, 1, 0, 30, 0, 0, 11, 147368, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ironfur Steelhorn - 0-30% HP - Cast Spell 'Iron Fur'"),
(72842, 0, 0, 0, 0, 0, 100, 0, 5000, 8000, 12000, 15000, 11, 147354, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ironfur Herdling - In Combat - Cast Spell 'Headbutt'"),
(72843, 0, 0, 0, 0, 0, 100, 0, 5000, 8000, 12000, 15000, 11, 147382, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ironfur Grazer - In Combat - Cast Spell 'Headbutt'"),
(72843, 0, 1, 0, 2, 0, 100, 1, 0, 30, 0, 0, 11, 147368, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ironfur Grazer - 0-30% HP - Cast Spell 'Iron Fur'"),
(72844, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 147386, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ironfur Great Bull - On Aggro - Cast Spell 'Ox Charge'"),
(72844, 0, 1, 0, 2, 0, 100, 1, 0, 30, 0, 0, 11, 147368, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ironfur Great Bull - 0-30% HP - Cast Spell 'Iron Fur'"),

(72777, 0, 0, 0, 0, 0, 100, 0, 5000, 8000, 12000, 15000, 11, 147655, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Gulp Frog - In Combat - Cast Spell 'Gulp Frog Toxin'"),
(72777, 0, 1, 0, 2, 0, 100, 0, 0, 40, 15000, 15000, 11, 147654, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gulp Frog - 0-40% HP - Cast Spell 'Toxic Skin'"),
(72775, 0, 0, 0, 0, 0, 100, 0, 5000, 8000, 12000, 15000, 11, 147655, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Bufo - In Combat - Cast Spell 'Gulp Frog Toxin'"),
(72775, 0, 1, 0, 2, 0, 100, 0, 0, 40, 15000, 15000, 11, 147654, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bufo - 0-40% HP - Cast Spell 'Toxic Skin'");
