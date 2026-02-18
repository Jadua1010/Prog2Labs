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
#include <tuple>
#include <chrono>
#include <thread>
#include <algorithm>

// In this case we use a square 12x12 maze defined globally
const int mazeSize = 12;
std::array<std::array<char, mazeSize>, mazeSize> maze;
std::tuple<int, int> CurrentPosition;

// Setup ENUM for all 4 possible directions
enum Direction {
    LEFT,
    UP,
    RIGHT,
    DOWN
};

// Move left initially
Direction CurrentDirection = LEFT;

// Function to enable easy input of the maze
std::array<char, mazeSize> removeSpaces(std::string str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());

    std::array<char, mazeSize> arr = {};

    for (int i = 0; i < mazeSize; i++) {
        arr[i] = str[i];
    }

    return arr;
}

// Function to find the position of the x
std::tuple<int, int> GetTheXPosition() {

    // Check each column and each row
    for (int i = 0; i < mazeSize; i++) {
        for (int j = 0; j < mazeSize; j++) {
            if (maze[i][j] == 'x') {
                std::tuple<int, int> pairino(i, j);
                return pairino;
            }
        }
    }
    return {-1, -1};
}

// Separate print maze function, makes it easy to call a lot of times
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

// Function to check position in terms of where X is and the direction it wants to go
bool CheckPosition(Direction direction) {
    char theChar = 'q';
    switch (direction) {
        case (UP):
            theChar = maze[std::get<0>(CurrentPosition) - 1][std::get<1>(CurrentPosition)];
            if (theChar == 'x' || theChar == '.')
                return 1;
            break;
        case (DOWN):
            theChar = maze[std::get<0>(CurrentPosition) + 1][std::get<1>(CurrentPosition)];
            if (theChar == 'x' || theChar == '.')
                return 1;
            break;
        case (LEFT):
            theChar = maze[std::get<0>(CurrentPosition)][std::get<1>(CurrentPosition) - 1];
            if (theChar == 'x' || theChar == '.')
                return 1;
            break;
        case (RIGHT):
            theChar = maze[std::get<0>(CurrentPosition)][std::get<1>(CurrentPosition) + 1];
            if (theChar == 'x' || theChar == '.')
                return 1;
            break;

    }
    // This should never be returned unless the maze is broken
    return 0;
}

// Function to transverse maze based on priority, first turn left, check forward, turn right, turn around
bool traverseMaze() {

    switch (CurrentDirection) {
        case (LEFT):
            if (CheckPosition(UP)) {
                std::get<0>(CurrentPosition) = std::get<0>(CurrentPosition) - 1;
                maze[std::get<0>(CurrentPosition)][std::get<1>(CurrentPosition)] = 'x';

                CurrentDirection = UP;
            }
            else if (CheckPosition(LEFT)) {
                std::get<1>(CurrentPosition) = std::get<1>(CurrentPosition) - 1;
                maze[std::get<0>(CurrentPosition)][std::get<1>(CurrentPosition)] = 'x';

                CurrentDirection = LEFT;
            }
            else if (CheckPosition(DOWN)) {
                std::get<0>(CurrentPosition) = std::get<0>(CurrentPosition) + 1;
                maze[std::get<0>(CurrentPosition)][std::get<1>(CurrentPosition)] = 'x';

                CurrentDirection = DOWN;
            }
            else {
                std::get<1>(CurrentPosition) = std::get<1>(CurrentPosition) + 1;
                maze[std::get<0>(CurrentPosition)][std::get<1>(CurrentPosition)] = 'x';

                CurrentDirection = RIGHT;
            }
            break;

        case (UP):
            if (CheckPosition(RIGHT)) {
                std::get<1>(CurrentPosition) = std::get<1>(CurrentPosition) + 1;
                maze[std::get<0>(CurrentPosition)][std::get<1>(CurrentPosition)] = 'x';

                CurrentDirection = RIGHT;
            }
            else if (CheckPosition(UP)) {
                std::get<0>(CurrentPosition) = std::get<0>(CurrentPosition) - 1;
                maze[std::get<0>(CurrentPosition)][std::get<1>(CurrentPosition)] = 'x';

                CurrentDirection = UP;
            }
            else if (CheckPosition(LEFT)) {
                std::get<1>(CurrentPosition) = std::get<1>(CurrentPosition) - 1;
                maze[std::get<0>(CurrentPosition)][std::get<1>(CurrentPosition)] = 'x';

                CurrentDirection = LEFT;
            }
            else {
                std::get<0>(CurrentPosition) = std::get<0>(CurrentPosition) + 1;
                maze[std::get<0>(CurrentPosition)][std::get<1>(CurrentPosition)] = 'x';

                CurrentDirection = DOWN;
            }
            break;

        case (RIGHT):
            if (CheckPosition(DOWN)) {
                std::get<0>(CurrentPosition) = std::get<0>(CurrentPosition) + 1;
                maze[std::get<0>(CurrentPosition)][std::get<1>(CurrentPosition)] = 'x';

                CurrentDirection = DOWN;
            }
            else if (CheckPosition(RIGHT)) {
                std::get<1>(CurrentPosition) = std::get<1>(CurrentPosition) + 1;
                maze[std::get<0>(CurrentPosition)][std::get<1>(CurrentPosition)] = 'x';

                CurrentDirection = RIGHT;
            }
            else if (CheckPosition(UP)) {
                std::get<0>(CurrentPosition) = std::get<0>(CurrentPosition) - 1;
                maze[std::get<0>(CurrentPosition)][std::get<1>(CurrentPosition)] = 'x';

                CurrentDirection = UP;
            }
            else {
                std::get<1>(CurrentPosition) = std::get<1>(CurrentPosition) - 1;
                maze[std::get<0>(CurrentPosition)][std::get<1>(CurrentPosition)] = 'x';

                CurrentDirection = LEFT;
            }
            break;

        case (DOWN):
            if (CheckPosition(LEFT)) {
                std::get<1>(CurrentPosition) = std::get<1>(CurrentPosition) - 1;
                maze[std::get<0>(CurrentPosition)][std::get<1>(CurrentPosition)] = 'x';

                CurrentDirection = LEFT;
            }
            else if (CheckPosition(DOWN)) {
                std::get<0>(CurrentPosition) = std::get<0>(CurrentPosition) + 1;
                maze[std::get<0>(CurrentPosition)][std::get<1>(CurrentPosition)] = 'x';

                CurrentDirection = DOWN;
            }
            else if (CheckPosition(RIGHT)) {
                std::get<1>(CurrentPosition) = std::get<1>(CurrentPosition) + 1;
                maze[std::get<0>(CurrentPosition)][std::get<1>(CurrentPosition)] = 'x';

                CurrentDirection = RIGHT;
            }
            else {
                std::get<0>(CurrentPosition) = std::get<0>(CurrentPosition) - 1;
                maze[std::get<0>(CurrentPosition)][std::get<1>(CurrentPosition)] = 'x';

                CurrentDirection = UP;
            }
            break;


    }

    // Print the maze as it currently is
    printmaz();

    // Check if we are at the final position (column 0)
    if (std::get<0>(CurrentPosition) == 0 || std::get<0>(CurrentPosition) == mazeSize - 1 || std::get<1>(CurrentPosition) == 0 || std::get<1>(CurrentPosition) == mazeSize - 1)
        return 1;

    return 0;
}

int main(void) {
    // Maze has input here

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

    //Intial printmaze
    printmaz();

    // Setup position
    CurrentPosition = GetTheXPosition();
    bool isFinished = false;
    int steps = 0;
    int sleepTime = 50;

    while (!isFinished) {
        isFinished = traverseMaze();
        steps++;
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));

        // Prevent infinite loop in broken mazes (~8 mins of solving at 50ms sleep)
        if (steps > 10000) {
            std::cout << "unsolvable maze detected" << std::endl;
            break;
        }
    }

    // The maze is finished
    std::cout << "after " << steps << " steps, the maze is solved and exit the program." << std::endl;

    return 0;
}