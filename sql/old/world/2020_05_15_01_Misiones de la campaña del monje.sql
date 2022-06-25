-- "Stolen Knowledge" (QuestID: 41039)

/*disables*/
DELETE FROM `disables` WHERE `sourceType` = 1 AND `entry` = 41039;

/*quest_template_addon*/
DELETE FROM `quest_template_addon` WHERE `ID` = 41039;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(41039, 0, 0, 0, 41038, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);



-- "A Peaceful World" (QuestID: 41086)

/*quest_template_addon*/
DELETE FROM `quest_template_addon` WHERE `ID` = 41086;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(41086, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*creature_queststarter*/
DELETE FROM `creature_queststarter` WHERE `id` = 102820 AND `quest` = 41086;
INSERT INTO `creature_queststarter`(`id`, `quest`) VALUES (102820, 41086);




-- "In the House of Light and Shadow" (QuestID: 44448)

/*quest_template_addon*/
DELETE FROM `quest_template_addon` WHERE `ID` = 44448;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(44448, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*smart_scripts*/
DELETE FROM `smart_scripts` WHERE `entryorguid` = 113857;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(113857, 0, 0, 0, 73, 0, 100, 0, 0, 0, 0, 0, 33, 113753, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '');

/*npc_spellclick_spells*/
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 113857 AND `spell_id` = 226373;
INSERT INTO `npc_spellclick_spells`(`npc_entry`, `spell_id`, `cast_flags`, `user_type`, `add_npc_flag`) VALUES (113857, 226373, 1, 0, 1);



-- "Halls of Valor: Odyn's Cauldron" (QuestID: 41059)

/*quest_template_addon*/
DELETE FROM `quest_template_addon` WHERE `ID` = 41059;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(41059, 0, 0, 0, 41040, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*disables*/
DELETE FROM `disables` WHERE `sourceType` = 1 AND `entry` = 41059;

