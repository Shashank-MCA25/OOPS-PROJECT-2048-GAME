#ifndef BOARD_H
#define BOARD_H

/**
 * @class Board
 * @brief Represents the 4×4 grid and all core game logic for 2048.
 *
 * Input: Player moves via Game class (W/A/S/D)
 * Output: Tile positions, score, and steps displayed in terminal
 * Approach:
 *   - Maintains internal 4×4 grid
 *   - Handles tile generation, sliding, and merging logic
 *   - Tracks score and steps
 * Side Effects:
 *   - Modifies grid, score, and steps
 */
class Board {
public:
    /**
     * @brief Constructs a new Board object.
     * Input: None
     * Output: Initializes empty grid, score = 0, steps = 0, and adds two tiles
     * Approach: Fill grid with 0, then addRandomTile() twice
     * Side Effects: Updates grid state
     */
    Board();

    /**
     * @brief Displays the current board including score and steps
     * Input: None
     * Output: Prints board to console
     * Approach: Formats tiles with spacing, draws frame
     * Side Effects: Writes to terminal
     */
    void display() const;

    /**
     * @brief Adds a new random tile (2 or 4) in an empty cell
     * Input: None
     * Output: New tile appears in grid
     * Approach: Randomly select empty position; assign 2 (90%) or 4 (10%)
     * Side Effects: Modifies grid
     */
    void addRandomTile();

    /**
     * @brief Checks if the player has won
     * Input: None
     * Output: Returns true if 2048 exists
     * Approach: Scan all tiles
     * Side Effects: None
     */
    bool hasWon() const;

    /**
     * @brief Checks if no moves are left (game over)
     * Input: None
     * Output: Returns true if game over
     * Approach: Check empty cells and adjacent equal tiles
     * Side Effects: None
     */
    bool isGameOver() const;

    /* ---------------- Movement Functions ---------------- */

    void moveLeft();   ///< Input: None, Output: board moves left, Side Effects: grid, score, steps
    void moveRight();  ///< Moves right
    void moveUp();     ///< Moves up
    void moveDown();   ///< Moves down

private:
    int grid[4][4]; ///< Stores tile values
    int score;      ///< Tracks score
    int steps;      ///< Tracks moves

    /* ---------------- Internal Helpers ---------------- */

    void mergeLeft();   ///< Merges tiles left
    void slideLeft();   ///< Slides tiles left
    void mergeRight();  ///< Merges tiles right
    void slideRight();  ///< Slides tiles right
    void mergeUp();     ///< Merges tiles up
    void slideUp();     ///< Slides tiles up
    void mergeDown();   ///< Merges tiles down
    void slideDown();   ///< Slides tiles down
    bool hasEmptyCell() const; ///< Checks for empty tiles
};

#endif // BOARD_H
