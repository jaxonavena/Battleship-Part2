#ifndef PLAYER_HPP
#define PLAYER_HPP
using namespace std;

#include <array>
#include <memory>
#include <string>
#include "ships.hpp"

class Player {

    public:
        Player( const string named, const int numShips);  
        string returnName() const;
        shared_ptr<Ship> getShip( const size_t shipSize );
        void setupShips();

    private:
        string name; //name of the player
        array<shared_ptr<Ship>, 5> shipArray; //A std::array of shared pointers whose size is 5
        int numofShips;

};

#endif
