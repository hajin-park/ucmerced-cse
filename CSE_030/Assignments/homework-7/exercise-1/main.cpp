#include <iostream>
#include "ArrayList.h"

using namespace std;

int main(){

    ArrayList<int> numbers;

    numbers.append(5);
    numbers.append(7);
    numbers.append(9);

    ArrayList<int> temp = numbers;

    cout << numbers << endl;
    cout << temp << endl;

    temp.removeFirst();
    numbers.removeLast();

    cout << numbers << endl;
    cout << temp << endl;

    numbers = temp;


    return 0;
}