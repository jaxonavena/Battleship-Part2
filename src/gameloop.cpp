#include "gameloop.hpp"

//Initialize gameplay loop by taking const refs 
GameplayLoop::GameplayLoop(const Player& p1, const Player& p2) : 
                           playerOne(p1), playerTwo(p2){}

bool GameplayLoop::gameOver() {

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
