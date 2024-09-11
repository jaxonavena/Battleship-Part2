using namespace std;

#include <iostream>
#include "src/setup.hpp"
#include "src/ships.hpp"
#include "src/player.cpp"


int main() {
    
    cout << "Hello and welcome to Project 1 581: 2 player battleship!" << endl;
    
    const int numShips = Setup::getNumShips(); //returns correct number of ships
    
    //set up player both players by calling from the Setup namespace
    cout << "Setting up Player 1..." << endl;
    
    Player p1 = Setup::initialize_Player(numShips);

    //set up player 2
    cout << "Setting up Player 2..." << endl;

    Player p2 = Setup::initialize_Player(numShips);
    
    //enter main gameplay loop
    return 0;
}






































