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
#include "SpellScript.h"
#include "Vehicle.h"

// 49337
struct npc_darnel_q26800 : public ScriptedAI
{
    npc_darnel_q26800(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        Talk(0);
    }

    void DoAction(int32 const action) override
    {
        if (action == ACTION_1)
        {
            for (uint8 i = 1; i < 4; ++i)
            {
                if (auto pass = me->GetVehicleKit()->GetPassenger(i))
                    pass->ExitVehicle();
            }
        }
    }

    void PassengerBoarded(Unit* who, int8 seatId, bool apply) override
    {
        if (!me->GetVehicle())
            return;

        if (!apply && who->ToCreature())
        {
            who->ToCreature()->DespawnOrUnsummon(2000);
        }
    }
};

// 49340
struct npc_scarlet_corpse_q26800 : public ScriptedAI
{
    npc_scarlet_corpse_q26800(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    bool used = false;

    void Reset() override
    {
        used = false;
    }

    void IsSummonedBy(Unit* summoner) override
    {
        used = true;
        me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        me->RemoveAura(92230);
    }

    void OnSpellClick(Unit* who) override
    {
        if (!used)
        {
            used = true;
            auto cList = who->GetSummonList(49337);
            for (GuidList::const_iterator iter = cList->begin(); iter != cList->end(); ++iter)
            {
                if (auto darnel = ObjectAccessor::GetCreature(*who, (*iter)))
                {
                    if (auto sum = me->SummonCreature(49340, me->GetPosition()))
                    {
                        if (auto plr = who->ToPlayer())
                        {
                            plr->KilledMonsterCredit(49340);
                            sum->CastSpell(darnel, 46598, true);
                            me->DespawnOrUnsummon(100);
                        }
                    }
                }
            }
        }
    }
};

// 1740
struct npc_deathguard_saltain : public ScriptedAI
{
    npc_deathguard_saltain(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void OnQuestReward(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == 26800)
        {
            auto cList = player->GetSummonList(49337);
            for (GuidList::const_iterator iter = cList->begin(); iter != cList->end(); ++iter)
            {
                if (auto darnel = ObjectAccessor::GetCreature(*player, (*iter)))
                {
                    if (darnel->IsAIEnabled)
                        darnel->AI()->DoAction(ACTION_1);
                }
            }
        }
    }

};



// 91938
class spell_summon_darnel_q26800 : public AuraScript
{
    PrepareAuraScript(spell_summon_darnel_q26800);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (auto caster = GetCaster())
        {
            auto cList = caster->GetSummonList(49337);
            for (GuidList::const_iterator iter = cList->begin(); iter != cList->end(); ++iter)
            {
                if (auto darnel = ObjectAccessor::GetCreature(*caster, (*iter)))
                    darnel->DespawnOrUnsummon(100);
            }
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_summon_darnel_q26800::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

enum loginUndead
{
    SPELL_RIGOR_MORTIS = 73523,
    QUEST_FRESH_OUT_OF_THE_GRAVE = 24959,
    SPELL_VALKYR_RESURRECTION = 73524
};

class first_login_undead : public PlayerScript
{
public:
    first_login_undead() : PlayerScript("first_login_undead") { }

    void OnLogin(Player* player)
    {
        if (player->getRace() == RACE_UNDEAD_PLAYER && player->GetQuestStatus(QUEST_FRESH_OUT_OF_THE_GRAVE) == QUEST_STATE_NONE)
        {
            player->AddAura(SPELL_RIGOR_MORTIS, player);
        }
    }
};

class npc_agatha : public CreatureScript
{
public:
    npc_agatha() : CreatureScript("npc_agatha") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_FRESH_OUT_OF_THE_GRAVE)
        {
            player->CastSpell(player, SPELL_VALKYR_RESURRECTION);
            player->RemoveAura(SPELL_RIGOR_MORTIS);
        }
        return true;
    }
};

void AddSC_tirisfal_glades()
{
    new first_login_undead();
    new npc_agatha();
    RegisterCreatureAI(npc_darnel_q26800);
    RegisterCreatureAI(npc_scarlet_corpse_q26800);
    RegisterCreatureAI(npc_deathguard_saltain);
    RegisterAuraScript(spell_summon_darnel_q26800);
}
