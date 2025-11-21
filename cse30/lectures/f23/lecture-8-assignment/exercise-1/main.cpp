#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, char* argv[]){

    LinkedList numbers;

    numbers.append(5);
    numbers.append(7);
    numbers.append(4);

    cout << numbers << endl;

    numbers.removeFirst();

    cout << numbers << endl;

    return 0;
}