
-- Nassar SAI
UPDATE `creature_template` SET `gossip_menu_id`= 18861 WHERE `entry`= 114663;
SET @ENTRY := 114663;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,18861,0,0,0,75,193472,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nassar - On Gossip Option 0 Selected - Add Aura"),
(@ENTRY,0,1,0,62,0,100,0,18861,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nassar - On Gossip Option 0 Selected - Close Gossip");

DELETE FROM gossip_menu WHERE  `Entry` = 18861;
INSERT INTO `gossip_menu` (`Entry`,`TextId`,`FriendshipFactionID`) VALUES 
(18861,27614, 0); 
UPDATE `npc_text` SET `BroadcastTextID1`= 100714 WHERE `ID`= 27612;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`='99976' WHERE  `MenuID`= 18861;
UPDATE `gossip_menu_option` SET `OptionText`='I will fight alongside the Horde in battlegrounds, for now.' WHERE `MenuID`= 18861;

DELETE FROM npc_text WHERE `ID` = 27614;
INSERT INTO `npc_text` (`ID`,`Probability0`,`Probability1`,`Probability2`,`Probability3`,`Probability4`,`Probability5`,`Probability6`,`Probability7`,`BroadcastTextID0`,`BroadcastTextID1`,`BroadcastTextID2`,`BroadcastTextID3`,`BroadcastTextID4`,`BroadcastTextID5`,`BroadcastTextID6`,`BroadcastTextID7`,`VerifiedBuild`) VALUES 
('27614', '1', '0', '0', '0', '0', '0', '0', '0', '100714', '0', '0', '0', '0', '0', '0', '0', '1111'); 

-- Sergeant Wilson SAI
SET @ENTRY := 114665;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,18860,0,0,0,75,193475,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sergeant Wilson - On Gossip Option 0 Selected - Add Aura"),
(@ENTRY,0,1,0,62,0,100,0,18860,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sergeant Wilson - On Gossip Option 0 Selected - Close Gossip");
