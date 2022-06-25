/* Montura sede Brujo */


/*
-[La misiva de Sangredoble]46237

-[A construir] 46238 

-[Se buscan donantes]46240

-[Vil hasta la médula]46239

-[Los esbirros de Hel'nurath]46241

-[El llamado del señor del terror]46242

-[El corcel iracundo de Xoroth]46243
*/

/* Arreglo Temporal */


/* INSET Coment

DELETE FROM `quest_template` WHERE (`ID`='46239');
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestLevel`, `QuestMaxScalingLevel`, `QuestPackageID`, `MinLevel`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `RewardArtifactXP`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `StartItem`, `Flags`, `FlagsEx`, `RewardItem1`, `RewardAmount1`, `RewardItem2`, `RewardAmount2`, `RewardItem3`, `RewardAmount3`, `RewardItem4`, `RewardAmount4`, `ItemDrop1`, `ItemDropQuantity1`, `ItemDrop2`, `ItemDropQuantity2`, `ItemDrop3`, `ItemDropQuantity3`, `ItemDrop4`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemQuantity1`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemID2`, `RewardChoiceItemQuantity2`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemID3`, `RewardChoiceItemQuantity3`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemID4`, `RewardChoiceItemQuantity4`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemID5`, `RewardChoiceItemQuantity5`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitTurnIn`, `RewardFactionID1`, `RewardFactionValue1`, `RewardFactionOverride1`, `FactionCapIn1`, `RewardFactionID2`, `RewardFactionValue2`, `RewardFactionOverride2`, `FactionCapIn2`, `RewardFactionID3`, `RewardFactionValue3`, `RewardFactionOverride3`, `FactionCapIn3`, `RewardFactionID4`, `RewardFactionValue4`, `RewardFactionOverride4`, `FactionCapIn4`, `RewardFactionID5`, `RewardFactionValue5`, `RewardFactionOverride5`, `FactionCapIn5`, `RewardFactionFlags`, `RewardCurrencyID1`, `RewardCurrencyQty1`, `RewardCurrencyID2`, `RewardCurrencyQty2`, `RewardCurrencyID3`, `RewardCurrencyQty3`, `RewardCurrencyID4`, `RewardCurrencyQty4`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `QuestRewardID`, `Expansion`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `StartScript`, `CompleteScript`, `VerifiedBuild`) VALUES 
('46239', '2', '110', '255', '0', '110', '-427', '0', '0', '0', '5', '1', '194000', '5', '1', '182850', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '587202568', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '7', '0', '0', '0', '7', '0', '0', '0', '7', '0', '0', '0', '7', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '0', '0', '890', '878', '0', '0', '18446744073709551615', '0', '6', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '0', '0', '24015');

*/

UPDATE `quest_template` SET `QuestType`='0' WHERE 
(`ID`='46239');
DELETE FROM `quest_objectives` WHERE (`ID`='289115');


/* Arreglos  */
DELETE FROM `creature_loot_template` WHERE (`entry`='108259') AND (`item`='144444');
DELETE FROM `creature_loot_template` WHERE (`entry`='108675') AND (`item`='144444');

INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES
('108259', '144444', '29.1779', '0', '0', '2', '8', '0'),
('108675', '144444', '35.6341', '0', '0', '2', '8', '0');


/* UPdate loot */

UPDATE `creature_loot_template` SET `ChanceOrQuestChance`='100' WHERE (`entry`='119173') AND (`item`='144445');

/* inset loot itemsQuest */

DELETE FROM `creature_loot_template` WHERE (`entry`='118840') AND (`item`='144443');
DELETE FROM `creature_loot_template` WHERE (`entry`='118975') AND (`item`='144443'); 
DELETE FROM `creature_loot_template` WHERE (`entry`='119579') AND (`item`='144443');
DELETE FROM `creature_loot_template` WHERE (`entry`='118180') AND (`item`='144443');
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES
('118840', '144443', '100', '7', '0', '1', '1', '0'),
('118975', '144443', '100', '7', '0', '1', '1', '0'),
('119579', '144443', '100', '7', '0', '1', '1', '0'),
('118180', '144443', '100', '7', '0', '1', '1', '0');

/* SmarAI */

DELETE FROM `smart_scripts` WHERE (`entryorguid`='119053');
DELETE FROM `smart_scripts` WHERE (`entryorguid`='11905300');
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
('119053', '0', '0', '0', '8', '0', '100', '0', '6358', '0', '0', '0', '80', '11905300', '2', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'actions - actions'),
('11905300', '9', '0', '0', '0', '0', '100', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'actions - say'),
('11905300', '9', '1', '0', '0', '0', '100', '0', '6000', '6000', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'actions - say'),
('11905300', '9', '2', '0', '0', '0', '100', '0', '6000', '6000', '0', '0', '1', '2', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'actions - say'),
('11905300', '9', '3', '0', '0', '0', '100', '0', '0', '0', '0', '0', '33', '119168', '0', '0', '0', '0', '0', '21', '10', '0', '0', '0', '0', '0', '0', 'actions - killcredit'),
('11905300', '9', '4', '0', '0', '0', '100', '0', '0', '0', '0', '0', '92', '0', '6388', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'actions - unaura');
