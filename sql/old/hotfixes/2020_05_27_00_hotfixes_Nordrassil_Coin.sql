-- Item id 505051  Nordrassil Coin 1$
SET @ITEMGUID = 505051;
REPLACE INTO `item_sparse` (`ID`, `AllowableRace`, `Display`, `Display1`, `Display2`, `Display3`, `Description`, `Flags1`, `Flags2`, `Flags3`, `Flags4`, `PriceRandomValue`, `PriceVariance`, `VendorStackCount`, `BuyPrice`, `SellPrice`, `RequiredAbility`, `MaxCount`, `Stackable`, `StatPercentEditor1`, `StatPercentEditor2`, `StatPercentEditor3`, `StatPercentEditor4`, `StatPercentEditor5`, `StatPercentEditor6`, `StatPercentEditor7`, `StatPercentEditor8`, `StatPercentEditor9`, `StatPercentEditor10`, `StatPercentageOfSocket1`, `StatPercentageOfSocket2`, `StatPercentageOfSocket3`, `StatPercentageOfSocket4`, `StatPercentageOfSocket5`, `StatPercentageOfSocket6`, `StatPercentageOfSocket7`, `StatPercentageOfSocket8`, `StatPercentageOfSocket9`, `StatPercentageOfSocket10`, `ItemRange`, `BagFamily`, `QualityModifier`, `DurationInInventory`, `DmgVariance`, `AllowableClass`, `ItemLevel`, `RequiredSkill`, `RequiredSkillRank`, `MinFactionID`, `ItemStatValue1`, `ItemStatValue2`, `ItemStatValue3`, `ItemStatValue4`, `ItemStatValue5`, `ItemStatValue6`, `ItemStatValue7`, `ItemStatValue8`, `ItemStatValue9`, `ItemStatValue10`, `ScalingStatDistributionID`, `ItemDelay`, `PageID`, `StartQuestID`, `LockID`, `RandomSelect`, `ItemRandomSuffixGroupID`, `ItemSet`, `ZoneBound`, `InstanceBound`, `TotemCategoryID`, `SocketMatch_Enchantment_Id`, `GemProperties`, `LimitCategory`, `RequiredHoliday`, `RequiredTransmogHoliday`, `ItemNameDescriptionID`, `OverallQualityID`, `InventoryType`, `RequiredLevel`, `RequiredPVPRank`, `RequiredPVPMedal`, `MinReputation`, `ContainerSlots`, `StatModifierBonusStat1`, `StatModifierBonusStat2`, `StatModifierBonusStat3`, `StatModifierBonusStat4`, `StatModifierBonusStat5`, `StatModifierBonusStat6`, `StatModifierBonusStat7`, `StatModifierBonusStat8`, `StatModifierBonusStat9`, `StatModifierBonusStat10`, `DamageDamageType`, `Bonding`, `LanguageID`, `PageMaterialID`, `Material`, `SheatheType`, `SocketType1`, `SocketType2`, `SocketType3`, `SpellWeightCategory`, `SpellWeight`, `ArtifactID`, `ExpansionID`, `VerifiedBuild`) VALUES
(@ITEMGUID,'-1','Nordrassil Coin',NULL,NULL,NULL,'|cff00FF00Obtienes 1 moneda para la tienda del juego.|r','134217760','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','-1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','6','0','-1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0');

REPLACE INTO hotfix_data (`Id`, `TableHash`, `RecordId`, `Deleted`) VALUES 
(@ITEMGUID, 2442913102, @ITEMGUID, 0),
(@ITEMGUID, 1344507586, @ITEMGUID, 0),
(@ITEMGUID, 1109793673, @ITEMGUID, 0),
(@ITEMGUID, 3834752085, @ITEMGUID, 0),
(@ITEMGUID, 1073915313, @ITEMGUID, 0);
REPLACE INTO item_appearance (`ID`, `ItemDisplayInfoID`, `DefaultIconFileDataID`, `UIOrder`, `DisplayType`, `VerifiedBuild`) VALUES 
(@ITEMGUID, 0, 0, 0, 0, 0);
REPLACE INTO item_modified_appearance (`ItemID`, `ItemAppearanceID`, `ItemAppearanceModifierID`, `OrderIndex`, `TransmogSourceTypeEnum`, `ID`, `VerifiedBuild`) VALUES 
(@ITEMGUID, 0, 0, 0, 0, @ITEMGUID, 0);
REPLACE INTO item (`ID`, `IconFileDataID`, `ClassID`, `SubClassID`, `SoundOverrideSubclass`, `Material`, `InventoryType`, `SheatheType`, `ItemGroupSoundsID`, `VerifiedBuild`) VALUES 
(@ITEMGUID, 513195, 0, 0, 0, 0, 0, 0, 0, 0); 
REPLACE INTO `item_effect` (`ID`, `SpellID`, `CoolDownMSec`, `CategoryCoolDownMSec`, `Charges`, `SpellCategoryID`, `ChrSpecializationID`, `LegacySlotIndex`, `TriggerType`, `ItemID`, `VerifiedBuild`) VALUES
(@ITEMGUID,18282,0,0,0,0,0,0,0,@ITEMGUID,0);


-- Item id 505052  Nordrassil Coin 2$
SET @ITEMGUID = 505052;
REPLACE INTO `item_sparse` (`ID`, `AllowableRace`, `Display`, `Display1`, `Display2`, `Display3`, `Description`, `Flags1`, `Flags2`, `Flags3`, `Flags4`, `PriceRandomValue`, `PriceVariance`, `VendorStackCount`, `BuyPrice`, `SellPrice`, `RequiredAbility`, `MaxCount`, `Stackable`, `StatPercentEditor1`, `StatPercentEditor2`, `StatPercentEditor3`, `StatPercentEditor4`, `StatPercentEditor5`, `StatPercentEditor6`, `StatPercentEditor7`, `StatPercentEditor8`, `StatPercentEditor9`, `StatPercentEditor10`, `StatPercentageOfSocket1`, `StatPercentageOfSocket2`, `StatPercentageOfSocket3`, `StatPercentageOfSocket4`, `StatPercentageOfSocket5`, `StatPercentageOfSocket6`, `StatPercentageOfSocket7`, `StatPercentageOfSocket8`, `StatPercentageOfSocket9`, `StatPercentageOfSocket10`, `ItemRange`, `BagFamily`, `QualityModifier`, `DurationInInventory`, `DmgVariance`, `AllowableClass`, `ItemLevel`, `RequiredSkill`, `RequiredSkillRank`, `MinFactionID`, `ItemStatValue1`, `ItemStatValue2`, `ItemStatValue3`, `ItemStatValue4`, `ItemStatValue5`, `ItemStatValue6`, `ItemStatValue7`, `ItemStatValue8`, `ItemStatValue9`, `ItemStatValue10`, `ScalingStatDistributionID`, `ItemDelay`, `PageID`, `StartQuestID`, `LockID`, `RandomSelect`, `ItemRandomSuffixGroupID`, `ItemSet`, `ZoneBound`, `InstanceBound`, `TotemCategoryID`, `SocketMatch_Enchantment_Id`, `GemProperties`, `LimitCategory`, `RequiredHoliday`, `RequiredTransmogHoliday`, `ItemNameDescriptionID`, `OverallQualityID`, `InventoryType`, `RequiredLevel`, `RequiredPVPRank`, `RequiredPVPMedal`, `MinReputation`, `ContainerSlots`, `StatModifierBonusStat1`, `StatModifierBonusStat2`, `StatModifierBonusStat3`, `StatModifierBonusStat4`, `StatModifierBonusStat5`, `StatModifierBonusStat6`, `StatModifierBonusStat7`, `StatModifierBonusStat8`, `StatModifierBonusStat9`, `StatModifierBonusStat10`, `DamageDamageType`, `Bonding`, `LanguageID`, `PageMaterialID`, `Material`, `SheatheType`, `SocketType1`, `SocketType2`, `SocketType3`, `SpellWeightCategory`, `SpellWeight`, `ArtifactID`, `ExpansionID`, `VerifiedBuild`) VALUES
(@ITEMGUID,'-1','Nordrassil Coin',NULL,NULL,NULL,'|cff00FF00Obtienes 2 monedas para la tienda del juego.|r','134217760','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','-1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','6','0','-1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0');

REPLACE INTO hotfix_data (`Id`, `TableHash`, `RecordId`, `Deleted`) VALUES 
(@ITEMGUID, 2442913102, @ITEMGUID, 0),
(@ITEMGUID, 1344507586, @ITEMGUID, 0),
(@ITEMGUID, 1109793673, @ITEMGUID, 0),
(@ITEMGUID, 3834752085, @ITEMGUID, 0),
(@ITEMGUID, 1073915313, @ITEMGUID, 0);
REPLACE INTO item_appearance (`ID`, `ItemDisplayInfoID`, `DefaultIconFileDataID`, `UIOrder`, `DisplayType`, `VerifiedBuild`) VALUES 
(@ITEMGUID, 0, 0, 0, 0, 0);
REPLACE INTO item_modified_appearance (`ItemID`, `ItemAppearanceID`, `ItemAppearanceModifierID`, `OrderIndex`, `TransmogSourceTypeEnum`, `ID`, `VerifiedBuild`) VALUES 
(@ITEMGUID, 0, 0, 0, 0, @ITEMGUID, 0);
REPLACE INTO item (`ID`, `IconFileDataID`, `ClassID`, `SubClassID`, `SoundOverrideSubclass`, `Material`, `InventoryType`, `SheatheType`, `ItemGroupSoundsID`, `VerifiedBuild`) VALUES 
(@ITEMGUID, 513195, 0, 0, 0, 0, 0, 0, 0, 0); 
REPLACE INTO `item_effect` (`ID`, `SpellID`, `CoolDownMSec`, `CategoryCoolDownMSec`, `Charges`, `SpellCategoryID`, `ChrSpecializationID`, `LegacySlotIndex`, `TriggerType`, `ItemID`, `VerifiedBuild`) VALUES
(@ITEMGUID,18282,0,0,0,0,0,0,0,@ITEMGUID,0);


-- Item id 505053  Nordrassil Coin 3$
SET @ITEMGUID = 505053;
REPLACE INTO `item_sparse` (`ID`, `AllowableRace`, `Display`, `Display1`, `Display2`, `Display3`, `Description`, `Flags1`, `Flags2`, `Flags3`, `Flags4`, `PriceRandomValue`, `PriceVariance`, `VendorStackCount`, `BuyPrice`, `SellPrice`, `RequiredAbility`, `MaxCount`, `Stackable`, `StatPercentEditor1`, `StatPercentEditor2`, `StatPercentEditor3`, `StatPercentEditor4`, `StatPercentEditor5`, `StatPercentEditor6`, `StatPercentEditor7`, `StatPercentEditor8`, `StatPercentEditor9`, `StatPercentEditor10`, `StatPercentageOfSocket1`, `StatPercentageOfSocket2`, `StatPercentageOfSocket3`, `StatPercentageOfSocket4`, `StatPercentageOfSocket5`, `StatPercentageOfSocket6`, `StatPercentageOfSocket7`, `StatPercentageOfSocket8`, `StatPercentageOfSocket9`, `StatPercentageOfSocket10`, `ItemRange`, `BagFamily`, `QualityModifier`, `DurationInInventory`, `DmgVariance`, `AllowableClass`, `ItemLevel`, `RequiredSkill`, `RequiredSkillRank`, `MinFactionID`, `ItemStatValue1`, `ItemStatValue2`, `ItemStatValue3`, `ItemStatValue4`, `ItemStatValue5`, `ItemStatValue6`, `ItemStatValue7`, `ItemStatValue8`, `ItemStatValue9`, `ItemStatValue10`, `ScalingStatDistributionID`, `ItemDelay`, `PageID`, `StartQuestID`, `LockID`, `RandomSelect`, `ItemRandomSuffixGroupID`, `ItemSet`, `ZoneBound`, `InstanceBound`, `TotemCategoryID`, `SocketMatch_Enchantment_Id`, `GemProperties`, `LimitCategory`, `RequiredHoliday`, `RequiredTransmogHoliday`, `ItemNameDescriptionID`, `OverallQualityID`, `InventoryType`, `RequiredLevel`, `RequiredPVPRank`, `RequiredPVPMedal`, `MinReputation`, `ContainerSlots`, `StatModifierBonusStat1`, `StatModifierBonusStat2`, `StatModifierBonusStat3`, `StatModifierBonusStat4`, `StatModifierBonusStat5`, `StatModifierBonusStat6`, `StatModifierBonusStat7`, `StatModifierBonusStat8`, `StatModifierBonusStat9`, `StatModifierBonusStat10`, `DamageDamageType`, `Bonding`, `LanguageID`, `PageMaterialID`, `Material`, `SheatheType`, `SocketType1`, `SocketType2`, `SocketType3`, `SpellWeightCategory`, `SpellWeight`, `ArtifactID`, `ExpansionID`, `VerifiedBuild`) VALUES
(@ITEMGUID,'-1','Nordrassil Coin',NULL,NULL,NULL,'|cff00FF00Obtienes 3 monedas para la tienda del juego.|r','134217760','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','-1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','6','0','-1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0');

REPLACE INTO hotfix_data (`Id`, `TableHash`, `RecordId`, `Deleted`) VALUES 
(@ITEMGUID, 2442913102, @ITEMGUID, 0),
(@ITEMGUID, 1344507586, @ITEMGUID, 0),
(@ITEMGUID, 1109793673, @ITEMGUID, 0),
(@ITEMGUID, 3834752085, @ITEMGUID, 0),
(@ITEMGUID, 1073915313, @ITEMGUID, 0);
REPLACE INTO item_appearance (`ID`, `ItemDisplayInfoID`, `DefaultIconFileDataID`, `UIOrder`, `DisplayType`, `VerifiedBuild`) VALUES 
(@ITEMGUID, 0, 0, 0, 0, 0);
REPLACE INTO item_modified_appearance (`ItemID`, `ItemAppearanceID`, `ItemAppearanceModifierID`, `OrderIndex`, `TransmogSourceTypeEnum`, `ID`, `VerifiedBuild`) VALUES 
(@ITEMGUID, 0, 0, 0, 0, @ITEMGUID, 0);
REPLACE INTO item (`ID`, `IconFileDataID`, `ClassID`, `SubClassID`, `SoundOverrideSubclass`, `Material`, `InventoryType`, `SheatheType`, `ItemGroupSoundsID`, `VerifiedBuild`) VALUES 
(@ITEMGUID, 513195, 0, 0, 0, 0, 0, 0, 0, 0); 
REPLACE INTO `item_effect` (`ID`, `SpellID`, `CoolDownMSec`, `CategoryCoolDownMSec`, `Charges`, `SpellCategoryID`, `ChrSpecializationID`, `LegacySlotIndex`, `TriggerType`, `ItemID`, `VerifiedBuild`) VALUES
(@ITEMGUID,18282,0,0,0,0,0,0,0,@ITEMGUID,0);


-- Item id 505054  Nordrassil Coin 4$
SET @ITEMGUID = 505054;
REPLACE INTO `item_sparse` (`ID`, `AllowableRace`, `Display`, `Display1`, `Display2`, `Display3`, `Description`, `Flags1`, `Flags2`, `Flags3`, `Flags4`, `PriceRandomValue`, `PriceVariance`, `VendorStackCount`, `BuyPrice`, `SellPrice`, `RequiredAbility`, `MaxCount`, `Stackable`, `StatPercentEditor1`, `StatPercentEditor2`, `StatPercentEditor3`, `StatPercentEditor4`, `StatPercentEditor5`, `StatPercentEditor6`, `StatPercentEditor7`, `StatPercentEditor8`, `StatPercentEditor9`, `StatPercentEditor10`, `StatPercentageOfSocket1`, `StatPercentageOfSocket2`, `StatPercentageOfSocket3`, `StatPercentageOfSocket4`, `StatPercentageOfSocket5`, `StatPercentageOfSocket6`, `StatPercentageOfSocket7`, `StatPercentageOfSocket8`, `StatPercentageOfSocket9`, `StatPercentageOfSocket10`, `ItemRange`, `BagFamily`, `QualityModifier`, `DurationInInventory`, `DmgVariance`, `AllowableClass`, `ItemLevel`, `RequiredSkill`, `RequiredSkillRank`, `MinFactionID`, `ItemStatValue1`, `ItemStatValue2`, `ItemStatValue3`, `ItemStatValue4`, `ItemStatValue5`, `ItemStatValue6`, `ItemStatValue7`, `ItemStatValue8`, `ItemStatValue9`, `ItemStatValue10`, `ScalingStatDistributionID`, `ItemDelay`, `PageID`, `StartQuestID`, `LockID`, `RandomSelect`, `ItemRandomSuffixGroupID`, `ItemSet`, `ZoneBound`, `InstanceBound`, `TotemCategoryID`, `SocketMatch_Enchantment_Id`, `GemProperties`, `LimitCategory`, `RequiredHoliday`, `RequiredTransmogHoliday`, `ItemNameDescriptionID`, `OverallQualityID`, `InventoryType`, `RequiredLevel`, `RequiredPVPRank`, `RequiredPVPMedal`, `MinReputation`, `ContainerSlots`, `StatModifierBonusStat1`, `StatModifierBonusStat2`, `StatModifierBonusStat3`, `StatModifierBonusStat4`, `StatModifierBonusStat5`, `StatModifierBonusStat6`, `StatModifierBonusStat7`, `StatModifierBonusStat8`, `StatModifierBonusStat9`, `StatModifierBonusStat10`, `DamageDamageType`, `Bonding`, `LanguageID`, `PageMaterialID`, `Material`, `SheatheType`, `SocketType1`, `SocketType2`, `SocketType3`, `SpellWeightCategory`, `SpellWeight`, `ArtifactID`, `ExpansionID`, `VerifiedBuild`) VALUES
(@ITEMGUID,'-1','Nordrassil Coin',NULL,NULL,NULL,'|cff00FF00Obtienes 4 monedas para la tienda del juego.|r','134217760','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','-1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','6','0','-1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0');

REPLACE INTO hotfix_data (`Id`, `TableHash`, `RecordId`, `Deleted`) VALUES 
(@ITEMGUID, 2442913102, @ITEMGUID, 0),
(@ITEMGUID, 1344507586, @ITEMGUID, 0),
(@ITEMGUID, 1109793673, @ITEMGUID, 0),
(@ITEMGUID, 3834752085, @ITEMGUID, 0),
(@ITEMGUID, 1073915313, @ITEMGUID, 0);
REPLACE INTO item_appearance (`ID`, `ItemDisplayInfoID`, `DefaultIconFileDataID`, `UIOrder`, `DisplayType`, `VerifiedBuild`) VALUES 
(@ITEMGUID, 0, 0, 0, 0, 0);
REPLACE INTO item_modified_appearance (`ItemID`, `ItemAppearanceID`, `ItemAppearanceModifierID`, `OrderIndex`, `TransmogSourceTypeEnum`, `ID`, `VerifiedBuild`) VALUES 
(@ITEMGUID, 0, 0, 0, 0, @ITEMGUID, 0);
REPLACE INTO item (`ID`, `IconFileDataID`, `ClassID`, `SubClassID`, `SoundOverrideSubclass`, `Material`, `InventoryType`, `SheatheType`, `ItemGroupSoundsID`, `VerifiedBuild`) VALUES 
(@ITEMGUID, 513195, 0, 0, 0, 0, 0, 0, 0, 0); 
REPLACE INTO `item_effect` (`ID`, `SpellID`, `CoolDownMSec`, `CategoryCoolDownMSec`, `Charges`, `SpellCategoryID`, `ChrSpecializationID`, `LegacySlotIndex`, `TriggerType`, `ItemID`, `VerifiedBuild`) VALUES
(@ITEMGUID,18282,0,0,0,0,0,0,0,@ITEMGUID,0);


-- Item id 505055  Nordrassil Coin 5$
SET @ITEMGUID = 505055;
REPLACE INTO `item_sparse` (`ID`, `AllowableRace`, `Display`, `Display1`, `Display2`, `Display3`, `Description`, `Flags1`, `Flags2`, `Flags3`, `Flags4`, `PriceRandomValue`, `PriceVariance`, `VendorStackCount`, `BuyPrice`, `SellPrice`, `RequiredAbility`, `MaxCount`, `Stackable`, `StatPercentEditor1`, `StatPercentEditor2`, `StatPercentEditor3`, `StatPercentEditor4`, `StatPercentEditor5`, `StatPercentEditor6`, `StatPercentEditor7`, `StatPercentEditor8`, `StatPercentEditor9`, `StatPercentEditor10`, `StatPercentageOfSocket1`, `StatPercentageOfSocket2`, `StatPercentageOfSocket3`, `StatPercentageOfSocket4`, `StatPercentageOfSocket5`, `StatPercentageOfSocket6`, `StatPercentageOfSocket7`, `StatPercentageOfSocket8`, `StatPercentageOfSocket9`, `StatPercentageOfSocket10`, `ItemRange`, `BagFamily`, `QualityModifier`, `DurationInInventory`, `DmgVariance`, `AllowableClass`, `ItemLevel`, `RequiredSkill`, `RequiredSkillRank`, `MinFactionID`, `ItemStatValue1`, `ItemStatValue2`, `ItemStatValue3`, `ItemStatValue4`, `ItemStatValue5`, `ItemStatValue6`, `ItemStatValue7`, `ItemStatValue8`, `ItemStatValue9`, `ItemStatValue10`, `ScalingStatDistributionID`, `ItemDelay`, `PageID`, `StartQuestID`, `LockID`, `RandomSelect`, `ItemRandomSuffixGroupID`, `ItemSet`, `ZoneBound`, `InstanceBound`, `TotemCategoryID`, `SocketMatch_Enchantment_Id`, `GemProperties`, `LimitCategory`, `RequiredHoliday`, `RequiredTransmogHoliday`, `ItemNameDescriptionID`, `OverallQualityID`, `InventoryType`, `RequiredLevel`, `RequiredPVPRank`, `RequiredPVPMedal`, `MinReputation`, `ContainerSlots`, `StatModifierBonusStat1`, `StatModifierBonusStat2`, `StatModifierBonusStat3`, `StatModifierBonusStat4`, `StatModifierBonusStat5`, `StatModifierBonusStat6`, `StatModifierBonusStat7`, `StatModifierBonusStat8`, `StatModifierBonusStat9`, `StatModifierBonusStat10`, `DamageDamageType`, `Bonding`, `LanguageID`, `PageMaterialID`, `Material`, `SheatheType`, `SocketType1`, `SocketType2`, `SocketType3`, `SpellWeightCategory`, `SpellWeight`, `ArtifactID`, `ExpansionID`, `VerifiedBuild`) VALUES
(@ITEMGUID,'-1','Nordrassil Coin',NULL,NULL,NULL,'|cff00FF00Obtienes 5 monedas para la tienda del juego.|r','134217760','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','-1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','6','0','-1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0');

REPLACE INTO hotfix_data (`Id`, `TableHash`, `RecordId`, `Deleted`) VALUES 
(@ITEMGUID, 2442913102, @ITEMGUID, 0),
(@ITEMGUID, 1344507586, @ITEMGUID, 0),
(@ITEMGUID, 1109793673, @ITEMGUID, 0),
(@ITEMGUID, 3834752085, @ITEMGUID, 0),
(@ITEMGUID, 1073915313, @ITEMGUID, 0);
REPLACE INTO item_appearance (`ID`, `ItemDisplayInfoID`, `DefaultIconFileDataID`, `UIOrder`, `DisplayType`, `VerifiedBuild`) VALUES 
(@ITEMGUID, 0, 0, 0, 0, 0);
REPLACE INTO item_modified_appearance (`ItemID`, `ItemAppearanceID`, `ItemAppearanceModifierID`, `OrderIndex`, `TransmogSourceTypeEnum`, `ID`, `VerifiedBuild`) VALUES 
(@ITEMGUID, 0, 0, 0, 0, @ITEMGUID, 0);
REPLACE INTO item (`ID`, `IconFileDataID`, `ClassID`, `SubClassID`, `SoundOverrideSubclass`, `Material`, `InventoryType`, `SheatheType`, `ItemGroupSoundsID`, `VerifiedBuild`) VALUES 
(@ITEMGUID, 513195, 0, 0, 0, 0, 0, 0, 0, 0); 
REPLACE INTO `item_effect` (`ID`, `SpellID`, `CoolDownMSec`, `CategoryCoolDownMSec`, `Charges`, `SpellCategoryID`, `ChrSpecializationID`, `LegacySlotIndex`, `TriggerType`, `ItemID`, `VerifiedBuild`) VALUES
(@ITEMGUID,18282,0,0,0,0,0,0,0,@ITEMGUID,0);


-- Item id 505056  Nordrassil Coin 10$
SET @ITEMGUID = 505056;
REPLACE INTO `item_sparse` (`ID`, `AllowableRace`, `Display`, `Display1`, `Display2`, `Display3`, `Description`, `Flags1`, `Flags2`, `Flags3`, `Flags4`, `PriceRandomValue`, `PriceVariance`, `VendorStackCount`, `BuyPrice`, `SellPrice`, `RequiredAbility`, `MaxCount`, `Stackable`, `StatPercentEditor1`, `StatPercentEditor2`, `StatPercentEditor3`, `StatPercentEditor4`, `StatPercentEditor5`, `StatPercentEditor6`, `StatPercentEditor7`, `StatPercentEditor8`, `StatPercentEditor9`, `StatPercentEditor10`, `StatPercentageOfSocket1`, `StatPercentageOfSocket2`, `StatPercentageOfSocket3`, `StatPercentageOfSocket4`, `StatPercentageOfSocket5`, `StatPercentageOfSocket6`, `StatPercentageOfSocket7`, `StatPercentageOfSocket8`, `StatPercentageOfSocket9`, `StatPercentageOfSocket10`, `ItemRange`, `BagFamily`, `QualityModifier`, `DurationInInventory`, `DmgVariance`, `AllowableClass`, `ItemLevel`, `RequiredSkill`, `RequiredSkillRank`, `MinFactionID`, `ItemStatValue1`, `ItemStatValue2`, `ItemStatValue3`, `ItemStatValue4`, `ItemStatValue5`, `ItemStatValue6`, `ItemStatValue7`, `ItemStatValue8`, `ItemStatValue9`, `ItemStatValue10`, `ScalingStatDistributionID`, `ItemDelay`, `PageID`, `StartQuestID`, `LockID`, `RandomSelect`, `ItemRandomSuffixGroupID`, `ItemSet`, `ZoneBound`, `InstanceBound`, `TotemCategoryID`, `SocketMatch_Enchantment_Id`, `GemProperties`, `LimitCategory`, `RequiredHoliday`, `RequiredTransmogHoliday`, `ItemNameDescriptionID`, `OverallQualityID`, `InventoryType`, `RequiredLevel`, `RequiredPVPRank`, `RequiredPVPMedal`, `MinReputation`, `ContainerSlots`, `StatModifierBonusStat1`, `StatModifierBonusStat2`, `StatModifierBonusStat3`, `StatModifierBonusStat4`, `StatModifierBonusStat5`, `StatModifierBonusStat6`, `StatModifierBonusStat7`, `StatModifierBonusStat8`, `StatModifierBonusStat9`, `StatModifierBonusStat10`, `DamageDamageType`, `Bonding`, `LanguageID`, `PageMaterialID`, `Material`, `SheatheType`, `SocketType1`, `SocketType2`, `SocketType3`, `SpellWeightCategory`, `SpellWeight`, `ArtifactID`, `ExpansionID`, `VerifiedBuild`) VALUES
(@ITEMGUID,'-1','Nordrassil Coin',NULL,NULL,NULL,'|cff00FF00Obtienes 10 monedas para la tienda del juego.|r','134217760','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','-1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','6','0','-1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0');

REPLACE INTO hotfix_data (`Id`, `TableHash`, `RecordId`, `Deleted`) VALUES 
(@ITEMGUID, 2442913102, @ITEMGUID, 0),
(@ITEMGUID, 1344507586, @ITEMGUID, 0),
(@ITEMGUID, 1109793673, @ITEMGUID, 0),
(@ITEMGUID, 3834752085, @ITEMGUID, 0),
(@ITEMGUID, 1073915313, @ITEMGUID, 0);
REPLACE INTO item_appearance (`ID`, `ItemDisplayInfoID`, `DefaultIconFileDataID`, `UIOrder`, `DisplayType`, `VerifiedBuild`) VALUES 
(@ITEMGUID, 0, 0, 0, 0, 0);
REPLACE INTO item_modified_appearance (`ItemID`, `ItemAppearanceID`, `ItemAppearanceModifierID`, `OrderIndex`, `TransmogSourceTypeEnum`, `ID`, `VerifiedBuild`) VALUES 
(@ITEMGUID, 0, 0, 0, 0, @ITEMGUID, 0);
REPLACE INTO item (`ID`, `IconFileDataID`, `ClassID`, `SubClassID`, `SoundOverrideSubclass`, `Material`, `InventoryType`, `SheatheType`, `ItemGroupSoundsID`, `VerifiedBuild`) VALUES 
(@ITEMGUID, 513195, 0, 0, 0, 0, 0, 0, 0, 0); 
REPLACE INTO `item_effect` (`ID`, `SpellID`, `CoolDownMSec`, `CategoryCoolDownMSec`, `Charges`, `SpellCategoryID`, `ChrSpecializationID`, `LegacySlotIndex`, `TriggerType`, `ItemID`, `VerifiedBuild`) VALUES
(@ITEMGUID,18282,0,0,0,0,0,0,0,@ITEMGUID,0);