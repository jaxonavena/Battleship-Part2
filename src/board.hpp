#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <utility>

class Board {
protected:
	//std::vector<std::pair<std::pair<int, int>, bool>> spaces; // Spaces the ship controls along with their hit status
	//int shipSize; // Size of the ship
	char board[10][10];

public:
	Board(); // Initialiatize board
	virtual ~Board() = default; // Board destructor
	//void add_hit(std::pair<int, int>);
	//void add_miss(std::pair<int, int>);
	void print();
	void print_for_opponent();
	void update(const std::pair<int, int>& coord, bool is_hit);
	void place_ship(const std::vector<std::pair<int, int> >& coords);
};

#endif
