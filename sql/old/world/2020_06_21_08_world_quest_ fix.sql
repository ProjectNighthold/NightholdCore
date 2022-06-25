-- http://10.96.2.10/bugtracker/view.php?id=273 world quest de Argus que le dava problemas a algunos usuarios.
DELETE FROM `gossip_menu_option` WHERE `MenuID`=21238 AND `OptionIndex`=4;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionNPC`, `OptionText`, `OptionType`, `OptionNpcflag`, `OptionNpcflag2`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxCurrency`, `BoxText`, `OptionBroadcastTextID`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES (21238, 4, 0, '¿Haz perdido tu cristal? Toma otro.', 1, 1, 0, 0, 0, 0, 0, 0, NULL, 0, 0, 0);

DELETE FROM `smart_scripts` WHERE `entryorguid`=123413 AND `source_type`=0 AND `id`=6 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES (123413, 0, 6, 0, 62, 0, 100, 0, 21238, 4, 0, 0, 56, 153249, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'en gossip 4 da item');

UPDATE `creature_template_wdb` SET `Name1`='Archmage Y\'mera' WHERE (`Entry`='123413');