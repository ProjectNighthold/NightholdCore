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

#include "AdhocStatement.h"
#include "MySQLConnection.h"

BasicStatementTask::BasicStatementTask(const char* sql, bool async, bool iscallback, std::function<void(QueryResult)> && callback) : m_result(nullptr), m_Callback(std::move(callback))
{
    m_sql = strdup(sql);
    m_has_result = async; // If the operation is async, then there's a result
    m_has_callback = iscallback;
    if (async)
        m_result = new QueryResultPromise();
}

BasicStatementTask::~BasicStatementTask()
{
    free((void*)m_sql);
    if (m_has_result && m_result != nullptr)
        delete m_result;
}

bool BasicStatementTask::Execute()
{
    if (m_has_result)
    {
        ResultSet* result = m_conn->Query(m_sql);
        if (!result || !result->GetRowCount() || !result->NextRow())
        {
            delete result;
            if (m_has_callback)
                m_Callback(QueryResult(NULL));
            else
                m_result->set_value(QueryResult(NULL));
            return false;
        }

        if (m_has_callback)
            m_Callback(QueryResult(result));
        else
            m_result->set_value(QueryResult(result));
        return true;
    }

    bool _executed = m_conn->Execute(m_sql);
    if (_executed && m_has_callback)
        m_Callback(QueryResult(NULL));
    return _executed;
}

QueryResultFuture BasicStatementTask::GetFuture() const
{
    return m_result->get_future();
}
