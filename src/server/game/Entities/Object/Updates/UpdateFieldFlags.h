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

#ifndef _UPDATEFIELDFLAGS_H
#define _UPDATEFIELDFLAGS_H

#include "UpdateFields.h"

enum UpdatefieldFlags
{
    UF_FLAG_NONE                = 0x000,
    UF_FLAG_PUBLIC              = 0x001, // MIRROR_ALL
    UF_FLAG_PRIVATE             = 0x002, // MIRROR_SELF
    UF_FLAG_OWNER               = 0x004, // MIRROR_OWNER
    UF_FLAG_ITEM_OWNER          = 0x008,
    UF_FLAG_SPECIAL_INFO        = 0x010, // MIRROR_EMPATH
    UF_FLAG_PARTY_MEMBER        = 0x020, // MIRROR_PARTY
    UF_FLAG_UNIT_ALL            = 0x040, // MIRROR_UNIT_ALL
    UF_FLAG_DYNAMIC             = 0x080, // MIRROR_VIEWER_DEPENDENT
    UF_FLAG_UNK0X100            = 0x100,
    UF_FLAG_URGENT              = 0x200, // MIRROR_URGENT
    UF_FLAG_URGENT_SELF_ONLY    = 0x400, // MIRROR_URGENT_SELF_ONLY
};

extern uint32 ItemUpdateFieldFlags[CONTAINER_END];
extern uint32 UnitUpdateFieldFlags[PLAYER_FIELD_END];
extern uint32 GameObjectUpdateFieldFlags[GAMEOBJECT_END];
extern uint32 DynamicObjectUpdateFieldFlags[DYNAMIC_OBJECT_END];
extern uint32 CorpseUpdateFieldFlags[CORPSE_END];
extern uint32 AreaTriggerUpdateFieldFlags[AREA_TRIGGER_END];
extern uint32 SceneObjectUpdateFieldFlags[SCENEOBJECT_END];
extern uint32 ConversationUpdateFieldFlags[CONVERSATION_END];

extern uint32 UnitDynamicFieldFlags[PLAYER_DYNAMIC_END];
extern uint32 ItemDynamicFieldFlags[ITEM_DYNAMIC_END];
extern uint32 ConversationDynamicFieldFlags[CONVERSATION_DYNAMIC_END];
extern uint32 GameObjectDynamicUpdateFieldFlags[GAMEOBJECT_DYNAMIC_END];

#endif // _UPDATEFIELDFLAGS_H
