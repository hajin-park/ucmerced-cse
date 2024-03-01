#ifndef WORDLE_H
#define WORDLE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <random>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <cmath>
#include "game_screen.h"

using namespace std;


string getRandomWord() {
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(0, 2315); // define the range
    int number = distr(gen);
    string answer_lower;
    ifstream file("words.txt");
    for (int i = 0; i < number; i++) getline(file, answer_lower);
    file.close();
    return answer_lower;
}

vector<string> guessColors(string guess_upper, string answer_upper) {
    vector<string> color = {BLACK, BLACK, BLACK, BLACK, BLACK};

    // 10 iterations - check guess input word twice
    for (int i = 0; i < 10; i++) {
        size_t index = answer_upper.find(guess_upper[(i % 5)]);

        // First five iterations
        if (floor((float)i/float(5)) == 0) {

            // Letter is an exact match
            if (index != string::npos && index == (i % 5)) {
                color[index] = GREEN;
                answer_upper[index] = ' ';
            }
        
        // Last five iterations
        } else {
            if (index != string::npos) {

                // Letter is an indirect match
                color[i % 5] = YELLOW;
                answer_upper[index] = ' ';
            }
        }
    }
    return color;
}

void updateKeyboardFile(vector<vector<string>> colors, string guess_upper) {
    string black_keys;
    string yellow_keys;
    string green_keys;

    ifstream keyboard_file_in("keyboard.txt");

    // Keep track of previous keyboard colors
    if (keyboard_file_in.is_open()) {
        string line;
        getline(keyboard_file_in, line);
        black_keys = line + string(5, ' ');
        getline(keyboard_file_in, line);
        yellow_keys = line + string(5, ' ');
        getline(keyboard_file_in, line);
        green_keys = line + string(5, ' ');
    } else cerr << "Error: File could not be opened" << endl;
    keyboard_file_in.close();

    ofstream keyboard_file_out("keyboard.txt", ios::trunc);
    if (keyboard_file_out.is_open()) {

        // Add new colors to keyboard color rows
        for (int i = 0; i < 5; i++) {
            if (colors.back()[i] == BLACK) {
                black_keys[black_keys.size()-5+i] = guess_upper[i];
            } else if (colors.back()[i] == YELLOW) {
                yellow_keys[yellow_keys.size()-5+i] = guess_upper[i];
            } else if (colors.back()[i] == GREEN) {
                green_keys[green_keys.size()-5+i] = guess_upper[i];
            }
        }
        keyboard_file_out << black_keys << '\n' << yellow_keys << '\n' << green_keys;
    } else cerr << "Error: File could not be opened" << endl;
    keyboard_file_out.close();
}

void startGame(Stats& stats) {
    vector<string> guesses;
    vector<vector<string>> colors;
    string gameState = "active";
    bool valid_guess = false;
    string answer = getRandomWord();
    transform(answer.begin(), answer.end(), answer.begin(), ::toupper);

    while (gameState == "active") {
        bool valid_guess = false;
        string guess;
        string line;

        while (!valid_guess) {

            // Check if input guess is a valid 5-letter word
            ifstream allowed_words_file("allowed.txt");
            ifstream answer_words_file("words.txt");
            cout << "Enter guess: ";
            cin >> guess;
            while (getline(allowed_words_file, line) || getline(answer_words_file, line)) {
                if (line.find(guess) != string::npos && guess.size() == 5) {
                    valid_guess = true;
                    break;
                }
            }
            allowed_words_file.close();
            answer_words_file.close();
        }

        // Assign colors to letters according to Wordle logic
        transform(guess.begin(), guess.end(), guess.begin(), ::toupper);
        guesses.push_back(guess);
        colors.push_back(guessColors(guess, answer));
        updateKeyboardFile(colors, guess);

        // Check game-ending conditions according to Wordle logic
        if (guess == answer) gameState = "win";
        else if (guesses.size() == 6) gameState = "lose";

        printGameScreen(guesses, answer, gameState, colors);
    }

    // Update game history stats
    stats.Words.push_back(answer);
    stats.Attempts.push_back(guesses.size());
    stats.Wins.push_back((gameState == "win") ? "Yes" : "No");

    cin.ignore();
    while (!gameState.empty()) getline(cin, gameState);
}

#endif