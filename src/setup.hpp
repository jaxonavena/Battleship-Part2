#ifndef SETUP_HPP
#define SETUP_HPP

#include <optional>
#include "player.cpp"

namespace Setup {

int getNumShips();
std::optional<Player> initializePlayer(const int numShips);

}

#endif
