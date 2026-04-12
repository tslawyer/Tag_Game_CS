#include "../Header FIles/GameController.h"
#include <iostream>
#include <ctime>

void GameController::startGame() {
    logFile.open("ivashchenko_logFile.txt", std::ios::app);

    if (!logFile.is_open()) {
        std::cout << "Failed to open log file\n";
    }

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
            std::cout << "Exception: " << msg << "\n";
            logFile << "Error: " << msg << "\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << "\n";
            logFile << "Error: " << e.what() << "\n";
        }
    }

    game.init(size);

    time_t now = time(0);
    logFile << "=== GAME START ===\n";
    logFile << "Time: " << ctime(&now);
    logFile << "Field size: " << size << "\n";
    logFile << "Initial field:\n";
    logFile << game << "\n";
    logFile << "State: Active\n\n";

    game.state = GameField::Active;

    gameLoop();
}

void GameController::gameLoop() {
    int moveCount = 0;

    while (game.state == GameField::Active) {
        try {
            logFile << "$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$\n";
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

            logFile << "Move #" << ++moveCount << "\n";
            logFile << "Input: " << input << "\n";

            if (input == ' ') {
                game.state = GameField::Interrupted;


                logFile << "State: Interrupted\n\n";
                break;
            }

            game && input;

            if (game.isWin()) {
                game.state = GameField::Win;
            }

            logFile << "Field after move:\n";
            logFile << game << "\n";

            logFile << "State: ";
            if (game.state == GameField::Active)
                logFile << "Active\n\n";
            else if (game.state == GameField::Win)
                logFile << "Win\n\n";
            else if (game.state == GameField::Interrupted)
                logFile << "Interrupted\n\n";
        }
        catch (const char* msg) {
            std::cout << "Exception: " << msg << "\n";
            logFile << "Error: " << msg << "\n";
        }
        catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << "\n";
            logFile << "Error: " << e.what() << "\n";
        }
    }

    std::cout << game;

    if (game.state == GameField::Win) {
        std::cout << "YOU WIN!\n";
    } else if (game.state == GameField::Interrupted) {
        std::cout << "GAME INTERRUPTED\n";
    }

    time_t now = time(0);
    logFile << "=== GAME END ===\n";
    logFile << "Time: " << ctime(&now);

    if (game.state == GameField::Win) {
        logFile << "Result: WIN\n";
    } else if (game.state == GameField::Interrupted) {
        logFile << "Result: INTERRUPTED\n";
    }

    logFile << "====================\n\n";

    logFile.close();
}