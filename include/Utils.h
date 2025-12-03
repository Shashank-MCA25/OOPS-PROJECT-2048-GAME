#ifndef UTILS_H
#define UTILS_H

/**
 * @brief Clears the terminal screen (platform-dependent).
 */
void clearScreen();

/**
 * @brief Returns a random index between 0 and 3 for board operations.
 */
int randomIndex();

/**
 * @brief Returns a new tile value (2 or 4), usually with 90/10 probability.
 */
int newTileValue();

#endif
