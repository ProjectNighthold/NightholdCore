DELETE FROM `disables` WHERE `sourceType` = 1 AND  `entry` = 11997;
UPDATE `quest_template` SET `QuestLevel`='100', `QuestMaxScalingLevel`='255', `MinLevel`='100' WHERE (`ID`='11997');