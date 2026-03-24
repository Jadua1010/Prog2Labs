
#ifndef GHOST_H
#define GHOST_H

#include "GameObjectStruct.hpp"
#include <vector>

class UI;

class Ghost : public GameObjectStruct
{
	// Use protected because we want these values to be accessible in derrived classes but NOT anywhere else
protected:

	// Use private since they only got to be accessed by Pacman functions itself
private:
	std::vector<std::vector<int>>* map;
	int GetNextTile();
	int GetNextTile(Direction dir);
	void ChangeMovement();
	Direction recentRotateAttempt = NONE;
	UI* ui;
public:
	// Init function
	Ghost(int x, int y, Type type, Direction direction, std::vector<std::vector<int>>* map, UI* ui);

	// Try to make a move every gameupdate
	void Move();
};


#endif //GHOST_H