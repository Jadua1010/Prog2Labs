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
#include <tuple>

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

std::tuple<int, int> GetTheXPosition() {
    for (int i = 0; i < mazeSize; i++) {
        for (int j = 0; j < mazeSize; j++) {
            if (maze[i][j] == 'x') {
                std::tuple<int, int> pairino(i, j);
                return pairino;
            }
        }
    }
}


int main(void) {
    // Code goes here

    

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

    for (int i = 0; i < mazeSize; i++) {
        for (int j = 0; j < mazeSize; j++) {
            std::cout << maze[i][j];
        }
        std::cout << std::endl;
    }

    std::tuple<int, int> positionOfTheX = GetTheXPosition();

    std::cout << get<0>(positionOfTheX) << ", " << get<1>(positionOfTheX) << std::endl;

    return 0;
}