/*
Program: header file for setup class
Description: Contains methods implemented in setup class
Author: Team 9
*/
#ifndef SETUP_HPP
#define SETUP_HPP

#include <optional>
#include "player.hpp"

namespace Setup {

[[nodiscard]] int getNumShips(); //don't ignore return value, so nodiscard
[[nodiscard]] std::optional<Player> initializePlayer(const int numShips); //don't ignore return value, so nodiscard
[[nodiscard]] std::optional<AI> initializeAI(int ai_difficulty, const int numShips); //don't ignore return value, so nodiscard

}

#endif
