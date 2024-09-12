/*
This is just a file for testing the functionalites of the ship class
*/

#include <iostream>
#include "ships.hpp"
#include <vector>

int main() {
    // Test Ship class and derived classes

    // Create a One-size ship
    OneShip oneShip;
    std::vector<std::pair<int, int>> oneCoords = { {1, 1} };
    if (oneShip.place(oneCoords)) {
        std::cout << "One-size ship placed at (1, 1)." << std::endl;
    } else {
        std::cout << "Error placing One-size ship." << std::endl;
    }

    // Create a Two-size ship
    TwoShip twoShip;
    std::vector<std::pair<int, int>> twoCoords = { {2, 2}, {2, 3} };
    if (twoShip.place(twoCoords)) {
        std::cout << "Two-size ship placed at (2, 2) and (2, 3)." << std::endl;
    } else {
        std::cout << "Error placing Two-size ship." << std::endl;
    }

    // Check if specific coordinates are controlled by the twoShip
    std::pair<int, int> checkCoord1 = {2, 2};
    std::pair<int, int> checkCoord3 = {2, 3};
    std::pair<int, int> checkCoord2 = {3, 3};

    if (twoShip.valid_space(checkCoord1)) {
        std::cout << "(2, 2) is part of the Two-size ship." << std::endl;
    } else {
        std::cout << "(2, 2) is not part of the Two-size ship." << std::endl;
    }

    if (twoShip.valid_space(checkCoord2)) {
        std::cout << "(3, 3) is part of the Two-size ship." << std::endl;
    } else {
        std::cout << "(3, 3) is not part of the Two-size ship." << std::endl;
    }

    // Simulate hitting a space
    if (twoShip.is_hit(checkCoord1)) {
        std::cout << "(2, 2) has already been hit." << std::endl;
    } else {
        std::cout << "Hitting (2, 2)." << std::endl;
        twoShip.hit(checkCoord1); 
        twoShip.hit(checkCoord3);
        for (auto& x : twoShip.get_spaces()) {
            std::cout << x.second << std::endl;
        }
        std::cout << "(2, 2) has been hit." << std::endl;
    }

    // Check if the ship is sunk
    if (twoShip.is_sunk()) {
        std::cout << "Two-size ship is sunk." << std::endl;
    } else {
        std::cout << "Two-size ship is not yet sunk." << std::endl;
    }

    return 0;
}
