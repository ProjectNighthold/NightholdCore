-- Sortet and added Battlepay Group
DELETE FROM `battlepay_product_group` WHERE `GroupID`=1;
INSERT INTO `battlepay_product_group` (`GroupID`, `Name`, `IconFileDataID`, `DisplayType`, `Ordering`) VALUES (1, 'Flying Mounts', 236231, 0, 1);
DELETE FROM `battlepay_product_group` WHERE `GroupID`=2;
INSERT INTO `battlepay_product_group` (`GroupID`, `Name`, `IconFileDataID`, `DisplayType`, `Ordering`) VALUES (2, 'Pets', 132599, 0, 3);
DELETE FROM `battlepay_product_group` WHERE `GroupID`=3;
INSERT INTO `battlepay_product_group` (`GroupID`, `Name`, `IconFileDataID`, `DisplayType`, `Ordering`) VALUES (3, 'Services', 136243, 0, 6);
DELETE FROM `battlepay_product_group` WHERE `GroupID`=5;
INSERT INTO `battlepay_product_group` (`GroupID`, `Name`, `IconFileDataID`, `DisplayType`, `Ordering`) VALUES (5, 'Professions', 134939, 0, 11);
DELETE FROM `battlepay_product_group` WHERE `GroupID`=7;
INSERT INTO `battlepay_product_group` (`GroupID`, `Name`, `IconFileDataID`, `DisplayType`, `Ordering`) VALUES (7, '|cffa335eeArmor', 1030904, 0, 9);
DELETE FROM `battlepay_product_group` WHERE `GroupID`=8;
INSERT INTO `battlepay_product_group` (`GroupID`, `Name`, `IconFileDataID`, `DisplayType`, `Ordering`) VALUES (8, 'Promotions', 237244, 2, 0);
DELETE FROM `battlepay_product_group` WHERE `GroupID`=9;
INSERT INTO `battlepay_product_group` (`GroupID`, `Name`, `IconFileDataID`, `DisplayType`, `Ordering`) VALUES (9, 'Toys', 133865, 0, 4);
DELETE FROM `battlepay_product_group` WHERE `GroupID`=10;
INSERT INTO `battlepay_product_group` (`GroupID`, `Name`, `IconFileDataID`, `DisplayType`, `Ordering`) VALUES (10, 'Elixirs & Flasks', 134863, 0, 7);
DELETE FROM `battlepay_product_group` WHERE `GroupID`=11;
INSERT INTO `battlepay_product_group` (`GroupID`, `Name`, `IconFileDataID`, `DisplayType`, `Ordering`) VALUES (11, 'Bag', 133643, 0, 8);
DELETE FROM `battlepay_product_group` WHERE `GroupID`=12;
INSERT INTO `battlepay_product_group` (`GroupID`, `Name`, `IconFileDataID`, `DisplayType`, `Ordering`) VALUES (12, 'Artifact Relics', 237244, 0, 10);
DELETE FROM `battlepay_product_group` WHERE `GroupID`=16;
INSERT INTO `battlepay_product_group` (`GroupID`, `Name`, `IconFileDataID`, `DisplayType`, `Ordering`) VALUES (16, '|cffff8000Appearances', 133123, 0, 5);
DELETE FROM `battlepay_product_group` WHERE `GroupID`=17;
INSERT INTO `battlepay_product_group` (`GroupID`, `Name`, `IconFileDataID`, `DisplayType`, `Ordering`) VALUES (17, 'Ground Mounts', 236245, 0, 2);


-- PvP Reward Mounts added to BattlePay
DELETE FROM `battlepay_product_item` WHERE `ID`=5026;
DELETE FROM `battlepay_product_item` WHERE `ID`=5027;
DELETE FROM `battlepay_product_item` WHERE `ID`=5028;
DELETE FROM `battlepay_product_item` WHERE `ID`=5029;
DELETE FROM `battlepay_product_item` WHERE `ID`=5030;
DELETE FROM `battlepay_product_item` WHERE `ID`=5031;
DELETE FROM `battlepay_product_item` WHERE `ID`=5032;
DELETE FROM `battlepay_product_item` WHERE `ID`=5033;
DELETE FROM `battlepay_product_item` WHERE `ID`=5034;
DELETE FROM `battlepay_product_item` WHERE `ID`=5035;
DELETE FROM `battlepay_product_item` WHERE `ID`=5036;
DELETE FROM `battlepay_product_item` WHERE `ID`=5037;
DELETE FROM `battlepay_product_item` WHERE `ID`=5038;
DELETE FROM `battlepay_product_item` WHERE `ID`=5039;
DELETE FROM `battlepay_product_item` WHERE `ID`=5040;
DELETE FROM `battlepay_product_item` WHERE `ID`=5041;
DELETE FROM `battlepay_product_item` WHERE `ID`=5042;
DELETE FROM `battlepay_product_item` WHERE `ID`=5043;
DELETE FROM `battlepay_product_item` WHERE `ID`=5044;
DELETE FROM `battlepay_product_item` WHERE `ID`=5045;
DELETE FROM `battlepay_product_item` WHERE `ID`=5046;
DELETE FROM `battlepay_product_item` WHERE `ID`=5047;
DELETE FROM `battlepay_product_item` WHERE `ID`=5048;
DELETE FROM `battlepay_product_item` WHERE `ID`=5049;
DELETE FROM `battlepay_product_item` WHERE `ID`=5050;
DELETE FROM `battlepay_product_item` WHERE `ID`=5051;
DELETE FROM `battlepay_product_item` WHERE `ID`=5052;
DELETE FROM `battlepay_product_item` WHERE `ID`=5053;
DELETE FROM `battlepay_product_item` WHERE `ID`=5054;
DELETE FROM `battlepay_product_item` WHERE `ID`=5055;
DELETE FROM `battlepay_product_item` WHERE `ID`=5056;
DELETE FROM `battlepay_product_item` WHERE `ID`=5057;
DELETE FROM `battlepay_product_item` WHERE `ID`=5058;
DELETE FROM `battlepay_product_item` WHERE `ID`=5059;
DELETE FROM `battlepay_product_item` WHERE `ID`=5060;
DELETE FROM `battlepay_product_item` WHERE `ID`=5061;
DELETE FROM `battlepay_product_item` WHERE `ID`=5062;
DELETE FROM `battlepay_product_item` WHERE `ID`=5063;
DELETE FROM `battlepay_product_item` WHERE `ID`=5064;
DELETE FROM `battlepay_product_item` WHERE `ID`=5065;
DELETE FROM `battlepay_product_item` WHERE `ID`=5066;
DELETE FROM `battlepay_product_item` WHERE `ID`=5067;
DELETE FROM `battlepay_product_item` WHERE `ID`=5068;
DELETE FROM `battlepay_product_item` WHERE `ID`=5069;
DELETE FROM `battlepay_product_item` WHERE `ID`=5070;
INSERT INTO `battlepay_product_item` (`ID`, `ProductID`, `ItemID`	, `Quantity`, `DisplayID`	, `PetResult`, `CreatureDisplayInfoID`	) 
VALUES 										 (5026, 5026			, 103533		, 1			, 0				, 0			 , 0								),
												 (5027, 5027			, 44077		, 1			, 0				, 0			 , 0								),
												 (5028, 5028			, 43956		, 1			, 0				, 0			 , 0								),
												 (5029, 5029			, 44083		, 1			, 0				, 0			 , 0								),
												 (5030, 5030			, 43959		, 1			, 0				, 0			 , 0								),
												 (5031, 5031			, 29465		, 1			, 0				, 0			 , 0								),
												 (5032, 5032			, 29471		, 1			, 0				, 0			 , 0								),
												 (5033, 5033			, 29467		, 1			, 0				, 0			 , 0								),
												 (5034, 5034			, 19030		, 1			, 0				, 0			 , 0								),
												 (5035, 5035			, 35906		, 1			, 0				, 0			 , 0								),
												 (5036, 5036			, 29468		, 1			, 0				, 0			 , 0								),
												 (5037, 5037			, 34129		, 1			, 0				, 0			 , 0								),
												 (5038, 5038			, 29466		, 1			, 0				, 0			 , 0								),
												 (5039, 5039			, 29469		, 1			, 0				, 0			 , 0								),
												 (5040, 5040			, 29472		, 1			, 0				, 0			 , 0								),
												 (5041, 5041			, 19029		, 1			, 0				, 0			 , 0								),
												 (5042, 5042			, 29470		, 1			, 0				, 0			 , 0								),
												 (5043, 5043			, 103638		, 1			, 0				, 0			 , 0								),
												 (5044, 5044			, 116775		, 1			, 0				, 0			 , 0								),
												 (5045, 5045			, 116776		, 1			, 0				, 0			 , 0								),
												 (5046, 5046			, 30609		, 1			, 0				, 0			 , 0								),
												 (5047, 5047			, 34092		, 1			, 0				, 0			 , 0								),
												 (5048, 5048			, 37676		, 1			, 0				, 0			 , 0								),
												 (5049, 5049			, 43516		, 1			, 0				, 0			 , 0								),
												 (5050, 5050			, 46708		, 1			, 0				, 0			 , 0								),
												 (5051, 5051			, 46171		, 1			, 0				, 0			 , 0								),
												 (5052, 5052			, 47840		, 1			, 0				, 0			 , 0								),
												 (5053, 5053			, 50435		, 1			, 0				, 0			 , 0								),
												 (5054, 5054			, 71339		, 1			, 0				, 0			 , 0								),
												 (5055, 5055			, 71954		, 1			, 0				, 0			 , 0								),
												 (5056, 5056			, 85785		, 1			, 0				, 0			 , 0								),
												 (5057, 5057			, 95041		, 1			, 0				, 0			 , 0								),
												 (5058, 5058			, 104325		, 1			, 0				, 0			 , 0								),
												 (5059, 5059			, 104326		, 1			, 0				, 0			 , 0								),
												 (5060, 5060			, 104327		, 1			, 0				, 0			 , 0								),
												 (5061, 5061			, 128277		, 1			, 0				, 0			 , 0								),
												 (5062, 5062			, 128281		, 1			, 0				, 0			 , 0								),
												 (5063, 5063			, 128282		, 1			, 0				, 0			 , 0								),
												 (5064, 5064			, 141843		, 1			, 0				, 0			 , 0								),
												 (5065, 5065			, 141844		, 1			, 0				, 0			 , 0								),
												 (5066, 5066			, 141845		, 1			, 0				, 0			 , 0								),
												 (5067, 5067			, 141846		, 1			, 0				, 0			 , 0								),
												 (5068, 5068			, 141847		, 1			, 0				, 0			 , 0								),
												 (5069, 5069			, 141848		, 1			, 0				, 0			 , 0								),
												 (5070, 5070			, 153493		, 1			, 0				, 0			 , 0								);

DELETE FROM `battlepay_product` WHERE `ProductID`=5026;
DELETE FROM `battlepay_product` WHERE `ProductID`=5027;
DELETE FROM `battlepay_product` WHERE `ProductID`=5028;
DELETE FROM `battlepay_product` WHERE `ProductID`=5029;
DELETE FROM `battlepay_product` WHERE `ProductID`=5030;
DELETE FROM `battlepay_product` WHERE `ProductID`=5031;
DELETE FROM `battlepay_product` WHERE `ProductID`=5032;
DELETE FROM `battlepay_product` WHERE `ProductID`=5033;
DELETE FROM `battlepay_product` WHERE `ProductID`=5034;
DELETE FROM `battlepay_product` WHERE `ProductID`=5035;
DELETE FROM `battlepay_product` WHERE `ProductID`=5036;
DELETE FROM `battlepay_product` WHERE `ProductID`=5037;
DELETE FROM `battlepay_product` WHERE `ProductID`=5038;
DELETE FROM `battlepay_product` WHERE `ProductID`=5039;
DELETE FROM `battlepay_product` WHERE `ProductID`=5040;
DELETE FROM `battlepay_product` WHERE `ProductID`=5041;
DELETE FROM `battlepay_product` WHERE `ProductID`=5042;
DELETE FROM `battlepay_product` WHERE `ProductID`=5043;
DELETE FROM `battlepay_product` WHERE `ProductID`=5044;
DELETE FROM `battlepay_product` WHERE `ProductID`=5045;
DELETE FROM `battlepay_product` WHERE `ProductID`=5046;
DELETE FROM `battlepay_product` WHERE `ProductID`=5047;
DELETE FROM `battlepay_product` WHERE `ProductID`=5048;
DELETE FROM `battlepay_product` WHERE `ProductID`=5049;
DELETE FROM `battlepay_product` WHERE `ProductID`=5050;
DELETE FROM `battlepay_product` WHERE `ProductID`=5051;
DELETE FROM `battlepay_product` WHERE `ProductID`=5052;
DELETE FROM `battlepay_product` WHERE `ProductID`=5053;
DELETE FROM `battlepay_product` WHERE `ProductID`=5054;
DELETE FROM `battlepay_product` WHERE `ProductID`=5055;
DELETE FROM `battlepay_product` WHERE `ProductID`=5056;
DELETE FROM `battlepay_product` WHERE `ProductID`=5057;
DELETE FROM `battlepay_product` WHERE `ProductID`=5058;
DELETE FROM `battlepay_product` WHERE `ProductID`=5059;
DELETE FROM `battlepay_product` WHERE `ProductID`=5060;
DELETE FROM `battlepay_product` WHERE `ProductID`=5061;
DELETE FROM `battlepay_product` WHERE `ProductID`=5062;
DELETE FROM `battlepay_product` WHERE `ProductID`=5063;
DELETE FROM `battlepay_product` WHERE `ProductID`=5064;
DELETE FROM `battlepay_product` WHERE `ProductID`=5065;
DELETE FROM `battlepay_product` WHERE `ProductID`=5066;
DELETE FROM `battlepay_product` WHERE `ProductID`=5067;
DELETE FROM `battlepay_product` WHERE `ProductID`=5068;
DELETE FROM `battlepay_product` WHERE `ProductID`=5069;
DELETE FROM `battlepay_product` WHERE `ProductID`=5070;
INSERT INTO `battlepay_product` 		(`ProductID`, `NormalPriceFixedPoint`	, `CurrentPriceFixedPoint`	, `Type`	, `ChoiceType`	, `Flags`, `DisplayInfoID`	, `ScriptName`	, `ClassMask`	, `WebsiteType`) 
VALUES 										(5026			, 80								, 80								, 0		, 2				, 54860	, 5026				, ''				, 0				, 3				),
												(5027			, 80								, 80								, 0		, 2				, 54860	, 5027				, ''				, 0				, 3				),
												(5028			, 80								, 80								, 0		, 2				, 54860	, 5028				, ''				, 0				, 3				),
												(5029			, 80								, 80								, 0		, 2				, 54860	, 5029				, ''				, 0				, 3				),
												(5030			, 80								, 80								, 0		, 2				, 54860	, 5030				, ''				, 0				, 3				),
												(5031			, 80								, 80								, 0		, 2				, 54860	, 5031				, ''				, 0				, 3				),
												(5032			, 80								, 80								, 0		, 2				, 54860	, 5032				, ''				, 0				, 3				),
												(5033			, 80								, 80								, 0		, 2				, 54860	, 5033				, ''				, 0				, 3				),
												(5034			, 80								, 80								, 0		, 2				, 54860	, 5034   			, ''				, 0				, 3				),
												(5035			, 80								, 80								, 0		, 2				, 54860	, 5035   			, ''				, 0				, 3				),
												(5036			, 80								, 80								, 0		, 2				, 54860	, 5036   			, ''				, 0				, 3				),
												(5037			, 80								, 80								, 0		, 2				, 54860	, 5037   			, ''				, 0				, 3				),
												(5038			, 80								, 80								, 0		, 2				, 54860	, 5038   			, ''				, 0				, 3				),
												(5039			, 80								, 80								, 0		, 2				, 54860	, 5039   			, ''				, 0				, 3				),
												(5040			, 80								, 80								, 0		, 2				, 54860	, 5040   			, ''				, 0				, 3				),
												(5041			, 80								, 80								, 0		, 2				, 54860	, 5041   			, ''				, 0				, 3				),
												(5042			, 80								, 80								, 0		, 2				, 54860	, 5042   			, ''				, 0				, 3				),
												(5043			, 80								, 80								, 0		, 2				, 54860	, 5043   			, ''				, 0				, 3				),
												(5044			, 80								, 80								, 0		, 2				, 54860	, 5044   			, ''				, 0				, 3				),
												(5045			, 80								, 80								, 0		, 2				, 54860	, 5045   			, ''				, 0				, 3				),
												(5046			, 80								, 80								, 0		, 2				, 54860	, 5046   			, ''				, 0				, 3				),
												(5047			, 80								, 80								, 0		, 2				, 54860	, 5047   			, ''				, 0				, 3				),
												(5048			, 80								, 80								, 0		, 2				, 54860	, 5048   			, ''				, 0				, 3				),
												(5049			, 80								, 80								, 0		, 2				, 54860	, 5049   			, ''				, 0				, 3				),
												(5050			, 80								, 80								, 0		, 2				, 54860	, 5050   			, ''				, 0				, 3				),
												(5051			, 80								, 80								, 0		, 2				, 54860	, 5051	  			, ''				, 0				, 3				),
												(5052			, 80								, 80								, 0		, 2				, 54860	, 5052	  			, ''				, 0				, 3				),
												(5053			, 80								, 80								, 0		, 2				, 54860	, 5053	  			, ''				, 0				, 3				),
												(5054			, 80								, 80								, 0		, 2				, 54860	, 5054	  			, ''				, 0				, 3				),
												(5055			, 80								, 80								, 0		, 2				, 54860	, 5055	  			, ''				, 0				, 3				),
												(5056			, 80								, 80								, 0		, 2				, 54860	, 5056	  			, ''				, 0				, 3				),
												(5057			, 80								, 80								, 0		, 2				, 54860	, 5057	  			, ''				, 0				, 3				),
												(5058			, 80								, 80								, 0		, 2				, 54860	, 5058	  			, ''				, 0				, 3				),
												(5059			, 80								, 80								, 0		, 2				, 54860	, 5059	  			, ''				, 0				, 3				),
												(5060			, 80								, 80								, 0		, 2				, 54860	, 5060	  			, ''				, 0				, 3				),
												(5061			, 80								, 80								, 0		, 2				, 54860	, 5061	  			, ''				, 0				, 3				),
												(5062			, 80								, 80								, 0		, 2				, 54860	, 5062	  			, ''				, 0				, 3				),
												(5063			, 80								, 80								, 0		, 2				, 54860	, 5063	  			, ''				, 0				, 3				),
												(5064			, 80								, 80								, 0		, 2				, 54860	, 5064	  			, ''				, 0				, 3				),
												(5065			, 80								, 80								, 0		, 2				, 54860	, 5065	  			, ''				, 0				, 3				),
												(5066			, 80								, 80								, 0		, 2				, 54860	, 5066	  			, ''				, 0				, 3				),
												(5067			, 80								, 80								, 0		, 2				, 54860	, 5067	  			, ''				, 0				, 3				),
												(5068			, 80								, 80								, 0		, 2				, 54860	, 5068	  			, ''				, 0				, 3				),
												(5069			, 80								, 80								, 0		, 2				, 54860	, 5069	  			, ''				, 0				, 3				),
												(5070			, 80								, 80								, 0		, 2				, 54860	, 5070	  			, ''				, 0				, 3				);
												
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5026;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5027;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5028;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5029;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5030;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5031;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5032;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5033;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5034;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5035;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5036;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5037;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5038;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5039;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5040;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5041;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5042;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5043;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5044;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5045;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5046;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5047;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5048;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5049;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5050;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5051;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5052;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5053;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5054;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5055;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5056;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5057;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5058;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5059;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5060;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5061;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5062;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5063;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5064;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5065;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5066;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5067;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5068;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5069;
DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=5070;

INSERT INTO `battlepay_display_info`(`DisplayInfoId`, `CreatureDisplayInfoID`, `FileDataID`, `Flags`		, `Name1`							    	   			, `Name2`, `Name3`, `Name4`) 
VALUES 										(5026			  	 , 236361					  , 0			    , 0				, 'Vicious Saddle'					 	   			, ''		, ''		, ''		),
												(5027			  	 , 236237					  , 0			    , 0				, 'Black War Mammoth'			 	  	   			, ''		, ''		, ''		),
												(5028			  	 , 236237					  , 0			    , 0				, 'Black War Mammoth'			 	 	   			, ''		, ''		, ''		),
												(5029			  	 , 236237					  , 0			    , 0				, '(3P)Grand Black War Mammoth'	 	   			, ''		, ''		, ''		),
												(5030			  	 , 236237					  , 0			    , 0				, '(3P)Grand Black War Mammoth'	 	   			, ''		, ''		, ''		),
												(5031			  	 , 298587					  , 0			    , 0				, 'Black Battlestrider'	 			 	   			, ''		, ''		, ''		),
												(5032			  	 , 132225					  , 0			    , 0				, 'Black War Tiger'	 				 	   			, ''		, ''		, ''		),
												(5033			  	 , 132248					  , 0			    , 0				, 'Black War Ram'	 					      			, ''		, ''		, ''		),
												(5034			  	 , 132248					  , 0			    , 0				, 'Stormpike Battle Charger'		 	   			, ''		, ''		, ''		),
												(5035			  	 , 132259					  , 0			    , 0				, 'Black War Elekk'			 			   			, ''		, ''		, ''		),
												(5036			  	 , 132251					  , 0			    , 0				, 'Black War Steed'			 			   			, ''		, ''		, ''		),
												(5037			  	 , 132228					  , 0			    , 0				, 'Swift Warstrider'			 			   			, ''		, ''		, ''		),
												(5038			  	 , 132243					  , 0			    , 0				, 'Black War Kodo'			 			   			, ''		, ''		, ''		),
												(5039			  	 , 132224					  , 0			    , 0				, 'Black War Wolf'			 			   			, ''		, ''		, ''		),
												(5040			  	 , 132253					  , 0			    , 0				, 'Black War Raptor'			 			   			, ''		, ''		, ''		),
												(5041			  	 , 134227					  , 0			    , 0				, 'Frostwolf Howler'			 			   			, ''		, ''		, ''		),
												(5042			  	 , 132264					  , 0			    , 0				, 'Red Skeletal Warhorse'	 			   			, ''		, ''		, ''		),
												(5043			  	 , 901299					  , 0			    , 0				, 'Ashhide Mushan Beast'	 			   			, ''		, ''		, ''		),
												(5044			  	 , 1032613					  , 0			    , 0				, 'Breezestrider Stallion'				   			, ''		, ''		, ''		),
												(5045			  	 , 1032613					  , 0			    , 0				, 'Pale Thorngrazer'				 		   			, ''		, ''		, ''		),
												(5046			  	 , 132249					  , 0			    , 0				, 'Swift Nether Drake'				  	   			, ''		, ''		, ''		),
												(5047			  	 , 132249					  , 0			    , 0				, 'Merciless Nether Drake'			 	   			, ''		, ''		, ''		),
												(5048			  	 , 132249					  , 0			    , 0				, 'Vengeful Nether Drake'			 	   			, ''		, ''		, ''		),
												(5049			  	 , 132249					  , 0			    , 0				, 'Brutal Nether Drake'				 	   			, ''		, ''		, ''		),
												(5050			  	 , 303868					  , 0			    , 0				, 'Deadly Gladiator´s Frost Wyrm' 	   			, ''		, ''		, ''		),
												(5051			  	 , 303868					  , 0			    , 0				, 'Furious Gladiator´s Frost Wyrm'	   			, ''		, ''		, ''		),
												(5052			  	 , 303868					  , 0			    , 0				, 'Relentless Gladiator´s Frost Wyrm' 				, ''		, ''		, ''		),
												(5053			  	 , 303868					  , 0			    , 0				, 'Wrathful Gladiator´s Frost Wyrm'	 	  			, ''		, ''		, ''		),
												(5054			  	 , 236235					  , 0			    , 0				, 'Vicious Gladiator´s Twilight Drake' 			, ''		, ''		, ''		),
												(5055			  	 , 236235					  , 0			    , 0				, 'Ruthless Gladiator´s Twilight Drake'			, ''		, ''		, ''		),
												(5056			  	 , 236235					  , 0			    , 0				, 'Cataclysmic Gladiator´s Twilight Drake'		, ''		, ''		, ''		),
												(5057			  	 , 838515					  , 0			    , 0				, 'Malevolent Gladiator´s Cloud Serpent'			, ''		, ''		, ''		),
												(5058			  	 , 838515					  , 0			    , 0				, 'Tyrannical Gladiator´s Cloud Serpent'			, ''		, ''		, ''		),
												(5059			  	 , 838515					  , 0			    , 0				, 'Grievous Gladiator´s Cloud Serpent'				, ''		, ''		, ''		),
												(5060			  	 , 838515					  , 0			    , 0				, 'Prideful Gladiator´s Cloud Serpent'				, ''		, ''		, ''		),
												(5061			  	 , 1127958					  , 0			    , 0				, 'Primal Gladiator´s Felblood Gronnling' 		, ''		, ''		, ''		),
												(5062			  	 , 1127958					  , 0			    , 0				, 'Wild Gladiator´s Felblood Gronnling'			, ''		, ''		, ''		),
												(5063			  	 , 1127958					  , 0			    , 0				, 'Warmongering Gladiator´s Felblood Gronnling'	, ''		, ''		, ''		),
												(5064			  	 , 1503309					  , 0			    , 0				, 'Vindictive Gladiator´s Storm Dragon'			, ''		, ''		, ''		),
												(5065			  	 , 1503309					  , 0			    , 0				, 'Fearless Gladiator´s Storm Dragon'				, ''		, ''		, ''		),
												(5066			  	 , 1503309					  , 0			    , 0				, 'Cruel Gladiator´s Storm Dragon'					, ''		, ''		, ''		),
												(5067			  	 , 1503309					  , 0			    , 0				, 'Ferocious Gladiator´s Storm Dragon'				, ''		, ''		, ''		),
												(5068			  	 , 1503309					  , 0			    , 0				, 'Fierce Gladiator´s Storm Dragon'					, ''		, ''		, ''		),
												(5069			  	 , 1503309					  , 0			    , 0				, 'Dominant Gladiator´s Storm Dragon'				, ''		, ''		, ''		),
												(5070			  	 , 1503309					  , 0			    , 0				, 'Demonic Gladiator´s Storm Dragon'				, ''		, ''		, ''		);
 	
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5026;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5027;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5028;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5029;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5030;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5031;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5032;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5033;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5034;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5035;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5036;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5037;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5038;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5039;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5040;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5041;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5042;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5043;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5044;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5045;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5046;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5047;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5048;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5049;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5050;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5051;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5052;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5053;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5054;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5055;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5056;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5057;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5058;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5059;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5060;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5061;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5062;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5063;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5064;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5065;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5066;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5067;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5068;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5069;
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=5070;

INSERT INTO `battlepay_shop_entry` 	(`EntryID`	, `GroupID`	, `ProductID`	, `Ordering`, `Flags`, `BannerType`	, `DisplayInfoID`	) 
VALUES 										(5026			, 17			, 5026			, 2			, 0		, 0				, 0				),
												(5027			, 17			, 5027			, 3			, 0		, 0				, 0				),
												(5028			, 17			, 5028			, 4			, 0		, 0				, 0				),
												(5029			, 17			, 5029			, 5			, 0		, 0				, 0				),
												(5030			, 17			, 5030			, 6			, 0		, 0				, 0				),
												(5031			, 17			, 5031			, 7			, 0		, 0				, 0				),
												(5032			, 17			, 5032			, 8			, 0		, 0				, 0				),
												(5033			, 17			, 5033			, 9			, 0		, 0				, 0				),
												(5034			, 17			, 5034			, 10			, 0		, 0				, 0				),
												(5035			, 17			, 5035			, 11			, 0		, 0				, 0				),
												(5036			, 17			, 5036			, 12			, 0		, 0				, 0				),
												(5037			, 17			, 5037			, 13			, 0		, 0				, 0				),
												(5038			, 17			, 5038			, 14			, 0		, 0				, 0				),
												(5039			, 17			, 5039			, 15			, 0		, 0				, 0				),
												(5040			, 17			, 5040			, 16			, 0		, 0				, 0				),
												(5041			, 17			, 5041			, 17			, 0		, 0				, 0				),
												(5042			, 17			, 5042			, 18			, 0		, 0				, 0				),
												(5043			, 17			, 5043			, 19			, 0		, 0				, 0				),
												(5044			, 17			, 5044			, 20			, 0		, 0				, 0				),
												(5045			, 17			, 5045			, 21			, 0		, 0				, 0				),
												(5046			, 1			, 5046			, 22			, 0		, 0				, 0				),
												(5047			, 1			, 5047			, 23			, 0		, 0				, 0				),
												(5048			, 1			, 5048			, 24			, 0		, 0				, 0				),
												(5049			, 1			, 5049			, 25			, 0		, 0				, 0				),
												(5050			, 1			, 5050			, 26			, 0		, 0				, 0				),
												(5051			, 1			, 5051			, 27			, 0		, 0				, 0				),
												(5052			, 1			, 5052			, 28			, 0		, 0				, 0				),
												(5053			, 1			, 5053			, 29			, 0		, 0				, 0				),
												(5054			, 1			, 5054			, 30			, 0		, 0				, 0				),
												(5055			, 1			, 5055			, 31			, 0		, 0				, 0				),
												(5056			, 1			, 5056			, 32			, 0		, 0				, 0				),
												(5057			, 1			, 5057			, 33			, 0		, 0				, 0				),
												(5058			, 1			, 5058			, 34			, 0		, 0				, 0				),
												(5059			, 1			, 5059			, 35			, 0		, 0				, 0				),
												(5060			, 1			, 5060			, 36			, 0		, 0				, 0				),
												(5061			, 17			, 5061			, 22			, 0		, 0				, 0				),
												(5062			, 17			, 5062			, 23			, 0		, 0				, 0				),
												(5063			, 17			, 5063			, 24			, 0		, 0				, 0				),
												(5064			, 1			, 5064			, 37			, 0		, 0				, 0				),
												(5065			, 1			, 5065			, 38			, 0		, 0				, 0				),
												(5066			, 1			, 5066			, 39			, 0		, 0				, 0				),
												(5067			, 1			, 5067			, 40			, 0		, 0				, 0				),
												(5068			, 1			, 5068			, 41			, 0		, 0				, 0				),
												(5069			, 1			, 5069			, 42			, 0		, 0				, 0				),
												(5070			, 1			, 5070			, 43			, 0		, 0				, 0				);