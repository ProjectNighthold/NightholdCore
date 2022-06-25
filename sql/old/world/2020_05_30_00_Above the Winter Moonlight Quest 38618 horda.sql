/* Above the Winter Moonlight Quest 38618*/

DELETE FROM `quest_template_addon` WHERE `ID` IN (38618, 38413, 40568, 38414);
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(38618, 0, 0, 0, 38617, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0),
(38413, 0, 0, 0, 38618, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0),
(38414, 0, 0, 0, 38618, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0),
(40568, 0, 0, 0, 38618, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);
