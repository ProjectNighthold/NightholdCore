-- Antorus Spell Scaling --
-- Exhaust Boss Sleep spell changed from 18 - 3sec
-- Sleep Canister
DELETE FROM `spell_misc` WHERE `ID`=238793;
INSERT INTO `spell_misc` (`ID`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellIconFileDataID`, `Speed`, `ActiveIconFileDataID`, `LaunchDelay`, `DifficultyID`, `Attributes1`, `Attributes2`, `Attributes3`, `Attributes4`, `Attributes5`, `Attributes6`, `Attributes7`, `Attributes8`, `Attributes9`, `Attributes10`, `Attributes11`, `Attributes12`, `Attributes13`, `Attributes14`, `SpellID`, `VerifiedBuild`) VALUES (238793, 3, 27, 135, 8, 136090, 0, 0, 0, 16, 262144, 0, 131076, 0, 0, 0, 0, 0, 1073741824, 16, 0, 0, 0, 0, 255029, 0);
DELETE FROM `spell_misc` WHERE `ID`=240961;
INSERT INTO `spell_misc` (`ID`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellIconFileDataID`, `Speed`, `ActiveIconFileDataID`, `LaunchDelay`, `DifficultyID`, `Attributes1`, `Attributes2`, `Attributes3`, `Attributes4`, `Attributes5`, `Attributes6`, `Attributes7`, `Attributes8`, `Attributes9`, `Attributes10`, `Attributes11`, `Attributes12`, `Attributes13`, `Attributes14`, `SpellID`, `VerifiedBuild`) VALUES (240961, 1, 35, 135, 8, 136090, 0, 0, 0, 17, 262144, 0, 131076, 0, 0, 0, 0, 0, 1073741824, 16, 0, 0, 0, 0, 255029, 0);
DELETE FROM `spell_misc` WHERE `ID`=238794;
INSERT INTO `spell_misc` (`ID`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellIconFileDataID`, `Speed`, `ActiveIconFileDataID`, `LaunchDelay`, `DifficultyID`, `Attributes1`, `Attributes2`, `Attributes3`, `Attributes4`, `Attributes5`, `Attributes6`, `Attributes7`, `Attributes8`, `Attributes9`, `Attributes10`, `Attributes11`, `Attributes12`, `Attributes13`, `Attributes14`, `SpellID`, `VerifiedBuild`) VALUES (238794, 1, 39, 135, 8, 136090, 0, 0, 0, 0, 262144, 0, 131076, 0, 0, 0, 0, 0, 1073741824, 16, 0, 0, 0, 0, 255029, 0);


-- Eonar Focusing Crystal Debuff length changed from infinit to 4sec
-- Feedback: Arcane Singularity
DELETE FROM `spell_misc` WHERE `ID`=232727;
INSERT INTO `spell_misc` (`ID`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellIconFileDataID`, `Speed`, `ActiveIconFileDataID`, `LaunchDelay`, `DifficultyID`, `Attributes1`, `Attributes2`, `Attributes3`, `Attributes4`, `Attributes5`, `Attributes6`, `Attributes7`, `Attributes8`, `Attributes9`, `Attributes10`, `Attributes11`, `Attributes12`, `Attributes13`, `Attributes14`, `SpellID`, `VerifiedBuild`) VALUES (232727, 1, 39, 13, 1, 463280, 0, 0, 0, 0, 612370432, 0, 4, 1310720, 128, 0, 0, 0, 0, 1048576, 0, 0, 0, 0, 249017, 1);

-- Feedback: Targeted
DELETE FROM `spell_misc` WHERE `ID`=232726;
INSERT INTO `spell_misc` (`ID`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellIconFileDataID`, `Speed`, `ActiveIconFileDataID`, `LaunchDelay`, `DifficultyID`, `Attributes1`, `Attributes2`, `Attributes3`, `Attributes4`, `Attributes5`, `Attributes6`, `Attributes7`, `Attributes8`, `Attributes9`, `Attributes10`, `Attributes11`, `Attributes12`, `Attributes13`, `Attributes14`, `SpellID`, `VerifiedBuild`) VALUES (232726, 1, 39, 13, 1, 463281, 0, 0, 0, 0, 612370432, 0, 4, 1310720, 128, 0, 0, 0, 0, 1048576, 0, 0, 0, 0, 249016, 1);

-- Feedback: Burning Embers
DELETE FROM `spell_misc` WHERE `ID`=232725;
INSERT INTO `spell_misc` (`ID`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellIconFileDataID`, `Speed`, `ActiveIconFileDataID`, `LaunchDelay`, `DifficultyID`, `Attributes1`, `Attributes2`, `Attributes3`, `Attributes4`, `Attributes5`, `Attributes6`, `Attributes7`, `Attributes8`, `Attributes9`, `Attributes10`, `Attributes11`, `Attributes12`, `Attributes13`, `Attributes14`, `SpellID`, `VerifiedBuild`) VALUES (232725, 1, 39, 13, 1, 463282, 0, 0, 0, 0, 612370432, 0, 4, 1310720, 128, 0, 0, 0, 0, 1048576, 0, 0, 0, 0, 249015, 1);

-- Feedback: Foul Steps
DELETE FROM `spell_misc` WHERE `ID`=232724;
INSERT INTO `spell_misc` (`ID`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellIconFileDataID`, `Speed`, `ActiveIconFileDataID`, `LaunchDelay`, `DifficultyID`, `Attributes1`, `Attributes2`, `Attributes3`, `Attributes4`, `Attributes5`, `Attributes6`, `Attributes7`, `Attributes8`, `Attributes9`, `Attributes10`, `Attributes11`, `Attributes12`, `Attributes13`, `Attributes14`, `SpellID`, `VerifiedBuild`) VALUES (232724, 1, 39, 13, 1, 460954, 0, 0, 0, 0, 612370432, 0, 4, 1310720, 128, 0, 0, 0, 0, 1048576, 0, 0, 0, 0, 249014, 1);

-- Empowered Foe Breaker | Aggramar
DELETE FROM `spell_effect` WHERE `ID`=476673;
INSERT INTO `spell_effect` (`ID`, `Effect`, `EffectBasePoints`, `EffectIndex`, `EffectAura`, `DifficultyID`, `EffectAmplitude`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectDieSides`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `EffectPosFacing`, `EffectAttributes`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `ImplicitTarget1`, `ImplicitTarget2`, `SpellID`, `VerifiedBuild`) VALUES (476673, 6, 150, 2, 4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255060, 0);
REPLACE INTO hotfix_data SELECT ID, 4030871717, ID, 0, 0 FROM legion_hotfixes.spell_effect WHERE ID = 476673;

-- Foe Breaker | Aggramar
DELETE FROM `spell_effect` WHERE `ID`=371350;
INSERT INTO `spell_effect` (`ID`, `Effect`, `EffectBasePoints`, `EffectIndex`, `EffectAura`, `DifficultyID`, `EffectAmplitude`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectDieSides`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `EffectPosFacing`, `EffectAttributes`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `ImplicitTarget1`, `ImplicitTarget2`, `SpellID`, `VerifiedBuild`) VALUES (371350, 6, 150, 2, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 33, 0, 0, 0, 6, 0, 244291, 0);
REPLACE INTO hotfix_data SELECT ID, 4030871717, ID, 0, 0 FROM legion_hotfixes.spell_effect WHERE ID = 371350;

