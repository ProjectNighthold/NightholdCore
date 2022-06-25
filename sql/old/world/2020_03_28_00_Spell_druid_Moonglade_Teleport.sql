/* Eliminando script name */
DELETE FROM `spell_script_names` WHERE `spell_id`='18960';

/* Esta tabla fija el target para un spell de teleport y no es necesario pues se ejecuta en el SpellEffect
Ademas de impedir el retorno de la ubicacion anterior */
DELETE FROM `spell_target_position` WHERE (`id`='18960');
