/* termina quest  46842*/
DELETE FROM `creature_questender` WHERE `quest` IN (46842);
INSERT INTO `creature_questender`(id, quest) VALUES
(120953, 46842);


/* repracion de flag de questobject mision 46732 */
 
UPDATE `quest_objectives` SET `flags` = 4 WHERE `Id` = 289530;
UPDATE `quest_objectives` SET `flags` = 4 WHERE `Id` = 289531;