#include "include/Game.h"
#include <ctime>
#include <cstdlib>

/*
 * Entry point of the 2048 game.
 * Seeds the random generator and starts the game loop.
 */
int main() {
    srand((unsigned)time(NULL));   // Initialize RNG
    
    Game game;
    game.start();                  // Launch the main game loop
    
    return 0;
}
