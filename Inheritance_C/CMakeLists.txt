# Command to output information to the console
# Useful for displaying errors, warnings, and debugging
set(CMAKE_CXX_FLAGS "-Wall -fPIC -std=c++11")
set(CMAKE_VERBOSE_MAKEFILE on)
message(STATUS "Inheritance_C - cxx Flags: " ${CMAKE_CXX_FLAGS})

file(GLOB Project_src
  "./*.c"
  "./*.h")

include_directories(
  .)

add_executable(Inheritance_C ${Project_src})
# add_dependencies(Inheritance_C FrontEnd)

# target_link_libraries(Inheritance_C
#   FrontEnd
#   ${Qt5Widgets_LIBRARIES})

# Creates a folder "executables" and adds target
# project (*.vcproj) under it
set_property(TARGET Inheritance_C PROPERTY FOLDER "executables")

# Adds logic to INSTALL.vcproj to copy *.exe to destination directory
install (TARGETS Inheritance_C
  RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin
  LIBRARY DESTINATION ${PROJECT_BINARY_DIR}/bin
  ARCHIVE DESTINATION ${PROJECT_BINARY_DIR}/bin)
