cmake_minimum_required(VERSION 3.29)
project(Lab1)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(Lab1 src/main.cpp
        src/address.cpp
        src/package.cpp
        src/twoDayPackage.cpp
        src/overnightPackage.cpp
        src/BusinessCustomer.cpp
        src/Customer.cpp
        src/PrivateCustomer.cpp
        src/twoDayPackage.cpp
)
