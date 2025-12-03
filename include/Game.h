#ifndef GAME_H
#define GAME_H

#include "Board.h"

/**
 * @class Game
 * @brief Controls the main loop of the 2048 game.
 *
 * The Game class manages display, input, and overall game flow.
 * All tile movement and merging logic is handled by the Board class.
 */
class Game {
public:

    /**
     * @brief Starts and runs the main game loop.
     *
     * Handles:
     *  - Creating the Board
     *  - Displaying the grid
     *  - Reading user input
     *  - Triggering board movements
     *  - Checking win/loss conditions
     */
    void start();
};

#endif
