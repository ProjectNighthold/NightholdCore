/* zona valle sombra luna */
/* elimina aura del npc q lo tenia muerto */
UPDATE `creature_template_addon` SET `auras` = ""  WHERE `entry`= 78148;
/* flag mala salia muerto */
UPDATE `creature_template` SET `unit_flags2` = 2048 WHERE `entry`= 83494;

/*Arreglo NPC 101644 Maestro de esquirlas Petragrís en Altamontaña
La spell 202358 se canaliza correctamente pero según wowhead no tiene tiempo de casteo ni de reutilización y estaba aturdiendo permanentemente al player y sin posibilidad de safarse del debuff.

La solución es la siguiente: */

UPDATE smart_scripts SET action_param2 = 1 WHERE entryorguid = 101644 AND action_param1 = 213738;


