#ifndef WORDLE_HELPER_H
#define WORDLE_HELPER_H

#include <stdexcept>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class WordleHelper{
 
    std::vector<std::string> allowed;
    std::vector<std::string> answers;

    std::vector<std::string> green;
    std::vector<std::string> yellow;
    std::vector<std::string> gray;


    bool contains(std::string word, char c){
        for (int i = 0; i < word.length(); i++){
            if (word[i] == c){
                return true;
            }
        }

        return false;
    }

public:
    WordleHelper(){
        std::string answersFile = "answers.txt";
        std::string allowedFile = "allowed.txt";

        std::fstream newfile;

        newfile.open(answersFile, std::ios::in);
        if (newfile.is_open()){
            std::string tp;
            
            while(getline(newfile, tp)){
                answers.push_back(tp);
            }
            newfile.close();
        }
        else {
            throw std::logic_error("Cant read file " + answersFile + ".");
        }

        newfile.open(allowedFile, std::ios::in);
        if (newfile.is_open()){
            std::string tp;
            
            while(getline(newfile, tp)){
                allowed.push_back(tp);
            }
            newfile.close();
        }
        else {
            throw std::logic_error("Cant read file " + allowedFile + ".");
        }
    }

    void addGreen(std::string feedback){
        if (feedback.size() != 5){
            throw std::logic_error("Green feedback must be exactly 5 characters");
        }
        if (std::any_of(feedback.begin(), feedback.end(), [](char c){
            return c != '_' && (c < 'a' || c > 'z');
        })){
            throw std::logic_error("Green feedback must contain only lowercase letters or underscores");
        }

        green.push_back(feedback);
    }

    void addYellow(std::string feedback){
        if (feedback.size() != 5){
            throw std::logic_error("Yellow feedback must be exactly 5 characters");
        }
        if (std::any_of(feedback.begin(), feedback.end(), [](char c){
            return c != '_' && (c < 'a' || c > 'z');
        })){
            throw std::logic_error("Yellow feedback must contain only lowercase letters or underscores");
        }

        yellow.push_back(feedback);
    }

    void addGray(std::string feedback){
        if (std::any_of(feedback.begin(), feedback.end(), [](char c){
            return c < 'a' && c > 'z';
        })){
            throw std::logic_error("Yellow feedback must contain only lowercase letters");
        }

        gray.push_back(feedback);
    }

    std::vector<std::string>possibleSolutions(){
        std::vector<std::string> results;
        bool is_possible = true;

        for (std::string word : answers) {
            is_possible = true;

            // Check possible solutions against gray letter constraints
            for (std::string gray_feedback : gray) {
                for (char gray_letter : gray_feedback) {
                    if (contains(word, gray_letter)) {
                        is_possible = false;
                        continue;
                    }
                }
            }

            // Check possible solutions against yellow letter constraints    
            for (std::string yellow_feedback : yellow) {
                for (int i = 0; i < yellow_feedback.length(); i++) {
                    // Word is not valid if its letter matches a yellow index
                    if (word[i] == yellow_feedback[i]) {
                        is_possible = false;
                        continue;
                    }

                    // A valid word must contain the yellow letter somewhere
                    if (yellow_feedback[i] != '_' && !contains(word, yellow_feedback[i])) {
                        is_possible = false;
                        continue;
                    }
                }
            }     

            // Check possible solutions against green letter constraints    
            for (std::string green_feedback : green) {
                for (int i = 0; i < green_feedback.length(); i++) {
                    if (green_feedback[i] != '_' && word[i] != green_feedback[i]) {
                        is_possible = false;
                        continue;
                    }
                }
            }

            if (is_possible) {
                results.push_back(word);
            }
        }

        return results;
    }

    std::vector<std::string> suggest(){
        // Optionally, your code here...
        return {"bring", "words", "close"};
    }

    ~WordleHelper(){

    }

    friend struct WordleTester;

};

#endif