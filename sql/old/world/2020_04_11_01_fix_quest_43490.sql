/* reparacion de mision 43490 cambio de % de loot */
UPDATE creature_loot_template SET ChanceOrQuestChance = '7' WHERE entry = '92447' AND item  = '139540';
UPDATE creature_loot_template SET ChanceOrQuestChance = '4' WHERE entry = '92445' AND item  = '139540';
UPDATE creature_loot_template SET ChanceOrQuestChance = '4' WHERE entry = '92450' AND item  = '139540';