# 581_Project1
Project 1 for EECS 581.  This is a battleship game between two players. 

Cmake compatible. A g++ makefile has been added for convenience.

Main class: starts the program and setups up the players, then call the main gameplay loop to keep everything organized.

Board class: encapsulates the printing out and control of the board.  The Player class each has their own board and their view of the opponent's board

Gameloop: This class runs the main gameplay loop.  To prevent having a while true loop in main, this class controls that to prevent memory issues.

Player class: Class which controls each player.  The major method here is the setup method, which has the players set up their boats.  Checks both
that the ships are in a valid location and are not on top of each other.  Here is where indexing comes into play and transitions from 1-indexing
(for the input) to 0 indexing (for the board class).

Setup: Class to control the setup process.  This breaks up the setup into its own class so the main class is not super long.

Ships: This class controls the ship objects.  Methods here impact each ship object, which the players have control of, both on their board and in
a ship pointer array.  Each ship is in charge of knowing where it is and its hit status.

Gameplay: In order to keep it secret, this gameplay style is hot seat.  This means two players are sitting at the same terminal playing the game.
After a player takes a shot, they wait a few seconds (to swap the seat), then the next player goes.

-------------------------------------------

Part 2 Additions

Added an AI opponent to optionally play against. This AI has three difficulty levels.
1. Randomly fires
2. Randomly fires until it lands a hit, then will attempt to hit the same ship by firing in an orthogonally adjacent space. If it misses it continues to fire randomly.
3. Lands a hit every turn.

Added a special attack that any player including the AI can use once per game. It launches three shots at the opponent, but the game randomly selects the coordinate for these shots.
