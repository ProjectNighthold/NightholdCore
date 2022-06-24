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

#ifndef _SQLOPERATION_H
#define _SQLOPERATION_H

#include "QueryResult.h"

//- Forward declare (don't include header to prevent circular includes)
class PreparedStatement;

//- Union that holds element data
union SQLElementUnion
{
    PreparedStatement* stmt;
    const char* query;
};

//- Type specifier of our element data
enum SQLElementDataType
{
    SQL_ELEMENT_RAW,
    SQL_ELEMENT_PREPARED,
};

//- The element
struct SQLElementData
{
    SQLElementUnion element;
    SQLElementDataType type;
};

//- For ambigious resultsets
union SQLResultSetUnion
{
    PreparedResultSet* presult;
    ResultSet* qresult;
};

class MySQLConnection;

class SQLOperation
{
    public:
        SQLOperation(): m_conn(NULL) { }
        virtual ~SQLOperation() { }

        virtual int call()
        {
            Execute();
            return 0;
        }
        virtual bool Execute() = 0;
        virtual void SetConnection(MySQLConnection* con) { m_conn = con; }

        MySQLConnection* m_conn;

    private:
        SQLOperation(SQLOperation const& right) = delete;
        SQLOperation& operator=(SQLOperation const& right) = delete;
};

#endif
