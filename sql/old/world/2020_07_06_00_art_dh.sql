-- Altruis el Sufridor SAI
SET @ENTRY := 99254;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,40816,0,0,0,85,201092,0,0,0,0,0,7,0,0,0,0,0,0,0,"Quest Accept - Invoker Cast Spell"),
(@ENTRY,0,1,0,62,0,100,0,19214,0,0,0,85,201092,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gossip Select - Invoker Cast Spell"),
(@ENTRY,0,2,0,19,0,100,0,40819,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Quest Accept - Talk"),
(@ENTRY,0,3,0,19,0,100,0,41803,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Quest Accept - Talk");

-- Kayn Furia del Sol SAI
SET @ENTRY := 94902;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,1,1,5,0,0,69,0,0,0,0,0,0,8,0,0,0,1300.85,-261.126,44.266,0,"PIR - MTP"),
(@ENTRY,0,1,0,20,0,100,1,39051,0,0,0,11,201108,0,0,0,0,0,1,0,0,0,0,0,0,0,"QR - CS");

-- Celador Alturas SAI
SET @ENTRY := 96313;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,19303,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"GS - ST"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Link - CG"),
(@ENTRY,0,2,1,62,0,100,0,19304,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"GS - ST"),
(@ENTRY,0,3,4,62,0,100,0,19304,1,0,0,1,2,6000,0,0,0,0,7,0,0,0,0,0,0,0,"GS - ST"),
(@ENTRY,0,4,6,61,0,100,0,0,0,0,0,33,96313,0,0,0,0,0,7,0,0,0,0,0,0,0,"Link - KC"),
(@ENTRY,0,5,7,52,0,100,0,2,96313,0,0,85,188163,0,0,0,0,0,7,0,0,0,0,0,0,0,"TO - ICS"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Set NPC Flag"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Set NPC Flag"),
(@ENTRY,0,8,0,60,0,100,1,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"EU - Set NPC Flag"),
(@ENTRY,0,9,11,10,0,100,1,1,6,0,0,53,0,96313,0,0,0,0,21,6,0,0,0,0,0,0,"PIR - SWP"),
(@ENTRY,0,10,12,10,0,100,1,1,30,0,0,1,3,0,0,0,0,0,21,30,0,0,0,0,0,0,"PIR - SWP"),
(@ENTRY,0,11,0,61,0,100,1,0,0,0,0,1,4,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Link - ST"),
(@ENTRY,0,12,0,61,0,100,1,0,0,0,0,45,1,1,0,0,0,0,11,96312,25,0,0,0,0,0,"Link - SD"),
(@ENTRY,0,13,0,40,0,100,1,4,96313,0,0,11,201103,0,0,0,0,0,1,0,0,0,0,0,0,0,"On WP - CS"),
(@ENTRY,0,14,0,40,0,100,1,8,96313,0,0,45,1,1,0,0,0,0,11,94731,50,0,0,0,0,0,"On WP - SD"),
(@ENTRY,0,15,16,40,0,100,1,10,96313,0,0,1,5,6000,0,0,0,0,1,0,0,0,0,0,0,0,"On WP - ST"),
(@ENTRY,0,16,0,61,0,100,1,0,0,0,0,11,190972,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - CS"),
(@ENTRY,0,17,21,52,0,100,1,5,96313,0,0,1,6,4000,0,0,0,0,1,0,0,0,0,0,0,0,"TO - ST"),
(@ENTRY,0,18,19,52,0,100,1,6,96313,0,0,45,2,2,0,0,0,0,11,94731,50,0,0,0,0,0,"Link - SD"),
(@ENTRY,0,19,20,61,0,100,1,0,0,0,0,11,195453,0,0,0,0,0,1,0,0,0,0,0,0,0,"TO - CS"),
(@ENTRY,0,20,0,61,0,100,1,0,0,0,0,41,1500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Despawn"),
(@ENTRY,0,21,0,61,0,100,1,0,0,0,0,9,0,0,0,0,0,0,15,246993,30,0,0,0,0,0,"Link - Activate GO");

-- Guardia del Bastión Violeta SAI
SET @ENTRY := 96312;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,1,1,1,0,0,53,1,96312,0,0,0,0,1,0,0,0,0,0,0,0,"UD - SWP"),
(@ENTRY,0,1,0,40,0,100,1,1,96312,0,0,9,0,0,0,0,0,0,15,247002,30,0,0,0,0,0,"Link - Activate GO");

-- Taldath el Destructor SAI
SET @ENTRY := 94731;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,1,1,1,0,0,1,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"UD - ST"),
(@ENTRY,0,1,0,38,0,100,1,2,2,0,0,1,1,3000,0,0,0,0,1,0,0,0,0,0,0,0,"UD - ST"),
(@ENTRY,0,2,0,52,0,100,1,1,94731,0,0,53,0,94731,0,0,0,0,1,0,0,0,0,0,0,0,"TO - SWP"),
(@ENTRY,0,3,4,40,0,100,1,1,94731,0,0,19,33536,0,0,0,0,0,1,0,0,0,0,0,0,0,"WPR - RUF"),
(@ENTRY,0,4,5,61,0,100,1,0,0,0,0,11,191030,0,0,0,0,0,21,50,0,0,0,0,0,0,"Link - CS"),
(@ENTRY,0,5,7,61,0,100,1,0,0,0,0,1,2,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Link - ST"),
(@ENTRY,0,6,8,52,0,100,1,2,94731,0,0,11,191028,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - ST"),
(@ENTRY,0,7,0,61,0,100,1,0,0,0,0,97,20,20,0,0,0,0,8,0,0,0,1362.98,-263.514,38.6569,3.08465,"Link - JTP"),
(@ENTRY,0,8,0,61,0,100,1,0,0,0,0,80,94731,2,0,0,0,0,1,0,0,0,0,0,0,0,"Link - RTS"),
(@ENTRY,0,9,0,6,0,100,1,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"OD - ST");

-- Actionlist SAI
SET @ENTRY := 94731;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,1,0,0,0,0,11,201105,0,0,0,0,0,1,0,0,0,0,0,0,0,"TS - CS"),
(@ENTRY,9,1,0,0,0,100,1,6000,6000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"TS - ST"),
(@ENTRY,9,2,0,0,0,100,1,6000,6000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"TS - ST"),
(@ENTRY,9,3,0,0,0,100,1,6000,6000,0,0,11,201106,0,0,0,0,0,1,0,0,0,0,0,0,0,"TS - CS");

-- Archimago Khadgar SAI
SET @ENTRY := 90417;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,-844.172,4666.63,767.58,0,"Just Summoned - Move To Position"),
(@ENTRY,0,1,12,61,0,100,0,0,0,0,0,1,0,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Say Text"),
(@ENTRY,0,2,0,34,0,100,0,0,1,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"WP Reached - Say Text"),
(@ENTRY,0,3,0,52,0,100,0,1,90417,0,0,69,2,0,0,0,0,0,8,0,0,0,-833.524,4661.14,767.688,0,"Text Over - Move To Position"),
(@ENTRY,0,4,0,34,0,100,0,0,2,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"WP Reached - Say Text"),
(@ENTRY,0,5,0,52,0,100,0,2,90417,0,0,1,3,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Text Over - Say Text"),
(@ENTRY,0,6,0,52,0,100,0,3,90417,0,0,69,3,0,0,0,0,0,8,0,0,0,-829.136,4654.21,767.658,0,"Text Over - Move To Position"),
(@ENTRY,0,7,0,34,0,100,0,0,3,0,0,1,4,5000,0,0,0,0,1,0,0,0,0,0,0,0,"WP Reached - Say Text"),
(@ENTRY,0,8,10,52,0,100,0,4,90417,0,0,1,5,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Text Over - Say Text"),
(@ENTRY,0,9,14,52,0,100,0,5,90417,0,0,1,6,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Text Over - Say Text"),
(@ENTRY,0,10,11,61,0,100,0,0,0,0,0,33,90417,0,0,0,0,0,18,20,0,0,0,0,0,0,"Link - Kill Credit"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,50,248521,60,0,0,0,0,8,0,0,0,-829.306,4652.83,768.774,0,"Link - Summon GO"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Set NPC Flag"),
(@ENTRY,0,13,0,19,0,100,0,41804,0,0,0,12,90417,2,300000,0,0,0,1,0,0,0,0,0,0,0,"Quest Accept - Summon Creature"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Despawn"),
(@ENTRY,0,15,0,62,0,100,0,18558,5,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,""),
(@ENTRY,0,16,0,10,0,100,1,1,15,0,0,1,9,0,0,0,0,0,7,0,0,0,0,0,0,0,"Text Over - Say Text"),
(@ENTRY,0,17,0,19,0,100,0,39986,0,0,0,1,10,0,0,0,0,0,7,0,0,0,0,0,0,0,"Text Over - Say Text"),
(@ENTRY,0,18,0,19,0,100,0,39987,0,0,0,1,11,0,0,0,0,0,7,0,0,0,0,0,0,0,"Text Over - Say Text"),
(@ENTRY,0,19,0,62,0,100,0,18558,6,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Actions_smart"),
(@ENTRY,0,20,0,19,0,100,0,45904,0,0,0,85,234765,0,0,0,0,0,7,0,0,0,0,0,0,0,"QA - ICS"),
(@ENTRY,0,30,0,20,0,100,0,43341,0,0,0,85,237707,0,0,0,0,0,7,0,0,0,0,0,0,0,"QR - ICS");

-- Jace Tejeoscuro SAI
SET @ENTRY := 99262;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,41807,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Quest Reward - Talk");

-- Actionlist SAI
SET @ENTRY := 104909;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,1,10000,10000,0,0,33,104908,0,0,0,0,0,18,20,0,0,0,0,0,0,"TS - Kill Credit");
-- Allari la Devoraalmas SAI
SET @ENTRY := 104909;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,85,207762,0,0,0,0,0,1,0,0,0,0,0,0,0,"Just Summoned - Invoker Cast"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,80,104909,2,0,0,0,0,1,0,0,0,0,0,0,0,"Link - Run TS");

-- Aparecido Aldrachi SAI
SET @ENTRY := 105151;
UPDATE `creature_template` SET `AIName`="SmartAI"  WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,100,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"HAVOC"),
(@ENTRY,0,1,0,0,0,100,0,11000,13000,11000,13000,11,216020,0,0,0,0,0,2,0,0,0,0,0,0,0,"HAVOC"),
(@ENTRY,0,2,0,0,0,100,1,700,800,7000,8000,11,208186,0,0,0,0,0,2,0,0,0,0,0,0,0,"HAVOC");