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

#include "Errors.h"
#include "Util.h"
#include "Duration.h"

#include <cstdio>
#include <cstdlib>
#include <thread>
#include <cstdarg>

namespace Trinity {

void Assert(char const* file, int line, char const* function, char const* message)
{
    fprintf(stderr, "\n%s:%i in %s ASSERTION FAILED:\n  %s\n",
            file, line, function, message);
    *((volatile int*)NULL) = 0;
    exit(1);
}

void Assert(char const* file, int line, char const* function, char const* message, char const* format, ...)
{
    va_list args;
    va_start(args, format);

    fprintf(stderr, "\n%s:%i in %s ASSERTION FAILED:\n  %s ", file, line, function, message);
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
    fflush(stderr);

    va_end(args);
    *((volatile int*)NULL) = 0;
    exit(1);
}

void Fatal(char const* file, int line, char const* function, char const* message, ...)
{
    va_list args;
    va_start(args, message);

    fprintf(stderr, "\n%s:%i in %s FATAL ERROR:\n  ", file, line, function);
    vfprintf(stderr, message, args);
    fprintf(stderr, "\n");
    fflush(stderr);

    std::this_thread::sleep_for(std::chrono::seconds(10));
    *((volatile int*)NULL) = 0;
    exit(1);
}

void Error(char const* file, int line, char const* function, char const* message)
{
    fprintf(stderr, "\n%s:%i in %s ERROR:\n  %s\n",
                   file, line, function, message);
    *((volatile int*)NULL) = 0;
    exit(1);
}

void Warning(char const* file, int line, char const* function, char const* message)
{
    fprintf(stderr, "\n%s:%i in %s WARNING:\n  %s\n",
                   file, line, function, message);
}

void Abort(char const* file, int line, char const* function)
{
    fprintf(stderr, "\n%s:%i in %s ABORTED.\n",
                   file, line, function);
    *((volatile int*)NULL) = 0;
    exit(1);
}

void AbortHandler(int signum)
{
    if (m_worldCrashChecker) // Prevent double dump if crash already run
    {
        std::this_thread::sleep_for(Milliseconds(5000)); // Waiting when gdb is dump this thread
        signal(signum, SIG_DFL);
    }
    else
    {
        m_worldCrashChecker = true;
        TC_LOG_ERROR(LOG_FILTER_WORLDSERVER, "AbortHandler m_worldCrashChecker %u", m_worldCrashChecker);

        std::this_thread::sleep_for(Milliseconds(5000)); // Waiting for save and exit from work thread

        signal(signum, SIG_DFL);
        exit(1);
    }
}

void DumpHandler(int signum)
{
    if (m_worldCrashChecker) // Prevent double dump if crash already run
    {
        std::this_thread::sleep_for(Milliseconds(5000)); // Waiting when gdb is dump this thread
        signal(signum, SIG_DFL);
    }
    else
    {
        m_worldCrashChecker = true;
        TC_LOG_ERROR(LOG_FILTER_WORLDSERVER, "DumpHandler m_worldCrashChecker %u", m_worldCrashChecker);

        std::this_thread::sleep_for(Milliseconds(5000)); // Waiting for save and exit from work thread

        signal(signum, SIG_DFL);
        exit(3);
    }
}

} // namespace Trinity
