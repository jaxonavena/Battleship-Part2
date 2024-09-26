#include "ai.hpp"
#include <string>
#include "player.hpp"

// constructor definition
AI::AI(int difficulty, const int numShips) : Player("Ted", numShips), difficulty(difficulty) {}

// getters
int AI::getDifficulty() const {
  return difficulty;
}

// setters
void AI::setDifficulty(int newDifficulty) {
  difficulty = newDifficulty;
}
