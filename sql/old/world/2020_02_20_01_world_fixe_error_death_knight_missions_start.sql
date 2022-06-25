-- fixed speed_run value to NPC Death Knight Initiate
UPDATE `creature_template` SET `speed_run`= 1.14286 WHERE `entry`= 28406;

-- Eliminated Unnecessary Core Script and change to Smart Scripts Database

-- SAI Citizen of Havenshire Famele NPC ID: 28577
SET @CitizenFamele := 28577;
UPDATE `creature_text` SET `Type`= 12 WHERE `Entry`= 28577;
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`= 28577;
UPDATE `creature_template` SET `AIName`= "SmartAI" WHERE `entry`= 28577;
DELETE FROM `smart_scripts` WHERE `entryorguid`= 28577;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@CitizenFamele,0,0,0,4,0,100,1,0,0,0,0,31,1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Set Random Phase on Aggro"),
(@CitizenFamele,0,1,2,4,1,100,1,0,0,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Play Emote Fear on Aggro"),
(@CitizenFamele,0,2,3,61,1,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stop Attack on Aggro"),
(@CitizenFamele,0,3,4,61,1,100,1,0,0,0,0,4,14987,0,0,0,0,0,1,0,0,0,0,0,0,0,"Play Sound Female on Aggro"),
(@CitizenFamele,0,4,5,61,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stop Move on Aggro"),
(@CitizenFamele,0,5,0,61,1,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Say on Aggro"),
(@CitizenFamele,0,6,0,0,1,100,0,20000,20000,40000,40000,4,14987,0,0,0,0,0,1,0,0,0,0,0,0,0,"Play Sound Female Scream on Repeat"),
(@CitizenFamele,0,7,0,2,1,100,1,0,70,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Say Text at 70% HP"),
(@CitizenFamele,0,8,9,7,1,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reset Emote on Evade"),
(@CitizenFamele,0,9,0,61,1,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reset Phase on Evade"),
(@CitizenFamele,0,10,0,6,1,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reset Emote on Death"),
(@CitizenFamele,0,11,12,4,2,100,1,0,0,0,0,11,52262,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Cornered and Enraged! on Aggro"),
(@CitizenFamele,0,12,13,61,2,100,1,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Say Text on Aggro"),
(@CitizenFamele,0,13,14,61,2,100,1,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Start Attack on Aggro"),
(@CitizenFamele,0,14,0,61,2,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Start Move on Aggro"),
(@CitizenFamele,0,15,0,7,2,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reset Phase on Evade"),
(@CitizenFamele,0,16,0,6,1,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,"Quest Credit on Death"),
(@CitizenFamele,0,17,0,6,2,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,"Quest Credit on Death");

DELETE FROM `creature_text` WHERE `Entry`= 28577;
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
('28577', '0', '6', 'Ask for anything and you shall have it! Just spare my life! ', '12', '0', '50', '0', '0', '0', '29088', '0', '0', '0', 'combat Say'),
('28577', '2', '1', 'Die Scourge dog!DIE!', '12', '0', '50', '0', '0', '0', '0', '0', '0', '0', 'combat Say'),
('28577', '2', '0', 'I won\'t go down that easy!', '12', '0', '50', '0', '0', '0', '28788', '0', '0', '0', 'combat Say'),
('28577', '0', '5', 'I\'m too young to die! ', '12', '0', '50', '0', '0', '0', '63671', '0', '0', '0', 'combat Say'),
('28577', '2', '2', 'Is this the best the Scourge can do?', '12', '0', '50', '0', '0', '0', '28791', '0', '0', '0', 'combat Say'),
('28577', '0', '1', 'P... Please don\'t...', '12', '0', '50', '0', '0', '0', '28763', '0', '0', '0', 'combat Say'),
('28577', '0', '2', 'Spare my life! I will leave this place forever!Please!', '14', '0', '50', '0', '0', '0', '0', '0', '0', '0', 'combat Say'),
('28577', '1', '1', 'The Lich King whispers:Finish it!', '42', '0', '30', '0', '0', '14774', '0', '0', '0', '0', 'combat Say'),
('28577', '1', '6', 'The Lich King whispers:Kill or die!', '42', '0', '30', '0', '0', '14777', '0', '0', '0', '0', 'combat Say'),
('28577', '1', '0', 'The Lich King whispers:Kill them all!', '42', '0', '30', '0', '0', '14772', '0', '0', '0', '0', 'combat Say'),
('28577', '1', '2', 'The Lich King whispers:Mercy is for the weak!', '42', '0', '30', '0', '0', '14773', '0', '0', '0', '0', 'combat Say'),
('28577', '1', '5', 'The Lich King whispers:No mercy!', '42', '0', '50', '0', '0', '14771', '0', '0', '0', '0', 'combat Say'),
('28577', '1', '3', 'The Lich King whispers:No survivors!', '42', '0', '30', '0', '0', '14776', '0', '0', '0', '0', 'combat Say'),
('28577', '1', '4', 'The Lich King whispers:Show it the meaning of terror!', '42', '0', '30', '0', '0', '14782', '0', '0', '0', '0', 'combat Say'),
('28577', '1', '7', 'The Lich King whispers:Suffering to the conquered!', '42', '0', '30', '0', '0', '14781', '0', '0', '0', '0', 'combat Say'),
('28577', '0', '4', 'The... They promised that we\'d be safe... ', '12', '0', '50', '0', '0', '0', '29085', '0', '0', '0', 'combat Say'),
('28577', '0', '0', 'Why?', '12', '0', '50', '0', '0', '0', '28869', '0', '0', '0', 'combat Say'),
('28577', '0', '3', 'You make my children orphans on this day,friend! ', '12', '0', '50', '0', '0', '0', '0', '0', '0', '0', 'combat Say'),
('28577', '2', '3', 'You may take my life, but you won\'t take my freedom!', '12', '0', '50', '0', '0', '0', '28792', '0', '0', '0', 'combat Say');

-- SAI Citizen of Havenshire Male NPC ID: 28576
SET @CitizenMale := 28576;
UPDATE `creature_text` SET `Type`= 12 WHERE `Entry`= 28576;
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`= 28576;
UPDATE `creature_template` SET `AIName`= "SmartAI" WHERE `entry`= 28576;
DELETE FROM `smart_scripts` WHERE `entryorguid`= 28576;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@CitizenMale,0,0,0,4,0,100,1,0,0,0,0,31,1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Set Random Phase on Aggro"),
(@CitizenMale,0,1,2,4,1,100,1,0,0,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Play Emote Fear on Aggro"),
(@CitizenMale,0,2,3,61,1,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stop Attack on Aggro"),
(@CitizenMale,0,3,4,61,1,100,1,0,0,0,0,4,14987,0,0,0,0,0,1,0,0,0,0,0,0,0,"Play Sound Female on Aggro"),
(@CitizenMale,0,4,5,61,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stop Move on Aggro"),
(@CitizenMale,0,5,0,61,1,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Say on Aggro"),
(@CitizenMale,0,6,0,0,1,100,0,20000,20000,40000,40000,4,14987,0,0,0,0,0,1,0,0,0,0,0,0,0,"Play Sound Female Scream on Repeat"),
(@CitizenMale,0,7,0,2,1,100,1,0,70,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Say Text at 70% HP"),
(@CitizenMale,0,8,9,7,1,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reset Emote on Evade"),
(@CitizenMale,0,9,0,61,1,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reset Phase on Evade"),
(@CitizenMale,0,10,0,6,1,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reset Emote on Death"),
(@CitizenMale,0,11,12,4,2,100,1,0,0,0,0,11,52262,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Cornered and Enraged! on Aggro"),
(@CitizenMale,0,12,13,61,2,100,1,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Say Text on Aggro"),
(@CitizenMale,0,13,14,61,2,100,1,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Start Attack on Aggro"),
(@CitizenMale,0,14,0,61,2,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Start Move on Aggro"),
(@CitizenMale,0,15,0,7,2,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reset Phase on Evade"),
(@CitizenMale,0,16,0,6,1,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,"Quest Credit on Death"),
(@CitizenMale,0,17,0,6,2,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,"Quest Credit on Death");

DELETE FROM `creature_text` WHERE `Entry`= 28576;
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
('28576', '0', '6', 'Ask for anything and you shall have it! Just spare my life! ', '12', '0', '50', '0', '0', '0', '29088', '0', '0', '0', 'combat Say'),
('28576', '2', '1', 'Die Scourge dog!DIE!', '12', '0', '50', '0', '0', '0', '0', '0', '0', '0', 'combat Say'),
('28576', '2', '0', 'I won\'t go down that easy!', '12', '0', '50', '0', '0', '0', '28788', '0', '0', '0', 'combat Say'),
('28576', '0', '5', 'I\'m too young to die! ', '12', '0', '50', '0', '0', '0', '63671', '0', '0', '0', 'combat Say'),
('28576', '2', '2', 'Is this the best the Scourge can do?', '12', '0', '50', '0', '0', '0', '28791', '0', '0', '0', 'combat Say'),
('28576', '0', '1', 'P... Please don\'t...', '12', '0', '50', '0', '0', '0', '28763', '0', '0', '0', 'combat Say'),
('28576', '0', '2', 'Spare my life! I will leave this place forever!Please!', '14', '0', '50', '0', '0', '0', '0', '0', '0', '0', 'combat Say'),
('28576', '1', '1', 'The Lich King whispers:Finish it!', '42', '0', '30', '0', '0', '14774', '0', '0', '0', '0', 'combat Say'),
('28576', '1', '6', 'The Lich King whispers:Kill or die!', '42', '0', '30', '0', '0', '14777', '0', '0', '0', '0', 'combat Say'),
('28576', '1', '0', 'The Lich King whispers:Kill them all!', '42', '0', '30', '0', '0', '14772', '0', '0', '0', '0', 'combat Say'),
('28576', '1', '2', 'The Lich King whispers:Mercy is for the weak!', '42', '0', '30', '0', '0', '14773', '0', '0', '0', '0', 'combat Say'),
('28576', '1', '5', 'The Lich King whispers:No mercy!', '42', '0', '30', '0', '0', '14771', '0', '0', '0', '0', 'combat Say'),
('28576', '1', '3', 'The Lich King whispers:No survivors!', '42', '0', '30', '0', '0', '14776', '0', '0', '0', '0', 'combat Say'),
('28576', '1', '4', 'The Lich King whispers:Show it the meaning of terror!', '42', '0', '30', '0', '0', '14782', '0', '0', '0', '0', 'combat Say'),
('28576', '1', '7', 'The Lich King whispers:Suffering to the conquered!', '42', '0', '30', '0', '0', '14781', '0', '0', '0', '0', 'combat Say'),
('28576', '0', '4', 'The... They promised that we\'d be safe... ', '12', '0', '50', '0', '0', '0', '29085', '0', '0', '0', 'combat Say'),
('28576', '0', '0', 'Why?', '12', '0', '50', '0', '0', '0', '28869', '0', '0', '0', 'combat Say'),
('28576', '0', '3', 'You make my children orphans on this day,friend! ', '12', '0', '50', '0', '0', '0', '0', '0', '0', '0', 'combat Say'),
('28576', '2', '3', 'You may take my life, but you won\'t take my freedom!', '12', '0', '50', '0', '0', '0', '28792', '0', '0', '0', 'combat Say');

-- Eliminated Unnecessary GameObject
DELETE FROM `gameobject` WHERE `guid`= 29975;

-- Fixed error Quest ID: 12711 Title: Abandoned Mail
UPDATE `gameobject_template` SET `flags`= 32 WHERE `entry`= 190917;

-- Change creature questender and creature queststarter value to quest id 12779
DELETE FROM `creature_queststarter` WHERE `quest`= 12779;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES ('29110', '12779');
DELETE FROM `creature_questender` WHERE `quest`= 12779;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES ('29110', '12779');


DELETE FROM `quest_objectives` WHERE `QuestID`= 13166;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES 
('264790', '13166', '0', '1', '31098', '10', '0', '0', '0', 'Scourge slain', '19865'),
('264789', '13166', '0', '0', '31099', '1', '0', '0', '0', '', '19865');

-- Fixed missions error
UPDATE `quest_template` SET `RewardItem2`= 142320 WHERE `ID`= 12619;
UPDATE `quest_template` SET `RewardAmount2`= 1 WHERE `ID`= 12619;
UPDATE `quest_template` SET `RewardItem3`= 142320 WHERE `ID`= 12619;
UPDATE `quest_template` SET `RewardAmount3`= 1 WHERE `ID`= 12619;
UPDATE `quest_template_addon` SET `SourceSpellID`= 53642 WHERE `ID`= 13166;
UPDATE `quest_template_addon` SET `SourceSpellID`= 53606 WHERE `ID`= 12801;
UPDATE `quest_template` SET `RewardMoney`= 25000 WHERE `ID`= 13189;
UPDATE `quest_template` SET `StartItem`= 0 WHERE `ID`= 13189;
UPDATE `quest_template` SET `RewardFactionID1`= 1098 WHERE `ID`= 13189;
UPDATE `quest_template` SET `RewardFactionValue1`= 7 WHERE `ID`= 13189;
UPDATE `quest_template` SET `QuestPackageID`= 17144 WHERE `ID`= 12801;

-- Implement creature_text of quest A Special Surprise

-- Troll
DELETE FROM `creature_text` WHERE `Entry` = 29073;
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
('29073', '0', '0', 'Come ta finish da job, mon?', '12', '0', '100', '0', '0', '0', '29403', '0', '0', '0', 'special_surprise SAY_EXEC_START_3'),
('29073', '1', '0', 'Dis troll gonna stand for da...', '12', '0', '100', '0', '0', '0', '29404', '0', '0', '0', 'special_surprise SAY_EXEC_PROG_7'),
('29073', '2', '0', '$n? Mon?', '12', '0', '100', '0', '0', '0', '29405', '0', '0', '0', 'special_surprise SAY_EXEC_NAME_2'),
('29073', '3', '0', '$n, I\'d recognize dem tusks anywhere... What... What have dey done ta you, mon?', '12', '0', '100', '0', '0', '0', '29406', '0', '0', '0', 'special_surprise SAY_EXEC_RECOG_6'),
('29073', '4', '0', 'You don\'t remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin\' dat made ya a mojo masta. Every last ounce a good... Everytin\' dat made ya a troll hero, mon!', '12', '0', '100', '0', '0', '0', '29407', '0', '0', '0', 'special_surprise SAY_EXEC_NOREM_9'),
('29073', '5', '0', 'TINK, $n. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought da Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!\n', '12', '0', '100', '0', '0', '0', '29408', '0', '0', '0', 'special_surprise SAY_EXEC_THINK_10'),
('29073', '6', '0', 'Listen ta me, $g brudda:sista;. You must fight against da Lich King\'s control. He be a monster dat want ta see dis world - our world - be ruined. Don\'t let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!', '12', '0', '100', '0', '0', '0', '29409', '0', '0', '0', 'special_surprise SAY_EXEC_LISTEN_4'),
('29073', '7', '0', 'Der... Der\'s no more time for me. I be done for. Finish me off, $n. Do it or dey\'ll kill us both. $n... Remember Sen\'jin Village, mon! Dis world be worth saving!', '12', '0', '100', '0', '0', '0', '29410', '0', '0', '0', 'special_surprise SAY_EXEC_TIME_10'),
('29073', '8', '0', 'Do it, $n! Put me out of my misery!', '12', '0', '100', '0', '0', '0', '29401', '0', '0', '0', 'special_surprise SAY_EXEC_WAITING');

-- Orc
DELETE FROM `creature_text` WHERE `Entry` = 29072;
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
('29072', '0', '0', 'Come to finish the job, have you?', '12', '0', '100', '0', '0', '0', '29393', '0', '0', '0', 'special_surprise SAY_EXEC_START_1'),
('29072', '1', '0', 'I want to die like an orc...', '12', '0', '100', '0', '0', '0', '29384', '0', '0', '0', 'special_surprise SAY_EXEC_PROG_6'),
('29072', '2', '0', '$n?', '12', '0', '100', '0', '0', '0', '29395', '0', '0', '0', 'special_surprise SAY_EXEC_NAME_1'),
('29072', '3', '0', '$n, I\'d recognize that face anywhere... What... What have they done to you, $n?', '12', '0', '100', '0', '0', '0', '29386', '0', '0', '0', 'special_surprise SAY_EXEC_RECOG_1'),
('29072', '4', '0', 'You don\'t remember me, do you? Blasted Scourge... They\'ve tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!', '12', '0', '100', '0', '0', '0', '29387', '0', '0', '0', 'special_surprise SAY_EXEC_NOREM_7'),
('29072', '5', '0', 'Think, $n. Think back. Try and remember Durotar, $g brother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $n. Together! This isn\'t you. You were a champion of the Horde once!', '12', '0', '100', '0', '0', '0', '29388', '0', '0', '0', 'special_surprise SAY_EXEC_THINK_8'),
('29072', '6', '0', 'Listen to me, $n. You must fight against the Lich King\'s control. He is a monster that wants to see this world - our world - in ruin. Don\'t let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!', '12', '0', '100', '0', '0', '0', '29389', '0', '0', '0', 'special_surprise SAY_EXEC_LISTEN_1'),
('29072', '7', '0', 'There... There\'s no more time for me. I\'m done for. Finish me off, $n. Do it or they\'ll kill us both. $n... For the Horde! This world is worth saving.', '12', '0', '100', '0', '0', '0', '29390', '0', '0', '0', 'special_surprise SAY_EXEC_TIME_8'),
('29072', '8', '0', 'Do it, $n! Put me out of my misery!', '12', '0', '100', '0', '0', '0', '29401', '0', '0', '0', 'special_surprise SAY_EXEC_WAITING');

-- Undead
DELETE FROM `creature_text` WHERE `Entry` = 29071;
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
('29071', '0', '0', 'Come to finish the job, have you?', '12', '0', '100', '0', '0', '0', '29393', '0', '0', '0', 'special_surprise SAY_EXEC_START_1'),
('29071', '1', '0', 'Ironic, isn\'t it? To be killed...', '12', '0', '100', '0', '0', '0', '29394', '0', '0', '0', 'special_surprise SAY_EXEC_PROG_3'),
('29071', '2', '0', '$n?', '12', '0', '100', '0', '0', '0', '29395', '0', '0', '0', 'special_surprise SAY_EXEC_NAME_1'),
('29071', '3', '0', '$n, I\'d recognize that decay anywhere... What... What have they done to you, $n?', '12', '0', '100', '0', '0', '0', '29396', '0', '0', '0', 'special_surprise SAY_EXEC_RECOG_4'),
('29071', '4', '0', 'You don\'t remember me? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady.', '12', '0', '100', '0', '0', '0', '29397', '0', '0', '0', 'special_surprise SAY_EXEC_NOREM_3'),
('29071', '5', '0', 'A pact was made, $g brother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the Plaguelands and freeing Tirisifal! You and I were champions of the Forsaken!', '12', '0', '100', '0', '0', '0', '29398', '0', '0', '0', 'special_surprise SAY_EXEC_THINK_1'),
('29071', '6', '0', 'Listen to me, $n. You must fight against the Lich King\'s control. He is a monster that wants to see this world - our world - in ruin. Don\'t let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!', '12', '0', '100', '0', '0', '0', '29389', '0', '0', '0', 'special_surprise SAY_EXEC_LISTEN_1'),
('29071', '7', '0', 'There... There\'s no more time for me. I\'m done for. Finish me off, $n. Do it or they\'ll kill us both. $n... Remember Tirisfal! This world is worth saving!', '12', '0', '100', '0', '0', '0', '29400', '0', '0', '0', 'special_surprise SAY_EXEC_TIME_4'),
('29071', '8', '0', 'Do it, $n! Put me out of my misery!', '12', '0', '100', '0', '0', '0', '29401', '0', '0', '0', 'special_surprise SAY_EXEC_WAITING');

-- Tauren
DELETE FROM `creature_text` WHERE `Entry` = 29032;
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
('29032', '0', '0', 'Come to finish the job, have you?', '12', '0', '100', '0', '0', '0', '29393', '0', '0', '0', 'special_surprise SAY_EXEC_START_1'),
('29032', '1', '0', 'You\'ll look me in the eyes when...', '12', '0', '100', '0', '0', '0', '29369', '0', '0', '0', 'special_surprise SAY_EXEC_PROG_1'),
('29032', '2', '0', '$n?', '12', '0', '100', '0', '0', '0', '29395', '0', '0', '0', 'special_surprise SAY_EXEC_NAME_1'),
('29032', '3', '0', '$n, I\'d recognize those horns anywhere... What... What have they done to you, $n?', '12', '0', '100', '0', '0', '0', '29289', '0', '0', '0', 'special_surprise SAY_EXEC_RECOG_5'),
('29032', '4', '0', 'You don\'t remember me, do you? Blasted Scourge... They\'ve tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!', '12', '0', '100', '0', '0', '0', '29290', '0', '0', '0', 'special_surprise SAY_EXEC_NOREM_8'),
('29032', '5', '0', 'Think, $n. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $g brother:sister;. You were a champion of the tauren once! This isn\'t you.', '12', '0', '100', '0', '0', '0', '29294', '0', '0', '0', 'special_surprise SAY_EXEC_THINK_9'),
('29032', '6', '0', 'Listen to me, $n. You must fight against the Lich King\'s control. He is a monster that wants to see this world - our world - in ruin. Don\'t let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!', '12', '0', '100', '0', '0', '0', '29389', '0', '0', '0', 'special_surprise SAY_EXEC_LISTEN_1'),
('29032', '7', '0', 'There... There\'s no more time for me. I\'m done for. Finish me off, $n. Do it or they\'ll kill us both. $n... Remember Mulgore. This world is worth saving.', '12', '0', '100', '0', '0', '0', '29301', '0', '0', '0', 'special_surprise SAY_EXEC_TIME_9'),
('29032', '8', '0', 'Do it, $n! Put me out of my misery!', '12', '0', '100', '0', '0', '0', '29401', '0', '0', '0', 'special_surprise SAY_EXEC_WAITING');

-- Blood Elf
DELETE FROM `creature_text` WHERE `Entry` = 29074;
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
('29074', '0', '0', 'Come to finish the job, have you?', '12', '0', '100', '0', '0', '0', '29393', '0', '0', '0', 'special_surprise SAY_EXEC_START_1'),
('29074', '1', '0', 'You\'ll look me in the eyes when...', '12', '0', '100', '0', '0', '0', '29369', '0', '0', '0', 'special_surprise SAY_EXEC_PROG_1'),
('29074', '2', '0', '$n?', '12', '0', '100', '0', '0', '0', '29395', '0', '0', '0', 'special_surprise SAY_EXEC_NAME_1'),
('29074', '3', '0', '$n, I\'d recognize that face anywhere... What... What have they done to you, $n?', '12', '0', '100', '0', '0', '0', '29386', '0', '0', '0', 'special_surprise SAY_EXEC_RECOG_1'),
('29074', '4', '0', 'Think, $n. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $g brother:sister;. You were a champion of the sin\'dorei once! This isn\'t you.', '12', '0', '100', '0', '0', '0', '29374', '0', '0', '0', 'special_surprise SAY_EXEC_THINK_3'),
('29074', '5', '0', 'Listen to me, $n. You must fight against the Lich King\'s control. He is a monster that wants to see this world - our world - in ruin. Don\'t let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!', '12', '0', '100', '0', '0', '0', '29389', '0', '0', '0', 'special_surprise SAY_EXEC_LISTEN_1'),
('29074', '6', '0', 'There... There\'s no more time for me. I\'m done for. Finish me off, $n. Do it or they\'ll kill us both. $n... Remember Silvermoon. This world is worth saving.', '12', '0', '100', '0', '0', '0', '29376', '0', '0', '0', 'special_surprise SAY_EXEC_TIME_1'),
('29074', '7', '0', 'Do it, $n! Put me out of my misery!', '12', '0', '100', '0', '0', '0', '29401', '0', '0', '0', 'special_surprise SAY_EXEC_WAITING');

-- Goblin
DELETE FROM `creature_text` WHERE `Entry` = 49356;
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
('49356', '0', '0', 'Come to finish the job, have you?', '12', '0', '100', '0', '0', '0', '29393', '0', '0', '0', 'special_surprise SAY_EXEC_START_1'),
('49356', '1', '0', 'I\'d like to stand for...', '12', '0', '100', '0', '0', '0', '29323', '0', '0', '0', 'special_surprise SAY_EXEC_PROG_5'),
('49356', '2', '0', '$n?', '12', '0', '100', '0', '0', '0', '29395', '0', '0', '0', 'special_surprise SAY_EXEC_NAME_1'),
('49356', '3', '0', '$n, I\'d recognize that face anywhere... What... What have they done to you, $n?', '12', '0', '100', '0', '0', '0', '29386', '0', '0', '0', 'special_surprise SAY_EXEC_RECOG_1'),
('49356', '4', '0', 'Listen to me, $n. You must fight against the Lich King\'s control. He is a monster that wants to see this world - our world - in ruin. Don\'t let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!', '12', '0', '100', '0', '0', '0', '29389', '0', '0', '0', 'special_surprise SAY_EXEC_LISTEN_1'),
('49356', '5', '0', 'Do it, $n! Put me out of my misery!', '12', '0', '100', '0', '0', '0', '29401', '0', '0', '0', 'special_surprise SAY_EXEC_WAITING');

-- Human
DELETE FROM `creature_text` WHERE `Entry` = 29061;
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
('29061', '0', '0', 'Come to finish the job, have you?', '12', '0', '100', '0', '0', '0', '29393', '0', '0', '0', 'special_surprise SAY_EXEC_START_1'),
('29061', '1', '0', 'I\'d like to stand for...', '12', '0', '100', '0', '0', '0', '29323', '0', '0', '0', 'special_surprise SAY_EXEC_PROG_5'),
('29061', '2', '0', '$n?', '12', '0', '100', '0', '0', '0', '29395', '0', '0', '0', 'special_surprise SAY_EXEC_NAME_1'),
('29061', '3', '0', '$n, I\'d recognize that face anywhere... What... What have they done to you, $n?', '12', '0', '100', '0', '0', '0', '29386', '0', '0', '0', 'special_surprise SAY_EXEC_RECOG_1'),
('29061', '4', '0', 'You don\'t remember me, do you? Blasted Scourge... They\'ve tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a human!', '12', '0', '100', '0', '0', '0', '29314', '0', '0', '0', 'special_surprise SAY_EXEC_NOREM_5'),
('29061', '5', '0', 'Think, $n. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $g brother:sister;. You were a champion of the Alliance once! This isn\'t you.', '12', '0', '100', '0', '0', '0', '29315', '0', '0', '0', 'special_surprise SAY_EXEC_THINK_7'),
('29061', '6', '0', 'Listen to me, $n. You must fight against the Lich King\'s control. He is a monster that wants to see this world - our world - in ruin. Don\'t let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!', '12', '0', '100', '0', '0', '0', '29389', '0', '0', '0', 'special_surprise SAY_EXEC_LISTEN_1'),
('29061', '7', '0', 'There... There\'s no more time for me. I\'m done for. Finish me off, $n. Do it or they\'ll kill us both. $n... Remember Elwynn. This world is worth saving.', '12', '0', '100', '0', '0', '0', '29317', '0', '0', '0', 'special_surprise SAY_EXEC_TIME_6'),
('29061', '8', '0', 'Do it, $n! Put me out of my misery!', '12', '0', '100', '0', '0', '0', '29401', '0', '0', '0', 'special_surprise SAY_EXEC_WAITING');

-- Dwarf
DELETE FROM `creature_text` WHERE `Entry` = 29067;
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
('29067', '0', '0', 'Come to finish the job, have you?', '12', '0', '100', '0', '0', '0', '29393', '0', '0', '0', 'special_surprise SAY_EXEC_START_1'),
('29067', '1', '0', 'Well this son o\' Ironforge would like...', '12', '0', '100', '0', '0', '0', '29336', '0', '0', '0', 'special_surprise SAY_EXEC_PROG_2'),
('29067', '2', '0', '$n?', '12', '0', '100', '0', '0', '0', '29395', '0', '0', '0', 'special_surprise SAY_EXEC_NAME_1'),
('29067', '3', '0', '$n, I\'d recognize that face anywhere... What... What have they done to you, $n?', '12', '0', '100', '0', '0', '0', '29386', '0', '0', '0', 'special_surprise SAY_EXEC_RECOG_1'),
('29067', '4', '0', 'Ye don\'t remember me, do ye? Blasted Scourge... They\'ve tried to drain ye o\' everything that made ye a righteous force o\' reckoning. Every last ounce o\' good... Everything that made ye a $g son:daughter; o\' Ironforge!', '12', '0', '100', '0', '0', '0', '29339', '0', '0', '0', 'special_surprise SAY_EXEC_NOREM_2'),
('29067', '5', '0', 'Think, $n. Think back. Try and remember the snow capped mountains o\' Dun Morogh! Ye were born there, $g lad:lass;. Remember the splendor o\' life, $n! Ye were a champion o\' the dwarves once! This isn\'t ye!', '12', '0', '100', '0', '0', '0', '29340', '0', '0', '0', 'special_surprise SAY_EXEC_THINK_5'),
('29067', '6', '0', 'Listen to me, $n. You must fight against the Lich King\'s control. He is a monster that wants to see this world - our world - in ruin. Don\'t let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!', '12', '0', '100', '0', '0', '0', '29389', '0', '0', '0', 'special_surprise SAY_EXEC_LISTEN_1'),
('29067', '7', '0', 'There... There\'s no more time for me. I\'m done for. Finish me off, $n. Do it or they\'ll kill us both. $n... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!', '12', '0', '100', '0', '0', '0', '29342', '0', '0', '0', 'special_surprise SAY_EXEC_TIME_3'),
('29067', '8', '0', 'Do it, $n! Put me out of my misery!', '12', '0', '100', '0', '0', '0', '29401', '0', '0', '0', 'special_surprise SAY_EXEC_WAITING');

-- Night Elf
DELETE FROM `creature_text` WHERE `Entry` = 29065;
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
('29065', '0', '0', 'Come to finish the job, have you?', '12', '0', '100', '0', '0', '0', '29393', '0', '0', '0', 'special_surprise SAY_EXEC_START_1'),
('29065', '1', '0', 'I\'d like to stand for...', '12', '0', '100', '0', '0', '0', '29323', '0', '0', '0', 'special_surprise SAY_EXEC_PROG_5'),
('29065', '2', '0', '$n?', '12', '0', '100', '0', '0', '0', '29395', '0', '0', '0', 'special_surprise SAY_EXEC_NAME_1'),
('29065', '3', '0', '$n, I\'d recognize that face anywhere... What... What have they done to you, $n?', '12', '0', '100', '0', '0', '0', '29386', '0', '0', '0', 'special_surprise SAY_EXEC_RECOG_1'),
('29065', '4', '0', 'You don\'t remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you honey and sheep\'s milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $n?', '12', '0', '100', '0', '0', '0', '29326', '0', '0', '0', 'special_surprise SAY_EXEC_NOREM_6'),
('29065', '5', '0', 'You must remember the splendor of life, $g brother:sister;. You were a champion of the kaldorei once! This isn\'t you!', '12', '0', '100', '0', '0', '0', '29328', '0', '0', '0', 'special_surprise SAY_EXEC_THINK_2'),
('29065', '6', '0', 'Listen to me, $n. You must fight against the Lich King\'s control. He is a monster that wants to see this world - our world - in ruin. Don\'t let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!', '12', '0', '100', '0', '0', '0', '29389', '0', '0', '0', 'special_surprise SAY_EXEC_LISTEN_1'),
('29065', '7', '0', 'There... There\'s no more time for me. I\'m done for. Finish me off, $n. Do it or they\'ll kill us both. $n... Remember Teldrassil, our beloved home. This world is worth saving.', '12', '0', '100', '0', '0', '0', '29330', '0', '0', '0', 'special_surprise SAY_EXEC_TIME_7'),
('29065', '8', '0', 'Do it, $n! Put me out of my misery!', '12', '0', '100', '0', '0', '0', '29401', '0', '0', '0', 'special_surprise SAY_EXEC_WAITING');

-- Gnome
DELETE FROM `creature_text` WHERE `Entry` = 29068;
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
('29068', '0', '0', 'Come to finish the job, have you?', '12', '0', '100', '0', '0', '0', '29393', '0', '0', '0', 'special_surprise SAY_EXEC_START_1'),
('29068', '1', '0', 'If you\'d allow me just one...', '12', '0', '100', '0', '0', '0', '29348', '0', '0', '0', 'special_surprise SAY_EXEC_PROG_4'),
('29068', '2', '0', '$n?', '12', '0', '100', '0', '0', '0', '29395', '0', '0', '0', 'special_surprise SAY_EXEC_NAME_1'),
('29068', '3', '0', '$n, I\'d recognize that face anywhere... What... What have they done to you, $n?', '12', '0', '100', '0', '0', '0', '29386', '0', '0', '0', 'special_surprise SAY_EXEC_RECOG_1'),
('29068', '4', '0', 'You don\'t remember me, do you? Blasted Scourge... They\'ve tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!', '12', '0', '100', '0', '0', '0', '29351', '0', '0', '0', 'special_surprise SAY_EXEC_NOREM_4'),
('29068', '5', '0', 'Think, $n. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an arclight spanner, $g brother:sister;. You were a champion of gnome-kind once! This isn\'t you.', '12', '0', '100', '0', '0', '0', '29352', '0', '0', '0', 'special_surprise SAY_EXEC_THINK_6'),
('29068', '6', '0', 'Listen to me, $n. You must fight against the Lich King\'s control. He is a monster that wants to see this world - our world - in ruin. Don\'t let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!', '12', '0', '100', '0', '0', '0', '29389', '0', '0', '0', 'special_surprise SAY_EXEC_LISTEN_1'),
('29068', '7', '0', 'There... There\'s no more time for me. I\'m done for. Finish me off, $n. Do it or they\'ll kill us both. $n... Remember Gnomeregan! This world is worth saving.', '12', '0', '100', '0', '0', '0', '29354', '0', '0', '0', 'special_surprise SAY_EXEC_TIME_5'),
('29068', '8', '0', 'Do it, $n! Put me out of my misery!', '12', '0', '100', '0', '0', '0', '29401', '0', '0', '0', 'special_surprise SAY_EXEC_WAITING');

-- Draenei
DELETE FROM `creature_text` WHERE `Entry` = 29070;
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
('29070', '0', '0', 'Come to finish the job, have you?', '12', '0', '100', '0', '0', '0', '29393', '0', '0', '0', 'special_surprise SAY_EXEC_START_1'),
('29070', '1', '0', 'You\'ll look me in the eyes when...', '12', '0', '100', '0', '0', '0', '29369', '0', '0', '0', 'special_surprise SAY_EXEC_PROG_1'),
('29070', '2', '0', '$n?', '12', '0', '100', '0', '0', '0', '29395', '0', '0', '0', 'special_surprise SAY_EXEC_NAME_1'),
('29070', '3', '0', '$n, I\'d recognize those face tentacles anywhere... What... What have they done to you, $n?', '12', '0', '100', '0', '0', '0', '29360', '0', '0', '0', 'special_surprise SAY_EXEC_RECOG_2'),
('29070', '4', '0', 'You don\'t remember me, do you? Blasted Scourge... They\'ve tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!', '12', '0', '100', '0', '0', '0', '29361', '0', '0', '0', 'special_surprise SAY_EXEC_NOREM_1'),
('29070', '5', '0', 'Think, $n. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $g brother:sister;. You were a champion of the draenei once! This isn\'t you.', '12', '0', '100', '0', '0', '0', '29362', '0', '0', '0', 'special_surprise SAY_EXEC_THINK_4'),
('29070', '6', '0', 'Listen to me, $n. You must fight against the Lich King\'s control. He is a monster that wants to see this world - our world - in ruin. Don\'t let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!', '12', '0', '100', '0', '0', '0', '29389', '0', '0', '0', 'special_surprise SAY_EXEC_LISTEN_1'),
('29070', '7', '0', 'There... There\'s no more time for me. I\'m done for. Finish me off, $n. Do it or they\'ll kill us both. $n... Remember Argus. Don\'t let that happen to this world.', '12', '0', '100', '0', '0', '0', '29364', '0', '0', '0', 'special_surprise SAY_EXEC_TIME_2'),
('29070', '8', '0', 'Do it, $n! Put me out of my misery!', '12', '0', '100', '0', '0', '0', '29401', '0', '0', '0', 'special_surprise SAY_EXEC_WAITING');

-- Worgen
DELETE FROM `creature_text` WHERE `Entry` = 49355;
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
('49355', '0', '0', 'Come to finish the job, have you?', '12', '0', '100', '0', '0', '0', '29393', '0', '0', '0', 'special_surprise SAY_EXEC_START_1'),
('49355', '1', '0', 'I\'d like to stand for...', '12', '0', '100', '0', '0', '0', '29323', '0', '0', '0', 'special_surprise SAY_EXEC_PROG_5'),
('49355', '2', '0', '$n?', '12', '0', '100', '0', '0', '0', '29395', '0', '0', '0', 'special_surprise SAY_EXEC_NAME_1'),
('49355', '3', '0', '$n, I\'d recognize that face anywhere... What... What have they done to you, $n?', '12', '0', '100', '0', '0', '0', '29386', '0', '0', '0', 'special_surprise SAY_EXEC_RECOG_1'),
('49355', '4', '0', 'You don\'t remember me, do you? Blasted Scourge... They\'ve tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a human!', '12', '0', '100', '0', '0', '0', '29314', '0', '0', '0', 'special_surprise SAY_EXEC_NOREM_5'),
('49355', '5', '0', 'Think, $n. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $g brother:sister;. You were a champion of the Alliance once! This isn\'t you.', '12', '0', '100', '0', '0', '0', '29315', '0', '0', '0', 'special_surprise SAY_EXEC_THINK_7'),
('49355', '6', '0', 'Listen to me, $n. You must fight against the Lich King\'s control. He is a monster that wants to see this world - our world - in ruin. Don\'t let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!', '12', '0', '100', '0', '0', '0', '29389', '0', '0', '0', 'special_surprise SAY_EXEC_LISTEN_1'),
('49355', '7', '0', 'There... There\'s no more time for me. I\'m done for. Finish me off, $n. Do it or they\'ll kill us both. $n... Remember Elwynn. This world is worth saving.', '12', '0', '100', '0', '0', '0', '29317', '0', '0', '0', 'special_surprise SAY_EXEC_TIME_6'),
('49355', '8', '0', 'Do it, $n! Put me out of my misery!', '12', '0', '100', '0', '0', '0', '29401', '0', '0', '0', 'special_surprise SAY_EXEC_WAITING');

DELETE FROM `gameobject` WHERE `guid` = 47958;
DELETE FROM `creature` WHERE `id`= 31099;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES ('146733863', '31099', '0', '139', '4281', '1', '256', '', '0', '0', '2463.88', '-5595.44', '414.122', '3.45213', '300', '0', '0', '224300', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');
UPDATE `creature` SET `spawntimesecs`='45' WHERE `id`= 31098;
UPDATE `gameobject` SET `id`='191009' WHERE `guid`= 46443;
UPDATE `gameobject` SET `id`='190960' WHERE `guid`= 46444;
UPDATE `quest_template` SET `StartItem`= 43441 WHERE `ID`= 13189;
UPDATE `quest_template` SET `RewardFactionID1`= 76 WHERE `ID`= 13189;


