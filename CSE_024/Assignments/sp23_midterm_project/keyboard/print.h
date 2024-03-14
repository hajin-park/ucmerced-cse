#ifndef PRINT_H
#define PRINT_H
#define RESET "\033[0m"

#include <iostream>
#include <vector>

using namespace std;


void printTop(string COLOR) { cout << COLOR << " --- " << RESET; }
void printMiddle(char c, string COLOR) { cout << COLOR << "| " << c << " |" << RESET; }
void printBottom(string COLOR) { cout << COLOR << " --- " << RESET; }
void printKeyboard(vector<vector<char>> keyboard, vector<vector<string>> colors) {
    for (int i = 0; i < keyboard.size(); i++) {
        string spaces((50 - (keyboard[i].size() * 5))/2, ' ');
        cout << spaces;
        for (int j = 0; j < keyboard[i].size(); j++) {
            printTop(colors[i][j]);
        }
        cout << endl << spaces;
        for (int j = 0; j < keyboard[i].size(); j++) {
            printMiddle(keyboard[i][j], colors[i][j]);
        }
        cout << endl << spaces;
        for (int j = 0; j < keyboard[i].size(); j++) {
            printBottom(colors[i][j]);
        }
        cout << endl;
    }
}

#endif