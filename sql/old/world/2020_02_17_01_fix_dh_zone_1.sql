UPDATE `quest_template` SET `RewardNextQuest` = 39516 WHERE `Id` = 39515;
UPDATE `quest_template` SET `RewardNextQuest` = 39262 WHERE `Id` = 38813;
UPDATE `quest_template` SET `RewardNextQuest` = 38819 WHERE `Id` = 38727;
UPDATE `quest_template` SET `RewardNextQuest` = 39663 WHERE `Id` = 39516;
UPDATE `quest_template` SET `RewardNextQuest` = 38728 WHERE `Id` = 39663;
UPDATE `quest_template` SET `RewardNextQuest` = 39495 WHERE `Id` = 39262;
UPDATE `creature` SET `PhaseId` = 0 WHERE `Id` = 97303;


DELETE FROM `creature` WHERE `guid`= 368767;
DELETE FROM `creature` WHERE `guid`= 368956;
DELETE FROM `creature` WHERE `guid`= 368932;
DELETE FROM `creature` WHERE `guid`= 368953;
DELETE FROM `creature` WHERE `guid`= 368849;
DELETE FROM `creature` WHERE `guid`= 368975;
DELETE FROM `creature` WHERE `guid`= 368910;
DELETE FROM `creature` WHERE `guid`= 368940;
DELETE FROM `creature` WHERE `guid`= 368941;
DELETE FROM `creature` WHERE `guid`= 368907;
DELETE FROM `creature` WHERE `guid`= 368974;
DELETE FROM `creature` WHERE `guid`= 368912;
DELETE FROM `creature` WHERE `guid`= 368954;
DELETE FROM `creature` WHERE `guid`= 368777;
DELETE FROM `creature` WHERE `guid`= 368776;
DELETE FROM `creature` WHERE `guid`= 368893;
DELETE FROM `creature` WHERE `guid`= 368807;
DELETE FROM `creature` WHERE `guid`= 368758;
DELETE FROM `creature` WHERE `guid`= 368749;
DELETE FROM `creature` WHERE `guid`= 368737;
DELETE FROM `creature` WHERE `guid`= 368733;
DELETE FROM `creature` WHERE `guid`= 368712;

UPDATE `creature_template` SET `unit_flags2` = 2048 WHERE `Entry` = 97706;
UPDATE `creature_template` SET `unit_flags2` = 2048 WHERE `Entry` = 100243;

