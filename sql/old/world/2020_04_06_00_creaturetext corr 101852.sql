REPLACE INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
('101852','0','0','Here we are - my old sanctuary!','12','0','100','1','0','67275','104154','Chief Telemancer Oculeth to Player'),
('101852','1','0','Strange... the defenses are offline...','12','0','100','1','0','67276','104155','Chief Telemancer Oculeth to Player'),
('101852','2','0','Intruders! How did they get in here?!','12','0','100','1','0','67277','104156','Chief Telemancer Oculeth to Player'),
('101852','3','0','This coil taps into the ancient leylines. Crank it up to full power!','12','0','100','1','0','67278','104221','Chief Telemancer Oculeth to Player'),
('101852','4','0','Good. If we overcharge enough coils, the entire system will failsafe into a lockdown.','12','0','100','0','0','67280','104224','Chief Telemancer Oculeth to Player'),
('101852','5','0','There are more coils in the chamber below - and more intruders, I imagine.','12','0','100','0','0','67279','104223','Chief Telemancer Oculeth to Player'),
('101852','6','0','Thwen... I should have recognized your uniquely oafish meddling on my network.','12','0','100','25','0','67292','104157','Chief Telemancer Oculeth to Player'),
('101852','7','0','I can deal with Thwen. You overload the coils!','12','0','100','1','0','67296','104161','Chief Telemancer Oculeth to Player');

REPLACE into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values
('96176','0','0','1','54','0','100','1','0','0','0','0','207','0','0','0','0','0','0','7','0','0','0','0','0','0','0','JS - SPI'),
('96176','0','1','0','61','0','100','1','0','0','0','0','80','96176','2','0','0','0','0','1','0','0','0','0','0','0','0','L - RTS'),
('96176','9','0','0','0','0','100','1','1800','1800','0','0','1','3','4000','0','0','0','0','1','0','0','0','0','0','0','0','TS - ST'),
('96176','9','1','0','0','0','100','0','0','0','0','0','12','96175','3','45000','0','0','0','8','0','0','0','3503.06','2164.7','231.29','6.25475','summon npc 96175');
