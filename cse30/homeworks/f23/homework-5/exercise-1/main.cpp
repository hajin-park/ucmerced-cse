#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "Stash.h"

using namespace std;

int main(){
    Stash jar;

    jar.deposit(5);
    cout << jar.getBalance() << endl;

    jar.withdraw(3);
    cout << jar.getBalance() << endl;

    jar.undo();
    cout << jar.getBalance() << endl;

    jar.undo();
    cout << jar.getBalance() << endl;
    
    return 0;
}