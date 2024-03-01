#include <igloo/igloo.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "keyboard.h"
#include "../wordle/wordle.h"

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"

using namespace igloo;

Context(TODO){
    Spec(FirstRow) {
        ::Keyboard keyboard;

        std::ofstream colors_file_out("../data/colors.txt", std::ios::trunc);
        colors_file_out << "UJIKOLP" << '\n' << "RFTGYH" << '\n' << "QAWSED";
        keyboard.getColors();
        std::vector<std::string> actual = keyboard.colors[0];
        std::vector<std::string> expected = {GREEN, GREEN, GREEN, YELLOW, YELLOW, YELLOW, BLACK, BLACK, BLACK, BLACK};

        Assert::That(actual, Equals(expected));
    }
    Spec(SecondRow) {
        ::Keyboard keyboard;
        
        std::ofstream colors_file_out("../data/colors.txt", std::ios::trunc);
        colors_file_out << "ZXCVBN" << '\n' << "ASDFGHL" << '\n' << "QWERTY";
        keyboard.getColors();
        std::vector<std::string> actual = keyboard.colors[1];
        std::vector<std::string> expected = {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, RESET, RESET, YELLOW};

        Assert::That(actual, Equals(expected));
    }
    Spec(ThirdRow) {
        ::Keyboard keyboard;

        std::ofstream colors_file_out("../data/colors.txt", std::ios::trunc);
        colors_file_out << "MNBVCX" << '\n' << "LKJHGF" << '\n' << "POIUYT";
        keyboard.getColors();
        std::vector<std::string> actual = keyboard.colors[2];
        std::vector<std::string> expected = {RESET, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK};

        Assert::That(actual, Equals(expected));
    }
    Spec(AllRows) {
        ::Keyboard keyboard;

        std::ofstream colors_file_out("../data/colors.txt", std::ios::trunc);
        colors_file_out << "XCVBNMERTYUI" << '\n' << "FGHJKL" << '\n' << "ERTYUIP";
        keyboard.getColors();
        std::vector<std::vector<std::string>> actual = keyboard.colors;
        std::vector<std::vector<std::string>> expected = {{RESET, RESET, GREEN, GREEN, GREEN, GREEN, GREEN , GREEN, RESET, GREEN}, {RESET, RESET, RESET, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW}, {RESET, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK}};

        Assert::That(actual, Equals(expected));
    }
};

int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}
