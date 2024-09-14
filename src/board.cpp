#include <vector>
#include <utility>
#include <iostream>
#include "board.hpp"

Board::Board() {
	for (std::size_t i = 0; i < 10; i++) {
		for (std::size_t j = 0; j < 10; j++) {
			board[i][j] = '_';
		}
	}
}

void Board::print() const {
	for (std::size_t i = 0; i < 10; i++) {
		for (std::size_t j = 0; j < 9; j++) {
			std::cout << '|' << board[i][j];
		}

		std::cout << "|\n";
	}
}

void Board::print_for_opponent() const {
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
	const std::size_t row = coord.first;
	const std::size_t col = coord.second;

	if (is_hit) {
		board[row][col] = 'X';
	}

	else {
		board[row][col] = 'O';
	}
}

void Board::place_ship(const std::vector<std::pair<std::size_t, std::size_t> >& coords) {
	for (const auto& coord : coords) {
		const std::size_t row = coord.first;
		const std::size_t col = coord.second;
		board[row][col] = 'S';
	}
}
