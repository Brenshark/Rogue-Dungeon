# CMakeList.txt : CMake project for Rogue Dungeon, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("RogueDungeon")
# Add source to this project's executable.
#include_directories(${OpenCV_INCLUDE_DIRS})
#find_package(OpenCV REQUIRED)

add_executable (CMakeTarget "RogueDungeon.cpp" "RogueDungeon.h" "CharacterSheet.h"  "Paladin.h" "Arbalist.h" "Weapons.h" "Archer.h" "Blacksmith.h" "Demon.h" "Hound.h" "Knight.h" "Stargazer.h" "CharacterSheet.cpp"  "Arbalist.cpp" "Archer.cpp" "Blacksmith.cpp" "Demon.cpp" "Hound.cpp" "Knight.cpp" "Paladin.cpp" "Priest.cpp" "Stargazer.cpp"  "Character.h" "Character.cpp" "Rogue.cpp" "Rogue.h" "Weapons.cpp" "Map.h" "Map.cpp" "Battle.cpp" "Battle.h"  "CharacterInitialization.h")

#target_link_libraries("C:\Users\Brens\source\repos\Rogue Dungeon" ${OPENCV_LIBS})
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
