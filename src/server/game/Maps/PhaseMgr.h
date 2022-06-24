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

#ifndef TRINITY_PHASEMGR_H
#define TRINITY_PHASEMGR_H

#include "SpellAuras.h"
#include "ConditionMgr.h"
#include <safe_ptr.h>

class ObjectMgr;
class Player;

// Phasing (visibility)
enum PhasingFlags
{
    PHASE_FLAG_OVERWRITE_EXISTING           = 0x01,       // don't stack with existing phases, overwrites existing phases
    PHASE_FLAG_NO_MORE_PHASES               = 0x02,       // stop calculating phases after this phase was applied (no more phases will be applied)
    PHASE_FLAG_NEGATE_PHASE                 = 0x04        // negate instead to add the phasemask
};

enum PhaseUpdateFlag
{
    PHASE_UPDATE_FLAG_ZONE_UPDATE           = 0x01,
    PHASE_UPDATE_FLAG_AREA_UPDATE           = 0x02,

    // Internal flags
    PHASE_UPDATE_FLAG_CLIENTSIDE_CHANGED    = 0x08,
    PHASE_UPDATE_FLAG_SERVERSIDE_CHANGED    = 0x10,
};

struct PhaseDefinition
{
    std::list<uint16> phaseId;
    uint32 zoneId;
    uint32 entry;
    uint32 phasemask;
    uint16 terrainswapmap;
    uint16 wmAreaId;
    uint16 uiWmAreaId;
    uint8 flags;

    bool IsOverwritingExistingPhases() const { return flags & PHASE_FLAG_OVERWRITE_EXISTING; }
    bool IsLastDefinition() const { return flags & PHASE_FLAG_NO_MORE_PHASES; }
    bool IsNegatingPhasemask() const { return flags & PHASE_FLAG_NEGATE_PHASE; }
};

typedef std::list<PhaseDefinition> PhaseDefinitionContainer;
typedef std::unordered_map<uint32 /*zoneId*/, PhaseDefinitionContainer> PhaseDefinitionStore;

struct SpellPhaseInfo
{
    uint32 spellId;
    uint32 phasemask;
    uint32 terrainswapmap;
    uint32 phaseId;
};

typedef std::unordered_map<uint32 /*spellId*/, SpellPhaseInfo> SpellPhaseStore;

struct PhaseInfo
{
    PhaseInfo() : phasemask(0), terrainswapmap(0), phaseId(0) {}

    uint32 phasemask;
    uint32 terrainswapmap;
    uint32 phaseId;

    bool NeedsServerSideUpdate() const { return phasemask || phaseId; }
    bool NeedsClientSideUpdate() const { return terrainswapmap || phaseId; }
};

typedef std::unordered_map<uint32 /*spellId*/, PhaseInfo> PhaseInfoContainer;

struct PhaseData
{
    PhaseData(Player* _player) : _PhasemaskThroughDefinitions(0), _PhasemaskThroughAuras(0), _CustomPhasemask(0), player(_player) {}

    uint32 _PhasemaskThroughDefinitions;
    uint32 _PhasemaskThroughAuras;
    uint32 _CustomPhasemask;

    uint32 GetCurrentPhasemask() const;
    inline uint32 GetPhaseMaskForSpawn() const;

    void ResetDefinitions() { _PhasemaskThroughDefinitions = 0; activePhaseDefinitions.clear(); }
    void AddPhaseDefinition(PhaseDefinition const* phaseDefinition);
    bool HasActiveDefinitions() const { return !activePhaseDefinitions.empty(); }

    void AddAuraInfo(uint32 const spellId, PhaseInfo phaseInfo);
    uint32 RemoveAuraInfo(uint32 const spellId);

    void SendPhaseMaskToPlayer();
    void SendPhaseshiftToPlayer();

    std::list<PhaseDefinition const*> activePhaseDefinitions;
    PhaseInfoContainer spellPhaseInfo;
private:
    Player* player;
};

struct PhaseUpdateData
{
    void AddConditionType(ConditionTypes const conditionType) { _conditionTypeFlags |= uint64(1ULL << uint64(conditionType)); }
    void AddQuestUpdate(uint32 const questId);
    void AddScenarioUpdate(uint32 step);

    bool IsConditionRelated(Condition const* condition) const;

private:
    uint64 _conditionTypeFlags = 0;
    uint32 _questId = 0;
};

class PhaseMgr
{
public:
    PhaseMgr(Player* _player);
    ~PhaseMgr() {}

    uint32 GetCurrentPhasemask() { return phaseData.GetCurrentPhasemask(); };

    uint32 GetPhaseMaskForSpawn() { return phaseData.GetCurrentPhasemask(); }

    // Phase definitions update handling
    void NotifyConditionChanged(PhaseUpdateData const& updateData);
    void NotifyStoresReloaded() { Recalculate(); Update(); }

    void Update();

    // Aura phase effects
    void RegisterPhasingAuraEffect(AuraEffect const* auraEffect);
    void UnRegisterPhasingAuraEffect(AuraEffect const* auraEffect);

    // Aura phase
    void RegisterPhasingAura(uint32 spellId, Unit* target);
    void UnRegisterPhasingAura(uint32 spellId, Unit* target);

    // Update flags (delayed phasing)
    void AddUpdateFlag(PhaseUpdateFlag const updateFlag) { _UpdateFlags |= updateFlag; }
    void RemoveUpdateFlag(PhaseUpdateFlag const updateFlag);

    // Needed for modify phase command
    void SetCustomPhase(uint32 const phaseMask);

    // Debug
    void SendDebugReportToPlayer(Player* const debugger);

    static bool IsConditionTypeSupported(ConditionTypes const conditionType);

    std::string GetPhaseIdString();
    void Recalculate();
private:

    inline bool CheckDefinition(PhaseDefinition const* phaseDefinition);

    bool NeedsPhaseUpdateWithData(PhaseUpdateData const updateData) const;

    bool IsUpdateInProgress() const { return (_UpdateFlags & PHASE_UPDATE_FLAG_ZONE_UPDATE) || (_UpdateFlags & PHASE_UPDATE_FLAG_AREA_UPDATE); }

    PhaseDefinitionStore const* _PhaseDefinitionStore;
    SpellPhaseStore const* _SpellPhaseStore;

    sf::contention_free_shared_mutex< >  _updateLock;

    Player* player;
    PhaseData phaseData;
    uint8 _UpdateFlags;
};

#endif