#include <vector>
#include <utility>
#include "ships.hpp"

  // Initialize ship based on size
Ship::Ship(const std::size_t size) : shipSize(size) {
  spaces.resize(size); // Give the ship enough space for its size
}

// Place the ship on the board
bool Ship::place(std::vector<std::pair<std::size_t, std::size_t>>& coords) {
  if (coords.size() != shipSize) {
    return false;
  }
  for (std::size_t i = 0; i < shipSize; i++) {
    spaces[i] = {coords[i], false};
  }
  return true;
}

// Remove the ship from the board if we need to during setup
void Ship::remove() {
  spaces.clear();
}

 // Hit a space occupied by the ship
void Ship::hit(std::pair<std::size_t, std::size_t>& coord) {
  for (auto& space : spaces) {
    if (coord == space.first) {
      space.second = true;
      return;
    }
  }
}

// Check a coordinate for being controlled by this ship
bool Ship::valid_space(const std::pair<std::size_t, std::size_t>& coord) const {
  for (const auto& space : spaces) {
    if (coord == space.first) {
      return true;
    }
  }
  return false;
}

// Check a coordinate for being hit
bool Ship::is_hit(const std::pair<std::size_t, std::size_t>& coord) const {
  for (const auto& space : spaces) {
    if (coord == space.first)
      return space.second;
  }
  return false;
}

// Check if the ship is sunk
bool Ship::is_sunk() const { 
  for (const auto& space : spaces) {
    if (space.second == false) {
      return false;
    }
  }
  return true;
}

// Returns this ship's spaces and hit status's
std::vector<std::pair<std::pair<std::size_t, std::size_t>, bool>>& Ship::get_spaces() {
  return spaces;
}


OneShip::OneShip() : Ship(1) {}  // Call the base class constructor with size 1
TwoShip::TwoShip() : Ship(2) {}  // Call the base class constructor with size 2
ThreeShip::ThreeShip() : Ship(3) {}  // Call the base class constructor with size 3
FourShip::FourShip() : Ship(4) {}  // Call the base class constructor with size 4
FiveShip::FiveShip() : Ship(5) {}  // Call the base class constructor with size 5
