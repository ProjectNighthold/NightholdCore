/*
 *###############################################################################
 *#                                                                             #
 *# Copyright (C) 2022 Project Nighthold <https://github.com/ProjectNighthold>  #
 *#                                                                             #
 *# This file is free software; as a special exception the author gives         #
 *# unlimited permission to copy and/or distribute it, with or without          #
 *# modifications, as long as this notice is preserved.                         #
 *#                                                                             #
 *# This program is distributed in the hope that it will be useful, but         #
 *# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the      #
 *# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.    #
 *#                                                                             #
 *# Read the THANKS file on the source root directory for more info.            #
 *#                                                                             #
 *###############################################################################
 */

#include "LFGMgr.h"
#include "Group.h"
/*
UPDATE  `creature_template` SET  `faction` =  '14', `ScriptName` =  'boss_coren_direbrew' WHERE `entry` =23872 LIMIT 1 ;
UPDATE creature SET `spawntimesecs` = 604800 WHERE `id` =23872;
UPDATE  `quest_template` SET  `SpecialFlags` =  '9' WHERE  `entry` =25483 LIMIT 1 ;
*/
class boss_coren_direbrew : public CreatureScript
{
    public:
        boss_coren_direbrew() : CreatureScript("boss_coren_direbrew") { }

        struct boss_coren_direbrewAI : public BossAI
        {
            boss_coren_direbrewAI(Creature* creature) : BossAI(creature, 10) {}

            void Reset()
            {
            }

            void JustDied(Unit* /*victim*/)
            {
                if (instance)
                {
                    // LFG reward
                    Map::PlayerList const& players = instance->instance->GetPlayers();
                    LFGDungeonsEntry const* dungeon = sLfgDungeonsStore.LookupEntry(287); //lfg id

                    if (!players.isEmpty())
                    {
                        if (Group* group = players.begin()->getSource()->GetGroup())
                        if (group->isLFGGroup())
                            sLFGMgr->FinishDungeon(group->GetGUID(), dungeon->ID);
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_coren_direbrewAI(creature);
        }
};

void AddSC_coren_direbrew()
{
    new boss_coren_direbrew();
}
