#include <igloo/igloo.h>
#include <stdexcept>
#include <unistd.h>
#include "ArrayList.h"

using namespace igloo;

Context(TestArrayList){
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

    Spec(TestCreateEmpty){
        ArrayList<int> numbers;

        Assert::That(numbers.count, Equals(0));
        Assert::That(numbers.capacity, Equals(1));
    }

    Spec(RemoveFirstFromEmpty){
        ArrayList<int> numbers;
        try {
            numbers.removeFirst();
            numbers.removeFirst();
        }
        catch(std::logic_error){
            Assert::That(true);
        }
    }

    Spec(RemoveLastFromEmpty){
        ArrayList<int> numbers;
        try{
            numbers.removeLast();
            numbers.removeLast();
        }
        catch(std::logic_error){
            Assert::That(true);
        }
    }
    
    Spec(TestAppendOne){
        ArrayList<int> numbers;
        numbers.append(99);
        
        Assert::That(numbers.count, Equals(1));
        Assert::That(numbers.capacity, Equals(2));
        Assert::That(numbers.arr[0], Equals(99));
    }

    Spec(TestAppendTwo){
        ArrayList<int> numbers;
        numbers.append(99);
        numbers.append(27);
        
        Assert::That(numbers.count, Equals(2));
        Assert::That(numbers.capacity, Equals(4));
        Assert::That(numbers.arr[0], Equals(99));
        Assert::That(numbers.arr[1], Equals(27));
    }

    Spec(TestAppendFour){
        ArrayList<int> numbers;
        numbers.append(99);
        numbers.append(27);
        numbers.append(14);
        numbers.append(42);
        
        Assert::That(numbers.count, Equals(4));
        Assert::That(numbers.capacity, Equals(8));
        Assert::That(numbers.arr[0], Equals(99));
        Assert::That(numbers.arr[1], Equals(27));
        Assert::That(numbers.arr[2], Equals(14));
        Assert::That(numbers.arr[3], Equals(42));
    }

    Spec(TestAppendFive){
        ArrayList<int> numbers;
        numbers.append(99);
        numbers.append(27);
        numbers.append(14);
        numbers.append(42);
        numbers.append(72);
        
        Assert::That(numbers.count, Equals(5));
        Assert::That(numbers.capacity, Equals(8));
        Assert::That(numbers.arr[0], Equals(99));
        Assert::That(numbers.arr[1], Equals(27));
        Assert::That(numbers.arr[2], Equals(14));
        Assert::That(numbers.arr[3], Equals(42));
        Assert::That(numbers.arr[4], Equals(72));
    }

    Spec(TestPrependOne){
        ArrayList<int> numbers;
        numbers.prepend(99);
        
        Assert::That(numbers.count, Equals(1));
        Assert::That(numbers.capacity, Equals(2));
        Assert::That(numbers.arr[0], Equals(99));
    }

    Spec(TestPrependTwo){
        ArrayList<int> numbers;
        numbers.prepend(99);
        numbers.prepend(27);
        
        Assert::That(numbers.count, Equals(2));
        Assert::That(numbers.capacity, Equals(4));
        Assert::That(numbers.arr[0], Equals(27));
        Assert::That(numbers.arr[1], Equals(99));
    }

    Spec(TestPrependFour){
        ArrayList<int> numbers;
        numbers.prepend(99);
        numbers.prepend(27);
        numbers.prepend(14);
        numbers.prepend(42);
        
        Assert::That(numbers.count, Equals(4));
        Assert::That(numbers.capacity, Equals(8));
        Assert::That(numbers.arr[0], Equals(42));
        Assert::That(numbers.arr[1], Equals(14));
        Assert::That(numbers.arr[2], Equals(27));
        Assert::That(numbers.arr[3], Equals(99));
    }

    Spec(TestPrependFive){
        ArrayList<int> numbers;
        numbers.prepend(99);
        numbers.prepend(27);
        numbers.prepend(14);
        numbers.prepend(42);
        numbers.prepend(72);
        
        Assert::That(numbers.count, Equals(5));
        Assert::That(numbers.capacity, Equals(8));
        Assert::That(numbers.arr[0], Equals(72));
        Assert::That(numbers.arr[1], Equals(42));
        Assert::That(numbers.arr[2], Equals(14));
        Assert::That(numbers.arr[3], Equals(27));
        Assert::That(numbers.arr[4], Equals(99));
    }

    Spec(TestRemoveLastFromFiveOnce){
        ArrayList<int> numbers;
        numbers.append(99);
        numbers.append(27);
        numbers.append(14);
        numbers.append(42);
        numbers.append(72);

        numbers.removeLast();

        Assert::That(numbers.count, Equals(4));
        Assert::That(numbers.capacity, Equals(8));
        Assert::That(numbers.arr[0], Equals(99));
        Assert::That(numbers.arr[1], Equals(27));
        Assert::That(numbers.arr[2], Equals(14));
        Assert::That(numbers.arr[3], Equals(42));
    }

    Spec(TestRemoveLastFromFiveTwice){
        ArrayList<int> numbers;
        numbers.append(99);
        numbers.append(27);
        numbers.append(14);
        numbers.append(42);
        numbers.append(72);

        numbers.removeLast();
        numbers.removeLast();

        Assert::That(numbers.count, Equals(3));
        Assert::That(numbers.capacity, Equals(4));
        Assert::That(numbers.arr[0], Equals(99));
        Assert::That(numbers.arr[1], Equals(27));
        Assert::That(numbers.arr[2], Equals(14));

    }

    Spec(TestRemoveFirstFromFiveOnce){
        ArrayList<int> numbers;
        numbers.append(99);
        numbers.append(27);
        numbers.append(14);
        numbers.append(42);
        numbers.append(72);

        numbers.removeFirst();

        Assert::That(numbers.count, Equals(4));
        Assert::That(numbers.capacity, Equals(8));
        Assert::That(numbers.arr[0], Equals(27));
        Assert::That(numbers.arr[1], Equals(14));
        Assert::That(numbers.arr[2], Equals(42));
        Assert::That(numbers.arr[3], Equals(72));
    }

    Spec(TestRemoveFirstFromFiveTwice){
        ArrayList<int> numbers;
        numbers.append(99);
        numbers.append(27);
        numbers.append(14);
        numbers.append(42);
        numbers.append(72);

        numbers.removeFirst();
        numbers.removeFirst();

        Assert::That(numbers.count, Equals(3));
        Assert::That(numbers.capacity, Equals(4));
        Assert::That(numbers.arr[0], Equals(14));
        Assert::That(numbers.arr[1], Equals(42));
        Assert::That(numbers.arr[2], Equals(72));

    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}