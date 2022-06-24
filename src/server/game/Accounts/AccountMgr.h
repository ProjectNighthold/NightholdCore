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

#ifndef _ACCMGR_H
#define _ACCMGR_H

#include <string>
#include "Define.h"

enum class AccountOpResult : uint8
{
    AOR_OK,
    AOR_NAME_TOO_LONG,
    AOR_PASS_TOO_LONG,
    AOR_EMAIL_TOO_LONG,
    AOR_NAME_ALREADY_EXIST,
    AOR_NAME_NOT_EXIST,
    AOR_DB_INTERNAL_ERROR,
};

#define MAX_PASS_STR 32
#define MAX_ACCOUNT_STR 32
#define MAX_EMAIL_STR 64

namespace AccountMgr
{
    AccountOpResult CreateAccount(std::string username, std::string password);
    AccountOpResult DeleteAccount(uint32 accountId);
    AccountOpResult ChangeUsername(uint32 accountId, std::string newUsername, std::string newPassword);
    AccountOpResult ChangePassword(uint32 accountId, std::string newPassword);
    bool CheckPassword(uint32 accountId, std::string password);

    uint32 GetId(std::string username);
    uint32 GetSecurity(uint32 accountId);
    uint32 GetSecurity(uint32 accountId, int32 realmId);
    bool GetName(uint32 accountId, std::string& name);
    uint32 GetCharactersCount(uint32 accountId);
    std::string CalculateShaPassHash(std::string& name, std::string& password);

    bool IsPlayerAccount(uint32 gmlevel);
	bool IsDonorAccount(uint32 gmlevel);
	bool IsBugTrackerAccount(uint32 gmlevel);
    bool IsModeratorAccount(uint32 gmlevel);
	bool IsTrailGMAccount(uint32 gmlevel);
    bool IsGMAccount(uint32 gmlevel);
    bool IsAdminAccount(uint32 gmlevel);
	bool IsDevAccount(uint32 gmlevel);
    bool IsConsoleAccount(uint32 gmlevel);
};

#endif
