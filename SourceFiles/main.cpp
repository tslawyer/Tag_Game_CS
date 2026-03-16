#include <iostream>
#include "../Header FIles/GameField.h"


int main() {

    GameField game;
    int size;

    while (true) {

        std::cout << "Enter field size: ";
        std::cin >> size;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Enter a number.\n";
            continue;
        }

        if (size <= 1) {
            std::cout << "Size must be greater than 1\n";
            continue;
        }

        break;
    }

    game.init(size);
    game.print();

    return 0;
}