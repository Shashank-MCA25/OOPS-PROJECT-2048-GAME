#ifndef BOARD_H
#define BOARD_H

/**
 * @class Board
 * @brief Represents the 4×4 grid and all core game logic for 2048.
 *
 * The Board class manages:
 * - Internal 4×4 grid state
 * - Tile generation
 * - Sliding and merging mechanics
 * - Win and game-over detection
 * - Score and step counting
 *
 * It contains movement functions for all directions and utility functions
 * supporting merging, sliding, and checking game conditions.
 */
class Board {
public:
    /**
     * @brief Constructs a new Board object.
     * Initializes all tiles to zero, score to 0, steps to 0,
     * and spawns the first two initial tiles automatically
     * (in your Game.cpp implementation).
     */
    Board();

    /**
     * @brief Displays the current board, including score and steps.
     *
     * Handles formatting the grid and printing it to the console.
     */
    void display() const;

    /**
     * @brief Adds a new random tile (2 or 4) to a random empty position.
     *
     * Logic:
     * - 90% chance for value 2
     * - 10% chance for value 4
     */
    void addRandomTile();

    /**
     * @brief Checks if the player has reached the winning tile (2048).
     *
     * @return true If a tile equals 2048.
     * @return false Otherwise.
     */
    bool hasWon() const;

    /**
     * @brief Determines whether the game is over (no valid moves remain).
     *
     * Conditions for game over:
     * - No empty tiles.
     * - No horizontally or vertically adjacent equal tiles.
     *
     * @return true If no moves left.
     * @return false If at least one move is still possible.
     */
    bool isGameOver() const;

    /* ----------------------------------------------------------------------
       Movement Functions
       ---------------------------------------------------------------------- */

    /**
     * @brief Executes a LEFT move.
     *
     * Steps:
     * - Merge tiles to the left.
     * - Slide remaining tiles to the left.
     * - Add new random tile if at least one move happened.
     */
    void moveLeft();

    /**
     * @brief Executes a RIGHT move.
     */
    void moveRight();

    /**
     * @brief Executes an UP move.
     */
    void moveUp();

    /**
     * @brief Executes a DOWN move.
     */
    void moveDown();


private:
    /* ----------------------------------------------------------------------
       Private Member Variables
       ---------------------------------------------------------------------- */

    int grid[4][4]; ///< Main 4×4 game grid storing tile values.
    int score;      ///< Total score accumulated from merges.
    int steps;      ///< Number of moves made by the player.

    /* ----------------------------------------------------------------------
       Internal Helper Methods (Movement & Merging Logic)
       ---------------------------------------------------------------------- */

    /**
     * @brief Merges tiles towards LEFT direction.
     *
     * Merges only once per tile per move following 2048 rules.
     */
    void mergeLeft();

    /**
     * @brief Slides all tiles towards LEFT direction.
     */
    void slideLeft();

    /**
     * @brief Merges tiles towards RIGHT direction.
     */
    void mergeRight();

    /**
     * @brief Slides all tiles towards RIGHT direction.
     */
    void slideRight();

    /**
     * @brief Merges tiles upwards.
     */
    void mergeUp();

    /**
     * @brief Slides all tiles upwards.
     */
    void slideUp();

    /**
     * @brief Merges tiles downwards.
     */
    void mergeDown();

    /**
     * @brief Slides all tiles downwards.
     */
    void slideDown();

    /**
     * @brief Checks if at least one tile is empty (value == 0).
     *
     * @return true If an empty cell exists.
     * @return false If the grid is completely filled.
     */
    bool hasEmptyCell() const;
};

#endif // BOARD_H
