-- Oro y Sangre Questid 39595 

/*Table_creature_loot_template*/
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = 50 WHERE `Entry` = 108289 AND `Item` = 128511;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = 100 WHERE `Entry` = 108289 AND `Item` = 128512;

DELETE FROM `creature_loot_template` WHERE `Item` = 128512;
INSERT INTO `creature_loot_template`(`Entry`, `Item`, `ChanceOrQuestChance`,  `LootMode`, `GroupId`, `mincountOrRef`, `MaxCount`, `shared`) VALUES 
(96129, 128512, 100, 1, 0, 1, 1, 0),
(96229, 128512, 100, 1, 0, 1, 1, 0),
(96236, 128512, 100, 1, 0, 1, 1, 0),
(100433, 128512, 100, 1, 0, 1, 1, 0),
(100435, 128512, 100, 1, 0, 1, 1, 0),
(108283, 128512, 100, 1, 0, 1, 1, 0),
(108289, 128512, 100, 1, 0, 1, 1, 0),
(108306, 128512, 100, 1, 0, 1, 1, 0),
(108309, 128512, 100, 1, 0, 1, 1, 0);

DELETE FROM `creature_loot_template` WHERE `Item` = 128511;
INSERT INTO `creature_loot_template`(`Entry`, `Item`, `ChanceOrQuestChance`,  `LootMode`, `GroupId`, `mincountOrRef`, `MaxCount`, `shared`) VALUES 
(96129, 128511, 28, 1, 0, 1, 1, 0),
(96229, 128511, 49, 1, 0, 1, 1, 0),
(96236, 128511, 44, 1, 0, 1, 1, 0),
(100433, 128511, 56, 1, 0, 1, 1, 0),
(100435, 128511, 52, 1, 0, 1, 1, 0),
(108283, 128511, 41, 1, 0, 1, 1, 0),
(108289, 128511, 50, 1, 0, 1, 1, 0),
(108306, 128511, 45, 1, 0, 1, 1, 0),
(108309, 128511, 42, 1, 0, 1, 1, 0);

/*Table_smart_scripst*/
SET @Duelista := 240026; -- Gobject Duelista Totem de Sangre
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@Duelista;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Duelista AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Duelista,0,0,0,62,0,100,0,44047,0,0,0,56,128512,1,0,0,0,0,7,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)");


/*Table_gossip_menu*/
DELETE FROM `gossip_menu` WHERE `Entry`= 44047;
INSERT INTO `gossip_menu`(`Entry`, `TextId`, `FriendshipFactionID`) VALUES (44047, 0, 0);

/*Table_gossip_menu_option*/
DELETE FROM `gossip_menu_option` WHERE `MenuID`= 44047;
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionIndex`, `OptionNPC`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(44047, 0, 0, '¿Oro y Sangre?', 0, 1, 1, 19865);
