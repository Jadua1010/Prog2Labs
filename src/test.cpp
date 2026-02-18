

#include <iostream>
#include <array>
#include <string>
#include <tuple>
#include <chrono>
#include <thread>
#include <algorithm>
#include "main.h"


// In this case we use a square 12x12 maze defined globally
std::array<std::array<char, mazeSize>, mazeSize> maze;


// Function to enable easy input and attempt to fix some broken mazes
std::array<char, mazeSize> removeSpaces(std::string str) {
    // Remove all spaces
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

    std::array<char, mazeSize> arr{};

    // Start by filling with wall elements
    arr.fill('#');

    // Now cast all elements from the string into the array
    size_t len = std::min(str.size(), static_cast<size_t>(mazeSize));
    for (size_t i = 0; i < len; ++i) {
        arr[i] = str[i];
    }

    return arr;
}


int TestScript() {

    // Testing a correct maze
    maze = {
            removeSpaces("# # # # # # # # # # # #"),
            removeSpaces("# . . . # . . . . . . #"),
            removeSpaces(". . # . # . # # # # . #"),
            removeSpaces("# # # . # . . . . # . #"),
            removeSpaces("# . . . . # # # . # . x"),
            removeSpaces("# # # # . # . # . # . #"),
            removeSpaces("# . . # . # . # . # . #"),
            removeSpaces("# # . # . # . # . # . #"),
            removeSpaces("# . . . . . . . . # . #"),
            removeSpaces("# # # # # # . # # # . #"),
            removeSpaces("# . . . . . . . . . . #"),
            removeSpaces("# # # # # # # # # # # #")
    };

    RunProgram(maze);

    // Testing an unsolvable maze
    maze = {
            removeSpaces("# # # # # # # # # # # #"),
            removeSpaces("# . . . # . . . . . . #"),
            removeSpaces("# . # . # . # # # # . #"),
            removeSpaces("# # # . # . . . . # . #"),
            removeSpaces("# . . . . # # # . # . x"),
            removeSpaces("# # # # . # . # . # . #"),
            removeSpaces("# . . # . # . # . # . #"),
            removeSpaces("# # . # . # . # . # . #"),
            removeSpaces("# . . . . . . . . # . #"),
            removeSpaces("# # # # # # . # # # . #"),
            removeSpaces("# . . . . . . . . . . #"),
            removeSpaces("# # # # # # # # # # # #")
    };

    // Testing without an X
    maze = {
            removeSpaces("# # # # # # # # # # # #"),
            removeSpaces("# . . . # . . . . . . #"),
            removeSpaces(". . # . # . # # # # . #"),
            removeSpaces("# # # . # . . . . # . #"),
            removeSpaces("# . . . . # # # . # . #"),
            removeSpaces("# # # # . # . # . # . #"),
            removeSpaces("# . . # . # . # . # . #"),
            removeSpaces("# # . # . # . # . # . #"),
            removeSpaces("# . . . . . . . . # . #"),
            removeSpaces("# # # # # # . # # # . #"),
            removeSpaces("# . . . . . . . . . . #"),
            removeSpaces("# # # # # # # # # # # #")
    };

    // Testing with elements missing
    maze = {
            removeSpaces("# # # # # # # # # # # #"),
            removeSpaces("# . . . # . . . . . . #"),
            removeSpaces(". . # . # . # # # # . #"),
            removeSpaces("# # # . # . . . . # . #"),
            removeSpaces("# . . . . # # # . # . #"),
            removeSpaces("# # # # . #   # . # . #"),
            removeSpaces("# . . # . # . # . # . #"),
            removeSpaces("# # . # . # . # .   . #"),
            removeSpaces("# . . . . . . . . # . #"),
            removeSpaces("# # # # # # . # # # . #"),
            removeSpaces("# . . . . . . . . . . #"),
            removeSpaces("# # # # # # # # # # # #")
    };


    return 0;
}