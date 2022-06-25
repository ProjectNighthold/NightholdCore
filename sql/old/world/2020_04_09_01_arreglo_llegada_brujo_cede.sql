/* Arreglo brujo para que funcione en la fase correcta a la hora de hacer las misiones de llegada a cede de clase*/

/*Borrado de npcs en mapa 1220 relativos a la mision*/

DELETE FROM creature WHERE id IN (101433,101455,101457,101456,101454,98797) AND map=1502;
/*Agregado de SAI para ubicar al player en el mapa correcto*/
REPLACE INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values('101456','0','14','0','19','0','100','0','40729','0','0','0','62','1220','0','0','0','0','0','7','0','0','0','-856.426','4456.5','695.943','4.0753','Teleport to correct map');
REPLACE INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values('101097','0','5','0','20','0','100','0','40729','0','0','0','62','1107','0','0','0','0','0','7','0','0','0','3121.29','1106.27','286.578','5.2107','Reubicacion de player al finalizar quest 40729 al mapa 1107');

/*Cambio de flags para SAI de portal para que se pueda repetir el evento */
update smart_scripts set event_flags=0 where entryorguid=101433;

/*Cambio de tiempos de respawn a los npc involucrados en el evento*/
UPDATE creature SET spawntimesecs=60 WHERE id IN (101433,101455,101457,101456,101454,98797,101097);