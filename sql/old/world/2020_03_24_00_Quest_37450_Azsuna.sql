/* quest - 37450 Azsuna
Modificando el looteo de -100 a 100 (LOOT_QUEST_PROBLEM)
*/
UPDATE `creature_loot_template`  SET `ChanceOrQuestChance`='100'  WHERE `entry`='86535' AND `item`='120359';