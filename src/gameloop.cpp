/*
Program: GameLoop class
Description: This class represents the main gamplay loop.  This is taken out
of main to keep the flow of the game more clear, and to prevent a large main
file.  The loop is to ask player 1 where they want to shoot, update their board
and player 2's board, then check if game is over.  If game is not over, then
player 2 gets their turn.
Author: Team 9
*/
#include "gameloop.hpp"
#include "player.hpp"

#include <iostream>
#include <limits>
#include <unistd.h>
#include <utility>
#include <random>


using namespace std;

//Initialize gameplay loop by taking rvalue refs
GameplayLoop::GameplayLoop(Player&& p1, Player&& p2) :  //use references to prevent memory issues
                           playerOne(move(p1)), playerTwo(move(p2)), //create players within this class.
                           currentTurn(1){} //this moves the player objects

//Simple function that returns true if a shot is valid to take
bool GameplayLoop::verifyShot(const size_t row, const size_t col) const {
    if (row >= 0 && row < 10 && col >= 0 && col < 10) { // make sure it's on the board
      //If the cell of the top board is X or O that means the shot has already been taken
      if ( !currentTurn ) {
          if ( playerOne.getCellTopBoard(row, col) == 'X' || playerOne.getCellTopBoard(row, col) == 'O' ) { //check if shot already taken
              cout << "Player 1 took this shot already.";
              return false; //verify shot as bad, don't continue
          }
      } else {
          if ( playerTwo.getCellTopBoard(row, col) == 'X' || playerTwo.getCellTopBoard(row, col) == 'O' ) { //check if already takena
              cout << "Player 2 took this shot already.";
              return false; //verify shot as bad, don't continue
          }
      }
      // cout << "SHOT IS VALID\n";
      return true; //otherwise shot is good, continue
    }
    // cout << "SHOT IS INVALID\n";
    return false;
}

//This function gets a shot from the user in the format of RowCol
pair<size_t, size_t> GameplayLoop::getShot() const {
    size_t shot_row = 0; //Value of the input
    char column = 'a'; //Value of the input as a char

    while ( true ) {
        cout << "Please enter your shot's row: "; //min 1 - max 10
        //Loop to validate the rows
        //!(cin >> shot_row) means cin to fin has failed in some way, while also grabbing input
        while ( !(cin >> shot_row) || ( shot_row > 10 ) || ( shot_row < 1 ) ) {
            //Clears the failure state and then throws everything out of the input stream
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Bad number (min 1, max 10) please try again: ";
        }
        shot_row = shot_row - 1; //0 indexed now

        //then column
        cout << "Please enter your shot's column: "; //min a - max j

        //Loop to validate the column
        //!(cin >> column) means cin to fin has failed in some way, while also grabbing input
        while ( !(cin >> column ) || ( tolower(column) > 'j' ) || ( tolower(column) < 'a' ) ) {
            //Clears the failure state and then throws everything out of the input stream
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Bad Letter ( a through j) please try again: ";
        }

        //Now verify to see if the shot has already been taken
        //If the shot is valid return the coords from the function
        if ( !verifyShot(shot_row, playerOne.convert_chartoIndex( column ))) {
            cout << "You have already taken this shot! Try again.";
        } else {
            return make_pair(shot_row, playerOne.convert_chartoIndex( column )); //create pair to return for shot validation
        }
    }
}

//This function gets a shot from the user in the format of RowCol
pair<size_t, size_t> GameplayLoop::getAIShot() {
    // cout << "Inside getAIShot()";

    size_t shot_row = -1;
    size_t shot_col = -1;
// LEVEL 1
    if (playerTwo.this_ai_difficulty == 1){
      // cout << "\nLevel 1 reached";
      while(!verifyShot(shot_row, shot_col)){
        // cout <<"\nin the while loop";

        shot_row = rand() % 10; // Random row (0-9)
        shot_col = rand() % 10; // Random column (0-9)

      }
      // cout << "\nROW COL: ";
      // cout << shot_row;
      // cout << " ";
      // cout << shot_col;
      return make_pair(shot_row, shot_col); //create pair to return for shot validation
// LEVEL 2
    } else if (playerTwo.this_ai_difficulty == 2) {
    // cout << "Level 2 AI reached" << endl;

    while (true) {
      // If there are no next shots to try, reset the last hit status
      if (playerTwo.nextShots.size() == 0) {
        playerTwo.lastHit.first = false;
      }

        // If the last shot was a hit, prioritize firing in adjacent spots
        if (playerTwo.lastHit.first == true) {
          std::pair<size_t, size_t> coord = playerTwo.nextShots.front();
          playerTwo.nextShots.erase(playerTwo.nextShots.begin());
          shot_row = coord.first;
          shot_col = coord.second;

          if (verifyShot(shot_row, shot_col)) {
              // If the shot is a hit, continue targeting adjacent spaces
            bool is_hit = its_a_hit(playerTwo, playerOne, coord);
            if (is_hit) {
              // Add adjacent spots to the nextShots queue
              if (shot_row > 0) playerTwo.nextShots.push_back({shot_row - 1, shot_col}); // Up
              if (shot_row < 9) playerTwo.nextShots.push_back({shot_row + 1, shot_col}); // Down
              if (shot_col > 0) playerTwo.nextShots.push_back({shot_row, shot_col - 1}); // Left
              if (shot_col < 9) playerTwo.nextShots.push_back({shot_row, shot_col + 1}); // Right

              // Mark last hit for future reference
              playerTwo.lastHit = {true, {shot_row, shot_col}};
            } else {
              // If no hit, mark last hit as false
              playerTwo.lastHit.first = false;
            }

            return make_pair(shot_row, shot_col); // Return the shot for validation
          }
        } else {
          // Fire randomly if no hit has been made recently
          shot_row = rand() % 10; // Random row (0-9)
          shot_col = rand() % 10; // Random column (0-9)
          std::pair<size_t, size_t> coord = make_pair(shot_row, shot_col);

          if (verifyShot(shot_row, shot_col)) {
            // If the shot is a hit, begin targeting adjacent spots
            bool is_hit = its_a_hit(playerTwo, playerOne, coord);

            if (is_hit) {
              // Add adjacent spots to the nextShots queue
              if (shot_row > 0) playerTwo.nextShots.push_back({shot_row - 1, shot_col}); // Up
              if (shot_row < 9) playerTwo.nextShots.push_back({shot_row + 1, shot_col}); // Down
              if (shot_col > 0) playerTwo.nextShots.push_back({shot_row, shot_col - 1}); // Left
              if (shot_col < 9) playerTwo.nextShots.push_back({shot_row, shot_col + 1}); // Right

              // Mark last hit for future reference
              playerTwo.lastHit = {true, {shot_row, shot_col}};
            } else {
              // If no hit, continue firing randomly
              playerTwo.lastHit.first = false;
            }

            return make_pair(shot_row, shot_col); // Return the shot for validation
          }
        }
    }

// LEVEL THREE
    } else if (playerTwo.this_ai_difficulty == 3){
      // cout << "Level 3 reached";
      while(!verifyShot(shot_row, shot_col)){
        // grabs a random coord from list of ship coords and will check if it has shot there already then shoot if not
        size_t outerIndex = rand() % playerOne.playerShips.size();
        size_t innerIndex = rand() % playerOne.playerShips[outerIndex].size();
        std::pair<size_t,size_t> coords = playerOne.playerShips[outerIndex][innerIndex];
        shot_row = coords.first; // Random row (0-9)
        shot_col = coords.second; // Random column (0-9)
      }
      return make_pair(shot_row, shot_col); //create pair to return for shot validation

    } else {
      cout << "No difficulty selected";
    }
}

bool GameplayLoop::its_a_hit(Player& main, Player& target, pair<size_t, size_t> coord) {
  int flag = 0;

  for (int i = 1; i < main.getNumShips() + 1; i++) {
      if (target.getShip(i)->valid_space(coord)) { //if is_hit, update board and ship
          flag = i; //figure out which ship has been marked
          break; //exit loop
      }
  }

  bool is_hit;
  if (flag > 0) {
    is_hit = true;
  }
  else {
    is_hit = false;
  }

  if (is_hit) {
        //hit
        cout << "Hit your opponent!\n" << endl;
        main.top_board.update(coord, true); //update bottom board
        target.getShip(flag)->hit(coord); //hit the ship
        target.bottom_board.update(coord, true); // update bottom board
        return true;
    }
    else {
        cout << "Missed your opponent!\n" << endl;
        main.top_board.update(coord, false); //update with miss
        target.bottom_board.update(coord, false); //update with miss
        return false;
    }
}

bool GameplayLoop::special_attack(Player& main, Player& target) {
  if (main.this_is_ai && main.has_used_special_attack == false) {
    // cout << "HASNT USED SPECIAL\n";
    int use_special = rand() % 10; // Random row (0-9)
    if (use_special == 5) { // 5 is arbitrary, 10% chance to use the special attack
      // cout << "IN SPECIAL reg\n";
      // Generate 5 random coords and then validate each. All three must pass or three more will be generated.
      std::vector<std::pair<size_t, size_t>> special_attack_coords;
      int flag = 0;
      while (flag == 0) {
        for (int i = 0; i < 3; i++) {
          // Generate coorstd::pair<bool, int> values = d
          size_t shot_row = rand() % 10; // Random row (0-9)
          size_t shot_col = rand() % 10; // Random column (0-9)
          // cout << "NEW COORD: " << shot_row << ", " << shot_col << "\n";
          std::pair<size_t, size_t> coord = make_pair(shot_row, shot_col);
          special_attack_coords.push_back(coord);
        }

        // Validate the coords
        for (std::pair<size_t, size_t> coord : special_attack_coords) {
          // std::cout << "Putting" << coord.first << ", " << coord.second << "in the list\n";
          if (verifyShot( coord.first, coord.second)) {
            flag = 1; // All shots need to be valid
          }      
          else {
            flag = 0;
            special_attack_coords.clear();
            break;
          }
        }
      } 

      if (flag == 1) { // Double check if all coords ended up being valid..
        for (std::pair<size_t, size_t> coord : special_attack_coords) {
          // shoot da shots
          its_a_hit(main, target, coord);
        }
        main.has_used_special_attack = true;
        // cout << "AI used special attack";
        return true;     // 
      }
    } else {
      return false;
    }
  } else {
    if (main.ask_to_use_special_attack()) {
      // cout << "IN SPECIAL reg\n";
      // Generate 5 random coords and then validate each. All three must pass or three more will be generated.
      std::vector<std::pair<size_t, size_t>> special_attack_coords;
      int flag = 0;
      while (flag == 0) {
        for (int i = 0; i < 3; i++) {
          // Generate coorstd::pair<bool, int> values = d
          size_t shot_row = rand() % 10; // Random row (0-9)
          size_t shot_col = rand() % 10; // Random column (0-9)
          // cout << "NEW COORD: " << shot_row << ", " << shot_col << "\n";
          std::pair<size_t, size_t> coord = make_pair(shot_row, shot_col);
          special_attack_coords.push_back(coord);
        }

        // Validate the coords
        for (std::pair<size_t, size_t> coord : special_attack_coords) {
          // std::cout << "Putting" << coord.first << ", " << coord.second << "in the list\n";
          if (verifyShot( coord.first, coord.second)) {
            flag = 1; // All shots need to be valid
          }      
          else {
            flag = 0;
            special_attack_coords.clear();
            break;
          }
        }
      } 

      if (flag == 1) { // Double check if all coords ended up being valid..
        for (std::pair<size_t, size_t> coord : special_attack_coords) {
          // shoot da shots
          its_a_hit(main, target, coord);
        }
        main.has_used_special_attack = true;
        // cout << "player used special";
        return true;     // 
      }
    } else {
        return false;
    }
  }
  
}

void GameplayLoop::playerOneTurn() {
    //Player 1 takes their turn
    cout << "Player 1's Turn." << endl; //output player turn
    playerOne.print_Board(); //print player 1's board

    if ( !playerOne.has_used_special_attack ) {
      if (special_attack(playerOne, playerTwo)) {
        return;
      }
    }

    pair<size_t, size_t> coord = getShot();//pair that gets the shot from the user
    its_a_hit(playerOne, playerTwo, coord); //output ship
    playerOne.print_Board(); //reprint board(s)
    sleep(4); //sleep for hot seat, wait for next player
    system("clear"); //clear the terminal before the next action
}

void GameplayLoop::playerTwoTurn() {
    //Player 2 takes their turn
    if (playerTwo.this_is_ai) {
      cout << "AI's Turn." << endl; //output player's board
    }
    else {
      cout << "Player 2's Turn." << endl; //output player's board
    }

    playerTwo.print_Board(); //print player 2's board
    pair<size_t, size_t> coord;

    if (playerTwo.this_is_ai){
      // cout << "getting ai shot";
      if ( !playerTwo.has_used_special_attack ) {
        if (special_attack(playerTwo, playerOne)) {
          return;
        }
      }
      coord = getAIShot(); //pair that gets the shot from the AI
    } else {
      // cout << "Getting regular player2 shot";
      if ( !playerTwo.has_used_special_attack ) {
        if (special_attack(playerTwo, playerOne)) {
          return;
        }
      }
      coord = getShot(); //pair that gets the shot from the user
    }

    its_a_hit(playerTwo, playerOne, coord); //output ship
    playerTwo.print_Board(); //reprint board(s)
    sleep(4); //sleep for hot seat.
    system("clear"); //clear the terminal before the next action

}

bool GameplayLoop::gameOver() const {
    // Iterate through both players' ships and return true iff (if and onl if) all ships are sunk for one player
    const int numShips = playerOne.getNumShips(); //num ships to check for
    bool playerOneSunk = true; //set flag
    bool playerTwoSunk = true; //set flag
    for (int i = 1; i < numShips + 1; i++) { //check over all ships
        if (!(playerOne.getShip(i)->is_sunk())) { //check all ships are sunk
            playerOneSunk = false; //one ship is not sunk, game NOT over
        }
    }
    for (int i = 1; i < numShips + 1; i++) { //check player two's ships
        if (!(playerTwo.getShip(i)->is_sunk())) { //check all ships owned by player 2
            playerTwoSunk = false; //one ship not sunk, game NOT over
        }
    }
    if (playerOneSunk) { //check if player one loses
        cout << playerOne.returnName() << "'s ships have been sunk. " //use name to show who loses
                  << playerTwo.returnName() << " wins!" << endl; //show name to see who wins
        return true;  //for game play loop class
    }
    else if (playerTwoSunk) { //check if player two loses
        cout << playerTwo.returnName() << "'s ships have been sunk. " //use player two name to lose
                  << playerOne.returnName() << " wins!" << endl; //use player one name to lose
        return true; //there is a loss here
    }
    return false;
}
void GameplayLoop::start() {

    // Main loop
    while ( true ) {
        //Get the current player
        //(1 + 1) % 2 = 0 which is player one
        //(0 + 1) % 2 = 1 player two
        ++currentTurn %= 2;
        //if currentTurn == 0
        if ( !currentTurn ) {
            playerOneTurn(); //get the correct player's turn
        } else {
            playerTwoTurn();
        }
        //Check if game over
        //If the game is over, exit the loop
        if( gameOver() ) {
            return;
        }

    }
}
