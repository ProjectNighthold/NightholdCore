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

#include "DatabaseLoader.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "DBUpdater.h"
#include "Log.h"

#include <mysqld_error.h>

DatabaseLoader::DatabaseLoader(std::string const& logger, uint32 const defaultUpdateMask)
    : _logger(logger), _autoSetup(sConfigMgr->GetBoolDefault("Updates.AutoSetup", true)),
    _updateFlags(sConfigMgr->GetIntDefault("Updates.EnableDatabases", defaultUpdateMask))
{
}

template <class T>
DatabaseLoader& DatabaseLoader::AddDatabase(DatabaseWorkerPool<T>& pool, std::string const& name)
{
    bool const updatesEnabledForThis = DBUpdater<T>::IsEnabled(_updateFlags);

    _open.push([this, name, updatesEnabledForThis, &pool]() -> bool
    {
        std::string const dbString = sConfigMgr->GetStringDefault(name + "DatabaseInfo", "");
        if (dbString.empty())
        {
            TC_LOG_ERROR(LOG_FILTER_GENERAL, "Database %s not specified in configuration file!", name.c_str());
            return false;
        }

        uint8 const asyncThreads = uint8(sConfigMgr->GetIntDefault(name + "Database.WorkerThreads", 1));
        if (asyncThreads < 1 || asyncThreads > 32)
        {
            TC_LOG_ERROR(LOG_FILTER_GENERAL, "%s database: invalid number of worker threads specified. "
                "Please pick a value between 1 and 32.", name.c_str());
            return false;
        }

        uint8 const synchThreads = uint8(sConfigMgr->GetIntDefault(name + "Database.SynchThreads", 1));

        //pool.SetConnectionInfo(dbString, asyncThreads, synchThreads);
        if (bool error = pool.Open(dbString, asyncThreads, synchThreads))
        {
            // Database does not exist
           /* if (error && updatesEnabledForThis && _autoSetup)
            {
                // Try to create the database and connect again if auto setup is enabled
                if (DBUpdater<T>::Create(pool) && (!pool.Open(dbString, asyncThreads, synchThreads)))
                    error = true;
            }*/

            // If the error wasn't handled quit
            if (!error)
            {
                TC_LOG_ERROR(LOG_FILTER_GENERAL, "\nDatabasePool %s NOT opened. There were errors opening the MySQL connections. Check your SQLDriverLogFile "
                    "for specific errors. Read wiki at https://www.trinitycore.info/display/tc/TrinityCore+Home", name.c_str());

                return false;
            }
        }
        // Add the close operation
        _close.push([&pool]
        {
            pool.Close();
        });
        return true;
    });

    // Populate and update only if updates are enabled for this pool
    if (updatesEnabledForThis)
    {
        _populate.push([this, name, &pool]() -> bool
        {
            if (!DBUpdater<T>::Populate(pool))
            {
                TC_LOG_ERROR(LOG_FILTER_GENERAL, "Could not populate the %s database, see log for details.", name.c_str());
                return false;
            }
            return true;
        });

        _update.push([this, name, &pool]() -> bool
        {
            if (!DBUpdater<T>::Update(pool))
            {
                TC_LOG_ERROR(LOG_FILTER_GENERAL, "Could not update the %s database, see log for details.", name.c_str());
                return false;
            }
            return true;
        });
    }

  

    return *this;
}

bool DatabaseLoader::Load()
{
    if (!_updateFlags)
        TC_LOG_INFO(LOG_FILTER_UPDATE_SQL, "Automatic database updates are disabled for all databases!");

    if (!OpenDatabases())
        return false;

    if (!PopulateDatabases())
        return false;

    if (!UpdateDatabases())
        return false;

  

    return true;
}

bool DatabaseLoader::OpenDatabases()
{
    return Process(_open);
}

bool DatabaseLoader::PopulateDatabases()
{
    return Process(_populate);
}

bool DatabaseLoader::UpdateDatabases()
{
    return Process(_update);
}

bool DatabaseLoader::PrepareStatements()
{
    return Process(_prepare);
}

bool DatabaseLoader::Process(std::queue<Predicate>& queue)
{
    while (!queue.empty())
    {
        if (!queue.front()())
        {
            // Close all open databases which have a registered close operation
            while (!_close.empty())
            {
                _close.top()();
                _close.pop();
            }

            return false;
        }

        queue.pop();
    }
    return true;
}

template
DatabaseLoader& DatabaseLoader::AddDatabase<LoginDatabaseConnection>(DatabaseWorkerPool<LoginDatabaseConnection>&, std::string const&);
template
DatabaseLoader& DatabaseLoader::AddDatabase<CharacterDatabaseConnection>(DatabaseWorkerPool<CharacterDatabaseConnection>&, std::string const&);
template
DatabaseLoader& DatabaseLoader::AddDatabase<HotfixDatabaseConnection>(DatabaseWorkerPool<HotfixDatabaseConnection>&, std::string const&);
template
DatabaseLoader& DatabaseLoader::AddDatabase<WorldDatabaseConnection>(DatabaseWorkerPool<WorldDatabaseConnection>&, std::string const&);
