-- Numbo's Customs --
-- Mounts Guide --
-- Part1: Custom Creature --

-- 1.1 Create a custom creature template
-- Important values to change for mounts:
-- entry 				= unique NPC ID	(Custom Mounts 4400000 - 4499999)spell
DELETE FROM creature_template WHERE `entry`=4400000;
INSERT INTO creature_template 								(`entry`	, `gossip_menu_id`, `minlevel`, `maxlevel`, `SandboxScalingID`	, `ScaleLevelMin`	, `ScaleLevelMax`	, `ScaleLevelDelta`	, `ScaleLevelDuration`	, `exp`	, `faction`	, `npcflag`	, `npcflag2`, `speed_walk`	, `speed_run`	, `speed_fly`	, `scale`, `mindmg`	, `maxdmg`	, `dmgschool`	, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`	, `unit_class`	, `unit_flags`	, `unit_flags2`, `unit_flags3`, `dynamicflags`	, `trainer_type`	, `trainer_spell`	, `trainer_class`	, `trainer_race`	, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `lootid`	, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`	, `spell2`	, `spell3`	, `spell4`	, `spell5`	, `spell6`	, `spell7`	, `spell8`	, `PetSpellDataId`, `VehicleId`	, `mingold`	, `maxgold`	, `AIName`	, `MovementType`	, `InhabitType`, `HoverHeight`, `Mana_mod_extra`, `Armor_mod`	, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ControllerID`	, `WorldEffects`	, `PassiveSpells`	, `StateWorldEffectID`	, `SpellStateVisualID`	, `SpellStateAnimID`	, `SpellStateAnimKitID`	, `IgnoreLos`	, `AffixState`	, `MaxVisible`	, `ScriptName`	)
VALUES 																				(4400000	, 0					, 1			, 1			, 0						, 0					, 0					, 0						, 0							, 2		, 35			, 0			, 0			, 1				, 1.14286		, 1.14286		, 1		, 1			, 2			, 0				, 0				, 1					, 2000				, 0						, 1				, 0				, 2048			, 0				, 8					, 0					, 0					, 0					, 0					, 1				, 1				, 0						, 0			, 0					, 0			, 0				, 0				, 0				, 0				, 0				, 0				, 0			, 0			, 0			, 0			, 0			, 0			, 0			, 0			, 0					, 0				, 0			, 0			, ''			, 0					, 3				, 1				, 1					, 1				, 1				, 0							, 0				, 0					, ''					, ''					, 0							, 0							, 0						, 0							, 0				, 0				, 0				, ''				);



-- 1.2 Create template extension
-- Important values to change for flying mounts:
-- Entry 				= creature_template `entry`
-- Name1 				= NPC Name
-- Type 					= https://wow.tools/dbc/?dbc=creaturetype&build=7.3.5.26972#page=1
-- Displayid1 			= .npc info (ingame)
-- MovementInfoID		= 113
-- VerifiedBuild 		= Custom Dev Number ( choose yourself a number and stick with it; so you know what you edit )

-- Important values to change for ground mounts:
-- Entry 				= creature_template `entry`
-- Name1 				= NPC Name
-- Type 					= https://wow.tools/dbc/?dbc=creaturetype&build=7.3.5.26972#page=1
-- Displayid1 			= .npc info (ingame)
-- MovementInfoID		= 140
-- VerifiedBuild 		= Custom Dev Number ( choose yourself a number and stick with it; so you know what you edit )
DELETE FROM creature_template_wdb WHERE `Entry`=4400000;
INSERT INTO creature_template_wdb 							(`Entry`	, `Name1`			, `Name2`, `Name3`, `Name4`, `NameAlt1`, `NameAlt2`, `NameAlt3`, `NameAlt4`, `Title`, `TitleAlt`, `CursorName`		, `TypeFlags`	, `TypeFlags2`	, `Type`	, `Family`	, `Classification`, `KillCredit1`, `KillCredit2`, `VignetteID`	, `Displayid1`	, `Displayid2`	, `Displayid3`	, `Displayid4`	, `HpMulti`	, `PowerMulti`	, `Leader`	, `QuestItem1`	, `QuestItem2`	, `QuestItem3`	, `QuestItem4`	, `QuestItem5`	, `QuestItem6`	, `QuestItem7`	, `QuestItem8`	, `QuestItem9`	, `QuestItem10`, `MovementInfoID`, `RequiredExpansion`, `FlagQuest`	, `VerifiedBuild`	)
VALUES 																				(4400000	, 'Test Mount'		, ''		, ''		, ''		, ''			, ''			, ''			, ''			, ''		, ''			, 'vehichleCursor', 0				, 0				, 2		, 0			, 0					, 0				, 0				, 0				, 497				, 0				, 0				, 0				, 5.95238	, 1.6				, 0			, 0				, 0				, 0				, 0				, 0				, 0				, 0				, 0				, 0				, 0				, 113					, 2						, 0				, 4200				);






-- 3.3 Add to mount collection list
-- Important values to change for mounts:
-- spell 						= legion_hotfixes.spell `ID`
-- name							= Mount name
DELETE FROM mount_list WHERE `spell`=4400000;
INSERT INTO mount_list 										(`spell`	, `side`	, `spellS`	, `sideS`, `name`			)
VALUES 																				(4400000	, 0		, 0			, 0		, 'Test Mount'	);

--   ()()
--  (°-°)
--  (@)(@)
