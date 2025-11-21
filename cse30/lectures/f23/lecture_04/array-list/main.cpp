#include <iostream>
#include "ArrayList.h"

using namespace std;

int main(int argc, char* argv[]){


    ArrayList<int> c;

    for (int i = 0; i < 10; i++){
        c.append(i+1);
    }
   

    cout << c << endl;

    ArrayList<string> s;

    s.append("Alice");
    s.append("Bob");

    cout << s << endl;
    return 0;
}