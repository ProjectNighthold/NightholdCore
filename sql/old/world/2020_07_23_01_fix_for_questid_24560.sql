-- update wrong data in smart_scripts for quest id 24560--
update `smart_scripts` set `event_chance`= 100 where `entryorguid`= 37094;
update `smart_scripts` set `event_type`= 8 where `entryorguid`= 37094 and `action_param1`= 69956;
update `smart_scripts` set `action_type`= 85 where `entryorguid`= 37094 and `action_param1`= 69956;

-- spawned npc id 39942 --
delete from `creature` where `guid`= 6760009;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
('6760009', '36642', '571', '210', '4862', '1', '1', '', '0', '0', '5609.76', '2038.55', '798.043', '5.38782', '120', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');

