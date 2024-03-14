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

    Spec(TestWithInt){
        LinkedList<int> numbers;
        numbers.append(5);
        numbers.append(7);
        numbers.append(2);

        Assert::That(numbers.front->data, Equals(5));
        Assert::That(numbers.front->next->data, Equals(7));
        Assert::That(numbers.front->next->next->data, Equals(2));
    }

    Spec(TestWithString){
        LinkedList<std::string> names;
        names.append("Alice");
        names.append("Trudy");
        names.append("Bob");

        Assert::That(names.front->data, Equals("Alice"));
        Assert::That(names.front->next->data, Equals("Trudy"));
        Assert::That(names.front->next->next->data, Equals("Bob"));
    }


    Spec(TestRemoveFirstGeneral){
        LinkedList<int> nums;
        nums.append(5);
        nums.append(7);
        nums.append(2);

        int x = nums.removeFirst();
        Assert::That(x, Equals(5));
        Assert::That(nums.front->data, Equals(7));
        Assert::That(nums.front->next->data, Equals(2));
    }

    Spec(TestRemoveFirstFromOne){
        LinkedList<int> nums;
        nums.append(9);

        int x = nums.removeFirst();
        Assert::That(x, Equals(9));
        Assert::That(nums.front == nullptr, IsTrue());
        Assert::That(nums.back == nullptr, IsTrue());
    }

    Spec(TestRemoveFirstFromEmpty){
        LinkedList<int> nums;

        AssertThrows(std::logic_error, nums.removeFirst());
    }

    Spec(TestRemoveLastGeneral){
        LinkedList<int> nums;
        nums.append(5);
        nums.append(7);
        nums.append(2);

        int x = nums.removeLast();
        Assert::That(x, Equals(2));
        Assert::That(nums.front->data, Equals(5));
        Assert::That(nums.front->next->data, Equals(7));
    }

    Spec(TestRemoveLastFromOne){
        LinkedList<int> nums;
        nums.append(9);

        int x = nums.removeLast();
        Assert::That(x, Equals(9));
        Assert::That(nums.front == nullptr, IsTrue());
        Assert::That(nums.back == nullptr, IsTrue());
    }

    Spec(TestRemoveLastFromEmpty){
        LinkedList<int> nums;

        AssertThrows(std::logic_error, nums.removeLast());
    }

};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}