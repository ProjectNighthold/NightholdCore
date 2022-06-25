/* Open Quest */

SET @OPQ1 := 116490;
SET @OPQ2 := 119945;
SET @CallactionL := 119781;
SET @Lixahl1 := 119945;
SET @LixahlEND := 119947;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@OPQ1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@OPQ1 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@OPQ1,0,0,1,62,0,100,0,20683,0,0,0,33,116490,0,0,0,0,0,7,0,0,0,0,0,0,0,"killcredit"),
(@OPQ1,0,1,0,61,0,100,0,0,0,0,0,85,238529,0,0,0,0,0,7,0,0,0,0,0,0,0,"spellcast_on_player"),
(@OPQ1,0,3,0,62,0,100,0,20683,1,0,0,85,232013,0,0,0,0,0,7,0,0,0,0,0,0,0,"end");


UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@OPQ2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@OPQ2 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@OPQ2,0,0,0,10,0,100,1,0,50,0,0,205,0,119918,1,0,0,0,7,0,0,0,0,0,0,0,"killcredit"),
(@OPQ2,0,1,2,2,0,100,1,0,30,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0," faction 35"),
(@OPQ2,0,2,3,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"off combat"),
(@OPQ2,0,3,4,61,0,100,0,0,0,0,0,27,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"off avtoattack"),
(@OPQ2,0,4,5,61,0,100,0,0,0,0,0,205,0,119920,1,0,0,0,18,50,0,0,0,0,0,0,"link- add killcredit"),
(@OPQ2,0,5,6,61,0,100,0,0,0,0,0,202,2070,88,-48,0,0,0,1,0,0,0,0,0,0,0,"link- move fly xZy"),
(@OPQ2,0,6,0,61,0,100,0,0,0,0,0,41,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,"link- despawn "),
(@OPQ2,0,7,0,0,0,100,0,7000,8000,14000,16000,11,238617,0,0,0,0,0,2,0,0,0,0,0,0,0,"spell1"),
(@OPQ2,0,8,0,0,0,100,0,15000,25000,30000,50000,11,241117,0,0,0,0,0,2,0,0,0,0,0,0,0,"spell2"),
(@OPQ2,0,9,0,0,0,100,0,14000,26000,28000,53000,11,238619,0,0,0,0,0,2,0,0,0,0,0,0,0,"spell3"),
(@OPQ2,0,10,0,0,0,100,0,9000,10000,18000,19000,11,238618,0,0,0,0,0,2,0,0,0,0,0,0,0,"spell4");

/* Event Gesta Questid-46334*/
/* Fase 2*/

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@CallactionL;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@CallactionL AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@CallactionL,0,0,0,62,0,100,0,20894,0,0,0,80,@CallactionL*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"actions-1"),
(@CallactionL,0,1,0,38,0,100,0,1,1,0,0,80,@CallactionL*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"actions2"),
(@CallactionL,0,2,0,54,0,100,0,0,0,0,0,80,@CallactionL*100+02,0,0,0,0,0,1,0,0,0,0,0,0,0,"actions3");

/* Lixahl npc1-id-119916 */

UPDATE `creature_template` SET `AIName`='SmartAI', `InhabitType`='3' WHERE 
(`entry`='119916');

/* Fase 4 npc2-id-119945 */

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@Lixahl1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Lixahl1 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Lixahl1,0,0,0,10,0,100,1,0,50,0,0,205,0,119918,1,0,0,0,7,0,0,0,0,0,0,0,"smart_killcredit"),
(@Lixahl1,0,1,2,2,0,100,1,0,30,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"in hp-add faction 35"),
(@Lixahl1,0,2,3,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"in hp-off combat"),
(@Lixahl1,0,3,4,61,0,100,0,0,0,0,0,27,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"in hp-off avtoattack"),
(@Lixahl1,0,4,5,61,0,100,0,0,0,0,0,205,0,119920,1,0,0,0,18,50,0,0,0,0,0,0,"link- add killcredit_on-player"),
(@Lixahl1,0,5,6,61,0,100,0,0,0,0,0,202,2070,88,-48,0,0,0,1,0,0,0,0,0,0,0,"link- move fly xZy"),
(@Lixahl1,0,6,0,61,0,100,0,0,0,0,0,41,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,"link- despawn on yourself"),
(@Lixahl1,0,7,0,0,0,100,0,7000,8000,14000,16000,11,238617,0,0,0,0,0,2,0,0,0,0,0,0,0,"spellcast_for_player"),
(@Lixahl1,0,8,0,0,0,100,0,15000,25000,30000,50000,11,241117,0,0,0,0,0,2,0,0,0,0,0,0,0,"spellcast_for_player"),
(@Lixahl1,0,9,0,0,0,100,0,14000,26000,28000,53000,11,238619,0,0,0,0,0,2,0,0,0,0,0,0,0,"spellcast_for_player"),
(@Lixahl1,0,10,0,0,0,100,0,9000,10000,18000,19000,11,238618,0,0,0,0,0,2,0,0,0,0,0,0,0,"spellcast_for_player");

/* Fase 5  Sigue el rastro de lixahl */

/* Fase 6 npc3-id-119947 (Salto de fe) */

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@LixahlEND;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@LixahlEND AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@LixahlEND,0,0,1,10,0,100,1,1,35,0,0,62,1732,0,0,0,0,0,7,0,0,0,1430.13,-150.496,-186.246,3.83544,"Salto de fe "),
(@LixahlEND,0,1,2,61,0,100,0,0,0,0,0,53,1,119947,0,0,0,0,1,0,0,0,0,0,0,0,"link-wp_start"),
(@LixahlEND,0,2,3,61,0,100,0,0,0,0,0,205,0,121316,1,0,0,0,18,50,0,0,0,0,0,0,"link- killcredit"),
(@LixahlEND,0,3,4,61,0,100,0,0,0,0,0,2,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"link- add aura"),
(@LixahlEND,0,4,0,61,0,100,0,0,0,0,0,80,@LixahlEND*100+00,2,1,0,0,0,1,0,0,0,0,0,0,0,"link- actions"),
(@LixahlEND,0,5,6,2,0,100,1,0,5,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"OOC_LOS-change factions"),
(@LixahlEND,0,6,7,61,0,100,0,0,0,0,0,205,0,119947,1,0,0,0,18,50,0,0,0,0,0,0,"link- killcredit"),
(@LixahlEND,0,7,8,61,0,100,0,0,0,0,0,12,119947,7,0,0,0,0,1,0,0,0,0,0,0,0,"link- out-combat"),
(@LixahlEND,0,9,10,8,0,100,0,238603,0,0,0,86,238603,0,18,10,0,0,1,0,0,0,0,0,0,0,"OOC_LOS-CROSS_CAST"),
(@LixahlEND,0,10,0,61,0,100,0,0,0,0,0,53,1,119948,0,0,0,0,1,0,0,0,0,0,0,0,"link-wp_start"),
(@LixahlEND,0,11,0,0,0,100,0,7000,8000,14000,16000,11,238617,0,0,0,0,0,2,0,0,0,0,0,0,0,"spellcast_for_player"),
(@LixahlEND,0,12,0,0,0,100,0,15000,25000,30000,50000,11,241117,0,0,0,0,0,2,0,0,0,0,0,0,0,"spellcast_for_player"),
(@LixahlEND,0,13,0,0,0,100,0,14000,26000,28000,53000,11,238619,0,0,0,0,0,2,0,0,0,0,0,0,0,"spellcast_for_player"),
(@LixahlEND,0,14,0,0,0,100,0,9000,10000,18000,19000,11,238618,0,0,0,0,0,2,0,0,0,0,0,0,0,"spellcast_for_player");
