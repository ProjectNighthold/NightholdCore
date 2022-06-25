-- "Do the Thing" (QuestID: 42396)

/*Quest_template_addon*/
DELETE FROM `quest_template_addon` WHERE `ID` = 42396;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(42396, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*Creature_queststarter*/
DELETE FROM `creature_queststarter` WHERE `id` = 107302 AND `quest` = 42396;
INSERT INTO `creature_queststarter`(`id`, `quest`) VALUES (107302, 42396);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Turtle Powered" (QuestID: 40368)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 40368;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(40368, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Leyline Feed: Falanaar Dephts" (QuestID: 45593)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 45593;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(45593, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Leyline Feed: Falanaar Arcway" (QuestID: 45592)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 45592;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(45592, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Seed of Hope" (QuestID: 44561)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 44561;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(44561, 0, 0, 0, 42230, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Leyline Feed: Ley Station Moonfall"(QuestID: 43590)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 43590;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(43590, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Leyline Feed: Ley Station Aethenar" (QuestID: 43591)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 43591;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(43591, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0); 

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Sigil Reclamation" (QuestID: 41030)

/*Creature_queststarter*/
DELETE FROM `creature_queststarter` WHERE `id` = 101767 AND `quest` = 41030;
INSERT INTO `creature_queststarter`(`id`, `quest`) VALUES (101767, 41030);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Recovering Stolen Power" (QuestID: 40968)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` IN (40968, 40964);
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(40968, 0, 0, 0, 40963, 40967, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0),
(40964, 0, 0, 0, 40963, 40967, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Precious Little Left" (QuestID: 40967)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 40967;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES 
(40967, 0, 0, 0, 40964, 40969, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Zealot's Dues" (QuestID: 40968)

/*Creature_loot_template*/
DELETE FROM `creature_loot_template` WHERE `entry` = 106275 AND `item` = 136851;
INSERT INTO `creature_loot_template`(`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES
(106275, 136851, 100, 0, 0, 1, 1, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Waiting for Reverge" (41110)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 41110;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES 
(41110, 0, 0, 0, 40968, 41111, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Rain Death Upon Them" (41111)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 41111;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES 
(41111, 0, 0, 0, 41110, 40970, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "The Orchestrator of Our Demise" (QuestID: 40970)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 40970;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES 
(40970, 0, 0, 0, 41111, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*Quest_Objectives*/
DELETE FROM `quest_objectives` WHERE `ID` = 281595;
INSERT INTO `quest_objectives`(`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES
(281595, 40970, 0, 0, 102575, 1, 0, 0, 0, NULL, 21737);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Leyline Feed: Kel'balor" (QuestID: 43588)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 43588;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES 
(43588, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Beach Bonfire" (QuestID: 40332)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 40332;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES 
(40332, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*disables*/
DELETE FROM `disables` WHERE `sourceType` = 1 AND `entry` = 40332;

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Leyline Feed: Elor'shan" (QuestID: 43587)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 43587;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES 
(43587, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "The Key is Around Here Somewhere" (QuestID: 41139)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 41139;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(41139, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Leyline Feed:Halls of the Eclipse" (QuestID: 43594)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 43594;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(43594, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);


/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Growind Strong" (QuestID: 44562)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 44562;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(44562, 0, 0, 0, 42488, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Blast of Spice Fish" (QuestID: 41256)

/*Table_creature_Queststarter*/
DELETE FROM `creature_queststarter` WHERE `id` = 103131 AND `quest` = 41256;
INSERT INTO `creature_queststarter`(`id`, `quest`) VALUES
(103131, 41256);

/*creature*/
DELETE FROM `creature` WHERE `id`= 105014;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(6730112, 105014, 1220, 7637, 7840, 1, 65535, '', 0, 0, 1402.62, 4558.47, 120.562, 3.43949, 300, 0, 0, 1039267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6730113, 105014, 1220, 7637, 7840, 1, 65535, '', 0, 0, 1434.8, 4581.7, 120.568, 5.46267, 300, 0, 0, 1039267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6730114, 105014, 1220, 7637, 7840, 1, 65535, '', 0, 0, 1421.94, 4565.46, 120.314, 0.511523, 300, 0, 0, 1039267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6730115, 105014, 1220, 7637, 7840, 1, 65535, '', 0, 0, 1409.52, 4579.02, 119.427, 5.70536, 300, 0, 0, 1039267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6730116, 105014, 1220, 7637, 7840, 1, 65535, '', 0, 0, 1385.3, 4581.16, 119.427, 1.23959, 300, 0, 0, 1039267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6730117, 105014, 1220, 7637, 7840, 1, 65535, '', 0, 0, 1296.82, 4524.17, 116.541, 1.48699, 300, 0, 0, 1039267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6730118, 105014, 1220, 7637, 7840, 1, 65535, '', 0, 0, 1356.41, 4549.14, 120.506, 0.469111, 300, 0, 0, 1039267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6730119, 105014, 1220, 7637, 7840, 1, 65535, '', 0, 0, 1319.47, 4509.84, 117.541, 2.12159, 300, 0, 0, 1039267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6730120, 105014, 1220, 7637, 7840, 1, 65535, '', 0, 0, 1311.15, 4523.38, 116.545, 2.12159, 300, 0, 0, 1039267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Bad apples" (QuestID:41107)

/*Table_creature_Queststarter*/
DELETE FROM `creature_queststarter` WHERE `id` = 103131 AND `quest` = 41107;
INSERT INTO `creature_queststarter`(`id`, `quest`) VALUES
(103131, 41107);

/*gameobject*/
DELETE FROM `gameobject` WHERE `id` = 247023;
INSERT INTO `gameobject`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `AiID`, `state`, `isActive`, `personal_size`) VALUES 
(6730121, 247023, 1220, 7637, 7840, 1, 1, '', 1369.96, 4548.19, 122.11, 2.05954, -0, -0, -0.857179, -0.515018, 300, 0, 0, 1, 0, 0),
(6730122, 247023, 1220, 7637, 7840, 1, 1, '', 1345.5, 4573.97, 121.625, 4.45814, -0, -0, -0.791049, 0.611753, 300, 0, 0, 1, 0, 0),
(6730123, 247023, 1220, 7637, 7840, 1, 1, '', 1347.06, 4587.69, 121.692, 4.1644, -0, -0, -0.872058, 0.489403, 300, 0, 0, 1, 0, 0),
(6730124, 247023, 1220, 7637, 7840, 1, 1, '', 1365.45, 4596.54, 122.161, 3.2447, -0, -0, -0.998671, 0.0515313, 300, 0, 0, 1, 0, 0),
(6730125, 247023, 1220, 7637, 7840, 1, 1, '', 1385.98, 4600.99, 122.223, 3.28947, -0, -0, -0.997268, 0.0738706, 300, 0, 0, 1, 0, 0),
(6730126, 247023, 1220, 7637, 7840, 1, 1, '', 1411.8, 4613.51, 121.481, 1.40216, -0, -0, -0.645042, -0.764147, 300, 0, 0, 1, 0, 0),
(6730127, 247023, 1220, 7637, 7840, 1, 1, '', 1429.8, 4557.42, 121.522, 0.968616, -0, -0, -0.465596, -0.884997, 300, 0, 0, 1, 0, 0),
(6730128, 247023, 1220, 7637, 7840, 1, 1, '', 1410.93, 4553.03, 121.615, 6.25749, -0, -0, -0.0128477, 0.999918, 300, 0, 0, 1, 0, 0),
(6730129, 247023, 1220, 7637, 7840, 1, 1, '', 1388.15, 4551.09, 123.397, 0.26647, -0, -0, -0.132841, -0.991137, 300, 0, 0, 1, 0, 0),
(6730130, 247023, 1220, 7637, 7840, 1, 1, '', 1345.23, 4525.86, 119.442, 2.70357, -0, -0, -0.976113, -0.217264, 300, 0, 0, 1, 0, 0),
(6730131, 247023, 1220, 7637, 7840, 1, 1, '', 1334.28, 4519.8, 118.011, 3.78507, -0, -0, -0.948688, 0.316215, 300, 0, 0, 1, 0, 0),
(6730132, 247023, 1220, 7637, 7840, 1, 1, '', 1316.48, 4507.61, 117.522, 3.13947, -0, -0, -0.999999, -0.00106223, 300, 0, 0, 1, 0, 0),
(6730133, 247023, 1220, 7637, 7840, 1, 1, '', 1310.76, 4514.67, 117.535, 1.64328, -0, -0, -0.732265, -0.68102, 300, 0, 0, 1, 0, 0),
(6730134, 247023, 1220, 7637, 7840, 1, 1, '', 1296.55, 4530.52, 117.54, 1.93388, -0, -0, -0.823152, -0.567821, 300, 0, 0, 1, 0, 0),
(6730135, 247023, 1220, 7637, 7840, 1, 1, '', 1313.53, 4543.31, 118.495, 0.220142, -0, -0, -0.109849, -0.993948, 300, 0, 0, 1, 0, 0);


/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Friends with Benefits" (QuestID´: 44053)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 44053;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(44053, 0, 0, 0, 43318, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "In the Bag" (QuestID: 43317)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 43317;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(43317, 0, 0, 0, 44040, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Court of Stars: Beware the Fury of a Patient Elf" (QuestID: 43314)

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 43314;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(43314, 0, 0, 0, 44053, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Ephemeral Manastorm Projector" (QuestID: 43563)

/*Table_creature_loot_template*/
DELETE FROM `creature_loot_template` WHERE `entry` = 109670 AND `item` = 139689;
INSERT INTO `creature_loot_template`(`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES
(109670, 139689, 80, 0, 0, 1, 1, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Dry powder" (QuestID: 41410)

/*creature_queststarter*/
DELETE FROM `creature_queststarter` WHERE `id` = 104586 AND `quest` = 41410;
INSERT INTO `creature_queststarter`(`id`, `quest`) VALUES
(104586, 41410);

/*creature*/
DELETE FROM `creature` WHERE `guid`= 6730100;
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES
(6730100, 104586, 1220, 7637, 7917, 1, 1, '', 0, 0, 1231.53, 2352.12, -117.556, 2.19188, 300, 0, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

/*gameobject*/
DELETE FROM `gameobject` WHERE `id` = 247851;
INSERT INTO `gameobject`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `AiID`, `state`, `isActive`, `personal_size`) VALUES
(6730101, 247851, 1220, 7637, 7917, 1, 1, '', 1208.96, 2384.6, -121.877, 2.88303, -0, -0, -0.991655, -0.12892, 300, 0, 0, 1, 0, 0),
(6730102, 247851, 1220, 7637, 7917, 1, 1, '', 1234.1, 2399.76, -119.049, 5.31384, -0, -0, -0.465918, 0.884828, 300, 0, 0, 1, 0, 0),
(6730103, 247851, 1220, 7637, 7917, 1, 1, '', 1260.21, 2409.53, -123.544, 0.177338, -0, -0, -0.0885527, -0.996072, 300, 0, 0, 1, 0, 0),
(6730104, 247851, 1220, 7637, 7917, 1, 1, '', 1197, 2398.08, -114.667, 4.18994, -0, -0, -0.865738, 0.500498, 300, 0, 0, 1, 0, 0),
(6730105, 247851, 1220, 7637, 7917, 1, 1, '', 1144.79, 2410.03, -119.993, 3.88835, -0, -0, -0.931101, 0.364762, 300, 0, 0, 1, 0, 0),
(6730106, 247851, 1220, 7637, 7917, 1, 1, '', 1130.4, 2396.98, -123.259, 3.88835, -0, -0, -0.931101, 0.364762, 300, 0, 0, 1, 0, 0),
(6730107, 247851, 1220, 7637, 7917, 1, 1, '', 1103.43, 2391.94, -122.229, 3.30794, -0, -0, -0.996543, 0.0830762, 300, 0, 0, 1, 0, 0),
(6730108, 247851, 1220, 7637, 7917, 1, 1, '', 1091.26, 2382.58, -123.95, 4.37451, -0, -0, -0.815932, 0.578148, 300, 0, 0, 1, 0, 0),
(6730109, 247851, 1220, 7637, 7917, 1, 1, '', 1075.48, 2364.88, -126.039, 3.72891, -0, -0, -0.957191, 0.289456, 300, 0, 0, 1, 0, 0),
(6730110, 247851, 1220, 7637, 7917, 1, 1, '', 1072.93, 2386.12, -119.799, 1.69002, -0, -0, -0.747976, -0.663725, 300, 0, 0, 1, 0, 0),
(6730111, 247851, 1220, 7637, 7917, 1, 1, '', 1086.69, 2393.7, -106.839, 0.550403, -0, -0, -0.271741, -0.962371, 300, 0, 0, 1, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Fruit of the Doom" (QuestID: 41258)

/*quest_Template*/
UPDATE `quest_template` SET `StartItem` = 134014 WHERE `ID` = 41258;

/*Quest_Template_addom*/
DELETE FROM `quest_template_addon` WHERE `ID` = 41258;
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(41258, 0, 0, 0, 41107, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Dispensing Compassion" (QuestID: 41148)

DELETE FROM `disables` WHERE `sourceType` = 1 AND `entry` = 41148;

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Thalyssra's Abode" (QuestID: 42488)

DELETE FROM `disables` WHERE `sourceType` = 1 AND `entry` = 42488;

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Or Against Us" (QuestID: 43311)

DELETE FROM `conditions` WHERE `SourceEntry` = 43311;


/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "The Esmerald Nightmare: The Stuff of Dreams" (QuestID: 43362)

/*Creature_loot_template*/
DELETE FROM `creature_loot_template` WHERE `entry` = 103769 AND `item` = 139342;
INSERT INTO `creature_loot_template`(`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES
(103769, 139342, 100, 7, 0, 1, 1, 0);

/*conditions*/
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 1 AND `SourceGroup` = 103769 AND `SourceEntry` = 139342 AND `SourceId` = 0 AND `ElseGroup` = 0 AND `ConditionTypeOrReference` = 9 AND `ConditionTarget` = 0 AND `ConditionValue1` = 43362 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES (1, 103769, 139342, 0, 0, 9, 0, 43362, 0, 0, 0, 0, '', NULL);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "The Arcway: Long Buried Knowledge" (QuestID: 42491)

/*gobject*/
DELETE FROM `gameobject` WHERE `id` = 251641;
INSERT INTO `gameobject`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `AiID`, `state`, `isActive`, `personal_size`) VALUES
(25182744, 251641, 1516, 7855, 7855, 8388868, 1, '', 3219.36, 5065.24, 624.447, 0.494648, 0, 0, -0.24481, -0.969571, 60, 0, 0, 1, 0, 0);

/*--------------------------------------------------------------------------------------------------------------------------------*/
-- "Missing Persons" (QuestID: 44724)

/*creature_loot_Template*/
DELETE FROM `creature_loot_template` WHERE `entry` IN (114959, 114869, 114904) AND `item` = 142066;
INSERT INTO `creature_loot_template`(`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES
(114869, 142066, 67.1573, 0, 0, 1, 1, 0),
(114904, 142066, 7.0999, 0, 0, 1, 1, 0),
(114959, 142066, 10.9693, 0, 0, 1, 1, 0);

