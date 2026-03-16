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