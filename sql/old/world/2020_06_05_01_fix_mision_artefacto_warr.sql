/* repara loot y spawn de objeto misiones de war sede de classe mision Artefacto*/ 
/* https://www.wowhead.com/object=252879*/
DELETE FROM `gameobject` WHERE `guid`="900001" AND `id`="252879";
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `AiID`, `state`, `isActive`, `personal_size`) VALUES
("900001", "252879", "1220", "7637", "8222", "1", "65535", "", "2610.51", "4725.94", "262.888", "0.648222", "-0", "-0", "-0.318466", "-0.947934", "300", "0", "0", "1", "0", "0");
DELETE FROM gameobject_loot_template WHERE entry IN(252879);
INSERT INTO gameobject_loot_template (entry, item, ChanceOrQuestChance, lootmode, groupid, mincountOrRef, maxcount) VALUES
(252879, 140131, 100, 1, 0, 1, 1);
/* https://pt.wowhead.com/object=252878/a-era-de-galakrond objeto de mision */
DELETE FROM `gameobject` WHERE `guid`="900002" AND `id`="252878";
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `AiID`, `state`, `isActive`, `personal_size`)VALUES
("900002", "252878", "1501", "7805", "7805", "2", "1", "", "3196.9", "7456.38", "29.3146", "3.26398", "-0", "-0", "-0.998128", "0.0611546", "300", "0", "0", "1", "0", "0");
DELETE FROM gameobject_loot_template WHERE entry IN(252878);
INSERT INTO gameobject_loot_template (entry, item, ChanceOrQuestChance, lootmode, groupid, mincountOrRef, maxcount) VALUES
(252878, 140132, 100, 1, 0, 1, 1);
/* https://pt.wowhead.com/object=252877/as-tribos-belicosas-e-a-ascens%C3%A3o-de-arathor objeto de mision */
DELETE FROM gameobject_template WHERE entry IN (252877);
INSERT INTO gameobject_template (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `unkInt32`, `AIName`, `ScriptName`, `WorldEffectID`, `StateWorldEffectID`, `SpellVisualID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `MaxVisible`, `IgnoreDynLos`, `MinGold`, `MaxGold`, `VerifiedBuild`)values
("252877", "3", "36036", "Las tribus bélicas y el auge de arathor", "openhandglow", "Extracción", "", "0", "0", "1", "140130", "0", "0", "0", "0", "0", "1691", "0", "0", "0", "1", "1", "0", "0", "0", "0", "0", "0", "0", "0", "23645", "0", "1", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "67966", "1", "0", "0", "", "", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "1");
DELETE FROM `gameobject` WHERE `guid`="900003" AND `id`="252877";
INSERT INTO gameobject (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `AiID`, `state`, `isActive`, `personal_size`) VALUES
("900003", "252877", "1001", "6052", "6052", "2", "1", "", "1298.46", "532.904", "14.1407", "1.71452", "-0", "-0", "-0.756052", "-0.654511", "300", "0", "0", "1", "0", "0");
DELETE FROM gameobject_loot_template WHERE entry IN(252877);
INSERT INTO gameobject_loot_template (entry, item, ChanceOrQuestChance, lootmode, groupid, mincountOrRef, maxcount) VALUES
(252877, 140130, 100, 1, 0, 1, 1);
/*spawn https://es.wowhead.com/npc=105637/rosa-la-ce%C3%B1uda#screenshots:id=617497 necesario para mision artefacto */
DELETE FROM `creature` WHERE `guid`="670032" AND `id`="105637";
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) values
("670032", "105637", "0", "5287", "35", "1", "1", "", "0", "0", "-14389.9", "420.1", "7.45013", "2.28963", "300", "0", "0", "8314136", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");

/* traduccion de mision para locales esMX*/
DELETE FROM quest_template_locale WHERE `ID` = "43826";
INSERT INTO quest_template_locale (`ID`, `locale`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `QuestCompletionLog`, `VerifiedBuild`) VALUES
("43826", "esMX", "Historia secreta", "Usa las notas de exploración para localizar y recuperar los 4 tomos antiguos que Fjornson necesita para comenzar a investigar tu artefacto..", "Empuñas un acero antiguo, reforzado por una magia que apenas comprendemos.
Si de verdad quieres desbloquear el potencial de tus armas, debes saber más sobre cómo se forjaron y las batallas en las que participaron. Puedo ayudarte.
Tus razas guardan sus historias en libros y necesitaré algunos para recomponer la leyenda de tu acero. Le pedí a una de tus seguidoras que me buscara sus ubicaciones. Aquí tienes sus notas.", "", "", "", "", "", "", "21737");
