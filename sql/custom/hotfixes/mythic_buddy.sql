-- Custom mythic melper buddy
-- Part 1 - Hotfix
-- Spell
DELETE FROM `spell` WHERE `ID`=305307;
INSERT INTO `spell` (`ID`, `Name`, `NameSubtext`, `Description`, `AuraDescription`, `VerifiedBuild`) VALUES (305307, 'Mythic+ Ally', NULL, 'Calls forth a Mythic Helper  to fight at your side', NULL, 4200);
DELETE FROM `spell_effect` WHERE `ID`=900100;
INSERT INTO `spell_effect` (`ID`, `Effect`, `EffectBasePoints`, `EffectIndex`, `EffectAura`, `DifficultyID`, `EffectAmplitude`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectDieSides`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `EffectPosFacing`, `EffectAttributes`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `ImplicitTarget1`, `ImplicitTarget2`, `SpellID`, `VerifiedBuild`) VALUES (900100, 28, 110, 0, 0, 0, 99999, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 4200000, 2141, 15, 0, 32, 0, 305307, 0);
DELETE FROM `spell_misc` WHERE `ID`=900100;
INSERT INTO `spell_misc` (`ID`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellIconFileDataID`, `Speed`, `ActiveIconFileDataID`, `LaunchDelay`, `DifficultyID`, `Attributes1`, `Attributes2`, `Attributes3`, `Attributes4`, `Attributes5`, `Attributes6`, `Attributes7`, `Attributes8`, `Attributes9`, `Attributes10`, `Attributes11`, `Attributes12`, `Attributes13`, `Attributes14`, `SpellID`, `VerifiedBuild`) VALUES (900100, 1, 21, 1, 1, 134539, 0, 0, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0, 0, 0, 0, 0, 0, 0, 305307, 0);
DELETE FROM `spell_levels` WHERE `ID`=305307;
INSERT INTO `spell_levels` (`ID`, `BaseLevel`, `MaxLevel`, `SpellLevel`, `DifficultyID`, `MaxPassiveAuraLevel`, `SpellID`, `VerifiedBuild`) VALUES (305307, 110, 0, 110, 0, 0, 305307, 4200);

-- Hotfix data
REPLACE INTO `hotfix_data` 													(`Id`		, `TableHash`	, `RecordID`, `Timestamp`	, `Deleted`	)
VALUES 																				(4000009	, 3776013982	, 305307		, 0				, 0			),
																						(4000010	, 4030871717	, 900100		, 0				, 0			),
																						(4000011	, 3322146344	, 900100		, 0				, 0			),
																						(4000012	, 501138918		, 305307		, 0				, 0			);
