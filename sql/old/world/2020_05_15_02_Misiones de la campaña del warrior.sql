-- "Stolen Honor" (QuestID: 42194)

/*disables*/
DELETE FROM `disables` WHERE `sourceType` = 1 AND `entry` = 42194;


/*******************************************************************************/
-- "Jorhuttam" (QuestID: 42204)

/*disables*/
DELETE FROM `disables` WHERE `sourceType` = 1 AND `entry` = 42204;


/*******************************************************************************/
-- "Mow of Souls: Message to Helya" (QuestID: 43586)

/*quest_template_Addon*/
DELETE FROM `quest_template_addon` WHERE `ID` = 43586;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES 
(43586, 0, 0, 0, 44153, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);



/*******************************************************************************/
-- "Will of the Valarjar" (QuestID: 44667)

/*quest_template_Addon*/
DELETE FROM `quest_template_addon` WHERE `ID` = 44667;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(44667, 0, 0, 0, 43090, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);
