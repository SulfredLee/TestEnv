# Command to output information to the console
# Useful for displaying errors, warnings, and debugging
set(CMAKE_CXX_FLAGS "-Wall -fPIC -std=c++11")
set(CMAKE_VERBOSE_MAKEFILE on)
message(STATUS "TranslationUnit_Cpp - cxx Flags: " ${CMAKE_CXX_FLAGS})

file(GLOB Project_src
  "./*.cpp"
  "./*.h")

include_directories(
  .)

add_executable(TestIncludeArray ${Project_src})
# add_dependencies(TestIncludeArray FrontEnd)

# target_link_libraries(TestIncludeArray
#   FrontEnd
#   ${Qt5Widgets_LIBRARIES})

# Creates a folder "executables" and adds target
# project (*.vcproj) under it
set_property(TARGET TestIncludeArray PROPERTY FOLDER "executables")

# Adds logic to INSTALL.vcproj to copy *.exe to destination directory
install (TARGETS TestIncludeArray
  RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin
  LIBRARY DESTINATION ${PROJECT_BINARY_DIR}/bin
  ARCHIVE DESTINATION ${PROJECT_BINARY_DIR}/bin)
