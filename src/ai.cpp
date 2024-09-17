#include "ai.hpp"

// constructor definition
AI::AI(int difficulty) : difficulty(difficulty) {}

// getters
int AI::getDifficulty() const {
  return difficulty;
}

// setters
void AI::setDifficulty(int newDifficulty) {
  difficulty = newDifficulty;
}
