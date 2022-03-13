cmake_minimum_required(VERSION 3.14)

# set the project name and version
project(Shell VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

FIND_PACKAGE(Boost COMPONENTS system io thread)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
ENDIF()

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
