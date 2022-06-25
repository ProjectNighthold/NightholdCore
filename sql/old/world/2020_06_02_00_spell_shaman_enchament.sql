/* Colatifon (spell id 195255) ahora se activa con Son del viento , Derrumblo Relampago Estruendoso, Totem de viento furioso */
DELETE FROM `spell_proc_check` WHERE `entry`='195255' AND `hastalent`='202004';
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) VALUES ('195255', '0', '0', '0', '202004', '0', '0', '7', '-1', '-1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Бурехлест');
DELETE FROM `spell_proc_check` WHERE `entry`='195255' AND `hastalent`='201898';
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) VALUES ('195255', '0', '0', '0', '201898', '0', '0', '7', '-1', '-1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Бурехлест');
DELETE FROM `spell_proc_check` WHERE `entry`='195255' AND `hastalent`='187878';
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) VALUES ('195255', '0', '0', '0', '187878', '0', '0', '7', '-1', '-1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Бурехлест');

/* Portador de Tormentas 201845  fue escriptado en Core */
DELETE FROM `spell_proc_event` WHERE (`entry`='194084') AND (`effectmask`='2');
DELETE FROM `spell_trigger` WHERE (`spell_id`='201845') AND (`spell_trigger`='201846') AND (`option`='20') AND (`bp0`='0') AND (`effectmask`='7') AND (`aura`='0') AND (`check_spell_id`='0') AND (`addptype`='-1') AND (`CreatureType`='0');

/*  Esta anterior a la revision
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) VALUES ('194084', '0', '11', '8454144', '0', '2101252', '0', '8388628', '0', '0', '0', '0', '2');

INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `spell_cooldown`, `option`, `target`, `caster`, `targetaura`, `targetaura2`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `aura2`, `chance`, `group`, `procFlags`, `procEx`, `check_spell_id`, `addptype`, `schoolMask`, `dummyId`, `dummyEffect`, `CreatureType`, `slot`, `randList`, `comment`) VALUES ('201845', '201846', '0', '20', '0', '0', '0', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '-1', '0', '0', '0', '0', '0', '', 'Вестник шторма');
*/

/* Tormenta estruendosa ( talento level 90 spell id 192246) */
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='187874') AND (`spell_effect`='210801') AND (`type`='6') AND (`caster`='0') AND (`target`='0') AND (`hastalent`='192246') AND (`effectMask`='0') AND (`actiontype`='0');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastype`, `hastalent`, `hasparam`, `hastype2`, `hastalent2`, `hasparam2`, `chance`, `cooldown`, `duration`, `hitmask`, `removeMask`, `effectMask`, `targetCountType`, `targetCount`, `actiontype`, `group`, `param`, `randList`, `comment`) VALUES ('187874', '210801', '6', '0', '0', '0', '192246', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '-1', '0', '0', '0', '', 'Сокрушающая буря');
