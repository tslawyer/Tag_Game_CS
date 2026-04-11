#include "../Header FIles/GameController.h"
#include <iostream>

void GameController::startGame() {
    int size;

    while (true) {
        try {
            std::cout << "Enter field size (" << MIN_FIELD_SIZE << "-" << MAX_FIELD_SIZE << "): ";

            if (!(std::cin >> size)) {
                throw "Invalid input type";
            }

            if (size < MIN_FIELD_SIZE || size > MAX_FIELD_SIZE) {
                throw std::runtime_error("Size out of range");
            }

            break;
        }
        catch (const char* msg) {
            std::cout << "Error: " << msg << "\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    game.init(size);
    game.state = GameField::Active;

    gameLoop();
}
void GameController::gameLoop() {
    while (game.state == GameField::Active) {
        try {
            std::cout << game;

            std::cout << "\nState: ";
            if (game.state == GameField::Active)
                std::cout << "Active\n";
            else if (game.state == GameField::Win)
                std::cout << "Win\n";
            else if (game.state == GameField::Interrupted)
                std::cout << "Interrupted\n";

            std::cout << "\nUse WASD (space to exit): ";

            std::cin.ignore(1000, '\n');
            char input;

            if (!(std::cin >> std::noskipws >> input)) {
                throw "Incorrect symbol entered";
            }

            if (input == ' ') {
                game.state = GameField::Interrupted;
                break;
            }

            game && input;

            if (game.isWin()) {
                game.state = GameField::Win;
            }
        }
        catch (const char* msg) {
            std::cout << "Exception: " << msg << "\n";
        }
        catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << "\n";
        }
    }

    std::cout << game;

    if (game.state == GameField::Win) {
        std::cout << "YOU WIN!\n";
    } else if (game.state == GameField::Interrupted) {
        std::cout << "GAME INTERRUPTED\n";
    }
}