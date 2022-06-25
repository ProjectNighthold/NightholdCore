-- Legion Questchain Sorting: Val'sharah --
-- Introduction 0/7 --

-- The Tranquil Forest
UPDATE `quest_template_addon` SET PrevQuestID =         0 WHERE `ID` = 39731;
UPDATE `quest_template_addon` SET NextQuestID =     39861 WHERE `ID` = 39731;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 39731;

-- Tying Up Loose Ends
UPDATE `quest_template_addon` SET PrevQuestID =     39731 WHERE `ID` = 39861;
UPDATE `quest_template_addon` SET NextQuestID =     38305 WHERE `ID` = 39861;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 39861;

-- Cenarius, Keeper of the Grove
UPDATE `quest_template_addon` SET PrevQuestID =     39861 WHERE `ID` = 38305;
UPDATE `quest_template_addon` SET NextQuestID =     38384 WHERE `ID` = 38305;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38305;

-- Nature's Call
UPDATE `quest_template_addon` SET PrevQuestID =     38305 WHERE `ID` = 38384;
UPDATE `quest_template_addon` SET NextQuestID =     38382 WHERE `ID` = 38384;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38384;


-- Archdruid of the Vale 1/7 --
-- Archdruid of the Vale
UPDATE `quest_template_addon` SET PrevQuestID =     38384 WHERE `ID` = 38382;
UPDATE `quest_template_addon` SET NextQuestID =     39383 WHERE `ID` = 38382;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38382;

-- Moonclaw Vale
UPDATE `quest_template_addon` SET PrevQuestID =     38382 WHERE `ID` = 39393;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 39393;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 39393;
-- Dishonored
UPDATE `quest_template_addon` SET PrevQuestID =     38382 WHERE `ID` = 39383;
UPDATE `quest_template_addon` SET NextQuestID =     39384 WHERE `ID` = 39383;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 39383;

-- The Corruptor
UPDATE `quest_template_addon` SET PrevQuestID =     39383 WHERE `ID` = 39384;
UPDATE `quest_template_addon` SET NextQuestID =     40573 WHERE `ID` = 39384;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 39384;

-- The Nightmare Lord
UPDATE `quest_template_addon` SET PrevQuestID =     39384 WHERE `ID` = 40573;
UPDATE `quest_template_addon` SET NextQuestID =     38148 WHERE `ID` = 40573;
UPDATE `quest_template_addon` SET ExclusiveGroup = -40573 WHERE `ID` = 40573;


-- Archdruid of the Claw 2/7 --
-- Archdruid of the Claw
UPDATE `quest_template_addon` SET PrevQuestID =     38384 WHERE `ID` = 38142;
UPDATE `quest_template_addon` SET NextQuestID =     38922 WHERE `ID` = 38142;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38142;

-- Littlefur
UPDATE `quest_template_addon` SET PrevQuestID =     38142 WHERE `ID` = 38922;
UPDATE `quest_template_addon` SET NextQuestID =     38246 WHERE `ID` = 38922;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38922;

-- Totemic Call
UPDATE `quest_template_addon` SET PrevQuestID =     38922 WHERE `ID` = 38246;
UPDATE `quest_template_addon` SET NextQuestID =     38143 WHERE `ID` = 38246;
UPDATE `quest_template_addon` SET ExclusiveGroup = -38246 WHERE `ID` = 38246;
-- Frenzied Furbolgs
UPDATE `quest_template_addon` SET PrevQuestID =     38142 WHERE `ID` = 38455;
UPDATE `quest_template_addon` SET NextQuestID =     38143 WHERE `ID` = 38455;
UPDATE `quest_template_addon` SET ExclusiveGroup = -38246 WHERE `ID` = 38455;
-- The Chieftain's Beads
UPDATE `quest_template_addon` SET PrevQuestID =     38142 WHERE `ID` = 38146;
UPDATE `quest_template_addon` SET NextQuestID =     38143 WHERE `ID` = 38146;
UPDATE `quest_template_addon` SET ExclusiveGroup = -38246 WHERE `ID` = 38146;

-- Awakening the Archdruid
UPDATE `quest_template_addon` SET PrevQuestID =     38246 WHERE `ID` = 38143;
UPDATE `quest_template_addon` SET NextQuestID =     38145 WHERE `ID` = 38143;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38143;

-- The Demons Below
UPDATE `quest_template_addon` SET PrevQuestID =     38143 WHERE `ID` = 38144;
UPDATE `quest_template_addon` SET NextQuestID =     38147 WHERE `ID` = 38144;
UPDATE `quest_template_addon` SET ExclusiveGroup = -38145 WHERE `ID` = 38144;
-- Out of the Dream
UPDATE `quest_template_addon` SET PrevQuestID =     38143 WHERE `ID` = 38145;
UPDATE `quest_template_addon` SET NextQuestID =     38147 WHERE `ID` = 38145;
UPDATE `quest_template_addon` SET ExclusiveGroup = -38145 WHERE `ID` = 38145;

-- Entangled Dreams
UPDATE `quest_template_addon` SET PrevQuestID =     38145 WHERE `ID` = 38147;
UPDATE `quest_template_addon` SET NextQuestID =     38148 WHERE `ID` = 38147;
UPDATE `quest_template_addon` SET ExclusiveGroup = -40573 WHERE `ID` = 38147;

-- Archdruid of Lore 3/7 --
-- Archdruid of Lore
UPDATE `quest_template_addon` SET PrevQuestID =     38384 WHERE `ID` = 38381;
UPDATE `quest_template_addon` SET NextQuestID =     38235 WHERE `ID` = 38381;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38381;
-- Wretched Sisters
UPDATE `quest_template_addon` SET PrevQuestID =     38381 WHERE `ID` = 38372;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 38372;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38372;

-- Solid as a Rock
UPDATE `quest_template_addon` SET PrevQuestID =     38381 WHERE `ID` = 38235;
UPDATE `quest_template_addon` SET NextQuestID =     38148 WHERE `ID` = 38235;
UPDATE `quest_template_addon` SET ExclusiveGroup = -40573 WHERE `ID` = 38235;
-- Death to the Witchmother
UPDATE `quest_template_addon` SET PrevQuestID =     38381 WHERE `ID` = 38225;
UPDATE `quest_template_addon` SET NextQuestID =     38148 WHERE `ID` = 38225;
UPDATE `quest_template_addon` SET ExclusiveGroup = -40573 WHERE `ID` = 38225;

-- Into the Nightmare 4/7 --
-- Return to the Grove
UPDATE `quest_template_addon` SET PrevQuestID =     40573 WHERE `ID` = 38148;
UPDATE `quest_template_addon` SET NextQuestID =     38377 WHERE `ID` = 38148;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38148;

-- The Emerald Queen
UPDATE `quest_template_addon` SET PrevQuestID =     38148 WHERE `ID` = 38377;
UPDATE `quest_template_addon` SET NextQuestID =     38641 WHERE `ID` = 38377;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38377;

-- The Temple of Elune
UPDATE `quest_template_addon` SET PrevQuestID =     38377 WHERE `ID` = 38641;
UPDATE `quest_template_addon` SET NextQuestID =     38662 WHERE `ID` = 38641;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38641;

-- Root Cause
UPDATE `quest_template_addon` SET PrevQuestID =     38641 WHERE `ID` = 38655;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 38655;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38655;
-- Defend The Temple
UPDATE `quest_template_addon` SET PrevQuestID =     38641 WHERE `ID` = 39029;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 39029;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 39029;
-- Mark of the Demon
UPDATE `quest_template_addon` SET PrevQuestID =         0 WHERE `ID` = 38656;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 38656;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38656;

-- Tears for Fears
UPDATE `quest_template_addon` SET PrevQuestID =     38641 WHERE `ID` = 38662;
UPDATE `quest_template_addon` SET NextQuestID =     38663 WHERE `ID` = 38662;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38662;

-- The Die is Cast
UPDATE `quest_template_addon` SET PrevQuestID =     38662 WHERE `ID` = 38663;
UPDATE `quest_template_addon` SET NextQuestID =     38595 WHERE `ID` = 38663;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38663;

-- Malfurion's Fury
UPDATE `quest_template_addon` SET PrevQuestID =     38663 WHERE `ID` = 38595;
UPDATE `quest_template_addon` SET NextQuestID =     38582 WHERE `ID` = 38595;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38595;

-- To Old Friends
UPDATE `quest_template_addon` SET PrevQuestID =     38595 WHERE `ID` = 38582;
UPDATE `quest_template_addon` SET NextQuestID =     38753 WHERE `ID` = 38582;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38582;

-- The Demon's Trail
UPDATE `quest_template_addon` SET PrevQuestID =     38582 WHERE `ID` = 38753;
UPDATE `quest_template_addon` SET NextQuestID =     41056 WHERE `ID` = 38753;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38753;

-- All Nightmare Long 5/7 --
-- Love Lost
UPDATE `quest_template_addon` SET PrevQuestID =     38753 WHERE `ID` = 41056;
UPDATE `quest_template_addon` SET NextQuestID =     41708 WHERE `ID` = 41056;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 41056;

-- Wormtalon Wreckage
UPDATE `quest_template_addon` SET PrevQuestID =     41056 WHERE `ID` = 41707;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 41707;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 41707;
-- Lost in Retreat
UPDATE `quest_template_addon` SET PrevQuestID =     41056 WHERE `ID` = 38671;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 38671;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38671;

-- Dark Side of the Moon
UPDATE `quest_template_addon` SET PrevQuestID =     41056 WHERE `ID` = 41708;
UPDATE `quest_template_addon` SET NextQuestID =     43576 WHERE `ID` = 41708;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 41708;

-- Regroup at the Refuge
UPDATE `quest_template_addon` SET PrevQuestID =     41708 WHERE `ID` = 43576;
UPDATE `quest_template_addon` SET NextQuestID =     38675 WHERE `ID` = 43576;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 43576;

-- Heart of the Nightmare
UPDATE `quest_template_addon` SET PrevQuestID =     43576 WHERE `ID` = 38675;
UPDATE `quest_template_addon` SET NextQuestID =     41893 WHERE `ID` = 38675;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38675;

-- Flow of the Nightmare
UPDATE `quest_template_addon` SET PrevQuestID =     38675 WHERE `ID` = 43241;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 43241;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 43241;

-- Reading the Leaves
UPDATE `quest_template_addon` SET PrevQuestID =     38675 WHERE `ID` = 38684;
UPDATE `quest_template_addon` SET NextQuestID =     43702 WHERE `ID` = 38684;
UPDATE `quest_template_addon` SET ExclusiveGroup = -41893 WHERE `ID` = 38684;
-- Given to Corruption
UPDATE `quest_template_addon` SET PrevQuestID =     38675 WHERE `ID` = 41893;
UPDATE `quest_template_addon` SET NextQuestID =     43702 WHERE `ID` = 41893;
UPDATE `quest_template_addon` SET ExclusiveGroup = -41893 WHERE `ID` = 41893;

-- Softening the Target
UPDATE `quest_template_addon` SET PrevQuestID =     41893 WHERE `ID` = 43702;
UPDATE `quest_template_addon` SET NextQuestID =     38687 WHERE `ID` = 43702;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 43702;

-- Ruins of Shala'nir
UPDATE `quest_template_addon` SET PrevQuestID =     43702 WHERE `ID` = 38748;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 38748;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38748;

-- Close Enough to Touch
UPDATE `quest_template_addon` SET PrevQuestID =     43702 WHERE `ID` = 38687;
UPDATE `quest_template_addon` SET NextQuestID =     38743 WHERE `ID` = 38687;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38687;

-- The Fate of Val'sharah
UPDATE `quest_template_addon` SET PrevQuestID =     38687 WHERE `ID` = 38743;
UPDATE `quest_template_addon` SET NextQuestID =     40567 WHERE `ID` = 38743;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38743;

-- The Tears of ELune
UPDATE `quest_template_addon` SET PrevQuestID =     38743 WHERE `ID` = 40890;
UPDATE `quest_template_addon` SET NextQuestID =     46253 WHERE `ID` = 40890;
UPDATE `quest_template_addon` SET ExclusiveGroup = -42213 WHERE `ID` = 40890;

-- Darkheart Thicket: Enter the Nightmare
UPDATE `quest_template_addon` SET PrevQuestID =     38743 WHERE `ID` = 40567;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 40567;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 40567;

-- Bradensbrook 6/7 --
-- A Village in Peril
UPDATE `quest_template_addon` SET PrevQuestID =     38641 WHERE `ID` = 38643;
UPDATE `quest_template_addon` SET NextQuestID =     40567 WHERE `ID` = 38643;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38643;

-- Grumpy
UPDATE `quest_template_addon` SET PrevQuestID =     38643 WHERE `ID` = 39015;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 39015;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 39015;
-- The Warden's Signet
UPDATE `quest_template_addon` SET PrevQuestID =     38643 WHERE `ID` = 38711;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 38711;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38711;

-- Children of the Night
UPDATE `quest_template_addon` SET PrevQuestID =     38643 WHERE `ID` = 38645;
UPDATE `quest_template_addon` SET NextQuestID =     38691 WHERE `ID` = 38645;
UPDATE `quest_template_addon` SET ExclusiveGroup = -38645 WHERE `ID` = 38645;
-- The Farmsteads
UPDATE `quest_template_addon` SET PrevQuestID =     38643 WHERE `ID` = 38644;
UPDATE `quest_template_addon` SET NextQuestID =     38691 WHERE `ID` = 38644;
UPDATE `quest_template_addon` SET ExclusiveGroup = -38645 WHERE `ID` = 38644;

-- Jarod's Mission
UPDATE `quest_template_addon` SET PrevQuestID =     38645 WHERE `ID` = 38691;
UPDATE `quest_template_addon` SET NextQuestID =     38718 WHERE `ID` = 38691;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38691;

-- For the Corn!
UPDATE `quest_template_addon` SET PrevQuestID =     38645 WHERE `ID` = 38647;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 38647;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38647;
-- A Sight For Sore Eyes
UPDATE `quest_template_addon` SET PrevQuestID =     38645 WHERE `ID` = 38646;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 38646;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38646;

-- Shriek No More
UPDATE `quest_template_addon` SET PrevQuestID =     38691 WHERE `ID` = 39117;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 39117;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 39117;


-- Black Rook Hold --
-- Kur'talos Ravencrest
UPDATE `quest_template_addon` SET PrevQuestID =     38691 WHERE `ID` = 38718;
UPDATE `quest_template_addon` SET NextQuestID =     38714 WHERE `ID` = 38718;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38718;
-- Black Rook Hold
UPDATE `quest_template_addon` SET PrevQuestID =     38718 WHERE `ID` = 38716;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 38716;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38716;

-- The Rook's Guard
UPDATE `quest_template_addon` SET PrevQuestID =     38718 WHERE `ID` = 38715;
UPDATE `quest_template_addon` SET NextQuestID =     38717 WHERE `ID` = 38715;
UPDATE `quest_template_addon` SET ExclusiveGroup = -38714 WHERE `ID` = 38715;
-- Maiev's Trail
UPDATE `quest_template_addon` SET PrevQuestID =     38718 WHERE `ID` = 38714;
UPDATE `quest_template_addon` SET NextQuestID =     38717 WHERE `ID` = 38714;
UPDATE `quest_template_addon` SET ExclusiveGroup = -38714 WHERE `ID` = 38714;

-- Black Rook Prison
UPDATE `quest_template_addon` SET PrevQuestID =     38714 WHERE `ID` = 38717;
UPDATE `quest_template_addon` SET NextQuestID =     38724 WHERE `ID` = 38717;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38717;

-- Illidari Freedom
UPDATE `quest_template_addon` SET PrevQuestID =     38717 WHERE `ID` = 38719;
UPDATE `quest_template_addon` SET NextQuestID =     38721 WHERE `ID` = 38719;
UPDATE `quest_template_addon` SET ExclusiveGroup = -38724 WHERE `ID` = 38719;
-- Brotherly Love
UPDATE `quest_template_addon` SET PrevQuestID =     38717 WHERE `ID` = 38724;
UPDATE `quest_template_addon` SET NextQuestID =     38721 WHERE `ID` = 38724;
UPDATE `quest_template_addon` SET ExclusiveGroup = -38724 WHERE `ID` = 38724;

-- Lieutenant of the Tower
UPDATE `quest_template_addon` SET PrevQuestID =     38724 WHERE `ID` = 38721;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 38721;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 38721;


-- Where the Wildkin Are --
-- Where the Wildkin Are
UPDATE `quest_template_addon` SET PrevQuestID =         0 WHERE `ID` = 42747;
UPDATE `quest_template_addon` SET NextQuestID =     42751 WHERE `ID` = 42747;
UPDATE `quest_template_addon` SET ExclusiveGroup = -42747 WHERE `ID` = 42747;
-- Emerald Sisters
UPDATE `quest_template_addon` SET PrevQuestID =         0 WHERE `ID` = 42748;
UPDATE `quest_template_addon` SET NextQuestID =     42751 WHERE `ID` = 42748;
UPDATE `quest_template_addon` SET ExclusiveGroup = -42747 WHERE `ID` = 42748;
-- Dreamcatcher
UPDATE `quest_template_addon` SET PrevQuestID =         0 WHERE `ID` = 42750;
UPDATE `quest_template_addon` SET NextQuestID =     42751 WHERE `ID` = 42750;
UPDATE `quest_template_addon` SET ExclusiveGroup = -42747 WHERE `ID` = 42750;

-- Moon Reaver
UPDATE `quest_template_addon` SET PrevQuestID =     42747 WHERE `ID` = 42751;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 42751;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 42751;

