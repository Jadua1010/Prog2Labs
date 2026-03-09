cmake_minimum_required(VERSION 3.29)
project(Lab1)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(Lab1 src/main.cpp
        include/address.cpp
        include/package.cpp
        include/twoDayPackage.cpp
        include/overnightPackage.cpp
)
