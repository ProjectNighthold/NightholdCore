-- npc que mete tremendo damage y que tiene mas vida de la que deveria fix
UPDATE `creature_template_wdb` SET `HpMulti`=1 WHERE `entry`= 93031;
UPDATE `creature_template` SET `dmg_multiplier`=0.25 WHERE `entry`= 93031;

