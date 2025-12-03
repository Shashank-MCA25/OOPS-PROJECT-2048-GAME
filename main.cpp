#include "include/Game.h"
#include <ctime>
#include <cstdlib>

/*
 * @brief Entry point of the 2048 game.
 *
 * Input: None
 * Output: Starts the game loop (displays board, handles moves)
 * Approach:
 *   - Seed random number generator
 *   - Instantiate Game object
 *   - Call Game::start() to run main loop
 * Side Effects:
 *   - Modifies terminal output
 *   - Changes internal board state during gameplay
 */
int main() {
    srand((unsigned)time(NULL));   // Initialize RNG for random tiles
    
    Game game;
    game.start();                  // Launch the main game loop
    
    return 0;
}
