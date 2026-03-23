#pragma once

struct GameField {

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
    void print() const;

    //===== Сигнатури для перевірки виграшу і ходу =====
    bool canMove(int row, int col) const;
    bool moveTile(int value);
    bool isWin() const;
    bool moveEmpty(char direction);

};