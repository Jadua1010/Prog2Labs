cmake_minimum_required(VERSION 3.29)
project(Lab1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab1 src/main.cpp
        include/package.cpp
        include/package.h
        include/twoDayPackage.cpp
        include/twoDayPackage.h
        include/overnightPackage.cpp
        include/overnightPackage.h
        include/address.cpp
        include/address.h
)
