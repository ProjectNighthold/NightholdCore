/* Above the Winter Moonlight Quest 38412 */
DELETE FROM `creature_queststarter` WHERE `id` = 91558 AND `quest` = 38412;
INSERT INTO `creature_queststarter`(`id`, `quest`) VALUES (91558, 38412);

DELETE FROM `quest_template_addon` WHERE `ID` IN (38412, 38413, 40568, 38414);
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(38412, 0, 0, 0, 38342, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0),
(38413, 0, 0, 0, 38412, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0),
(38414, 0, 0, 0, 38412, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0),
(40568, 0, 0, 0, 38412, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);


