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

#ifndef __TRINITY_REPUTATION_MGR_H
#define __TRINITY_REPUTATION_MGR_H

#include "Common.h"
#include "SharedDefines.h"
#include "Language.h"
#include "DatabaseEnvFwd.h"

static uint32 ReputationRankStrIndex[MAX_REPUTATION_RANK] =
{
    LANG_REP_HATED,    LANG_REP_HOSTILE, LANG_REP_UNFRIENDLY, LANG_REP_NEUTRAL,
    LANG_REP_FRIENDLY, LANG_REP_HONORED, LANG_REP_REVERED,    LANG_REP_EXALTED
};

enum FactionFlags
{
    FACTION_FLAG_NONE               = 0x00,                 // no faction flag
    FACTION_FLAG_VISIBLE            = 0x01,                 // makes visible in client (set or can be set at interaction with target of this faction)
    FACTION_FLAG_AT_WAR             = 0x02,                 // enable AtWar-button in client. player controlled (except opposition team always war state), Flag only set on initial creation
    FACTION_FLAG_HIDDEN             = 0x04,                 // hidden faction from reputation pane in client (player can gain reputation, but this update not sent to client)
    FACTION_FLAG_INVISIBLE_FORCED   = 0x08,                 // always overwrite FACTION_FLAG_VISIBLE and hide faction in rep.list, used for hide opposite team factions
    FACTION_FLAG_PEACE_FORCED       = 0x10,                 // always overwrite FACTION_FLAG_AT_WAR, used for prevent war with own team factions
    FACTION_FLAG_INACTIVE           = 0x20,                 // player controlled, state stored in characters.data (CMSG_SET_FACTION_INACTIVE)
    FACTION_FLAG_RIVAL              = 0x40,                 // flag for the two competing outland factions
    FACTION_FLAG_SPECIAL            = 0x80                  // horde and alliance home cities and their northrend allies have this flag
};

typedef int32 RepListID;
struct FactionState
{
    uint32 ID;
    RepListID ReputationListID;
    int32 Standing;
    uint8 Flags;
    bool init = false;
    bool notInDB = true;
    bool needSend = false;
    bool needSave = false;
    bool needUpdateStanding = false;
    bool needUpdateFlags = false;
};

typedef std::vector<FactionState> FactionStateList;
typedef std::map<uint32, ReputationRank> ForcedReactions;

class Player;

class ReputationMgr
{
    public:                                                 // constructors and global modifiers
        explicit ReputationMgr(Player* owner);

        ~ReputationMgr() {}

        void Clear();
        uint32 GetSize();

        void SaveToDB(SQLTransaction& trans);
        void LoadFromDB(PreparedQueryResult result);

        static ReputationRank GetReactionLevel(int32 standing);

        uint8 GetVisibleFactionCount() const;
        uint8 GetHonoredFactionCount() const;
        uint8 GetReveredFactionCount() const;
        uint8 GetExaltedFactionCount() const;

        FactionStateList const& GetStateList() const;
        FactionState const* GetState(FactionEntry const* factionEntry) const;
        FactionState const* GetState(RepListID id) const;
        FactionState* GetState(RepListID id);

        bool IsAtWar(uint32 faction_id) const;
        bool IsAtWar(FactionEntry const* factionEntry) const;

        int32 GetReputation(uint32 faction_id) const;
        int32 GetReputation(FactionEntry const* factionEntry) const;
        int32 GetBaseReputation(FactionEntry const* factionEntry) const;

        ReputationRank GetRank(FactionEntry const* factionEntry) const;
        ReputationRank GetBaseRank(FactionEntry const* factionEntry) const;
        uint32 GetReputationRankStrIndex(FactionEntry const* factionEntry) const;
        ReputationRank const* GetForcedRankIfAny(uint32 factionId) const;
        ReputationRank const* GetForcedRankIfAny(FactionTemplateEntry const* factionTemplateEntry) const;

        bool SetReputation(FactionEntry const* factionEntry, int32 standing);
        bool ModifyReputation(FactionEntry const* factionEntry, int32 standing, bool noSpillover = false);
        void ModifyParagonReputation(FactionEntry const* factionEntry, int32 standing);

        void SetVisible(FactionTemplateEntry const* factionTemplateEntry);
        void SetVisible(FactionEntry const* factionEntry);
        void SetAtWar(RepListID repListID, bool on);
        void SetInactive(RepListID repListID, bool on);

        void ApplyForceReaction(uint32 faction_id, ReputationRank rank, bool apply);

        //! Public for chat command needs
        bool SetOneFactionReputation(FactionEntry const* factionEntry, int32 standing, bool incremental, bool paragon);

        void SendInitialReputations();
        void SendForceReactions();
        void SendState(FactionState const* faction);
        void SendStates();
        bool IsVisible(RepListID repListID) const;

    private:                                                // internal helper functions
        void Initialize();
        uint32 GetDefaultStateFlags(FactionEntry const* factionEntry) const;
        bool SetReputation(FactionEntry const* factionEntry, int32 standing, bool incremental, bool noSpillover);
        void SetVisible(FactionState* faction);
        void SetAtWar(FactionState* faction, bool atWar) const;
        void SetInactive(FactionState* faction, bool inactive) const;
        void SendVisible(FactionState const* faction, bool visible = true) const;
        void UpdateRankCounters(ReputationRank old_rank, ReputationRank new_rank);

        Player* _player;
        FactionStateList _factions;
        ForcedReactions _forcedReactions;
        uint8 _visibleFactionCount :8;
        uint8 _honoredFactionCount :8;
        uint8 _reveredFactionCount :8;
        uint8 _exaltedFactionCount :8;
        bool _sendFactionIncreased; //! Play visual effect on next SMSG_SET_FACTION_STANDING sent
};

#endif
