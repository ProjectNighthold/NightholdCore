DELETE FROM `gossip_menu_option` WHERE `MenuID`='1626';
DELETE FROM `gossip_menu_option` WHERE `MenuID`='5461';
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionNPC`, `OptionText`, `OptionType`, `OptionNpcflag`, `OptionNpcflag2`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxCurrency`, `BoxText`, `OptionBroadcastTextID`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
("1626", "0", "7", "How do I form a guild?", "10", "262144", "0", "0", "0", "0", "0", "0", "", "3413", "0", "0"),
("1626", "1", "8", "I want to create a guild crest.", "11", "524288", "0", "0",	"0", "0", "0", "0", "", "3415", "0", "0"),
("5461", "0", "7", "How do I form a guild?", "10", "262144", "0", "0", "0", "0", "0", "0", "", "3413", "0", "0"),
("5461", "1", "8", "I want to create a guild crest.", "11", "524288", "0", "0", "0", "0", "0", "0", "", "3415", "0", "0");