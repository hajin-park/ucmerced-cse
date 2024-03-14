#include <igloo/igloo.h>
#include <unistd.h>
#include "Container.h"
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

    Spec(TestSearchEmpty){
        Container bag;
        
        Assert::That(bag.search(5), IsFalse());
    }

    Spec(TestSingleton){
        Container bag;
        bag.add(5);

        Assert::That(bag.search(5), IsTrue());
        Assert::That(bag.search(7), IsFalse());
    }

    Spec(TestSearchCorrectness){
        Container bag;
        bag.add(5);
        bag.add(7);
        bag.add(3);
        bag.add(1);
        bag.add(4);

        Assert::That(bag.search(0), IsFalse());
        Assert::That(bag.search(1), IsTrue());
        Assert::That(bag.search(2), IsFalse());
        Assert::That(bag.search(3), IsTrue());
        Assert::That(bag.search(4), IsTrue());
        Assert::That(bag.search(5), IsTrue());
        Assert::That(bag.search(6), IsFalse());
        Assert::That(bag.search(7), IsTrue());
        Assert::That(bag.search(8), IsFalse());
        Assert::That(bag.search(9), IsFalse());
    }
    
    Spec(TestSpeed){
        const int N = 5000;

        Container bag(N);
        RNG rng(0, N-1);


        timestamp start = current_time();

        for (int i = 0; i < N; i++) {
            int num = rng.get();
            bag.add(num);

            for (int j = 0; j < N; j++) {
                bag.search(-1);
            }
        }

        timestamp end = current_time();

        int duration = time_diff(start, end);

        Assert::That(duration, IsLessThan(500));
    }
};

int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}