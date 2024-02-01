#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"

#include <iostream>
#include <vector>


void printTop(std::string COLOR) { std::cout << COLOR << " --- " << RESET; }
void printMiddle(char c, std::string COLOR) { std::cout << COLOR << "| " << c << " |" << RESET; }
void printBottom(std::string COLOR) { std::cout << COLOR << " --- " << RESET; }
void printGameScreen(std::vector<std::string> guesses, std::string answer, std::string gameState, std::vector<std::vector<std::string>> colors) {
    system("clear");

    for (int i = 0; i < guesses.size(); i++) {
        for (int j = 0; j < 5; j++) {
            printTop(colors[i][j]);
        }
        std::cout << std::endl;
        for (int j = 0; j < 5; j++) {
            printMiddle(guesses[i][j], colors[i][j]);
        }
        std::cout << std::endl;
        for (int j = 0; j < 5; j++) {
            printBottom(colors[i][j]);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
    if (gameState == "win") {
        std::cout << "Splendid!" << std::endl << std::endl << std::endl;
        std::cout << "Press [enter] to continue" << std::endl;
    } else if (gameState == "lose") {
        std::cout << "The word was: " << answer << std::endl << std::endl << std::endl;
        std::cout << "Better luck next time!" << std::endl << std::endl << std::endl;
        std::cout << "Press [enter] to continue" << std::endl;
    }
}

#endif