#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(){

    LinkedList<int> numbers;

    numbers.append(5);
    numbers.append(7);
    numbers.append(9);

    LinkedList<int> temp = numbers;
    temp.reverse();

    cout << numbers << endl;
    cout << temp << endl;

    temp.removeFirst();
    numbers.removeLast();

    cout << numbers << endl;
    cout << temp << endl;

    numbers = temp;


    return 0;
}