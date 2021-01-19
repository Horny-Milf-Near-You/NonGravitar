cmake_minimum_required(VERSION 3.16)
project(NonGravitar CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# olcPixelGameEngine directory
set(OLCPGE_DIR "./library/olcPixelGameEngine/")
# Project's class definition and Core.hpp
set(INCLUDE_DIR "./include/")

# Compiler (g++) flags
add_definitions("-D DEBUG_MODE")
add_compile_options(-Wall -Wextra)

include_directories(${INCLUDE_DIR} ${OLCPGE_DIR})

add_executable(NonGravitar NonGravitar.cpp source/Game.cpp)
# Useless?
# target_precompile_headers(NonGravitar PUBLIC "./library/olcPixelGameEngine/olcPixelGameEngine.h")
target_link_libraries(NonGravitar X11 GL pthread png stdc++fs)