-- Legion: warlock starting quests for headquarters --
-- templates  part 1 --
/*
-- the sixth --
DELETE FROM `quest_template_addon` WHERE `ID`=40716;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES 
(40716, 0, 256, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);
-- the new blood --
DELETE FROM `quest_template_addon` WHERE `ID`=40729;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES 
(40729, 0, 0, 0, 40716, 40684, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);
-- The Tome of Blighted Implements --
DELETE FROM `quest_template_addon` WHERE `ID`=40684;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES 
(40684, 0, 0, 0, 40731, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);
-- The Heart of the Dreadscar --
DELETE FROM `quest_template_addon` WHERE `ID`=40731;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES 
(40731, 0, 0, 0, 0, 40864, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);
*/
-- UPDATES --
-- the sixth --
UPDATE `legion_world`.`quest_template_addon` SET PrevQuestID =     0 WHERE `ID` = 40716;
UPDATE `legion_world`.`quest_template_addon` SET NextQuestID = 40729 WHERE `ID` = 40716;
-- the new blood --
UPDATE `legion_world`.`quest_template_addon` SET PrevQuestID = 40716 WHERE `ID` = 40729;
UPDATE `legion_world`.`quest_template_addon` SET NextQuestID = 40684 WHERE `ID` = 40729;
-- The Tome of Blighted Implements --
UPDATE `legion_world`.`quest_template_addon` SET PrevQuestID = 40729 WHERE `ID` = 40684;
UPDATE `legion_world`.`quest_template_addon` SET NextQuestID =     0 WHERE `ID` = 40684;
-- The heart of the dreadscar --
UPDATE `legion_world`.`quest_template_addon` SET PrevQuestID = 40684 WHERE `ID` = 40731;
UPDATE `legion_world`.`quest_template_addon` SET NextQuestID =     0 WHERE `ID` = 40731;