
UPDATE `playercreateinfo` SET `position_x`=1704.12, `position_y`=1704.64, `position_z`=133.95, `orientation`=4.70 WHERE `race`=5 and `map`=0 and `zone`=5692;

UPDATE `creature` SET `position_x`=1704.32, `position_y`=1702.44, `position_z`=137.26, `orientation`=1.59 WHERE `id`=49044;

UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_agatha' WHERE `entry`=49044;
