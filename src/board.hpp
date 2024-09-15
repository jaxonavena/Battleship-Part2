/*
Program: Board header file
Description:  Contains the methods which are implemented in the board class
Author: Team 9
*/
#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <vector>
#include <utility>

class Board {
protected:
	//std::vector<std::pair<std::pair<std::size_t, std::size_t>, bool>> spaces; // Spaces the ship controls along with their hit status
	//std::size_t shipSize; // Size of the ship
    std::array<std::array<char, 10>, 10> board;

public:
	Board(); // Initialiatize board
	~Board() = default; // Board destructor
	//void add_hit(std::pair<std::size_t, std::size_t>);
	//void add_miss(std::pair<std::size_t, std::size_t>);
    char getCell(const std::size_t row, const std::size_t col) const; //Gets the current value in a cell
	void print() const;
	void print_for_opponent() const;
	void update(const std::pair<std::size_t, std::size_t>& coord, const bool is_hit);
	void place_ship(const std::vector<std::pair<std::size_t, std::size_t> >& coords);
};

#endif
