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
        Player playerOne;  //control player within loop class, get from main
        Player playerTwo;  //as above
        short currentTurn; //either 1 or 2
        bool verifyShot(const std::size_t row, const std::size_t col) const; //verify a shot as valid
        std::pair<std::size_t, std::size_t> getShot() const; //get a shot as the correct type
        pair<size_t, size_t> getAIShot();
        void playerOneTurn(); //take player one turn
        void playerTwoTurn(); //take player two turn
        bool gameOver() const; //check if the game is over, if so return true, otherwise false.
        bool its_a_hit(Player& main, Player& target, pair<size_t, size_t> coord);
};

#endif
