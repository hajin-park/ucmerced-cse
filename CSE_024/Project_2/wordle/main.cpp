#include <iostream>
#include "wordle.h"

using namespace std;

int main(int argc, char* argv[]) {
    // Quit program if the Wordle lengths are not specified
    if (argc != 4) {
        cout << "Incorrect arguments" << endl;
        exit(0);
    }

    Wordle game {argv[1], argv[2], argv[3]};
    string user_option;
    
    // Read in stored game statistics and print out initial menu screen.
    system("clear");
    game.readStatsFile();
    game.updateStatsFile();
    game.printMenu();
    
    // Main game loop, check user inputs for options 1-5 only
    while (cin >> user_option) {
        cin.ignore();

        // Exit the Wordle program, update the program state for the keyboard program before exiting
        if (user_option == "5") {
            game.gameState = 0;
            game.updateStatsFile();
            system("clear");
            break;

        // Start a new game session, update the stats.txt file before and after the game ends
        } else if (user_option == "1") {
            system("clear");
            game.gameState = 2;
            game.updateStatsFile();
            game.play();
            game.gameState = 1;
            game.updateStatsFile();

        // Print out the tutorial screen
        } else if (user_option == "2") {
            while (!user_option.empty()) {
                system("clear");
                game.printTutorial();
                getline(cin, user_option);
            }

        // Print out the stats screen
        } else if (user_option == "3") {
            while (!user_option.empty()) {
                system("clear");
                game.printStats();
                getline(cin, user_option);
            }

        // Reset stats.txt and the game stats, then print out the stats screen.
        } else if (user_option == "4") {
            game.resetStatsFile();
            game.readStatsFile();
            while (!user_option.empty()) {
                system("clear");
                game.printStats();
                getline(cin, user_option);
            }
        }

        // Reset the console to the menu screen at the end of each process
        system("clear");
        game.printMenu();
    }

    return 0;
}