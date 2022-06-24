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

#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include "Field.h"
#include "DatabaseEnvFwd.h"

#ifdef _WIN32
#include <winsock2.h>
#endif
#include <mysql.h>

class ResultSet
{
public:
    ResultSet(MYSQL_RES* result, MYSQL_FIELD* fields, uint64 rowCount, uint32 fieldCount);
    ~ResultSet();

    bool NextRow();
    uint64 GetRowCount() const;
    uint32 GetFieldCount() const;

    Field* Fetch() const;

    const Field& operator [](uint32 index) const;

protected:
    uint64 _rowCount;
    Field* _currentRow;
    uint32 _fieldCount;

private:
    void CleanUp();
    MYSQL_RES* _result;
    MYSQL_FIELD* _fields;

    ResultSet(ResultSet const& right) = delete;
    ResultSet& operator=(ResultSet const& right) = delete;
};

class PreparedResultSet
{
public:
    PreparedResultSet(MYSQL_STMT* stmt, MYSQL_RES* result, uint64 rowCount, uint32 fieldCount);
    ~PreparedResultSet();

    bool NextRow();
    uint64 GetRowCount() const;
    uint32 GetFieldCount() const;
    Field* Fetch() const;
    const Field& operator [](uint32 index) const;

protected:
    std::vector<Field*> m_rows;
    uint64 m_rowCount;
    uint64 m_rowPosition;
    uint32 m_fieldCount;

private:
    MYSQL_BIND* m_rBind;
    MYSQL_STMT* m_stmt;
    MYSQL_RES* m_res;

    my_bool* m_isNull;
    unsigned long* m_length;

    void FreeBindBuffer();
    void CleanUp();
    bool _NextRow();

    PreparedResultSet(PreparedResultSet const& right) = delete;
    PreparedResultSet& operator=(PreparedResultSet const& right) = delete;
};

#endif

