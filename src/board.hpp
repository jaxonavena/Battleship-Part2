/*
Program: Board header file
Description:  Contains the methods which are implemented in the board class
Author: Team 9
*/
#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <utility>

class Board {
protected:
	//std::vector<std::pair<std::pair<std::size_t, std::size_t>, bool>> spaces; // Spaces the ship controls along with their hit status
	//std::size_t shipSize; // Size of the ship
	char board[10][10]; //board is 10 X 10 size

public:
	Board(); // Initialiatize board
	~Board() = default; // Board destructor
	//void add_hit(std::pair<std::size_t, std::size_t>);
	//void add_miss(std::pair<std::size_t, std::size_t>);
	void print() const;
	void print_for_opponent() const;
	void update(const std::pair<std::size_t, std::size_t>& coord, const bool is_hit);
	void place_ship(const std::vector<std::pair<std::size_t, std::size_t> >& coords);
};

#endif
