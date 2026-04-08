#pragma once
#include "./GameField.h"


#define MIN_FIELD_SIZE 3
#define MAX_FIELD_SIZE 9


struct GameController {
    GameField game;
    void startGame();
    void gameLoop();
};
