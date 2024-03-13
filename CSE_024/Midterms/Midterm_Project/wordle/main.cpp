// #defines, #includes, namespace are placed in this order intentionally
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#include <iostream>
#include <vector>
using namespace std;

struct Stats {
    int gameState, timesPlayed, averageAttempts, winPercentage, currentStreak, longestStreak;
    vector<string> Words, Wins;
    vector<int> Attempts;
};

#include "wordle.h"
#include "file_manip.h"
#include "menu_screen.h"
#include "stats_screen.h"
#include "tutorial_screen.h"


int main(int argc, char* argv[]) {

    // New game initializes current game statistics and user input variable
    Stats stats;
    string user_option;
    
    // Read in stored game statistics and print out initial menu screen.
    system("clear");
    readStatsFile(stats);
    updateStatsFile(stats);
    printMenuScreen();
    
    // Main game loop, check user inputs for options 1-5 only
    while (cin >> user_option) {
        cin.ignore();

        // Exit the Wordle program, update the program state for the keyboard program before exiting
        if (user_option == "5") {
            stats.gameState = 0;
            updateStatsFile(stats);
            system("clear");
            break;

        // Start a new game session, update the stats.txt file before and after the game ends
        } else if (user_option == "1") {
            system("clear");
            stats.gameState = 2;
            updateStatsFile(stats);
            startGame(stats);
            stats.gameState = 1;
            updateStatsFile(stats);

        // Print out the tutorial screen
        } else if (user_option == "2") {
            while (!user_option.empty()) {
                system("clear");
                printTutorialScreen();
                getline(cin, user_option);
            }

        // Print out the stats screen
        } else if (user_option == "3") {
            while (!user_option.empty()) {
                system("clear");
                printStatsScreen(
                    stats.timesPlayed, 
                    stats.averageAttempts, 
                    stats.winPercentage, 
                    stats.currentStreak, 
                    stats.longestStreak, 
                    stats.Words, 
                    stats.Attempts, 
                    stats.Wins);
                getline(cin, user_option);
            }

        // Reset stats.txt and the game stats, then print out the stats screen.
        } else if (user_option == "4") {
            resetStatsFile();
            readStatsFile(stats);
            while (!user_option.empty()) {
                system("clear");
                printStatsScreen(
                    stats.timesPlayed, 
                    stats.averageAttempts, 
                    stats.winPercentage, 
                    stats.currentStreak, 
                    stats.longestStreak, 
                    stats.Words, 
                    stats.Attempts, 
                    stats.Wins);
                getline(cin, user_option);
            }
        }

        // Reset the console to the menu screen at the end of each process
        system("clear");
        printMenuScreen();
    }

    return 0;
}