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
