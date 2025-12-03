#ifndef UTILS_H
#define UTILS_H

/* ------------------- Clear Screen ------------------------- */
/**
 * Input: None
 * Output: Clears the terminal screen
 * Approach:
 *   - Executes platform-dependent system command ("cls" on Windows)
 * Side Effects:
 *   - Clears the console window
 */
void clearScreen();

/* ------------------- Random Index ------------------------- */
/**
 * Input: None
 * Output: Returns a random integer between 0 and 3
 * Approach:
 *   - Uses rand() function modulo 4
 * Side Effects:
 *   - None
 */
int randomIndex();

/* ------------------- New Tile Value ------------------------- */
/**
 * Input: None
 * Output: Returns 2 (90% chance) or 4 (10% chance)
 * Approach:
 *   - Uses rand() % 10 to generate probability
 * Side Effects:
 *   - None
 */
int newTileValue();

#endif
