
#ifndef GHOST_H
#define GHOST_H

#include "GameObjectStruct.hpp"
#include <vector>
#include "GhostState.h"

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

	Type originalType; // Store the ghost's normal sprite type for restoring after RUNNING
	int moveTickCounter = 0; // Ensure we can change speed
	int scaredTickCounter = 0; // Ensure we can change back from scared after a while

	// Here we define different speeds for the gost
	int moveTickSpeed = 1; // For movement, same as pacman
	int runningTickSpeed = 2; // For running, half the speed
	int eatenTickSpeed = 1; // For eaten, same as pacman

public:
	// Init function
	Ghost(int x, int y, Type type, Direction direction, std::vector<std::vector<int>>* map, UI* ui);

	GhostState state = GhostState::MOVING; // Default state


	// Function to change the state of the ghost
	void setState(GhostState newState);

	// Try to make a move every gameupdate
	void Move();
};


#endif //GHOST_H