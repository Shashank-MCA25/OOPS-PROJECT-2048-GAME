#include "../include/Board.h"
#include "../include/Utils.h"
#include <iostream>
#include <algorithm>

using namespace std;

Board::Board() {
    score = 0;
    steps = 0;

    // Initialize all tiles to empty (0)
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            grid[i][j] = 0;

    // Standard 2048 start: two tiles appear randomly
    addRandomTile();
    addRandomTile();
}

void Board::display() const {
    // Prints board frame, score, and tile values
    cout << "##################\n";
    cout << "#    2048 GAME   #\n";
    cout << "##################\n";
    cout << "Score: " << score << " | Steps: " << steps << "\n\n";

    for(int i = 0; i < 4; i++){
        cout << "|-----------------------|\n";
        for(int j = 0; j < 4; j++){
            cout << "|";
            int v = grid[i][j];

            // Align numbers for clean output
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

void Board::addRandomTile() {
    // Places a new tile (2 or 4) in a random empty cell
    while(true){
        int r = randomIndex();
        int c = randomIndex();
        if(grid[r][c] == 0){
            grid[r][c] = newTileValue();
            break;
        }
    }
}

bool Board::hasWon() const {
    // Win condition: tile reaches 2048
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(grid[i][j] == 2048)
                return true;
    return false;
}

bool Board::hasEmptyCell() const {
    // Checks if any tile is empty (0)
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(grid[i][j] == 0)
                return true;
    return false;
}

bool Board::isGameOver() const {
    // If empty cell exists, the game is not over
    if(hasEmptyCell()) return false;

    // Check possible horizontal merges
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 3; j++)
            if(grid[i][j] == grid[i][j+1])
                return false;

    // Check possible vertical merges
    for(int j = 0; j < 4; j++)
        for(int i = 0; i < 3; i++)
            if(grid[i][j] == grid[i+1][j])
                return false;

    // No moves left → game over
    return true;
}

/* ------------------- MOVE LEFT ------------------------- */

void Board::mergeLeft() {
    // Combines equal tiles while scanning leftward
    for(int i = 0; i < 4; i++){
        int lastMerge = -1; // prevents double-merge in a single move

        for(int j = 1; j < 4; j++){
            if(grid[i][j] == 0) continue;

            // Scan left to find merge opportunity
            for(int k = j - 1; k >= 0; k--){
                if(grid[i][k] != 0){

                    // Merge only if same number AND not merged before
                    if(grid[i][k] == grid[i][j] && lastMerge != k){
                        grid[i][k] *= 2;
                        score += grid[i][k];
                        grid[i][j] = 0;
                        lastMerge = k;
                    }
                    break; // stop scanning
                }
            }
        }
    }
}

void Board::slideLeft() {
    // Pushes all tiles to the left, filling empty spaces
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

void Board::moveLeft() {
    mergeLeft();
    slideLeft();
    steps++;
    addRandomTile();
}

/* ------------------- MOVE RIGHT ------------------------- */

void Board::mergeRight() {
    // Mirrors left merge logic but toward the right
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

void Board::slideRight() {
    // Slides tiles toward the right
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

void Board::moveRight() {
    mergeRight();
    slideRight();
    steps++;
    addRandomTile();
}

/* ------------------- MOVE UP ------------------------- */

void Board::mergeUp() {
    // Merge tiles upward
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

void Board::slideUp() {
    // Slide tiles upward to remove gaps
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

void Board::moveUp() {
    mergeUp();
    slideUp();
    steps++;
    addRandomTile();
}

/* ------------------- MOVE DOWN ------------------------- */

void Board::mergeDown() {
    // Merge tiles downward
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

void Board::slideDown() {
    // Slide tiles downward
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

void Board::moveDown() {
    mergeDown();
    slideDown();
    steps++;
    addRandomTile();
}
