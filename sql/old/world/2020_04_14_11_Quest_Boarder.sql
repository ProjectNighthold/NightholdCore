-- "Boarder" (QuestID: 38052)

/*Table_quest_template_Addon*/
DELETE FROM `quest_template_addon` WHERE (`ID`='38052');
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES 
('38052', '0', '0', '0', '39800', '0', '0', '0', '0', '', '0', '0', '0', '0', '0', '0', '0', '0');

/*Table_quest_objetives*/
DELETE FROM `quest_objectives` WHERE (`ID`='277527');
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES 
('277527', '38052', '0', '1', '90899', '8', '0', '0', '0', NULL, '21737');
