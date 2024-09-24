#include "ai.hpp"

// constructor definition
AI::AI(int difficulty) : Player(int numShips), difficulty(int difficulty) {}

// getters
int AI::getDifficulty() const {
  return difficulty;
}

// setters
void AI::setDifficulty(int newDifficulty) {
  difficulty = newDifficulty;
}
