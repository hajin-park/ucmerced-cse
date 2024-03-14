#include <igloo/igloo.h>
#include <stdexcept>
#include <unistd.h>

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


Context(TestRR){
    int oldSTDOUT;
    int oldSTDERR;

    void SetUp() {
        oldSTDOUT = dup( 1 );
        oldSTDERR = dup( 2 );
        freopen( "/dev/null", "w", stdout );
        freopen( "/dev/null", "w", stderr );

        exec("g++ main.cpp -o temp");
    }

    void TearDown() {
        fflush( stdout );
        fflush( stderr );
        dup2( oldSTDOUT, 1 );
        dup2( oldSTDERR, 2 );
        system("rm -rf temp");
    }

    Spec(TestProgram){
        std::string result = exec("echo '3\nAlice\n125\nBob\n103\nCecilia\n77\n50' | ./temp");
        Assert::That(result, Equals("Alice - 50\nBob - 50\nCecilia - 50\nAlice - 50\nBob - 50\nCecilia - 27\nAlice - 25\nBob - 3\nDone..."));
    }

  
};


int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}