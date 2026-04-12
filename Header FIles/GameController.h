#pragma once
#include "./GameField.h"
#include <fstream>

#define MIN_FIELD_SIZE 3
#define MAX_FIELD_SIZE 9


struct GameController {
    GameField game;
    std::ofstream logFile;
    void startGame();
    void gameLoop();
};
