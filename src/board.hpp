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
    std::array<std::array<char, 10>, 10> board; //the board

public:
	Board(); // Initialiatize board
	~Board() = default; // Board destructor
	//void add_hit(std::pair<std::size_t, std::size_t>);
	//void add_miss(std::pair<std::size_t, std::size_t>);
    char getCell(const std::size_t row, const std::size_t col) const; //Gets the current value in a cell
	const std::array<std::array<char, 10>, 10>& get_board() const; //getter for the board
	void print() const; //print the board
	//void print_for_opponent() const; //print the board without the ships based on your opponent's hits and misses
	void update(const std::pair<std::size_t, std::size_t>& coord, const bool is_hit); //update the board with the hits and misses
	void place_ship(const std::vector<std::pair<std::size_t, std::size_t> >& coords); //place ships on the board
};

#endif
