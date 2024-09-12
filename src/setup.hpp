#ifndef SETUP_HPP
#define SETUP_HPP

#include <optional>
#include "player.hpp"

namespace Setup {

[[nodiscard]] int getNumShips();
[[nodiscard]] std::optional<Player> initializePlayer(const int numShips);

}

#endif
