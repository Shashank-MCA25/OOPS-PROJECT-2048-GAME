#include "../include/Game.h"
#include "../include/Utils.h"
#include <iostream>

#ifdef _WIN32
#include <conio.h> // for _getch() on Windows
#endif

using namespace std;

/*
 * Runs the main game loop:
 *  - Displays the board
 *  - Checks win/lose conditions
 *  - Takes player input (W/A/S/D)
 *  - Applies movement to the board
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
