#include "../include/Game.h"
#include "../include/Utils.h"
#include <iostream>

#ifdef _WIN32
#include <conio.h> // for _getch() on Windows
#endif

using namespace std;

/* ------------------- Game Start ------------------------- */
/**
 * Input: None
 * Output: Runs the interactive 2048 game loop in terminal
 * Approach:
 *   1. Initializes a Board object
 *   2. Clears screen and displays the board each iteration
 *   3. Checks for win (tile 2048) and prompts to continue
 *   4. Checks for game over (no moves left)
 *   5. Takes immediate key input (W/A/S/D or Q)
 *   6. Performs corresponding move on Board
 *   7. Loops until player quits or game ends
 * Side Effects:
 *   - Modifies Board state (tiles, score, steps)
 *   - Prints to console
 *   - Captures user input
 */
void Game::start() {
    Board board;

    while(true){
        clearScreen();
        board.display();

        // Check win condition
        if(board.hasWon()){
            cout << "YOU WIN! Continue playing? (y/n): ";
            char c;
            cin >> c;
            if(c == 'n' || c == 'N') return;
        }

        // Check game over condition
        if(board.isGameOver()){
            cout << "GAME OVER!\n";
            return;
        }

        cout << "Use W/A/S/D to move (Q to quit): ";
        char ch = _getch(); // immediate key input (no Enter)

        // Perform movement based on user key
        switch(ch){
            case 'w': case 'W': board.moveUp();    break;
            case 's': case 'S': board.moveDown();  break;
            case 'a': case 'A': board.moveLeft();  break;
            case 'd': case 'D': board.moveRight(); break;
            case 'q': case 'Q': return;
        }
    }
}
