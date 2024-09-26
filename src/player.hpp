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
        Player( const string& named, const int numShips);  //create player with name and number of ships
        string returnName() const; //get player name (const) as won't change
        int getNumShips() const;   //get number of ships this player controls
        char getCellTopBoard(const size_t row, const size_t col) const; //get top board for gameplay loop
        Board get_top_board(); //getter for the top board
        Board get_bottom_board(); //getter for the bottom board
        shared_ptr<Ship> getShip( const size_t shipSize ); //get modifiable ship
        shared_ptr<Ship> getShip( const size_t shipSize ) const; //get ship as a const (for memory safe use)
        void setupShips(); //transfer control of ship control to player class
        void print_Board(); //prints both top and bottom board
        size_t convert_chartoIndex( char column ) const; //converts a column char to a 0 indexed size_t
        Board top_board;    //top board, shows this player's shots and hits
        Board bottom_board; //bottom board, shows this player's ships

    private:
        string name; //name of the player
        array<shared_ptr<Ship>, 5> shipArray; //A std::array of shared pointers whose size is 5
        int numofShips; //number of ships this player controls
        int this_ai_difficulty;
        bool this_is_ai;
};

#endif
