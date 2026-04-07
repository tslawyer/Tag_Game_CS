#pragma once
#include <iostream>

struct GameField {
    //GameField.h

    // ==== Стан гри=====
    enum GameState {
        Active,
        Win,
        Interrupted
    };


    int size;
    int** field;
    int emptyRow;
    int emptyCol;
    GameState state;

    void init(int d);

    //===== Сигнатури для перевірки виграшу і ходу =====
    bool canMove(int row, int col) const;
    bool isWin() const;
    bool moveEmpty(char direction);
    void operator&&(int value);

};

std::ostream& operator<<(std::ostream& out, const GameField& gf);