

#include "Ghost.h"
#include "GameObjectStruct.hpp"
#include <vector>
#include "UI.hpp"
#include <iostream>
#include <random>

// Initialize function for PACMAN
Ghost::Ghost(int _x, int _y, Type _type, Direction _direction, std::vector<std::vector<int>>* _map, UI* _ui) :
	map(_map),
	 ui(_ui)
{
	this->x = _x;
	this->y = _y;
	this->type = _type;
	this->dir = _direction;
}

// Private function variant of the one with direction for easy check for its own direction
int Ghost::GetNextTile() {
	return Ghost::GetNextTile(this->dir);
}

// Private function purely to simplify wall detection for other functions
int Ghost::GetNextTile(Direction direction) {
	int value = 0;
	const int maxY = map->size();
	const int maxX = map->begin()->size();

	/*std::cout << "Max x: " << maxX << "     Max y: " << maxY << "\n";
	std::cout << "current x: " << x << "     current y: " << y << "\n";*/

	switch (direction) {
	case LEFT:
		if (x == 0)
			value = MAP_EDGE;
		else
			value = map->at(y).at(x - 1);
		break;
	case RIGHT:
		if (x == maxX - 1)
			value = MAP_EDGE;
		else
			value = map->at(y).at(x + 1);
		break;
	case UP:
		if (y == 0)
			value = MAP_EDGE;
		else
			value = map->at(y - 1).at(x);
		break;
	case DOWN:
		if (y == maxY - 1)
			value = MAP_EDGE;
		else
			value = map->at(y + 1).at(x);
		break;
	}

	return value;
}

/// <summary>
/// The path of Ghosts is determined randomly at crossings.
/// On straights, the ghost contiues its path
/// </summary>
void Ghost::ChangeMovement() {
	
	int oppositeDirection;

	switch (dir) {
	case LEFT:
		oppositeDirection = RIGHT;
		break;
	case RIGHT:
		oppositeDirection = LEFT;
		break;
	case UP:
		oppositeDirection = DOWN;
		break;
	case DOWN:
		oppositeDirection = UP;
		break;

	}


	int tiles[4];

	int possibilities = 0;

	for (int i = 0; i < 4; i++) {
		tiles[i] = GetNextTile((Direction)i);

		if (tiles[i] != WALL_TILE && oppositeDirection != i)
			possibilities++;
	}

	// Only one is possible, so it must move to there
	if (possibilities == 0) {
		for (int i = 0; i < 4; i++) {
			if (tiles[i] != WALL_TILE) {
				dir = (Direction)i;
				return;
			}
		}
	}

	int pathNumber = std::rand() % possibilities;

	for (int i = 0; i < 4; i++) {
		if (tiles[i] == WALL_TILE || oppositeDirection == i)
			continue;

		if (pathNumber == 0) {
			dir = (Direction)i;
			return;
		}
		else
			pathNumber--;
	}

}

/// <summary>
/// Make a move every gameupdate 
/// so that the Ghost continuously moves, just like the game itself
/// </summary>
void Ghost::Move() {

	// Teleporting requires the knowledge of the edges of x
	const int maxX = map->begin()->size();

	ChangeMovement();

	int nexTile = GetNextTile();

	// Moving Pacman is dependend on its direction
	switch (this->dir) {
	case LEFT:
		if (nexTile == MAP_EDGE) // These checks only have to be done at the x directions, since they only have teleporting options
			x = maxX - 1;
		else
			x--;
		break;
	case RIGHT:
		if (nexTile == MAP_EDGE)
			x = 0;
		else
			x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
}