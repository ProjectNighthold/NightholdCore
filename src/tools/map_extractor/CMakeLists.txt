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

file(GLOB_RECURSE sources *.cpp *.h)

include_directories (
  ${CMAKE_SOURCE_DIR}/src/common
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${CMAKE_SOURCE_DIR}/dep/CascLib/src
  ${CMAKE_SOURCE_DIR}/dep/g3dlite/include
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/loadlib
)

include_directories(${include_Dirs})

add_executable(mapextractor
  ${sources}
)

target_link_libraries(mapextractor
  common
  casc
  g3dlib
  boost
)

add_dependencies(mapextractor casc)

if( UNIX )
  install(TARGETS mapextractor DESTINATION bin)
elseif( WIN32 )
  install(TARGETS mapextractor DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()
