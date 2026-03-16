cmake_minimum_required(VERSION 4.1)
project(Tag_Game_CS)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tag_Game_CS SourceFiles/main.cpp
        "Header FIles/GameField.h"
        SourceFiles/game.cpp
        SourceFiles/GameField.cpp)
