#include "../Header FIles//GameField.h"
#include <iostream>

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

void GameField::print() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            if (field[i][j] == 0)
                std::cout << "_ ";
            else
                std::cout << field[i][j] << " ";

        }
        std::cout << std::endl;
    }
}

// ========Перевірка можливості руху===============
bool GameField::canMove(int row, int col) const {
    if (row < 0 || row >= size || col < 0 || col >= size)
        return false;
    if ((row == emptyRow && abs(col - emptyCol) == 1) ||
        (col == emptyCol && abs(row - emptyRow) == 1)) {
        return true;
        }

    return false;
}


bool GameField::moveTile(int value) {
    int tileRow = -1, tileCol = -1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (field[i][j] == value) {
                tileRow = i;
                tileCol = j;
                break;
            }
        }
    }

    if (tileRow == -1) return false;

    if (!canMove(tileRow, tileCol))
        return false;

    field[emptyRow][emptyCol] = field[tileRow][tileCol];
    field[tileRow][tileCol] = 0;

    emptyRow = tileRow;
    emptyCol = tileCol;

    return true;
}


// =================Перевірка виграшу ============
bool GameField::isWin() const {
    int expected = 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            if (i == size - 1 && j == size - 1) {
                if (field[i][j] != 0)
                    return false;
            } else {
                if (field[i][j] != expected)
                    return false;
                expected++;
            }

        }
    }

    return true;
}

// ============== Реалізація методу який дозволяє керувати елементом _ ==========
bool GameField::moveEmpty(char direction) {
    int newRow = emptyRow;
    int newCol = emptyCol;

    switch (direction) {
        case 'w': newRow--; break;
        case 's': newRow++; break;
        case 'a': newCol--; break;
        case 'd': newCol++; break;
        default: return false;
    }

    if (newRow < 0 || newRow >= size || newCol < 0 || newCol >= size)
        return false;

    field[emptyRow][emptyCol] = field[newRow][newCol];
    field[newRow][newCol] = 0;

    emptyRow = newRow;
    emptyCol = newCol;

    return true;
}