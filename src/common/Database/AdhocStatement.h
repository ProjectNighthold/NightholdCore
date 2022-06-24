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

#ifndef _ADHOCSTATEMENT_H
#define _ADHOCSTATEMENT_H

#include "SQLOperation.h"
#include "DatabaseEnvFwd.h"

class BasicStatementTask : public SQLOperation
{
public:
    BasicStatementTask(const char* sql, bool async = false, bool iscallback = false, std::function<void(QueryResult)> && callback = [](QueryResult) -> void {});
    ~BasicStatementTask();

    bool Execute() override;
    QueryResultFuture GetFuture() const;

private:
    const char* m_sql;      //- Raw query to be executed
    bool m_has_result;
    bool m_has_callback;
    QueryResultPromise* m_result;
    std::function<void(QueryResult)> m_Callback;
};

#endif
