-- Changed wrong values for npc vendor id 121282 --
update  `conditions` set `ConditionValue1`= 46178 where `SourceEntry` in(143490, 143491) and `ConditionValue1`= 46337;