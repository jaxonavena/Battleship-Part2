/*
Program: Setup class
Description: This class represents the setup part of the game.  This is creating
the players and them setting their boats.  This also gets the number of ships
to be played with in the game.
Author: Team 9
*/
#include "setup.hpp"

#include <iostream>
#include <limits>
#include <optional>
#include "player.hpp"
#include "ai.hpp"


namespace Setup {

//This function will get the number of ships
[[nodiscard]] int getNumShips() {
    int fin = 0; //Value the function will return
    std::cout << "Please enter number of ships: "; //min 1 - max 5

    //Loop to validate the number of ships
    //!(std::cin >> fin) means cin to fin has failed in some way, while also grabbing input
    while ( !(std::cin >> fin) || ( fin > 5 ) || ( fin < 1 ) ) {

        //Clears the failure state and then throws everything out of the input stream
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        std::cout << "Bad number (min 1, max 5) please try again: ";
    }

    //Clear input stream just in case cin leaves anything, as cin stops at white space
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    return fin;
}

//This function will initialize one of the players
//Takes the number of ships as a parameter
[[nodiscard]] std::optional<Player> initializePlayer(const int numShips, int ai_difficulty, bool is_ai) {
    std::string name; //Name of the player that we will receive
    if (is_ai) {
      return Player("Tim", numShips, ai_difficulty, is_ai);
    }
    else {
      std::cout << "Please type your name: ";

          //If some error has ocurred, return a nullopt
      if ( !(std::getline(std::cin, name)) ) {
          std::cout << "A catastrophic error has ocurred!" << std::endl;
          return std::nullopt;
      }

      //Return the player name and ships as a player object
      return Player(name, numShips);
    }


}

// //This function will initialize an AI opponent
// //Takes the number of ships and ai_difficulty as a parameters
// [[nodiscard]] std::optional<AI> initializeAI(int ai_difficulty, const int numShips) {
//     // std::string name; //Name of the player that we will receive
//     // std::cout << "Please type your name: ";

//     //If some error has ocurred, return a nullopt
//     // if ( !(std::getline(std::cin, name)) ) {
//     //     std::cout << "A catastrophic error has ocurred!" << std::endl;
//     //     return std::nullopt;
//     // }

//     //Return the player name and ships as a player object
//     return AI(ai_difficulty, numShips);
// }

}
