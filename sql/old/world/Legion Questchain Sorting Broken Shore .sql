-- Legion Questchain Sorting: Broken Shore --
-- Breaching the Tomb 1/3
-- Armies of Legionfall
UPDATE `quest_template_addon` SET PrevQuestID =     44184 WHERE `ID` = 46730;
UPDATE `quest_template_addon` SET NextQuestID =     46734 WHERE `ID` = 46730;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 46730;

-- Assault on Broken Shore
UPDATE `quest_template_addon` SET PrevQuestID =     46730 WHERE `ID` = 46734;
UPDATE `quest_template_addon` SET NextQuestID =     47137 WHERE `ID` = 46734;
UPDATE `quest_template_addon` SET ExclusiveGroup = -46247 WHERE `ID` = 46734;
-- Defending Broken Isles
UPDATE `quest_template_addon` SET PrevQuestID =     46730 WHERE `ID` = 46247;
UPDATE `quest_template_addon` SET NextQuestID =     47137 WHERE `ID` = 46247;
UPDATE `quest_template_addon` SET ExclusiveGroup = -46247 WHERE `ID` = 46247;

-- Legionfall Supplies
UPDATE `quest_template_addon` SET PrevQuestID =     46247 WHERE `ID` = 46286;
UPDATE `quest_template_addon` SET NextQuestID =     46245 WHERE `ID` = 46286;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 46286;

-- Begin Construction
UPDATE `quest_template_addon` SET PrevQuestID =     46286 WHERE `ID` = 46245;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 46245;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 46245;

-- Aalgen Point
UPDATE `quest_template_addon` SET PrevQuestID =     46734 WHERE `ID` = 46832;
UPDATE `quest_template_addon` SET NextQuestID =     46845 WHERE `ID` = 46832;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 46832;

-- Vengeance Point
UPDATE `quest_template_addon` SET PrevQuestID =     46832 WHERE `ID` = 46845;
UPDATE `quest_template_addon` SET NextQuestID =     46499 WHERE `ID` = 46845;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 46845;
-- Treasure Master Iks'reeged --
-- Spiders, Huh?
UPDATE `quest_template_addon` SET PrevQuestID =     46845 WHERE `ID` = 46499;
UPDATE `quest_template_addon` SET NextQuestID =     46501 WHERE `ID` = 46499;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 46499;

-- Grave Robbin'
UPDATE `quest_template_addon` SET PrevQuestID =     46499 WHERE `ID` = 46501;
UPDATE `quest_template_addon` SET NextQuestID =     46509 WHERE `ID` = 46501;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 46501;

-- Tomb Raidering
UPDATE `quest_template_addon` SET PrevQuestID =     46501 WHERE `ID` = 46509;
UPDATE `quest_template_addon` SET NextQuestID =     46510 WHERE `ID` = 46509;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 46509;

-- Ship Graveyard
UPDATE `quest_template_addon` SET PrevQuestID =     46509 WHERE `ID` = 46510;
UPDATE `quest_template_addon` SET NextQuestID =     46511 WHERE `ID` = 46510;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 46510;

-- We're Treasure Hunters
UPDATE `quest_template_addon` SET PrevQuestID =     46510 WHERE `ID` = 46511;
UPDATE `quest_template_addon` SET NextQuestID =     46666 WHERE `ID` = 46511;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 46511;

-- The Motherlode
UPDATE `quest_template_addon` SET PrevQuestID =     46511 WHERE `ID` = 46666;
UPDATE `quest_template_addon` SET NextQuestID =     45379 WHERE `ID` = 46666;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 46666;

-- Treasure Master Iks'reeged
UPDATE `quest_template_addon` SET PrevQuestID =     46666 WHERE `ID` = 45379;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 45379;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 45379;

-- Breaching the Tomb --
-- Champions of Legionfall
UPDATE `quest_template_addon` SET PrevQuestID =     46734 WHERE `ID` = 47137;
UPDATE `quest_template_addon` SET NextQuestID =     46251 WHERE `ID` = 47137;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 47137;

-- Recruit a Champion From Legionfall --
-- Breaching the Tomb --
-- Shard Times
UPDATE `quest_template_addon` SET PrevQuestID =     47137 WHERE `ID` = 46251;
UPDATE `quest_template_addon` SET NextQuestID =     47139 WHERE `ID` = 46251;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 46251;

-- Mark of the Sentinax
UPDATE `quest_template_addon` SET PrevQuestID =     46251 WHERE `ID` = 47139;
UPDATE `quest_template_addon` SET NextQuestID =     46248 WHERE `ID` = 47139;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 47139;

-- Self-Fulfilling Prophecy
UPDATE `quest_template_addon` SET PrevQuestID =     47139 WHERE `ID` = 46248;
UPDATE `quest_template_addon` SET NextQuestID =     46252 WHERE `ID` = 46248;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 46248;

-- Intolerable Infestation
UPDATE `quest_template_addon` SET PrevQuestID =     46248 WHERE `ID` = 46252;
UPDATE `quest_template_addon` SET NextQuestID =     46769 WHERE `ID` = 46252;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 46252;

-- Relieved of Their Valuables
UPDATE `quest_template_addon` SET PrevQuestID =     46252 WHERE `ID` = 46769;
UPDATE `quest_template_addon` SET NextQuestID =     46250 WHERE `ID` = 46769;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 46769;

-- Take Out the Head...
UPDATE `quest_template_addon` SET PrevQuestID =     46769 WHERE `ID` = 46250;
UPDATE `quest_template_addon` SET NextQuestID =     46249 WHERE `ID` = 46250;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 46250;

-- Championing Our Cause
UPDATE `quest_template_addon` SET PrevQuestID =     46250 WHERE `ID` = 46249;
UPDATE `quest_template_addon` SET NextQuestID =     46246 WHERE `ID` = 46249;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 46249;

-- Strike Them Down
UPDATE `quest_template_addon` SET PrevQuestID =     46249 WHERE `ID` = 46246;
UPDATE `quest_template_addon` SET NextQuestID =         0 WHERE `ID` = 46246;
UPDATE `quest_template_addon` SET ExclusiveGroup =      0 WHERE `ID` = 46246;
