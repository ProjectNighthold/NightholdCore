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

#include "sunwell_plateau.h"

enum Quotes
{
    YELL_AGGRO                 =   0,
    YELL_KILL                  =   1,
    YELL_LOVE                  =   2,
    YELL_BERSERK               =   3,
    YELL_DEATH                 =   4
};

enum Spells
{
    SPELL_METEOR_SLASH                 =   45150,
    SPELL_BURN                         =   46394,
    SPELL_STOMP                        =   45185,
    SPELL_BERSERK                      =   26662,
    SPELL_DUAL_WIELD                   =   42459,

    SPELL_INTRO_FROST_BLAST            =   45203,
    SPELL_INTRO_FROSTBOLT              =   44843,
    SPELL_INTRO_ENCAPSULATE            =   45665,
    SPELL_INTRO_ENCAPSULATE_CHANELLING =   45661
};

enum sEvents
{
     EVENT_SLASH          = 1,
     EVENT_STOMP          = 2,
     EVENT_BURN           = 3,
     EVENT_BERSERK        = 4,
};

class boss_brutallus : public CreatureScript
{
public:
    boss_brutallus() : CreatureScript("boss_brutallus") {}

    struct boss_brutallusAI : public BossAI
    {
        boss_brutallusAI(Creature* creature) : BossAI(creature, DATA_BRUTALLUS_EVENT)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset()
        {
            _Reset();
            DoCast(me, SPELL_DUAL_WIELD, true);
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            Talk(YELL_AGGRO);
            events.RescheduleEvent(EVENT_SLASH,                11000);
            events.RescheduleEvent(EVENT_STOMP,                30000);
            events.RescheduleEvent(EVENT_BURN,  urand(60000, 180000));
            events.RescheduleEvent(EVENT_BERSERK,             360000);
        }

        void KilledUnit(Unit* victim)
        {
            if (victim->IsPlayer())
                Talk(YELL_KILL);
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(YELL_DEATH);
            _JustDied();
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SLASH:
                    DoCastVictim(SPELL_METEOR_SLASH);
                    events.RescheduleEvent(EVENT_SLASH, 11000);
                    break;
                case EVENT_STOMP:
                    Talk(YELL_LOVE);
                    DoCastVictim(SPELL_STOMP);
                    events.RescheduleEvent(EVENT_STOMP, 30000);
                    break;
                case EVENT_BURN:
                    {
                        Map::PlayerList const &players = me->GetMap()->GetPlayers();
                        for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                        {
                            if (Player* pl = i->getSource())
                                if (pl->isAlive())
                                {
                                    if (!pl->HasAura(SPELL_BURN))
                                    {
                                        pl->CastSpell(pl, SPELL_BURN, true);
                                        break;
                                    }
                                }
                        }
                        events.RescheduleEvent(EVENT_BURN, urand(60000, 180000));
                        break;
                    }
                case EVENT_BERSERK:
                    Talk(YELL_BERSERK);
                    DoCast(me, SPELL_BERSERK);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_brutallusAI (creature);
    }
};

void AddSC_boss_brutallus()
{
    new boss_brutallus();
}
