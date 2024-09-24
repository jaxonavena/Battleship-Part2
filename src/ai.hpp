#ifndef AI_HPP
#define AI_HPP

#include "player.hpp"
#include <string>

class AI : public Player {
public:
  // constructor
  AI(int difficulty);

  // getters
  int getDifficulty() const;

  // setters
  void setDifficulty(int difficulty);

private:
  int difficulty;
};

#endif
