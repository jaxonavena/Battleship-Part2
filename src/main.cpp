using namespace std;

#include "gameloop.hpp"

#include <iostream>
#include <optional>
#include "player.hpp"
#include "setup.hpp"

static void printVector( const vector<pair<pair<size_t, size_t>, bool>>& v ) {
    for( const pair<pair<size_t, size_t>, bool>& p : v ) {
        cout << "Row: " << p.first.first << ", Column: " << p.first.second << ", Hit: " << p.second << endl;
    }
}

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

    //Initialize gameplay loop by dereferencing the optionals
    //Dereferencing accesses the object directly, .value() returns a copy, so this avoids an extra copy
    GameplayLoop gameLoop(*p1, *p2);
    gameLoop.start();
    
    /*
    for( int i = 0; i < numShips; i++ ) {
        printVector( person1.getShip( i+1 )->get_spaces() );
    }
    for( int i = 0; i < numShips; i++ ) {
        printVector( person2.getShip( i+1 )->get_spaces() );
    }
    */
    return 0;
}
