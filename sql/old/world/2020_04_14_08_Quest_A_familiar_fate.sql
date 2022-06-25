-- A familiar Fate (QuestID: 40002)

/*Table_creature_text*/
DELETE FROM `creature_text` WHERE `Entry` = 97979;
INSERT INTO `creature_text`(`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES
(97979, 0, 0, '¡No...me...rendirè!', 12, 0, 0, 1, 0, 0, 0, 0, 0, 0, 'Talk-near of creature'),
(97979, 1, 0, '¡Al fin! parece que te debo otra vida camarada', 12, 0, 0, 1, 0, 0, 0, 0, 0, 0, 'Talk-near of creature');

/*Table_smart_Scripts*/
SET @Vethir := 97979;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@Vethir;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Vethir AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Vethir,0,0,0,19,0,100,0,40002,6,0,0,1,0,5000000,0,0,0,0,7,0,0,0,0,0,0,0,"Vethir-Select quest-Talk"),
(@Vethir,0,1,0,62,0,100,0,18828,0,0,0,1,1,7000,0,0,0,0,7,0,0,0,0,0,0,0,"Vethir - Gossip Select - Talk"),
(@Vethir,0,2,0,62,0,100,0,18828,0,0,0,33,97981,0,0,0,0,0,7,0,0,0,0,0,0,0,"Vethir - Gossip Select- Kill Monster"),
(@Vethir,0,3,0,62,0,100,0,18828,0,0,0,41,120000,0,0,0,0,0,14,20374233,244733,0,0,0,0,0,"Vethir-Gossip-Select-Despaw Prison");

/*Table_Creature_Template*/
UPDATE `creature_template` SET `gossip_menu_id` = 18828 WHERE `entry` = 97979;

/*Table_gossip_menu_option*/
DELETE FROM `gossip_menu_option` WHERE `MenuID` = 18828 AND `OptionIndex` = 0;
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionIndex`, `OptionNPC`, `OptionText`, `OptionType`, `OptionNpcflag`, `OptionNpcflag2`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxCurrency`, `BoxText`, `OptionBroadcastTextID`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES 
(18828, 0, 0, 'Use the Jailer\'s Shard to break Vethir\'s prison.',2, 2, 0, 0, 0, 0, 0, 0, '', 0, 0, 0);


/*Table_creature_loot_template*/
DELETE FROM `creature_loot_template` WHERE `entry` = 97890 AND `item` = 129106;
INSERT INTO `creature_loot_template`(`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES 
(97890, 129106, 100, 0, 0, 1, 1, 0);

