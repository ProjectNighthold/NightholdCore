###############################################################################
#                                                                             #
# Copyright (C) 2022 Project Nighthold <https://github.com/ProjectNighthold>  #
#                                                                             #
# This file is free software; as a special exception the author gives         #
# unlimited permission to copy and/or distribute it, with or without          #
# modifications, as long as this notice is preserved.                         #
#                                                                             #
# This program is distributed in the hope that it will be useful, but         #
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the      #
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.    #
#                                                                             #
# Read the THANKS file on the source root directory for more info.            #
#                                                                             #
###############################################################################

CollectSourceFiles(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE_SOURCES
  # Exclude
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)

if (USE_COREPCH)
  set(PRIVATE_PCH_HEADER PrecompiledHeaders/gamePCH.h)
  set(PRIVATE_PCH_SOURCE PrecompiledHeaders/gamePCH.cpp)
  if (MSVC)
    list(INSERT PRIVATE_SOURCES 0 PrecompiledHeaders/gamePCH.cpp)
  endif (MSVC)
endif ()

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_library(game
  ${PRIVATE_SOURCES}
)

CollectIncludeDirectories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PUBLIC_INCLUDES
  # Exclude
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)

target_include_directories(game
  PUBLIC
    ${PUBLIC_INCLUDES}
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(game
  PUBLIC
    shared
    Detour)

set_target_properties(game
    PROPERTIES
      FOLDER
        "server")

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(game ${PRIVATE_PCH_HEADER} ${PRIVATE_PCH_SOURCE})
endif ()
