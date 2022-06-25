-- "A heavy burden" (QuestId: 40078)

/*Table_quest_Template_Addon*/
DELETE FROM `quest_template_addon` WHERE `ID` = 40078;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(40078, 0, 0, 0, 40044, 40001, 0, 0, 0, '', 185, 1, 0, 0, 0, 0, 0, 0);
