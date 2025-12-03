#ifndef GAME_H
#define GAME_H

#include "Board.h"

/* ------------------- Game Class ------------------------- */
/**
 * @class Game
 * @brief Controls the main loop of the 2048 game.
 *
 * Input: None directly (takes user input during runtime)
 * Output: Displays the board, messages, and updates score/steps
 * Approach:
 *   - Uses Board class for grid and movement logic
 *   - Reads immediate key input (W/A/S/D/Q)
 *   - Checks win and game over conditions
 * Side Effects:
 *   - Updates Board tiles and score
 *   - Clears the terminal screen on each loop iteration
 */
class Game {
public:

    /* ------------------- Start Game Loop ------------------------- */
    /**
     * Input: None
     * Output: Runs the game until win/lose or player quits
     * Approach:
     *   - Creates Board object
     *   - Loops: clear screen → display → get input → move → check status
     * Side Effects:
     *   - Modifies board state
     *   - Updates score and steps
     *   - Prints to terminal
     */
    void start();
};

#endif
