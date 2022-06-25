/* reparacion de mision 43490 quest_objectives */
UPDATE quest_objectives SET TYPE=1 AND ObjectID=139540 WHERE id=285494;
DELETE FROM `smart_scripts` WHERE  entryorguid = 92445 AND id = 1 ;