#include <igloo/igloo.h>
#include <stdexcept>
#include <unistd.h>

using namespace igloo;

Context(TestSortedList){
    int oldSTDOUT;
    int oldSTDERR;

    // Suppress outputs so that program being
    // tested does not polute the console
    void SetUp() {
        oldSTDOUT = dup( 1 );
        oldSTDERR = dup( 2 );
        freopen( "/dev/null", "w", stdout );
        freopen( "/dev/null", "w", stderr );     
    }

    // Restore output ability after tests are complete
    void TearDown() {
        fflush( stdout );
        fflush( stderr );
        dup2( oldSTDOUT, 1 );
        dup2( oldSTDERR, 2 );
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}