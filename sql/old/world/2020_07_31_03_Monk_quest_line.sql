-- "Stolen Knowledge" (QuestID: 41039)

/*disables*/
DELETE FROM `disables` WHERE `sourceType` = 1 AND `entry` = 41039;

/*quest_template_addon*/
DELETE FROM `quest_template_addon` WHERE `ID` = 41039;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(41039, 0, 0, 0, 41038, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*creature_questender*/
DELETE FROM `creature_questender` WHERE `id` = 105072 AND `quest` = 41039;
INSERT INTO `creature_questender`(`id`, `quest`) VALUES (105072, 41039);

-- "A Peaceful World" (QuestID: 41086)

/*quest_template_addon*/
DELETE FROM `quest_template_addon` WHERE `ID` = 41086;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(41086, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*creature_queststarter*/
DELETE FROM `creature_queststarter` WHERE `id` = 102820 AND `quest` = 41086;
INSERT INTO `creature_queststarter`(`id`, `quest`) VALUES (102820, 41086);

/*creature_questender*/
DELETE FROM `creature_questender` WHERE `id` = 102820 AND `quest` = 41086;
INSERT INTO `creature_questender`(`id`, `quest`) VALUES (102820, 41086);

