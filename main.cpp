using namespace std;

#include <iostream>
#include <optional>
#include "src/setup.cpp"
#include "src/ships.cpp"
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
    Player person1 = p1.value();

    //set up player 2
    cout << "Setting up Player 2..." << endl;

    const optional<Player> p2 = Setup::initializePlayer(numShips);
    if ( !p2 ) {
        return 1;
    }
    Player person2 = p2.value();
    //enter main gameplay loop
    cout << person1.getShip( 1 ) << endl;
    return 0;
}




































