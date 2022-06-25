DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = '13' AND `SourceEntry` = '108627' AND `ElseGroup` = '0' AND `ConditionValue2` = '57207';
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = '13' AND `SourceEntry` = '108627' AND `ElseGroup` = '1' AND `ConditionValue2` = '59498';
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = '13' AND `SourceEntry` = '108627' AND `ElseGroup` = '2' AND `ConditionValue2` = '57742';
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,  `ErrorTextId`,`ScriptName`,`Comment`) VALUES 
('13', '1', '108627', '0', '0', '31', '0', '3', '57207', '0', '0', '0', '', 'Ox Cart Rope Left target Nourished Yak'),
('13', '1', '108627', '0', '1', '31', '0', '3', '59498', '0', '0', '0', '', 'Ox Cart Rope Left target Nourished Yak'),
('13', '1', '108627', '0', '2', '31', '0', '3', '57742', '0', '0', '0', '', 'Ox Cart Rope Left target Nourished Yak');

UPDATE `creature_template` SET `faction`='35' WHERE (`entry`='59498');
UPDATE `creature_template` SET `ScriptName`='npc_nourished_yak' WHERE (`entry`='59498');

DELETE FROM `script_waypoint` WHERE `entry` = 57207;
INSERT INTO `script_waypoint`  (`entry`,`pointid`,`location_x`,`location_y`,`location_z`,`point_comment`) VALUES 
('57207', '1', '977.016', '2848.52', '87.2352', ''),
('57207', '2', '947.266', '2835.52', '87.2352', ''),
('57207', '3', '918.016', '2825.02', '87.2352', ''),
('57207', '4', '894.766', '2811.27', '86.9852', ''),
('57207', '5', '879.766', '2807.02', '83.9852', ''),
('57207', '6', '852.516', '2799.02', '83.7352', ''),
('57207', '7', '824.516', '2790.77', '78.7352', ''),
('57207', '8', '801.266', '2785.27', '76.7352', ''),
('57207', '9', '789.266', '2792.77', '75.7352', ''),
('57207', '10', '762.016', '2815.52', '76.2352', ''),
('57207', '11', '745.766', '2834.77', '75.7352', ''),
('57207', '12', '745.266', '2851.77', '75.9852', ''),
('57207', '13', '754.516', '2869.77', '75.2352', ''),
('57207', '14', '752.516', '2890.02', '74.9852', ''),
('57207', '15', '731.766', '2915.02', '74.7352', ''),
('57207', '16', '702.766', '2939.02', '74.7352', ''),
('57207', '17', '682.766', '2954.77', '75.2352', ''),
('57207', '18', '673.016', '2975.52', '74.9852', ''),
('57207', '19', '665.266', '2983.27', '75.2352', ''),
('57207', '20', '659.516', '2990.77', '79.9852', ''),
('57207', '21', '650.266', '2999.52', '74.9852', ''),
('57207', '22', '643.016', '3006.27', '74.7352', ''),
('57207', '23', '629.016', '3016.52', '75.4852', ''),
('57207', '24', '616.016', '3035.52', '76.7352', ''),
('57207', '25', '611.766', '3061.27', '80.4852', ''),
('57207', '26', '611.766', '3080.27', '84.4852', ''),
('57207', '27', '617.01', '3107.21', '87.5104', ''),
('57207', '28', '616.01', '3131.96', '87.7604', ''),
('57207', '29', '606.01', '3143.96', '88.0104', '');

DELETE FROM `script_waypoint` WHERE `entry` = 59498;
INSERT INTO `script_waypoint`  (`entry`,`pointid`,`location_x`,`location_y`,`location_z`,`point_comment`) VALUES 
('59498', '1', '582.076', '3153.46', '88.2618', ''),
('59498', '2', '573.326', '3149.96', '86.7618', ''),
('59498', '3', '558.076', '3156.96', '79.2618', ''),
('59498', '4', '548.076', '3172.46', '77.5118', ''),
('59498', '5', '545.076', '3197.46', '77.5118', ''),
('59498', '6', '538.076', '3210.71', '76.5118', ''),
('59498', '7', '517.826', '3224.96', '74.5118', ''),
('59498', '8', '508.076', '3244.71', '76.5118', ''),
('59498', '9', '508.076', '3265.46', '77.7618', ''),
('59498', '10', '512.326', '3291.21', '74.5118', ''),
('59498', '11', '520.076', '3315.21', '73.5118', ''),
('59498', '12', '524.326', '3323.96', '77.7618', ''),
('59498', '13', '527.326', '3328.71', '78.2618', ''),
('59498', '14', '532.076', '3336.46', '73.7618', ''),
('59498', '15', '543.576', '3355.71', '76.7618', ''),
('59498', '16', '555.076', '3366.96', '78.5118', ''),
('59498', '17', '568.326', '3375.71', '80.5118', ''),
('59498', '18', '608.076', '3383.46', '87.0118', ''),
('59498', '19', '635.076', '3392.21', '93.2618', ''),
('59498', '20', '653.076', '3404.96', '99.0118', ''),
('59498', '21', '675.576', '3427.21', '106.762', ''),
('59498', '22', '685.326', '3443.71', '112.012', ''),
('59498', '23', '694.076', '3467.46', '118.012', ''),
('59498', '24', '715.576', '3480.71', '121.512', ''),
('59498', '25', '741.826', '3492.21', '133.762', ''),
('59498', '26', '751.326', '3506.46', '137.762', ''),
('59498', '27', '756.076', '3525.21', '139.262', ''),
('59498', '28', '743.076', '3552.71', '140.512', ''),
('59498', '29', '741.576', '3572.46', '140.762', 'Despawn');




DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = '13' AND `SourceEntry` = '104012' AND `ElseGroup` = '0' AND `ConditionValue2` = '209626';
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
('13', '8', '104012', '0', '0', '31', '0', '5', '209626', '0', '0','0', '', 'Break Gong Credit target Break Gong');

DELETE FROM `creature_template_addon` WHERE `entry` = '55539';
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES ('55539', '0', '0', '65536', '0', '0','42386');

DELETE FROM `creature_template_addon` WHERE `entry` = '60916';
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES ('60916', '0', '0', '0', '1', '0', '105889 42386');

SET @KILLC1 := 104017;
SET @KILLC2 := 104023;


UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=@ENTRY ;
-- Shu SAI
SET @ENTRY := 55556;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,5000,8000,12000,11,118032,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shu - Out of Combat - Cast '<Spell not found!>'"),
(@ENTRY,0,1,2,62,0,100,0,13140,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shu - On Gossip Option 0 Selected - Close Gossip"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,85,104017,2,0,0,0,0,7,0,0,0,0,0,0,0,"Shu - On Gossip Select - Invoker Cast Summon Spirit of Water"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,85,104023,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shu - On Gossip Option 0 Selected - Invoker Cast Credit");


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = '13' AND `SourceEntry` = @KILLC1 AND `ElseGroup` = '0' AND `ConditionValue2` = '55556';
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
('13', '1', @KILLC1, '0', '0', '31', '0', '3', '55556', '0', '0', '0', '', 'Summon Spirit of Water target Shu');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = '13' AND `SourceEntry` = '118034' AND `ElseGroup` = '0' AND `ConditionValue2` = '55558';
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
('13', '1', '118034', '0', '0', '31', '0', '3', '55558', '0', '0', '0', '', 'Summon Spirit of Water target Shu');

-- Shu SAI
SET @ENTRY := 55558;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,53,1,55558,0,0,0,0,1,0,0,0,0,0,0,0,"Shu - Just Spawned - Start WP"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,54,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shu - Just Spawned - Pause WP"),
(@ENTRY,0,2,3,58,0,100,0,6,55558,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6.21337,"Shu - On WP Ended - Set Orientation"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,11,118027,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shu - On WP Ended - Cast Shu's Water Splash"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,11,118034,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shu - On WP Ended - Cast Water Splash"),
(@ENTRY,0,5,6,8,0,100,0,118034,0,0,0,11,@KILLC2,0,0,0,0,0,23,0,0,0,0,0,0,0,"Shu - On Spellhit - Cast Water Splash Credit"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shu - On Spellhit - Run Script"),
(@ENTRY,0,7,8,31,0,100,0,118027,0,0,0,28,42386,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shu - On Spellhit Target - Remove Aura"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shu - On Spellhit Target - Store Target"),
(@ENTRY,0,9,10,58,0,100,0,8,@ENTRY*100+00,0,0,11,118035,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shu - On WP Ended - Cast Cast Water Spirit Laugh"),
(@ENTRY,0,10,11,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,12,1,0,0,0,0,0,0,"Shu - On WP Ended - Set Data"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,29,0,1,0,0,0,0,23,0,0,0,0,0,0,0,"Shu - On WP Ended - Follow Summoner"),
(@ENTRY,0,12,13,8,0,100,1,106683,0,0,0,59,1,15,1,0,0,0,1,0,0,0,0,0,0,0,"Shu - On Spellhit - Set Run"),
(@ENTRY,0,13,14,61,0,100,1,0,0,0,0,53,1,@ENTRY*100+01,0,0,0,0,1,0,0,0,0,0,0,0,"Shu - On Spellhit - Start WP"),
(@ENTRY,0,14,0,61,0,100,1,0,0,0,0,28,@KILLC1,0,0,0,0,0,23,0,0,0,0,0,0,0,"Shu - On Spellhit - Remove Aura"),
(@ENTRY,0,15,0,58,0,100,0,8,@ENTRY*100+01,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shu - On WP Ended - Despawn");

-- Actionlist SAI
SET @ENTRY := 5555800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,11,118035,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shu - Cast Water Spirit Laugh"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,53,1,5555800,0,0,0,0,1,0,0,0,0,0,0,0,"Shu - Start WP");

DELETE FROM `waypoints` WHERE `entry` = 55558;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES 
('55558', '1', '648.675', '3124.17', '90.2095', ''),
('55558', '2', '639.615', '3120.11', '89.8218', ''),
('55558', '3', '628.448', '3121.48', '88.5602', ''),
('55558', '4', '622.969', '3125.62', '88.0585', ''),
('55558', '5', '620.156', '3134.65', '87.837', ''),
('55558', '6', '621.747', '3140.77', '87.837', '');

DELETE FROM `waypoints` WHERE `entry` = 5555800;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES 
('5555800', '1', '614.498', '3126.25', '87.8195', ''),
('5555800', '2', '624.028', '3121.75', '87.9445', ''),
('5555800', '3', '634.573', '3125.93', '88.6816', ''),
('5555800', '4', '638.785', '3133.88', '88.1648', ''),
('5555800', '5', '639.109', '3140.55', '88.3733', ''),
('5555800', '6', '636.264', '3146.2', '88.5406', ''),
('5555800', '7', '630.757', '3147.61', '88.2409', ''),
('5555800', '8', '625.675', '3143.88', '87.837', '');

DELETE FROM `waypoints` WHERE `entry` = 5555801;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES 
('5555801', '1', '815.315', '3608.55', '173.987', ''),
('5555801', '2', '831.068', '3607.74', '175.247', ''),
('5555801', '3', '841.146', '3606.77', '175.188', ''),
('5555801', '4', '855.831', '3607.75', '173.619', ''),
('5555801', '5', '880.269', '3605.99', '192.267', ''),
('5555801', '6', '892.776', '3605.94', '192.93', ''),
('5555801', '7', '900.755', '3603.12', '193.08', ''),
('5555801', '8', '906.239', '3600.17', '193.1', 'Despawn');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = '13' AND `SourceEntry` = '118027' AND `ElseGroup` = '0' AND `ConditionValue2` = '60916';
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = '13' AND `SourceEntry` = '105893' AND `ElseGroup` = '0' AND `ConditionValue2` = '60916';
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
('13', '1', '118027', '0', '0', '31', '0', '3', '60916', '0', '0', '0', '', 'Shu\'s Water Splash target Wugou'),
('13', '1', '105893', '0', '0', '31', '0', '3', '60916', '0', '0', '0', '', 'Trigger Spirit of Earth at Temple target Wugou');

-- Wugou SAI
SET @ENTRY := 60916;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,29,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wugou - Just Spawned - Follow"),
(@ENTRY,0,1,0,8,0,100,0,118027,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Wugou - On Spellhit - Run Script"),
(@ENTRY,0,2,0,38,0,100,0,1,1,0,0,29,0,5,0,0,0,0,23,0,0,0,0,0,0,0,"Wugou - On Data Set - Follow Summoner"),
(@ENTRY,0,3,4,8,0,100,0,105893,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wugou - On Spellhit - Set Walk"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,927.573,3610.24,196.442,0,"Wugou - On Spellhit - Move to Pos"),
(@ENTRY,0,5,0,34,0,100,0,8,1,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Wugou - Movement Inform - Run Script");

-- Actionlist SAI
SET @ENTRY := 6091600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,5,53,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wugou - Play Emote"),
(@ENTRY,9,1,0,0,0,100,0,2500,2500,0,0,29,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Wugou - Follow");

-- Actionlist SAI
SET @ENTRY := 6091601;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,250,250,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.9968,"Wugou - Set Orientation"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,28,118036,0,0,0,0,0,23,0,0,0,0,0,0,0,"Wugou - Remove Aura"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,44,1029,1,0,0,0,0,23,0,0,0,0,0,0,0,"Wugou - Add Phase"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wugou - Despawn");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = '13' AND `SourceEntry` = '118036' AND `ElseGroup` = '0' AND `ConditionValue2` = '55539';
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
('13', '1', '118036', '0', '0', '31', '0', '3', '55539', '0', '0', '0', '', 'Summon Spirit of Earth target Wugou');

