-- Arreglado x PEGA-PEGA(WoW-Legion)
-- Expansion (...)
-- Reliquias profanadas (id-14333)


-- QuestID[14333]: Reliquias profanadas
-- ItemID[49194]: Reliquia profana
-- ObjectID[196395]: Defiled Relic


/*El loteo estaba x -100 x eso no daba el item. En el delete puse un solo valor puesto a que ese es el unico con ese entry*/
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance`='100' WHERE (`entry`='196395') AND (`item`='49194');
UPDATE `gameobject_loot_template` SET `lootmode`='1' WHERE (`entry`='196395') AND (`item`='49194');
DELETE FROM `gameobject_template` WHERE `entry`= 196395;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `unkInt32`, `AIName`, `ScriptName`, `WorldEffectID`, `StateWorldEffectID`, `SpellVisualID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `MaxVisible`, `IgnoreDynLos`, `MinGold`, `MaxGold`, `VerifiedBuild`) VALUES ('196395', '3', '406', 'Defiled Relic', '', '', '', '0', '0', '2', '49194', '0', '0', '0', '0', '0', '5', '49194', '1200', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1');
