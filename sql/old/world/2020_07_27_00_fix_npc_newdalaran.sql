/* reparacion npc dalaran nuevo de piedra hogar q no funcionaba */
UPDATE creature_template SET AIName ='0', ScriptName='npc_innkeeper' WHERE entry =96806;