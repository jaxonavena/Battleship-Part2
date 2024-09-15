/*
Program: Header file for GameLoop class
Description: Contains gameloop methods which are implemented in gameloop.cpp
Author: Team 9
*/
#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "player.hpp"

class GameplayLoop {

    public:
        GameplayLoop(Player&& p1, Player&& p2); //Move constructor
        void start(); //Main loop

    private:
        Player playerOne;  
        Player playerTwo;
        bool gameOver();
};

#endif
