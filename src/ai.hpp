#ifndef AI_HPP
#define AI_HPP

#include <string>

class AI {
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
