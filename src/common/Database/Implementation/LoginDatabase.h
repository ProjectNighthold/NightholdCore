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

#ifndef _LOGINDATABASE_H
#define _LOGINDATABASE_H

#include "DatabaseWorkerPool.h"
#include "MySQLConnection.h"

class LoginDatabaseConnection : public MySQLConnection
{
    public:
        //- Constructors for sync and async connections
        LoginDatabaseConnection(MySQLConnectionInfo& connInfo) : MySQLConnection(connInfo) { }
        LoginDatabaseConnection(ProducerConsumerQueue<SQLOperation*>* q, MySQLConnectionInfo& connInfo) : MySQLConnection(q, connInfo) { }

        //- Loads database type specific prepared statements
        void DoPrepareStatements();
};

typedef DatabaseWorkerPool<LoginDatabaseConnection> LoginDatabaseWorkerPool;

enum LoginDatabaseStatements
{
    /*  Naming standard for defines:
        {DB}_{SEL/INS/UPD/DEL/REP}_{Summary of data changed}
        When updating more than one field, consider looking at the calling function
        name for a suiting suffix.
    */

    LOGIN_SEL_REALMLIST,
    LOGIN_DEL_EXPIRED_IP_BANS,
    LOGIN_UPD_EXPIRED_ACCOUNT_BANS,
    LOGIN_SEL_IP_INFO,
    LOGIN_SEL_ACCOUNT_BANNED,
    LOGIN_SEL_ACCOUNT_BANNED_ALL,
    LOGIN_SEL_ACCOUNT_BANNED_BY_USERNAME,
    LOGIN_DEL_ACCOUNT_BANNED,
    LOGIN_SEL_ACCOUNT_ID_BY_NAME,
    LOGIN_SEL_ACCOUNT_LIST_BY_NAME,
    LOGIN_SEL_ACCOUNT_INFO_BY_NAME,
    LOGIN_SEL_ACCOUNT_LIST_BY_EMAIL,
    LOGIN_SEL_ACCOUNT_BY_IP,
    LOGIN_INS_IP_BANNED,
    LOGIN_DEL_IP_NOT_BANNED,
    LOGIN_SEL_IP_BANNED_ALL,
    LOGIN_SEL_IP_BANNED_BY_IP,
    LOGIN_SEL_ACCOUNT_BY_ID,
    LOGIN_INS_ACCOUNT_BANNED,
    LOGIN_UPD_ACCOUNT_BANNED,
    LOGIN_UPD_ACCOUNT_NOT_BANNED,
    LOGIN_DEL_REALM_CHARACTERS_BY_REALM,
    LOGIN_DEL_REALM_CHARACTERS,
    LOGIN_INS_REALM_CHARACTERS,
    LOGIN_SEL_SUM_REALM_CHARACTERS,
    LOGIN_INS_ACCOUNT,
    LOGIN_INS_REALM_CHARACTERS_INIT,
    LOGIN_UPD_EXPANSION,
    LOGIN_UPD_ACCOUNT_LOCK,
    LOGIN_INS_LOG,
    LOGIN_UPD_USERNAME,
    LOGIN_UPD_PASSWORD,
    LOGIN_UPD_MUTE_TIME,
    LOGIN_UPD_LAST_IP,
    LOGIN_UPD_ACCOUNT_ONLINE,
    LOGIN_UPD_UPTIME_PLAYERS,
    LOGIN_DEL_OLD_LOGS,
    LOGIN_DEL_ACCOUNT_ACCESS,
    LOGIN_DEL_ACCOUNT_ACCESS_BY_REALM,
    LOGIN_INS_ACCOUNT_ACCESS,
    LOGIN_GET_ACCOUNT_ID_BY_USERNAME,
    LOGIN_GET_ACCOUNT_ACCESS_GMLEVEL,
    LOGIN_GET_GMLEVEL_BY_REALMID,
    LOGIN_GET_USERNAME_BY_ID,
    LOGIN_SEL_CHECK_PASSWORD,
    LOGIN_SEL_CHECK_PASSWORD_BY_NAME,
    LOGIN_SEL_PINFO,
    LOGIN_SEL_PINFO_BANS,
    LOGIN_SEL_GM_ACCOUNTS,
    LOGIN_SEL_ACCOUNT_INFO,
    LOGIN_SEL_ACCOUNT_ACCESS_GMLEVEL_TEST,
    LOGIN_SEL_ACCOUNT_ACCESS,
    LOGIN_SEL_ACCOUNT_WHOIS,
    LOGIN_SEL_REALMLIST_SECURITY_LEVEL,
    LOGIN_DEL_ACCOUNT,
    
    LOGIN_SET_DUMP,
    LOGIN_UPD_DUMP,
    LOGIN_ADD_TRANSFERTS_LOGS,

    LOGIN_SEL_BNET_ACCOUNT_INFO,
    LOGIN_SEL_BNET_ACCOUNT_INFO_BY_ACC,
    LOGIN_UPD_BNET_LAST_LOGIN_INFO,
    LOGIN_INS_BNET_ACCOUNT,
    LOGIN_SEL_BNET_ACCOUNT_EMAIL_BY_ID,
    LOGIN_SEL_BNET_ACCOUNT_ID_BY_EMAIL,
    LOGIN_UPD_BNET_PASSWORD,
    LOGIN_SEL_BNET_CHECK_PASSWORD,
    LOGIN_UPD_BNET_ACCOUNT_LOCK,
    LOGIN_UPD_BNET_ACCOUNT_LOCK_CONTRY,
    LOGIN_SEL_BNET_ACCOUNT_ID_BY_GAME_ACCOUNT,
    LOGIN_SEL_BNET_ACCOUNT_EMAIL_BY_ACC,

    LOGIN_UPD_AT_AUTH_FLAG,
    LOGIN_SEL_BATTLEPAY_COINS,
    LOGIN_UPD_BATTLEPAY_CHANGE_COINS_COUNT,    
    
    LOGIN_SEL_ACCOUNT_INFO_CONTINUED_SESSION,
    LOGIN_UPD_ACCOUNT_INFO_CONTINUED_SESSION,
    LOGIN_UPD_BNET_GAME_ACCOUNT_LOGIN_INFO,
    LOGIN_SEL_BNET_LAST_PLAYER_CHARACTERS,
    LOGIN_DEL_BNET_LAST_PLAYER_CHARACTERS,
    LOGIN_INS_BNET_LAST_PLAYER_CHARACTERS,
    LOGIN_SEL_BNET_CHARACTER_COUNTS_BY_BNET_ID,
    LOGIN_SEL_BNET_CHARACTER_COUNTS_BY_ACCOUNT_ID,
    LOGIN_SEL_ACCOUNT_IP_ACCESS,
    
    LOGIN_SELECT_DONATE_TOKEN,
    LOGIN_UPD_DESTROY_DONATE_TOKEN,
    LOGIN_UPD_ADD_DONATE_TOKEN,
    LOGIN_INS_STORE_ADD_ITEM_LOG,
    LOGIN_INS_STORE_ADD_ITEM_LOG_SERVICE,
    LOGIN_INS_STORE_ADD_ITEM_LOG_BONUS,
    LOGIN_INS_STORE_ADD_ITEM_LOG_ADDITIONAL,
    LOGIN_UPD_HISTORY_GUID,
    LOGIN_UPD_HISTORY_STATUS,
    LOGIN_UPD_HISTORY_STATUS_AND_GUID_BY_STATUS,
    LOGIN_UPD_HISTORY_RETURN,
    LOGIN_INS_STORE_ADD_ITEM_LOG_SERVICE_ART,
    LOGIN_INS_STORE_ADD_ITEM_LOG_GUILD_RENAME,

    LOGIN_SEL_ACCOUNT_CHARACTER_TEMPLATE,
    LOGIN_UPD_ACCOUNT_CHARACTER_TEMPLATE,
    LOGIN_UPD_TRANSFER_REQUESTS,

    MAX_LOGINDATABASE_STATEMENTS,
};

#endif
