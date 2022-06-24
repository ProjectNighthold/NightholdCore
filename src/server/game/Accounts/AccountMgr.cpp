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

#include "AccountMgr.h"
#include "DatabaseEnv.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Util.h"
#include "SHA1.h"

namespace AccountMgr
{

AccountOpResult CreateAccount(std::string username, std::string password)
{
    if (utf8length(username) > MAX_ACCOUNT_STR)
        return AccountOpResult::AOR_NAME_TOO_LONG;          // username's too long

    Utf8ToUpperOnlyLatin(username);
    Utf8ToUpperOnlyLatin(password);

    if (GetId(username))
        return AccountOpResult::AOR_NAME_ALREADY_EXIST;     // username does already exist

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_ACCOUNT);

    stmt->setString(0, username);
    stmt->setString(1, CalculateShaPassHash(username, password));

    LoginDatabase.Execute(stmt);

    //stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_REALM_CHARACTERS_INIT);

    //LoginDatabase.Execute(stmt);

    return AccountOpResult::AOR_OK;                         // everything's fine
}

AccountOpResult DeleteAccount(uint32 accountId)
{
    // Check if accounts exists
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_BY_ID);
    stmt->setUInt32(0, accountId);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    if (!result)
        return AccountOpResult::AOR_NAME_NOT_EXIST;

    // Obtain accounts characters
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARS_BY_ACCOUNT_ID);

    stmt->setUInt32(0, accountId);

    result = CharacterDatabase.Query(stmt);

    if (result)
    {
        do
        {
            ObjectGuid guid = ObjectGuid::Create<HighGuid::Player>((*result)[0].GetUInt32());

            // Kick if player is online
            if (Player* p = ObjectAccessor::FindPlayer(guid))
            {
                WorldSession* s = p->GetSession();
                s->KickPlayer();                            // mark session to remove at next session list update
                s->LogoutPlayer(false);                     // logout player without waiting next session list update
            }

            Player::DeleteFromDB(guid, accountId, false);       // no need to update realm characters
        } while (result->NextRow());
    }

    // table realm specific but common for all characters of account for realm
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_TUTORIALS);
    stmt->setUInt32(0, accountId);
    CharacterDatabase.Execute(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ACCOUNT_DATA);
    stmt->setUInt32(0, accountId);
    CharacterDatabase.Execute(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_BAN);
    stmt->setUInt32(0, accountId);
    CharacterDatabase.Execute(stmt);

    SQLTransaction trans = LoginDatabase.BeginTransaction();

    stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_ACCOUNT);
    stmt->setUInt32(0, accountId);
    trans->Append(stmt);

    stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_ACCOUNT_ACCESS);
    stmt->setUInt32(0, accountId);
    trans->Append(stmt);

    stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_REALM_CHARACTERS);
    stmt->setUInt32(0, accountId);
    trans->Append(stmt);

    stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_ACCOUNT_BANNED);
    stmt->setUInt32(0, accountId);
    trans->Append(stmt);

    LoginDatabase.CommitTransaction(trans);

    return AccountOpResult::AOR_OK;
}

AccountOpResult ChangeUsername(uint32 accountId, std::string newUsername, std::string newPassword)
{
    // Check if accounts exists
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_BY_ID);
    stmt->setUInt32(0, accountId);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    if (!result)
        return AccountOpResult::AOR_NAME_NOT_EXIST;

    if (utf8length(newUsername) > MAX_ACCOUNT_STR)
        return AccountOpResult::AOR_NAME_TOO_LONG;

    if (utf8length(newPassword) > MAX_ACCOUNT_STR)
        return AccountOpResult::AOR_PASS_TOO_LONG;

    Utf8ToUpperOnlyLatin(newUsername);
    Utf8ToUpperOnlyLatin(newPassword);

    stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_USERNAME);

    stmt->setString(0, newUsername);
    stmt->setString(1, CalculateShaPassHash(newUsername, newPassword));
    stmt->setUInt32(2, accountId);

    LoginDatabase.Execute(stmt);

    return AccountOpResult::AOR_OK;
}

AccountOpResult ChangePassword(uint32 accountId, std::string newPassword)
{
    std::string username;

    if (!GetName(accountId, username))
        return AccountOpResult::AOR_NAME_NOT_EXIST;     // account doesn't exist

    if (utf8length(newPassword) > MAX_ACCOUNT_STR)
        return AccountOpResult::AOR_PASS_TOO_LONG;

    Utf8ToUpperOnlyLatin(username);
    Utf8ToUpperOnlyLatin(newPassword);

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_PASSWORD);

    stmt->setString(0, CalculateShaPassHash(username, newPassword));
    stmt->setUInt32(1, accountId);

    LoginDatabase.Execute(stmt);

    return AccountOpResult::AOR_OK;
}

uint32 GetId(std::string username)
{
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_ACCOUNT_ID_BY_USERNAME);
    stmt->setString(0, username);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    return (result) ? (*result)[0].GetUInt32() : 0;
}

uint32 GetSecurity(uint32 accountId)
{
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_ACCOUNT_ACCESS_GMLEVEL);
    stmt->setUInt32(0, accountId);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    return result ? (*result)[0].GetUInt8() : uint32(SEC_PLAYER);
}

uint32 GetSecurity(uint32 accountId, int32 realmId)
{
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_GMLEVEL_BY_REALMID);
    stmt->setUInt32(0, accountId);
    stmt->setInt32(1, realmId);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    return result ? (*result)[0].GetUInt8() : uint32(SEC_PLAYER);
}

bool GetName(uint32 accountId, std::string& name)
{
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_USERNAME_BY_ID);
    stmt->setUInt32(0, accountId);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    if (result)
    {
        name = (*result)[0].GetString();
        return true;
    }

    return false;
}

bool CheckPassword(uint32 accountId, std::string password)
{
    std::string username;

    if (!GetName(accountId, username))
        return false;

    Utf8ToUpperOnlyLatin(username);
    Utf8ToUpperOnlyLatin(password);

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_CHECK_PASSWORD);
    stmt->setUInt32(0, accountId);
    stmt->setString(1, CalculateShaPassHash(username, password));
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    return result ? true : false;
}

uint32 GetCharactersCount(uint32 accountId)
{
    // check character count
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_SUM_CHARS);
    stmt->setUInt32(0, accountId);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    return result ? (*result)[0].GetUInt64() : 0;
}

std::string CalculateShaPassHash(std::string& name, std::string& password)
{
    SHA1Hash sha;
    sha.Initialize();
    sha.UpdateData(name);
    sha.UpdateData(":");
    sha.UpdateData(password);
    sha.Finalize();

    return ByteArrayToHexStr(sha.GetDigest(), sha.GetLength());
}

bool IsPlayerAccount(uint32 gmlevel)
{
    return gmlevel == SEC_PLAYER;
}

bool IsDonorAccount(uint32 gmlevel) {
	return gmlevel >= SEC_DONOR && gmlevel <= SEC_BUGTRACKER;
}

bool IsBugTrackerAccount(uint32 gmlevel) {
	return gmlevel >= SEC_BUGTRACKER && gmlevel <= SEC_MODERATOR;
}

bool IsModeratorAccount(uint32 gmlevel)
{
    return gmlevel >= SEC_MODERATOR && gmlevel <= SEC_TRAIL_GM;
}

bool IsTrailGMAccount(uint32 gmlevel) {
	return gmlevel >= SEC_TRAIL_GM && gmlevel <= SEC_GAMEMASTER;
}

bool IsGMAccount(uint32 gmlevel)
{
    return gmlevel >= SEC_GAMEMASTER && gmlevel <= SEC_ADMINISTRATOR;
}

bool IsAdminAccount(uint32 gmlevel)
{
    return gmlevel >= SEC_ADMINISTRATOR && gmlevel <= SEC_DEVELOPER;
}

bool IsDevAccount(uint32 gmlevel) {
	return gmlevel >= SEC_DEVELOPER && gmlevel <= SEC_CONSOLE;
}

bool IsConsoleAccount(uint32 gmlevel)
{
    return gmlevel == SEC_CONSOLE;
}

} // Namespace AccountMgr
