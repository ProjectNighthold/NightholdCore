-- by Gyarakushi
-- Legion Questchain Sorting: Argus --
-- The Assault Begins 1/3
-- The Hand of Fate (Alli)
UPDATE quest_template_addon SET PrevQuestID =     46734 WHERE ID = 47221;
UPDATE quest_template_addon SET NextQuestID =     47222 WHERE ID = 47221;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 47221;

-- The Hand of Fate (Horde)
UPDATE quest_template_addon SET PrevQuestID =     46734 WHERE ID = 47835;
UPDATE quest_template_addon SET NextQuestID =     47867 WHERE ID = 47835;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 47835;

-- Two if By Sea (Alli)
UPDATE quest_template_addon SET PrevQuestID =     47221 WHERE ID = 47222;
UPDATE quest_template_addon SET NextQuestID =     47223 WHERE ID = 47222;
UPDATE quest_template_addon SET ExclusiveGroup =      47222 WHERE ID = 47222;

-- Two if By Sea (Horde)
UPDATE quest_template_addon SET PrevQuestID =     47835 WHERE ID = 47867;
UPDATE quest_template_addon SET NextQuestID =     47223 WHERE ID = 47867;
UPDATE quest_template_addon SET ExclusiveGroup =      47222 WHERE ID = 47867;

-- Light's Exodus
UPDATE quest_template_addon SET PrevQuestID =     47222 WHERE ID = 47223;
UPDATE quest_template_addon SET NextQuestID =     47224 WHERE ID = 47223;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 47223;

-- The Vindicaar
UPDATE quest_template_addon SET PrevQuestID =     47223 WHERE ID = 47224;
UPDATE quest_template_addon SET NextQuestID =     48440 WHERE ID = 47224;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 47224;

-- Into the Night
UPDATE quest_template_addon SET PrevQuestID =     47224 WHERE ID = 48440;
UPDATE quest_template_addon SET NextQuestID =     46938 WHERE ID = 48440;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 48440;

-- Alone in the Abyss
UPDATE quest_template_addon SET PrevQuestID =     48440 WHERE ID = 46938;
UPDATE quest_template_addon SET NextQuestID =     47589 WHERE ID = 46938;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 46938;

-- Righteous Fury
UPDATE quest_template_addon SET PrevQuestID =     46938 WHERE ID = 47589;
UPDATE quest_template_addon SET NextQuestID =     47627 WHERE ID = 47589;
UPDATE quest_template_addon SET ExclusiveGroup =      -47589 WHERE ID = 47589;

-- Overwhelming Power
UPDATE quest_template_addon SET PrevQuestID =     46938 WHERE ID = 46297;
UPDATE quest_template_addon SET NextQuestID =     47627 WHERE ID = 46297;
UPDATE quest_template_addon SET ExclusiveGroup = -48483 WHERE ID = 46297;

-- A Stranger's Plea
UPDATE quest_template_addon SET PrevQuestID =     46938 WHERE ID = 48483;
UPDATE quest_template_addon SET NextQuestID =     47627 WHERE ID = 48483;
UPDATE quest_template_addon SET ExclusiveGroup =      -47589 WHERE ID = 48483;

-- Vengeance
UPDATE quest_template_addon SET PrevQuestID =     47589 WHERE ID = 47627;
UPDATE quest_template_addon SET NextQuestID =     47641 WHERE ID = 47627;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 47627;

-- Signs of Resistance
UPDATE quest_template_addon SET PrevQuestID =     47627 WHERE ID = 47641;
UPDATE quest_template_addon SET NextQuestID =     46732 WHERE ID = 47641;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 47641;

-- The Prophet's Gambit
UPDATE quest_template_addon SET PrevQuestID =     47641 WHERE ID = 46732;
UPDATE quest_template_addon SET NextQuestID =     46816 WHERE ID = 46732;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 46732;

-- Rendezvous
UPDATE quest_template_addon SET PrevQuestID =     46732 WHERE ID = 46816;
UPDATE quest_template_addon SET NextQuestID =     46839 WHERE ID = 46816;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 46816;

-- From Darkness
UPDATE quest_template_addon SET PrevQuestID =     46816 WHERE ID = 46839;
UPDATE quest_template_addon SET NextQuestID =     46840 WHERE ID = 46839;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 46839;

-- Prisoners No More
UPDATE quest_template_addon SET PrevQuestID =     46839 WHERE ID = 46840;
UPDATE quest_template_addon SET NextQuestID =     46842 WHERE ID = 46840;
UPDATE quest_template_addon SET ExclusiveGroup =      -46840 WHERE ID = 46840;

-- Threat Reduction
UPDATE quest_template_addon SET PrevQuestID =     46839 WHERE ID = 46841;
UPDATE quest_template_addon SET NextQuestID =     46842 WHERE ID = 46841;
UPDATE quest_template_addon SET ExclusiveGroup =      -46840 WHERE ID = 46841;

-- A Strike at the Heart
UPDATE quest_template_addon SET PrevQuestID =     46840 WHERE ID = 46842;
UPDATE quest_template_addon SET NextQuestID =     46843 WHERE ID = 46842;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 46842;

-- Return to the Vindicaar
UPDATE quest_template_addon SET PrevQuestID =     46842 WHERE ID = 46843;
UPDATE quest_template_addon SET NextQuestID =     48500 WHERE ID = 46843;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 46843;

-- A Moment of Respite
UPDATE quest_template_addon SET PrevQuestID =     46843 WHERE ID = 48500;
UPDATE quest_template_addon SET NextQuestID =     47431 WHERE ID = 48500;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 48500;

-- Gathering Light
UPDATE quest_template_addon SET PrevQuestID =     48500 WHERE ID = 47431;
UPDATE quest_template_addon SET NextQuestID =     40238 WHERE ID = 47431;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 47431;

-- A Grim Equation
UPDATE quest_template_addon SET PrevQuestID =     47431 WHERE ID = 40238;
UPDATE quest_template_addon SET NextQuestID =     47508 WHERE ID = 40238;
UPDATE quest_template_addon SET ExclusiveGroup =      -40238 WHERE ID = 40238;

-- Crystals Not Included
UPDATE quest_template_addon SET PrevQuestID =     47431 WHERE ID = 46213;
UPDATE quest_template_addon SET NextQuestID =     47508 WHERE ID = 46213;
UPDATE quest_template_addon SET ExclusiveGroup =      -40238 WHERE ID = 46213;

-- The Best Prevention
UPDATE quest_template_addon SET PrevQuestID =     47431 WHERE ID = 47541;
UPDATE quest_template_addon SET NextQuestID =     47508 WHERE ID = 47541;
UPDATE quest_template_addon SET ExclusiveGroup =      -40238 WHERE ID = 47541;

-- Fire at Will
UPDATE quest_template_addon SET PrevQuestID =     40238 WHERE ID = 47508;
UPDATE quest_template_addon SET NextQuestID =     47771 WHERE ID = 47508;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 47508;

-- Locating the Longshot
UPDATE quest_template_addon SET PrevQuestID =     47508 WHERE ID = 47771;
UPDATE quest_template_addon SET NextQuestID =     47526 WHERE ID = 47771;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 47771;

-- Bringing the Big Guns
UPDATE quest_template_addon SET PrevQuestID =     47771 WHERE ID = 47526;
UPDATE quest_template_addon SET NextQuestID =     47754 WHERE ID = 47526;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 47526;

-- Lightly Roasted
UPDATE quest_template_addon SET PrevQuestID =     47526 WHERE ID = 47754;
UPDATE quest_template_addon SET NextQuestID =     47563 WHERE ID = 47754;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 47754;

-- Light's Return
UPDATE quest_template_addon SET PrevQuestID =     47754 WHERE ID = 47563;
UPDATE quest_template_addon SET NextQuestID =     47431 WHERE ID = 47563;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 47563;

-- The Light Mother
UPDATE quest_template_addon SET PrevQuestID =     47563 WHERE ID = 47431;
UPDATE quest_template_addon SET NextQuestID =     47743 WHERE ID = 47431;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 47431;

-- The Child of Light and Shadow
UPDATE quest_template_addon SET PrevQuestID =     47431 WHERE ID = 47743;
UPDATE quest_template_addon SET NextQuestID =     49143 WHERE ID = 47743;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 47743;

-- The Vindicaar Matrix Core
UPDATE quest_template_addon SET PrevQuestID =     47743 WHERE ID = 47287;
UPDATE quest_template_addon SET NextQuestID =     0 WHERE ID = 47287;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 47287;

-- Essence of the Light Mother
UPDATE quest_template_addon SET PrevQuestID =     47743 WHERE ID = 49143;
UPDATE quest_template_addon SET NextQuestID =     48559 WHERE ID = 49143;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 49143;

-- An Offering of Light
UPDATE quest_template_addon SET PrevQuestID =     49143 WHERE ID = 48559;
UPDATE quest_template_addon SET NextQuestID =     48199 WHERE ID = 48559;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 48559;

-- The Burning Heart
UPDATE quest_template_addon SET PrevQuestID =     48559 WHERE ID = 48199;
UPDATE quest_template_addon SET NextQuestID =     48200 WHERE ID = 48199;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 48199;

-- The Wranglers
UPDATE quest_template_addon SET PrevQuestID =     48199 WHERE ID = 48460;
UPDATE quest_template_addon SET NextQuestID =     0 WHERE ID = 48460;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 48460;

-- Securing a Foothold
UPDATE quest_template_addon SET PrevQuestID =     48199 WHERE ID = 48200;
UPDATE quest_template_addon SET NextQuestID =     48201 WHERE ID = 48200;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 48200;

-- Reinforce Light's Purchase
UPDATE quest_template_addon SET PrevQuestID =     48200 WHERE ID = 48201;
UPDATE quest_template_addon SET NextQuestID =     47473 WHERE ID = 48201;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 48201;

-- Reinforce the Veiled Den
UPDATE quest_template_addon SET PrevQuestID =     48200 WHERE ID = 48202;
UPDATE quest_template_addon SET NextQuestID =     48929 WHERE ID = 48202;
UPDATE quest_template_addon SET ExclusiveGroup =      0 WHERE ID = 48202;

-- Sizing up the Opposition
UPDATE quest_template_addon SET PrevQuestID =     48201 WHERE ID = 47473;
UPDATE quest_template_addon SET NextQuestID =     47889 WHERE ID = 47473;
UPDATE quest_template_addon SET ExclusiveGroup =      47473 WHERE ID = 47473;

-- Sizing up the Opposition
UPDATE quest_template_addon SET PrevQuestID =     48202 WHERE ID = 48929;
UPDATE quest_template_addon SET NextQuestID =     47889 WHERE ID = 48929;
UPDATE quest_template_addon SET ExclusiveGroup =      47473 WHERE ID = 48929;


-- Dark Awakenings 2/3
-- The Speaker Calls
UPDATE quest_template_addon SET PrevQuestID =		47473 WHERE ID = 47889;
UPDATE quest_template_addon SET NextQuestID = 		47890 WHERE ID = 47889;
UPDATE quest_template_addon SET ExclusiveGroup =		 0 WHERE ID = 47889;

-- Visions of Torment
UPDATE quest_template_addon SET PrevQuestID =		47889 WHERE ID = 47890;
UPDATE quest_template_addon SET NextQuestID = 		47891 WHERE ID = 47890;
UPDATE quest_template_addon SET ExclusiveGroup =		 0 WHERE ID = 47890;

-- Dire News
UPDATE quest_template_addon SET PrevQuestID =		47890 WHERE ID = 47891;
UPDATE quest_template_addon SET NextQuestID = 		47892 WHERE ID = 47891;
UPDATE quest_template_addon SET ExclusiveGroup =		 0 WHERE ID = 47891;

-- Storming the Citadel
UPDATE quest_template_addon SET PrevQuestID =		47891 WHERE ID = 47892;
UPDATE quest_template_addon SET NextQuestID = 		47986 WHERE ID = 47892;
UPDATE quest_template_addon SET ExclusiveGroup =		 0 WHERE ID = 47892;

-- Scars of the Past
UPDATE quest_template_addon SET PrevQuestID =		47892 WHERE ID = 47986;
UPDATE quest_template_addon SET NextQuestID = 		47991 WHERE ID = 47986;
UPDATE quest_template_addon SET ExclusiveGroup =	-47986 WHERE ID = 47986;

-- Preventive Measures
UPDATE quest_template_addon SET PrevQuestID =		47892 WHERE ID = 47987;
UPDATE quest_template_addon SET NextQuestID = 		47991 WHERE ID = 47987;
UPDATE quest_template_addon SET ExclusiveGroup =	-47986 WHERE ID = 47987;

-- Chaos Theory
UPDATE quest_template_addon SET PrevQuestID =		47892 WHERE ID = 47988;
UPDATE quest_template_addon SET NextQuestID = 		47991 WHERE ID = 47988;
UPDATE quest_template_addon SET ExclusiveGroup =	-47986 WHERE ID = 47988;

-- Dark Machinations
UPDATE quest_template_addon SET PrevQuestID =		47986 WHERE ID = 47991;
UPDATE quest_template_addon SET NextQuestID = 		47992 WHERE ID = 47991;
UPDATE quest_template_addon SET ExclusiveGroup =	-47991 WHERE ID = 47991;

-- A Touch of Fel
UPDATE quest_template_addon SET PrevQuestID =		47986 WHERE ID = 47990;
UPDATE quest_template_addon SET NextQuestID = 		47992 WHERE ID = 47990;
UPDATE quest_template_addon SET ExclusiveGroup =	-47991 WHERE ID = 47990;

-- Heralds of Apocalypse
UPDATE quest_template_addon SET PrevQuestID =		47986 WHERE ID = 47989;
UPDATE quest_template_addon SET NextQuestID = 		47992 WHERE ID = 47989;
UPDATE quest_template_addon SET ExclusiveGroup =	-47991 WHERE ID = 47989;

-- Dawn of Justice
UPDATE quest_template_addon SET PrevQuestID =		47991 WHERE ID = 47992;
UPDATE quest_template_addon SET NextQuestID = 		47993 WHERE ID = 47992;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 47992;

-- Lord of the Spire
UPDATE quest_template_addon SET PrevQuestID =		47992 WHERE ID = 47993;
UPDATE quest_template_addon SET NextQuestID = 		47994 WHERE ID = 47993;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 47993;

-- Forming a Bond
UPDATE quest_template_addon SET PrevQuestID =		47993 WHERE ID = 47994;
UPDATE quest_template_addon SET NextQuestID = 		48081 WHERE ID = 47994;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 47994;

-- A Floating Ruin
UPDATE quest_template_addon SET PrevQuestID =		47994 WHERE ID = 48041;
UPDATE quest_template_addon SET NextQuestID = 		46815 WHERE ID = 48041;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 48041;

-- Mac'Aree, Jewel of Argus
UPDATE quest_template_addon SET PrevQuestID =		48041 WHERE ID = 46815;
UPDATE quest_template_addon SET NextQuestID = 		46818 WHERE ID = 46815;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 46815;

-- Defenseless and Afraid
UPDATE quest_template_addon SET PrevQuestID =		46815 WHERE ID = 46818;
UPDATE quest_template_addon SET NextQuestID = 		47066 WHERE ID = 46818;
UPDATE quest_template_addon SET ExclusiveGroup =	-46818 WHERE ID = 46818;

-- Khazaduum, First od His Name
UPDATE quest_template_addon SET PrevQuestID =		46815 WHERE ID = 46834;
UPDATE quest_template_addon SET NextQuestID = 		47066 WHERE ID = 46834;
UPDATE quest_template_addon SET ExclusiveGroup =	-46818 WHERE ID = 46834;

-- Consecrating Ground
UPDATE quest_template_addon SET PrevQuestID =		46818 WHERE ID = 47066;
UPDATE quest_template_addon SET NextQuestID = 		46941 WHERE ID = 47066;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 47066;

-- The Path Forward
UPDATE quest_template_addon SET PrevQuestID =		46818 WHERE ID = 46941;
UPDATE quest_template_addon SET NextQuestID = 		47686 WHERE ID = 46941;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 46941;

-- Not-So-Humble Beginnings
UPDATE quest_template_addon SET PrevQuestID =		46941 WHERE ID = 47686;
UPDATE quest_template_addon SET NextQuestID = 		47882 WHERE ID = 47686;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 47686;

-- Conservative Magic
UPDATE quest_template_addon SET PrevQuestID =		47686 WHERE ID = 47882;
UPDATE quest_template_addon SET NextQuestID = 		47883 WHERE ID = 47882;
UPDATE quest_template_addon SET ExclusiveGroup =	-47882 WHERE ID = 47882;

-- Invasive Species
UPDATE quest_template_addon SET PrevQuestID =		47686 WHERE ID = 47688;
UPDATE quest_template_addon SET NextQuestID = 		47883 WHERE ID = 47688;
UPDATE quest_template_addon SET ExclusiveGroup =	-47882 WHERE ID = 47688;

-- The Longest Vigil
UPDATE quest_template_addon SET PrevQuestID =		47882 WHERE ID = 47883;
UPDATE quest_template_addon SET NextQuestID = 		47689 WHERE ID = 47883;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 47883;

-- Gatekeeper's Challenge: Tenacity
UPDATE quest_template_addon SET PrevQuestID =		47883 WHERE ID = 47689;
UPDATE quest_template_addon SET NextQuestID = 		47690 WHERE ID = 47689;
UPDATE quest_template_addon SET ExclusiveGroup =	-47689 WHERE ID = 47689;

-- Gatekeeper's Challenge: Tenacity
UPDATE quest_template_addon SET PrevQuestID =		47883 WHERE ID = 47685;
UPDATE quest_template_addon SET NextQuestID = 		47690 WHERE ID = 47685;
UPDATE quest_template_addon SET ExclusiveGroup =	-47689 WHERE ID = 47685;

-- Gatekeeper's Challenge: Tenacity
UPDATE quest_template_addon SET PrevQuestID =		47883 WHERE ID = 47687;
UPDATE quest_template_addon SET NextQuestID = 		47690 WHERE ID = 47687;
UPDATE quest_template_addon SET ExclusiveGroup =	-47689 WHERE ID = 47687;

-- The Defiler's Legacy
UPDATE quest_template_addon SET PrevQuestID =		47689 WHERE ID = 47690;
UPDATE quest_template_addon SET NextQuestID = 		48107 WHERE ID = 47690;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 47690;

-- The Sigil of Awakening
UPDATE quest_template_addon SET PrevQuestID =		47690 WHERE ID = 48107;
UPDATE quest_template_addon SET NextQuestID = 		48461 WHERE ID = 48107;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 48107;

-- Where They Least Expect It
UPDATE quest_template_addon SET PrevQuestID =		48107 WHERE ID = 48461;
UPDATE quest_template_addon SET NextQuestID = 		48344 WHERE ID = 48461;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 48461;


-- The War of Light and Shadow 3/3
-- We Have a Problem
UPDATE quest_template_addon SET PrevQuestID =		48461 WHERE ID = 48344;
UPDATE quest_template_addon SET NextQuestID = 		47691 WHERE ID = 48344;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 48344;

-- A Non-Prophet Organization
UPDATE quest_template_addon SET PrevQuestID =		48344 WHERE ID = 47691;
UPDATE quest_template_addon SET NextQuestID = 		47853 WHERE ID = 47691;
UPDATE quest_template_addon SET ExclusiveGroup =	-47691 WHERE ID = 47691;
-- Wrath of the High Exarch
UPDATE quest_template_addon SET PrevQuestID =		48344 WHERE ID = 47854;
UPDATE quest_template_addon SET NextQuestID = 		47853 WHERE ID = 47854;
UPDATE quest_template_addon SET ExclusiveGroup =	-47691 WHERE ID = 47854;
-- Overt Ops
UPDATE quest_template_addon SET PrevQuestID =		48344 WHERE ID = 47995;
UPDATE quest_template_addon SET NextQuestID = 		47853 WHERE ID = 47995;
UPDATE quest_template_addon SET ExclusiveGroup =	-47691 WHERE ID = 47995;

-- Flanking Maneuvers
UPDATE quest_template_addon SET PrevQuestID =		47691 WHERE ID = 47853;
UPDATE quest_template_addon SET NextQuestID = 		47855 WHERE ID = 47853;
UPDATE quest_template_addon SET ExclusiveGroup =	-47853 WHERE ID = 47853;
-- Talgath's Forces
UPDATE quest_template_addon SET PrevQuestID =		47691 WHERE ID = 48345;
UPDATE quest_template_addon SET NextQuestID = 		47855 WHERE ID = 48345;
UPDATE quest_template_addon SET ExclusiveGroup =	-47853 WHERE ID = 48345;

-- What Might Have Been
UPDATE quest_template_addon SET PrevQuestID =		47853 WHERE ID = 47855;
UPDATE quest_template_addon SET NextQuestID = 		47856 WHERE ID = 47855;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 47855;

-- Across the Universe
UPDATE quest_template_addon SET PrevQuestID =		47855 WHERE ID = 47856;
UPDATE quest_template_addon SET NextQuestID = 		47416 WHERE ID = 47856;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 47856;

-- Shadow of the Triumvirate
UPDATE quest_template_addon SET PrevQuestID =		47856 WHERE ID = 47416;
UPDATE quest_template_addon SET NextQuestID = 		47238 WHERE ID = 47416;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 47416;

-- The Seat of the Triumvirate
UPDATE quest_template_addon SET PrevQuestID =		47416 WHERE ID = 47238;
UPDATE quest_template_addon SET NextQuestID = 		40761 WHERE ID = 47238;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 47238;

-- Whispers from Oronaar
UPDATE quest_template_addon SET PrevQuestID =		47238 WHERE ID = 40761;
UPDATE quest_template_addon SET NextQuestID = 		47180 WHERE ID = 40761;
UPDATE quest_template_addon SET ExclusiveGroup =	-40761 WHERE ID = 40761;
-- Arkhaan's Prayers
UPDATE quest_template_addon SET PrevQuestID =		47238 WHERE ID = 47101;
UPDATE quest_template_addon SET NextQuestID = 		47180 WHERE ID = 47101;
UPDATE quest_template_addon SET ExclusiveGroup =	-40761 WHERE ID = 47101;

-- The Pulsing Madness
UPDATE quest_template_addon SET PrevQuestID =		40761 WHERE ID = 47180;
UPDATE quest_template_addon SET NextQuestID = 		47183 WHERE ID = 47180;
UPDATE quest_template_addon SET ExclusiveGroup =	-47180 WHERE ID = 47180;
-- Arkhaan's Pain
UPDATE quest_template_addon SET PrevQuestID =		40761 WHERE ID = 47100;
UPDATE quest_template_addon SET NextQuestID = 		47183 WHERE ID = 47100;
UPDATE quest_template_addon SET ExclusiveGroup =	-47180 WHERE ID = 47100;

-- Arkhaan's Plan
UPDATE quest_template_addon SET PrevQuestID =		47180 WHERE ID = 47183;
UPDATE quest_template_addon SET NextQuestID = 		47184 WHERE ID = 47183;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 47183;

-- Arkhaan's Peril
UPDATE quest_template_addon SET PrevQuestID =		47183 WHERE ID = 47184;
UPDATE quest_template_addon SET NextQuestID = 		47203 WHERE ID = 47184;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 47184;

-- Throwing Shade
UPDATE quest_template_addon SET PrevQuestID =		47184 WHERE ID = 47203;
UPDATE quest_template_addon SET NextQuestID = 		47217 WHERE ID = 47203;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 47203;

-- Sources of Darkness
UPDATE quest_template_addon SET PrevQuestID =		47203 WHERE ID = 47217;
UPDATE quest_template_addon SET NextQuestID = 		47219 WHERE ID = 47217;
UPDATE quest_template_addon SET ExclusiveGroup =	-47217 WHERE ID = 47217;
-- The Shadowguard Incursion
UPDATE quest_template_addon SET PrevQuestID =		47203 WHERE ID = 47218;
UPDATE quest_template_addon SET NextQuestID = 		47219 WHERE ID = 47218;
UPDATE quest_template_addon SET ExclusiveGroup =	-47217 WHERE ID = 47218;

-- A Vessel Made Ready
UPDATE quest_template_addon SET PrevQuestID =		47217 WHERE ID = 47219;
UPDATE quest_template_addon SET NextQuestID = 		47220 WHERE ID = 47219;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 47219;

-- A Beacon in the Dark
UPDATE quest_template_addon SET PrevQuestID =		47219 WHERE ID = 47220;
UPDATE quest_template_addon SET NextQuestID = 		48560 WHERE ID = 47220;
UPDATE quest_template_addon SET ExclusiveGroup =		0 WHERE ID = 47220;

-- An Offering of Shadow
UPDATE quest_template_addon SET PrevQuestID =		47220 WHERE ID = 48560;
UPDATE quest_template_addon SET NextQuestID = 			0 WHERE ID = 48560;
UPDATE quest_template_addon SET ExclusiveGroup =	-48560 WHERE ID = 48560;
-- Seat of the Triumvirate: The Crest of Knowledge
UPDATE quest_template_addon SET PrevQuestID =		47220 WHERE ID = 47654;
UPDATE quest_template_addon SET NextQuestID = 			0 WHERE ID = 47654;
UPDATE quest_template_addon SET ExclusiveGroup =	-48560 WHERE ID = 47654;