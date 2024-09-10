#ifndef SHIPS_HPP
#define SHIPS_HPP

#include <vector>
#include <utility>

class Ship {
protected:
    std::vector<std::pair<std::pair<int, int>, bool>> spaces; // Spaces the ship controls along with their hit status
    int shipSize; // Size of the ship

public:
  Ship(int size); // Initialiatize ship with given size
  virtual ~Ship() = default; // Ship destructor
  bool place(std::vector<std::pair<int, int>>& coords); // Places the ship by giving it the coordinates it controls
  void remove(void); // When the ship needs to be removed from the board
  void hit(std::pair<int, int>& coord); // Hit a space occupied by the ship
  bool valid_space(std::pair<int, int>& coord); // Check if a given coordinate is occupied by this ship
  bool is_hit(std::pair<int, int>& coord); // Check if a given space occupied by this ship is hit
  bool is_sunk(void); // Check if the ship has been sunk
  std::vector<std::pair<std::pair<int, int>, bool>>& get_spaces(void); // Returns this ship's spaces and hit status's

};

// Constructors of ships of sizes 1x1 (One) through 1x5 (Five)
class OneShip : public Ship {
public:
    OneShip(); 
};

class TwoShip : public Ship {
public:
    TwoShip(); 
};

class ThreeShip : public Ship {
public:
    ThreeShip();
};

class FourShip : public Ship {
public:
    FourShip();
};

class FiveShip : public Ship {
public:
    FiveShip();
};

#endif // SHIPS_HPP



