/*
Program: Player class
Description: This class represents the player in the 2 player battleship game.
The player controls two boards (top and bottom), a ship array, their name,
and their number of ships.  The ship array is to keep track of all the player's
ships and their hit status.
Author: Team 9
*/
using namespace std;

#include "player.hpp"

#include <array>
#include <iostream>
#include <memory>
#include <string>
#include "ships.hpp"
#include <limits>

size_t Player::convert_chartoIndex( char column ) const {
    //Converts a char into its proper number for board indexing
    //a is 97, j is 106. Want a to be 0 and j to be 9
    if( tolower(column) == 'a' ) {return 0;} //a to 0
    else if( tolower(column) == 'b' ) {return 1;} //b to 1
    else if( tolower(column) == 'c' ) {return 2;} //c to 2
    else if( tolower(column) == 'd' ) {return 3;} //d to 3
    else if( tolower(column) == 'e' ) {return 4;} //e to 4
    else if( tolower(column) == 'f' ) {return 5;} //f to 5
    else if( tolower(column) == 'g' ) {return 6;} //g to 6
    else if( tolower(column) == 'h' ) {return 7;} //h to 7
    else if( tolower(column) == 'i' ) {return 8;} //i to 8
    else if( tolower(column) == 'j' ) {return 9;} //j to 9
    else { return -1; } //error
}

Player::Player( const string& named , const int numShips ) { //Player constructor from player name and number of ships
    name = named; //player's name
    numofShips = numShips; //number of ships this player controls
}

string Player::returnName() const {
    return name; //return name
}

int Player::getNumShips() const {
    return numofShips;
}

void Player::print_Board() {
    top_board.print(); //print top board
    bottom_board.print_for_opponent(); //print bottom board
}

char Player::getCellTopBoard(const size_t row, const size_t col) const {
    return top_board.getCell(row, col);
}

Board Player::get_top_board() {
	return this->top_board;
}

Board Player::get_bottom_board() {
	return this->bottom_board;
}

shared_ptr<Ship> Player::getShip( const size_t shipSize ) {
//input: ship size to get (etc 1 for ship size 1, 2 for ship size 2)
//output: ship pointer to ship of that size controlled by this player
    if( (shipSize < 1) || ( shipSize > 5 ) ) { //checks if ship size is valid
        return nullptr; //invalid
    }
    return shipArray[ shipSize - 1 ]; //return pointer to ship
}

shared_ptr<Ship> Player::getShip( const size_t shipSize ) const {
//input: ship size to get (etc 1 for ship size 1, 2 for ship size 2)
//output: ship pointer to ship of that size controlled by this player
    if( (shipSize < 1) || ( shipSize > 5 ) ) { //checks if ship size is valid
        return nullptr; //invalid
    }
    return shipArray[ shipSize - 1 ]; //return pointer to ship
}


void Player::setupShips() {
    //setup ships and their coordinates
    for( int i = 0; i < numofShips; i++ ) {
        //create ship of size i
        shared_ptr<Ship> s1 = make_shared<Ship>(i + 1); //get ship pointer of size i + 1
        vector<pair<size_t, size_t>> coords( i + 1 ); //create vector of size i + 1
        //ask where to put ship and put coordinates in ship
        if( i == 0 ) {
            //ship size 1, little different.
            //first row
            bottom_board.print(); //print board out for reference
            size_t row; //Value of the input
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
            char column; //Value of the input as a char
            cout << "Please enter ship 1 column: "; //min a - max j

            //Loop to validate the column
            //!(cin >> fin) means cin to fin has failed in some way, while also grabbing input
            while ( !(cin >> column ) || ( tolower(column) > 'j' ) || ( tolower(column) < 'a' ) ) {
                //Clears the failure state and then throws everything out of the input stream
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Bad Letter ( a through j) please try again: ";
            } 
            size_t column_conv = convert_chartoIndex( column ); //converts my char to a zero-indexed board number
            vector<pair<size_t, size_t>> oneCoords = { {row - 1, column_conv } }; //since board 0 indexed, need to subtract 1 from row
            s1->place(oneCoords); //place ship in ship array
            bottom_board.place_ship( oneCoords ); //update board with ship
        }
        else {
            //any other size of ship
            //bit longer as need to check ship is in valid spot.
            bool invalid = true;       //bool for a valid spot
            bool hittingOther = false; //bool for if the ship placed is on top of another ship
            int row = 0;    //value of row, HAS to be int as can be negative when checking if it goes off board
            int column = 0; //Value of column, HAS to be int as can be negative when checking if it goes off board
            size_t way = 0; //which way to put the back
            while( invalid || hittingOther ) {
                bottom_board.print(); //print board out for reference
                invalid = true; //reset for loop
                hittingOther = false; //reset for loop
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
                char column_pre; //Value of the input as a char
                cout << "Please enter ship " << i + 1 << " column: "; //min a - max j

                //Loop to validate the column
                //!(cin >> fin) means cin to fin has failed in some way, while also grabbing input
                while ( !(cin >> column_pre ) || ( tolower(column_pre) > 'j' ) || ( tolower(column_pre) < 'a' ) ) {
                    //Clears the failure state and then throws everything out of the input stream
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Bad Letter ( a through j) please try again: ";
                } 
                column = convert_chartoIndex( column_pre ); //converts my char to a zero-indexed board number
                //which way to place the back (Left, right, up, or down)
                cout << "Which way would you like to place the back? ([1]Up, [2]Right, [3]Down, or [4]Left): "; //classic terminal style, entering number to represent way
                //!(cin >> fin) means cin to fin has failed in some way, while also grabbing input
                while ( !(cin >> way ) || ( way > 4 ) || ( way < 1 ) ) {

                    //Clears the failure state and then throws everything out of the input stream
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Bad number (min 1, max 4) please try again: "; //didn't choose one of the options, try again
                } 
                //check if valid, both in/off board AND not hitting another ship
                if( way == 1 ) {
                    //going up, so column is auto valid and bottom bound
                    if( row - i < 1 ) {
                        //invalid
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Bad placement please try again. " << endl;
                    }
                    else {
                        invalid = false; //now valid
                        //put rest of coords in
                        for( size_t j = 0; j <= static_cast<size_t>(i); j++ ) { //go over vector and put them in.
                            //this is up, so only row decreases
                            coords[ j ] = {row - j, column};
                        }
                    }
                }
                else if( way == 2) {
                    //going right, so row is valid and left bound is valid
                    if( column + i > 9 ) { //columns are zero indexed at this point, so greater than 9
                        //invalid
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Bad placement please try again. " << endl;;
                    }
                    else {
                        invalid = false;
                        for( size_t j = 0; j <= static_cast<size_t>(i); j++ ) { //go over vector and put them in.
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
                        for( size_t j = 0; j <= static_cast<size_t>(i); j++ ) { //go over vector and put them in.
                            //this is down, so only row increases
                            coords[ j ] = {row + j, column};
                        }
                    }
                }
                else {
                    //going left, so row and right bound are valid (left is column 10 to column 9)
                    if( column - i < 0 ) { //columns are zero indexed at this point, so less than 0
                        //invalid
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Bad placement please try again. " << endl;;
                    }
                    else {
                        invalid = false;
                        for( size_t j = 0; j <= static_cast<size_t>(i); j++ ) { //go over vector and put them in.
                            //this is left, so only column decreases
                            coords[ j ] = {row, column - j};
                        }
                    }
                }
                if( !invalid ) {
                    for( auto& par : coords ) { //fix row indexing HERE to properly check
                        par = { par.first - 1, par.second }; //zero indexed array so need to subtract 1 from row
                    } //now my rows and columns are zero indexed for the board
                    
                    //Only check if hitting other if in valid position.
                    //check if on top of this player's other ship!
                    //set hittingOther = false if not
                    //start at ship 0 (size 1) and go up to one less than current size (which is i)
                    //example: ship size 2 is i = 1, so this checks ship size 1.
                    for( size_t j = 0; j < static_cast<size_t>(i); j++ ) {
                        shared_ptr<Ship> shipToCheck = shipArray[ j ]; //get ship to check
                        //go over each posize_t in current ship and see if it conflicts
                        for(size_t k = 0; k <= static_cast<size_t>(i); k++ ) {
                            if( shipToCheck->valid_space( coords[ k ] ) == true ) {
                                //conflict
                                hittingOther = true; //need to redo loop
                                cout << "Placed on previous ship! Try again" << endl;
                                break;
                            }
                        }
                        if( hittingOther == true ) {break;} //auto leave if hitting a ship, don't need to keep checking
                    }
                }
                
            }
            s1->place(coords); //update ship array
            bottom_board.place_ship( coords ); //update board with ship
        }
        shipArray[ i ] = s1; //place ship in array
        cin.clear(); //clear stream
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //clear input stream
    }
}
