cmake_minimum_required(VERSION 3.3)
project(NonGravitar CXX)

set(CMAKE_CXX_STANDARD 17)

# olcPixelGameEngine directory
set(OLCPGE_DIR "./library/olcPixelGameEngine/")
# Project's class definition and Core.hpp
set(INCLUDE_DIR "./include/")

# Compiler (g++) flags
set(C_FLAGS "-I $(OLCPGE_DIR) -I $(INCLUDE_DIR)")
add_compile_options(${C_FLAGS})
add_definitions("-D DEBUG_MODE")

include_directories(${INCLUDE_DIR})
include_directories(${OLCPGE_DIR})

add_executable(NonGravitar NonGravitar.cpp source/Game.cpp )
target_link_libraries(NonGravitar X11 GL pthread png stdc++fs)