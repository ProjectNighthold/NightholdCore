-- Change hitbox because invi wall dont disapp
-- Al'Akir first model --
UPDATE creature_model_info SET BoundingRadius =         12 WHERE DisplayID = 35248;
UPDATE creature_model_info SET CombatReach =            24 WHERE DisplayID = 35248;

-- Al'Akir sec model --
UPDATE creature_model_info SET BoundingRadius =         15 WHERE DisplayID = 36062;
UPDATE creature_model_info SET CombatReach =            30 WHERE DisplayID = 36062; 


UPDATE access_requirement SET item_level = 0 WHERE difficulty = 1;
UPDATE access_requirement SET item_level = 0 WHERE difficulty = 2;
