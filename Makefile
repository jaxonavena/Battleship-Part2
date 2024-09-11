#Make file for Project 1 581
CC=g++
#If adding new cpp files, add them beneath here
all: main.cpp src/player.cpp src/setup.cpp src/ships.cpp
	g++ -c src/player.cpp
	g++ -c src/setup.cpp
	g++ -c src/ships.cpp
	$(CC) -o battleship main.cpp
#clean
clean: 
	rm player.o setup.o ships.o battleship
