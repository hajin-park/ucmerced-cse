#ifndef KEYBOARD_H
#define KEYBOARD_H

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"

#include <iostream>
#include <fstream>
#include <vector>

struct Keyboard {
    Keyboard() {
        gameState = 0;
        colorOptions = {BLACK, YELLOW, GREEN, RESET};
        prevColors = {{RESET}};
        letters = {
            {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'},
            {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'},
            {'Z', 'X', 'C', 'B', 'N', 'M', 'V'}
        };
    }

    int gameState, prevGameState;
    std::vector<std::string> colorOptions;
    std::vector<std::vector<std::string>> colors, prevColors;
    std::vector<std::vector<char>> letters;

    void printKeyboard() {
        for (int i = 0; i < letters.size(); i++) {
            std::string spaces((50 - (letters[i].size() * 5))/2, ' ');
            std::cout << spaces;
            for (int j = 0; j < letters[i].size(); j++) {
                std::cout << colors[i][j] << " --- " << RESET;
            }
            std::cout << std::endl << spaces;
            for (int j = 0; j < letters[i].size(); j++) {
                std::cout << colors[i][j] << "| " << letters[i][j] << " |" << RESET;
            }
            std::cout << std::endl << spaces;
            for (int j = 0; j < letters[i].size(); j++) {
                std::cout << colors[i][j] << " --- " << RESET;
            }
            std::cout << std::endl;
        }
    }

    void getColors() {
        std::string line;
        for (std::vector<char> row : letters) {
            colors.push_back({});
            for (char c : row) {
                std::ifstream file("../data/colors.txt");
                colors.back().push_back(colorOptions[3]);
                for (int i = 0; i < 3; i++) {
                    getline(file, line);
                    if (line.find(c) != std::string::npos) colors.back().back() = colorOptions[i];
                }
            }
        }
    }
};

#endif