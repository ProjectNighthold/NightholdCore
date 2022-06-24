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

#ifndef _TRANSACTION_H
#define _TRANSACTION_H

#include "SQLOperation.h"
#include "DatabaseEnvFwd.h"
#include "StringFormat.h"

class PreparedStatement;

class Transaction
{
    friend class TransactionTask;
    friend class MySQLConnection;
    friend class DatabaseWokerPool;

    template <typename T>
    friend class DatabaseWorkerPool;

public:
    Transaction();
    ~Transaction();

    void Append(PreparedStatement* statement);
    void Append(const char* sql);
    template<typename Format, typename... Args>
    void PAppend(Format&& sql, Args&&... args)
    {
        Append(Trinity::StringFormat(std::forward<Format>(sql), std::forward<Args>(args)...).c_str());
    }

    size_t GetSize() const;

protected:
    void Cleanup();
    std::list<SQLElementData> m_queries;

private:
    bool _cleanedUp;
};

class TransactionTask : public SQLOperation
{
    template <class T> friend class DatabaseWorkerPool;
    friend class DatabaseWorker;

public:
    TransactionTask(SQLTransaction trans, std::function<void()>&& callback = []() -> void {});
    ~TransactionTask() = default;

protected:
    bool Execute() override;

    SQLTransaction m_trans;
    std::function<void()> m_Callback;
};

#endif
