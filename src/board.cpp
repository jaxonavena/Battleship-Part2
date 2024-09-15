/*
Program: Board class
Description: This class represents the board in the battleship game.
A player controls two boards, and the boards keep track of hits/misses in
a grid.  The board is 10 x 10.
Author: Team 9
*/
#include <array>
#include <vector>
#include <utility>
#include <iostream>
#include "board.hpp"

Board::Board() {
	for (std::size_t i = 0; i < 10; i++) {
		for (std::size_t j = 0; j < 10; j++) {
			board[i][j] = '_'; //init board spaces with underscore
		}
	}
}

char Board::getCell(const std::size_t row, const std::size_t col) const { //Gets the current value in a cell
    return board[row][col];
}

const std::array<std::array<char, 10>, 10>& Board::get_board() const {
	return board;
}

void Board::print() const {
    std::cout << "\n  |A|B|C|D|E|F|G|H|I|J|" << std::endl; //print out top row with labels
	for (std::size_t i = 0; i < 10; i++) { //print out 10 row
	    //print out row label
	    if( i == 9 ) {
	        std::cout << std::to_string( i + 1 ); //since 10 is 1 char bigger, need a special case to line up
	    }
	    else {
	        std::cout << " " << std::to_string( i + 1 ); //otherwise, just print out space then i
	    }
	    
		for (std::size_t j = 0; j < 10; j++) { //print out 10 columns
			std::cout << '|' << board[i][j];
		}

		std::cout << "|\n"; //last char and then new line to keep this output seperate
	}
}

void Board::print_for_opponent() const {
    //prints out bottom board but hides where the ships are.
	for (std::size_t i = 0; i < 10; i++) {
		for (std::size_t j = 0; j < 10; j++) {
			if (board[i][j] == 'S') {
				std::cout << "|_";
			}

			else {
				std::cout << '|' << board[i][j];
			}
		}

		std::cout << "|\n";
	}
}

void Board::update(const std::pair<std::size_t, std::size_t>& coord, const bool is_hit) {
    //updates the board with a hit or miss
	const std::size_t row = coord.first;
	const std::size_t col = coord.second;

	if (is_hit) {
		board[row][col] = 'X'; //X is a hit, O is a miss
	}

	else {
		board[row][col] = 'O'; //miss on fire
	}
}

void Board::place_ship(const std::vector<std::pair<std::size_t, std::size_t> >& coords) {
	for (const auto& coord : coords) {
		const std::size_t row = coord.first;
		const std::size_t col = coord.second;
		board[row][col] = 'S'; //S represents a ship being on that grid mark.
	}
}
