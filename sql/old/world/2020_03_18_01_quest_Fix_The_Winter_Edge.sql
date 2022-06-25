-- actualizado loot de npc 33289 antes estaba en -100
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`='100' WHERE (`entry`='33289') AND (`item`='45005');