/*
fix quest 33882 memesan*/

delete from `quest_objectives` where QuestID = 33882;
insert INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES('272146','33882','0','0','76922','7','0','0','0','Frightened Peachicks rescued','19865');
delete FROM smart_scripts WHERE entryorguid= 76722 AND source_type=0;
UPDATE creature_template SET AIName='SmartAI' WHERE entry=76722;
DELETE FROM `smart_scripts` WHERE  `entryorguid` = 76722 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE  `entryorguid` = 76722 AND `source_type` = 1;
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values
('76722','0','0','0','73','0','100','0','0','0','0','0','41','2000','60','0','0','0','0','1','0','0','0','0','0','0','0','Quest 33882 spawn  pollo'),
('76722','0','1','0','73','0','100','0','0','0','0','0','33','76922','0','0','0','0','0','7','0','0','0','0','0','0','0','Quest 33882 da el kill credit');
