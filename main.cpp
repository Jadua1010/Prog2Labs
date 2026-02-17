//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 1.1
//=====================...........................=================================

#include <iostream>
#include <array>
#include <string>

const int mazeSize = 12;

std::array<char, mazeSize> removeSpaces(std::string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());

    std::array<char, mazeSize> arr = {};

    for (int i = 0; i < mazeSize; i++) {
        arr[i] = str[i];
    }

    return arr;
}

int main(void) {
    // Code goes here

    

    std::array<std::array<char, mazeSize>, mazeSize> maze = {
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

    for (int i = 0; i < mazeSize; i++) {
        for (int j = 0; j < mazeSize; j++) {
            std::cout << maze[i][j];
        }
        std::cout << std::endl;
    }

    

    return 0;
}