/*
Program: Player header file
Description: Contains methods implemented within player
Author: Team 9
*/
#ifndef PLAYER_HPP
#define PLAYER_HPP
using namespace std;

#include <array>
#include <memory>
#include <string>
#include "ships.hpp"
#include "board.hpp"

class Player {

    public:
        Player( const string& named, const int numShips);  
        string returnName() const;
        shared_ptr<Ship> getShip( const size_t shipSize );
        void setupShips();
        void print_Board(); //prints both top and bottom board
        size_t convert_chartoIndex( char column ); //converts a column char to a 0 indexed size_t
    private:
        string name; //name of the player
        array<shared_ptr<Ship>, 5> shipArray; //A std::array of shared pointers whose size is 5
        int numofShips;
        unique_ptr<Board> top_board;    //top board, shows this player's shots and hits
        unique_ptr<Board> bottom_board; //bottom board, shows this player's ships
};

#endif
