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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "blackwing_lair.h"
#include "ScriptedGossip.h"
#include "Player.h"

enum Says
{
   SAY_LINE1                         = 0,
   SAY_LINE2                         = 1,
   SAY_LINE3                         = 2,
   SAY_HALFLIFE                      = 3,
   SAY_KILLTARGET                    = 4
};

enum Gossip
{
   GOSSIP_ID                         = 21334,
};

enum Spells
{
   SPELL_ESSENCEOFTHERED             = 23513,
   SPELL_FLAMEBREATH                 = 23461,
   SPELL_FIRENOVA                    = 23462,
   SPELL_TAILSWIPE                   = 15847,
   SPELL_BURNINGADRENALINE           = 23620,
   SPELL_CLEAVE                      = 20684   //Chain cleave is most likely named something different and contains a dummy effect
};

enum Events
{
    EVENT_SPEECH_1                  = 1,
    EVENT_SPEECH_2                  = 2,
    EVENT_SPEECH_3                  = 3,
    EVENT_SPEECH_4                  = 4,
    EVENT_ESSENCEOFTHERED           = 5,
    EVENT_FLAMEBREATH               = 6,
    EVENT_FIRENOVA                  = 7,
    EVENT_TAILSWIPE                 = 8,
    EVENT_CLEAVE                    = 9,
    EVENT_BURNINGADRENALINE_CASTER  = 10,
    EVENT_BURNINGADRENALINE_TANK    = 11
};

class boss_vaelastrasz : public CreatureScript
{
public:
    boss_vaelastrasz() : CreatureScript("boss_vaelastrasz") { }

    struct boss_vaelAI : public BossAI
    {
        boss_vaelAI(Creature* creature) : BossAI(creature, BOSS_VAELASTRAZ)
        {
            creature->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            creature->setFaction(35);
            creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void Reset()
        {
            _Reset();
            PlayerGUID.Clear();

            me->SetStandState(UNIT_STAND_STATE_DEAD);

            HasYelled = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();

            DoCast(me, SPELL_ESSENCEOFTHERED);
            me->SetHealth(me->CountPctFromMaxHealth(30));
            // now drop damage requirement to be able to take loot
            me->ResetPlayerDamageReq();

            events.RescheduleEvent(EVENT_CLEAVE, 10000);
            events.RescheduleEvent(EVENT_FLAMEBREATH, 15000);
            events.RescheduleEvent(EVENT_FIRENOVA, 20000);
            events.RescheduleEvent(EVENT_TAILSWIPE, 11000);
            events.RescheduleEvent(EVENT_BURNINGADRENALINE_CASTER, 15000);
            events.RescheduleEvent(EVENT_BURNINGADRENALINE_TANK, 45000);
        }

        void BeginSpeech(Unit* target)
        {
            PlayerGUID = target->GetGUID();
            me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            events.RescheduleEvent(EVENT_SPEECH_1, 1000);
        }

        void KilledUnit(Unit* victim)
        {
            if (rand()%5)
                return;

            Talk(SAY_KILLTARGET, victim->GetGUID());
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            // Speech
            if (!UpdateVictim())
            {
                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SPEECH_1:
                            Talk(SAY_LINE1);
                            me->SetStandState(UNIT_STAND_STATE_STAND);
                            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                            events.RescheduleEvent(EVENT_SPEECH_2, 12000);
                            break;
                        case EVENT_SPEECH_2:
                            Talk(SAY_LINE2);
                            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                            events.RescheduleEvent(EVENT_SPEECH_3, 12000);
                            break;
                        case EVENT_SPEECH_3:
                            Talk(SAY_LINE3);
                            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                            events.RescheduleEvent(EVENT_SPEECH_4, 16000);
                            break;
                        case EVENT_SPEECH_4:
                            me->setFaction(103);
                            if (PlayerGUID && Unit::GetUnit(*me, PlayerGUID))
                                AttackStart(Unit::GetUnit(*me, PlayerGUID));;
                            break;
                    }
                }
                return;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CLEAVE:
                        events.RescheduleEvent(EVENT_CLEAVE, 15000);
                        DoCastVictim(SPELL_CLEAVE);
                        break;
                    case EVENT_FLAMEBREATH:
                        DoCastVictim(SPELL_FLAMEBREATH);
                        events.RescheduleEvent(EVENT_FLAMEBREATH, urand(8000, 14000));
                        break;
                    case EVENT_FIRENOVA:
                        DoCastVictim(SPELL_FIRENOVA);
                        events.RescheduleEvent(EVENT_FIRENOVA, 15000);
                        break;
                    case EVENT_TAILSWIPE:
                        //Only cast if we are behind
                        /*if (!me->HasInArc(M_PI, me->GetVictim()))
                        {
                        DoCast(me->GetVictim(), SPELL_TAILSWIPE);
                        }*/
                        events.RescheduleEvent(EVENT_TAILSWIPE, 15000);
                        break;
                    case EVENT_BURNINGADRENALINE_CASTER:
                        {
                            Unit* target = NULL;

                            uint8 i = 0;
                            while (i < 3)   // max 3 tries to get a random target with power_mana
                            {
                                ++i;
                                target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true); // not aggro leader
                                if (target && target->getPowerType() == POWER_MANA)
                                    i = 3;
                            }
                            if (target)                                     // cast on self (see below)
                                target->CastSpell(target, SPELL_BURNINGADRENALINE, true);
                        }
                        events.RescheduleEvent(EVENT_BURNINGADRENALINE_CASTER, 15000);
                        break;
                    case EVENT_BURNINGADRENALINE_TANK:
                        // have the victim cast the spell on himself otherwise the third effect aura will be applied to Vael instead of the player
                        me->getVictim()->CastSpell(me->getVictim(), SPELL_BURNINGADRENALINE, true);
                        events.RescheduleEvent(EVENT_BURNINGADRENALINE_TANK, 45000);
                        break;
                }
            }

            // Yell if hp lower than 15%
            if (HealthBelowPct(15) && !HasYelled)
            {
                Talk(SAY_HALFLIFE);
                HasYelled = true;
            }

            DoMeleeAttackIfReady();
        }

        void sGossipSelect(Player* player, uint32 sender, uint32 action)
        {
            if (sender == GOSSIP_ID && action == 0)
            {
                player->CLOSE_GOSSIP_MENU();
                BeginSpeech(player);
            }
        }

        private:
            ObjectGuid PlayerGUID;
            bool HasYelled;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetInstanceAI<boss_vaelAI>(creature);
    }
};

void AddSC_boss_vaelastrasz()
{
    new boss_vaelastrasz();
}
