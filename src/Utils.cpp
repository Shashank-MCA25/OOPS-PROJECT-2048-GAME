#include "../include/Utils.h"
#include <cstdlib>

/*
 * Clears the console screen.
 * Uses "cls" for Windows terminals.
 */
void clearScreen() {
    system("cls");
}

/*
 * Returns a random index between 0 and 3.
 * Used for selecting random board positions.
 */
int randomIndex() {
    return rand() % 4;
}

/*
 * Returns a new tile value.
 *  - 90% chance: 2
 *  - 10% chance: 4
 */
int newTileValue() {
    return (rand() % 10 == 0) ? 4 : 2;
}
