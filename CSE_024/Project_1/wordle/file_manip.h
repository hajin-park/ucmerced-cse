#ifndef FILE_MANIP_H
#define FILE_MANIP_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>


void readStatsFile(Stats& stats) {
    std::ifstream file("stats.txt");
    if (file) {
        stats.Words.clear();
        stats.Attempts.clear();
        stats.Wins.clear();
        file >> stats.gameState
             >> stats.timesPlayed
             >> stats.averageAttempts
             >> stats.winPercentage
             >> stats.currentStreak
             >> stats.longestStreak;
        std::string line;
        getline(file, line); // Skip the first line of stats.txt
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string word, win;
            int attempt;
            iss >> word >> attempt >> win;
            stats.Words.push_back(word);
            stats.Attempts.push_back(attempt);
            stats.Wins.push_back(win);
        }
        stats.gameState = 1;
    } else {
        std::cerr << "Error: Could not open file.\n";
    }
}

void updateStatsFile(Stats& stats) {
    std::ofstream file("stats.txt", std::ios::trunc);
    if (file.is_open()) {
        int numWins = 0, longestStreak = 0, currentStreak = 0, attemptSum = 0;
        for (std::string win : stats.Wins) {
            if (win == "Yes") {
                numWins++, currentStreak++;
                if (currentStreak > longestStreak) longestStreak = currentStreak;
            } else currentStreak = 0;
        }
        for (int i : stats.Attempts) attemptSum += i;
        stats.timesPlayed = stats.Words.size();
        stats.averageAttempts = stats.timesPlayed ? attemptSum/stats.Attempts.size() : 0;
        stats.winPercentage = stats.timesPlayed ? ((float)numWins/stats.Wins.size())*100 : 0;
        stats.currentStreak = currentStreak, stats.longestStreak = longestStreak;
        file << stats.gameState << ' ' << stats.timesPlayed << ' ' << stats.averageAttempts << ' ' << stats.winPercentage << ' ' << stats.currentStreak << ' ' << stats.longestStreak << '\n';
        for (int i = 0; i < stats.Words.size(); i++) {
            file << stats.Words[i] << ' ' << stats.Attempts[i] << ' ' << stats.Wins[i] << '\n';
        }
        file.close();
    } else std::cerr << "Error: Could not open file." << std::endl;
}

void resetStatsFile() {
    std::ofstream file("stats.txt", std::ios::trunc);
    if (file.is_open()) {
        file << "1 0 0 0 0 0 0";
        file.close();
    } else std::cerr << "Error: Could not open file." << std::endl;
}

#endif