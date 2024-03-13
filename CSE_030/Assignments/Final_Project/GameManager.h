#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <sstream>
#include <iostream>
#include <vector>
#include "GameState.h"

class GameManager {
    GameState game;
    int gameDifficulty;
    bool isRunning;

    GameManager() {
        isRunning = false;
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
            if (game.done) {
                break;
            }
            Vec move = playerMove();
            game.play(move.x, move.y);
            if (gameType == 1) {
                system("clear");
                std::cout << game << std::endl;
            }
            if (game.done) {
                break;
            }
            move = otherMove(gameType);
            game.play(move.x, move.y);
        }
    }

    Vec playerMove() {//player move 

    }

    Vec otherMove(int gameType) {
        switch(gameType) {
            case 1: {
                return playerMove();
            }
            case 2: {
                return validMove();
            }
            case 3: {
                return findBestMove();
            }
        }
    }

    Vec validMove() {}//easy
    Vec findBestMove() {//impossible 

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

    void printGame(std::vector<std::string> guesses, std::string answer, std::string gameCondition, std::vector<std::vector<std::string>> colors) {
        system("clear");

    }
    // =========== Console printing methods ===========

    void play() {
    }
};

#endif