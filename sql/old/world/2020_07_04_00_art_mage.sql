-- Meryl Tormenta Vil SAI
SET @ENTRY := 102850;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,1,1,20,0,0,1,0,5000,0,0,0,0,18,80,0,0,0,0,0,0,"Player In Range - Say Text"),
(@ENTRY,0,1,0,52,0,100,1,0,102850,0,0,1,1,4000,0,0,0,0,1,0,0,0,0,0,0,0,"WP Reached - Say Text"),
(@ENTRY,0,2,4,52,0,100,1,1,102850,0,0,11,205450,0,0,0,0,0,18,50,0,0,0,0,0,0,"Text Over - Cast Spell"),
(@ENTRY,0,3,0,0,0,100,0,0,0,0,0,11,211578,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,102785,30,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,5,0,38,0,100,0,1,1,0,0,53,1,102850,0,0,0,0,1,0,0,0,0,0,0,0,"Update Data - Start WP"),
(@ENTRY,0,6,0,40,0,100,0,1,102850,0,0,11,182938,0,0,0,0,0,1,0,0,0,0,0,0,0,"WP Reached - Cast Spell");

-- Imagen de la archimaga Modera SAI
SET @ENTRY := 99313;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,7,60,0,100,1,0,0,0,0,1,0,6000,0,0,0,0,21,20,0,0,0,0,0,0,"Just Summoned - Say Text"),
(@ENTRY,0,1,0,52,0,100,1,0,99313,0,0,1,1,6000,0,0,0,0,7,0,0,0,0,0,0,0,"Text Over - Say Text"),
(@ENTRY,0,2,0,52,0,100,1,1,99313,0,0,1,2,6000,0,0,0,0,7,0,0,0,0,0,0,0,"Text Over - Say Text"),
(@ENTRY,0,3,0,52,0,100,1,2,99313,0,0,1,3,4000,0,0,0,0,7,0,0,0,0,0,0,0,"Text Over - Say Text"),
(@ENTRY,0,4,5,52,0,100,1,3,99313,0,0,33,99313,4000,0,0,0,0,18,30,0,0,0,0,0,0,"Text Over - Kill Credit"),
(@ENTRY,0,5,6,61,0,100,1,0,0,0,0,45,1,1,0,0,0,0,19,99309,5,0,0,0,0,0,"Link - Send Data"),
(@ENTRY,0,6,0,61,0,100,1,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Despawn"),
(@ENTRY,0,7,0,61,0,100,1,0,0,0,0,11,46598,0,0,0,0,0,19,99309,10,0,0,0,0,0,"Link - Cast Spell");

-- Mago Fuego Arma artefacto Felo melon
-- Archimaga Modera SAI
SET @ENTRY := 99398;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,1,10,300000,300000,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"PIR - Say Text"),
(@ENTRY,0,1,0,10,0,100,0,1,10,5000,5000,33,99396,0,0,0,0,0,7,0,0,0,0,0,0,0,"PIR - Kill Credit"),
(@ENTRY,0,2,0,19,0,100,0,40270,0,0,0,85,195454,0,0,0,0,0,7,0,0,0,0,0,0,0,"Quest Accept - Invoker Cast");

-- Aethas Atracasol SAI
SET @ENTRY := 99427;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,1,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,275.438,452.967,57.0549,0,"Just Summoned - MTP"),
(@ENTRY,0,1,2,61,0,100,1,0,0,0,0,11,195453,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Cast Spell"),
(@ENTRY,0,2,3,61,0,100,1,0,0,0,0,11,196708,0,0,0,0,0,7,0,0,0,0,0,0,0,"Link - Cast Spell"),
(@ENTRY,0,3,4,61,0,100,1,0,0,0,0,80,99427,2,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Run TS"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,207,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Link - Set Personal Invis");

-- Actionlist SAI
SET @ENTRY := 99427;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,61,0,100,1,55000,55000,0,0,33,99415,0,0,0,0,0,18,20,0,0,0,0,0,0,"TS - Kill Credit"),
(@ENTRY,9,1,0,61,0,100,1,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"TS - Despawn");

-- Aethas Atracasol SAI
SET @ENTRY := 99415;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,2,19,0,100,0,11997,0,0,0,1,0,2000,0,0,0,0,7,0,0,0,0,0,0,0,"Quest Accept - Say Text"),
(@ENTRY,0,1,3,52,0,100,0,0,99415,0,0,1,1,6000,0,0,0,0,7,0,0,0,0,0,0,0,"Text Over - Say Text"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,204,957,0,0,0,0,0,7,0,0,0,0,0,0,0,"Link - Set Scenario"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,12,99418,8,0,0,0,0,8,0,0,0,273.379,451.583,57.3796,1.66105,"Link - Summon Creature");

-- Portal de Aethas SAI
SET @ENTRY := 99418;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,73,0,100,1,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spell Click - Despawn"),
(@ENTRY,0,1,0,60,0,100,1,0,0,0,0,11,195453,0,0,0,0,0,1,0,0,0,0,0,0,0,"Just Summoned - Cast Spell");

-- Muro de hielo SAI
SET @ENTRY := 105377;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,6,0,100,1,0,0,0,0,9,0,0,0,0,0,0,15,248867,20,0,0,0,0,0,"On Death - Activate GO"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,205,92,47027,0,0,0,0,7,0,0,0,0,0,0,0,"Link - CSC"),
(@ENTRY,0,2,0,60,0,100,1,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Event Update - Set React");

-- Actionlist SAI
SET @ENTRY := 99615;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,1,3000,3000,0,0,1,0,5000,0,0,0,0,7,0,0,0,0,0,0,0,"TS - Say Text"),
(@ENTRY,9,1,0,0,0,100,1,5000,5000,0,0,1,1,0,0,0,0,0,21,70,0,0,0,0,0,0,"TS - Say Text"),
(@ENTRY,9,2,0,0,0,100,1,5000,5000,0,0,11,195739,0,0,0,0,0,1,0,0,0,0,0,0,0,"TS - Cast Spell"),
(@ENTRY,9,3,0,0,0,100,1,3000,3000,0,0,45,1,1,0,0,0,0,11,94164,50,0,0,0,0,0,"TS - Send Data");

-- Lyandra Caminante del Sol SAI
SET @ENTRY := 99615;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,1,1,1,0,0,80,99615,2,0,0,0,0,1,0,0,0,0,0,0,0,"Update Data - Run TS"),
(@ENTRY,0,1,0,38,0,100,1,2,2,0,0,1,2,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Update Data - Say Text"),
(@ENTRY,0,2,3,52,0,100,1,2,99615,0,0,11,196244,0,0,0,0,0,1,0,0,0,0,0,0,0,"Text Over - Cast Spell"),
(@ENTRY,0,3,4,61,0,100,1,0,0,0,0,12,99614,8,0,0,0,0,8,0,0,0,4550.06,2774.47,351.184,3.38069,"Link - Summon Creature"),
(@ENTRY,0,4,0,61,0,100,1,0,0,0,0,12,99614,8,0,0,0,0,8,0,0,0,4548.84,2768.63,351.184,3.27553,"Link - Summon Creature"),
(@ENTRY,0,5,0,38,0,100,1,3,3,0,0,1,3,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Update Data - Say Text"),
(@ENTRY,0,6,7,52,0,100,1,3,99615,0,0,11,196244,0,0,0,0,0,1,0,0,0,0,0,0,0,"Text Over - Cast Spell"),
(@ENTRY,0,7,8,61,0,100,1,0,0,0,0,12,99700,8,0,0,0,0,8,0,0,0,4571.1,2774.88,360.279,2.99384,"Link - Summon Creature"),
(@ENTRY,0,8,9,61,0,100,1,0,0,0,0,69,0,0,0,0,0,0,1,0,0,0,4635.41,2769.5,361.254,3.12543,"Link - MtP"),
(@ENTRY,0,9,10,61,0,100,1,0,0,0,0,9,0,0,0,0,0,0,15,245333,30,0,0,0,0,0,"Link - Activate GO"),
(@ENTRY,0,10,0,61,0,100,1,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Despawn"),
(@ENTRY,0,11,0,4,0,100,1,0,0,0,0,1,4,6000,0,0,0,0,1,0,0,0,0,0,0,0,"On Aggro - Say Text"),
(@ENTRY,0,12,0,52,0,100,1,4,99615,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Aggro - Say Text"),
(@ENTRY,0,13,0,0,0,100,0,3000,6000,8000,10000,11,198623,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,14,0,0,0,100,0,6000,9000,12000,15000,11,101381,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,15,0,0,0,100,1,0,80,0,0,11,196327,0,0,0,0,0,2,0,0,0,0,0,0,0,"On 80% HP - Cast Spell"),
(@ENTRY,0,16,0,0,0,100,1,0,20,0,0,11,196327,0,0,0,0,0,2,0,0,0,0,0,0,0,"On 20% HP - Cast Spell"),
(@ENTRY,0,17,18,2,0,100,1,0,50,0,0,75,61204,0,0,0,0,0,1,0,0,0,0,0,0,0,"On 50% HP - Set React"),
(@ENTRY,0,18,19,61,0,100,1,0,0,0,0,11,196262,3,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Cast Spell"),
(@ENTRY,0,19,20,61,0,100,1,0,0,0,0,11,195739,64,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Cast Spell"),
(@ENTRY,0,20,21,61,0,100,1,0,0,0,0,1,6,7000,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Say Text"),
(@ENTRY,0,21,22,61,0,100,1,0,0,0,0,45,1,1,0,0,0,0,19,98686,50,0,0,0,0,0,"Link - Send Data"),
(@ENTRY,0,23,0,52,0,100,1,6,99615,0,0,12,99763,8,0,0,0,0,8,0,0,0,4657.79,2785.37,361.19,5.38595,"Text Over - Summon Creature"),
(@ENTRY,0,24,25,38,0,100,1,4,4,0,0,1,7,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Update Data - Say Text"),
(@ENTRY,0,25,26,61,0,100,1,0,0,0,0,28,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Unaura"),
(@ENTRY,0,26,0,61,0,100,1,0,0,0,0,45,2,2,0,0,0,0,19,99763,50,0,0,0,0,0,"Link - Send Data"),
(@ENTRY,0,27,28,6,0,100,1,0,0,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Death - Say Text"),
(@ENTRY,0,28,29,61,0,100,1,0,0,0,0,12,103696,8,0,0,0,0,8,0,0,0,4641.81,2769.26,361.26,3.12898,"Link - Summon NPC"),
(@ENTRY,0,29,30,61,0,100,1,0,0,0,0,45,3,3,0,0,0,0,19,99763,50,0,0,0,0,0,"Link - Send Data"),
(@ENTRY,0,30,31,61,0,100,1,0,0,0,0,50,247494,3000,0,0,0,0,8,99763,50,0,4641.81,2769.26,362.64,3.12894,"Link - Sum GO"),
(@ENTRY,0,31,32,61,0,100,1,0,0,0,0,205,92,47380,0,0,0,0,7,0,0,0,0,0,0,0,"Link - CSC");

-- Necrófago explosivo SAI
SET @ENTRY := 99723;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,60,0,100,1,0,0,0,0,11,196232,0,0,0,0,0,1,0,0,0,0,0,0,0,"Event Update - Cast Spell"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,49,0,0,0,0,0,0,21,70,0,0,0,0,0,0,"Link - Start Attack"),
(@ENTRY,0,2,4,6,0,100,1,0,0,0,0,45,2,2,0,0,0,0,19,99615,100,0,0,0,0,0,"On Death - Send Data"),
(@ENTRY,0,3,0,6,0,100,1,0,0,0,0,11,198550,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Death - Cast Spell"),
(@ENTRY,0,4,0,61,0,100,1,0,0,0,0,205,92,47464,0,0,0,0,7,0,0,0,0,0,0,0,"Link - CSC");

-- Esqueleto ardiente SAI
SET @ENTRY := 99614;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,60,0,100,1,0,0,0,0,11,196223,0,0,0,0,0,1,0,0,0,0,0,0,0,"Event Update - Cast Spell"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,49,0,0,0,0,0,0,21,70,0,0,0,0,0,0,"Link - Start Attack"),
(@ENTRY,0,2,4,6,0,100,1,0,0,0,0,45,3,3,0,0,0,0,19,99615,100,0,0,0,0,0,"On Death - Send Data"),
(@ENTRY,0,3,0,0,0,100,0,3000,8000,5000,10000,11,198597,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,4,0,61,0,100,1,0,0,0,0,205,92,47464,0,0,0,0,7,0,0,0,0,0,0,0,"Link - CSC");

-- Hullahueso SAI
SET @ENTRY := 99700;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,60,0,100,1,0,0,0,0,11,196228,0,0,0,0,0,1,0,0,0,0,0,0,0,"Event Update - Cast Spell"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,49,0,0,0,0,0,0,21,70,0,0,0,0,0,0,"Link - Start Attack"),
(@ENTRY,0,2,0,0,0,100,1,0,0,0,0,11,201681,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,3,0,0,0,100,0,3000,8000,5000,10000,11,198603,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,4,0,6,0,100,1,0,0,0,0,205,92,47464,0,0,0,0,7,0,0,0,0,0,0,0,"On Death - CSC");

-- Aethas Atracasol SAI
SET @ENTRY := 99763;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,60,0,100,1,0,0,0,0,11,12980,0,0,0,0,0,1,0,0,0,0,0,0,0,"Event Update - Cast Spell"),
(@ENTRY,0,1,2,61,0,100,1,0,0,0,0,11,196561,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Cast Spell"),
(@ENTRY,0,2,0,61,0,100,1,0,0,0,0,11,196347,0,0,0,0,0,19,99615,50,0,0,0,0,0,"Link - Cast Spell"),
(@ENTRY,0,3,0,38,0,100,1,2,2,0,0,11,196381,0,0,0,0,0,1,0,0,0,0,0,0,0,"Update Data - Cast Spell"),
(@ENTRY,0,4,5,38,0,100,1,3,3,0,0,28,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Update Data - Cast Spell"),
(@ENTRY,0,5,6,61,0,100,1,0,0,0,0,53,1,99763,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Start WP"),
(@ENTRY,0,6,0,61,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Say Text"),
(@ENTRY,0,7,8,40,0,100,1,1,99763,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"WP Reached - Say Text"),
(@ENTRY,0,8,9,61,0,100,1,0,0,0,0,11,223908,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Cast Spell"),
(@ENTRY,0,9,10,61,0,100,1,0,0,0,0,12,99861,8,0,0,0,0,8,0,0,0,4625.47,2769.47,361.248,0,"Link - Cast Spell"),
(@ENTRY,0,10,0,61,0,100,1,0,0,0,0,11,196520,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Cast Spell");

-- Alasangre el Despierto SAI
SET @ENTRY := 98686;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,1,1,1,0,0,80,98686,2,0,0,0,0,1,0,0,0,0,0,0,0,"Update Data - Run TS"),
(@ENTRY,0,1,0,0,0,100,0,0,5000,15000,20000,11,198608,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,45,4,4,0,0,0,0,19,99615,80,0,0,0,0,0,"On Death - Send Data"),
(@ENTRY,0,3,0,2,0,100,1,0,35,0,0,11,196571,3,0,0,0,0,1,0,0,0,0,0,0,0,"On 35% HP - Cast Spell");

-- Actionlist SAI
SET @ENTRY := 98686;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,1,8000,8000,0,0,28,195699,0,0,0,0,0,1,0,0,0,0,0,0,0,"TS - Unaura"),
(@ENTRY,9,1,0,0,0,100,1,5000,5000,0,0,19,33555200,0,0,0,0,0,1,0,0,0,0,0,0,0,"TS - Remove UF"),
(@ENTRY,9,2,0,0,0,100,1,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"TS - Start Attack"),
(@ENTRY,9,3,0,0,0,100,1,0,0,0,0,1,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"TS - Start Attack");


-- Mago Arcano Artefacto Aluneth
-- Imagen de Kalec SAI
SET @ENTRY := 105917;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,33,104752,0,0,0,0,0,7,0,0,0,0,0,0,0,"Just Summoned - Kill Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Link - Say Text");

-- Príncipe-nexo Bilaal SAI
SET @ENTRY := 104399;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,1,0,0,0,0,80,104399,2,0,0,0,0,1,0,0,0,0,0,0,0,"Just Summoned - Run TS");

-- Actionlist SAI
SET @ENTRY := 104399;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,1,0,0,0,0,11,208110,0,0,0,0,0,1,0,0,0,0,0,0,0,"TS - Cast Spell"),
(@ENTRY,9,1,0,0,0,100,1,10000,10000,0,0,11,208111,0,0,0,0,0,1,0,0,0,0,0,0,0,"TS - Cast Spell"),
(@ENTRY,9,2,0,0,0,100,1,10000,10000,0,0,11,208112,0,0,0,0,0,1,0,0,0,0,0,0,0,"TS - Cast Spell"),
(@ENTRY,9,3,0,0,0,100,1,10000,10000,0,0,11,208113,0,0,0,0,0,1,0,0,0,0,0,0,0,"TS - Cast Spell"),
(@ENTRY,9,4,0,0,0,100,1,5000,5000,0,0,33,104765,0,0,0,0,0,18,30,0,0,0,0,0,0,"TS - Kill Credit");

-- Canalizador tocado por el Vacío SAI
SET @ENTRY := 104402;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,11,209315,0,0,0,0,0,19,104826,30,0,0,0,0,0,"Reset - Cast Spell"),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,33,104767,0,0,0,0,0,7,0,0,0,0,0,0,0,"On Death - Kill Credit"),
(@ENTRY,0,2,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,104828,30,0,0,0,0,0,"On Death - Dend Data"),
(@ENTRY,0,3,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,104826,30,0,0,0,0,0,"On Death - Dend Data"),
(@ENTRY,0,4,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,104819,30,0,0,0,0,0,"On Death - Dend Data");

-- Canalizador tocado por el Vacío SAI
SET @ENTRY := 106711;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,5000,3000,6000,11,209315,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,106747,50,0,0,0,0,0,"On Death - Send Data"),
(@ENTRY,0,2,0,6,0,100,0,0,0,0,0,45,5,5,0,0,0,0,19,104902,50,0,0,0,0,0,"On Death - Send Data");

-- Acechador-nexo tocado por el Vacío SAI
SET @ENTRY := 106710;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,5000,3000,6000,11,209308,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,1,0,25,0,100,0,0,0,500,500,49,0,0,0,0,0,0,19,106569,20,0,0,0,0,0,"OOC - Start Attack");

-- Azuregos SAI
SET @ENTRY := 106747;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,1,0,0,0,0,53,1,106747,0,0,0,0,7,0,0,0,0,0,0,0,"Just Summoned - Start WP"),
(@ENTRY,0,1,2,40,0,100,1,1,106747,0,0,206,2143,0,0,0,0,0,18,50,0,0,0,0,0,0,"WP Reached - Sum Convers"),
(@ENTRY,0,2,3,61,0,100,1,0,0,0,0,9,0,0,0,0,0,0,15,248515,30,0,0,0,0,0,"Link - Activate GO"),
(@ENTRY,0,3,0,61,0,100,1,0,0,0,0,29,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"Link - Follow Player"),
(@ENTRY,0,4,5,38,0,100,1,1,1,0,0,53,0,@ENTRY*100+00,0,0,0,0,1,0,0,0,0,0,0,0,"Update Data - Start WP"),
(@ENTRY,0,5,0,61,0,100,1,0,0,0,0,1,0,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Say Text"),
(@ENTRY,0,6,0,52,0,100,1,0,106747,0,0,1,1,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Text Over - Say Text"),
(@ENTRY,0,7,0,52,0,100,1,1,106747,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Text Over - Say Text"),
(@ENTRY,0,8,10,52,0,100,1,2,106747,0,0,1,3,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Text Over - Say Text"),
(@ENTRY,0,9,0,52,0,100,1,3,106747,0,0,11,207797,0,0,0,0,0,1,0,0,0,0,0,0,0,"Text Over - Cast Spell"),
(@ENTRY,0,10,11,61,0,100,1,0,0,0,0,11,211768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Cast Spell"),
(@ENTRY,0,11,0,61,0,100,1,0,0,0,0,205,92,49807,0,0,0,0,21,50,0,0,0,0,0,0,"Link - Complete Scenario Criteria"),
(@ENTRY,0,12,0,2,0,100,0,0,40,0,0,11,211765,1,0,0,0,0,1,0,0,0,0,0,0,0,"On 40% HP - Cast Spell"),
(@ENTRY,0,13,0,0,0,100,0,0,0,0,0,11,209856,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,15,16,38,0,100,1,3,3,0,0,206,1688,0,0,0,0,0,21,50,0,0,0,0,0,0,"Link - Sum Convers"),
(@ENTRY,0,16,0,61,0,100,1,0,0,0,0,29,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"Link - Follow"),
(@ENTRY,0,17,0,38,0,100,1,2,2,0,0,53,1,@ENTRY*100+01,0,0,0,0,1,0,0,0,0,0,0,0,"Update Data - Start WP"),
(@ENTRY,0,18,19,40,0,100,1,3,@ENTRY*100+01,0,0,1,4,10000,0,0,0,0,18,50,0,0,0,0,0,0,"WP Reached - Say Text"),
(@ENTRY,0,19,0,61,0,100,1,0,0,0,0,11,211763,0,0,0,0,0,21,50,0,0,0,0,0,0,"Link - Cast Spell"),
(@ENTRY,0,20,0,52,0,100,1,4,106747,0,0,1,5,5000,0,0,0,0,21,50,0,0,0,0,0,0,"Text Over - Say text"),
(@ENTRY,0,21,0,52,0,100,1,5,106747,0,0,1,6,7000,0,0,0,0,21,50,0,0,0,0,0,0,"Text Over - Say text"),
(@ENTRY,0,22,23,52,0,100,1,6,106747,0,0,1,7,5000,0,0,0,0,21,50,0,0,0,0,0,0,"Text Over - Say text"),
(@ENTRY,0,23,24,61,0,100,1,0,0,0,0,205,92,49809,0,0,0,0,21,50,0,0,0,0,0,0,"Link - Complete Scenario Criteria"),
(@ENTRY,0,24,25,61,0,100,1,0,0,0,0,12,104546,8,0,0,0,0,8,0,0,0,4197.23,7408.31,257.944,1.61278,"Link - Summon Creature"),
(@ENTRY,0,25,26,61,0,100,1,0,0,0,0,28,211725,0,0,0,0,0,21,50,0,0,0,0,0,0,"Link - Remove Aura"),
(@ENTRY,0,26,0,61,0,100,1,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Despawn");

-- Eco de Aluneth SAI
SET @ENTRY := 106706;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,5000,8000,15000,11,216901,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,6000,12000,11,209856,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,2,3,6,0,100,1,0,0,0,0,205,92,49808,0,0,0,0,7,0,0,0,0,0,0,0,"On Death - Complete Scenario Criteria"),
(@ENTRY,0,3,4,61,0,100,1,0,0,0,0,45,3,3,0,0,0,0,19,106747,50,0,0,0,0,0,"Link - Send Data"),
(@ENTRY,0,4,5,61,0,100,1,0,0,0,0,12,106710,8,0,0,0,0,8,0,0,0,4129.62,7460.69,266.844,3.81803,"Link - Summon Creature"),
(@ENTRY,0,5,6,61,0,100,1,0,0,0,0,12,106710,8,0,0,0,0,8,0,0,0,4130.2,7445.77,266.797,2.83959,"Link - Summon Creature"),
(@ENTRY,0,6,0,61,0,100,1,0,0,0,0,12,106711,8,0,0,0,0,8,0,0,0,4172.04,7467.85,265.403,2.29368,"Link - Summon Creature");

-- Canalizador tocado por el Vacío SAI
SET @ENTRY := 106711;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,5000,3000,6000,11,209315,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,106747,50,0,0,0,0,0,"On Death - Send Data"),
(@ENTRY,0,2,0,6,0,100,0,0,0,0,0,45,5,5,0,0,0,0,19,104902,50,0,0,0,0,0,"On Death - Send Data");


-- Meryl Tormenta Vil SAI
SET @ENTRY := 108097;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,10,0,100,1,1,20,0,0,205,92,51384,0,0,0,0,7,0,0,0,0,0,0,0,"Player In Range - Complete SC"),
(@ENTRY,0,1,2,61,0,100,1,1,20,0,0,1,0,8000,0,0,0,0,7,0,0,0,0,0,0,0,"Link - Say Text"),
(@ENTRY,0,2,0,61,0,100,1,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-404.591,8008.24,66.6802,0,"Link - Move To Position"),
(@ENTRY,0,3,4,52,0,100,1,0,108097,0,0,1,1,8000,0,0,0,0,7,0,0,0,0,0,0,0,"Text Over - Say Text"),
(@ENTRY,0,4,0,61,0,100,1,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-416.173,7998.82,66.6617,0,"Link - Move To Position"),
(@ENTRY,0,5,6,52,0,100,1,1,108097,0,0,1,2,8000,0,0,0,0,7,0,0,0,0,0,0,0,"Text Over - Say Text"),
(@ENTRY,0,6,0,61,0,100,1,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-433.767,8011.37,66.626,0,"Link - Move To Position"),
(@ENTRY,0,7,8,52,0,100,1,2,108097,0,0,1,3,8000,0,0,0,0,7,0,0,0,0,0,0,0,"Text Over - Say Text"),
(@ENTRY,0,8,13,61,0,100,1,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-427.482,8010.65,66.6379,0,"Link - Move To Position"),
(@ENTRY,0,9,0,52,0,100,1,3,108097,0,0,81,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Text Over - Set NPC Flag"),
(@ENTRY,0,10,11,62,0,100,1,19816,0,0,0,205,92,51386,0,0,0,0,7,0,0,0,0,0,0,0,"Gossip Select - Complete Scenario Criteria"),
(@ENTRY,0,11,12,61,0,100,1,0,0,0,0,1,4,8000,0,0,0,0,7,0,0,0,0,0,0,0,"Link - Say Text"),
(@ENTRY,0,12,0,61,0,100,1,0,0,0,0,85,214607,0,0,0,0,0,7,0,0,0,0,0,0,0,"Link - Invoker Cast"),
(@ENTRY,0,13,0,61,0,100,1,0,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Set NPC Flag"),
(@ENTRY,0,14,0,0,0,100,1,0,0,0,0,11,183081,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell");


-- Azuregos SAI
SET @ENTRY := 104546;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,73,0,100,1,0,0,0,0,62,1583,0,0,0,0,0,7,0,0,0,4226.59,7140.15,265.112,4.2545,"Spell Click - Teleport"),
(@ENTRY,0,1,2,60,0,100,1,0,0,0,0,80,104546,2,0,0,0,0,1,0,0,0,0,0,0,0,"Event Update - Run TS"),
(@ENTRY,0,2,3,40,0,100,1,1,104546,0,0,206,3471,0,0,0,0,0,21,50,0,0,0,0,0,0,"WP Reached - Summon Convers"),
(@ENTRY,0,3,4,61,0,100,1,0,0,0,0,11,223908,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Cast Spell"),
(@ENTRY,0,4,5,61,0,100,1,0,0,0,0,50,248553,0,0,0,0,0,8,0,0,0,4202.22,7084.17,268.199,2.81046,"Link - Sum GO"),
(@ENTRY,0,5,6,61,0,100,1,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Set NPC Flag"),
(@ENTRY,0,6,0,61,0,100,1,0,0,0,0,202,0,0,0,1,0,0,1,0,0,0,0,0,0,0,"Link - Disable Fly Mode");

-- Actionlist SAI
SET @ENTRY := 104546;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,1,0,0,0,0,11,207897,0,0,0,0,0,1,0,0,0,0,0,0,0,"TS - Cast spell"),
(@ENTRY,9,1,0,0,0,100,1,0,0,0,0,53,0,104546,0,0,0,0,1,0,0,0,0,0,0,0,"TS - Start WP"),
(@ENTRY,9,2,0,0,0,100,1,0,0,0,0,206,3470,0,0,0,0,0,21,50,0,0,0,0,0,0,"TS - Summon Convers"),
(@ENTRY,9,3,0,0,0,100,1,3000,3000,0,0,3,0,68826,0,0,0,0,1,0,0,0,0,0,0,0,"TS - Update Model");

-- Príncipe-nexo Bilaal SAI
SET @ENTRY := 106708;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,5000,5000,8000,11,209874,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,1,0,0,0,100,0,8000,12000,5000,8000,11,209869,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,2,0,2,0,100,0,0,80,0,0,11,209863,0,0,0,0,0,2,0,0,0,0,0,0,0,"On 80% HP - Cast Spell"),
(@ENTRY,0,3,0,2,0,100,0,0,50,0,0,11,209863,0,0,0,0,0,2,0,0,0,0,0,0,0,"On 50% HP - Cast Spell"),
(@ENTRY,0,4,0,2,0,100,0,0,20,0,0,11,209863,0,0,0,0,0,2,0,0,0,0,0,0,0,"On 20% HP - Cast Spell"),
(@ENTRY,0,5,6,6,0,100,0,0,0,0,0,205,92,49810,0,0,0,0,7,0,0,0,0,0,0,0,"On Death - Complete Scenario Criteria"),
(@ENTRY,0,6,0,61,0,100,1,0,0,0,0,12,104546,8,0,0,0,0,8,0,0,0,4219.38,7124.89,268.198,4.28748,"Link - Summon Creature");

-- Aluneth SAI
SET @ENTRY := 106756;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,60,0,100,0,0,0,8000,8000,1,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Event Update - Say Text"),
(@ENTRY,0,1,2,60,0,100,1,0,0,0,0,45,1,1,0,0,0,0,11,113142,60,0,0,0,0,0,"Event Update - Send Data"),
(@ENTRY,0,2,3,61,0,100,1,0,0,0,0,62,1583,0,0,0,0,0,21,60,0,0,1122.48,1048.06,312.513,3.13018,"Link - Teleport Player"),
(@ENTRY,0,3,4,61,0,100,1,0,0,0,0,50,249814,0,0,0,0,0,8,0,0,0,1117.78,1048.03,314.619,2.09636,"Link - Sum GO"),
(@ENTRY,0,4,5,61,0,100,1,0,0,0,0,50,248574,0,0,0,0,0,8,0,0,0,1152.58,1002.02,309.289,2.21201,"Link - Sum GO"),
(@ENTRY,0,5,6,61,0,100,1,0,0,0,0,28,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Unaura"),
(@ENTRY,0,6,0,61,0,100,1,0,0,0,0,1,1,0,0,0,0,0,21,60,0,0,0,0,0,0,"Link - Say Text");

-- Artefacto Escarcha
-- Glotonia SAI
SET @ENTRY := 107622;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,1,30,0,0,33,107612,0,0,0,0,0,7,0,0,0,0,0,0,0,"Player In range - Kill Credit"),
(@ENTRY,0,1,2,62,0,100,0,19778,0,0,0,1,2,5000,0,0,0,0,7,0,0,0,0,0,0,0,"Gossip Select - Say Text"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Cast Spell"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,33,107614,0,0,0,0,0,7,0,0,0,0,0,0,0,"Link - Kill Credit"),
(@ENTRY,0,4,0,52,0,100,0,2,107622,0,0,1,3,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Text Over - Say Text"),
(@ENTRY,0,5,0,62,0,100,0,19778,1,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talk"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,33,117002,0,0,0,0,0,7,0,0,0,0,0,0,0,"killcredit");

-- Maga eredar SAI
SET @ENTRY := 107800;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,60,0,100,1,0,0,0,0,49,0,0,0,0,0,0,18,30,0,0,0,0,0,0,"Event Update - Start Attack"),
(@ENTRY,0,1,2,6,0,100,1,0,0,0,0,45,3,3,0,0,0,0,19,107716,30,0,0,0,0,0,"On Death - Send Data"),
(@ENTRY,0,2,0,61,0,100,1,0,0,0,0,85,226138,0,0,0,0,0,7,0,0,0,0,0,0,0,"On Death - Send Data");

-- Meryl Tormenta Vil SAI
SET @ENTRY := 107976;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,10,0,100,1,1,20,0,0,11,214432,0,0,0,0,0,7,0,0,0,0,0,0,0,"Player In range - Cast Spell"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,80,107976,2,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Run TS");

-- Resguardo de atenuación vil SAI
SET @GUID := -369716;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= 107939;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,1,8,0,100,1,214283,0,0,0,11,214247,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spell Hit - Cast Spell"),
(@GUID,0,1,2,61,0,100,1,0,0,0,0,205,92,51383,0,0,0,0,7,0,0,0,0,0,0,0,"Link - Complete Scenario Criteria"),
(@GUID,0,2,3,61,0,100,1,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Set NPC Flag"),
(@GUID,0,3,4,61,0,100,1,0,0,0,0,12,107956,8,0,0,0,0,8,0,0,0,-355.118,8066.14,90.9201,3.16339,"Link - Summon Creature"),
(@GUID,0,4,5,61,0,100,1,0,0,0,0,12,107956,8,0,0,0,0,8,0,0,0,-339.76,8066.03,90.3854,2.38859,"Link - Summon Creature"),
(@GUID,0,5,6,61,0,100,1,0,0,0,0,12,107956,8,0,0,0,0,8,0,0,0,-346.806,8059,90.9201,4.77675,"Link - Summon Creature"),
(@GUID,0,6,0,61,0,100,1,0,0,0,0,12,107956,8,0,0,0,0,8,0,0,0,-344.906,8073.42,90.12,1.28449,"Link - Summon Creature");

-- Resguardo de atenuación vil SAI
SET @GUID := -369715;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= 107939;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,1,8,0,100,1,214283,0,0,0,11,214247,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spell Hit - Cast Spell"),
(@GUID,0,1,2,61,0,100,1,0,0,0,0,205,92,51383,0,0,0,0,7,0,0,0,0,0,0,0,"Link - Complete Scenario Criteria"),
(@GUID,0,2,3,61,0,100,1,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Set NPC Flag"),
(@GUID,0,3,4,61,0,100,1,0,0,0,0,12,107956,8,0,0,0,0,8,0,0,0,-472.535,7856.95,98.6776,3.16339,"Link - Summon Creature"),
(@GUID,0,4,5,61,0,100,1,0,0,0,0,12,107956,8,0,0,0,0,8,0,0,0,-457.177,7856.85,100.101,6.2481,"Link - Summon Creature"),
(@GUID,0,5,6,61,0,100,1,0,0,0,0,12,107956,8,0,0,0,0,8,0,0,0,-464.222,7849.81,100.302,4.77675,"Link - Summon Creature"),
(@GUID,0,6,0,61,0,100,1,0,0,0,0,12,107956,8,0,0,0,0,8,0,0,0,-462.323,7864.23,98.4331,0.641817,"Link - Summon Creature");

-- Resguardo de atenuación vil SAI
SET @GUID := -369714;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= 107939;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,1,8,0,100,1,214283,0,0,0,11,214247,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spell Hit - Cast Spell"),
(@GUID,0,1,2,61,0,100,1,0,0,0,0,205,92,51383,0,0,0,0,7,0,0,0,0,0,0,0,"Link - Complete Scenario Criteria"),
(@GUID,0,2,3,61,0,100,1,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Set NPC Flag"),
(@GUID,0,3,4,61,0,100,1,0,0,0,0,12,107956,8,0,0,0,0,8,0,0,0,-325.606,7847.7,98.6107,3.16339,"Link - Summon Creature"),
(@GUID,0,4,5,61,0,100,1,0,0,0,0,12,107956,8,0,0,0,0,8,0,0,0,-310.248,7847.59,98.4813,6.2481,"Link - Summon Creature"),
(@GUID,0,5,6,61,0,100,1,0,0,0,0,12,107956,8,0,0,0,0,8,0,0,0,-317.293,7840.56,99.0239,4.77675,"Link - Summon Creature"),
(@GUID,0,6,0,61,0,100,1,0,0,0,0,12,107956,8,0,0,0,0,8,0,0,0,-315.394,7854.98,98.467,1.28449,"Link - Summon Creature");

-- Maga de almas eredar SAI
SET @ENTRY := 107742;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,60,0,100,1,0,0,0,0,49,0,0,0,0,0,0,18,100,0,0,0,0,0,0,"Event Update - Start Attack"),
(@ENTRY,0,1,0,0,0,100,0,0,0,5000,5000,11,202420,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell");

-- Balaadur SAI
SET @ENTRY := 108168;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,50,0,0,1,4,0,0,0,0,0,2,0,0,0,0,0,0,0,"On 50 % HP - Say Text"),
(@ENTRY,0,1,0,0,0,100,0,2000,2000,5000,5000,11,202420,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,5000,5000,11,202290,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Spell"),
(@ENTRY,0,4,5,6,0,100,1,0,0,0,0,50,251049,3600,0,0,0,0,8,0,0,0,-4384.41,471.078,435.011,4.90771,"On Death - Sum GO"),
(@ENTRY,0,5,0,61,0,100,1,0,0,0,0,12,108202,8,0,0,0,0,8,0,0,0,-4384.41,471.078,435.011,4.90771,"Link - Sum NPC"),
(@ENTRY,0,6,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"On Aggro - Say Text"),
(@ENTRY,0,7,8,6,0,100,1,0,0,0,0,205,92,51391,0,0,0,0,7,0,0,0,0,0,0,0,"On Death - Complete Scenario Criteria");

