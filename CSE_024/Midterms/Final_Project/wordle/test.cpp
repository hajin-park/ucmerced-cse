#include <igloo/igloo.h>
#include <string>
#include <vector>
#include "wordle.h"

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"

using namespace igloo;

Context(TODO){
    Spec(FourLettersCorrect) {
        ::Wordle game {"4", "4-words.txt", "4-allowed.txt"};
        std::string guess_upper = "POLE";
        std::string answer_upper = "POLE";
        std::vector<std::string> actual = game.matchColors(guess_upper, answer_upper);
        std::vector<std::string> expected = {GREEN, GREEN, GREEN, GREEN};
        Assert::That(actual, Equals(expected));
    }
    Spec(FiveLettersPartial) {
        ::Wordle game {"5", "5-words.txt", "5-allowed.txt"};
        std::string guess_upper = "HAVEN";
        std::string answer_upper = "AUNTS";
        std::vector<std::string> actual = game.matchColors(guess_upper, answer_upper);
        std::vector<std::string> expected = {BLACK, YELLOW, BLACK, BLACK, YELLOW};
        Assert::That(actual, Equals(expected));
    }
    Spec(SixLettersIncorrect) {
        ::Wordle game {"6", "6-words.txt", "6-allowed.txt"};
        std::string guess_upper = "ABACUS";
        std::string answer_upper = "RODENT";
        std::vector<std::string> actual = game.matchColors(guess_upper, answer_upper);
        std::vector<std::string> expected = {BLACK, BLACK, BLACK, BLACK, BLACK, BLACK};
        Assert::That(actual, Equals(expected));
    }
    Spec(SevenLettersCorrect) {
        ::Wordle game {"7", "7-words.txt", "7-allowed.txt"};
        std::string guess_upper = "ZOMBIES";
        std::string answer_upper = "ZOMBIES";
        std::vector<std::string> actual = game.matchColors(guess_upper, answer_upper);
        std::vector<std::string> expected = {GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN};
        Assert::That(actual, Equals(expected));
    }
};

int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}
