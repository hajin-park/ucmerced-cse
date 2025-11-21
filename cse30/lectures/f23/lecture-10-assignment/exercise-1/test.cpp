#include <igloo/igloo.h>
#include <stdexcept>
#include <unistd.h>
#include "Stack.h"
#include "Queue.h"

using namespace igloo;

Context(TestQueue){
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

    Spec(TestCreation){
        Queue<int> q_int;
        Assert::That(q_int.length(), Equals(0));
    }

    Spec(TestDequeueFromEmpty){
        Queue<int> q_int;
        AssertThrows(std::logic_error, q_int.dequeue());
    }

    Spec(TestPeekFromEmpty){
        Queue<int> q_int;
        AssertThrows(std::logic_error, q_int.peek());
    }

    Spec(TestEnqueueAndPeek){
        Queue<int> q_int;
        q_int.enqueue(17);
        Assert::That(q_int.peek(), Equals(17));
        Assert::That(q_int.length(), Equals(1));
    }

    Spec(TestEnqueueAndDequeue){
        Queue<int> q_int;
        q_int.enqueue(17);
        Assert::That(q_int.dequeue(), Equals(17));
        Assert::That(q_int.length(), Equals(0));
    }

    Spec(TestMultipleEnqueueAndDequeue){
        Queue<int> q_int;
        Assert::That(q_int.length(), Equals(0));

        q_int.enqueue(17);
        Assert::That(q_int.length(), Equals(1));

        q_int.enqueue(8);
        Assert::That(q_int.length(), Equals(2));

        q_int.enqueue(93);
        Assert::That(q_int.length(), Equals(3));

        Assert::That(q_int.dequeue(), Equals(17));
        Assert::That(q_int.dequeue(), Equals(8));
        Assert::That(q_int.dequeue(), Equals(93));

        Assert::That(q_int.length(), Equals(0));
    }
};

Context(TestStack){
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
    
    Spec(TestCreation){
        Stack<int> s_int;
        Assert::That(s_int.length(), Equals(0));
    }

    Spec(TestPopFromEmpty){
        Stack<int> s_int;
        AssertThrows(std::logic_error, s_int.pop());
    }

    Spec(TestPeekFromEmpty){
        Stack<int> s_int;
        AssertThrows(std::logic_error, s_int.peek());
    }

    Spec(TestPushAndPeek){
        Stack<int> s_int;
        s_int.push(17);
        Assert::That(s_int.peek(), Equals(17));
        Assert::That(s_int.length(), Equals(1));
    }

    Spec(TestPushAndPop){
        Stack<int> s_int;
        s_int.push(17);
        Assert::That(s_int.pop(), Equals(17));
        Assert::That(s_int.length(), Equals(0));
    }

    Spec(TestMultiplePushAndPop){
        Stack<int> s_int;
        Assert::That(s_int.length(), Equals(0));

        s_int.push(17);
        Assert::That(s_int.length(), Equals(1));

        s_int.push(8);
        Assert::That(s_int.length(), Equals(2));

        s_int.push(93);
        Assert::That(s_int.length(), Equals(3));

        Assert::That(s_int.pop(), Equals(93));
        Assert::That(s_int.pop(), Equals(8));
        Assert::That(s_int.pop(), Equals(17));

        Assert::That(s_int.length(), Equals(0));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}