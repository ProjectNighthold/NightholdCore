DELETE FROM `spell` WHERE `ID` = 305306;
INSERT INTO `spell` (`ID`, `Name`, `NameSubtext`, `VerifiedBuild`) VALUES
(305306, 'Baldazzar\'s buff', 'Increase your healing done by $w1%.\r\nIncrease your damage done by $w2%.\r\nIncrease your speed by $w3%.\r\n', 1);
UPDATE `spell` SET `Description` = `NameSubtext`, `AuraDescription` = `NameSubtext` WHERE `ID` = 305306;

DELETE FROM `spell_effect` WHERE `ID` IN (900000, 900001, 900002);
INSERT INTO `spell_effect` (`ID`, `EffectIndex`, `Effect`, `EffectBasePoints`, `EffectAura`, `EffectMiscValue1`, `EffectMiscValue2`, `ImplicitTarget1`, `SpellID`) VALUES
(900000, 0, 6, 100, 118, 0,     0,    25, 305306),
(900001, 1, 6, 700, 79,  127,   3000, 25, 305306),
(900002, 2, 6, 100, 31,  0,     0,    25, 305306);

DELETE FROM `spell_misc` WHERE `ID` = 680001;
INSERT INTO `spell_misc` (`ID`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SpellIconFileDataID`, `Attributes1`, `Attributes2`, `Attributes3`, `Attributes4`, `Attributes6`, `Attributes9`, `SpellID`) VALUES
(680001, 1, 21, 13, 132864, -2147483648, 0x20, 0x5, 0x100000, 0x400, 0x1000, 305306);

DELETE FROM `hotfix_data` WHERE Id BETWEEN 2344524 AND 2344528;
INSERT INTO `hotfix_data` VALUES
(2344524, 0xE111669E, 305306, 0, 0),
(2344525, 0xF04238A5, 900000, 0, 0),
(2344526, 0xF04238A5, 900001, 0, 0),
(2344527, 0xF04238A5, 900002, 0, 0),
(2344528, 0xC603EE28, 680001, 0, 0);
