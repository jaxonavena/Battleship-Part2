using namespace std;

#include <iostream>
#include <optional>
#include "src/setup.cpp"
#include "src/ships.cpp"
#include "src/player.cpp"
static void printVector( vector<pair<pair<int, int>, bool>> v ) {
    for( pair<pair<int, int>, bool> p : v ) {
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
    Player person1 = p1.value();

    //set up player 2
    cout << "Setting up Player 2..." << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
    const optional<Player> p2 = Setup::initializePlayer(numShips);
    if ( !p2 ) {
        return 1;
    }
    Player person2 = p2.value();
    //enter main gameplay loop
    
    for( int i = 0; i < numShips; i++ ) {
        printVector( person1.getShip( i+1 )->get_spaces() );
    }
    for( int i = 0; i < numShips; i++ ) {
        printVector( person2.getShip( i+1 )->get_spaces() );
    }
    return 0;
}



































