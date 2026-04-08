#include "../Header FIles/GameController.h"
#include <iostream>

void GameController::startGame() {
    int size;

    while (true) {
        std::cout << "Enter field size (" << MIN_FIELD_SIZE << "-" << MAX_FIELD_SIZE << "): ";
        std::cin >> size;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input.\n";
            continue;
        }

        if (size < MIN_FIELD_SIZE || size > MAX_FIELD_SIZE) {
            std::cout << "Wrong size!\n";
            continue;
        }

        break;
    }

    game.init(size);
    game.state = GameField::Active;

    gameLoop();
}

void GameController::gameLoop() {
    while (game.state == GameField::Active) {

        std::cout << game;

        std::cout << "\nState: ";
        if (game.state == GameField::Active)
            std::cout << "Active\n";
        else if (game.state == GameField::Win)
            std::cout << "Win\n";
        else if (game.state == GameField::Interrupted)
            std::cout << "Interrupted\n";

        std::cout << "\nUse WASD (space to exit): ";

        std::cin.ignore(1000, '\n'); // очищаем буфер
        char input;
        std::cin >> std::noskipws >> input;

        if (input == ' ') {
            game.state = GameField::Interrupted;
            break;
        }

        game && input;

        if (game.isWin()) {
            game.state = GameField::Win;
        }
    }

    std::cout << game;

    if (game.state == GameField::Win) {
        std::cout << "YOU WIN!\n";
    } else if (game.state == GameField::Interrupted) {
        std::cout << "GAME INTERRUPTED\n";
    }
}