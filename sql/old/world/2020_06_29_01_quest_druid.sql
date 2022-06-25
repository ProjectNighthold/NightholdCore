DELETE FROM `creature` WHERE `id` IN (113000,113002,113006); 
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES
('113000','1220','7558','7710','1','1','6581','0','0','3402.86','5748.86','310.383','4.63725','300','0','0','87','0','0','0','0','0','0','0','0','0','0','0','0','0','0'),
('113002','1220','7558','7710','1','1','6581','0','0','3559.22','5691.26','317.061','1.60245','300','0','0','87','0','0','0','0','0','0','0','0','0','0','0','0','0','0'),
('113006','1220','7558','7710','1','1','6581','0','0','3390.55','5657.93','313.325','1.04326','300','0','0','87','0','0','0','0','0','0','0','0','0','0','0','0','0','0');

DELETE FROM `creature_template` WHERE `entry` IN (113000,113002,113006); 
INSERT INTO `creature_template` (`entry`, `minlevel`, `maxlevel`, `ScaleLevelMin`, `ScaleLevelMax`, `ScaleLevelDuration`, `exp`, `faction`, `npcflag`, `WorldEffects`, `PassiveSpells`) VALUES 
('113000', '110', '110', '98', '110', '100', '6', '35', '16777216', '', ''),
('113002', '110', '110', '98', '110', '100', '6', '35', '16777216', '', ''), 
('113006', '110', '110', '98', '110', '100', '6', '35', '16777216', '', ''); 

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (113000,113002,113006); 
REPLACE INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`) VALUES 
('113000', '224870', '1'),
('113002', '224876', '1'), 
('113006', '224883', '1'); 

--  SAI
SET @ENTRY := 113000;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,73,0,100,0,1,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Npc_AI");

--  SAI
SET @ENTRY := 113002;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,73,0,100,0,1,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Npc_AI");

--  SAI
SET @ENTRY := 113006;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,73,0,100,0,1,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Npc_AI");

--  SAI
SET @ENTRY := 108027;
UPDATE `creature_template` SET `AIName`="SmartAI" , `scriptname` ="" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,6,0,100,1,0,0,0,0,205,92,51413,0,0,0,0,7,0,0,0,0,0,0,0,"On Death - CSC"),
(@ENTRY,0,1,2,61,0,100,1,0,0,0,0,12,108053,8,0,0,0,0,8,0,0,0,2067.69,5402.16,-34.7808,0.829174,"Link - Summon Creature"),
(@ENTRY,0,2,3,61,0,100,1,0,0,0,0,12,107385,8,0,0,0,0,8,0,0,0,2063.92,5403.93,-34.7028,0.715101,"Link - Summon Creature"),
(@ENTRY,0,3,4,61,0,100,1,0,0,0,0,50,250386,3600,0,0,0,0,8,0,0,0,2063.78,5403.75,-34.7747,0.7151,"Link - Summon GO"),
(@ENTRY,0,4,0,61,0,100,1,0,0,0,0,45,1,1,0,0,0,0,19,108028,0,0,0,0,0,0,"Link - Send Data");


