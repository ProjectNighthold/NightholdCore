/*fix https://es.wowhead.com/quest=36384/prueba-sobre-el-terreno */
-- Actionlist SAI
SET @ENTRY := 8118300;
DELETE FROM smart_scripts WHERE entryorguid=@ENTRY AND source_type=9;
INSERT INTO smart_scripts (entryorguid,source_type,id,link,event_type,event_phase_mask,event_chance,event_flags,event_param1,event_param2,event_param3,event_param4,action_type,action_param1,action_param2,action_param3,action_param4,action_param5,action_param6,target_type,target_param1,target_param2,target_param3,target_x,target_y,target_z,target_o,comment) VALUES
(@ENTRY,9,0,0,0,0,100,0,5000,5000,0,0,85,102133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Invo Cast");

--  SAI
SET @ENTRY := 81183;
UPDATE creature_template SET AIName="SmartAI" , scriptname ="" WHERE entry= @ENTRY;
DELETE FROM smart_scripts WHERE entryorguid=@ENTRY AND source_type=0;
INSERT INTO smart_scripts (entryorguid,source_type,id,link,event_type,event_phase_mask,event_chance,event_flags,event_param1,event_param2,event_param3,event_param4,action_type,action_param1,action_param2,action_param3,action_param4,action_param5,action_param6,target_type,target_param1,target_param2,target_param3,target_x,target_y,target_z,target_o,comment) VALUES
(@ENTRY,0,0,0,8,0,100,0,170308,0,0,0,33,85258,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kill Credit"),
(@ENTRY,0,1,0,8,0,100,0,170308,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Npc_AI"),
(@ENTRY,0,2,0,8,0,100,0,170308,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Action List"),
(@ENTRY,0,3,0,8,0,100,0,170554,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Set Faction"),
(@ENTRY,0,4,0,8,0,100,0,170554,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Say Line Event"),
(@ENTRY,0,5,0,8,0,100,0,170554,0,0,0,41,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Despawn"),
(@ENTRY,0,6,0,4,0,100,0,0,0,0,0,42,0,14,0,0,0,0,1,0,0,0,0,0,0,0,"Set Invincibility hp"),
(@ENTRY,0,7,0,0,0,100,0,0,0,0,0,42,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Set Invincibility hp");