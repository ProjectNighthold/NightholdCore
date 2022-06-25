-- "Insurrection: Crafting War" (QuestID: 45280)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 45280;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(45280, 0, 0, 0, 44845, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*creature_queststarter*/
DELETE FROM `creature_queststarter` WHERE `id` = 115521 AND `quest` = 45280;
INSERT INTO `creature_queststarter`(`id`, `quest`) VALUES (115521, 45280);


/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Oculeth Ex Machina" (QuestID: 44873)

/*Smart_scripts_Oculeth_(NpcID: 115710)*/
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (115710, 11571005);
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(115710, 0, 0, 0, 19, 0, 100, 0, 38695, 0, 0, 0, 80, 11571000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'actions'),
(115710, 0, 1, 0, 62, 0, 100, 0, 20591, 4, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 115840, 15, 0, 0, 0, 0, 0, 'Smart_Set-data_player'),
(115710, 0, 2, 0, 38, 0, 100, 0, 1, 1, 0, 0, 80, 11571001, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'smart_actions_player'),
(115710, 0, 3, 4, 62, 0, 100, 0, 20591, 5, 0, 0, 33, 115710, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'SmartAI'),
(115710, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 232539, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'SmartAI'),
(115710, 0, 5, 0, 62, 0, 100, 0, 20591, 6, 0, 0, 80, 11571005, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'SmartAI'),

(11571005, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'SmartAI'),
(11571005, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 158941, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'SmartAI'),
(11571005, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'SmartAI'),
(11571005, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 33, 115365, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'SmartAI'),
(11571005, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 158941, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'SmartAI'),
(11571005, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 62, 1220, 0, 0, 0, 0, 0, 7, 0, 0, 0, 1182.25, 5881.03, -12.98, 0.58, 'SmartAI');

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Before the Siege" (QuestID: 45267)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 45267;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(45267, 0, 0, 0, 44740, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "The Advisor and the Arcanist" (QuestID: 45268)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 45268;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(45268, 0, 0, 0, 44833, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "A Taste Freedom" (QuestID: 45269)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 45269;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(45269, 0, 0, 0, 45064, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);


