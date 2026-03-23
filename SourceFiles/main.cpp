#include <iostream>
#include "../Header FIles/GameField.h"
#include "../Header FIles/GameController.h"



int main() {
    GameField game;
    int size;


    // =========================ІНІЦІАЛІЗАЦІЯ ПОЛЯ======================
    while (true) {
        constexpr int MIN_SIZE = MIN_FIELD_SIZE;
        constexpr int MAX_SIZE = MAX_FIELD_SIZE;
        std::cout << "Enter field size (" << MIN_SIZE << "-" << MAX_SIZE << "): ";
        std::cin >> size;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Enter a number.\n";
            continue;
        }

        if (size < MIN_SIZE || size > MAX_SIZE) {
            std::cout << "Size must be between " << MIN_SIZE << " and " << MAX_SIZE << ".\n";
            continue;
        }


        break;
    }

    game.init(size);

    // ======================ХОДИ====================================
    while (true) {
        game.print();

        std::cout << "\nUse WASD (q to exit): ";
        std::string input;
        std::cin >> input;

        char move = input[0];

        if (move == 'q') break;

        if (!game.moveEmpty(move)) {
            std::cout << "Invalid move!\n";
        }

        if (game.isWin()) {
            game.print();
            std::cout << "YOU WIN!\n";
            break;
        }
    }

    return 0;
}