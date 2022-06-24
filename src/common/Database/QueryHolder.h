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

#ifndef _QUERYHOLDER_H
#define _QUERYHOLDER_H

#include "DatabaseEnvFwd.h"

class SQLQueryHolder
{
    friend class SQLQueryHolderTask;
    typedef std::pair<SQLElementData, SQLResultSetUnion> SQLResultPair;
    std::vector<SQLResultPair> m_queries;
public:
    SQLQueryHolder() {}
    ~SQLQueryHolder();
    bool SetQuery(size_t index, const char *sql);
    bool SetPreparedQuery(size_t index, PreparedStatement* stmt);
    void SetSize(size_t size);
    QueryResult GetResult(size_t index);
    PreparedQueryResult GetPreparedResult(size_t index);
    void SetResult(size_t index, ResultSet* result);
    void SetPreparedResult(size_t index, PreparedResultSet* result);
};

class SQLQueryHolderTask : public SQLOperation
{
    SQLQueryHolder* m_holder;
    QueryResultHolderPromise m_result;
    bool m_executed;

public:
    SQLQueryHolderTask(SQLQueryHolder* holder);

    ~SQLQueryHolderTask();

    bool Execute() override;
    QueryResultHolderFuture GetFuture();
};

#endif
