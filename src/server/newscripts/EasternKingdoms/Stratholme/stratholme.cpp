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

/* ScriptData
SDName: Stratholme
SD%Complete: 100
SDComment: Misc mobs for instance. go-script to apply aura and start event for quest 8945
SDCategory: Stratholme
EndScriptData */

/* ContentData
go_gauntlet_gate
mob_freed_soul
mob_restless_soul
mobs_spectral_ghostly_citizen
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stratholme.h"
#include "Group.h"

/*######
## go_gauntlet_gate (this is the _first_ of the gauntlet gates, two exist)
######*/

class go_gauntlet_gate : public GameObjectScript
{
public:
    go_gauntlet_gate() : GameObjectScript("go_gauntlet_gate") {}

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        InstanceScript* instance = go->GetInstanceScript();

        if (!instance)
            return false;

        if (instance->GetData(TYPE_BARON_RUN) != NOT_STARTED)
            return false;

        if (Group* group = player->GetGroup())
        {
            for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
            {
                Player* pGroupie = itr->getSource();
                if (!pGroupie)
                    continue;

                if (pGroupie->GetQuestStatus(QUEST_DEAD_MAN_PLEA) == QUEST_STATUS_INCOMPLETE &&
                    !pGroupie->HasAura(SPELL_BARON_ULTIMATUM) &&
                    pGroupie->GetMap() == go->GetMap())
                    pGroupie->CastSpell(pGroupie, SPELL_BARON_ULTIMATUM, true);
            }
        }
        else if (player->GetQuestStatus(QUEST_DEAD_MAN_PLEA) == QUEST_STATUS_INCOMPLETE &&
                    !player->HasAura(SPELL_BARON_ULTIMATUM) &&
                    player->GetMap() == go->GetMap())
                    player->CastSpell(player, SPELL_BARON_ULTIMATUM, true);

        instance->SetData(TYPE_BARON_RUN, IN_PROGRESS);
        return false;
    }

};

/*######
## mob_freed_soul
######*/
class mob_freed_soul : public CreatureScript
{
public:
    mob_freed_soul() : CreatureScript("mob_freed_soul") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_freed_soulAI (creature);
    }

    struct mob_freed_soulAI : public ScriptedAI
    {
        mob_freed_soulAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            Talk(0);
        }

        void EnterCombat(Unit* /*who*/) override {}
    };
};

/*######
## mob_restless_soul
######*/

#define SPELL_EGAN_BLASTER  17368
#define SPELL_SOUL_FREED    17370
#define QUEST_RESTLESS_SOUL 5282
#define ENTRY_RESTLESS      11122
#define ENTRY_FREED         11136

class mob_restless_soul : public CreatureScript
{
public:
    mob_restless_soul() : CreatureScript("mob_restless_soul") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_restless_soulAI (creature);
    }

    struct mob_restless_soulAI : public ScriptedAI
    {
        mob_restless_soulAI(Creature* creature) : ScriptedAI(creature) {}

        ObjectGuid Tagger;
        uint32 Die_Timer;
        bool Tagged;

        void Reset() override
        {
            Tagger.Clear();
            Die_Timer = 5000;
            Tagged = false;
        }

        void EnterCombat(Unit* /*who*/) override {}

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (caster->IsPlayer())
            {
                if (!Tagged && spell->Id == SPELL_EGAN_BLASTER && CAST_PLR(caster)->GetQuestStatus(QUEST_RESTLESS_SOUL) == QUEST_STATUS_INCOMPLETE)
                {
                    Tagged = true;
                    Tagger = caster->GetGUID();
                }
            }
        }

        void JustSummoned(Creature* summoned) override
        {
            summoned->CastSpell(summoned, SPELL_SOUL_FREED, false);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Tagged)
                me->SummonCreature(ENTRY_FREED, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 300000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (Tagged)
            {
                if (Die_Timer <= diff)
                {
                    if (Unit* temp = Unit::GetUnit(*me, Tagger))
                    {
                        CAST_PLR(temp)->KilledMonsterCredit(ENTRY_RESTLESS, me->GetGUID());
                        me->Kill(me);
                    }
                }
                else
                    Die_Timer -= diff;
            }
        }
    };
};

/*######
## mobs_spectral_ghostly_citizen
######*/

enum eGhostlyCitizenSpells
{
    SPELL_HAUNTING_PHANTOM  = 16336,
    SPELL_SLAP              = 6754
};

class mobs_spectral_ghostly_citizen : public CreatureScript
{
public:
    mobs_spectral_ghostly_citizen() : CreatureScript("mobs_spectral_ghostly_citizen") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mobs_spectral_ghostly_citizenAI (creature);
    }

    struct mobs_spectral_ghostly_citizenAI : public ScriptedAI
    {
        mobs_spectral_ghostly_citizenAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 Die_Timer;
        bool Tagged;

        void Reset() override
        {
            Die_Timer = 5000;
            Tagged = false;
        }

        void EnterCombat(Unit* /*who*/) override {}

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) override
        {
            if (!Tagged && spell->Id == SPELL_EGAN_BLASTER)
                Tagged = true;
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Tagged)
            {
                for (uint32 i = 1; i <= 4; ++i)
                {
                     //100%, 50%, 33%, 25% chance to spawn
                     if (urand(1, i) == 1)
                         DoSummon(ENTRY_RESTLESS, me, 20.0f, 600000);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (Tagged)
            {
                if (Die_Timer <= diff)
                    me->Kill(me);
                else
                    Die_Timer -= diff;
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void ReceiveEmote(Player* player, uint32 emote) override
        {
            switch (emote)
            {
                case TEXT_EMOTE_DANCE:
                    EnterEvadeMode();
                    break;
                case TEXT_EMOTE_RUDE:
                    if (me->IsWithinDistInMap(player, 5))
                        DoCast(player, SPELL_SLAP, false);
                    else
                        me->HandleEmoteCommand(EMOTE_ONESHOT_RUDE);
                    break;
                case TEXT_EMOTE_WAVE:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);
                    break;
                case TEXT_EMOTE_BOW:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_BOW);
                    break;
                case TEXT_EMOTE_KISS:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_FLEX);
                    break;
            }
        }
    };
};

void AddSC_stratholme()
{
    new go_gauntlet_gate();
    new mob_freed_soul();
    new mob_restless_soul();
    new mobs_spectral_ghostly_citizen();
}
