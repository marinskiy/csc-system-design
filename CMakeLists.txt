cmake_minimum_required(VERSION 3.14)

# set the project name and version
project(Shell VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# work-around: FindBoost: Boost_ARCHITECTURE not detected on MinGW
# https://gitlab.kitware.com/cmake/cmake/-/issues/20587
if(MINGW)
    if (CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(Boost_ARCHITECTURE "-x64")
    else()
        set(Boost_ARCHITECTURE "-x32")
    endif()
endif()

FIND_PACKAGE(Boost COMPONENTS system io thread)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
