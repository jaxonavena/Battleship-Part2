cmake_minimum_required(VERSION 3.21)
project(battleship)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(battleship)

target_sources(battleship PRIVATE
    "src/main.cpp"
    "src/setup.cpp"
    "src/player.cpp"
    "src/ships.cpp"
)

#Includes the header files from src
target_include_directories(battleship PRIVATE 
    "src"
)

target_compile_options(battleship PRIVATE
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-g -Wall -Wextra -DCMAKE_EXPORT_COMPILE_COMMANDS=1> # Apply -O1 if the compiler is not MSVC
)
#Use this command to build: cmake -B build && make -C build
