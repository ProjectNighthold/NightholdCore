-- Legion Questchain Sorting: Azsuna --
-- Behind Legion Lines 1/5 --

-- Into the Fray
UPDATE `quest_template_addon` SET PrevQuestID =         0 WHERE `ID` = 38834;
UPDATE `quest_template_addon` SET NextQuestID =     37653 WHERE `ID` = 38834;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38834;

-- Demon Souls
UPDATE `quest_template_addon` SET PrevQuestID =     38834 WHERE `ID` = 37653;
UPDATE `quest_template_addon` SET NextQuestID =     37660 WHERE `ID` = 37653;
UPDATE `quest_template_addon` SET ExclusiveGroup = -37653 WHERE `ID` = 37653;
-- Reignite the Wards
UPDATE `quest_template_addon` SET PrevQuestID =     38834 WHERE `ID` = 37658;
UPDATE `quest_template_addon` SET NextQuestID =     37660 WHERE `ID` = 37658;
UPDATE `quest_template_addon` SET ExclusiveGroup = -37653 WHERE `ID` = 37658;

-- The Scythe of Souls
UPDATE `quest_template_addon` SET PrevQuestID =     37653 WHERE `ID` = 37660;
UPDATE `quest_template_addon` SET NextQuestID =     36920 WHERE `ID` = 37660;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37660;

-- From Within
UPDATE `quest_template_addon` SET PrevQuestID =     37660 WHERE `ID` = 36920;
UPDATE `quest_template_addon` SET NextQuestID =     37450 WHERE `ID` = 36920;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 36920;

-- Retake Faronaar
UPDATE `quest_template_addon` SET PrevQuestID =     36920 WHERE `ID` = 36811;
UPDATE `quest_template_addon` SET NextQuestID =     	  0 WHERE `ID` = 36811;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 36811;

-- Saving Stellagosa
UPDATE `quest_template_addon` SET PrevQuestID =     36920 WHERE `ID` = 37450;
UPDATE `quest_template_addon` SET NextQuestID =     37449 WHERE `ID` = 37450;
UPDATE `quest_template_addon` SET ExclusiveGroup = -37450 WHERE `ID` = 37450;
-- Fel Machinations
UPDATE `quest_template_addon` SET PrevQuestID =     36920 WHERE `ID` = 37656;
UPDATE `quest_template_addon` SET NextQuestID =     37449 WHERE `ID` = 37656;
UPDATE `quest_template_addon` SET ExclusiveGroup = -37450 WHERE `ID` = 37656;

-- Dark Revelations
UPDATE `quest_template_addon` SET PrevQuestID =     37450 WHERE `ID` = 37449;
UPDATE `quest_template_addon` SET NextQuestID =     38443 WHERE `ID` = 37449;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37449;


-- Defending Azurewing Repose 2/5 --
-- Journey to the Repose
UPDATE `quest_template_addon` SET PrevQuestID =     37449 WHERE `ID` = 38443;
UPDATE `quest_template_addon` SET NextQuestID =     37853 WHERE `ID` = 38443;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38443;

-- The Death of the Eldest
UPDATE `quest_template_addon` SET PrevQuestID =     38443 WHERE `ID` = 37853;
UPDATE `quest_template_addon` SET NextQuestID =     37991 WHERE `ID` = 37853;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37853;

-- Agapanthus
UPDATE `quest_template_addon` SET PrevQuestID =     37853 WHERE `ID` = 37991;
UPDATE `quest_template_addon` SET NextQuestID =     42271 WHERE `ID` = 37991;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37991;

-- Their Dying Breaths
UPDATE `quest_template_addon` SET PrevQuestID =     37853 WHERE `ID` = 42271;
UPDATE `quest_template_addon` SET NextQuestID =     37855 WHERE `ID` = 42271;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 42271;

-- The Last of the Last
UPDATE `quest_template_addon` SET PrevQuestID =     42271 WHERE `ID` = 37855;
UPDATE `quest_template_addon` SET NextQuestID =     37858 WHERE `ID` = 37855;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37855;

-- Stellagosa
UPDATE `quest_template_addon` SET PrevQuestID =     37855 WHERE `ID` = 37858;
UPDATE `quest_template_addon` SET NextQuestID =     37957 WHERE `ID` = 37858;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37858;

-- Runas the Shamed
UPDATE `quest_template_addon` SET PrevQuestID =     37858 WHERE `ID` = 37957;
UPDATE `quest_template_addon` SET NextQuestID =     37857 WHERE `ID` = 37957;
UPDATE `quest_template_addon` SET ExclusiveGroup = -37957 WHERE `ID` = 37957;
-- The Withered
UPDATE `quest_template_addon` SET PrevQuestID =     37855 WHERE `ID` = 37856;
UPDATE `quest_template_addon` SET NextQuestID =     37857 WHERE `ID` = 37856;
UPDATE `quest_template_addon` SET ExclusiveGroup = -37957 WHERE `ID` = 37856;
-- The Consumed
UPDATE `quest_template_addon` SET PrevQuestID =     37855 WHERE `ID` = 37859;
UPDATE `quest_template_addon` SET NextQuestID =     37857 WHERE `ID` = 37859;
UPDATE `quest_template_addon` SET ExclusiveGroup = -37957 WHERE `ID` = 37859;

-- Runas Knows the Way
UPDATE `quest_template_addon` SET PrevQuestID =     37957 WHERE `ID` = 37857;
UPDATE `quest_template_addon` SET NextQuestID =     37959 WHERE `ID` = 37857;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37857;

-- Those Beyond Redemption
UPDATE `quest_template_addon` SET PrevQuestID =     37857 WHERE `ID` = 37963;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 37963;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37963;

-- The Hunger Returns
UPDATE `quest_template_addon` SET PrevQuestID =     37857 WHERE `ID` = 37959;
UPDATE `quest_template_addon` SET NextQuestID =     37860 WHERE `ID` = 37959;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37959;
-- Leyline Abuse
UPDATE `quest_template_addon` SET PrevQuestID =     37857 WHERE `ID` = 37960;
UPDATE `quest_template_addon` SET NextQuestID =     37861 WHERE `ID` = 37960;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37960;
-- The Nightborne Prince
UPDATE `quest_template_addon` SET PrevQuestID =     37960 WHERE `ID` = 37861;
UPDATE `quest_template_addon` SET NextQuestID =     37862 WHERE `ID` = 37861;
UPDATE `quest_template_addon` SET ExclusiveGroup = -37860 WHERE `ID` = 37861;
-- You Scratch My Back...
UPDATE `quest_template_addon` SET PrevQuestID =     37959 WHERE `ID` = 37860;
UPDATE `quest_template_addon` SET NextQuestID =     37862 WHERE `ID` = 37860;
UPDATE `quest_template_addon` SET ExclusiveGroup = -37860 WHERE `ID` = 37860;

-- Still Alive
UPDATE `quest_template_addon` SET PrevQuestID =     37860 WHERE `ID` = 37862;
UPDATE `quest_template_addon` SET NextQuestID =     38015 WHERE `ID` = 37862;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37862;

-- Feasting on the Dragon
UPDATE `quest_template_addon` SET PrevQuestID =     37862 WHERE `ID` = 38014;
UPDATE `quest_template_addon` SET NextQuestID =     42567 WHERE `ID` = 38014;
UPDATE `quest_template_addon` SET ExclusiveGroup = -38015 WHERE `ID` = 38014;
-- On the Brink
UPDATE `quest_template_addon` SET PrevQuestID =     37862 WHERE `ID` = 38015;
UPDATE `quest_template_addon` SET NextQuestID =     42567 WHERE `ID` = 38015;
UPDATE `quest_template_addon` SET ExclusiveGroup = -38015 WHERE `ID` = 38015;

-- Cursed to Wither
UPDATE `quest_template_addon` SET PrevQuestID =     38015 WHERE `ID` = 42567;
UPDATE `quest_template_addon` SET NextQuestID =     42756 WHERE `ID` = 42567;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 42567;

-- Hunger's End
UPDATE `quest_template_addon` SET PrevQuestID =     38015 WHERE `ID` = 42567;
UPDATE `quest_template_addon` SET NextQuestID =     43496 WHERE `ID` = 42567;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 42567;


-- Azsuna versus Azshara 3/5 --
-- Those Who Remember
UPDATE `quest_template_addon` SET PrevQuestID =     42271 WHERE `ID` = 37690;
UPDATE `quest_template_addon` SET NextQuestID =     37256 WHERE `ID` = 37690;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37690;

-- They Came From the Sea
UPDATE `quest_template_addon` SET PrevQuestID =     37690 WHERE `ID` = 37256;
UPDATE `quest_template_addon` SET NextQuestID =     37733 WHERE `ID` = 37256;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37256;

-- Prince Farondis
UPDATE `quest_template_addon` SET PrevQuestID =     37256 WHERE `ID` = 37733;
UPDATE `quest_template_addon` SET NextQuestID =     37257 WHERE `ID` = 37733;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37733;

-- The Magister of Mixology
UPDATE `quest_template_addon` SET PrevQuestID =     37733 WHERE `ID` = 37727;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 37727;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37727;
-- Presentation is Everything
UPDATE `quest_template_addon` SET PrevQuestID =     37733 WHERE `ID` = 37728;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 37728;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37728;
-- A Rather Long Walk
UPDATE `quest_template_addon` SET PrevQuestID =     37733 WHERE `ID` = 37492;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 37492;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37492;

-- Our Very Bones
UPDATE `quest_template_addon` SET PrevQuestID =     37733 WHERE `ID` = 37257;
UPDATE `quest_template_addon` SET NextQuestID =     37497 WHERE `ID` = 37257;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37257;

-- Trailing the Tidestone
UPDATE `quest_template_addon` SET PrevQuestID =     37257 WHERE `ID` = 37497;
UPDATE `quest_template_addon` SET NextQuestID =     37486 WHERE `ID` = 37497;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37497;

-- The Broken Academy
UPDATE `quest_template_addon` SET PrevQuestID =     37497 WHERE `ID` = 37466;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 37466;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37466;

-- Children of Nar'thalas
UPDATE `quest_template_addon` SET PrevQuestID =     37497 WHERE `ID` = 42692;
UPDATE `quest_template_addon` SET NextQuestID =     42694 WHERE `ID` = 42692;
UPDATE `quest_template_addon` SET ExclusiveGroup = -42692 WHERE `ID` = 42692;
-- You Never Know Until You Scry
UPDATE `quest_template_addon` SET PrevQuestID =     37497 WHERE `ID` = 42693;
UPDATE `quest_template_addon` SET NextQuestID =     42694 WHERE `ID` = 42693;
UPDATE `quest_template_addon` SET ExclusiveGroup = -42692 WHERE `ID` = 42693;
-- Back from the Dead
UPDATE `quest_template_addon` SET PrevQuestID =     42692 WHERE `ID` = 42694;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 42694;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 42694;

-- Nar'thalas Still Suffers
UPDATE `quest_template_addon` SET PrevQuestID =     37497 WHERE `ID` = 37486;
UPDATE `quest_template_addon` SET NextQuestID =     37467 WHERE `ID` = 37486;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37486;

-- The Walk of Shame
UPDATE `quest_template_addon` SET PrevQuestID =     37486 WHERE `ID` = 37467;
UPDATE `quest_template_addon` SET NextQuestID =     37468 WHERE `ID` = 37467;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37467;

-- Into the Academy
UPDATE `quest_template_addon` SET PrevQuestID =     37467 WHERE `ID` = 37468;
UPDATE `quest_template_addon` SET NextQuestID =     37736 WHERE `ID` = 37468;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37468;

-- Hit the Books
UPDATE `quest_template_addon` SET PrevQuestID =     37468 WHERE `ID` = 37678;
UPDATE `quest_template_addon` SET NextQuestID =     37518 WHERE `ID` = 37678;
UPDATE `quest_template_addon` SET ExclusiveGroup = -37736 WHERE `ID` = 37678;
-- Dressing With Class
UPDATE `quest_template_addon` SET PrevQuestID =     37468 WHERE `ID` = 37736;
UPDATE `quest_template_addon` SET NextQuestID =     37518 WHERE `ID` = 37736;
UPDATE `quest_template_addon` SET ExclusiveGroup = -37736 WHERE `ID` = 37736;

-- The Haunted Halls
UPDATE `quest_template_addon` SET PrevQuestID =     37736 WHERE `ID` = 37518;
UPDATE `quest_template_addon` SET NextQuestID =     42370 WHERE `ID` = 37518;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37518;

-- Wanding 101
UPDATE `quest_template_addon` SET PrevQuestID =     37518 WHERE `ID` = 42370;
UPDATE `quest_template_addon` SET NextQuestID =     42371 WHERE `ID` = 42370;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 42370;

-- Study Hall: Combat Research
UPDATE `quest_template_addon` SET PrevQuestID =     42370 WHERE `ID` = 42371;
UPDATE `quest_template_addon` SET NextQuestID =     37729 WHERE `ID` = 42371;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 42371;

-- Pop Quiz: Advanced Rune Drawing
UPDATE `quest_template_addon` SET PrevQuestID =     42371 WHERE `ID` = 37729;
UPDATE `quest_template_addon` SET NextQuestID =     37730 WHERE `ID` = 37729;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37729;

-- The Headmistress' Keys
UPDATE `quest_template_addon` SET PrevQuestID =     37729 WHERE `ID` = 37730;
UPDATE `quest_template_addon` SET NextQuestID =     37469 WHERE `ID` = 37730;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37730;

-- The Tidestone: Shattered
UPDATE `quest_template_addon` SET PrevQuestID =     37730 WHERE `ID` = 37469;
UPDATE `quest_template_addon` SET NextQuestID =     37530 WHERE `ID` = 37469;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37469;

-- Save Yourself
UPDATE `quest_template_addon` SET PrevQuestID =     37469 WHERE `ID` = 37530;
UPDATE `quest_template_addon` SET NextQuestID =     37470 WHERE `ID` = 37530;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37530;

-- Tip the Scales
UPDATE `quest_template_addon` SET PrevQuestID =     37530 WHERE `ID` = 37779;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 37779;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37779;

-- The Head of the Snake
UPDATE `quest_template_addon` SET PrevQuestID =     37530 WHERE `ID` = 37470;
UPDATE `quest_template_addon` SET NextQuestID =     38286 WHERE `ID` = 37470;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37470;

-- Eye of Azshara: Wrath of Azshara
UPDATE `quest_template_addon` SET PrevQuestID =     37470 WHERE `ID` = 38286;
UPDATE `quest_template_addon` SET NextQuestID =     42213 WHERE `ID` = 38286;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38286;

-- Eye of Azshara: The Tidestone of Golganneth
UPDATE `quest_template_addon` SET PrevQuestID =     38286 WHERE `ID` = 42213;
UPDATE `quest_template_addon` SET NextQuestID =     46253 WHERE `ID` = 42213;
UPDATE `quest_template_addon` SET ExclusiveGroup = -42213 WHERE `ID` = 42213;


-- Against the Giants 4/5 --
-- Bottled Up
UPDATE `quest_template_addon` SET PrevQuestID =         0 WHERE `ID` = 38407;
UPDATE `quest_template_addon` SET NextQuestID =     37496 WHERE `ID` = 38407;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38407;

-- Infiltrating Shipwreck Arena
UPDATE `quest_template_addon` SET PrevQuestID =     38407 WHERE `ID` = 37496;
UPDATE `quest_template_addon` SET NextQuestID =     37507 WHERE `ID` = 37496;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37496;

-- Boss Whalebelly's in Charge
UPDATE `quest_template_addon` SET PrevQuestID =     37496 WHERE `ID` = 37507;
UPDATE `quest_template_addon` SET NextQuestID =     37528 WHERE `ID` = 37507;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37507;

-- Let Sleeping Giants Lie
UPDATE `quest_template_addon` SET PrevQuestID =     37507 WHERE `ID` = 37528;
UPDATE `quest_template_addon` SET NextQuestID =     37510 WHERE `ID` = 37528;
UPDATE `quest_template_addon` SET ExclusiveGroup = -37528 WHERE `ID` = 37528;
-- No Time for Tryouts
UPDATE `quest_template_addon` SET PrevQuestID =     37507 WHERE `ID` = 37542;
UPDATE `quest_template_addon` SET NextQuestID =     37510 WHERE `ID` = 37542;
UPDATE `quest_template_addon` SET ExclusiveGroup = -37528 WHERE `ID` = 37542;

-- Sternfathom's Champion
UPDATE `quest_template_addon` SET PrevQuestID =     37528 WHERE `ID` = 37510;
UPDATE `quest_template_addon` SET NextQuestID =     37536 WHERE `ID` = 37510;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37510;

-- Morale Booster
UPDATE `quest_template_addon` SET PrevQuestID =     37510 WHERE `ID` = 37536;
UPDATE `quest_template_addon` SET NextQuestID =     37538 WHERE `ID` = 37536;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37536;

-- Round 1, Fight!
UPDATE `quest_template_addon` SET PrevQuestID =     37536 WHERE `ID` = 37538;
UPDATE `quest_template_addon` SET NextQuestID =     37565 WHERE `ID` = 37538;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37538;

-- Plunder the Cove
UPDATE `quest_template_addon` SET PrevQuestID =     37538 WHERE `ID` = 37495;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 37495;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37495;
-- A Favor for Mr. Shackle
UPDATE `quest_template_addon` SET PrevQuestID =     37538 WHERE `ID` = 38857;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 38857;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38857;

-- The Right Weapon for the Job
UPDATE `quest_template_addon` SET PrevQuestID =     37538 WHERE `ID` = 37565;
UPDATE `quest_template_addon` SET NextQuestID =     37566 WHERE `ID` = 37565;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37565;

-- The Prince is Going Down
UPDATE `quest_template_addon` SET PrevQuestID =     37565 WHERE `ID` = 37566;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 37566;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37566;


-- Mak'rana and the Fate of the Queen's Reprisal 5/5 --
-- Making the World Safe for Profit
UPDATE `quest_template_addon` SET PrevQuestID =         0 WHERE `ID` = 37657;
UPDATE `quest_template_addon` SET NextQuestID =     37659 WHERE `ID` = 37657;
UPDATE `quest_template_addon` SET ExclusiveGroup = -37654 WHERE `ID` = 37657;
-- Shipwrecked Sailors
UPDATE `quest_template_addon` SET PrevQuestID =         0 WHERE `ID` = 42220;
UPDATE `quest_template_addon` SET NextQuestID =     37659 WHERE `ID` = 42220;
UPDATE `quest_template_addon` SET ExclusiveGroup = -37654 WHERE `ID` = 42220;

-- Maritime Law
UPDATE `quest_template_addon` SET PrevQuestID =         0 WHERE `ID` = 37654;
UPDATE `quest_template_addon` SET NextQuestID =     37659 WHERE `ID` = 37654;
UPDATE `quest_template_addon` SET ExclusiveGroup = -37654 WHERE `ID` = 37654;

-- The Captain's Foot Locker
UPDATE `quest_template_addon` SET PrevQuestID =     37654 WHERE `ID` = 37659;
UPDATE `quest_template_addon` SET NextQuestID =     40794 WHERE `ID` = 37659;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 37659;

-- Fate of the Queen's Reprisal
UPDATE `quest_template_addon` SET PrevQuestID =     37659 WHERE `ID` = 40794;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 40794;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 40794;