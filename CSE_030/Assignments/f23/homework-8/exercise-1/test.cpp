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

Context(TextProgram){

    static void SetUpContext() {
        exec("g++ main.cpp -o temp");
    }

    static void TearDownContext() {
        system("rm -rf temp");
    }

    Spec(NoneMatch){
        std::string result = exec("./temp");

        std::string expected = exec("cat expected.txt");
        
        Assert::That(result, Equals(expected));
    }


};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}