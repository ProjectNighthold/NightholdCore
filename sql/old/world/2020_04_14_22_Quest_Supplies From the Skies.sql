-- "Supplies From the Skies" (QuestID: 38036)  

/*Table_quest_template_Addon*/
DELETE FROM `quest_template_addon` WHERE (`ID`=38036);
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(38036, 0, 0, 0, 39800, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*Table_Creature*/
DELETE FROM `creature` WHERE `guid` IN (290783, 365179, 12817333);