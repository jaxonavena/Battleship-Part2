using namespace std;

#include <iostream>
#include "src/ships.hpp"
#include "src/player.cpp"
#include <string>

int getNumShips() {
    int fin;
    bool cont = true;
    cout << "Please enter number of ships: "; //min 1 - max 5
    cin >> fin;
    while( cont ) {
        if( ( fin > 5 ) || ( fin < 1 ) ) {
            //sanitize? TODO
            cout << "Bad number (min 1, max 5) please try again: ";
            cin >> fin;
        }
        else {
            cont = false;
        }
    }
    return fin;
}

int main() {
    
    cout << "Hello and welcome to Project 1 581: 2 player battleship!" << endl;
    
    int numShips = getNumShips(); //returns correct number of ships
    
    //set up player 1
    cout << "Setting up Player 1..." << endl;
    string p1Name;
    cout << "Please type your name: ";
    cin >> p1Name;
    
    Player p1( p1Name , numShips );
    /*
    cout << p1.returnName() << endl;
    */
    //set up player 2
    
    //enter main gameplay loop
    return 0;
}






































