#include <igloo/igloo.h>
#include <stdexcept>
#include <unistd.h>
#include "SortedList.h"
#include "TimeSupport.h"

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

    Spec(TestAppend){
        SortedList<int> nums;
        nums.append(5);
        nums.append(3);
        nums.append(9);
        nums.append(7);
        nums.append(1);

        Assert::That(nums[0], Equals(1));
        Assert::That(nums[1], Equals(3));
        Assert::That(nums[2], Equals(5));
        Assert::That(nums[3], Equals(7));
        Assert::That(nums[4], Equals(9));

        Assert::That(nums.capacity, Equals(8));
        Assert::That(nums.count, Equals(5));

    }

    Spec(TestSearchSpeed){
        SortedList<int> nums;
        // We know the list will be sorted
        for (int i = 1; i <= 1'000'000; i++){
            nums.append(i);
        }

        timestamp start = current_time();
        for (int i = 0; i < 1'000; i++){
            nums.search(-1);
        }
        timestamp end = current_time();

        int duration = time_diff(start, end);

        Assert::That(duration, IsLessThan(100));

    }

    Spec(TestSearchCorrectness){
        SortedList<int> nums;
        nums.append(5);
        nums.append(3);
        nums.append(9);
        nums.append(7);
        nums.append(1);

        Assert::That(nums.search(0), IsFalse());
        Assert::That(nums.search(1), IsTrue());
        Assert::That(nums.search(2), IsFalse());
        Assert::That(nums.search(3), IsTrue());
        Assert::That(nums.search(4), IsFalse());
        Assert::That(nums.search(5), IsTrue());
        Assert::That(nums.search(6), IsFalse());
        Assert::That(nums.search(7), IsTrue());
        Assert::That(nums.search(8), IsFalse());
        Assert::That(nums.search(9), IsTrue());
        Assert::That(nums.search(10), IsFalse());
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}