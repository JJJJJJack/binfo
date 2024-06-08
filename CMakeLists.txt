cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(binfo VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Create a variable for the source files
set(SOURCES
    src/binfoCommon.cpp
    src/binfoFile.cpp
    src/binfoLinux.cpp
    src/binfoWindows.cpp
)

# Create a variable for the header files (optional, but good practice)
set(HEADERS
    include/binfo.hpp
    include/BinaryManager.hpp
    include/BinaryManagerElf32.hpp
    include/BinaryManagerElf64.hpp
    include/BinaryManagerNT32.hpp
    include/BinaryManagerNT64.hpp
    include/Executables.hpp
    include/linuxstructs.h
    include/linuxtypes.h
    include/winstructs.h
    include/wintypes.h
)

# Add the static library target
add_library(binfo_lib STATIC ${SOURCES})

# Add the executable target
add_executable(binfo main.cpp)

# Link the static library to the executable
target_link_libraries(binfo binfo_lib)

# Specify the output directories for the library and executable
set_target_properties(binfo_lib PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set_target_properties(binfo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
