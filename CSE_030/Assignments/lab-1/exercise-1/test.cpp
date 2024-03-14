#include <igloo/igloo.h>
#include <stdexcept>
#include "WordleHelper.h"

using namespace igloo;

Context(WordleTester){
    Spec(TestInitialization){
        WordleHelper wh;

        Assert::That(wh.allowed.size(), Equals(10657));
        Assert::That(wh.answers.size(), Equals(2315));
        Assert::That(wh.allowed[0], Equals("aahed"));
        Assert::That(wh.allowed[157], Equals("aguti"));
        Assert::That(wh.allowed[10656], Equals("zymic"));
        Assert::That(wh.answers[0], Equals("aback"));
        Assert::That(wh.answers[157], Equals("basis"));
        Assert::That(wh.answers[2314], Equals("zonal"));
    }

    Spec(TestAddGreen){
        WordleHelper wh;

        wh.addGreen("___i_");
        std::vector<std::string> expected = {"___i_"};
        Assert::That(wh.green, EqualsContainer(expected));

        wh.addGreen("_a_i_");
        expected = {"___i_", "_a_i_"};
        Assert::That(wh.green, EqualsContainer(expected));

        wh.addGreen("_a_id");
        expected = {"___i_", "_a_i_", "_a_id"};
        Assert::That(wh.green, EqualsContainer(expected));
    }

    Spec(TestAddGreenLengthErrors){
        WordleHelper wh;

        // Only 4 characters
        AssertThrows(std::logic_error, wh.addGreen("____"));
      
    }

    Spec(TestAddGreenValidCharsErrors){
        WordleHelper wh;
        // A character other than lowercase letters or underscores
        AssertThrows(std::logic_error, wh.addGreen("___1_"));
      
    }


    Spec (TestPossibleSolutionsLofty){
        WordleHelper wh;
        wh.addGreen("_o__y");
        wh.addYellow("__tlo");
        wh.addGray("audih");

        std::vector<std::string> expected = {"lofty"};

        Assert::That(wh.possibleSolutions(), EqualsContainer(expected));
    }

    Spec (TestPossibleSolutionsClass){
        WordleHelper wh;
        wh.addGreen("c_a__");
        wh.addYellow("__s__");
        wh.addGray("rnepoit");

        std::vector<std::string> expected = {"chasm", "clash", "class"};

        Assert::That(wh.possibleSolutions(), EqualsContainer(expected));
    }

};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}
