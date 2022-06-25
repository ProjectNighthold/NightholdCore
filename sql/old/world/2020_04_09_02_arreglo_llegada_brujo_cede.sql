
/* cambio de phaseid npcs de brujo */
UPDATE creature SET phaseid=0 WHERE id IN (101433,101455,101457,101456,101454,98797) AND map=1220;
/* arreglo del portal del brujo para ir a mision clase */
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
('101433','0','6','0','61','0','100','0','0','0','0','0','37','0','0','0','0','0','0','1','0','0','0','0','0','0','0','El npc muere luego del evento');
UPDATE smart_scripts SET link=6 WHERE entryorguid=101433 AND id=5;
/* cambio de loot */
UPDATE gameobject_template SET Data1 = '245924' WHERE entry = '245924';
UPDATE gameobject_loot_template SET ChanceOrQuestChance = '100' WHERE entry = '245924';
/* reinicio de dialogo */
UPDATE smart_scripts SET event_flags=0 WHERE entryorguid=98771;
