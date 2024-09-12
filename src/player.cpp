using namespace std;

#include "player.hpp"

#include <array>
#include <iostream>
#include <memory>
#include <string>
#include "ships.hpp"
#include <limits>

Player::Player( const string named , const int numShips ) {
    name = named;
    numofShips = numShips;
}

string Player::returnName() const {
    return name;
}

shared_ptr<Ship> Player::getShip( const int shipSize ) {
//input: ship size to get (etc 1 for ship size 1, 2 for ship size 2)
//output: ship pointer to ship of that size controlled by this player
    if( (shipSize < 1) || ( shipSize > 5 ) ) {
        return nullptr; //invalid
    }
    return shipArray[ shipSize - 1 ];
}

void Player::setupShips() {
    //setup ships and their coordinates
    for( int i = 0; i < numofShips; i++ ) {
        //TODO: output position of current ships for reference, need board
        //create ship of size i
        shared_ptr<Ship> s1 = make_shared<Ship>(i + 1); 
        vector<pair<int, int>> coords( i + 1 ); //create vector of size i + 1
        //ask where to put ship and put coordinates in ship
        
        if( i == 0 ) {
            //ship size 1, little different.
            //first row
            int row; //Value of the input
            cout << "Please enter ship 1 row: "; //min 1 - max 10

            //Loop to validate the rows
            //!(cin >> fin) means cin to fin has failed in some way, while also grabbing input
            while ( !(cin >> row) || ( row > 10 ) || ( row < 1 ) ) {

                //Clears the failure state and then throws everything out of the input stream
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Bad number (min 1, max 10) please try again: ";
            } 
            //then column
            int column; //Value of the input
            cout << "Please enter ship 1 column: "; //min 1 - max 10

            //Loop to validate the column
            //!(cin >> fin) means cin to fin has failed in some way, while also grabbing input
            while ( !(cin >> column ) || ( column > 10 ) || ( column < 1 ) ) {

                //Clears the failure state and then throws everything out of the input stream
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Bad number (min 1, max 10) please try again: ";
            } 
            vector<pair<int, int>> oneCoords = { {row, column} };
            s1->place(oneCoords);
        }
        else {
            //any other size of ship
            //bit longer as need to check ship is in valid spot.
            bool invalid = true;
            bool hittingOther = false;
            int row = 0;
            int column = 0; //Value of the input
            int way = 0; //which way to put the back
            while( invalid || hittingOther ) {
                invalid = true;
                hittingOther = false;
                //first row
                cout << "Please enter ship " << i+1 << " row: "; //min 1 - max 10

                //Loop to validate the row
                //!(cin >> fin) means cin to fin has failed in some way, while also grabbing input
                while ( !(cin >> row) || ( row > 10 ) || ( row < 1 ) ) {

                    //Clears the failure state and then throws everything out of the input stream
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Bad number (min 1, max 10) please try again: ";
                } 
                //then column
                cout << "Please enter ship " << i+1 << " column: "; //min 1 - max 10

                //Loop to validate the column
                //!(cin >> fin) means cin to fin has failed in some way, while also grabbing input
                while ( !(cin >> column ) || ( column > 10 ) || ( column < 1 ) ) {

                    //Clears the failure state and then throws everything out of the input stream
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Bad number (min 1, max 10) please try again: ";
                } 
                //which way to place the back (Left, right, up, or down)
                cout << "Which way would you like to place the back? ([1]Up, [2]Right, [3]Down, or [4]Left): ";
                //!(cin >> fin) means cin to fin has failed in some way, while also grabbing input
                while ( !(cin >> way ) || ( way > 4 ) || ( way < 1 ) ) {

                    //Clears the failure state and then throws everything out of the input stream
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Bad number (min 1, max 4) please try again: ";
                } 
                //check if valid, both in/off board AND not hitting another ship
                if( way == 1 ) {
                    //going up, so column is auto valid and bottom bound
                    if( row - i < 1 ) {
                        //invalid
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Bad placement please try again. " << endl;;
                    }
                    else {
                        invalid = false;
                        //put rest of coords in
                        for( int j = 0; j <= i; j++ ) { //go over vector and put them in.
                            //this is up, so only row decreases
                            coords[ j ] = {row - j, column};
                        }
                    }
                }
                else if( way == 2) {
                    //going right, so row is valid and left bound is valid
                    if( column + i > 10 ) {
                        //invalid
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Bad placement please try again. " << endl;;
                    }
                    else {
                        invalid = false;
                        for( int j = 0; j <= i; j++ ) { //go over vector and put them in.
                            //this is right, so only column increases
                            coords[ j ] = {row, column+j};
                        }
                    }
                }
                else if( way == 3) {
                    //going down, so column and up bound are valid (up is row 2 to row 1)
                    if( row + i > 10 ) {
                        //invalid
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Bad placement please try again. " << endl;;
                    }
                    else {
                        invalid = false;
                        for( int j = 0; j <= i; j++ ) { //go over vector and put them in.
                            //this is down, so only row increases
                            coords[ j ] = {row + j, column};
                        }
                    }
                }
                else {
                    //going left, so row and right bound are valid
                    if( column - i < 1 ) {
                        //invalid
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Bad placement please try again. " << endl;;
                    }
                    else {
                        invalid = false;
                        for( int j = 0; j <= i; j++ ) { //go over vector and put them in.
                            //this is left, so only column decreases
                            coords[ j ] = {row, column - j};
                        }
                    }
                }
                if( !invalid ) {
                    //Only check if hitting other if in valid position.
                    //check if on top of this player's other ship!
                    //set hittingOther = false if not
                    //start at ship 0 (size 1) and go up to one less than current size (which is i)
                    //example: ship size 2 is i = 1, so this checks ship size 1.
                    for( int j = 0; j < i; j++ ) {
                        shared_ptr<Ship> shipToCheck = shipArray[ j ];
                        //go over each point in current ship and see if it conflicts
                        for(int k = 0; k <= i; k++ ) {
                            if( shipToCheck->valid_space( coords[ k ] ) == true ) {
                                //conflict
                                hittingOther = true;
                                cout << "Placed on previous ship! Try again" << endl;
                            }
                        }
                    }
                }
                
            }
            s1->place(coords);
        }
        shipArray[ i ] = s1; //place ship in array
    }
}
