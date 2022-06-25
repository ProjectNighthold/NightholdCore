-- quest 40336 fix npc que tenian demasiado damage que fue reducido para que tuviera mas equilibrio entre el damage y la vida
UPDATE `creature_template` SET `dmg_multiplier`=0.10 WHERE `entry`= 104829;
UPDATE `creature_template` SET `dmg_multiplier`=0.10 WHERE `entry`= 104359;