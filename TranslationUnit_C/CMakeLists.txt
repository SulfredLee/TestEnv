# Command to output information to the console
# Useful for displaying errors, warnings, and debugging
set(CMAKE_CXX_FLAGS "-Wall -fPIC -std=c++11")
set(CMAKE_VERBOSE_MAKEFILE on)
message(STATUS "TranslationUnit_C - cxx Flags: " ${CMAKE_CXX_FLAGS})

file(GLOB Project_src
  "./lib/*.c"
  "./lib/*.h"
  "./*.c"
  "./*.h")

include_directories(
  ./lib
  .)

add_executable(TranslationUnit_C ${Project_src})
# add_dependencies(TranslationUnit_C FrontEnd)

# target_link_libraries(TranslationUnit_C
#   FrontEnd
#   ${Qt5Widgets_LIBRARIES})

# Creates a folder "executables" and adds target
# project (*.vcproj) under it
set_property(TARGET TranslationUnit_C PROPERTY FOLDER "executables")

# Adds logic to INSTALL.vcproj to copy *.exe to destination directory
install (TARGETS TranslationUnit_C
  RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin
  LIBRARY DESTINATION ${PROJECT_BINARY_DIR}/bin
  ARCHIVE DESTINATION ${PROJECT_BINARY_DIR}/bin)
