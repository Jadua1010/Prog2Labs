cmake_minimum_required(VERSION 3.29)
project(Lab1)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

include_directories(include/SDL2/include)

add_executable(Lab1 src/main.cpp
        src/Ghost.cpp
        src/Pacman.cpp
        src/UI.cpp
        include/GhostState.h
)
