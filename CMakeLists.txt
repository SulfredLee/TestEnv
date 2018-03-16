cmake_minimum_required (VERSION 2.8.12)

# Maps to a solution filed (*.sln). The solution will
# have all targets (exe, lib, dll) as projects (.vcproj)
project(TestEnv)

# Turn on the ability to create folders to organize projects (.vcproj)
# It creates "CMakePredefinedTargets" folder by default and adds CMake
# defined projects like INSTALL.vcproj and ZERO_CHECK.vcproj
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Handle Preprocess Flags
if (UNIX)
  add_definitions(-DUNIX)
else ()
  add_definitions(-DWINDOWS -DWIN32 "/EHsc")
endif ()


# Sub-directories where more CMakeLists.txt exist
add_subdirectory(TranslationUnit_C)
add_subdirectory(TranslationUnit_Cpp)
add_subdirectory(TestIncludeArray)
add_subdirectory(TestString)
add_subdirectory(ArrayStruct_C)
add_subdirectory(ReadWriteFile_C)
add_subdirectory(ArrayManipulation)
add_subdirectory(Inheritance_C)
