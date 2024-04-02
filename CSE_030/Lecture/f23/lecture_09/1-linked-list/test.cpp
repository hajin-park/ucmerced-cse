#include <igloo/igloo.h>
#include <stdexcept>
#include <unistd.h>
#include "LinkedList.h"

using namespace igloo;

Context(TestLinkedList){

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

    Spec(TestAppendGeneral){
        LinkedList nums;
        nums.append(5);
        nums.append(7);
        nums.append(2);


        Assert::That(nums.front->data, Equals(5));
        Assert::That(nums.front->next->data, Equals(7));
        Assert::That(nums.front->next->next->data, Equals(2));
    }

    Spec(TestRemoveFirstGeneral){
        LinkedList nums;
        nums.append(5);
        nums.append(7);
        nums.append(2);

        int x = nums.removeFirst();
        Assert::That(x, Equals(5));
        Assert::That(nums.front->data, Equals(7));
        Assert::That(nums.front->next->data, Equals(2));
    }

    Spec(TestRemoveFirstFromOne){
        LinkedList nums;
        nums.append(9);

        int x = nums.removeFirst();
        Assert::That(x, Equals(9));
        Assert::That(nums.front == nullptr, IsTrue());
        Assert::That(nums.back == nullptr, IsTrue());
    }

    Spec(TestRemoveFirstFromEmpty){
        LinkedList nums;

        AssertThrows(std::logic_error, nums.removeFirst());
    }

    Spec(TestRemoveLastGeneral){
        LinkedList nums;
        nums.append(5);
        nums.append(7);
        nums.append(2);

        int x = nums.removeLast();
        Assert::That(x, Equals(2));
        Assert::That(nums.front->data, Equals(5));
        Assert::That(nums.front->next->data, Equals(7));
    }

    Spec(TestRemoveLastFromOne){
        LinkedList nums;
        nums.append(9);

        int x = nums.removeLast();
        Assert::That(x, Equals(9));
        Assert::That(nums.front == nullptr, IsTrue());
        Assert::That(nums.back == nullptr, IsTrue());
    }

    Spec(TestRemoveLastFromEmpty){
        LinkedList nums;

        AssertThrows(std::logic_error, nums.removeLast());
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}