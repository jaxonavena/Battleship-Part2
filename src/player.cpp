#ifndef PLAYER_CPP
#define PLAYER_CPP
using namespace std;

#include <iostream>
#include <string>
#include "ships.cpp"

class Player {
    public:
        Player( string named , int numShips ) {
            name = named;
            numofShips = numShips;
            //setup number of ships
            for( int i = 0; i < numShips; i++ ) {
                //create ship of size i
                Ship* s1 = new Ship( i );
                //ask where to put ship and put coordinates in ship
                //TODO
                shipArray[ i ] = s1; //place ship in array
            }
           
        };
        string returnName() {
            return name;
        };
        Ship* getShip( int shipSize ) {
            if( (shipSize < 1) || ( shipSize > 5 ) ) {
                return NULL; //invalid
            }
            return shipArray[ shipSize ];
        };

    private:
        string name; //name of the player
        Ship* shipArray[ 5 ];
        int numofShips;
};
#endif
