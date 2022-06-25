/* hellfire citidal 1 fence and door fix */
DELETE FROM `gameobject` WHERE `guid` = 145637 AND `id` = 242460;
DELETE FROM `gameobject` WHERE `guid` = 145628 AND `id` = 242452;
DELETE FROM `gameobject` WHERE `guid` = 145629 AND `id` = 242452;
DELETE FROM `gameobject` WHERE `guid` = 145630 AND `id` = 242452;
DELETE FROM `gameobject` WHERE `guid` = 145627 AND `id` = 242452;
DELETE FROM `gameobject` WHERE `guid` = 145581 AND `id` = 241732;
DELETE FROM `gameobject` WHERE `guid` = 145606 AND `id` = 241733;
/* hellfire citidal 1 door guardian display fix */
UPDATE `creature_template_wdb` SET `Name1`='Door Guardian', `Displayid2`='61921' WHERE  `Entry`=90019;