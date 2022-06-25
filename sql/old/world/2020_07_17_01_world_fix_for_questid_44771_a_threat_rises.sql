-- new gossip for npc havi --
delete from `gossip_menu_option` where `MenuID`= 20539 and `OptionIndex`= 0;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionNPC`, `OptionText`, `OptionType`, `OptionNpcflag`, `OptionNpcflag2`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxCurrency`, `BoxText`, `OptionBroadcastTextID`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES 
('20539', '0', '0', 'Entregar ponche', '1', '1', '0', '0', '0', '0', '0', '0', '', '0', '0', '0');

-- gossip condition --
delete from `conditions` where `SourceGroup`= 20539 and `SourceEntry`= 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
('15', '20539', '0', '0', '0', '1', '0', '229539', '0', '0', '0', '0', '', '');

-- gossip SAI --
delete from `smart_scripts` where `entryorguid`= 92539 and  `action_type` in( 223, 28);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(92539, 0, 3, 0, 62, 0, 100, 0, 20539, 0, 0, 0, 223, 44771, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0),
(92539, 0, 4, 0, 62, 0, 100, 0, 20539, 0, 0, 0, 28, 229539, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0);

-- game object 266054 update data and phases --
update `gameobject_template` set `Data1`= 44771 where `entry`= 266054;
update `gameobject_template` set `Data22`= 0 where `entry`= 266054;
update `gameobject` set `PhaseId`= 0 where `id`= 266054;

