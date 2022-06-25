/*
Fix quest 35500  http://10.96.2.9/bugtracker/view.php?id=190
EL NPCs esta fuera de phase y no esta como objetivo

*/

UPDATE `quest_objectives` SET `ObjectID`='82918' WHERE (`ID`='273854');
UPDATE `creature` SET `phaseMask`='1' WHERE (`guid`='11785129');
UPDATE `quest_poi` SET `QuestObjectID`='82918' WHERE (`QuestID`='35500') AND (`BlobIndex`='0') AND (`Idx1`='1');
UPDATE `quest_poi` SET `QuestObjectID`='82918' WHERE (`QuestID`='35500') AND (`BlobIndex`='0') AND (`Idx1`='2');