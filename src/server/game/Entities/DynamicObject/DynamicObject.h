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

#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

#include "Object.h"
#include "GridObject.h"
#include "MapObject.h"

class Unit;
class Aura;
class SpellInfo;

enum DynamicObjectType
{
    DYNAMIC_OBJECT_PORTAL           = 0x0,      // unused
    DYNAMIC_OBJECT_AREA_SPELL       = 0x1,
    DYNAMIC_OBJECT_FARSIGHT_FOCUS   = 0x2,
};

class DynamicObject : public WorldObject, public GridObject<DynamicObject>, public MapObject
{
    public:
        DynamicObject(bool isWorldObject);
        ~DynamicObject();

        void BuildValuesUpdate(uint8 updatetype, ByteBuffer* data, Player* target) const override;

        void AddToWorld() override;
        void RemoveFromWorld() override;

        bool CreateDynamicObject(ObjectGuid::LowType guidlow, Unit* caster, uint32 spellId, Position const& pos, float radius, DynamicObjectType type);
        void Update(uint32 p_time) override;
        void Remove();
        void SetDuration(int32 newDuration);
        int32 GetDuration() const;
        void Delay(int32 delaytime);
        void SetAura(Aura* aura);
        void RemoveAura();
        void SetCasterViewpoint();
        void RemoveCasterViewpoint();
        Unit* GetCaster() const { return _caster; }
        void BindToCaster();
        void UnbindFromCaster();
        uint32 GetSpellId() const {  return GetUInt32Value(DYNAMICOBJECT_FIELD_SPELL_ID); }
        ObjectGuid GetCasterGUID() const { return GetGuidValue(DYNAMICOBJECT_FIELD_CASTER); }
        float GetRadius() const { return GetFloatValue(DYNAMICOBJECT_FIELD_RADIUS); }
        DynamicObjectType GetType() const { return DynamicObjectType(GetUInt32Value(DYNAMICOBJECT_FIELD_TYPE)); }
        uint32 GetVisualId() const { return GetUInt32Value(DYNAMICOBJECT_FIELD_SPELL_XSPELL_VISUAL_ID); }

        void Say(int32 textId, uint32 language, ObjectGuid targetGuid) { MonsterSay(textId, language, targetGuid); }
        void Yell(int32 textId, uint32 language, ObjectGuid targetGuid) { MonsterYell(textId, language, targetGuid); }
        void TextEmote(int32 textId, ObjectGuid targetGuid) { MonsterTextEmote(textId, targetGuid); }
        void Whisper(int32 textId, ObjectGuid receiver) { MonsterWhisper(textId, receiver); }
        void YellToZone(int32 textId, uint32 language, ObjectGuid targetGuid) { MonsterYellToZone(textId, language, targetGuid); }

    protected:
        Aura* _aura;
        Aura* _removedAura;
        Unit* _caster;
        int32 _duration; // for non-aura dynobjects
        bool _isViewpoint;
};
#endif
