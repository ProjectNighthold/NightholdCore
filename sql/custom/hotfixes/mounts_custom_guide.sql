-- Numbo's Customs --
-- Mounts Guide --

-- Part2: Custom Spell --

-- 2.1 Create a custom spell
-- Important values to change for flying mounts:
-- ID 					= unique Spell ID ( for custom try to match NPC ID )
-- Name					= Creature Name
-- NameSubtext			= need research
-- Description			= Spell Tooltip
-- AuraDescription	= Buff Tooltip
-- VerifiedBuild 		= Custom Dev Number ( choose yourself a number and stick with it; so you know what you edit )
DELETE FROM spell WHERE `ID`=4400000;
INSERT INTO spell 											(`ID`		, `Name`			, `NameSubtext`			, `Description`											, `AuraDescription`																																																				, `VerifiedBuild`	)
VALUES 																				(4400000	, 'Test Mount'	, 'Numbo\'s Creations'	, 'Summons and dismisses a Test Mount.'			, '$?j1g [The speed of movement as to earth is  raised on $j1g%. ] [] $?j1f [The speed of flight is  raised on $j1f%. ] [] $?j1s [The speed of sail is  raised on $j1s%. ] []', 4200				);

-- every change in Hotfix Database need to be applied into hotfix_data table
-- Important Values:
-- ID						= Hotfix_Data ID ( try match recordID )
-- TableHash			= Just copy/paste yet ( ask if you edit a hotfix table not listed in this guide )
-- RecordID				= spell `ID`
REPLACE INTO hotfix_data 									(`Id`		, `TableHash`	, `RecordID`, `Timestamp`	, `Deleted`	)
VALUES 																				(4400000	, 3776013982	, 4400000	, 0				, 0			);



-- 2.2 Link spell to categorie
-- Important values to change for flying mounts:
-- ID 					= unique categorie ID ( for custom try to match SpellID )
-- SpellID 				= spell `ID`
-- VerifiedBuild 		= Custom Dev Number ( choose yourself a number and stick with it; so you know what you edit )
DELETE FROM spell_categories WHERE `ID`=4400000;
INSERT INTO spell_categories 							(`ID`		, `Category`, `StartRecoveryCategory`	, `ChargeCategory`, `DifficultyID`	, `DefenseType`, `DispelType`	, `Mechanic`, `PreventionType`, `SpellID`	, `VerifiedBuild`	)
VALUES 																				(4400000	, 0			, 0								, 0					, 0					, 0				, 0				, 21			, 0					, 4400000	, 4200				);

-- every change in Hotfix Database need to be applied into hotfix_data table
-- Important Values:
-- ID						= Hotfix_Data ID ( try match recordID )
-- TableHash			= Just copy/paste yet ( ask if you edit a hotfix table not listed in this guide )
-- RecordID				= spell_categories `ID`
REPLACE INTO hotfix_data 									(`Id`		, `TableHash`	, `RecordID`, `Timestamp`	, `Deleted`	)
VALUES 																				(4400000	, 3689412649	, 4400000	, 0				, 0			);



-- 2.3 Create spell effect
-- Important values to change for flying mounts:
-- ID 					= unique effect ID ( for custom try to match SpellID )
-- EffectMiscValue1	= 32158 ( Fly Mount )
-- EffectMiscValue2 	= 309 - 419 ( Fly Speed %-1 )
-- SpellID				= spell `ID`
-- VerifiedBuild 		= Custom Dev Number ( choose yourself a number and stick with it; so you know what you edit )

-- Important values to change for ground mounts:
-- ID 					= unique effect ID ( for custom try to match SpellID )
-- EffectMiscValue1	= 14559 ( Ground Mount )
-- EffectMiscValue2 	= 229 - 299 ( Ground Speed %-1 )
-- SpellID				= spell `ID`
-- VerifiedBuild 		= Custom Dev Number ( choose yourself a number and stick with it; so you know what you edit )
DELETE FROM spell_effect WHERE `ID`=4400000;
INSERT INTO spell_effect 									(`ID`		, `Effect`	, `EffectBasePoints`	, `EffectIndex`, `EffectAura`	, `DifficultyID`	, `EffectAmplitude`	, `EffectAuraPeriod`	, `EffectBonusCoefficient`	, `EffectChainAmplitude`, `EffectChainTargets`	, `EffectDieSides`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectRealPointsPerLevel`	, `EffectTriggerSpell`	, `EffectPosFacing`	, `EffectAttributes`	, `BonusCoefficientFromAP`	, `PvpMultiplier`	, `Coefficient`, `Variance`, `ResourceCoefficient`	, `GroupSizeBasePointsCoefficient`	, `EffectSpellClassMask1`	, `EffectSpellClassMask2`	, `EffectSpellClassMask3`	, `EffectSpellClassMask4`	, `EffectMiscValue1`	, `EffectMiscValue2`	, `EffectRadiusIndex1`	, `EffectRadiusIndex2`	, `ImplicitTarget1`	, `ImplicitTarget2`	, `SpellID`	, `VerifiedBuild`	)
VALUES 																				(4400000	, 6			, 0						, 0				, 78				, 0					, 0						, 0						, 0								, 1							, 0							, 0					, 0					, 0					, 0								, 0									, 0							, 0						, 0						, 0								, 1					, 0				, 0			, 0							, 1											, 0								, 0								, 0								, 0								, 32158					, 419						, 0							, 0							, 1						, 0						, 4400000	, 4200				);

-- every change in Hotfix Database need to be applied into hotfix_data table
-- Important Values:
-- ID						= Hotfix_Data ID ( try match recordID )
-- TableHash			= Just copy/paste yet ( ask if you edit a hotfix table not listed in this guide )
-- RecordID				= spell_effect `ID`
REPLACE INTO hotfix_data 									(`Id`		, `TableHash`	, `RecordID`, `Timestamp`	, `Deleted`	)
VALUES 																				(4400000	, 4030871717	, 4400000	, 0				, 0			);



-- 2.4 Create spell ranks
-- Important values to change for mounts:
-- ID						= unique level ID ( for custom try to match SpellID )
-- SpellID				= spell `ID`
-- VerifiedBuild 		= Custom Dev Number ( choose yourself a number and stick with it; so you know what you edit )
DELETE FROM spell_levels WHERE `ID`=4400000;
INSERT INTO spell_levels 									(`ID`		, `BaseLevel`	, `MaxLevel`, `SpellLevel`	, `DifficultyID`	, `MaxPassiveAuraLevel`	, `SpellID`	, `VerifiedBuild`	)
VALUES 																				(4400000	, 0				, 0			, 1				, 0					, 0							, 4400000	, 0					);

-- every change in Hotfix Database need to be applied into hotfix_data table
-- Important Values:
-- ID						= Hotfix_Data ID ( try match recordID )
-- TableHash			= Just copy/paste yet ( ask if you edit a hotfix table not listed in this guide )
-- RecordID				= spell_levels `ID`
REPLACE INTO hotfix_data 									(`Id`		, `TableHash`	, `RecordID`, `Timestamp`	, `Deleted`	)
VALUES 																				(4400000	, 501138918		, 4400000	, 0				, 0			);



-- 2.5 Create spell translation
-- Important values to change for mounts:
-- ID						= spell `ID`
-- locale				= deDE; ruRU; esES; frFR ( server is english so no need english locale )
-- VerifiedBuild 		= Custom Dev Number ( choose yourself a number and stick with it; so you know what you edit )
DELETE FROM spell_locale WHERE `ID`=4400000 AND `locale`='ruRU';
INSERT INTO spell_locale 									(`ID`		, `locale`	, `Name_lang`			, `NameSubtext_lang`											, `Description_lang`											, `AuraDescription_lang`																																																		, `VerifiedBuild`	)
VALUES																				(4400000	, 'ruRU'		, 'Сумерки'				, 'Творения Нумбо'											, 'Вызывает и увольняет Сумерки.'						, '$?j1g [Скорость движения относительно Земли увеличена на $j 1 г% ] [] $?j1f [Скорость полета увеличена на $j 1f%. ] [] $?j1s [Скорость паруса повышается на $j 1с%. ] []'	, 1					);

-- every change in Hotfix Database need to be applied into hotfix_data table
-- Important Values:
-- ID						= Hotfix_Data ID ( try match recordID )
-- TableHash			= Just copy/paste yet ( ask if you edit a hotfix table not listed in this guide )
-- RecordID				= spell `ID`

-- W.I.P --



-- 2.6 Assign spell miscs
-- Important values to change for mounts:
-- ID 						= unique misc ID ( for custom try match SpellID)
-- SpellIconFileDataID 	= IconID ( https://www.wowhead.com/icons )
-- SpellID					= spell `ID`
-- VerifiedBuild 			= Custom Dev Number ( choose yourself a number and stick with it; so you know what you edit )
DELETE FROM spell_misc WHERE `ID`=4400000;
INSERT INTO spell_misc 									(`ID`		, `CastingTimeIndex`	, `DurationIndex`	, `RangeIndex`	, `SchoolMask`	, `SpellIconFileDataID`	, `Speed`, `ActiveIconFileDataID`, `LaunchDelay`, `DifficultyID`	, `Attributes1`, `Attributes2`, `Attributes3`, `Attributes4`, `Attributes5`, `Attributes6`, `Attributes7`, `Attributes8`, `Attributes9`, `Attributes10`	, `Attributes11`	, `Attributes12`	, `Attributes13`	, `Attributes14`	, `SpellID`	, `VerifiedBuild`	)
VALUES 																				(4400000	, 16						, 21					, 1				, 1				, 1616893					, 0		, 0							, 0				, 0					, 269582608		, 0				, 0				, 0				, 0				, 0				, 131072			, 0				, 4096			, 0					, 0					, 0					, 0					, 0					, 4400000	, 4200				);

-- every change in Hotfix Database need to be applied into hotfix_data table
-- Important Values:
-- ID						= Hotfix_Data ID ( try match recordID )
-- TableHash			= Just copy/paste yet ( ask if you edit a hotfix table not listed in this guide )
-- RecordID				= spell `ID`
REPLACE INTO hotfix_data 									(`Id`		, `TableHash`	, `RecordID`, `Timestamp`	, `Deleted`	)
VALUES 																				(4400000	, 3322146344	, 4400000	, 0				, 0			);



-- 2.7 Spell visual effects
-- Important values to change for mounts:
-- ID 						= unique x_spell_visual ID ( for custom try match SpellID )
-- SpellID					= spell `ID`
-- VerifiedBuild 			= Custom Dev Number ( choose yourself a number and stick with it; so you know what you edit )
DELETE FROM spell_x_spell_visual WHERE `ID`=4400000;
INSERT INTO spell_x_spell_visual 						(`SpellVisualID`	, `ID`	, `Probability`, `CasterPlayerConditionID`, `CasterUnitConditionID`	, `ViewerPlayerConditionID`, `ViewerUnitConditionID`	, `SpellIconFileID`	, `ActiveIconFileID`	, `Flags`	, `DifficultyID`	, `Priority`, `SpellID`	, `VerifiedBuild`	)
VALUES 																				(62253				, 4400000, 0				, 0								, 0								, 0								, 0								, 0						, 0						, 0			, 0					, 0			, 4400000	, 4200				);

-- every change in Hotfix Database need to be applied into hotfix_data table
-- Important Values:
-- ID						= Hotfix_Data ID ( try match recordID )
-- TableHash			= Just copy/paste yet ( ask if you edit a hotfix table not listed in this guide )
-- RecordID				= spell_x_spell_visual `ID`
REPLACE INTO hotfix_data 									(`Id`		, `TableHash`	, `RecordID`, `Timestamp`	, `Deleted`	)
VALUES 																				(4400000	, 666345498		, 4400000	, 0				, 0			);




-- Part3: Custom Mount

-- 3.1 Create Mount
-- Important values to change for flying mounts:
-- SourceSpellID 			= spell `ID`
-- MountTypeID				= 248
-- Flags						= 128
-- ID 						= unique Mount ID ( Latest +1 )
-- VerifiedBuild 			= Custom Dev Number ( choose yourself a number and stick with it; so you know what you edit )

-- Important values to change for ground mounts:
-- SourceSpellID 			= spell `ID`
-- MountTypeID				= 230
-- Flags						= 0
-- ID 						= unique Mount ID ( Latest +1 )
-- VerifiedBuild 			= Custom Dev Number ( choose yourself a number and stick with it; so you know what you edit )
DELETE FROM mount WHERE `ID`=5027;
INSERT INTO mount 											(`Name`			, `Description`																																																																													, `SourceText`					, `SourceSpellID`	, `MountFlyRideHeight`	, `MountTypeID`, `Flags`, `SourceTypeEnum`, `ID`	, `PlayerConditionID`, `UiModelSceneID`, `VerifiedBuild`	)
VALUES 																				('Test Mount'	, 'Pain... Agony... My hatred burns through the cavernous deeps. The world heaves with my torment. Its wretched kingdoms quake beneath my rage. But at last... The whole of Azeroth will break... And all will burn beneath the shadow of my wings.'	, 'Numbo\'s Test Creations', 4400000			, 0							, 248				, 128		, 5					, 5027	, 0						, 4					, 4200				);

-- every change in Hotfix Database need to be applied into hotfix_data table
-- Important Values:
-- ID						= Hotfix_Data ID ( try match recordID )
-- TableHash			= Just copy/paste yet ( ask if you edit a hotfix table not listed in this guide )
-- RecordID				= mount `ID`
REPLACE INTO hotfix_data 									(`Id`		, `TableHash`		, `RecordID`, `Timestamp`	, `Deleted`	)
VALUES 																				(5027		, 2524150337		, 5027		, 0				, 0			);



-- 3.2 Set DisplayID
-- Important values to change for mounts:
-- ID 							= unique mount display ID ( latest +1 )
-- CreatureDisplayInfoID 	= Creature DisplayID
-- MountID 						= mount `ID`
-- VerifiedBuild 				= Custom Dev Number ( choose yourself a number and stick with it; so you know what you edit )
DELETE FROM mount_x_display WHERE `ID`=3027;
INSERT INTO mount_x_display 								(`ID`, `CreatureDisplayInfoID`, `PlayerConditionID`, `MountID`	, `VerifiedBuild`	)
VALUES 																				(3027, 497							, 0						, 5027		, 4200				);

-- every change in Hotfix Database need to be applied into hotfix_data table
-- Important Values:
-- ID						= Hotfix_Data ID ( try match recordID )
-- TableHash			= Just copy/paste yet ( ask if you edit a hotfix table not listed in this guide )
-- RecordID				= mount_x_display `ID`
REPLACE INTO hotfix_data 									(`Id`		, `TableHash`		, `RecordID`, `Timestamp`	, `Deleted`	)
VALUES 																				(3027		, 2030087241		, 3027		, 0				, 0			);

-- Part4: Create learnable item

-- 4.1 Create custom item
-- Important values to change for mounts:
-- ID								= unique Item ID ( for custom mount try match SpellID )
-- Display						= Item name
-- Description					= Item tooltip description
-- BuyPrice						= Gold in copper
-- SellPrice					= Gold in copper
-- RequiredAbility			= SpellID	( riding skill for mounts in most case )
-- OverallQualityID			= Rare/Epic and so on.. ( 1 - 6 )
-- RequiredLevel				= minLevel to use
-- VerifiedBuild 				= Custom Dev Number ( choose yourself a number and stick with it; so you know what you edit )
DELETE FROM item_sparse WHERE `ID`=4400000;
INSERT INTO item_sparse 									(`ID`		, `AllowableRace`	, `Display`						, `Display1`, `Display2`, `Display3`, `Description`						, `Flags1`	, `Flags2`	, `Flags3`	, `Flags4`	, `PriceRandomValue`	, `PriceVariance`	, `VendorStackCount`	, `BuyPrice`, `SellPrice`	, `RequiredAbility`	, `MaxCount`, `Stackable`	, `StatPercentEditor1`	, `StatPercentEditor2`	, `StatPercentEditor3`	, `StatPercentEditor4`	, `StatPercentEditor5`	, `StatPercentEditor6`	, `StatPercentEditor7`	, `StatPercentEditor8`	, `StatPercentEditor9`	, `StatPercentEditor10`	, `StatPercentageOfSocket1`, `StatPercentageOfSocket2`, `StatPercentageOfSocket3`, `StatPercentageOfSocket4`, `StatPercentageOfSocket5`, `StatPercentageOfSocket6`, `StatPercentageOfSocket7`, `StatPercentageOfSocket8`, `StatPercentageOfSocket9`, `StatPercentageOfSocket10`	, `ItemRange`	, `BagFamily`	, `QualityModifier`	, `DurationInInventory`	, `DmgVariance`, `AllowableClass`, `ItemLevel`	, `RequiredSkill`	, `RequiredSkillRank`, `MinFactionID`					, `ItemStatValue1`, `ItemStatValue2`, `ItemStatValue3`, `ItemStatValue4`, `ItemStatValue5`, `ItemStatValue6`, `ItemStatValue7`, `ItemStatValue8`, `ItemStatValue9`, `ItemStatValue10`	, `ScalingStatDistributionID`	, `ItemDelay`	, `PageID`	, `StartQuestID`	, `LockID`	, `RandomSelect`	, `ItemRandomSuffixGroupID`, `ItemSet`	, `ZoneBound`	, `InstanceBound`	, `TotemCategoryID`	, `SocketMatch_enchantment_id`, `GemProperties`	, `LimitCategory`		, `RequiredHoliday`	, `RequiredTransmogHoliday`	, `ItemNameDescriptionID`	, `OverallQualityID`	, `InventoryType`	, `RequiredLevel`	, `RequiredPVPRank`	, `RequiredPVPMedal`	, `MinReputation`				, `ContainerSlots`, `StatModifierBonusStat1`	, `StatModifierBonusStat2`	, `StatModifierBonusStat3`	, `StatModifierBonusStat4`	, `StatModifierBonusStat5`	, `StatModifierBonusStat6`	, `StatModifierBonusStat7`	, `StatModifierBonusStat8`	, `StatModifierBonusStat9`	, `StatModifierBonusStat10`, `DamageDamageType`	, `Bonding`	, `LanguageID`	, `PageMaterialID`, `Material`, `SheatheType`, `SocketType1`	, `SocketType2`	, `SocketType3`	, `SpellWeightCategory`		, `SpellWeight`					, `ArtifactID`	, `ExpansionID`		, `VerifiedBuild`	)
VALUES 																				(4400000	, -1					, 'Reins of the Test Mount', NULL		, NULL		, NULL		, 'Teaches you the Test Mount'	, 0			, 8192		, 0			, 0			, 1.0263					, 1					, 1						, 2000000	, 0				, 34091					, 1			, 1				, 0							, 0							, 0							, 0							, 0							, 0							, 0							, 0							, 0							, 0							, 0								, 0								, 0								, 0								, 0								, 0								, 0								, 0								, 0								, 0									, 0				, 0				, 0						, 0							, 0				, -1					, 420				, 0					, 0						, 0									, 0					, 0					, 0					, 0					, 0					, 0					, 0					, 0					, 0					, 0						, 0									, 0				, 0			, 0					, 0			, 0					, 0								, 0			, 0				, 0					, 0						, 0									, 0					, 0						, 0						, 0									, 0								, 4						, 0					, 70					, 0						, 0						, 0								, 0					, 0								, 0								, 0								, 0								, 0								, 0								, 0								, 0								, 0								, 0								, 0						, 1			, 0				, 0					, 0			, 0				, 0					, 0					, 0					, 0								, 0									, 0				, 0						, 0					);
-- same values but diffrent names ( dont ask why )
DELETE FROM itemsparse WHERE `ID`=4400000;
INSERT INTO itemsparse 									(`ID`		, `AllowableRace`	, `Name1`						, `Name2`	, `Name3`	, `Name4`	, `Description`						, `Flags1`	, `Flags2`	, `Flags3`	, `Flags4`	, `PriceRandomValue`	, `PriceVariance`	, `VendorStackCount`	, `BuyPrice`, `SellPrice`	, `RequiredSpell`		, `MaxCount`, `Stackable`	, `StatPercentEditor1`	, `StatPercentEditor2`	, `StatPercentEditor3`	, `StatPercentEditor4`	, `StatPercentEditor5`	, `StatPercentEditor6`	, `StatPercentEditor7`	, `StatPercentEditor8`	, `StatPercentEditor9`	, `StatPercentEditor10`	, `StatPercentageOfSocket1`, `StatPercentageOfSocket2`, `StatPercentageOfSocket3`, `StatPercentageOfSocket4`, `StatPercentageOfSocket5`, `StatPercentageOfSocket6`, `StatPercentageOfSocket7`, `StatPercentageOfSocket8`, `StatPercentageOfSocket9`, `StatPercentageOfSocket10`	, `ItemRange`	, `BagFamily`	, `QualityModifier`	, `DurationInInventory`	, `DmgVariance`, `AllowableClass`, `ItemLevel`	, `RequiredSkill`	, `RequiredSkillRank`, `RequiredReputationFaction`	, `ItemStatValue1`, `ItemStatValue2`, `ItemStatValue3`, `ItemStatValue4`, `ItemStatValue5`, `ItemStatValue6`, `ItemStatValue7`, `ItemStatValue8`, `ItemStatValue9`, `ItemStatValue10`	, `ScalingStatDistribution`	, `Delay`		, `PageText`, `StartQuest`		, `LockID`	, `RandomProperty`, `RandomSuffix`				, `ItemSet`	, `Area`			, `Map`				, `TotemCategory`		, `SocketBonus`					, `GemProperties`	, `ItemLimitCategory`, `HolidayID`			, `RequiredTransmogHolidayID`	, `ItemNameDescriptionID`	, `Quality`				, `InventoryType`	, `RequiredLevel`	, `RequiredHonorRank`, `RequiredCityRank`	, `RequiredReputationRank`	, `ContainerSlots`, `ItemStatType1`				, `ItemStatType2`				, `ItemStatType3`				, `ItemStatType4`				, `ItemStatType5`				, `ItemStatType6`				, `ItemStatType7`				, `ItemStatType8`				, `ItemStatType9`				, `ItemStatType10`			, `DamageType`			, `Bonding`	, `LanguageID`	, `PageMaterial`	, `Material`, `Sheath`		, `SocketColor1`	, `SocketColor2`	, `SocketColor3`	, `CurrencySubstitutionID`	, `CurrencySubstitutionCount`	, `ArtifactID`	, `RequiredExpansion`, `VerifiedBuild`	)
VALUES 																				(4400000	, -1					, 'Reins of the Test Mount', NULL		, NULL		, NULL		, 'Teaches you the Test Mount.'	, 0			, 8192		, 0			, 0			, 1.0263					, 1					, 1						, 2000000	, 0				, 34091					, 1			, 1				, 0							, 0							, 0							, 0							, 0							, 0							, 0							, 0							, 0							, 0							, 0								, 0								, 0								, 0								, 0								, 0								, 0								, 0								, 0								, 0									, 0				, 0				, 0						, 0							, 0				, -1					, 420				, 0					, 0						, 0									, 0					, 0					, 0					, 0					, 0					, 0					, 0					, 0					, 0					, 0						, 0									, 0				, 0			, 0					, 0			, 0					, 0								, 0			, 0				, 0					, 0						, 0									, 0					, 0						, 0						, 0									, 0								, 4						, 0					, 70					, 0						, 0						, 0								, 0					, 0								, 0								, 0								, 0								, 0								, 0								, 0								, 0								, 0								, 0								, 0						, 1			, 0				, 0					, 0			, 0				, 0					, 0					, 0					, 0								, 0									, 0				, 0						, 0					);

-- every change in Hotfix Database need to be applied into hotfix_data table
-- Important Values:
-- ID						= Hotfix_Data ID ( try match recordID )
-- TableHash			= Just copy/paste yet ( ask if you edit a hotfix table not listed in this guide )
-- RecordID				= item_sparse `ID`
REPLACE INTO hotfix_data 									(`Id`		, `TableHash`		, `RecordID`, `Timestamp`	, `Deleted`	)
VALUES 																				(4400000	, 2442913102		, 4400000	, 0				, 0			);



-- 4.2 Create custom item
-- Important values to change for mounts:
-- ID								= item_sparse `ID`
-- IconFileDataID				= Item Icon ( https://www.wowhead.com/icons )
-- VerifiedBuild 				= Custom Dev Number ( choose yourself a number and stick with it; so you know what you edit )
DELETE FROM item WHERE `ID`=4400000;
INSERT INTO item 											(`ID`		, `IconFileDataID`, `ClassID`	, `SubclassID`	, `SoundOverrideSubclass`	, `Material`, `InventoryType`	, `SheatheType`, `ItemGroupSoundsID`, `VerifiedBuild`	)
VALUES 																				(4400000	, 236231				, 15			, 5				, -1								, 0			, 0					, 0				, 16						, 0					);

-- every change in Hotfix Database need to be applied into hotfix_data table
-- Important Values:
-- ID						= Hotfix_Data ID ( try match recordID )
-- TableHash			= Just copy/paste yet ( ask if you edit a hotfix table not listed in this guide )
-- RecordID				= item `ID`
REPLACE INTO hotfix_data 									(`Id`		, `TableHash`		, `RecordID`, `Timestamp`	, `Deleted`	)
VALUES 																				(4400000	, 1344507586		, 4400000	, 0				, 0			);



-- 4.3 Create item learn effect
-- Important values to change for mounts:
-- ID 							= unique effect ID ( for custom try match ItemID )
-- ItemID						= item_sparse `ID`
-- VerifiedBuild 				= Custom Dev Number ( choose yourself a number and stick with it; so you know what you edit )
DELETE FROM item_effect WHERE `ID`=4400000;
INSERT INTO item_effect 									(`ID`		, `SpellID`	, `CoolDownMSec`	, `CategoryCoolDownMSec`, `Charges`	, `SpellCategoryID`	, `ChrSpecializationID`	, `LegacySlotIndex`	, `TriggerType`, `ItemID`	, `VerifiedBuild`	)
VALUES 																				(4400000	, 55884		, -1					, 3000						, -1			, 330						, 0							, 0						, 0				, 4400000	, 0					);

-- 4.4 Create mount learn effect
-- Important values to change for mounts:
-- ID 							= 4.3 Item learn effect ID +1
-- SpellID						= spell `ID`
-- ItemID						= item_sparse `ID`
-- VerifiedBuild 				= Custom Dev Number ( choose yourself a number and stick with it; so you know what you edit )
DELETE FROM item_effect WHERE `ID`=4400001;
INSERT INTO item_effect 									(`ID`		, `SpellID`		, `CoolDownMSec`	, `CategoryCoolDownMSec`, `Charges`	, `SpellCategoryID`	, `ChrSpecializationID`	, `LegacySlotIndex`	, `TriggerType`, `ItemID`	, `VerifiedBuild`	)
VALUES 																				(4400001	, 4400000		, -1					, -1							, 0			, 0						, 0							, 1						, 6				, 4400000	, 0					);

-- every change in Hotfix Database need to be applied into hotfix_data table
-- Important Values:
-- ID						= Hotfix_Data ID ( try match recordID )
-- TableHash			= Just copy/paste yet ( ask if you edit a hotfix table not listed in this guide )
-- RecordID				= item_effect `ID`
REPLACE INTO hotfix_data 									(`Id`		, `TableHash`		, `RecordID`, `Timestamp`	, `Deleted`	)
VALUES 																				(4400000	, 1073915313		, 4400000		, 0				, 0			),
																						(4400001	, 1073915313		, 4400001		, 0				, 0			);

--   ()()
--  (°-°)
--  (@)(@)



