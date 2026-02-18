

#include <iostream>
#include <array>
#include <string>
#include <tuple>
#include <chrono>
#include <thread>
#include <algorithm>
#include "main.h"



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

    int result1 = RunProgram();

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

    int result2 = RunProgram();

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

    int result3 = RunProgram();

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

    int result4 = RunProgram();


    std::cout << "Results of the mazes are: " << (result1 ? "First one is a succes " : "first one failed ") << (result2 ? "second one is a succes " : "second one failed ") << (result3 ? "third one is a succes " : "third one failed ") << (result4 ? "fourth one is a succes " : "fourth one failed ") << std::endl;

    return 0;
}