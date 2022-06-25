-- "Assault and Battery" (QuestID: 38053)

/*Table_quest_template_Addon*/
DELETE FROM `quest_template_addon` WHERE (`ID`='38053');
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
('38053', '0', '0', '0', '39800', '0', '0', '0', '0', '', '0', '0', '0', '0', '0', '0', '0', '0');

/*Table_quest_objetives*/
DELETE FROM `quest_objectives` WHERE (`ID`='277451');
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES
('277451', '38053', '1', '0', '122295', '1', '1', '0', '0', NULL, '21737');
