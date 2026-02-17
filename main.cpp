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
#include <algorithm>

const int mazeSize = 12;
std::array<std::array<char, mazeSize>, mazeSize> maze;

std::array<char, mazeSize> removeSpaces(std::string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());

    std::array<char, mazeSize> arr = {};

    for (int i = 0; i < mazeSize; i++) {
        arr[i] = str[i];
    }

    return arr;
}

std::pair<int, int> GetTheXPosition() {
    for (int i = 0; i < mazeSize; i++) {
        for (int j = 0; j < mazeSize; j++) {
            if (maze[i][j] == 'x')
                return std::pair<int, int>(i, j);
        }
    }
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

    std::pair<int, int> positionOfTheX = GetTheXPosition();

    std::cout << positionOfTheX.first << ", " << positionOfTheX.second << std::endl;

    return 0;
}