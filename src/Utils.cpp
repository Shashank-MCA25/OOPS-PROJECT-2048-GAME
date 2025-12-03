#include "../include/Utils.h"
#include <cstdlib>

/* ------------------- Clear Screen ------------------------- */
/**
 * Input: None
 * Output: Clears the console screen
 * Approach:
 *   - Executes system command "cls" on Windows
 * Side Effects:
 *   - Clears the terminal window
 */
void clearScreen() {
    system("cls");
}

/* ------------------- Random Index ------------------------- */
/**
 * Input: None
 * Output: Returns a random integer between 0 and 3
 * Approach:
 *   - Uses rand() % 4 to select a valid board index
 * Side Effects:
 *   - None
 */
int randomIndex() {
    return rand() % 4;
}

/* ------------------- New Tile Value ------------------------- */
/**
 * Input: None
 * Output: Returns 2 (90% chance) or 4 (10% chance)
 * Approach:
 *   - Uses rand() % 10 to implement probability
 * Side Effects:
 *   - None
 */
int newTileValue() {
    return (rand() % 10 == 0) ? 4 : 2;
}
