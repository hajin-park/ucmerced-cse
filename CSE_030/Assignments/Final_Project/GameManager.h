// Contributers:
// Hajin Park
// Aaron Romero
// Aram Shkhyan

#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <sstream>
#include <iostream>
#include "GameState.h"
#include "MoveManager.h"


struct GameManager {
    GameState game;
    int gameDifficulty;

    GameManager() {
    }

    void start() {
        system("clear");
        printMenu();
        int userOption;

        // Main game loop, user chooses opponent or exits program
        while (std::cin >> userOption) {
            std::cin.ignore();

            switch (userOption) {
                case 1:
                case 2:
                case 3: {
                    GameState game;
                    this->game = game;
                    runGame(userOption);
                    break;
                }
                case 4: {
                    return;
                }
                default: {
                    std::cout << "Please pick one of the options" << std::endl;
                    continue;
                }
            }
            
            system("clear");
            printMenu();
        }
    }

    void runGame(int gameType) {
        while (true) {
            system("clear");
            std::cout << game << std::endl;

            // User makes first move
            Vec move = playerMove(game);
            game.play(move.x, move.y);
            system("clear");
            std::cout << game << std::endl;

            // Print results and wait for user input if game is done
            if (game.done) {
                system("clear");
                std::cout << game << std::endl;
                printResult(game.winner);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get(); // Wait for user to press Enter
                break;
            }

            // Opponents makes next move
            move = opponentMove(gameType, game);
            game.play(move.x, move.y);
            system("clear");
            std::cout << game << std::endl;

            // Print results and wait for user input if game is done
            if (game.done) {
                system("clear");
                std::cout << game << std::endl;
                printResult(game.winner);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get(); // Wait for user to press Enter
                break;
            }
        }
    }

    // =========== Console printing methods ===========
    void printMenu() {
        std::cout << "==========================" << std::endl;
        std::cout << "  WELCOME TO TIC-TAC-TOE " << std::endl;
        std::cout << "==========================" << std::endl << std::endl << std::endl;
        std::cout << "1. Play Against Human" << std::endl;
        std::cout << "2. Play Against Easy AI" << std::endl;
        std::cout << "3. Play Against Impossible AI" << std::endl;
        std::cout << "4. Exit\n\n" << std::endl;
        std::cout << "Select an option: ";
    }

    void printResult(int winner) {
        if (winner == 0) {
            std::cout << "Player X has won!" << std::endl;
        } else if (winner == 1) {
            std::cout << "Player O has won!" << std::endl;
        } else if (winner == 2) {
            std::cout << "Draw!" << std::endl;
        } else {
            std::cout << "Game in progress!" << std::endl;
        }
        std::cout << "Press [enter] to continue" << std::endl;
    }
    // =========== Console printing methods ===========
};

#endif