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

#include <cstdlib>
#include <string>
#include <iostream>
#include <optional>
#include <unistd.h>
#include "player.hpp"
#include "setup.hpp"

int main() {

    cout << "Hello and welcome to Project 1 581: 2 player battleship!" << endl; //welcome sign
    const int numShips = Setup::getNumShips(); //returns correct number of ships

    char use_ai;
    int ai_difficulty = 0;
    while (use_ai != 'y' && use_ai != 'Y' && use_ai != 'n' && use_ai != 'N') {
      cout << "Would you like to play with an AI opponent? (y/n) " << endl;
      cin >> use_ai;  // Get input from the user
      cin.clear();
    }

    if (use_ai == 'y' || use_ai == 'Y') {
      while (ai_difficulty != 1 && ai_difficulty != 2 && ai_difficulty != 3) {
        cout << "What difficulty would you like to play against? (1,2,3) " << endl;
        cin >> ai_difficulty;  // Get input from the user
        cin.clear();
      }

      // Access and display the difficulty level
      cout << "AI Difficulty Level: " << ai_difficulty << endl;
    }

    //set up player both players by calling from the Setup namespace
    //If the optional returns null, exit the program with an error code
    cout << "Setting up Player 1..." << endl;

    optional<Player> p1 = Setup::initializePlayer(numShips); //player 1, set optional to catch errors.
    //can't be const as will be changing the ships and boards controlled by the player
    if ( !p1 ) {
        return 1;
    }
    p1->setupShips(); //setup ships within p1
    p1->print_Board(); //TMP
    //finish setup p1

    sleep(3);
    system("clear"); //clear the screen so player 2 doesn't see player 1's board

    //set up player 2

    if (use_ai == 'y' || use_ai == 'Y') {
      cout << "\n\n\n\n\n\n\nSetting up AI..." << endl;

      optional<Player> ai = Setup::initializePlayer(numShips, ai_difficulty, true);

      if ( !ai ) {
          return 1;
      }

      // ai->setDifficulty(ai_difficulty);
      ai->setupAIShips(); //setup ships within ai
      ai->print_Board(); //TMP

      sleep(3);
      system("clear"); //clear the screen so player 1 doesn't see ai's board

      cout << "\n\n\n\n\n\n\nStarting game..." << endl;
      //Initialize gameplay loop by dereferencing the optionals
      //Dereferencing accesses the object directly
      //The player objects will be moved into the gameplay loop after this, meaning they cant be used in main
      //Unique ptrs can be changed to shared ptrs if they are needed in main
      GameplayLoop gameLoop(std::move(*p1), std::move(*ai));
      gameLoop.start();
    }
    else {
      cout << "\n\n\n\n\n\n\nSetting up Player 2..." << endl;

      optional<Player> p2 = Setup::initializePlayer(numShips); //player 2, set optional to catch errors
      if ( !p2 ) {
          return 1;
      }
      p2->setupShips(); //setup ships within p2
      p2->print_Board(); //TMP

      sleep(3);
      system("clear"); //clear the screen so player 1 doesn't see player 2's board

      cout << "\n\n\n\n\n\n\nStarting game..." << endl;
      //Initialize gameplay loop by dereferencing the optionals
      //Dereferencing accesses the object directly
      //The player objects will be moved into the gameplay loop after this, meaning they cant be used in main
      //Unique ptrs can be changed to shared ptrs if they are needed in main
      GameplayLoop gameLoop(std::move(*p1), std::move(*p2));
      gameLoop.start();
    }
    return 0;
}
