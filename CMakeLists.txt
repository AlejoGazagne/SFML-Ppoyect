cmake_minimum_required(VERSION 3.15)
project(proyecto-infoII)
include_directories("C:\\mingw64\\include")

set(CMAKE_CXX_STANDARD 14)

#add_compile_definitions(DEBUG)


if(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(TMXLITE_STATIC_LIB TRUE)
    SET(CMAKE_EXE_LINKER_FLAGS "-static")
endif()

# Install TMXLITE if not installed
find_package(TMXLITE QUIET)

if (NOT ${TMXLITE_FOUND})
    message(STATUS "tmxlite not found, fetching from github...")
    include(FetchContent)
    FetchContent_Declare(
            tmxlite
            GIT_REPOSITORY https://github.com/fallahn/tmxlite
            GIT_TAG v1.2.1
    )
    FetchContent_MakeAvailable(tmxlite)
    add_subdirectory(${tmxlite_SOURCE_DIR}/tmxlite)
    set(TMXLITE_LIBRARIES tmxlite)
    set(TMXLITE_INCLUDE_DIR ${tmxlite_SOURCE_DIR}/tmxlite/include)
endif ()
include_directories(${TMXLITE_INCLUDE_DIR})
#

add_executable(proyecto main.cpp Clases/personaje.cpp Clases/Ataque.cpp Clases/maniMenu.cpp)
target_link_libraries(proyecto sfml-graphics sfml-audio sfml-system sfml-window ${TMXLITE_LIBRARIES})
