/*https://es.wowhead.com/quest=38347/esquinazo-con-sargazo */
DELETE FROM `creature_questender` WHERE `quest` IN (38347);
INSERT INTO `creature_questender`(id, quest) VALUES
(97419, 38347);


/* https://es.wowhead.com/npc=73877/jarrod-hamby spawn npc */

DELETE FROM `creature` WHERE `guid` = 6700011 AND `id`= 73877;
INSERT INTO `creature` ( `guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3` ) VALUES
( "6700011", "73877", "1116", "6719", "7470", "1", "1", "", "0", "0", "1997.95", "-936.014", "32.2343", "4.51096", "300", "0", "0", "46975", "7400", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");
 
/* https://es.wowhead.com/quest=36679/asalto-al-nidal-marea-oscura retiro de aura al npc */
DELETE FROM `creature_template_addon` WHERE `entry` IN (78148);
INSERT INTO  `creature_template_addon`(`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
("78148", "0", "0", "0", "1", "0", "");