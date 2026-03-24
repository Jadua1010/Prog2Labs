

#include "pacman.h"
#include "GameObjectStruct.hpp"
#include <vector>
#include "UI.hpp"
#include <iostream>

// Initialize function for PACMAN
Pacman::Pacman(int _x, int _y, Type _type, Direction _direction, std::vector<std::vector<int>>* _map, UI* _ui) :
	map(_map),
	 ui(_ui)
{
	this->x = _x;
	this->y = _y;
	this->type = _type;
	this->dir = _direction;
}

// Private function variant of the one with direction for easy check for its own direction
int Pacman::GetNextTile() {
	return Pacman::GetNextTile(this->dir);
}

// Private function purely to simplify wall detection for other functions
int Pacman::GetNextTile(Direction direction) {
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
/// If an arrowkey is pressed, Change direction if there is no wall.
/// Otherwise it saves it as a last attempt for easier movement
/// </summary>
/// <param name="_direction">The desired direction</param>
void Pacman::ChangeMovement(Direction _direction) {
	
	// Gets the tile for that direction
	int nexTile = GetNextTile(_direction);

	// If valid, DO IT
	if (nexTile != WALL_TILE) {
		dir = _direction;
		recentRotateAttempt = NONE;
	}
	else
		recentRotateAttempt = _direction;
}

/// <summary>
/// Try to make a move every gameupdate 
/// so that the Pacman continuously moves, just like the game itself
/// </summary>
void Pacman::Move() {

	// Teleporting requires the knowledge of the edges of x
	const int maxX = map->begin()->size();

	// Get the tile in front of pacman
	int nexTile = GetNextTile();

	if (nexTile == WALL_TILE)
		return; // WALL, so dont move into it


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


	if (map->at(y).at(x) == SNACK_TILE) {
		ui->addScore(1);
		(*map)[y][x] = PATH_TILE;           // ← remove dot
		ui->setMap(*map);
	}


	// Try to rotate to the last failed rotation for easier movement
	if (recentRotateAttempt != NONE) 
		ChangeMovement(recentRotateAttempt);
}