#pragma once

#include <array>

const int mazeSize = 12;

extern std::array<std::array<char, mazeSize>, mazeSize> maze;

int RunProgram();	