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

#ifndef TRINITY_COMPILERDEFS_H
#define TRINITY_COMPILERDEFS_H

#define PLATFORM_WINDOWS 0
#define PLATFORM_UNIX    1
#define PLATFORM_APPLE   2
#define PLATFORM_INTEL   3

// must be first (win 64 also define _WIN32)
#if defined( _WIN64 )
#  define PLATFORM PLATFORM_WINDOWS
#elif defined( __WIN32__ ) || defined( WIN32 ) || defined( _WIN32 )
#  define PLATFORM PLATFORM_WINDOWS
#elif defined( __APPLE_CC__ )
#  define PLATFORM PLATFORM_APPLE
#elif defined( __INTEL_COMPILER )
#  define PLATFORM PLATFORM_INTEL
#else
#  define PLATFORM PLATFORM_UNIX
#endif

#define COMPILER_MICROSOFT 0
#define COMPILER_GNU       1
#define COMPILER_BORLAND   2
#define COMPILER_INTEL     3

#ifdef _MSC_VER
#  define COMPILER COMPILER_MICROSOFT
#elif defined( __BORLANDC__ )
#  define COMPILER COMPILER_BORLAND
#elif defined( __INTEL_COMPILER )
#  define COMPILER COMPILER_INTEL
#elif defined( __GNUC__ )
#  define COMPILER COMPILER_GNU
#  define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#else
#  error "FATAL ERROR: Unknown compiler."
#endif

#if COMPILER == COMPILER_MICROSOFT
#  pragma warning( disable : 4267 )                         // conversion from 'size_t' to 'int', possible loss of data
#  pragma warning( disable : 4786 )                         // identifier was truncated to '255' characters in the debug information
#  pragma warning( disable : 4800 )
#  pragma warning( disable : 4477 )
#endif

#if defined(__cplusplus) && __cplusplus == 201103L
#  define COMPILER_HAS_CPP11_SUPPORT 1
#else
#  define COMPILER_HAS_CPP11_SUPPORT 0
#endif

#endif
