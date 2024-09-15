/*
Program: GameLoop class
Description: This class represents the main gamplay loop.  This is taken out
of main to keep the flow of the game more clear, and to prevent a large main 
file.  The loop is to ask player 1 where they want to shoot, update their board
and player 2's board, then check if game is over.  If game is not over, then
player 2 gets their turn.
Author: Team 9
*/
#include "gameloop.hpp"

//Initialize gameplay loop by taking const refs 
GameplayLoop::GameplayLoop(const Player& p1, const Player& p2) : 
                           playerOne(p1), playerTwo(p2){}

bool GameplayLoop::gameOver() {
    return true; //TODO
}

void GameplayLoop::start() {

    // Main loop
    while ( true ) {
        
        //If the game is over, exit the loop
        if( gameOver() ) {
            return;
        }
    }

}
