//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 2
//=====================...........................=================================

#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <tuple>
#include <chrono>
#include <thread>


const int mazeSize = 12;
std::array<std::array<char, mazeSize>, mazeSize> maze;

enum Direction {
    LEFT,
    UP,
    RIGHT,
    DOWN
};

Direction CurrentDirection = LEFT;
std::tuple<int, int> CurrentPosition;


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

//Separate print maze function
int printmaz(void) {
    for (int i = 0; i < mazeSize; i++) {
        for (int j = 0; j < mazeSize; j++) {
            std::cout << maze[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

bool CheckPosition(Direction direction) {
    char theChar = 'q';
    switch (direction) {
        case (UP):
            theChar = maze[get<0>(CurrentPosition) - 1][get<1>(CurrentPosition)];
            if (theChar == 'x' || theChar == '.')
                return 1;
            break;
        case (DOWN):
            theChar = maze[get<0>(CurrentPosition) + 1][get<1>(CurrentPosition)];
            if (theChar == 'x' || theChar == '.')
                return 1;
            break;
        case (LEFT):
            theChar = maze[get<0>(CurrentPosition)][get<1>(CurrentPosition) - 1];
            if (theChar == 'x' || theChar == '.')
                return 1;
            break;
        case (RIGHT):
            theChar = maze[get<0>(CurrentPosition)][get<1>(CurrentPosition) + 1];
            if (theChar == 'x' || theChar == '.')
                return 1;
            break;

    }
    return 0;
}


bool traverseMaze() {

    switch (CurrentDirection) {
        case (LEFT): 
            if (CheckPosition(UP)) {
                get<0>(CurrentPosition) = get<0>(CurrentPosition) - 1;
                maze[get<0>(CurrentPosition)][get<1>(CurrentPosition)] = 'x';

                CurrentDirection = UP;
            }
            else if (CheckPosition(LEFT)) {
                get<1>(CurrentPosition) = get<1>(CurrentPosition) - 1;
                maze[get<0>(CurrentPosition)][get<1>(CurrentPosition)] = 'x';

                CurrentDirection = LEFT;
            }
            else if (CheckPosition(DOWN)) {
                get<0>(CurrentPosition) = get<0>(CurrentPosition) + 1;
                maze[get<0>(CurrentPosition)][get<1>(CurrentPosition)] = 'x';

                CurrentDirection = DOWN;
            }
            else {
                get<1>(CurrentPosition) = get<1>(CurrentPosition) + 1;
                maze[get<0>(CurrentPosition)][get<1>(CurrentPosition)] = 'x';

                CurrentDirection = RIGHT;
            }
            break;

        case (UP): 
            if (CheckPosition(RIGHT)) {
                get<1>(CurrentPosition) = get<1>(CurrentPosition) + 1;
                maze[get<0>(CurrentPosition)][get<1>(CurrentPosition)] = 'x';

                CurrentDirection = RIGHT;
            }
            else if (CheckPosition(UP)) {
                get<0>(CurrentPosition) = get<0>(CurrentPosition) - 1;
                maze[get<0>(CurrentPosition)][get<1>(CurrentPosition)] = 'x';

                CurrentDirection = UP;
            }
            else if (CheckPosition(LEFT)) {
                get<1>(CurrentPosition) = get<1>(CurrentPosition) - 1;
                maze[get<0>(CurrentPosition)][get<1>(CurrentPosition)] = 'x';

                CurrentDirection = LEFT;
            }
            else {
                get<0>(CurrentPosition) = get<0>(CurrentPosition) + 1;
                maze[get<0>(CurrentPosition)][get<1>(CurrentPosition)] = 'x';

                CurrentDirection = DOWN;
            }
            break;

        case (RIGHT): 
            if (CheckPosition(DOWN)) {
                get<0>(CurrentPosition) = get<0>(CurrentPosition) + 1;
                maze[get<0>(CurrentPosition)][get<1>(CurrentPosition)] = 'x';

                CurrentDirection = DOWN;
            }
            else if (CheckPosition(RIGHT)) {
                get<1>(CurrentPosition) = get<1>(CurrentPosition) + 1;
                maze[get<0>(CurrentPosition)][get<1>(CurrentPosition)] = 'x';

                CurrentDirection = RIGHT;
            }
            else if (CheckPosition(UP)) {
                get<0>(CurrentPosition) = get<0>(CurrentPosition) - 1;
                maze[get<0>(CurrentPosition)][get<1>(CurrentPosition)] = 'x';

                CurrentDirection = UP;
            }
            else {
                get<1>(CurrentPosition) = get<1>(CurrentPosition) - 1;
                maze[get<0>(CurrentPosition)][get<1>(CurrentPosition)] = 'x';

                CurrentDirection = LEFT;
            }
            break;

        case (DOWN): 
            if (CheckPosition(LEFT)) {
                get<1>(CurrentPosition) = get<1>(CurrentPosition) - 1;
                maze[get<0>(CurrentPosition)][get<1>(CurrentPosition)] = 'x';

                CurrentDirection = LEFT;
            }
            else if (CheckPosition(DOWN)) {
                get<0>(CurrentPosition) = get<0>(CurrentPosition) + 1;
                maze[get<0>(CurrentPosition)][get<1>(CurrentPosition)] = 'x';

                CurrentDirection = DOWN;
            }
            else if (CheckPosition(RIGHT)) {
                get<1>(CurrentPosition) = get<1>(CurrentPosition) + 1;
                maze[get<0>(CurrentPosition)][get<1>(CurrentPosition)] = 'x';

                CurrentDirection = RIGHT;
            }
            else {
                get<0>(CurrentPosition) = get<0>(CurrentPosition) - 1;
                maze[get<0>(CurrentPosition)][get<1>(CurrentPosition)] = 'x';

                CurrentDirection = UP;
            }
            break;


    }

    printmaz();

    if (get<0>(CurrentPosition) == 0 || get<0>(CurrentPosition) == mazeSize - 1 || get<1>(CurrentPosition) == 0 || get<1>(CurrentPosition) == mazeSize - 1)
        return 1;

    return 0;
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

    printmaz();

    CurrentPosition = GetTheXPosition();

    bool isFinished = false;

    while (!isFinished) {
        isFinished = traverseMaze();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "that the maze is solved and exit the program." << std::endl;

    return 0;
}