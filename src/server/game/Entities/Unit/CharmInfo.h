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

#ifndef ChramInfo_h__
#define ChramInfo_h__

#include "ObjectGuid.h"

class Unit;
class SpellInfo;

enum CommandStates;
enum ActiveStates;

#define UNIT_ACTION_BUTTON_ACTION(X) (uint32(X) & 0x00FFFFFF)
#define UNIT_ACTION_BUTTON_TYPE(X)   ((uint32(X) & 0xFF000000) >> 24)
#define MAKE_UNIT_ACTION_BUTTON(A, T) (uint32(A) | (uint32(T) << 24))

struct UnitActionBarEntry
{
    UnitActionBarEntry();
    ActiveStates GetType() const;
    uint32 GetAction() const;
    bool IsActionBarForSpell() const;
    void SetActionAndType(uint32 action, ActiveStates type);
    void SetType(ActiveStates type);
    void SetAction(uint32 action);

    uint32 packedData;
};

typedef UnitActionBarEntry CharmSpellInfo;

enum ActionBarIndex
{
    ACTION_BAR_INDEX_START = 0,
    ACTION_BAR_INDEX_PET_SPELL_START = 3,
    ACTION_BAR_INDEX_PET_SPELL_END = 7,
    ACTION_BAR_INDEX_END = 10,
};

static uint32 constexpr MAX_UNIT_ACTION_BAR_INDEX = ACTION_BAR_INDEX_END - ACTION_BAR_INDEX_START;

struct CharmInfo
{
    explicit CharmInfo(Unit* unit);
    ~CharmInfo();
    void RestoreState();
    uint32 GetPetNumber() const;
    void SetPetNumber(uint32 petnumber, bool statwindow);
    void SetCommandState(CommandStates st);
    CommandStates GetCommandState() const;
    bool HasCommandState(CommandStates state) const;

    void InitPossessCreateSpells();
    void InitCharmCreateSpells();
    void InitPetActionBar();
    void InitEmptyActionBar(bool withAttack = true);

    bool AddSpellToActionBar(SpellInfo const* spellInfo, ActiveStates newstate = ACT_DECIDE);
    bool RemoveSpellFromActionBar(uint32 spell_id);
    void LoadPetActionBar(std::string const& data);
    void SetSpellAutocast(SpellInfo const* spellInfo, bool state);
    void SetActionBar(uint8 index, uint32 spellOrAction, ActiveStates type);
    UnitActionBarEntry const* GetActionBarEntry(uint8 index) const;
    void ToggleCreatureAutocast(SpellInfo const* spellInfo, bool apply);
    CharmSpellInfo* GetCharmSpell(uint8 index);

    void SetIsCommandAttack(bool val);
    bool IsCommandAttack();
    void SetIsAtStay(bool val);
    bool IsAtStay();
    void SetIsFollowing(bool val);
    bool IsFollowing();
    void SetIsReturning(bool val);
    bool IsReturning();
    void SaveStayPosition();
    void GetStayPosition(float &x, float &y, float &z);

    UnitActionBarEntry PetActionBar[MAX_UNIT_ACTION_BAR_INDEX];
private:
    Unit* m_unit;
    CharmSpellInfo m_charmspells[4];
    CommandStates m_CommandState;
    Position _stay;
    ReactStates m_oldReactState;
    uint32 m_petnumber;

    bool m_isCommandAttack;
    bool m_isAtStay;
    bool m_isFollowing;
    bool m_isReturning;
};

#endif // ChramInfo_h__
