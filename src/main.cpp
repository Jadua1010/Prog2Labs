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

std::vector<Ghost*> GhostPtrs;

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
    Pacman* pacman = static_cast<Pacman*>(param);
    pacman->Move();

    for (Ghost* ghost : GhostPtrs)
        ghost->Move();

    return interval;
}

/// Program entry point.
int main(int /*argc*/, char** /*argv*/)
{
    std::srand(time(NULL));

    std::vector<std::vector<int>> map = { {
        #include "board.def"
    } };

    // Create a new ui object
    UI ui(map); // <-- use map from your game objects.

    // Set the score
    ui.setScore(0); // <-- Pass correct value to the setter

    // Set the amount of lives
    ui.setLives(3); // <-- Pass correct value to the setter

    // Init a Pacman
    Pacman pacman(1, 1, PACMAN, UP, &map, &ui);

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
        SDL_AddTimer(150, gameUpdate, &pacman);


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
