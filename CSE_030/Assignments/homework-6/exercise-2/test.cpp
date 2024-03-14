#include <igloo/igloo.h>
#include <unistd.h>
#include "HashTable.h"
#include "RandomSupport.h"
#include "TimeSupport.h"

using namespace igloo;

Context(TestProject){
    int oldSTDOUT;
    int oldSTDERR;

    void SetUp() {
        oldSTDOUT = dup( 1 );
        oldSTDERR = dup( 2 );
        freopen( "/dev/null", "w", stdout );
        freopen( "/dev/null", "w", stderr );     
    }

    void TearDown() {
        fflush( stdout );
        fflush( stderr );
        dup2( oldSTDOUT, 1 );
        dup2( oldSTDERR, 2 );
    }

    Spec(TestSearchCorrectness){
        HashTable bag(10);
        bag.add(5);
        bag.add(7);
        bag.add(3);
        bag.add(1);
        bag.add(451626249);

        Assert::That(bag.search(0), IsFalse());
        Assert::That(bag.search(1), IsTrue());
        Assert::That(bag.search(2), IsFalse());
        Assert::That(bag.search(3), IsTrue());
        Assert::That(bag.search(4), IsFalse());
        Assert::That(bag.search(5), IsTrue());
        Assert::That(bag.search(6), IsFalse());
        Assert::That(bag.search(7), IsTrue());
        Assert::That(bag.search(8), IsFalse());
        Assert::That(bag.search(9), IsFalse());
        Assert::That(bag.search(451626249), IsTrue());
    }
    
    Spec(TestSpeed){
        const int N = 5000;

        HashTable bag(N);
        RNG rng(0, N*100);


        timestamp start = current_time();

        for (int i = 0; i < N; i++){
            int num = rng.get();
            bag.add(i);

            for (int j = 0; j < N; j++){
            bag.search(-1);
            }
        }

        timestamp end = current_time();

        int duration = time_diff(start, end);

        Assert::That(duration, IsLessThan(5000));
    }
};

int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}