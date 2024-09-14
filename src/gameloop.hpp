#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "player.hpp"

class GameplayLoop {

    public:
        GameplayLoop(const Player& p1, const Player& p2);
        void start(); //Main loop

    private:
        Player playerOne;  
        Player playerTwo;
        bool gameOver();
};

#endif
