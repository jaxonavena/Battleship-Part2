using namespace std;

#include <iostream>
#include <string>
#include "ships.hpp"

class Player {
    public:
        Player( string named , int numShips ) {
            name = named;
            numofShips = numShips;
            OneShip one( ); TwoShip two(); ThreeShip three(); FourShip four(); FiveShip five();
            //setup number of ships
            switch( numShips ) {
                case 1:
                    //1 ship
                    OneShip one{ };
                    shipArray[ 0 ] = one;
                    shipArray[ 1 ] = NULL;
                    shipArray[ 2 ] = NULL;
                    shipArray[ 3 ] = NULL;
                    shipArray[ 4 ] = NULL;
                    break;
                case 2:
                    //2 ships
                    shipArray[ 0 ] = one;
                    shipArray[ 1 ] = two;
                    shipArray[ 2 ] = NULL;
                    shipArray[ 3 ] = NULL;
                    shipArray[ 4 ] = NULL;
                    break;
                case 3:
                    //3 ships
                    shipArray[ 0 ] = one;
                    shipArray[ 1 ] = two;
                    shipArray[ 2 ] = three;
                    shipArray[ 3 ] = NULL;
                    shipArray[ 4 ] = NULL;
                    break;
                case 4:
                    //4 ships
                    shipArray[ 0 ] = one;
                    shipArray[ 1 ] = two;
                    shipArray[ 2 ] = three;
                    shipArray[ 3 ] = four;
                    shipArray[ 4 ] = NULL;
                    break;
                case 5:
                    //5 ships
                    shipArray[ 0 ] = one;
                    shipArray[ 1 ] = two;
                    shipArray[ 2 ] = three;
                    shipArray[ 3 ] = four;
                    shipArray[ 4 ] = five;
                    break;
                default:
                    //invalid
                    cout << "Invalid number of ships, exiting..." << endl;
                    return -1;
            }
        };
        string returnName() {
            return name;
        };

    private:
        string name; //name of the player
        Ship shipArray[ 5 ];
        int numofShips;
};
