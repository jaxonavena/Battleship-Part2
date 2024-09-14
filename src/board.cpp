#include <vector>
#include <utility>
#include <iostream>
#include "board.hpp"

Board::Board() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = '_';
		}
	}
}

void Board::print() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << '|' << board[i][j];
		}

		std::cout << "|\n";
	}
}

void Board::print_for_opponent() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
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

void Board::update(const std::pair<int, int>& coord, bool is_hit) {
	int row = coord.first;
	int col = coord.second;

	if (is_hit) {
		board[row][col] = 'X';
	}

	else {
		board[row][col] = 'O';
	}
}

void Board::place_ship(const std::vector<std::pair<int, int> >& coords) {
	for (const auto& coord : coords) {
		int row = coord.first;
		int col = coord.second;
		board[row][col] = 'S';
	}
}
