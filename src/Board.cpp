#include "../include/Board.h"
#include "../include/Utils.h"
#include <iostream>
#include <algorithm>

using namespace std;

/* ------------------- Board Constructor ------------------------- */
/**
 * Input: None
 * Output: Initializes a 4x4 grid
 * Approach: Sets all tiles to 0 and adds 2 random tiles
 * Side Effects: Modifies internal grid, score, and steps
 */
Board::Board() {
    score = 0;
    steps = 0;

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            grid[i][j] = 0;

    addRandomTile();
    addRandomTile();
}

/* ------------------- Display Board ------------------------- */
/**
 * Input: None
 * Output: Prints the board, score, and steps to console
 * Approach: Loops through grid and formats numbers
 * Side Effects: None (read-only)
 */
void Board::display() const {
    cout << "##################\n";
    cout << "#    2048 GAME   #\n";
    cout << "##################\n";
    cout << "Score: " << score << " | Steps: " << steps << "\n\n";

    for(int i = 0; i < 4; i++){
        cout << "|-----------------------|\n";
        for(int j = 0; j < 4; j++){
            cout << "|";
            int v = grid[i][j];

            if(v == 0) cout << "     ";
            else if(v < 10) cout << "  " << v << "  ";
            else if(v < 100) cout << "  " << v << " ";
            else if(v < 1000) cout << " " << v << " ";
            else cout << " " << v;
        }
        cout << "|\n";
    }
    cout << "|-----------------------|\n";
}

/* ------------------- Add Random Tile ------------------------- */
/**
 * Input: None
 * Output: Adds 2 or 4 in a random empty tile
 * Approach: Uses randomIndex() and newTileValue() until empty cell found
 * Side Effects: Modifies grid by adding a new tile
 */
void Board::addRandomTile() {
    while(true){
        int r = randomIndex();
        int c = randomIndex();
        if(grid[r][c] == 0){
            grid[r][c] = newTileValue();
            break;
        }
    }
}

/* ------------------- Check Win ------------------------- */
/**
 * Input: None
 * Output: Returns true if any tile is 2048
 * Approach: Loops through grid to find 2048
 * Side Effects: None
 */
bool Board::hasWon() const {
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(grid[i][j] == 2048)
                return true;
    return false;
}

/* ------------------- Check Empty Cell ------------------------- */
/**
 * Input: None
 * Output: Returns true if any tile is 0
 * Approach: Loops through grid
 * Side Effects: None
 */
bool Board::hasEmptyCell() const {
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(grid[i][j] == 0)
                return true;
    return false;
}

/* ------------------- Check Game Over ------------------------- */
/**
 * Input: None
 * Output: Returns true if no moves left
 * Approach: Checks for empty cells or possible merges horizontally/vertically
 * Side Effects: None
 */
bool Board::isGameOver() const {
    if(hasEmptyCell()) return false;
    //checks for merging/sliding in horizontal
    for(int i = 0; i < 4; i++)
    for(int j = 0; j < 3; j++)
    if(grid[i][j] == grid[i][j+1])
    return false;
    
    //checks for merging/sliding in vertical
    for(int j = 0; j < 4; j++)
        for(int i = 0; i < 3; i++)
            if(grid[i][j] == grid[i+1][j])
                return false;

    return true;
}

/* ------------------- Merge Left ------------------------- */
/**
 * Input: None
 * Output: Merges adjacent tiles left
 * Approach: Scan each row, combine equal tiles, track last merge to prevent double-merge
 * Side Effects: Modifies grid and score
 */
void Board::mergeLeft() {
    for(int i = 0; i < 4; i++){
        int lastMerge = -1;
        for(int j = 1; j < 4; j++){
            if(grid[i][j] == 0) continue;
            for(int k = j - 1; k >= 0; k--){
                if(grid[i][k] != 0){
                    if(grid[i][k] == grid[i][j] && lastMerge != k){
                        grid[i][k] *= 2;
                        score += grid[i][k];
                        grid[i][j] = 0;
                        lastMerge = k;
                    }
                    break;
                }
            }
        }
    }
}

/* ------------------- Slide Left ------------------------- */
/**
 * Input: None
 * Output: Moves all tiles left filling empty spaces
 * Approach: Loops through each row and swaps zeros with non-zero tiles
 * Side Effects: Modifies grid
 */
void Board::slideLeft() {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i][j] == 0){
                for(int k = j + 1; k < 4; k++){
                    if(grid[i][k] != 0){
                        swap(grid[i][j], grid[i][k]);
                        break;
                    }
                }
            }
        }
    }
}

/* ------------------- Move Left ------------------------- */
/**
 * Input: None
 * Output: Executes full left move
 * Approach: mergeLeft() + slideLeft() + increment steps + addRandomTile()
 * Side Effects: Modifies grid, score, and steps
 */
void Board::moveLeft() {
    mergeLeft();
    slideLeft();
    steps++;
    addRandomTile();
}

/* ------------------- Merge Right ------------------------- */
/**
 * Input: None
 * Output: Merges adjacent tiles right
 * Approach: Similar to mergeLeft but scans rightwards
 * Side Effects: Modifies grid and score
 */
void Board::mergeRight() {
    for(int i = 0; i < 4; i++){
        int lastMerge = -1;
        for(int j = 2; j >= 0; j--){
            if(grid[i][j] == 0) continue;
            for(int k = j + 1; k < 4; k++){
                if(grid[i][k] != 0){
                    if(grid[i][k] == grid[i][j] && lastMerge != k){
                        grid[i][k] *= 2;
                        score += grid[i][k];
                        grid[i][j] = 0;
                        lastMerge = k;
                    }
                    break;
                }
            }
        }
    }
}

/* ------------------- Slide Right ------------------------- */
/**
 * Input: None
 * Output: Moves tiles right filling empty spaces
 * Approach: Loops rows rightwards, swapping zeros with non-zero tiles
 * Side Effects: Modifies grid
 */
void Board::slideRight() {
    for(int i = 0; i < 4; i++){
        for(int j = 3; j > 0; j--){
            if(grid[i][j] == 0){
                for(int k = j - 1; k >= 0; k--){
                    if(grid[i][k] != 0){
                        swap(grid[i][j], grid[i][k]);
                        break;
                    }
                }
            }
        }
    }
}

/* ------------------- Move Right ------------------------- */
/**
 * Input: None
 * Output: Executes full right move
 * Approach: mergeRight() + slideRight() + increment steps + addRandomTile()
 * Side Effects: Modifies grid, score, and steps
 */
void Board::moveRight() {
    mergeRight();
    slideRight();
    steps++;
    addRandomTile();
}

/* ------------------- Merge Up ------------------------- */
/**
 * Input: None
 * Output: Merges tiles upward
 * Approach: Similar to mergeLeft but scans columns upwards
 * Side Effects: Modifies grid and score
 */
void Board::mergeUp() {
    for(int j = 0; j < 4; j++){
        int lastMerge = -1;
        for(int i = 1; i < 4; i++){
            if(grid[i][j] == 0) continue;
            for(int k = i - 1; k >= 0; k--){
                if(grid[k][j] != 0){
                    if(grid[k][j] == grid[i][j] && lastMerge != k){
                        grid[k][j] *= 2;
                        score += grid[k][j];
                        grid[i][j] = 0;
                        lastMerge = k;
                    }
                    break;
                }
            }
        }
    }
}

/* ------------------- Slide Up ------------------------- */
/**
 * Input: None
 * Output: Slides tiles upward filling empty cells
 * Approach: Loops columns and swaps zeros with non-zero tiles below
 * Side Effects: Modifies grid
 */
void Board::slideUp() {
    for(int j = 0; j < 4; j++){
        for(int i = 0; i < 3; i++){
            if(grid[i][j] == 0){
                for(int k = i + 1; k < 4; k++){
                    if(grid[k][j] != 0){
                        swap(grid[i][j], grid[k][j]);
                        break;
                    }
                }
            }
        }
    }
}

/* ------------------- Move Up ------------------------- */
/**
 * Input: None
 * Output: Executes full up move
 * Approach: mergeUp() + slideUp() + increment steps + addRandomTile()
 * Side Effects: Modifies grid, score, and steps
 */
void Board::moveUp() {
    mergeUp();
    slideUp();
    steps++;
    addRandomTile();
}

/* ------------------- Merge Down ------------------------- */
/**
 * Input: None
 * Output: Merges tiles downward
 * Approach: Similar to mergeUp but scans bottom to top
 * Side Effects: Modifies grid and score
 */
void Board::mergeDown() {
    for(int j = 0; j < 4; j++){
        int lastMerge = -1;
        for(int i = 2; i >= 0; i--){
            if(grid[i][j] == 0) continue;
            for(int k = i + 1; k < 4; k++){
                if(grid[k][j] != 0){
                    if(grid[k][j] == grid[i][j] && lastMerge != k){
                        grid[k][j] *= 2;
                        score += grid[k][j];
                        grid[i][j] = 0;
                        lastMerge = k;
                    }
                    break;
                }
            }
        }
    }
}

/* ------------------- Slide Down ------------------------- */
/**
 * Input: None
 * Output: Slides tiles downward filling empty cells
 * Approach: Loops columns bottom to top, swapping zeros with tiles above
 * Side Effects: Modifies grid
 */
void Board::slideDown() {
    for(int j = 0; j < 4; j++){
        for(int i = 3; i > 0; i--){
            if(grid[i][j] == 0){
                for(int k = i - 1; k >= 0; k--){
                    if(grid[k][j] != 0){
                        swap(grid[i][j], grid[k][j]);
                        break;
                    }
                }
            }
        }
    }
}

/* ------------------- Move Down ------------------------- */
/**
 * Input: None
 * Output: Executes full down move
 * Approach: mergeDown() + slideDown() + increment steps + addRandomTile()
 * Side Effects: Modifies grid, score, and steps
 */
void Board::moveDown() {
    mergeDown();
    slideDown();
    steps++;
    addRandomTile();
}
