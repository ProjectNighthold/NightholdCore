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

#include "segvcatch.h"
#include "Util.h"

#include <stdexcept>
#include <sstream>

using namespace std;

namespace
{

segvcatch::handler handler_segv = 0;
segvcatch::handler handler_abrt = 0;
segvcatch::handler handler_fpe = 0;

#if defined __GNUC__ && __linux

#ifdef __i386__
#include "i386-signal.h"
#endif /*__i386__*/

#ifdef __x86_64__
#include "x86_64-signal.h"
#endif /*__x86_64__*/

#endif /*defined __GNUC__ && __linux*/

void default_segv()
{
    throw std::runtime_error("Segmentation fault ");
}

void default_abrt()
{
    throw std::runtime_error("Program terminated ");
}

void default_fpe()
{
    throw std::runtime_error("Floating-point exception ");
}

void handle_segv()
{
    if (handler_segv)
        handler_segv();
}

void handle_abrt()
{
    if (handler_abrt)
        handler_abrt();
}

void handle_fpe()
{
    if (handler_fpe)
        handler_fpe();
}

#if defined (HANDLE_SEGV) || defined(HANDLE_FPE)

#include <execinfo.h>

/* Unblock a signal.  Unless we do this, the signal may only be sent
   once.  */
static void unblock_signal(int signum __attribute__((__unused__)))
{
#ifdef _POSIX_VERSION
    sigset_t sigs;
    sigemptyset(&sigs);
    sigaddset(&sigs, signum);
    sigprocmask(SIG_UNBLOCK, &sigs, NULL);
#endif
}
#endif

#ifdef HANDLE_SEGV

SIGNAL_HANDLER(catch_segv)
{
    // if (m_worldCrashChecker || m_stopEvent || segvcatch::crash_ignore)
        // signal(SIGSEGV, SIG_IGN);
    // else
    // {
        // segvcatch::crash_ignore = true;
        unblock_signal(SIGSEGV);
        MAKE_THROW_FRAME(nullp);
        handle_segv();
        // segvcatch::crash_ignore = false;
    // }
}
#endif

#ifdef HANDLE_ABRT

SIGNAL_HANDLER(catch_abrt)
{
    // if (m_worldCrashChecker || m_stopEvent || segvcatch::crash_ignore)
        // signal(SIGABRT, SIG_IGN);
    // else
    // {
        // segvcatch::crash_ignore = true;
        unblock_signal(SIGABRT);
        MAKE_THROW_FRAME(nullp);
        handle_abrt();
        // segvcatch::crash_ignore = false;
    // }
}
#endif

#ifdef HANDLE_FPE

SIGNAL_HANDLER(catch_fpe)
{
    // if (m_worldCrashChecker || m_stopEvent || segvcatch::crash_ignore)
        // signal(SIGFPE, SIG_IGN);
    // else
    // {
        // segvcatch::crash_ignore = true;
        unblock_signal(SIGFPE);
    #ifdef HANDLE_DIVIDE_OVERFLOW
        HANDLE_DIVIDE_OVERFLOW;
    #else
        MAKE_THROW_FRAME(arithexception);
    #endif
        handle_fpe();
        // segvcatch::crash_ignore = false;
    // }
}
#endif

#ifdef WIN32
#include <windows.h>

static LONG CALLBACK win32_exception_handler(LPEXCEPTION_POINTERS e)
{
    if (e->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION)
    {
        handle_segv();
        return EXCEPTION_CONTINUE_EXECUTION;
    }
    else if (e->ExceptionRecord->ExceptionCode == EXCEPTION_INT_DIVIDE_BY_ZERO)
    {
        handle_fpe();
        return EXCEPTION_CONTINUE_EXECUTION;
    }
    else
        return EXCEPTION_CONTINUE_SEARCH;
}
#endif
}


namespace segvcatch
{

bool crash_ignore = false;

void init_segv(handler h)
{
    if (h)
        handler_segv = h;
    else
        handler_segv = default_segv;
#ifdef HANDLE_SEGV
    INIT_SEGV;
#endif

#ifdef WIN32
    SetUnhandledExceptionFilter(win32_exception_handler);
#endif
}

void init_abrt(handler h)
{
    if (h)
        handler_abrt = h;
    else
        handler_abrt = default_abrt;

#ifdef HANDLE_ABRT
    INIT_ABRT;
#endif

#ifdef WIN32
    SetUnhandledExceptionFilter(win32_exception_handler);
#endif
}

void init_fpe(handler h)
{
    if (h)
        handler_fpe = h;
    else
        handler_fpe = default_fpe;
#ifdef HANDLE_FPE
    INIT_FPE;
#endif

#ifdef WIN32
    SetUnhandledExceptionFilter(win32_exception_handler);
#endif

}

}
