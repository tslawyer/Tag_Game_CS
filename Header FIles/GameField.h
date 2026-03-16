#pragma once

struct GameField {
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


};