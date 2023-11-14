# CMakeList.txt : CMake project for Rogue Dungeon, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Rogue Dungeon")

# Add source to this project's executable.
add_executable (CMakeTarget "Rogue Dungeon.cpp" "Rogue Dungeon.h" "CharacterSheet.h" "Enemies.h" "Characters/Paladin.h" "Characters/Arbalist.h" "Characters/Herbalist.h" "Weapons.h" "Characters/Archer" "Characters/Blacksmith" "Characters/Demon" "Characters/Hound" "Characters/Knight" "Characters/Stargazer")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
