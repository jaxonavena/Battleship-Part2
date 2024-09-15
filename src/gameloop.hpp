/*
Program: Header file for GameLoop class
Description: Contains gameloop methods which are implemented in gameloop.cpp
Author: Team 9
*/
#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <optional>
#include "player.hpp"
#include <utility>

class GameplayLoop {

    public:
        GameplayLoop(Player&& p1, Player&& p2); //Move constructor
        void start(); //Main loop

    private:
        Player playerOne;  
        Player playerTwo;
        short currentTurn;
        bool verifyShot(const std::size_t row, const std::size_t col) const;
        std::pair<std::size_t, std::size_t> getShot() const;
        void playerOneTurn();
        void playerTwoTurn();
        bool gameOver() const;
};

#endif
