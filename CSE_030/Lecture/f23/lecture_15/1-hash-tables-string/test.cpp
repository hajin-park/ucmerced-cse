#include <cstdio>
#include <igloo/igloo.h>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

using namespace igloo;

std::string exec(std::string command) {
   char buffer[128];
   std::string result = "";

   // Open pipe to file
   FILE* pipe = popen((command + " 2>&1").c_str(), "r");
   if (!pipe) {
      return "popen failed!";
   }

   // read till end of process:
   while (!feof(pipe)) {

      // use buffer to read and add to result
      if (fgets(buffer, 128, pipe) != NULL)
         result += buffer;
   }

   pclose(pipe);
   result.erase(result.find_last_not_of(" \t\n\r\f\v") + 1);
   return result;
}

struct OutputParser {
    int count;
    int duration;

    OutputParser(std::string raw){
        std::stringstream ss(raw);
        std::string countLine;
        std::string durationLine;
        getline(ss, countLine);
        getline(ss, durationLine);
        std::stringstream sc(countLine);
        std::string temp;
        std::string countS;
        std::string durationS;
        sc >> temp >> countS;
        std::stringstream sd(durationLine);
        sd >> temp >> durationS;
        count = std::stoi(countS);
        duration = std::stoi(durationS);
    }
};

Context(TextProgram){

    static void SetUpContext() {
        exec("g++ main.cpp -o temp");
    }

    static void TearDownContext() {
        system("rm -rf temp");
    }

    Spec(NoneMatch){
        std::string result = exec("printf 'hello\nworld' | ./temp");

        OutputParser op(result);
        
        Assert::That(op.count, Equals(0));
        Assert::That(op.duration, Equals(0));
    }

    Spec(SimpleTest){
        std::string result = exec("printf 'reward\nhello\ndrawer' | ./temp");

        OutputParser op(result);
        
        Assert::That(op.count, Equals(2));
        Assert::That(op.duration, Equals(0));
    }

    Spec(AnotherSimpleTest){
        std::string result = exec("printf 'reward\nhello\ndrawer\nracecar' | ./temp");

        OutputParser op(result);
        
        Assert::That(op.count, Equals(3));
        Assert::That(op.duration, Equals(0));
    }

    #if SKIPTIME != 1
    Spec(SpeedTest){
        std::string result = exec("./temp < english.txt");

        OutputParser op(result);

        Assert::That(op.count, Equals(1707));
        Assert::That(op.duration, IsLessThan(500));
    }
    #endif

};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}