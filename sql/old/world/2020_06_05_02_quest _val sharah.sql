-- Tanke 007 everything is blizzlike

-- Quest order correction
DELETE FROM `quest_template_addon` WHERE `ID`=39149;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES (39149, 0, 0, 0, 0, 38645, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);
DELETE FROM `quest_template_addon` WHERE `ID`=38644;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES (38644, 0, 0, 0, 39149, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);
DELETE FROM `quest_template_addon` WHERE `ID`=38645;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES (38645, 0, 0, 0, 39149, 38691, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);
DELETE FROM `quest_template_addon` WHERE `ID`=38646;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES (38646, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 1, 0);
DELETE FROM `quest_template_addon` WHERE `ID`=38647;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES (38647, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);
DELETE FROM `quest_template_addon` WHERE `ID`=39117;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES (39117, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);
DELETE FROM `quest_template_addon` WHERE `ID`=38691;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES (38691, 0, 0, 0, 38645, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);
DELETE FROM `quest_template_addon` WHERE `ID`=38714;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES (38714, 0, 0, 0, 38718, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);
DELETE FROM `quest_template_addon` WHERE `ID`=38715;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES (38715, 0, 0, 0, 38718, 38717, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);
DELETE FROM `quest_template_addon` WHERE `ID`=38724;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES (38724, 0, 0, 0, 38717, 38721, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=38717;

-- npc 92688 repeated the quest with different id
DELETE FROM `creature_queststarter` WHERE `id`=92688 AND `quest`=38643;

DELETE FROM `quest_template` WHERE `ID`=38691;
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestLevel`, `QuestMaxScalingLevel`, `QuestPackageID`, `MinLevel`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `RewardArtifactXP`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `StartItem`, `Flags`, `FlagsEx`, `RewardItem1`, `RewardAmount1`, `RewardItem2`, `RewardAmount2`, `RewardItem3`, `RewardAmount3`, `RewardItem4`, `RewardAmount4`, `ItemDrop1`, `ItemDropQuantity1`, `ItemDrop2`, `ItemDropQuantity2`, `ItemDrop3`, `ItemDropQuantity3`, `ItemDrop4`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemQuantity1`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemID2`, `RewardChoiceItemQuantity2`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemID3`, `RewardChoiceItemQuantity3`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemID4`, `RewardChoiceItemQuantity4`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemID5`, `RewardChoiceItemQuantity5`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitTurnIn`, `RewardFactionID1`, `RewardFactionValue1`, `RewardFactionOverride1`, `FactionCapIn1`, `RewardFactionID2`, `RewardFactionValue2`, `RewardFactionOverride2`, `FactionCapIn2`, `RewardFactionID3`, `RewardFactionValue3`, `RewardFactionOverride3`, `FactionCapIn3`, `RewardFactionID4`, `RewardFactionValue4`, `RewardFactionOverride4`, `FactionCapIn4`, `RewardFactionID5`, `RewardFactionValue5`, `RewardFactionOverride5`, `FactionCapIn5`, `RewardFactionFlags`, `RewardCurrencyID1`, `RewardCurrencyQty1`, `RewardCurrencyID2`, `RewardCurrencyQty2`, `RewardCurrencyID3`, `RewardCurrencyQty3`, `RewardCurrencyID4`, `RewardCurrencyQty4`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `QuestRewardID`, `Expansion`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `StartScript`, `CompleteScript`, `VerifiedBuild`) VALUES (38691, 2, -1, 255, 0, 98, 7558, 0, 0, 38718, 1, 1, 15400, 1, 1, 18350, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 37748744, 8192, 141388, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1883, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 890, 878, 0, 0, 18446744073709551615, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 21737);
DELETE FROM `quest_template` WHERE `ID`=38721;
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestLevel`, `QuestMaxScalingLevel`, `QuestPackageID`, `MinLevel`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `RewardArtifactXP`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `StartItem`, `Flags`, `FlagsEx`, `RewardItem1`, `RewardAmount1`, `RewardItem2`, `RewardAmount2`, `RewardItem3`, `RewardAmount3`, `RewardItem4`, `RewardAmount4`, `ItemDrop1`, `ItemDropQuantity1`, `ItemDrop2`, `ItemDropQuantity2`, `ItemDrop3`, `ItemDropQuantity3`, `ItemDrop4`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemQuantity1`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemID2`, `RewardChoiceItemQuantity2`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemID3`, `RewardChoiceItemQuantity3`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemID4`, `RewardChoiceItemQuantity4`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemID5`, `RewardChoiceItemQuantity5`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitTurnIn`, `RewardFactionID1`, `RewardFactionValue1`, `RewardFactionOverride1`, `FactionCapIn1`, `RewardFactionID2`, `RewardFactionValue2`, `RewardFactionOverride2`, `FactionCapIn2`, `RewardFactionID3`, `RewardFactionValue3`, `RewardFactionOverride3`, `FactionCapIn3`, `RewardFactionID4`, `RewardFactionValue4`, `RewardFactionOverride4`, `FactionCapIn4`, `RewardFactionID5`, `RewardFactionValue5`, `RewardFactionOverride5`, `FactionCapIn5`, `RewardFactionFlags`, `RewardCurrencyID1`, `RewardCurrencyQty1`, `RewardCurrencyID2`, `RewardCurrencyQty2`, `RewardCurrencyID3`, `RewardCurrencyQty3`, `RewardCurrencyID4`, `RewardCurrencyQty4`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `QuestRewardID`, `Expansion`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `StartScript`, `CompleteScript`, `VerifiedBuild`) VALUES (38721, 2, -1, 255, 9686, 98, 7558, 0, 0, 0, 5, 1, 154000, 5, 1, 182850, 0, 0, 0, 189256, 0, 0, 0, 1, 0, 0, 175112200, 8192, 141389, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64214, 0, 1883, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 890, 878, 0, 0, 18446744073709551615, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 21737);

-- condition for npc 94977
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=94977;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 94977, 0, 0, 9, 0, 38718, 0, 0, 0, 0, '', 'Only Run script if quest is taken');

DELETE FROM `gameobject_template` WHERE `entry`=243089;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `unkInt32`, `AIName`, `ScriptName`, `WorldEffectID`, `StateWorldEffectID`, `SpellVisualID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `MaxVisible`, `IgnoreDynLos`, `MinGold`, `MaxGold`, `VerifiedBuild`) VALUES 
(243089, 10, 35708, 'Sigilo de Kur\'talos Cresta Cuervo', 'questinteract', 'Reading', '', 0, 262144, 0.75, 0, 0, 0, 0, 0, 0, 1690, 0, 0, 10000, 0, 0, 0, 0, 0, 0, 187307, 0, 0, 0, 24589, 0, 0, 0, 0, 0, 0, 0, 34505, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21108);

--  SAI
SET @ENTRY := 92842;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,38717,0,0,0,1,5,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)"),
(@ENTRY,0,1,0,52,0,100,0,5,92842,0,0,53,1,9284201,0,38717,0,0,1,0,0,0,0,0,0,0,"<Could not generate name> - On Text 1 Over - Say Line 2"),
(@ENTRY,0,2,0,58,0,100,0,4,0,0,0,43,110665,0,0,0,0,0,1,0,0,0,0,0,0,0,"<Could not generate name> - On Text 1 Over - Say Line 2"),
(@ENTRY,0,3,0,58,0,100,0,4,0,0,0,1,6,3000,0,0,0,0,1,0,0,0,0,0,0,0,"<Could not generate name> - On Text 1 Over - Say Line 2"),
(@ENTRY,0,5,0,52,0,100,0,6,92842,0,0,53,1,9284202,0,0,0,0,1,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)"),
(@ENTRY,0,6,0,58,0,100,0,3,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)"),
(@ENTRY,0,7,0,25,0,100,0,0,0,0,0,43,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)");

--  SAI 
SET @ENTRY := -296387;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,60,0,100,0,1000,1000,1000,1000,33,92620,0,0,0,0,0,18,10,0,0,0,0,0,0,"on range credit"),
(@ENTRY,0,1,0,10,0,100,0,1,6,25000,25000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on range s0"),
(@ENTRY,0,2,0,19,0,100,0,38718,0,0,0,1,1,8000,0,0,0,0,1,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)"),
(@ENTRY,0,3,0,52,0,100,0,1,92842,0,0,53,0,928420,0,38718,0,0,0,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)"),
(@ENTRY,0,4,0,39,0,100,0,0,0,0,0,1,2,8000,0,0,0,0,1,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)"),
(@ENTRY,0,5,0,52,0,100,0,2,92842,0,0,1,3,8000,0,0,0,0,1,0,0,0,0,0,0,0,"<Could not generate name> - On Text 0 Over - Say Line 1"),
(@ENTRY,0,6,0,52,0,100,0,3,92842,0,0,1,4,8000,0,0,0,0,1,0,0,0,0,0,0,0,"<Could not generate name> - On Text 1 Over - Say Line 2"),
(@ENTRY,0,7,0,52,0,100,0,4,92842,0,0,41,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"<Could not generate name> - On Text 1 Over - Say Line 2");

DELETE FROM `creature` WHERE `guid`=296457;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES (296457, 92842, 1220, 7558, 7780, 1, 1, '5573 5542 5506 5354 5353 5352 5351 5131 4993 4986 4977 4926 4905 4771 4713 4712 4648 4619 4571 4570', 0, 0, 3117.56, 7191.45, 53.641, 2.47498, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
DELETE FROM `creature` WHERE `guid`=303776;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES (303776, 85809, 1116, 6721, 6893, 1, 1, '0', 0, 0, 6727.17, 44.3501, 74.2595, 0.692842, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `smart_scripts` WHERE `entryorguid`=243089;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(243089, 1, 0, 0, 64, 0, 100, 0, 0, 0, 0, 0, 33, 243089, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Sigilo de Kur\'talos Cresta Cuervo'),
(243089, 1, 2, 0, 64, 0, 100, 0, 0, 0, 0, 0, 85, 188412, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `creature` WHERE `guid`=296455;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES (296455, 92419, 1220, 7558, 7661, 1, 1, '', 0, 0, 3256.92, 7281.3, 90.8525, 3.9414, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
--  waypoints
DELETE FROM `waypoints` WHERE `entry`=928420 AND `pointid`=1;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES (928420, 1, 3017.6, 7361.86, 35.2368, 'despawn');

DELETE FROM `waypoints` WHERE `entry`=9284201 AND `pointid`=1;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES (9284201, 1, 3118.27, 7147.65, 64.6505, NULL);
DELETE FROM `waypoints` WHERE `entry`=9284201 AND `pointid`=2;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES (9284201, 2, 3080.65, 7149.38, 75.867, NULL);
DELETE FROM `waypoints` WHERE `entry`=9284201 AND `pointid`=3;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES (9284201, 3, 3044.23, 7163.11, 89.994, NULL);
DELETE FROM `waypoints` WHERE `entry`=9284201 AND `pointid`=4;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES (9284201, 4, 3044, 7166.43, 89.9933, 'pause');

DELETE FROM `waypoints` WHERE `entry`=9284202 AND `pointid`=1;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES (9284202, 1, 3052.79, 7168.4, 89.9933, '');
DELETE FROM `waypoints` WHERE `entry`=9284202 AND `pointid`=2;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES (9284202, 2, 3096.12, 7164.03, 90.1495, '');
DELETE FROM `waypoints` WHERE `entry`=9284202 AND `pointid`=3;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES (9284202, 3, 3186.64, 7175.8, 89.9935, '');

DELETE FROM `creature_questender` WHERE `id`=94977 AND `quest`=38718;
DELETE FROM `creature_questender` WHERE `id`=92842 AND `quest`=38718;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES (92842, 38718);

DELETE FROM `creature_queststarter` WHERE `id`=92842 AND `quest`=38714;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES (92842, 38714);
DELETE FROM `creature_queststarter` WHERE `id`=92842 AND `quest`=38715;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES (92842, 38715);


DELETE FROM `gameobject` WHERE `guid`=114096;
DELETE FROM `gameobject` WHERE `guid`=127498;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `AiID`, `state`, `isActive`, `personal_size`) VALUES 
(127498, 243089, 1220, 7558, 7661, 1, 1, '0', 3017.69, 7348.68, 38.2173, 1.56945, 0, 0, 0, 1, 180, 255, 0, 1, 0, 0);

DELETE FROM `gameobject_template` WHERE `entry`=243089;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `unkInt32`, `AIName`, `ScriptName`, `WorldEffectID`, `StateWorldEffectID`, `SpellVisualID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `MaxVisible`, `IgnoreDynLos`, `MinGold`, `MaxGold`, `VerifiedBuild`) VALUES (243089, 10, 35708, 'Sigilo de Kur\'talos Cresta Cuervo', 'questinteract', 'Reading', '', 0, 262144, 0.75, 0, 0, 0, 0, 0, 0, 1690, 0, 0, 10000, 0, 0, 0, 0, 0, 0, 187307, 0, 0, 0, 24589, 0, 0, 0, 0, 0, 0, 0, 34505, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartGameObjectAI', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21108);


DELETE FROM `quest_objectives` WHERE `ID`=278327;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES 
(278327, 38718, 2, 2, 243089, 1, 0, 0, 0, NULL, 21737);


DELETE FROM `creature` WHERE `guid`=296509;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES (296509, 92966, 1220, 7558, 7661, 1, 1, '', 0, 0, 3070.38, 7244.31, 52.8076, 3.12523, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
DELETE FROM `creature` WHERE `guid`=286833;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES (286833, 94975, 1220, 7558, 7675, 1, 1, '', 0, 0, 3388.45, 7422.76, 16.8909, 0.357393, 180, 3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- npc duplicates delete
DELETE FROM `creature` WHERE `guid`=296382;
DELETE FROM `creature` WHERE `guid`=296528;
DELETE FROM `creature` WHERE `guid`=296514;
DELETE FROM `creature` WHERE `guid`=296433;
DELETE FROM `creature` WHERE `guid`=286749;
DELETE FROM `creature` WHERE `guid`=296517;
DELETE FROM `creature` WHERE `guid`=296522;
DELETE FROM `creature` WHERE `guid`=288395;
DELETE FROM `creature` WHERE `guid`=285975;
DELETE FROM `creature` WHERE `guid`=286837;


DELETE FROM `quest_objectives` WHERE `ID`=278322;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES 
(278322, 38717, 1, 0, 127863, 1, 0, 0, 0, 'Llave de la prisión', 21737);

DELETE FROM `quest_objectives_locale` WHERE `ID`=278322 AND `locale`='esMX';
INSERT INTO `quest_objectives_locale` (`ID`, `locale`, `QuestId`, `StorageIndex`, `Description`, `VerifiedBuild`) VALUES 
(278322, 'esMX', 38717, 0, 'Llaves de la prisión', 26124);

-- Sirius Ebonwing SAI
SET @ENTRY := 94974;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,18574,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sirius Ebonwing - On Gossip Option 0 Selected - Set Faction 14"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sirius Ebonwing - On Gossip Option 0 Selected - Set Faction 14"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,226681,5,0,0,0,0,7,0,0,0,0,0,0,0,"Sirius Ebonwing - On Gossip Option 0 Selected - Set Faction 14"),
(@ENTRY,0,3,0,4,0,100,0,0,0,0,0,1,0,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Sirius Ebonwing - On Gossip Option 0 Selected - Set Faction 14"),
(@ENTRY,0,4,0,0,0,100,0,5000,5000,10000,10000,11,189747,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sirius Ebonwing - On Gossip Option 0 Selected - Set Faction 14"),
(@ENTRY,0,5,0,6,0,100,0,0,0,0,0,1,2,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Sirius Ebonwing - On Gossip Option 0 Selected - Set Faction 14");

DELETE FROM `creature` WHERE `guid`=296445;
DELETE FROM `creature` WHERE `guid`=296518;
DELETE FROM `creature` WHERE `guid`=296519;

DELETE FROM `creature` WHERE `guid`=286836;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(286836, 92987, 1220, 7558, 7675, 1, 1, '', 0, 0, 3418.53, 7430.65, 16.8465, 4.07303, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

--  SAI
SET @ENTRY := 92987;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,1,5,20000,20000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on range s0"),
(@ENTRY,0,1,0,20,0,100,0,38724,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)");

DELETE FROM `gameobject_template` WHERE `entry`=243227;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `unkInt32`, `AIName`, `ScriptName`, `WorldEffectID`, `StateWorldEffectID`, `SpellVisualID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `MaxVisible`, `IgnoreDynLos`, `MinGold`, `MaxGold`, `VerifiedBuild`) VALUES 
(243227, 10, 411, 'Cementerio Cresta Cuervo', '', '', '', 0, 0, 1.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19073, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartGameObjectAI', '', 5541, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21108);

--  SAI
SET @ENTRY := 93031;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,6,0,100,0,0,0,0,0,45,0,2,0,0,0,0,11,95041,50,0,0,0,0,0,"data attack"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,45,0,2,0,0,0,0,11,95042,50,0,0,0,0,0,"data attack"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"data attack"),
(@ENTRY,0,3,0,0,0,100,0,8000,8000,30000,32000,11,189709,0,0,0,0,0,2,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)"),
(@ENTRY,0,4,0,0,0,100,0,20000,20000,60000,60000,11,189725,0,0,0,0,0,2,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)"),
(@ENTRY,0,5,0,0,0,100,0,20000,20000,40000,40000,11,182710,0,0,0,0,0,2,0,0,0,0,0,0,0,"Npc - Event - Action (phase) (dungeon difficulty)");


DELETE FROM `creature_questender` WHERE `id`=92842 AND `quest`=38717;
DELETE FROM `creature_questender` WHERE `id`=118183 AND `quest`=38717;

--  text
DELETE FROM `creature_text` WHERE `Entry`=92842 AND `Text`='It is just as I feared. Lord Ravencrest\'s remains are gone.';
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
(92842, 0, 0, 'It is just as I feared. Lord Ravencrest\'s remains are gone.', 12, 0, 100, 0, 0, 0, 94829, 0, 0, 0, '???????? ?????? ????? ????? to Player');
DELETE FROM `creature_text` WHERE `Entry`=92842 AND `Text`='Lord Ravencrest died long ago, but I will always revere him as my mentor.';
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
(92842, 1, 0, 'Lord Ravencrest died long ago, but I will always revere him as my mentor.', 12, 0, 100, 0, 0, 0, 96293, 0, 0, 0, '???????? ?????? ????? ????? to Player');
DELETE FROM `creature_text` WHERE `Entry`=92842 AND `Text`='When the ancient war began, we suffered countless losses. Our cities burned.';
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
(92842, 2, 0, 'When the ancient war began, we suffered countless losses. Our cities burned.', 12, 0, 100, 0, 0, 0, 96580, 0, 0, 0, '???????? ?????? ????? ????? to Player');
DELETE FROM `creature_text` WHERE `Entry`=92842 AND `Text`='Lord Ravencrest saved our people and rescued our world from annihilation.';
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
(92842, 3, 0, 'Lord Ravencrest saved our people and rescued our world from annihilation.', 12, 0, 100, 0, 0, 0, 96581, 0, 0, 0, '???????? ?????? ????? ????? to Player');
DELETE FROM `creature_text` WHERE `Entry`=92842 AND `Text`='His loss was tragic for us all. We owe him... everything.';
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
(92842, 4, 0, 'His loss was tragic for us all. We owe him... everything.', 12, 0, 100, 0, 0, 0, 96582, 0, 0, 0, '???????? ?????? ????? ????? to Player');
DELETE FROM `creature_text` WHERE `Entry`=92842 AND `Text`='Follow me. This will lead us to the ramparts.';
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
(92842, 5, 0, 'Follow me. This will lead us to the ramparts.', 12, 0, 100, 0, 0, 0, 114650, 0, 0, 0, '???????? ?????? ????? ????? to Player');
DELETE FROM `creature_text` WHERE `Entry`=92842 AND `Text`='I will take out the guards inside the prison. Get those keys and meet me within the cells.';
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
(92842, 6, 0, 'I will take out the guards inside the prison. Get those keys and meet me within the cells.', 12, 0, 100, 0, 0, 0, 97003, 0, 0, 0, '???????? ?????? ????? ????? to Player');


