/* Evento portal al vacio de los Demon hunter */


/* Apariencia de la Celadora de hierro DH */
DELETE FROM `creature_loot_template` WHERE (`entry`='112375');
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES ('112375', '139550', '7', '0', '0', '1', '1', '0');
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES ('112375', '141960', '34', '0', '0', '1', '1', '0');
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES ('112375', '141959', '32', '0', '0', '1', '1', '0');
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES ('112375', '141961', '31', '0', '0', '1', '1', '0');
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES ('112375', '141958', '30', '0', '0', '1', '1', '0');
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES ('112375', '141962', '28', '0', '0', '1', '1', '0');

UPDATE `creature_template` SET `faction`='16' WHERE (`entry`='112375');
UPDATE `creature` SET `PhaseId`='7606' WHERE (`guid`='11840002');

--  SAI
SET @DemonPC := 114816;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@DemonPC;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@DemonPC AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@DemonPC,0,0,0,73,0,100,0,0,0,0,0,12,112375,7,0,1,0,0,8,0,0,0,1561.65,1412.92,176.433,4.72413,"Npc - Event - Action (phase) (dungeon difficulty)");
