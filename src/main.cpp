/// \file
/// main.cpp


#include "GameObjectStruct.hpp"
#include "UI.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include "Pacman.h"
#include "Ghost.h"
#include <iostream>
#include <cmath>
#include <random>
#include <utility>

// Pointers to be used in the game updates, initialized in the Main code.
std::vector<Ghost*> GhostPtrs;

constexpr int RESET_WALL_TICKS = 16;
constexpr int FRUIT_SPAWN_TICKS = 300;
int last_pac_x = 0;
int last_pac_y = 0;

/// <summary>
/// Function to initialize Map. Walls are colored wrong and this corrects that mistake
/// </summary>
/// <param name="map">The map as vectors of vectors of ints</param>
void FillMapWithWalls(std::vector<std::vector<int>>& map)
{
    for (auto& row : map) {
        for (int& tile : row) {
            tile = WALL_TILE;
        }
    }
}

// A struct to organise the pointers, could also has been done like GhostPtrs
struct GameState {
    Pacman* pacman;
    UI* ui;
    std::vector<std::vector<int>>* map;
    const std::vector<std::vector<int>>* originalMap;
    int resetWallTicksRemaining = 0;
    int ticksUntilFruitSpawn = FRUIT_SPAWN_TICKS;
};

/// Callback function to update the game state.
///
/// This function is called by an SDL timer at regular intervals.
/// Note that this callback may happen on a different thread than the main thread.
/// You therefore have to be careful in avoiding data races. For example, you
/// should use mutexes to access shared data.
/// Read the documentation of SDL_AddTimer for more information and for tips
/// regarding multithreading issues.

Uint32 gameUpdate(Uint32 interval, void* param)
{
    // Do game loop update here

    // Automatically set a step each gametick if its not a wall (and do at map edges)
    GameState* gameState = static_cast<GameState*>(param);
    Pacman* pacman = gameState->pacman;

    // During reset animation, keep walls up for a few ticks and then restore board.def map.
    if (gameState->resetWallTicksRemaining > 0) {
        gameState->resetWallTicksRemaining--;
        if (gameState->resetWallTicksRemaining == 0) {
            *gameState->map = *gameState->originalMap;
            gameState->ui->setMap(*gameState->map);
            gameState->ticksUntilFruitSpawn = FRUIT_SPAWN_TICKS;

            for (Ghost* ghost : GhostPtrs) {
                ghost->setState(GhostState::MOVING);
            }
        }
        
        return interval;
    }

    gameState->ticksUntilFruitSpawn--;
    if (gameState->ticksUntilFruitSpawn <= 0) {
        // Spawn a fruit and reset the counter
        gameState->ui->spawnFruit(*gameState->map); // You can change the fruit type as needed
        gameState->ticksUntilFruitSpawn = FRUIT_SPAWN_TICKS;
    }

    // Store last x and y (we need this for collision detection)
    last_pac_x = pacman->x;
    last_pac_y = pacman->y;
    pacman->Move();

    // When pacmans calls that its eaten a sneck.
    const EatType eaten = pacman->eatSnack();
    if (eaten != EatType::HUNGRY) {
        int scoreToAdd = 0;
        if (eaten == EatType::SNACK) {
            scoreToAdd = 10;
        }
        if (eaten == EatType::FRUIT) {
            scoreToAdd = 100;
        }
        else if (eaten == EatType::BIG_SNACK) {
            scoreToAdd = 50;
            for (Ghost* ghost : GhostPtrs) {
                ghost->setState(GhostState::RUNNING);
            }
        }

        gameState->ui->addScore(scoreToAdd);
        (*gameState->map)[pacman->y][pacman->x] = PATH_TILE;
        gameState->ui->setMap(*gameState->map);
    }

    bool pacmanEaten = false;
    for (Ghost* ghost : GhostPtrs) {
        // While we are at it, we can check if the ghost has now collided with a pacman

        // Check if the ghost is/is going to be in the same tile as pacmans
        if (ghost->x == pacman->x && ghost->y == pacman->y || (ghost->x == last_pac_x && ghost->y == last_pac_y)) {
            if (ghost->state == GhostState::RUNNING) {
                ghost->setState(GhostState::EATEN);
                gameState->ui->addScore(200); // Add score for eating a ghost
            }
            else if (ghost->state == GhostState::MOVING) {
                gameState->ui->addLives(-1); // Lose a life

                // Reset character positions.
                pacman->x = 1;
                pacman->y = 1;
                for (Ghost* resetGhost : GhostPtrs) {
                    // Basically works as a reset state
                    resetGhost->setState(GhostState::EATEN);
                }

                // Reset the score and lives if we dead
                if (gameState->ui->lives <= 0) {
                    gameState->ui->setScore(0);
                    gameState->ui->setLives(3);
                    // Fill map with walls to make it look very much like we ded
                    FillMapWithWalls(*gameState->map);
                    gameState->ui->setMap(*gameState->map);
                    // Wait for some ticks until we actually reset the map
                    gameState->resetWallTicksRemaining = RESET_WALL_TICKS;
                }
                pacmanEaten = true;
                break;
            }
        }
        else {
            ghost->Move();
        }
    }

    if (pacmanEaten) {
        return interval;
    }

    return interval;
}

/// Program entry point.
int main(int /*argc*/, char** /*argv*/)
{

    // Initialize Random with the time
    std::srand(time(NULL));

    // Init the map
    std::vector<std::vector<int>> map = { {
        #include "board.def"
    } };
    const std::vector<std::vector<int>> originalMap = map;

    // Create a new ui object
    UI ui(map); // <-- use map from your game objects.

    // Set the score
    ui.setScore(0); // <-- Pass correct value to the setter

    // Set the amount of lives
    ui.setLives(3); // <-- Pass correct value to the setter

    // Init a Pacman
    Pacman pacman(1, 1, PACMAN, UP, &map);
    GameState gameState = { &pacman, &ui, &map, &originalMap, 0, FRUIT_SPAWN_TICKS };


    // Init the ghosts and get their positions relative to the map size
    const int firstXPosition = floor(map.front().size() / 2.0) - 2;
    const int ghostYPosition = floor(map.size() / 2.0);

    Ghost inky(firstXPosition, ghostYPosition, INKY, RIGHT, &map, &ui);
    Ghost pinky(firstXPosition + 1, ghostYPosition, PINKY, UP, &map, &ui);
    Ghost blinky(firstXPosition + 2, ghostYPosition, BLINKY, UP, &map, &ui);
    Ghost clyde(firstXPosition + 3, ghostYPosition, CLYDE, LEFT, &map, &ui);


    // Fill in all the objects 

    GhostPtrs.push_back(&inky);
    GhostPtrs.push_back(&pinky);
    GhostPtrs.push_back(&blinky);
    GhostPtrs.push_back(&clyde);


    // Start timer for game update, call this function every 150 ms. with the objects pointer
    SDL_TimerID timer_id =
        SDL_AddTimer(150, gameUpdate, &gameState);


    // Call game init code here


    bool quit = false;
    while (!quit) {
        // set timeout to limit frame rate
        Uint32 timeout = SDL_GetTicks() + 20;

        // Handle the input
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            // Quit button.
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            // All keydown events. On movement keys, run the change movement function of pacman.
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                case SDLK_LEFT:
                    pacman.ChangeMovement(LEFT);
                    break;
                case SDLK_RIGHT:
                    pacman.ChangeMovement(RIGHT);
                    break;
                case SDLK_UP:
                    pacman.ChangeMovement(UP);
                    break;
                case SDLK_DOWN:
                    pacman.ChangeMovement(DOWN);
                    break;
                case SDLK_ESCAPE:
                    quit = true;
                    break;
                }
            }
        }

        // Render the scene

        std::vector<GameObjectStruct> objects = { pacman, inky, pinky, blinky, clyde };

        // game->getStructs())
        ui.update(objects);

        while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
            // ... do work until timeout has elapsed
            //std::cout << "Tick" << std::endl;
            ui.update(objects);
        }
    }

    SDL_RemoveTimer(timer_id);

    return 0;
}
