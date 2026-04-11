#include "../Header FIles//GameField.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>

// GameField.cpp
void GameField::init(int d) {
    size = d;

    field = new int*[size];
    for (int i = 0; i < size; i++) {
        field[i] = new int[size];
    }

    int value = size * size - 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == size - 1 && j == size - 1) {
                field[i][j] = 0;
                emptyRow = i;
                emptyCol = j;
            } else {
                field[i][j] = value--;
            }
        }
    }

    if (size % 2 == 0) {
        int temp = field[size - 1][size - 3];
        field[size - 1][size - 3] = field[size - 1][size - 2];
        field[size - 1][size - 2] = temp;
    }
}

bool GameField::canMove(int row, int col) const {
    if (row < 0 || row >= size || col < 0 || col >= size)
        return false;

    if ((row == emptyRow && abs(col - emptyCol) == 1) ||
        (col == emptyCol && abs(row - emptyRow) == 1)) {
        return true;
    }

    return false;
}

bool GameField::isWin() const {
    if (field[size - 1][size - 1] != 0)
        return false;

    int expected = 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            if (i == size - 1 && j == size - 1)
                return true;

            if (field[i][j] != expected)
                return false;

            expected++;
        }
    }

    return true;
}

void GameField::operator&&(char direction) {
    int newRow = emptyRow;
    int newCol = emptyCol;

    switch (direction) {
        case 'w': newRow--; break;
        case 's': newRow++; break;
        case 'a': newCol--; break;
        case 'd': newCol++; break;
        default:
            throw "Invalid move!";

    }

    if (newRow < 0 || newRow >= size || newCol < 0 || newCol >= size) {
        throw std::runtime_error("Went out of boundaries");
    }

    field[emptyRow][emptyCol] = field[newRow][newCol];
    field[newRow][newCol] = 0;
    emptyRow = newRow;
    emptyCol = newCol;
}

std::ostream& operator<<(std::ostream& out, const GameField& gf) {
    for (int i = 0; i < gf.size; i++) {
        for (int j = 0; j < gf.size; j++) {

            if (gf.field[i][j] == 0)
                out << std::setw(4) << "_";
            else
                out << std::setw(4) << gf.field[i][j];
        }
        out << '\n';
    }
    return out;
}