#include "setup.hpp"

#include <iostream>
#include <limits>
#include "player.cpp"

namespace Setup {

//This function will get the number of ships
int getNumShips() {
    int fin; //Value the function will return
    std::cout << "Please enter number of ships: "; //min 1 - max 5

    //Loop to validate the number of ships
    //!(std::cin >> fin) means cin to fin has failed in some way, while also grabbing input
    while( !(std::cin >> fin) || ( fin > 5 ) || ( fin < 1 ) ) {

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
Player initializePlayer(const int numShips) {
    string name; //Name of the player that we will receive 
    cout << "Please type your name: ";
    cin >> name;

    //Make sure to clear the input stream
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //Return the player name and ships as a player object
    return Player(name, numShips);
}

}
