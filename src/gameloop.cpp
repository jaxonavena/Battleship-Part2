/*
Program: GameLoop class
Description: This class represents the main gamplay loop.  This is taken out
of main to keep the flow of the game more clear, and to prevent a large main 
file.  The loop is to ask player 1 where they want to shoot, update their board
and player 2's board, then check if game is over.  If game is not over, then
player 2 gets their turn.
Author: Team 9
*/
#include "gameloop.hpp"
#include <iostream>
#include <limits>
//Initialize gameplay loop by taking rvalue refs 
GameplayLoop::GameplayLoop(Player&& p1, Player&& p2) : 
                           playerOne(std::move(p1)), playerTwo(std::move(p2)){} //this object controls the player objects.

bool GameplayLoop::gameOver() {
    return true; //TODO
}

void GameplayLoop::start() {

    // Main loop
    while ( true ) {
        //Player 1 takes their turn
        std::cout << "Player 1's Turn." << std::endl;
        size_t shot_row; //Value of the input
        std::cout << "Please enter your shot's row: "; //min 1 - max 10
        //Loop to validate the rows
        //!(cin >> fin) means cin to fin has failed in some way, while also grabbing input
        while ( !(std::cin >> shot_row) || ( shot_row > 10 ) || ( shot_row < 1 ) ) {
            //Clears the failure state and then throws everything out of the input stream
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
            std::cout << "Bad number (min 1, max 10) please try again: ";
        } 
        shot_row = shot_row - 1; //0 indexed now
        
        //then column
        char column; //Value of the input as a char
        std::cout << "Please enter your shot's column: "; //min a - max j

        //Loop to validate the column
        //!(cin >> fin) means cin to fin has failed in some way, while also grabbing input
        while ( !(std::cin >> column ) || ( column > 'j' ) || ( column < 'a' ) ) {
            //Clears the failure state and then throws everything out of the input stream
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
            std::cout << "Bad Letter ( a through j) please try again: ";
        } 
        size_t shot_column = playerOne.convert_chartoIndex( column ); //0 indexed now
        
        
        
        
        
        
        
        
        
        
        
        //Check if game over from player 1
        //If the game is over, exit the loop
        if( gameOver() ) {
            return;
        }
        //Player 2 takes their turn
        
        //Check if game over from player 2
        //If the game is over, exit the loop
        if( gameOver() ) {
            return;
        }
    }

}
