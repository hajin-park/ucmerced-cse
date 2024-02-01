#ifndef STATS_SCREEN_H
#define STATS_SCREEN_H

#include <iostream>
#include <vector>
#include <iomanip>


void printStatsScreen(
                int timesPlayed, 
                int averageAttempts, 
                int winPercentage, 
                int currentStreak, 
                int longestStreak, 
                std::vector<std::string> Words, 
                std::vector<int> Attempts, 
                std::vector<std::string> Wins) {
    std::cout << "==========================" << std::endl;
    std::cout << "    STATISTICS SUMMARY" << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "Times Played:" << setw(13) << right << timesPlayed << std::endl;
    std::cout << "Average Attempts:" << setw(9) << right << averageAttempts << std::endl;
    std::cout << "Win Percentage:" << setw(10) << right << winPercentage << '%' << std::endl;
    std::cout << "Current Streak:" << setw(11) << right << currentStreak << std::endl;
    std::cout << "Longest Streak:" << setw(11) << right << longestStreak << std::endl << std::endl << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "WORD     ATTEMPTS      WIN" << std::endl;
    std::cout << "--------------------------" << std::endl;
    for (int i = 0; i < Words.size(); i++) {
        std::cout << Words[i] << setw(12) << right << Attempts[i] << setw(9) << right << Wins[i] << std::endl;
    }
    std::cout << std::endl << std::endl;
    std::cout << "Press [enter] to continue" << std::endl;
}

#endif