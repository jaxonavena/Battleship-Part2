using namespace std;

#include <iostream>
#include <optional>
#include "src/setup.hpp"
#include "src/ships.hpp"
#include "src/player.cpp"


int main() {
    
    cout << "Hello and welcome to Project 1 581: 2 player battleship!" << endl;
    
    const int numShips = Setup::getNumShips(); //returns correct number of ships
    
    //set up player both players by calling from the Setup namespace
    //If the optional returns null, exit the program with an error code
    cout << "Setting up Player 1..." << endl;
    
    const optional<Player> p1 = Setup::initializePlayer(numShips);
    if ( !p1 ) {
        return 1;
    }

    //set up player 2
    cout << "Setting up Player 2..." << endl;

    const optional<Player> p2 = Setup::initializePlayer(numShips);
    if ( !p2 ) {
        return 1;
    }
    
    //enter main gameplay loop
    return 0;
}





































