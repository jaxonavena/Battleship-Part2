/*
Program: Main class
Inputs: player input to run battleship game
outputs: displays the battleship game
Description: Main class called from the terminal.  Calls setup and main 
game loop but doesn't do much computation within main.
Author: Team 9
*/
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
    
    optional<Player> p1 = Setup::initializePlayer(numShips); //player 1, set optional to catch errors.
    //can't be const as will be changing the ships and boards controlled by the player
    if ( !p1 ) {
        return 1;
    }
    p1.value().setupShips(); //setup ships within p1
    p1.value().print_Board(); //TMP
    //finish setup p1
    
    //set up player 2
    cout << "\n\n\n\n\n\n\nSetting up Player 2..." << endl;
    
    optional<Player> p2 = Setup::initializePlayer(numShips); //player 2, set optional to catch errors
    if ( !p2 ) {
        return 1;
    }
    p2.value().setupShips(); //setup ships within p2
    p2.value().print_Board(); //TMP
    cout << "\n\n\n\n\n\n\nStarting game..." << endl;
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
