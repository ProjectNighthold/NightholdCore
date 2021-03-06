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

#include "the_nighthold.h"
#include "Packets/SpellPackets.h"

enum Spells
{
    SpellSlam                   = 205862,
    SpellSlamATRight            = 205880,
    SpellSlamATLeft             = 205881,
    SpellSlamTriggerOnCircles   = 205863,
    SpellSlamTriggerAOE         = 225362,
    SpellSlamSmash              = 205875,

    SpellSearingBrand           = 206677,

    SpellFelBurst               = 206620,

    SpellFelBeamController      = 205383,
    SpellFelBeam                = 205370,
    SpellFelBeamDamage          = 205391,

    SpellOrbDestruction         = 205344,
    SpellOrbDestructionCast     = 205361,

    SpellBurningPitchPrecast    = 205420,
    SpellBurningPitchVisual     = 206307,
    SpellBurningPitchVisual2    = 206281,
    SpellBurningPitchSummon     = 206350,
    SpellBurningPitchDamage     = 206376,
    SpellBurningPitchModDamage  = 215944, //Deprecated?

    SpellIsolatedRageAura       = 208201,
    SpellIsolatedRageDmg1       = 208203,
    SpellIsolatedRageDmg2       = 208194,

    SpellFelBlast               = 209017,
    SpellFelBlust               = 206351,
    SpellAccelerate             = 209006,
    SpellBurnout                = 214141,

    //Christmas
    SPELL_CHRISTMAS_CAP         = 220518
};

Position const movementPositions[] =
{
    { -96.519f, 2794.32f, 3.659f },
    { -71.430f, 2809.25f, 3.659f },
    { -46.430f, 2824.25f, 3.659f },
    { -21.430f, 2839.25f, 3.659f },
};

Position const slamAtPositions[] =
{
    { -101.97f, 2783.92f, 3.16f },
    {  -75.62f, 2799.22f, 3.16f },
    {  -48.81f, 2813.67f, 3.16f },
    {  -22.03f, 2828.23f, 3.16f },

    { -108.36f, 2795.58f, 3.16f },
    {  -81.57f, 2809.99f, 3.16f },
    {  -55.22f, 2825.28f, 3.16f },
    {  -29.28f, 2841.07f, 3.16f }
};

struct BurningPitchData
{
    Position PosMin;
    Position PosMax;
};

BurningPitchData burningPitches[] =
{
    { { -107.091537f, 2780.961914f }, { -15.032656f, 2848.733643f } },
    { { -80.678909f, 2797.868408f }, { -17.259027f, 2848.385010f } },
    { { -58.884304f, 2809.939209f }, { -16.224754f, 2849.433594f } },
    { { -38.795380f, 2816.897949f }, { -11.434778f, 2850.490723f } }
};

struct LinesData
{
    Position Pos1;
    Position Pos2;
    Position Pos3;
    Position Pos4;
};

LinesData LinezCrossData[] =
{
    { { -28.321032f, 2848.733643f, 3.17f }, { -15.032656f, 2824.966309f, 3.17f }, { -92.455811f, 2780.961914f, 3.17f }, { -107.091537f, 2804.419189f, 3.17f } },
    { { -31.217550f, 2848.385010f, 3.17f }, { -17.259027f, 2827.575684f, 3.17f }, { -65.974739f, 2797.868408f, 3.17f }, { -80.678909f, 2818.099121f, 3.17f } },
    { { -28.304945f, 2849.433594f, 3.17f }, { -16.224754f, 2826.051514f, 3.17f }, { -47.342018f, 2809.939209f, 3.17f }, { -58.884304f, 2834.493408f, 3.17f } },
    { { -22.711079f, 2850.490723f, 3.17f }, { -11.434778f, 2828.723633f, 3.17f }, { -25.173914f, 2816.897949f, 3.17f }, { -38.795380f, 2846.193604f, 3.17f } }
};

Position const PlatformMid[] =
{
    { -62.388672f, 2814.183105f, 3.17f },
    { -51.350227f, 2820.720215f, 3.17f },
    { -37.900650f, 2828.584717f, 3.17f },
    { -23.073122f, 2837.892090f, 3.17f }
};

Position const lineBeamPos[2] =
{
    {-111.67f, 2785.84f, 3.16f},
    {-12.48f, 2843.19f, 3.24f}
};

struct Lines
{
    Position Pos1;
    Position Pos2;
};

// 101002
struct boss_krosus : BossAI
{
    explicit boss_krosus(Creature* creature) : BossAI(creature, DATA_KROSUS)
    {
        me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN | UNIT_FLAG2_UNK6);
        me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_PREVENT_SELECT_NPC);
        me->SetSpeed(MOVE_RUN, 12.0f);
        me->SetSpeed(MOVE_FLIGHT, 2.0f);
        SetCombatMovement(false);

        InitializeTimers();
    }

    void InitializeTimers()
    {
        switch (GetDifficultyID())
        {
        case DIFFICULTY_LFR_RAID:
        case DIFFICULTY_NORMAL_RAID:
            OrbOfDestructionTimers = { 70, 40, 60, 25, 60, 37, 15, 15, 30 };
            FelBeamTimers = { 5, 15, 30, 30, 23, 27, 30, 44, 14, 16, 14, 16, 22, 60 };
            BurningPitchTimerss = { 38, 102, 85, 90 };
            break;
        case DIFFICULTY_HEROIC_RAID:
            OrbOfDestructionTimers = { 19, 60, 23, 62, 27, 25, 15, 15, 14, 30, 55 };
            FelBeamTimers = { 7, 29, 30, 42, 16, 16, 14, 16, 27, 54, 26, 5, 5, 16, 5, 12, 12, 5, 13 }; // Complete up to berserk (not yet verified in 7.1.5)
            BurningPitchTimerss = { 49, 85, 90, 94 };
            break;
        case DIFFICULTY_MYTHIC_RAID:
            OrbOfDestructionTimers = { 13, 62, 27, 25, 14, 15, 15, 30, 55, 38, 30, 12, 18 }; // (up to 5:55, missing 5 seconds?)
            FelBeamTimers = { 6, 16, 16, 16, 14, 16, 27, 55, 26, 4, 21, 4, 12, 12, 4, 13, 19, 4, 25, 4, 25, 4 }; // (up to 5:55, missing 5 seconds?)
            BurningPitchTimerss = { 45, 90, 93, 78 };
            break;
        default:
            break;
        }
    }

    void ScheduleTasks() override
    {
        scheduler.Schedule(Seconds(8), 2, [this](TaskContext context) //Check closest players
        {
            bool found = false;

            std::list<HostileReference*> threatList = me->getThreatManager().getThreatList();
            for (auto const& ref : threatList)
            {
                if (auto player = Player::GetPlayer(*me, ref->getUnitGuid()))
                {
                    if (me->IsWithinMeleeRange(player))
                    {
                        found = true;
                        break;
                    }
                }
            }
            if (!found)
            {
                context.DelayGroup(1, Milliseconds(800));
                context.Repeat(Milliseconds(800));
                DoCast(me, SpellIsolatedRageDmg1, true);
                DoCast(me, SpellIsolatedRageDmg2, true);
            }
            else
                context.Repeat(Seconds(2));
        });

        //scheduler.Schedule(Seconds(3), 2, [this](TaskContext context) //Player check under ground
        //{
        //    context.Repeat(Seconds(3));
        //
        //    std::list<HostileReference*> threatList = me->getThreatManager().getThreatList();
        //    for (auto const& ref : threatList)
        //    {
        //        if (auto target = Unit::GetUnit(*me, ref->getUnitGuid()))
        //            if (target->GetPositionZ() < 3.10f && target->GetDistance(me) < 100.0f)
        //                target->CastSpell(target, 27965, true); //Suicide
        //    }
        //});

        scheduler.Schedule(Seconds(2), 1, [this](TaskContext context)
        {
            context.Repeat(Seconds(4));
            DoCastVictim(SpellSearingBrand, true);
        });

        scheduler.Schedule(Seconds(30), 1, [this](TaskContext context)
        {
            context.Repeat();
            me->SetPower(POWER_ENERGY, 0);
            me->CastSpell(slamAtPositions[PlatformID], SpellSlamATRight, true);
            me->CastSpell(slamAtPositions[PlatformID + 4], SpellSlamATLeft, true);
            DoCast(SpellSlam);
            Talk(SlamCounter == 2 ? 7 : 6);
        });

        scheduler.Schedule(Seconds(FelBeamTimers[0]), 1, [this](TaskContext context)
        {
            if (context.GetRepeatCounter() < FelBeamTimers.size())
                context.Repeat(Seconds(FelBeamTimers[context.GetRepeatCounter() + 1]));

            DoCast(me, SpellFelBeamController, true);

            if (auto spellInfo = sSpellMgr->GetSpellInfo(SpellFelBeam))
                const_cast<SpellInfo*>(spellInfo)->SetExtraSpellXSpellVisualId(FelBeamRight ? 104543 : 117235);

            if (Unit* target = me->FindNearestCreature(103999, 120.0f))
                DoCast(target, SpellFelBeam);
            else
                DoCast(SpellFelBeam);
        });

        scheduler.Schedule(Seconds(OrbOfDestructionTimers[0]), 1, [this](TaskContext context)
        {
            if (context.GetRepeatCounter() < OrbOfDestructionTimers.size())
                context.Repeat(Seconds(OrbOfDestructionTimers[context.GetRepeatCounter() + 1]));

            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 250.0f);

            playerList.remove_if([](Player* player) -> bool
            {
                return !player->IsRangedDamageDealer();
            });

            if (playerList.empty())
                return;

            auto const& target = Trinity::Containers::SelectRandomContainerElement(playerList);
            if (!target)
                return;

            DoCast(target, SpellOrbDestruction);
            Talk(6, target->GetGUID());

            DoCast(SpellOrbDestructionCast);
        });

        scheduler.Schedule(Seconds(BurningPitchTimerss[0]), 1, [this](TaskContext context)
        {
            if (context.GetRepeatCounter() < BurningPitchTimerss.size())
                context.Repeat(Seconds(BurningPitchTimerss[context.GetRepeatCounter() + 1]));

            PointList.clear();

            auto platfromLine = LinezCrossData[PlatformID];

            Lines LinezCross[4];
            LinezCross[0].Pos1 = platfromLine.Pos1;
            LinezCross[0].Pos2 = platfromLine.Pos2;
            LinezCross[1].Pos1 = platfromLine.Pos2;
            LinezCross[1].Pos2 = platfromLine.Pos3;
            LinezCross[2].Pos1 = platfromLine.Pos3;
            LinezCross[2].Pos2 = platfromLine.Pos4;
            LinezCross[3].Pos1 = platfromLine.Pos4;
            LinezCross[3].Pos2 = platfromLine.Pos1;

            auto pitchData = burningPitches[PlatformID];
            for (uint8 i = 0; i < PlayersCount;)
            {
                auto pos = Position{ frand(pitchData.PosMin.GetPositionX(), pitchData.PosMax.GetPositionX()), frand(pitchData.PosMin.GetPositionY(), pitchData.PosMax.GetPositionY()), 3.17f };

                auto canAdd = true;
                for (auto& linezCros : LinezCross)
                    if (PlatformMid[PlatformID].IsLinesCross(PlatformMid[PlatformID], pos, linezCros.Pos1, linezCros.Pos2))
                        canAdd = false;

                if (!canAdd)
                    continue;

                PointList.emplace_back(pos);
                ++i;
            }

            for (auto const& pos : PointList)
            {
                WorldPackets::Spells::PlaySpellVisual visual;
                visual.Source = me->GetGUID();
                visual.SpellVisualID = 54102;
                visual.TargetPosition = pos;
                visual.SpeedAsTime = true;
                visual.TravelSpeed = 5.f; // custom... need some extra function to calculate travel speed; seems like it based on Speed: 40.00 from spell / distance
                me->SendMessageToSet(visual.Write(), true);
            }

            DoCast(SpellBurningPitchPrecast);
        });

        scheduler.Schedule(Seconds(1), [this](TaskContext context)
        {
            context.Repeat();

            auto powerCount = me->GetPower(POWER_ENERGY);
            if (powerCount >= 100)
                return;

            if (PowerTick < 2)
            {
                PowerTick++;
                me->SetPower(POWER_ENERGY, powerCount + 1);
            }
            else
            {
                PowerTick = 0;
                me->SetPower(POWER_ENERGY, powerCount + 2);
            }
        });

        scheduler.Schedule(Seconds(30), [this](TaskContext context)
        {
            context.Repeat(Seconds(15), Minutes(1));
            Talk({ 1, 3, 4, 5, 8, 9, 10 });
        });
    }

    void SpellFinishCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case SpellSlam:
        {
            auto atRight = me->GetAreaObject(SpellSlamATRight);
            auto atLeft = me->GetAreaObject(SpellSlamATLeft);
            if (!atRight || !atLeft)
                return;

            auto callback = [=](AreaTrigger* at) -> void
            {
                for (auto playerGuid : *at->GetAffectedPlayers())
                    if (auto const& player = ObjectAccessor::GetPlayer(*me, playerGuid))
                        me->CastSpell(player, SpellSlamTriggerOnCircles, true);
            };

            if (!atRight->GetAffectedPlayers()->empty() && !atLeft->GetAffectedPlayers()->empty())
            {
                callback(atRight);
                callback(atLeft);
                DoCast(SpellSlamTriggerAOE);
            }
            else
                me->CastSpell(me->GetPosition(), SpellSlamSmash, true);

            ++SlamCounter;
            auto platformID = std::vector<uint8>{ DATA_KROSUS_PLATFORM1, DATA_KROSUS_PLATFORM2, DATA_KROSUS_PLATFORM3, DATA_KROSUS_PLATFORM4 }[PlatformID];

            switch (SlamCounter)
            {
            case 2:
                if (auto platform = instance->GetGameObject(platformID))
                    platform->SetDestructibleState(GO_DESTRUCTIBLE_DAMAGED);
                break;
            case 3:
                scheduler.DelayGroup(2, Seconds(10));
                if (auto platform = instance->GetGameObject(platformID))
                    platform->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);
                me->GetMotionMaster()->MovePoint(PlatformID, movementPositions[PlatformID], false);

                SlamCounter = 0;
                ++PlatformID;
                if (PlatformID == 4)
                    instance->instance->ApplyOnEveryPlayer([&](Player* player)
                {
                    player->CastSpell(player, 27965, true);
                });
                break;
            default:
                break;
            }
            break;
        }
        case SpellBurningPitchPrecast:
        {
            for (auto const& pos : PointList)
                me->CastSpell(pos, Trinity::Containers::SelectRandomContainerElement(std::vector<uint32>{SpellBurningPitchVisual, SpellBurningPitchVisual2}), true);

            if (IsMythicRaid())
            {
                scheduler.Schedule(Seconds(5), [this](TaskContext context)
                {
                    std::list<Creature*> creatureList;
                    me->GetCreatureListWithEntryInGrid(creatureList, 104262, 150.0f);
                    if (!creatureList.empty())
                    {
                        context.Repeat(Seconds(10));
                        Trinity::Containers::RandomResizeList(creatureList, 2);

                        for (auto const& creature : creatureList)
                            me->AddAura(SpellAccelerate, creature);
                    }
                });
            }
            break;
        }
        case SpellFelBeam:
        {
            std::list<Creature*> creatureList;
            me->GetCreatureListWithEntryInGrid(creatureList, 103725, 150.0f);
            for (auto const& creature : creatureList)
            {
                if (!FelBeamRight && creature->GetPositionX() < -110.f)
                    creature->AI()->DoAction(1);
                if (FelBeamRight && creature->GetPositionX() > -110.f)
                    creature->AI()->DoAction(2);
            }

            FelBeamRight = FelBeamRight ? 0 : 1;
            break;
        }
        default:
            break;
        }
    }

    void KilledUnit(Unit* who) override
    {
        if (who->IsPlayer())
            Talk({ 3, 4, 6 });
    }

    void Reset() override
    {
        _Reset();
        SetFlyMode(true);
        me->SetHover(true);
        me->SetReactState(REACT_DEFENSIVE);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 0);
        me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);
        me->AddUnitState(UNIT_STATE_ROTATING);

        SlamCounter = 0;
        PlatformID = 0;
        FelBeamRight = urand(0, 1);
        PlayersCount = 0;

        if (sGameEventMgr->IsActiveEvent(2))
            DoCast(SPELL_CHRISTMAS_CAP);
        else
        {
            if (me->HasAura(SPELL_CHRISTMAS_CAP))
                me->RemoveAura(SPELL_CHRISTMAS_CAP);
        }
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        Talk(0);
        me->SetFlag(UNIT_FIELD_FLAGS_2, 0);

        PlayersCount = std::max(me->GetMap()->GetPlayersCountExceptGMs(), 10u);

        if (IsMythicRaid())
            PlayersCount = 25;
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(11);

        me->SetLootRecipient(nullptr);
        me->DespawnOrUnsummon(500);
    }

    void EnterEvadeMode() override
    {
        for (auto platformID : std::vector<uint8>{ DATA_KROSUS_PLATFORM1, DATA_KROSUS_PLATFORM2, DATA_KROSUS_PLATFORM3, DATA_KROSUS_PLATFORM4 })
            if (auto platform = instance->GetGameObject(platformID))
                platform->SetDestructibleState(GO_DESTRUCTIBLE_REBUILDING);

        me->NearTeleportTo(me->GetHomePosition());
        _DespawnAtEvade(Seconds(15));
        BossAI::EnterEvadeMode();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || me->getVictim())
            return;

        if (me->IsValidAttackTarget(who) && me->IsWithinDistInMap(who, me->GetAttackDistance(who)))
            AttackStart(who);
    }

    void UpdateAI(uint32 diff) override
    {
        if (UpdateVictim())
            scheduler.Update(diff, std::bind(&BossAI::DoMeleeAttackIfReady, this, SPELL_SCHOOL_MASK_NORMAL));
    }

    std::vector<uint8> FelBeamTimers = std::vector<uint8>();
    std::vector<uint8> OrbOfDestructionTimers = std::vector<uint8>();
    std::vector<uint8> BurningPitchTimerss = std::vector<uint8>();
    std::vector<Position> PointList = std::vector<Position>();
    uint8 SlamCounter{};
    uint8 PlatformID{};
    uint8 FelBeamRight{};
    uint8 PowerTick{};
    uint8 PlayersCount{};
};

// 104262
struct npc_krosus_burning_ember : ScriptedAI
{
    explicit npc_krosus_burning_ember(Creature* creature) : ScriptedAI(creature)
    {
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL); // hack btw

        scheduler.SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        });
    }

    void Reset() override
    {
        scheduler.CancelAll();

        me->SetPower(POWER_ENERGY, 0);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);
    }

    void SetPower(Powers power, int32 value) override
    {
        if (power != POWER_ENERGY || !me->HasAura(SpellAccelerate))
            return;

        if (value == 100)
        {
            me->CastStop();
            scheduler.DelayAll(Seconds(1));
            DoCastAOE(SpellBurnout);
        }
    }

    void SpellFinishCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case SpellBurnout:
            scheduler.CancelAll();
            me->CastStop();
            me->DespawnOrUnsummon(100);
            break;
        default:
            break;
        }
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        scheduler
            .Schedule(Seconds(2), [this](TaskContext context)
        {
            context.Repeat();

            if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.f, true))
                DoCast(target, IsHeroicPlusRaid() ? SpellFelBlust : SpellFelBlast);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        if (UpdateVictim())
            scheduler.Update(diff);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(100);
    }

    void EnterEvadeMode() override
    {
        me->DespawnOrUnsummon(100);
    }

private:
    TaskScheduler scheduler;
};

// 103725
struct npc_krosus_fel_beam_caster : ScriptedAI
{
    explicit npc_krosus_fel_beam_caster(Creature* creature) : ScriptedAI(creature) { }

    void DoAction(int32 const actionID) override
    {
        switch (actionID)
        {
        case 1:
            if (me->GetPositionX() < -110.f)
                me->CastSpell(me, SpellFelBeamDamage, true);
            break;
        case 2:
            if (me->GetPositionX() > -110.f)
                me->CastSpell(me, SpellFelBeamDamage, true);
            break;
        default:
            break;
        }
    }
};

// 205348
class spell_krosus_orb_of_destruction_dmg : public SpellScript
{
    PrepareSpellScript(spell_krosus_orb_of_destruction_dmg);

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        auto caster = GetCaster();
        auto target = GetHitUnit();
        if (!caster || !target)
            return;

        auto distance = caster->GetExactDist2d(target) * 1.5f;
        auto pctModifier = 1u;
        if (distance < 100.0f)
            pctModifier = 100 - distance;

        SetHitDamage(CalculatePct(GetHitDamage(), pctModifier));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_krosus_orb_of_destruction_dmg::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 206280
class spell_krosus_burning_pitch : public SpellScript
{
    PrepareSpellScript(spell_krosus_burning_pitch);

    void TargetsList(std::list<WorldObject*>& targets)
    {
        if (!GetCaster())
            return;

        if (targets.empty())
        {
            if (auto loc = GetExplTargetDest())
                GetCaster()->CastSpell(loc, SpellBurningPitchSummon, true);
        }
    }

    void HandleDummy(SpellEffIndex /*effectIndex*/)
    {
        if (GetCaster() && GetHitUnit())
        {
            GetCaster()->CastSpell(GetHitUnit(), SpellBurningPitchDamage, true);

            //if (GetCaster()->GetMap()->IsMythicRaid())
            //    GetCaster()->CastSpell(GetHitUnit(), SpellBurningPitchModDamage, true);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_krosus_burning_pitch::TargetsList, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_krosus_burning_pitch::HandleDummy, SpellEffIndex::EFFECT_0, SpellEffects::SPELL_EFFECT_DUMMY);
    }
};

//205391
class spell_krosus_fel_beam : public SpellScript
{
    PrepareSpellScript(spell_krosus_fel_beam);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        std::list<WorldObject*> tempTargets;
        Position casterPos = GetCaster()->GetPosition();
        std::vector<Position> line;
        line.push_back(lineBeamPos[0]);
        line.push_back(lineBeamPos[1]);
        for (auto const& target : targets)
            if (casterPos.IsPointInBox(casterPos, line, target->GetPosition()))
                tempTargets.push_back(target);

        targets.clear();
        targets = tempTargets;
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_krosus_fel_beam::FilterTargets, EFFECT_0, TARGET_UNIT_ENEMY_BETWEEN_DEST2);
    }
};

void AddSC_boss_krosus()
{
    RegisterCreatureAI(boss_krosus);
    RegisterCreatureAI(npc_krosus_burning_ember);
    RegisterCreatureAI(npc_krosus_fel_beam_caster);
    RegisterSpellScript(spell_krosus_orb_of_destruction_dmg);
    RegisterSpellScript(spell_krosus_burning_pitch);
    RegisterSpellScript(spell_krosus_fel_beam);
}
