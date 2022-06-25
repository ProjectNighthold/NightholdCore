/* [Venganza... servida fría] 42202 */


DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`='23') AND (`SourceGroup`='7503') AND (`SourceEntry`='275') AND (`SourceId`='0') AND (`ElseGroup`='1') AND (`ConditionTypeOrReference`='14') AND (`ConditionTarget`='0') AND (`ConditionValue1`='42202') AND (`ConditionValue2`='0') AND (`ConditionValue3`='0');
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`='23') AND (`SourceGroup`='7503') AND (`SourceEntry`='277') AND (`SourceId`='0') AND (`ElseGroup`='1') AND (`ConditionTypeOrReference`='28') AND (`ConditionTarget`='0') AND (`ConditionValue1`='42202') AND (`ConditionValue2`='0') AND (`ConditionValue3`='0');
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`='23') AND (`SourceGroup`='7503') AND (`SourceEntry`='276') AND (`SourceId`='0') AND (`ElseGroup`='0') AND (`ConditionTypeOrReference`='9') AND (`ConditionTarget`='0') AND (`ConditionValue1`='42202') AND (`ConditionValue2`='0') AND (`ConditionValue3`='0');
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`='23') AND (`SourceGroup`='7503') AND (`SourceEntry`='277') AND (`SourceId`='0') AND (`ElseGroup`='0') AND (`ConditionTypeOrReference`='8') AND (`ConditionTarget`='0') AND (`ConditionValue1`='42202') AND (`ConditionValue2`='0') AND (`ConditionValue3`='0');

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES ('23', '7503', '275', '0', '1', '14', '0', '42202', '0', '0', '0', '0', '', 'Activate Phase - If Player NHCR Quest');
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES ('23', '7503', '277', '0', '1', '28', '0', '42202', '0', '0', '0', '0', '', 'Activate Phase - If Player C Quest');
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES ('23', '7503', '276', '0', '0', '9', '0', '42202', '0', '0', '0', '0', '', 'Activate Phase - If Player H Quest');
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES ('23', '7503', '277', '0', '0', '8', '0', '42202', '0', '0', '0', '0', '', 'Activate Phase - If Player R Quest');


DELETE FROM `phase_definitions` WHERE (`zoneId`='7503') AND (`entry`='278');
DELETE FROM `phase_definitions` WHERE (`zoneId`='7503') AND (`entry`='277');
DELETE FROM `phase_definitions` WHERE (`zoneId`='7503') AND (`entry`='276');
INSERT INTO `phase_definitions` (`zoneId`, `entry`, `phasemask`, `phaseId`, `PreloadMapID`, `VisibleMapID`, `UiWorldMapAreaID`, `flags`, `comment`) VALUES ('7503', '278', '0', '6192', '0', '0', '0', '16', '42202 Quest');
INSERT INTO `phase_definitions` (`zoneId`, `entry`, `phasemask`, `phaseId`, `PreloadMapID`, `VisibleMapID`, `UiWorldMapAreaID`, `flags`, `comment`) VALUES ('7503', '277', '0', '6192', '0', '0', '0', '16', '42202 Quest');
INSERT INTO `phase_definitions` (`zoneId`, `entry`, `phasemask`, `phaseId`, `PreloadMapID`, `VisibleMapID`, `UiWorldMapAreaID`, `flags`, `comment`) VALUES ('7503', '276', '0', '6192', '0', '0', '0', '16', '42202 Quest');
