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

#ifndef DB2Meta_h__
#define DB2Meta_h__

#include "Define.h"

struct DB2Meta
{
    DB2Meta(int32 indexField, uint32 fieldCount, uint32 layoutHash, char const* types, uint8 const* arraySizes, int32 parentIndexField);

    bool HasIndexFieldInData() const;
    uint32 GetIndexField() const;
    uint32 GetRecordSize() const;
    int32 GetParentIndexFieldOffset() const;
    uint32 GetDbIndexField() const;
    uint32 GetDbFieldCount() const;

    int32 IndexField;
    int32 ParentIndexField;
    uint32 FieldCount;
    uint32 LayoutHash;
    char const* Types;
    uint8 const* ArraySizes;
};

struct DB2FieldMeta
{
    DB2FieldMeta(bool isSigned, DBCFormer type, char const* name);

    bool IsSigned;
    DBCFormer Type;
    char const* Name;
};

#endif // DB2Meta_h__
